/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *node){
        int len=0;
        while(node){
            node=node->next;
            len++;
        }
        return len;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen=length(headA);
        int blen=length(headB);
        while(blen>alen){
            headB=headB->next;
            blen--;
        }
        while(alen>blen){
            headA=headA->next;
            alen--;
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();