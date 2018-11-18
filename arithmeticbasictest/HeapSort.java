package arithmeticbasictest;

public class HeapSort {

	public static void main(String[] args) {
		
		int[] arr = {69,70,36,47,35,77,64,45,99,19};
		
		heapSort(arr);
		
		printArray(arr);
	}

	private static void heapSort(int[] arr) {
		
		if(arr == null || arr.length<2){
			return;
		}
		for(int i = 0; i<arr.length; i++){
			heapInsert(arr,i);
		}
		int size = arr.length;
		swap(arr,0,--size);
		while(size>0){
			heapify(arr,0,size);
			swap(arr,0,--size);
		}
		
		
	}

	public static void heapify(int[] arr, int index, int size) {
		int leftson = index*2+1;
		while(leftson<size){
			int largest = leftson+1<size && arr[leftson]<arr[leftson+1]?leftson+1:leftson;
			if(arr[index]>=arr[largest]){
				break;
			}else{
				swap(arr,index,largest);
				index = largest;
				leftson = index*2+1;
			}
		}
		
		
	}

	public static void heapInsert(int[] arr, int index) {
		
		while(arr[index]>arr[(index-1)/2]){
			swap(arr,index,(index-1)/2);
			index = (index-1)/2;
		}
		
		
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
