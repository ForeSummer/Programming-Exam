package MyGraph;

import java.awt.geom.Point2D;

public class MyMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Point2D.Double p1 = new Point2D.Double(1.0,1.0);
		Point2D.Double p2 = new Point2D.Double(1.0,2.0);
		Point2D.Double p3 = new Point2D.Double(3.0,1.0);
		
		Three t = new Three(p1,p2,p3);
		System.out.println("�������ܳ��ǣ�" +t.zhouchang());
		System.out.println("����������ǣ�" +t.mianji());
		
		
		Point2D.Double p = new Point2D.Double(5.0,5.0);
		double length = 3;
		Four f  = new Four(p,length);
		System.out.println("�������ܳ��ǣ�" +f.zhouchang());
		System.out.println("����������ǣ�" +f.mianji());
		
		
		Point2D.Double c = new Point2D.Double(5.0,5.0);
		double r = 3;
		
		Circle s = new Circle(c,r);
		System.out.println("Բ�ܳ��ǣ�" +s.zhouchang());
		System.out.println("Բ����ǣ�" +s.mianji());
		
		
		Point2D.Double w1 = new Point2D.Double(3.0,3.0);
		Point2D.Double w2 = new Point2D.Double(3.0,2.0);
		Five w = new Five(w1,w2);
		System.out.println("������ܳ��ǣ�" +w.zhouchang());
		System.out.println("���������ǣ�" +w.mianji());
	}

}
