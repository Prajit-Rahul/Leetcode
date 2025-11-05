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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next, *next = NULL, *prev = NULL;
        slow->next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *fnext = NULL, *snext = NULL, *temp = prev;
        slow = head;
        while(slow && temp){
            fnext = slow->next;
            snext = temp->next;
            slow->next = temp;
            temp->next = fnext;
            slow = fnext;
            temp = snext;
        }
    }
};