import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Shuru {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			System.out.print("�������һ��������");
			int a = Integer.parseInt(bf.readLine());
		
			System.out.print("������ڶ���������");
			int b = Integer.parseInt(bf.readLine());
			
			System.out.println("��������"+a+"+"+b+"="+(a+b));
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
