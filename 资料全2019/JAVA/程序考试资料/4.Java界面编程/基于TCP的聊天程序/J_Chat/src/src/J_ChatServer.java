package src;

// ////////////////////////////////////////////////////////
// 
// J_ChatServer.java
// 
// 
// ���:����TCP���������̡����������˳��򲿷�
//
// ////////////////////////////////////////////////////////

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JScrollPane;

@SuppressWarnings("serial")
public class J_ChatServer extends JFrame
{
	private ObjectInputStream m_input; // ������
	private ObjectOutputStream m_output; // �����
	private JTextField m_enter; // ��������
	private JTextArea m_display; // ��ʾ����
	private int m_clientNumber = 0; // ���ӵĿͻ���

	/** ���췽�������� ��ͼ�ν����������� */
	public J_ChatServer()
	{
		super("��������������");
		Container c = getContentPane();// �����Ȼ�ȡJFrame������壬Ȼ����������������Ǻ�awt����ͬ�ĵط�
		m_enter = new JTextField();
		m_enter.setEnabled(false);// ��δ����ǰ�����Ϊ����״̬

		m_enter.addActionListener(new ActionListener()// ����ע��ļ���������Ӧ�ı����������ı��󰴻س�����¼�
				{
					public void actionPerformed(ActionEvent event)
					{
						try
						// ��ͻ��˷�������
						{
							String s = event.getActionCommand();// ��ȡ�ı��������������
							m_output.writeObject(s);// ��ObjectOutputStreamд���ض��Ķ���
							m_output.flush();// ˢ���������ǿ�ƻ������е�����ֽڱ�д��
							mb_displayAppend("��������: " + s);// �ڱ�����ʾ�ոշ���ȥ������
							m_enter.setText(""); // ������������ԭ������
						}
						catch (Exception e)
						{
							System.err.println("�����쳣:" + e);
							e.printStackTrace();
						} // try-catch�ṹ����
					} // ����actionPerformed����
				} // ʵ�ֽӿ�ActionListener���ڲ������
				); // addActionListener�������ý���

		c.add(m_enter, BorderLayout.NORTH);
		m_display = new JTextArea();
		c.add(new JScrollPane(m_display), BorderLayout.CENTER);// ���һ��������壬������m_display��JTextArea��
	}

	/** �������˵���ʾ���� */
	public void mb_displayAppend(String s)
	{
		m_display.append(s + "\n");// ��JTextArea�ı�����׷��д����
		m_display.setCaretPosition(m_display.getText().length());// �������ֵ�����������ܹ��Զ������¹���
		m_enter.requestFocusInWindow(); // ����ת�����뽹�㵽��������
	}

	/** ���Կͻ��˵���ϢΪ������Щ�ַ��������ͻ���������� */
	public boolean mb_isEndSession(String m)
	{
		if (m.equalsIgnoreCase("q"))
			return (true);
		if (m.equalsIgnoreCase("quit"))
			return (true);
		if (m.equalsIgnoreCase("exit"))
			return (true);
		if (m.equalsIgnoreCase("end"))
			return (true);
		if (m.equalsIgnoreCase("����"))
			return (true);
		return (false);
	}

	/** �������˵����к��� */
	public void mb_run()
	{
		try
		{
			ServerSocket server = new ServerSocket(5000);// ָ���˿ں�Ϊ5000
			String m; // ���Կͻ��˵���Ϣ

			while (true)// ���ϼ��ͻ����Ƿ�����������
			{
				m_clientNumber++;
				mb_displayAppend("�ȴ�����[" + m_clientNumber + "]");
				Socket s = server.accept();
				mb_displayAppend("���յ��ͻ�������[" + m_clientNumber + "]");

				m_output = new ObjectOutputStream(s.getOutputStream());
				m_input = new ObjectInputStream(s.getInputStream());
				m_output.writeObject("���ӳɹ�");// ��ObjectOutputStreamд���ض�����ע��ͻ����Ǳ߻��Լ����ϡ��������ˣ���������ǰ׺��
				m_output.flush();// ˢ���������ǿ�ƻ������е�����ֽڱ�д��
				m_enter.setEnabled(true);

				do// �������Կͻ��˵���Ϣ
				{
					m = (String) m_input.readObject();// ��ObjectInputStream��ȡ��������ǿ��ת����String����
					mb_displayAppend("�ͻ���: " + m);// ��ʾ�ڷ�������
				}
				while (!mb_isEndSession(m));// ���ͻ��˷�������Ϣ���ǽ�����ʶʱ����һֱ��ȡ����ʾ��Ϣ������ͻ����˳�����

				m_output.writeObject("q"); // ֪ͨ�ͻ����˳�����
				m_output.flush();
				m_enter.setEnabled(false);
				m_output.close();// �ر������
				m_input.close();// �ر�������
				s.close();// �ر������׽���

				mb_displayAppend("����[" + m_clientNumber + "]����");
			} // whileѭ������
		}
		catch (Exception e)
		{
			System.err.println("�����쳣:" + e);
			e.printStackTrace();
			mb_displayAppend("����[" + m_clientNumber + "]�����쳣");
		} // try-catch�ṹ����
	} // ����mb_run����

	public static void main(String args[])
	{
		J_ChatServer app = new J_ChatServer();

		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.setSize(350, 150);
		app.setVisible(true);

		app.mb_run();
	} // ����main����
} // ��J_ChatServer����
