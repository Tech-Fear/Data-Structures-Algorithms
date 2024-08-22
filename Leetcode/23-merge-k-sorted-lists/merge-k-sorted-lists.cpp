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
        auto comp=[](ListNode *a,ListNode *b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)>minHeap;
        for(auto list:lists){
            if(list)
            minHeap.push(list);
        }
        ListNode *head=new ListNode(-1);
        ListNode *curr=head;
        while(!minHeap.empty()){
            ListNode *tmp=minHeap.top();
            minHeap.pop();
            curr->next=tmp;
            curr=curr->next;
            if(tmp->next!=NULL){
                minHeap.push(tmp->next);
            }
        }
        return head->next;
    }
};