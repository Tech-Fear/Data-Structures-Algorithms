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
        
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head->next;
        ListNode* prev = head;
        while (cur) {
            int gcdVal = gcd(prev->val, cur->val);
            ListNode* temp = new ListNode(gcdVal);
            prev->next = temp;
            temp->next = cur;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
