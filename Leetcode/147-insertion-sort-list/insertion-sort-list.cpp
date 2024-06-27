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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *dummy=new ListNode(0);
        ListNode *cur=head;
        while(cur){
            ListNode* next=cur->next;
            ListNode *prev=dummy;
            while(prev->next && prev->next->val<cur->val){
                prev=prev->next;
            }
            cur->next=prev->next;
            prev->next=cur;
            cur=next;
        }
        ListNode* newHead=dummy->next;
        return newHead;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();