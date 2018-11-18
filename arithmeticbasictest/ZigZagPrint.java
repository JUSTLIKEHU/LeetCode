package arithmeticbasictest;

/*
 * ����Z���ʹ�ӡ��ά���顣
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
		boolean flag = false;//�ж�б���ϴ�ӡ����б���´�ӡ��
		
		while(aR != endR + 1){
			printNum(matrix,aR,aC,bR,bC,flag);
			aR = aC == endC ? aR+1 : aR ;
			aC = aC == endC ? aC : aC+1 ;
			bC = bR == endR ? bC+1 : bC ;//���ж������ж��У��������ִ�ӡ����
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
