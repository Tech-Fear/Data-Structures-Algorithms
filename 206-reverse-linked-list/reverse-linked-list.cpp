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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead=NULL;
        ListNode *cur=head;
        while(cur){
            ListNode *temp=cur->next;
            cur->next=newHead;
            newHead=cur;
            cur=temp;
        }
        return newHead;
    }
};
auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '@';
}();