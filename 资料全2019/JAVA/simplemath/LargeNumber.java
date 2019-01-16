package thu.hcguo.simplemath;

import java.math.BigDecimal;
import java.math.BigInteger;

/**
 * ���������㴦��
 */
public class LargeNumber {
	/**
	 * �����ӣ������ˣ���
	 * @param big1
	 * @param big2
	 */
	public static void calculate(BigDecimal big1, BigDecimal big2) {
		System.out.println(big1.add(big2));
		System.out.println(big1.subtract(big2));
		System.out.println(big1.multiply(big2));
		System.out.println(big1.divide(new BigDecimal("2.5")));
	}
	
	/**
	 * ���ô���������׳�
	 * @param num
	 */
	public static void factorial(int num) {
		BigInteger res = new BigInteger("1");
		for(int i = 1; i <= num; i++) {
			res = res.multiply(new BigInteger(""+i));
		}
		System.out.println(res);
	}
	
	public static void main(String[] args) {
		BigDecimal big1 = new BigDecimal("54646548787841321549879856135132154");
		BigDecimal big2 = new BigDecimal("1234123412341235645736756");
		calculate(big1, big2);
		factorial(35);
	}
}
