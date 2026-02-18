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
    ListNode *add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode *temp = l1, *prev = NULL;
        while(l1){
            int val = l1->val + carry;
            if(l2){
                val += l2->val;
                l2 = l2->next;
            }
            carry = val/10;
            val %= 10;
            prev = l1;
            l1->val = val;
            l1 = l1->next;
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        while(temp2){
            if(!temp1) return add(l2, l1);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return add(l1, l2);
    }
};