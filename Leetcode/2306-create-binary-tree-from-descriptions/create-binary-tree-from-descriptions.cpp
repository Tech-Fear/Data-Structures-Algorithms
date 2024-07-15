/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        set<int> child;
        for (auto& v : descriptions) {
            int parent = v[0];
            int ch = v[1];
            int pos = v[2];
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }
            if (mp.find(ch) == mp.end())
                mp[ch] = new TreeNode(ch);
            if (pos == 1) {
                mp[parent]->left = mp[ch];
            } else {
                mp[parent]->right = mp[ch];
            }
            child.insert(ch);
        }
        // finding the root
        for (auto& v : descriptions) {
            if (child.find(v[0]) == child.end()) {
                return mp[v[0]];
            }
        }
        return NULL;
    }
};
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'E';
}();