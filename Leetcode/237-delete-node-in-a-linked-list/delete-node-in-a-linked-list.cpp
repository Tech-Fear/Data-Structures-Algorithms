/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#pragma GCC optimize("Ofast,unroll-loops")
class Solution {
public:
    void deleteNode(ListNode* node) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode *temp=node->next;
        node->val=node->next->val;
        node->next=temp->next;
        delete temp;
    }
};