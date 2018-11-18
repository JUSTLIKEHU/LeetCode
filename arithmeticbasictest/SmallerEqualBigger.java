package arithmeticbasictest;

public class SmallerEqualBigger {

	public static void main(String[] args) {
		
		Node head = new Node(7);
		head.next = new Node(9);
		head.next.next = new Node(1);
		head.next.next.next = new Node(8);
		head.next.next.next.next = new Node(5);
		head.next.next.next.next.next = new Node(2);
		head.next.next.next.next.next.next= new Node(5);

		printLinkList(head);
		
		Node n = linkPartition2(head,5);
		
		printLinkList(n);
	}

	public static Node linkPartition2(Node head, int num) {
		
		Node sH = null;
		Node sT = null;
		Node eH = null;
		Node eT = null;
		Node bH = null;
		Node bT = null;
		Node next = null;
		
		//将节点分别存入三个子链表中。
		while(head != null){
			next = head.next;
			head.next = null;
			if(head.value < num){
				if(sH == null){
					sH = head;
					sT = head;
				}else{
					sT.next = head;
					sT = head;
				}
			}else if(head.value == num){
				if(eH == null){
					eH = head;
					eT = head;
				}else{
					eT.next = head;
					eT = head;
				}
			}else{
				if(bH == null){
					bH = head;
					bT = head;
				}else{
					bT.next = head;
					bT = head;
				}
			}
			
			head = next;
		}
		
		//将子链表连接起来。
		if(sT != null){
			sT.next = eH;
			eT = eT == null? sT : eT;
		}
		if(eT != null){
			eT.next = bH;
			bT = bT == null? eT : bT;
		}
		
		return sH != null? sH : eH !=null? eH : bH; 
	}

	public static Node linkPartition(Node head, int num) {
		
		if(head == null){
			return null;
		}
		Node cur = head;
		int i = 0 ;
		while(cur != null){
			i++;
			cur = cur.next;
		}
		//建立临时数组存储节点。
		Node[] NodeArr = new Node[i];
		cur = head;
		i = 0;
		
		while( cur != null){
			NodeArr[i++] = cur;
			cur = cur.next;
		}
		//将数组按照荷兰国旗问题处理。
		arrPartition(NodeArr,num);
		for( i = 1; i<NodeArr.length ; i++){
			NodeArr[i-1].next = NodeArr[i];
		}
		NodeArr[NodeArr.length-1].next = null;
		
		return NodeArr[0];
		
	}

	public static void arrPartition(Node[] arr, int num) {
		
		int less = -1;
		int more = arr.length;
		int index = 0;
		while(index != more){
			if(arr[index].value < num){
				swap(arr,++less,index++);
			}else if(arr[index].value > num){
				swap(arr,--more,index);
			}else{
				index++;
			}
		}
		
	}

	public static void swap(Node[] arr, int i, int j) {
		
		Node temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void printLinkList(Node node) {
		
		System.out.print("Linked List: ");
		while( node != null){
			System.out.print(node.value + " ");
			node = node.next;
		}
		System.out.println();
	}

	
}
