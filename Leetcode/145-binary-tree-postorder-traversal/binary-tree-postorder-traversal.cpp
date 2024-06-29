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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>post;
        stack<TreeNode*>st;
        TreeNode *cur=root;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur=cur->left;
            }else{
                TreeNode *temp=st.top()->right;
                if(temp==NULL){
                temp=st.top();
                st.pop();
                post.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    post.push_back(temp->val);
                }
            }else{
                cur=temp;
            }
            }
        }
        return post;
    }
};