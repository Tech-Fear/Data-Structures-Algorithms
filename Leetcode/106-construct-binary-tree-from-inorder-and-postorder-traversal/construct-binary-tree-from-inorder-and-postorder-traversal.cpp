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
    TreeNode* splitTree(vector<int>&postorder,unordered_map<int,int>&mp,int &rootInd,int leftInd,int rightInd){
        if(leftInd>rightInd) return nullptr;
        int val=postorder[rootInd];
        TreeNode* root=new TreeNode(val);
        int mid=mp[val];
        rootInd--;
        root->right=splitTree(postorder,mp,rootInd,mid+1,rightInd);
        root->left=splitTree(postorder,mp,rootInd,leftInd,mid-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int rootIndex=postorder.size()-1;
        return splitTree(postorder,mp,rootIndex,0,inorder.size()-1);
    }
};