package src;

/*
 * Library.java:
 * ����ļ����������¼����ࣺ
 * ���ࣺLibrary;�ࣺBook;�ڲ��ࣺaddHandler,modifyHandler,delHandler,lookHandler,
 * serchTypeHandler,serchAuthorHandler,serchPressHandler,
 * serchReaderHandler,sortPriceHandler,sortDateHandler,priceComp,dateComp
 * 
 */

/**
 * ˵����һ���򵥵�ͼ�������Ϣϵͳ
 */

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

/**
 * Book: ��������Book�ļ�������
 * 
 * @author zhaoyuan
 * @version1.0
 */
class Book
{
	public String id = null;
	public String name = null;
	public String type = null;
	public String author = null;
	public String price = null;
	public String pressDate = null;
	public String press = null;
	public String buyDate = null;
	public String reader = null;

}

/**
 * Library: ���࣬ʵ���˽��棬�������ʵ���¼����������ڲ���
 * 
 * @author ����
 * @version 1.0
 */
@SuppressWarnings("serial")
public class Library extends JFrame
{

	private ArrayList<Book> list = new ArrayList<Book>();
	private ArrayList<Book> serchList = new ArrayList<Book>();

	private JPanel p1 = new JPanel();
	private JButton addB = new JButton("¼��");
	private JButton modifyB = new JButton("�޸�");
	private JButton delB = new JButton("ɾ��");
	private JButton lookB = new JButton("�鿴");
	private JButton serchTypeB = new JButton("����-������");
	private JButton serchAuthorB = new JButton("����-������");
	private JButton serchPressB = new JButton("����-��������");
	private JButton serchReaderB = new JButton("����-��������");
	private JButton sortPriceB = new JButton("����-���۸�");
	private JButton sortDateB = new JButton("����-����������");

	private JPanel p2 = new JPanel();
	private JLabel idL = new JLabel("���");
	private JTextField idT = new JTextField("", 3);
	private JLabel nameL = new JLabel("����");
	private JTextField nameT = new JTextField("", 3);
	private JLabel typeL = new JLabel("����");
	private JTextField typeT = new JTextField("", 3);
	private JLabel authorL = new JLabel("����");
	private JTextField authorT = new JTextField("", 3);
	private JLabel priceL = new JLabel("�۸�");
	private JTextField priceT = new JTextField("", 3);
	private JLabel pressDateL = new JLabel("��������");
	private JTextField pressDateT = new JTextField("", 3);
	private JLabel pressL = new JLabel("������");
	private JTextField pressT = new JTextField("", 3);
	private JLabel buyDateL = new JLabel("��������");
	private JTextField buyDateT = new JTextField("", 3);
	private JLabel readerL = new JLabel("������");
	private JTextField readerT = new JTextField("", 3);

	private JTextArea info = new JTextArea();

	/**
	 * Library(): ���췽����ʵ���˽��棬����ÿ����ť������¼�������
	 * 
	 * @author zhaoyuan
	 */
	public Library()
	{
		Container c = getContentPane();

		p1.add(addB);// panel����ֱ�����
		p1.add(modifyB);
		p1.add(delB);
		p1.add(lookB);
		p1.add(serchTypeB);
		p1.add(serchAuthorB);
		p1.add(serchPressB);
		p1.add(serchReaderB);
		p1.add(sortPriceB);
		p1.add(sortDateB);

		p2.add(idL);
		p2.add(idT);
		p2.add(nameL);
		p2.add(nameT);
		p2.add(typeL);
		p2.add(typeT);
		p2.add(authorL);
		p2.add(authorT);
		p2.add(priceL);
		p2.add(priceT);
		p2.add(pressDateL);
		p2.add(pressDateT);
		p2.add(pressL);
		p2.add(pressT);
		p2.add(buyDateL);
		p2.add(buyDateT);
		p2.add(readerL);
		p2.add(readerT);

		c.add(p1, BorderLayout.NORTH);// ����������Frame����Ҫ�Ȼ�ȡ������������
		c.add(p2, BorderLayout.SOUTH);
		c.add(new JScrollPane(info), BorderLayout.CENTER);// ��JTextArea��װ��JScrollPane������ӵ�Frame��

		addB.addActionListener(new addHandler());
		modifyB.addActionListener(new modifyHandler());
		delB.addActionListener(new delHandler());
		lookB.addActionListener(new lookHandler());
		serchTypeB.addActionListener(new serchTypeHandler());
		serchAuthorB.addActionListener(new serchAuthorHandler());
		serchPressB.addActionListener(new serchPressHandler());
		serchReaderB.addActionListener(new serchReaderHandler());
		sortPriceB.addActionListener(new sortPriceHandler());
		sortDateB.addActionListener(new sortDateHandler());

	}

	/**
	 * refresh: ����textaAea info����Ϣ
	 * 
	 * @param list
	 *            ����ʾҪ���µ�list��������������Ϣ��list
	 * @author zhaoyuan
	 */
	private void refresh(ArrayList<Book> list)
	{
		StringBuffer sb = new StringBuffer("");
		sb.append("���" + "\t" + "����" + "\t" + "����" + "\t" + "����" + "\t" + "�۸�" + "\t" + "��������" + "\t" + "������" + "\t"
				+ "��������" + "\t" + "������" + "\n");
		for (int i = 0; i < list.size(); i++)
			sb.append(list.get(i).id + "\t" + list.get(i).name + "\t" + list.get(i).type + "\t" + list.get(i).author
					+ "\t" + list.get(i).price + "\t" + list.get(i).pressDate + "\t" + list.get(i).press + "\t"
					+ list.get(i).buyDate + "\t" + list.get(i).reader + "\n");

		info.setText(sb.toString());

	}

