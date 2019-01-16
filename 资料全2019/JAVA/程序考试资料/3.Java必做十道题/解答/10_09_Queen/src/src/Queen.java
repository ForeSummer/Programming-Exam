package src;

import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

@SuppressWarnings("serial")
public class Queen extends JFrame
{
	private JButton[][] button = new JButton[8][8];
	private int num = 0;
	long time1 = new Date().getTime();
	boolean gameOver;

	public Queen()
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				button[i][j] = new JButton("");
			}
		}

		Container c = getContentPane();
		c.setLayout(new GridLayout(8, 8));

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				c.add(button[i][j]);
				button[i][j].addActionListener(new Handler(i, j));
				// ����new��һ��Handler��Ķ���ע��Handler��Ĺ��췽���ǿ��Դ�������
			}
		}
	}

	class Handler implements ActionListener
	{
		private int i, j;

		public Handler(int row, int col)
		{
			i = row;
			j = col;
		}

		public void paint(int i, int j)
		{
			// ˮƽ�����ϻ�����
			for (int x = 0; x < 8; x++)
				button[x][j].setBackground(Color.GREEN);

			// ��ֱ�����ϻ�����
			for (int y = 0; y < 8; y++)
				button[i][y].setBackground(Color.GREEN);

			// б���ϻ�����
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					if (Math.abs(x - i) == Math.abs(y - j))
						button[x][y].setBackground(Color.GREEN);

				}
			}
		}

		public void actionPerformed(ActionEvent e)
		{
			if (gameOver)
				JOptionPane.showMessageDialog(null, "��Ϸ�ѽ���");
			else
			{
				if (button[i][j].getBackground() == Color.GREEN)
					JOptionPane.showMessageDialog(null, "λ�ó�ͻ�����طţ�");
				else if (button[i][j].getBackground() == Color.BLACK)
					JOptionPane.showMessageDialog(null, "��λ�������壬���طţ�");
				else
				{
					num++;
					paint(i, j);
					button[i][j].setBackground(Color.BLACK);
					if (num == 8)
					{
						gameOver = true;
						long time2 = new Date().getTime();
						String time = String.valueOf(time2 - time1);
						JOptionPane.showMessageDialog(null, "��ϲ��ʤ����ʱ" + time);
					}

				}

			}
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		Queen app = new Queen();
		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.setSize(400, 400);
		app.setLocation(290, 180);
		app.setVisible(true);

	}

}
