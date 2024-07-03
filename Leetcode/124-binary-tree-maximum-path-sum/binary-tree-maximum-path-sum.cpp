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
    int maxSum(TreeNode *root,int &sum){
        if(!root) return 0;
        int left=max(0,maxSum(root->left,sum));
        int right=max(0,maxSum(root->right,sum));
        int temp= root->val+left+right;
        sum=max(sum,temp);
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int sum=INT_MIN;
        maxSum(root,sum);
        return sum;
    }
};
auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();