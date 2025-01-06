/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        int n = 1;
        ListNode* curr = head;
        while(curr->next != NULL) {
            n++;
            curr = curr->next;
        }
        curr->next = head;
        k = k % n;
        int moves = n - k;
        curr = head;
        for(int i=1; i<moves; i++) {
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};