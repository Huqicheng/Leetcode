/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        int cnt = 0;
        while(cnt < n + 1) {
            second = second->next;
            cnt ++;
        }
        while(second != NULL) {
            second = second->next;
            first = first->next;
        }
        // detach
        ListNode* tmp =  first->next;
        first->next = first->next->next;
        delete tmp;
        return dummy->next;
    }
};