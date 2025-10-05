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
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL || head->next == NULL) return head;
    //     ListNode *newHead = reverseList(head->next);
    //     ListNode *nextHead = head->next;
    //     nextHead->next = head;
    //     head->next = NULL;
    //     return newHead;
    // }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *nextNode = head, *prev = NULL;
        while(nextNode){
            ListNode *temp = nextNode->next;
            nextNode->next = prev;
            prev = nextNode;
            nextNode = temp;
        }
        return prev;
    }
};