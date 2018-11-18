package arithmeticbasictest;

public class MyQueue {

	private int[] arr;
	private int first;
	private int last;
	private int size;
	
	public MyQueue(int initsize) throws Exception{
		if(initsize<0){
			throw new Exception("Input Error!!!");
		}
		arr = new int[initsize];
		first = 0;
		last = 0;
		size = 0;
	}
	
	public void push(int num) throws Exception{
		if(size == arr.length){
			throw new Exception("The Queue is full!!!");
		}
		arr[last] = num;
		last = last==arr.length-1?0:last+1;
		size++;
	}
	
	public int poll() throws Exception{
		if(size<1){
			throw new Exception("The Queue is empty!!!");
		}
		int temp = first;
		first = first==arr.length-1?0:first+1;
		size--;
		return arr[temp];
	}
	
	public int peek() throws Exception{
		if(size<1){
			throw new Exception("The Queue is empty!!!");
		}
		return arr[first];
	}
	
	public boolean isEmpty(){
		return size<1?true:false;
	}
	
	public static void main(String[] args) throws Exception {
		
		MyQueue mq = new MyQueue(5);
		mq.push(1);
		mq.push(2);
		mq.push(3);
		mq.poll();
		mq.push(4);
		mq.push(5);
		
		while(!mq.isEmpty()){
			System.out.println(mq.poll());
		}

	}

}
