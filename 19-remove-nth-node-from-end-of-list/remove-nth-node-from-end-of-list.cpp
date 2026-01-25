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
            temp = temp->next;
            total++;
        }
        if(n == total) return head->next;
        temp = head;
        for(int i=0; i < total - n - 1; i++){
            temp =  temp->next;
        }
        ListNode *del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};