package arithmeticbasictest;

/*
 * ����Ŀ�� ����һ�������ͷ�ڵ�head�����жϸ������Ƿ�Ϊ��
		     �Ľṹ�� ���磺 1->2->1������true�� 1->2->2->1������true��
	      15->6->15������true�� 1->2->3������false��
 * */

import java.util.Stack;

public class IsPalindromeList {

	public static class ListNode{
		
		public int value;
		public ListNode next;
		
		public ListNode(int value){
			this.value = value;
		}
		
	}
	
	public static void main(String[] args) {

		ListNode head = new ListNode(1);
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(2);
		head.next.next.next.next = new ListNode(1);
		
		printLinkList(head);
		
		System.out.println(isPalindrome2(head));
		
		printLinkList(head);
	}

	public static void printLinkList(ListNode node) {
		
		System.out.print("LinkList:");
		while(node!=null){
			System.out.print(node.value+" ");
			node = node.next;
		}
	}

	public static boolean isPalindrome1(ListNode head){
		
		Stack<ListNode> stack = new Stack<ListNode>();
		ListNode n1 = head;
		while(n1 != null){
			stack.push(n1);
			n1 = n1.next;
		}
		boolean res = true;
		while(head != null ){
			if(head.value != stack.pop().value){
				res = false;
			}
			head = head.next;
		}
		return res;
	}
	
	//����ռ临�Ӷ�ΪO(1)�ķ�����
	/*
	 * ˼·��Ҫ��ֻ�ڸ����������в���������ʹ�ö���Ŀռ䡣
	 * 1�����ҳ�������ص㡣
	 * 2���ҵ�������е�󣬽�������Ҳ෴ת�������е㴦��ָ��ָ��սڵ㡣
	 * 3�����������α�������һ�ж��ڵ�ֵ�Ƿ���ȡ�
	 * 4���жϽ�������Ҫ������ԭ�����·�ת��
	 * */
	public static boolean isPalindrome2(ListNode head){
		
		if(head == null && head.next == null){
			return false;
		}
		
		boolean res = true;
		
		ListNode n1 = head;
		ListNode n2 = head;
		//�ҵ�������е㡣
		while(n2.next != null && n2.next.next != null){
			n1 = n1.next;
			n2 = n2.next.next;
		}
		
		n2 = n1.next;
		n1.next = null;
		ListNode n3 = null;
		//���м�ڵ��Ҳ������ת��ָ���м�ڵ㡣
		while(n2 != null){
			n3 = n2.next;
			n2.next = n1;
			n1 = n2 ;
			n2 = n3 ;
		}
		
		n3 = n1;//�����Ҳ��ͷ��㡣
		n2 = head;
		//�ж���������Գ�λ���Ƿ���ȡ�
		while(n1 != null && n2 != null){
			if(n1.value != n2.value){
				res = false;
			}
			n1 = n1.next;
			n2 = n2.next;
		}
		
		//���Ҳ������ԭ��
		
		n1 = null;
		while(n3 != null){
			n2 = n3.next;
			n3.next = n1;
			n1 = n3;
			n3 =n2;
		}
		
		return res;
	}
	
	
}
