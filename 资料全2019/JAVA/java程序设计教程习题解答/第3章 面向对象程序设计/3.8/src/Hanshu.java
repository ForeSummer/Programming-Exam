import javax.swing.JOptionPane;


public class Hanshu {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		int a = Integer.parseInt(JOptionPane.showInputDialog("����"));
		int b = Integer.parseInt(JOptionPane.showInputDialog("����"));
		int c = Integer.parseInt(JOptionPane.showInputDialog("����"));
		
		double x = Math.sqrt(0.0+b*b-4*a*c);
		double result1 = (0.0-b+x)/(a*2);
		double result2 = (0.0-b-x)/(a*2);
		System.out.println("��һ������ "+result1+" �ڶ������� "+result2);
	}

}
