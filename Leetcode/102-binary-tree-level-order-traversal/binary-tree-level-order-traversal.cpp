class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;

        if (!root) return ans;

        que.push(root);
        
        while (!que.empty()) {
            int levelSize = que.size();
            vector<int> curLev;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* temp = que.front();
                que.pop();
                curLev.push_back(temp->val);
                
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            
            ans.push_back(curLev);
        }

        return ans;
    }
};