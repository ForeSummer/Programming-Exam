package thu.hcguo.simplemath;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * ����,����1�ͱ�����,���ܱ������κ���Ȼ����������Ȼ�����ֽ�����������С��������2.
 */
public class Prime {
	public static boolean isPrime(int num) {
		for(int i = 2; i < num; i++) {
			if(num % i == 0) 
				return false;
		}
		return true;
	}
	
	/**
	 * �ӿ���̨����һ���������ҳ�С�ڸ���������������
	 */
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = 0;
		try {
			num = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		for(int i = 1; i < num; i++) {
			if(isPrime(i))
				System.out.println(i);
		}
	}
}
