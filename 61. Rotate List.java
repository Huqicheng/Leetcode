/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        //check null node
        if (head == null) {
            return null;
        }
        int length = 1; // length of the linked list
        ListNode tail = head;
        while (tail.next != null) {
            length++;
            tail = tail.next;
        }
        k = k % length;
        tail.next = head; //make linked list a circle
        for (int i = 0; i < length - k - 1; i++) {
            head = head.next;
        }
        ListNode res = head.next;//result node
        head.next = null; //cut the circle before its new head node
        return res;
    }    
}