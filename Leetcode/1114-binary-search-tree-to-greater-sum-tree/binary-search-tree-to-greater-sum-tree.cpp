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
    vector<int>inord;
    void inorderTrav(TreeNode* root){
        if(root){
            inorderTrav(root->left);
            inord.push_back(root->val);
            inorderTrav(root->right);
        }
    }
    void updateTree(TreeNode* root,map<int,int>mp){
        if(root){
            updateTree(root->left,mp);
            root->val=mp[root->val];
            updateTree(root->right,mp);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorderTrav(root);
        vector<int>prefixSum(inord.size());
        prefixSum[0]=inord[0];
        for(int i=1;i<inord.size();i++){
            prefixSum[i]=prefixSum[i-1]+inord[i];
        }
        map<int,int>mp;
        int totalSum=prefixSum.back();
        for(int i=0;i<inord.size();i++){
            mp[inord[i]]=totalSum+inord[i]-prefixSum[i];
        }
        updateTree(root,mp);
        return root;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();