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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,nullptr);
        if(!head) return ans;
        ListNode* cur=head;
        int length=0;
        while(cur){
            length++;
            cur=cur->next;
        }
        int si=length/k;
        int rem=length%k;
        vector<int>temp(k,si);
        for(int i=0;i<rem;i++){
            temp[i]++;
        }
        cur=head;
        int i=0;
        while(i<k && cur){
            int l=temp[i];
            ans[i]=cur;
            ListNode* prev=NULL;
            while(l-- && cur){
                prev=cur;
                cur=cur->next;
            }
            if (prev) {
                prev->next = nullptr;
            }
            i++;
        }
        return ans;
    }
};