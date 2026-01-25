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
    ListNode *reverse(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = reverse(slow->next), *temp = head;
        slow->next = NULL;
        ListNode *newHead = new ListNode();
        ListNode *start = newHead;
        while(temp || second){
            if(temp){
                newHead->next = temp;
                temp = temp->next;
                newHead = newHead->next;
            }
            if(second){
                newHead->next = second;
                second = second->next;
                newHead = newHead->next;
            }
        }
    }
};