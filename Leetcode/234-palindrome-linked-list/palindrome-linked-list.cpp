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
    ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}
    bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;  // Empty list or single node is a palindrome
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* slow_prev = nullptr;
    ListNode* mid = nullptr;
    
    // Use fast and slow pointers to find the middle of the list
    while (fast && fast->next) {
        fast = fast->next->next;
        slow_prev = slow;
        slow = slow->next;
    }
    
    // Determine if the list has odd number of nodes
    if (fast) {  // Odd number of nodes, slow is at the exact middle
        mid = slow;
        slow = slow->next;
    }
    
    // Split the list into two halves
    slow_prev->next = nullptr;
    
    // Reverse the second half of the list
    ListNode* second_half = reverse(slow);
    
    // Compare the first half (head) with the reversed second half (second_half)
    ListNode* p1 = head;
    ListNode* p2 = second_half;
    bool is_palindrome = true;
    
    while (p1 && p2) {
        if (p1->val != p2->val) {
            is_palindrome = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // Restore the list to its original state (optional)
    slow_prev->next = reverse(second_half);
    
    return is_palindrome;
}
};
