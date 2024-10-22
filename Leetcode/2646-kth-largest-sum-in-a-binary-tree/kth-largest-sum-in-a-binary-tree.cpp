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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>sumArr;
        queue<TreeNode*>que;
        if(!root) return 0;
        que.push(root);
        while(!que.empty()){
            int levelSize=que.size();
            long long levelSum=0;
            for(int i=0;i<levelSize;i++){
                TreeNode *temp=que.front();
                que.pop();
                levelSum+=temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            sumArr.push(levelSum);
        }
        if(sumArr.size()<k) return -1;
        long long kLarg=-1;
        int j=0;
        while(j<k){
            j++;
            kLarg=sumArr.top();
            sumArr.pop();
        }
        return kLarg;
    }
};