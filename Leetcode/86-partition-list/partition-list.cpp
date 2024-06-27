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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* greaterDummy=new ListNode(101);
        ListNode* lessDummy=new ListNode(101);
        ListNode *less=lessDummy;
        ListNode *greater=greaterDummy;
        ListNode *cur=head;
        while(cur){
            if(cur->val<x){
                less->next=cur;
                less=less->next;
            }else{
                greater->next=cur;
                greater=greater->next;
            }
            cur=cur->next;
        }
        less->next=greaterDummy->next;
        greater->next=nullptr;

        ListNode *newHead=lessDummy->next;
        delete lessDummy;
        delete greaterDummy;
        return newHead;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();