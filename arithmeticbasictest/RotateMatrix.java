package arithmeticbasictest;

public class RotateMatrix {

	public static void main(String[] args) {
	
		int[][] matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 },
				{ 13, 14, 15, 16 } };
		
		printMatrix(matrix);
		
		System.out.println("=====================");
		rotateMatrix(matrix);
		printMatrix(matrix);
	}

	public static void rotateMatrix(int[][] matrix) {
		
		int r0 =0;
		int c0 =0;
		int r1 =matrix.length-1;
		int c1 =matrix[0].length-1;
		
		while(r0<r1){
			rotateEdge(matrix,r0++,c0++,r1--,c1--);
		}
		
	}

	public static void rotateEdge(int[][] matrix, int r0, int c0, int r1,
			int c1) {

		if(matrix.length<2){
			return;
		}
		int times = r1-r0;
		for(int i = 0 ; i<times;i++){
			int temp = matrix[r0][c0+i];
			matrix[r0][c0+i] = matrix[r1-i][c0];
			matrix[r1-i][c0] = matrix[r1][c1-i];
			matrix[r1][c1-i] = matrix[r0+i][c1];
			matrix[r0+i][c1] = temp;	
		}
	}
	
	public static void printMatrix(int[][] matrix){
		for(int i = 0 ;i<matrix.length;i++){
			for(int j = 0 ; j<matrix[0].length;j++){
				System.out.print(matrix[i][j]+"  ");
				if(j==matrix[0].length-1){
					System.out.println();
				}
			}
		}
	}

}
