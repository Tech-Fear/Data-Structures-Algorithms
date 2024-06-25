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
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        sumTree(root,sum);
        return root;
    }
    void sumTree(TreeNode *root,int &sum){
        if(root){
            sumTree(root->right,sum);
            root->val+=sum;
            sum=root->val;
            sumTree(root->left,sum);
        }
    }
};
auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();