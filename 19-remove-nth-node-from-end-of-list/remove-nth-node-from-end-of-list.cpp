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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int total = 0;
        while(temp){
            total++;
            temp = temp->next;
        }
        int count = total - n - 1;
        if(count < 0) return head->next;
        temp = head;
        while(count--){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};