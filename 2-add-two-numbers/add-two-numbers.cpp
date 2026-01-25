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
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode *list1 = l1, *list2 = l2, *prev = NULL;
        int carry = 0;
        while(list1){
            int sum = carry + list1->val;
            if(list2){
                sum += list2->val;
                list2 = list2->next;
            }
            carry = sum/10;
            sum %= 10;
            list1->val = sum;
            prev = list1;
            list1 = list1->next;
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1 = l1, *list2 = l2;
        while(list1){
            if(!list2) return add(l1, l2);
            list1 = list1->next;
            list2 = list2->next;
        }
        return add(l2, l1);
    }
};