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
    void invertedTree(TreeNode* root){
        if(!root) return;
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
            invertedTree(root->left);
            invertedTree(root->right);
        }
public:
    TreeNode* invertTree(TreeNode* root) {
        invertedTree(root);
        return root;
    }
};