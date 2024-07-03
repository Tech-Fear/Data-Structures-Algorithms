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
    void flatten(TreeNode* root) {
       if(!root) return;
       TreeNode *cur=root;
       while(cur){
        if(cur->left){
            TreeNode *pr=cur->left;
            while(pr->right){
                pr=pr->right;
            }
            pr->right=cur->right;
            cur->right=cur->left;
            cur->left=nullptr;
        }
        cur=cur->right;
       }
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();