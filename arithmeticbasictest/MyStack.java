package arithmeticbasictest;

public class MyStack {

	private int[] arr;
	private int size;
	
	public MyStack( int startsize) throws Exception {
		if(startsize<0){
			throw new Exception("ÊäÈëÓÐÎó");
		}
		arr = new int[startsize];
		size = 0;
	}
	
	public void push(int num) throws Exception{
		if(size == arr.length){
			throw new Exception("the stack is full!");
		}
		arr[size++] = num;
	}
	
	public int pop() throws Exception{
		if(size == 0){
			throw new Exception("the stack is empty!");
		}
		return arr[--size];
	}
	
	public int peek() throws Exception{
		if(size == 0){
			throw new Exception("the stack is empty!");
		}
		return arr[size-1];
	}

	public boolean isEmpty(){
		
		return size>0?false:true;
	}

	public static void main(String[] args) throws Exception {
		
		MyStack ms = new MyStack(10);
		ms.push(1);
		ms.pop();
		ms.push(2);
		ms.push(3);
		ms.push(4);
		ms.push(5);
		ms.push(2);
		ms.pop();
		ms.push(3);
		ms.push(4);
		ms.push(5);
		ms.push(2);
		ms.push(3);
		while(!ms.isEmpty()){
			System.out.println(ms.pop());
		}
		
	}

}
