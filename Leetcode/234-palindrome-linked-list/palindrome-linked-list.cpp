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
ListNode* findMiddle(ListNode* head){
    ListNode* fast=head;
    ListNode *slow=head;
    while(fast&& fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    if(!head|| !head->next) return head;
    ListNode* temp=reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return temp;
}
    bool isPalindrome(ListNode* A) {
       ListNode *mid=findMiddle(A);
    mid=reverse(mid);
    while(mid){
        if(mid->val!=A->val) return false;
        A=A->next;
        mid=mid->next;
    }
    return true; 
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();