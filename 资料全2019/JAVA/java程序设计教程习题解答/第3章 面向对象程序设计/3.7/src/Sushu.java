import javax.swing.JOptionPane;


public class Sushu {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = JOptionPane.showInputDialog("������һ����","2");
		int num = Integer.parseInt(str);
		for (int i=2;i<num/2+1;i++){
			if(num%i==0){
				System.out.println("���� "+num+" ��������");
				System.exit(0);
			}
			
		}
		
		System.out.println("���� "+num+" ������");
	}

}
