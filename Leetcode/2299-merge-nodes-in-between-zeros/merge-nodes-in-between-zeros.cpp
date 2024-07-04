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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *cur=head,*prev=nullptr,*start=head->next;
        int sum=0;
        while(start){
            if(start->val!=0){
                sum+=start->val;
            }else{
                cur->val=sum;
                sum=0;
                prev=cur;
                cur=cur->next;
            }
            start=start->next;
        }
        prev->next=nullptr;
        return head;
    }
};