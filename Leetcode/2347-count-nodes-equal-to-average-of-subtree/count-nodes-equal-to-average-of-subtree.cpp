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
    pair<int,int> dfs(TreeNode* root,int &count){
        if(!root) return {0,0};

        auto [l_sum,l_count]=dfs(root->left,count);
        auto [r_sum,r_count]=dfs(root->right,count);

        int currentSum=root->val+l_sum+r_sum;
        int currentCount=l_count+r_count+1;

        if(currentSum/currentCount==root->val){
            count++;
        }

        return {currentSum,currentCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        dfs(root,count);
        return count;
    }
};