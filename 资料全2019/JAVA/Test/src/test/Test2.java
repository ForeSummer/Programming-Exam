package test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * 
 * @author Lusar
 *
 */
public class Test2 {
	
	public static void main(String args[]){
		testStringReplace();
		testStringSplit();
		testStringPattern();
		testStringFind();		
		testStringSort();
		testStringPermutation();
	}
	
	//test-1 �ַ����滻
	public static void testStringReplace(){
		String test   = "my dog";
		String result = "";	
		result = test.replaceAll("my", "hello");	 //��һ���滻������������ʽ��
		result = result.replaceFirst("dog", "kitty");//ʹ��ʱ��ע�����������ַ���ת�� 
		System.out.println(result);
	}
	
	//test-2 �ַ��ָ�
	public static void testStringSplit(){
		String   test = "aa,ddd,ddd;ddwl;dsfa-aflksdfa.ksdf";
		String[] subs = test.split("(,|;|-|\\.)"); //ע�⣺ 1) split������������ʽ
		                                           //      2) ����"."��Ҫת��Ϊ"\\."
		System.out.println(Arrays.toString(subs)); //      3) �ָ������ƥ���������ʽ
	}
	
	//test-3 �ַ���ƥ��
	public static void testStringPattern(){
	    //ͨ��compile������������Patternʵ��  
        Pattern pattern = Pattern.compile("java"); //��������������ʽ
        //ͨ��match��������Matcherʵ��  
        Matcher matcher=pattern.matcher("java Java java JAVA jAva");  
        while (matcher.find())//���ҷ���pattern���ַ���  
        {  
            System.out.println("The result is here :" +   
                    matcher.group() + "\n" + "It starts from "  
                    + matcher.start() + " to " + matcher.end() + ".\n");  
        }  
        System.out.println("Java".matches("(?i)(java)"));  
	}
	
	//test-4 �ַ�������
	public static void testStringFind(){
		String test = "To do or not to do, it's your ...";
		int idx1 = test.indexOf("do");
		int idx2 = test.lastIndexOf("do");
		int idx3 = test.indexOf("can");			//û���ҵ�ʱ������-1
		
		System.out.println(idx1+" " +idx2+" " +idx3);
	}
	
	//test-5 �ַ�������
	public static void testStringSort(){
		List<String> test1 = new ArrayList<String>(4);
		test1.add("test");
		test1.add("sort");
		test1.add("string");
		test1.add("void");
		Collections.sort(test1);	//List sort	
		System.out.println(Arrays.toString(test1.toArray()));
		
		String[] test = "test,sort,string,void".split(",");
		Arrays.sort(test);			// Array sort
		System.out.println(Arrays.toString(test));
		
		//�Զ�����������
		Collections.sort(test1,new Comparator<String>(){
			@Override
			public int compare(String arg0, String arg1) {
				return arg1.compareTo(arg0);
			}
			
		});
		System.out.println(Arrays.toString(test1.toArray()));
	}
	
	//test-6 �ַ���֮ȫ����
	public static void testStringPermutation(){
		String 	 test 	= "312";
		System.out.println(Arrays.toString(permutation(test)));
	}
	
	private static String[] permutation(String orginal){
	        ArrayList<String> list = new ArrayList<String>();
	        if(orginal.length() == 1){
	            return new String[]{orginal};//���ص�ǰ�ַ�
	        } else{
	            for (int i = 0; i < orginal.length(); i++) {
	                String s = orginal.charAt(i) + "";
	                String result = "";
	                String resultA = "" + s;
	                String leftS = orginal.substring(0, i) + orginal.substring(i + 1, orginal.length());
	                for (String element : permutation(leftS)) {
	                    result = resultA + element; 
	                    list.add(result);
	                }
	            }
	            return (String[]) list.toArray(new String[list.size()]);
	        }
	  }
}
