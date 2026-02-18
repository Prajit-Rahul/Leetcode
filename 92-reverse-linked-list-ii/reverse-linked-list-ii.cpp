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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || (left == right)) return head;
        int count = 1;
        ListNode *dummy = new ListNode(0, head);
        ListNode *temp = head, *leftPrev = dummy;
        while(temp->next && count < left){
            leftPrev = temp;
            temp = temp->next;
            count++;
        }
        ListNode *prev = NULL, *nextNode = NULL;
        while(temp && right >= count){
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            count++;
        }
        leftPrev->next->next = nextNode;
        leftPrev->next = prev;
        return dummy->next;
    }
};