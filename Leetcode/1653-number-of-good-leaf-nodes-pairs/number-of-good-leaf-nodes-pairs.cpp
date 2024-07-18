/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans = 0;

    vector<int> recursion(TreeNode *root, int d) {
        if (!root) return {};
        if (!root->left && !root->right) return {1};
        
        vector<int> l = recursion(root->left, d);
        vector<int> r = recursion(root->right, d);
        vector<int> arr;

        for (auto &a : l) {
            for (auto &b : r) {
                if (a + b <= d) ans++;
            }
        }
        for (auto &a : l) {
            if (a + 1 < d) arr.push_back(a + 1);
        }
        for (auto &b : r) {
            if (b + 1 < d) arr.push_back(b + 1);
        }
        return arr;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        recursion(root, distance);
        return ans;
    }
};