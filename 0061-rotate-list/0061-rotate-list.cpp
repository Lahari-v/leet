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
        if(!head || !head->next)
            return head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        k = k % cnt; 
        if(k==0) 
            return head;
        int moves = cnt - k - 1; 
        temp = head;
        while(moves--) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr; 
        temp = newHead;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        return newHead;
    }
};