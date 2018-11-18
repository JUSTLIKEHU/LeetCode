package arithmeticbasictest;

/*
 * 【题目】 给定一个链表的头节点head，请判断该链表是否为回
		     文结构。 例如： 1->2->1，返回true。 1->2->2->1，返回true。
	      15->6->15，返回true。 1->2->3，返回false。
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
	
	//额外空间复杂度为O(1)的方法。
	/*
	 * 思路：要求只在给定的链表中操作，不能使用额外的空间。
	 * 1，先找出链表的重点。
	 * 2，找到链表的中点后，将链表的右侧反转，并将中点处的指针指向空节点。
	 * 3，从两端依次遍历并逐一判定节点值是否相等。
	 * 4，判断结束后需要将链表还原，重新反转。
	 * */
	public static boolean isPalindrome2(ListNode head){
		
		if(head == null && head.next == null){
			return false;
		}
		
		boolean res = true;
		
		ListNode n1 = head;
		ListNode n2 = head;
		//找到链表的中点。
		while(n2.next != null && n2.next.next != null){
			n1 = n1.next;
			n2 = n2.next.next;
		}
		
		n2 = n1.next;
		n1.next = null;
		ListNode n3 = null;
		//将中间节点右侧的链表反转并指向中间节点。
		while(n2 != null){
			n3 = n2.next;
			n2.next = n1;
			n1 = n2 ;
			n2 = n3 ;
		}
		
		n3 = n1;//保留右侧的头结点。
		n2 = head;
		//判断左右两侧对称位置是否相等。
		while(n1 != null && n2 != null){
			if(n1.value != n2.value){
				res = false;
			}
			n1 = n1.next;
			n2 = n2.next;
		}
		
		//将右侧的链表还原。
		
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
