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
TreeNode* splitTree(vector<int>&preorder,unordered_map<int,int>&mp,int &rootInd,int leftInd,int rightInd){
    if(leftInd>rightInd || rootInd>=preorder.size()) return nullptr;
    int rootVal = preorder[rootInd];
    TreeNode *node=new TreeNode(rootVal);
    int mid=mp[rootVal];
    rootInd++;
    node->left=splitTree(preorder,mp,rootInd,leftInd,mid-1);
    node->right=splitTree(preorder,mp,rootInd,mid+1,rightInd);
    return node;
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int rootInd=0;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
       return splitTree(preorder,mp,rootInd,0,inorder.size()-1);

    }
};