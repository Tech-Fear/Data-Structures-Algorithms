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
    vector<int>solve(TreeNode* root){
        if(root==NULL) return {0,0};
        vector<int>leftChoices=solve(root->left);
        vector<int>rightChoices=solve(root->right);
        vector<int>options(2,0);
        options[0]=root->val+leftChoices[1]+rightChoices[1];
        options[1]=max(leftChoices[1],leftChoices[0])+max(rightChoices[0],rightChoices[1]);
        return options;
    }
public:
    int rob(TreeNode* root) {
        vector<int>options=solve(root);
        return max(options[1],options[0]);
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'X';
}();