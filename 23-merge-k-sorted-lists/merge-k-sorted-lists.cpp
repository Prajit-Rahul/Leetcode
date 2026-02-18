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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<>> pq;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        for(auto &it: lists){
            if (it != NULL) 
                pq.push({it->val, it});
        }
        while(!pq.empty()){
            if(pq.top().second->next != NULL){
                ListNode *nxt = pq.top().second->next;
                pq.push({nxt->val, nxt});
            }
            temp->next = pq.top().second;
            temp = temp->next;
            pq.pop();
        }
        return dummy->next;
    }
    
};