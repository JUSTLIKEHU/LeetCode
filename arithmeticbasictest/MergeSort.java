package arithmeticbasictest;


//实现归并排序的算法实现。

public class MergeSort {

	public static void main(String[] args) {
		int[] arr = {69,70,36,47,35,77,64,45,99,19};
		
		mergeSort(arr);

		for(int i = 0;i<arr.length;i++){
			System.out.print(arr[i]+" ");
		}
	}

	public static void mergeSort(int[] arr) {
		if(arr==null || arr.length<2){
			return;
		}
		mergeSort(arr,0,arr.length-1);
	}

	public static void mergeSort(int[] arr, int l, int r) {
		
		if(l==r){
			return;
		}
		int mid = l+ ((r-l)>>1);
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
		
	}

	public static void merge(int[] arr, int l, int mid, int r) {
		
		int[] help = new int[r-l+1];
		int i = 0;
		int left = l;
		int right = mid+1;
		while(left<=mid && right<=r){
			help[i++] = arr[left]>arr[right]?arr[right++]:arr[left++];
		}
		while(left<=mid){
			help[i++] = arr[left++];
		}
		while(right<=r){
			help[i++] = arr[right++];
		}
		
		for(int j = 0;j<r-l+1;j++){
			arr[l+j] = help[j];
		}
	}
	
	

}
