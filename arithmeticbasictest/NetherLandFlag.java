package arithmeticbasictest;

//ºÉÀ¼¹úÆìÎÊÌâ¡£

public class NetherLandFlag {

	public static void main(String[] args) {
		
		int[] arr = {1,0,2,2,1,1,1,1,2,2};
		printArray(arr);
		
		partition(arr,1);
		printArray(arr);
	}

	public static void partition(int[] arr, int num) {
		
		if(arr==null || arr.length<2){
			return;
		}
		partition(arr,0,arr.length-1,num);
		
	}
	
	public static int[] partition(int[] arr, int l, int r, int num) {
		
		int less = l-1;
		int more = r+1;
		int p = l;
		while(p<more){
			if(arr[p]<num){
				swap(arr,p++,++less);
			}else if(arr[p]>num){
				swap(arr,p,--more);
			}else{
				p++;
			}
		}
		return new int[]{less+1,more-1}; 
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
