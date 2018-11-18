package arithmeticbasictest;

public class QuickSort {

	public static void main(String[] args) {
		
		int[] arr = {69,70,36,47,35,77,64,45,99,19};
		printArray(arr);
		quickSort(arr,0,arr.length-1);
		printArray(arr);
	}

	public static void quickSort(int[] arr, int l, int r) {
		
		if(l<r){
			swap(arr,l+(int)(Math.random()*(r-l+1)),r);//Ëæ»ú¿ìÅÅ¡£
			int[] p = partition(arr,l,r);
			quickSort(arr,l,p[0]);
			quickSort(arr,p[1],r);
		}
	}

	
	public static int[] partition(int[] arr, int l, int r) {
		
		int less = l-1;
		int more = r;
		while(l<more){
			if(arr[l]<arr[r]){
				swap(arr,l++,++less);
			}else if(arr[l]>arr[r]){
				swap(arr,l,--more);
			}else{
				l++;
			}
		}
		swap(arr,r,more++);
		return new int[]{less,more}; 
	}

	public static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		
	}

	public static void printArray(int[] arr) {
		for(int i = 0 ; i < arr.length;i++){
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
}
