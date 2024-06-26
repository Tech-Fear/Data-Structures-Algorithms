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
    void inordTrav(TreeNode *root,vector<int>&inord){
        if(root){
            inordTrav(root->left,inord);
            inord.push_back(root->val);
            inordTrav(root->right,inord);
        }
    }
    TreeNode* solve(int l,int r,vector<int>&inord){
        if(l>r) return nullptr;
        int mid=l+(r-l)/2;
        TreeNode *root=new TreeNode(inord[mid]);
        root->left=solve(l,mid-1,inord);
        root->right=solve(mid+1,r,inord);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inord;
        inordTrav(root,inord);
        return solve(0,inord.size()-1,inord);
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();