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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        //if head==nullptr or list has only 1 element then it has to be returned as it is.
        if (!head || !head->next) {
            return head;
        }
        //take two nodes
        ListNode* cur = head->next;
        ListNode* prev = head;
        //creation
        while (cur) {
            //finding gcd and creating gcd node 
            int gcdVal = gcd(prev->val, cur->val);
            ListNode* temp = new ListNode(gcdVal);
            //Inserting gcd node in-between the nodes
            prev->next = temp;
            temp->next = cur;
            //traversing further
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
