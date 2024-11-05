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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int levelSize=que.size();
            vector<int>cur;
            for(int i=0;i<levelSize;i++){
                TreeNode* temp=que.front();
                que.pop();
                cur.push_back(temp->val);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            ans.push_back(cur);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};