enum Week {����һ,���ڶ�,������,������,������,������,������}
public class Enum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Week [] w = Week.values();
		for(int i=0;i<w.length;i++){
			System.out.print(" "+w[i].name());
		}
			
	}

}
