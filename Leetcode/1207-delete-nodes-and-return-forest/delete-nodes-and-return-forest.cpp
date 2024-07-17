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
    TreeNode* deleteHelper(TreeNode *root,set<int>&st,vector<TreeNode*>&result){
        if(!root) return NULL;
        root->left=deleteHelper(root->left,st,result);
        root->right=deleteHelper(root->right,st,result);
        if(st.find(root->val)!=st.end()){
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            return NULL;
        }else
            return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;
        set<int>st;
        for(int &num:to_delete) st.insert(num);
        deleteHelper(root,st,result);
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};