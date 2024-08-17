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
    TreeNode *splitTree(vector<int>&preorder,unordered_map<int,int>&mp,int &rootInd,int leftInd,int rightInd){
         if (leftInd > rightInd) return nullptr;
        TreeNode *root=new TreeNode(preorder[rootInd]);
        int mid=mp[preorder[rootInd]];
        rootInd++;
        root->left=splitTree(preorder,mp,rootInd,leftInd,mid-1);
        root->right=splitTree(preorder,mp,rootInd,mid+1,rightInd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int rootInd=0;
        return splitTree(preorder,mp,rootInd,0,inorder.size()-1);
    }
};