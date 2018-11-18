package arithmeticbasictest;

public class FindNumInSortedMatrix {

	public static void main(String[] args) {
		
		
		int[][] Matrix = {{1,3,5,7},{3,5,9,10},{7,10,13,15}} ;
		int a = 3 ;
		System.out.println(findNumber(a,Matrix));
		
	}

	public static boolean findNumber(int a, int[][] m) {
		
		int endR = m[0].length-1;
		int endC = m.length - 1;
		int r = 0;
		int c = endC;
		
		while(r != endR+1 && c >= 0){
			if(m[r][c] == a){
				return true;
			}else if(m[r][c] < a){
				r++;
			}else{
				c--;
			}
		}
		
		return false;
		
	}

	
}
