import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class One {

	public static void main(String[] args) {
		generate(getN());
	}

	public static void generate(int n) {
		System.out.println("----------------");
		Random r = new Random();
		int range = 10;
		int[] count = new int[range]; //��������������¼1-100֮���ÿ�������ֵĴ���
		int maxCount = 0;
		for (int i = 0; i < n; ++i) {
			int index = r.nextInt(range);
			System.out.println(index);
			++count[index];

			if (maxCount < count[index]) { //��¼���ĳ��ִ���
				maxCount = count[index];
			}
		}
		System.out.println("----------------");

		for (int value = 0; value < range; ++value) {
			if (count[value] == maxCount) { //�ж�ĳ�������ֵĴ��������������г��ֵ�������
				System.out.println(value + "  |   count:" + count[value]);
			}
		}

	}

	//����û��������
	public static int getN() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = 0;
		try {
			String s = br.readLine();
			n = Integer.parseInt(s);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		return n;
	}
}
