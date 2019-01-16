package test;

import java.io.FileInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


/**
 * Created with IntelliJ IDEA.
 * User: Lusar
 * Date: 12-8-9
 * To change this template use File | Settings | File Templates.
 */
public class Test1 {
	
    public static void main(String args[]) throws IOException{
//    	testReadFromConsole();
//    	testBigIntegerOpt();
//    	testGcdByBruteForce();
//    	testStringSplit();
    }
    
    //Test-1 �ӿ���̨��ȡ����
    public static void testReadFromConsole(){
    	Scanner scanner = new Scanner(System.in);
    	int 		i 		  = scanner.nextInt();	//��ȡInt����
    	String 		str 	  = scanner.next();		//��ȡString����...
    	double 		dtest 	  = scanner.nextDouble();
    	BigInteger 	bgIntTest = scanner.nextBigInteger();
    	
    	System.out.println("int:" + i);
    	System.out.println("str:" + str);
    	System.out.println("dob:" + dtest);
    	System.out.println("bint:" + bgIntTest);
    }
  
    //Test-2 ���ı��ļ���ȡ����
    public static void testReadFromFile() throws IOException{
    	Scanner scanner = new Scanner(new FileInputStream("E:\\�μ�\\Java�����Ը���\\test.txt"));
    	int 		i 		  = scanner.nextInt();	//��ȡInt����
    	String 		str 	  = scanner.next();		//��ȡString����...
    	double 		dtest 	  = scanner.nextDouble();
    	BigInteger 	bgIntTest = scanner.nextBigInteger();
    	
    	System.out.println("int:" + i);
    	System.out.println("str:" + str);
    	System.out.println("dob:" + dtest);
    	System.out.println("bint:" + bgIntTest);
    }
    
    
    //Test-3 �����Ĳ���
    public static void testBigIntegerOpt(){
    	Scanner scanner = new Scanner(System.in);
    	BigInteger big1 = scanner.nextBigInteger();
    	BigInteger big2 = scanner.nextBigInteger();
    	BigInteger big3 = big1.add(big2);
    	System.out.println(big3);
    }
    
    //Test-4 ��������֮������Լ��
    public static void testGcdByBruteForce(){
    	Scanner scanner = new Scanner(System.in);
    	int x = scanner.nextInt();
    	int y = scanner.nextInt();
    	for(int i = Math.min(x, y); i > 0; i--){
    		if(((x % i) == 0) &&
    				((y % i) == 0)){
    			System.out.println("gcd = " + i);
    			break;
    		}
    	}
    }
    //Test-5 test string split.
    public static void testStringSplit(){
    	Scanner scanner = new Scanner(System.in);
    	scanner.useDelimiter(" |,|\\.");	//�ո񣬶��ţ���ţ�������Ϊ��ȡ�ָ��.
    	String  content  = scanner.nextLine();
    	
    	for(String sub : content.split(" ")){
    		System.out.println(sub);
    	}
    }
}
