import javax.swing.JOptionPane;


public class BuMa {

	/**
	 * @param args
	 */
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str;
		str = JOptionPane.showInputDialog("������һ������","0");
		int num = Integer.parseInt(str);
		String result2 = Integer.toBinaryString(num);
		String result8 = Integer.toOctalString(num);
		String result16 = Integer.toHexString(num);
		
		
		
		System.out.println("��������Ϊ:"+result2);
		System.out.println("�˽�����Ϊ:"+result8);
		System.out.println("ʮ��������Ϊ:"+result16);
	}

}
