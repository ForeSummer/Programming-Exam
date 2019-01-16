package src;

import java.math.*;

public class BigIntegerDemo
{

	public static void testBigInteger()
	{
		BigInteger bi = new BigInteger("888");
		BigInteger result = bi.multiply(new BigInteger("2"));//�����˷�
		System.out.println(result);

		result = bi.divide(new BigInteger("2"));//��������
		System.out.println(result);

		result = bi.add(new BigInteger("232"));//�����ӷ�
		System.out.println(result);

		result = bi.subtract(new BigInteger("23122"));//��������
		System.out.println(result);

		result = bi.shiftRight(10);//��λ
		System.out.println(result);

	}

	public static void testBigDecimal()
	{
		BigDecimal bi = new BigDecimal("888.888");
		BigDecimal result = bi.multiply(new BigDecimal("2.3"));//С���˷�
		System.out.println(result);

		result = bi.divide(new BigDecimal("90.4"), 2);//С������
		System.out.println(result);

		result = bi.add(new BigDecimal("232.34"));//С���ӷ�
		System.out.println(result);

		result = bi.subtract(new BigDecimal("343.3434"));//С������
		System.out.println(result);

	}

	public static void main(String[] args)
	{
		System.out.println("�������������㣺");
		testBigInteger();
		System.out.println("");
		System.out.println("������С�����㣺");
		testBigDecimal();
	}

}