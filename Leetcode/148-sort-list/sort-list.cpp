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
private:
    ListNode* findMiddle(ListNode* head) {
        if (!head) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *mergeLists( ListNode *leftHead, ListNode *rightHead ){
        ListNode *dummy = new ListNode( -1 );
        ListNode *temp = dummy;
        while( leftHead && rightHead){
            if( leftHead->val < rightHead->val ){
                temp->next=leftHead;
                leftHead = leftHead->next;
            }else{
                temp->next=rightHead;
                rightHead=rightHead->next;
            }
            temp=temp->next;
        }
        if(leftHead){
            temp->next=leftHead;
        }
        if(rightHead) temp->next=rightHead;
        ListNode *newHead=dummy->next;
        delete dummy;
        return newHead;
    } 
public:
    ListNode* sortList( ListNode* head ) {
        if( !head || !head->next ) return head;
        ListNode *middle = findMiddle( head );
        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;
        middle->next = nullptr;
        
        leftHead = sortList( leftHead );
        rightHead = sortList( rightHead );
        return mergeLists( leftHead, rightHead );
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '@';
}();