	/**
	 * addHandler: ʵ���˵㡰¼�롱ʱ�Ĺ��ܡ�������һ����Ϣ
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class addHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Book book = new Book();
			book.id = idT.getText();
			book.name = nameT.getText();
			book.type = typeT.getText();
			book.author = authorT.getText();
			book.price = priceT.getText();
			book.pressDate = pressDateT.getText();
			book.press = pressT.getText();
			book.buyDate = buyDateT.getText();
			book.reader = readerT.getText();

			list.add(book);
			refresh(list);
		}
	}

	/**
	 * modifyHandler: ʵ���˵㡰�޸ġ�ʱ�Ĺ��ܡ����޸�ĳ��ָ����id����Ϣ
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class modifyHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int index = -1;
			for (int i = 0; i < list.size(); i++)
			{
				if (list.get(i).id.equals(idT.getText()))
				{
					index = i;
					break;
				}
			}
			if (index == -1)
				JOptionPane.showMessageDialog(null, "��id�����ڣ�");

			else
			{
				list.get(index).id = idT.getText();
				list.get(index).name = nameT.getText();
				list.get(index).type = typeT.getText();
				list.get(index).author = authorT.getText();
				list.get(index).price = priceT.getText();
				list.get(index).pressDate = pressDateT.getText();
				list.get(index).press = pressT.getText();
				list.get(index).buyDate = buyDateT.getText();
				list.get(index).reader = readerT.getText();

				refresh(list);
			}

		}
	}

	/**
	 * delHandler: ʵ���˵㡰ɾ����ʱ�Ĺ��ܡ������ָ��id����Ϣ
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class delHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int index = -1;
			for (int i = 0; i < list.size(); i++)
			{
				if (list.get(i).id.equals(idT.getText()))
				{
					index = i;
					break;
				}
			}
			if (index != -1)
			{
				list.remove(index);

				refresh(list);
			}
			else
				JOptionPane.showMessageDialog(null, "��id�����ڣ�");
		}
	}

	/**
	 * lookHandler: ʵ���˵㡰�鿴��ʱ�Ĺ��ܡ����鿴������Ϣ
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class lookHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			refresh(list);
		}
	}

	/**
	 * serchTypeHandler: ʵ���˵㡰����-�����͡�ʱ�Ĺ��ܡ�����������ʾָ�����͵�����
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class serchTypeHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			serchList.clear();
			for (int i = 0; i < list.size(); i++)
			{
				if (list.get(i).type.equals(typeT.getText()))
				{
					serchList.add(list.get(i));
				}
			}
			refresh(serchList);
		}
	}

	/**
	 * serchAuthorHandler: ʵ���˵㡰����-�����ߡ�ʱ�Ĺ��ܡ�����������ʾָ�����ߵ�����
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class serchAuthorHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			serchList.clear();
			for (int i = 0; i < list.size(); i++)
			{
				if (list.get(i).author.equals(authorT.getText()))
				{
					serchList.add(list.get(i));
				}
			}
			refresh(serchList);
		}
	}

	/**
	 * serchPressHandler: ʵ���˵㡰����-�������硱ʱ�Ĺ��ܡ�����������ʾָ�������������
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class serchPressHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			serchList.clear();
			for (int i = 0; i < list.size(); i++)
			{
				if (list.get(i).press.equals(pressT.getText()))
				{
					serchList.add(list.get(i));
				}
			}
			refresh(serchList);
		}
	}

	/**
	 * serchReaderHandler: ʵ���˵㡰����-�������ˡ�ʱ�Ĺ��ܡ�����������ʾָ�������˵�����
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class serchReaderHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			serchList.clear();
			for (int i = 0; i < list.size(); i++)
			{
				if (list.get(i).reader.equals(readerT.getText()))
				{
					serchList.add(list.get(i));
				}
			}
			refresh(serchList);
		}
	}

	/**
	 * sortPriceHandler: ʵ���˵㡰����-���۸�ʱ�Ĺ��ܡ������۸�ӵ͵���������ʾ����
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class sortPriceHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Comparator<Book> comparator = new priceComp();// //////////////////
			Collections.sort(list, comparator);
			refresh(list);
		}

	}

	/**
	 * pricComp: ���۸�ȽϵıȽ�����ʵ���˽ӿ�Comparator<Book>
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class priceComp implements Comparator<Book>
	{
		public int compare(Book book1, Book book2)// //////////////////////
		{
			return book1.price.compareTo(book2.price);
		}
	}

	/**
	 * sortDateHandler: ʵ���˵㡰����-���������ڡ�ʱ�Ĺ��ܡ������������ڴӵ͵���������ʾ����
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	private class sortDateHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Comparator<Book> comparator = new dateComp();
			Collections.sort(list, comparator);
			refresh(list);
		}
	}

	/**
	 * dateComp: ���������ڱȽϵıȽ�����ʵ���˽ӿ�Comparator<Book>
	 * 
	 * @author zhaoyuan
	 * @version 1.0
	 */
	class dateComp implements Comparator<Book>
	{
		public int compare(Book book1, Book book2)
		{
			return book1.buyDate.compareTo(book2.buyDate);
		}
	}

	/**
	 * main�� ������
	 * 
	 * @param args
	 * @author zhaoyuan
	 */
	public static void main(String[] args)
	{
		Library app = new Library();
		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.setSize(800, 500);
		app.setVisible(true);

	}

}
