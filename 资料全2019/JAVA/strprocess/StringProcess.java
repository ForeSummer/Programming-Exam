package thu.hcguo.strprocess;

import java.text.SimpleDateFormat;
import java.util.Date;

public class StringProcess {

	public static void process(String str1, String str2) {
		// str1 < str2 ���ظ���; str1 = str2 ����0; str1 > str2 ��������
		System.out.println(str1.compareTo(str2));

		// ���Դ�Сд�ıȽ� str1.compareToIgnoreCase(str2);
		System.out.println(str1.compareToIgnoreCase(str2));
		
		// ��str2ƴ�ӵ�str1��
		System.out.println(str1.concat(str2));
		
		// str1�Ƿ����str2
		System.out.println(str1.contains(str2));
		
		// str1�Ƿ���str2���
		System.out.println(str1.equals(str2));
		
		// str1�Ƿ���str2���(���Դ�Сд)
		System.out.println(str1.equalsIgnoreCase(str2));
		
		// ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�������
		System.out.println(str1.indexOf(str2));

		// ����ָ�����ַ����ڴ��ַ��������ұ߳��ִ�������
		System.out.println(str1.lastIndexOf(str2));

		// ���ݸ���������ʽ��ƥ���ִ��ַ���
		for (String str : str1.split(" ")) {
			System.out.println(str);
		}

		// ʹ��Ĭ�����Ի����Ĺ��򽫴� String �е������ַ���ת��ΪСд
		System.out.println(str1.toLowerCase());
		
		// ʹ��Ĭ�����Ի����Ĺ��򽫴� String �е������ַ���ת��Ϊ��д
		System.out.println(str1.toUpperCase());

		// �����ַ����ĸ���������ǰ���հ׺�β���հ�
		System.out.println(str1.trim());

		// ����һ�����ַ��������Ǵ��ַ�����һ�����ַ����������ַ�����ָ���� beginIndex ����ʼ��ֱ������ endIndex - 1
		// �����ַ�����ˣ������ַ����ĳ���Ϊ endIndex-beginIndex
		System.out.println(str1.substring(1,3));
		
		// �ַ����滻
		System.out.println(str1.replace("a", "b"));
		
		// ����boolean char int double float long�Ȳ������ַ�����ʾ��ʽ��
		// ����str1��������������
		System.out.println(String.valueOf(str1));
		
		// ����һ���µ� double ֵ����ֵ����ʼ��Ϊ��ָ�� String ��ʾ��ֵ������ Double ��� valueOf ����һ����
		// ����param����String���ͣ����Ƶĺ�������Integer.parseInt(param)��
		// ����ͨ����������������쳣�����ж�param�Ƿ��ǿ��Խ���Ϊdouble
		System.out.println(Double.parseDouble(str1));
		
		// ���ڵĴ���
		Date date = new Date();
		System.out.println(date);
		SimpleDateFormat format = new SimpleDateFormat("yyyy-mm-dd hh:mm:ss");
		System.out.println(format.format(date));
	}
	
	public static void main(String[] args) {
		String str1 = "23.5";
		String str2 = "asdfj";
		process(str1, str2);
	}
}
