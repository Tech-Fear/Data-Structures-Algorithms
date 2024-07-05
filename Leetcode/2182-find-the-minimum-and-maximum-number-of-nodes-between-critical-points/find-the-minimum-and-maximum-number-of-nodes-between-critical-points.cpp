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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1);
        if(!head || !head->next || !head->next->next) return ans;
        int firstCritical =-1;
        int lastCritical=-1;
        int index=1;
        int minDistance=INT_MAX;
        ListNode *cur=head->next;
        ListNode *prev=head;
        ListNode *next=cur->next;
        while(next){
            if((cur->val<next->val && cur->val<prev->val) || (cur->val>next->val && cur->val>prev->val)){
                if(firstCritical==-1) firstCritical=index;
                else{
                    minDistance=min(minDistance,index-lastCritical);
                }
                lastCritical=index;
            }
            index++;
            prev=cur;
            cur=next;
            next=next->next;
        }
        if(firstCritical!=-1 && lastCritical!=-1 && firstCritical!=lastCritical){
            ans={minDistance,lastCritical-firstCritical};
        }
        return ans;
    }
};