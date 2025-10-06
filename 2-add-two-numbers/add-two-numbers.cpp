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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2, *prev = NULL, *prev2 = NULL;
        int carry = 0;
        while(temp1 || temp2){
            if(!temp1){
                prev->next = prev2->next;
                prev2->next = NULL;
                temp1 = prev->next;
                temp2 = NULL;
            }
            int sum = carry;
            if(temp2){
                sum += temp2->val;
                prev2 = temp2;
                temp2 = temp2->next;
            }
            if(temp1){
                sum += temp1->val;
                temp1->val = sum%10;
                prev = temp1;
                temp1 = temp1->next;
            }
            carry = sum/10;
            cout<<carry<<" ";
        }
        if(carry){
            prev->next = new ListNode(carry);;
        } 
        return l1;
    }
};