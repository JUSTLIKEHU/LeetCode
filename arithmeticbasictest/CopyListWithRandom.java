package arithmeticbasictest;

import java.util.HashMap;

public class CopyListWithRandom {

	public static class Node {
		public int value;
		public Node next;
		public Node rand;

		public Node(int data) {
			this.value = data;
		}
	}

	
	public static void main(String[] args) {
		
		Node head = null;
		Node res1 = null;
		Node res2 = null;
		
		head = new Node(1);
		head.next = new Node(2);
		head.next.next = new Node(3);
		head.next.next.next = new Node(4);
		head.next.next.next.next = new Node(5);
		head.next.next.next.next.next = new Node(6);

		head.rand = head.next.next.next.next.next; // 1 -> 6
		head.next.rand = head.next.next.next.next.next; // 2 -> 6
		head.next.next.rand = head.next.next.next.next; // 3 -> 5
		head.next.next.next.rand = head.next.next; // 4 -> 3
		head.next.next.next.next.rand = null; // 5 -> null
		head.next.next.next.next.next.rand = head.next.next.next; // 6 -> 4
		
		printRandomList(head);
		res1 = copyRandomList2(head);
		printRandomList(res1);
		printRandomList(head);
	}


	

	//��ԭ����͸���������һ��
	public static Node copyRandomList2(Node head) {
		
		while(head==null){
			return null;
		}
		
		Node cur = head;
		Node next;
		//�����ƽڵ����β���ԭ������
		while(cur != null){
			next = cur.next;
			cur.next = new Node(cur.value);
			cur.next.next = next;
			cur = next;
		}
		
		//������ڵ����ϡ�
		cur = head;
		Node copynode = null;
		while(cur !=null){
			next = cur.next.next;
			copynode = cur.next;
			copynode.rand = cur.rand == null? null : cur.rand.next;
			cur = next;
		}
		Node res = head.next;//�������������ͷ��㡣
		//�����������ԭ������롣
		cur = head;
		while(cur != null){
			next = cur.next.next;
			copynode = cur.next;
			cur.next = next;
			copynode.next = next == null ? null : next.next;
			cur = next;
		}
		
		return res;
	}





	//��hashmap�ķ���ʵ�֡�
	public static Node copyRandomList1(Node head) {
		
		HashMap<Node,Node> hm =new  HashMap<Node,Node>();
		Node cur = head;
		//�������Լ��临�ƴ洢��map�����С�
		while(cur != null){
			hm.put(cur, new Node(cur.value));
			cur = cur.next;
		}
		Node copynode = hm.get(head);
		cur = head;
		//�������ɵĽڵ㰴��ԭ�ڵ�ķ�ʽ���ӡ�
		while(cur !=null ){
			hm.get(cur).next = hm.get(cur.next);
			hm.get(cur).rand = hm.get(cur.rand);
			cur = cur.next;
		}
		
		return copynode;
	}

	public static void printRandomList(Node head) {
		
		System.out.print("order: ");
		Node cur = head;
		
		while(cur != null){
			System.out.print(cur.value+" ");
			cur = cur.next;
		}
		System.out.println();
		
		System.out.print("rand:  ");
		cur = head;
		while(cur != null){
			System.out.print(cur.rand == null?"- " : cur.rand.value+" ");
			cur = cur.next;
		}
		System.out.println();
		
	}

}
