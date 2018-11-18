package arithmeticbasictest;

/*
 * 需求：Z子型打印二维数组。
 * */

public class ZigZagPrint {

	public static void main(String[] args) {
	
		int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
		printZigZagMatrix(matrix);
	}

	public static void printZigZagMatrix(int[][] matrix) {
		
		int aR = 0 ;
		int aC = 0 ;
		int bR = 0 ;
		int bC = 0 ;
		int endR = matrix.length-1;
		int endC = matrix[0].length-1;
		boolean flag = false;//判断斜向上打印还是斜向下打印。
		
		while(aR != endR + 1){
			printNum(matrix,aR,aC,bR,bC,flag);
			aR = aC == endC ? aR+1 : aR ;
			aC = aC == endC ? aC : aC+1 ;
			bC = bR == endR ? bC+1 : bC ;//先判断列载判断行，否则会出现打印错误。
			bR = bR == endR ? bR : bR+1 ;
			flag = !flag;
		}
		System.out.println();
		
	}

	public static void printNum(int[][] m, int aR, int aC, int bR,
			int bC, boolean flag) {
		
		if(flag){
			while(aR != bR + 1){
				System.out.print(m[aR++][aC--] + " ");
			}
		}else{
			while(bR != aR - 1){
				System.out.print(m[bR--][bC++] + " ");
			}
		}
		
	}

	
	
}
