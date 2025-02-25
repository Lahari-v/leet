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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while(p1 != p2) {
            p1 = !p1 ? headB : p1->next;
            p2 = !p2 ? headA : p2->next;
        }
        return p1;
    }
};