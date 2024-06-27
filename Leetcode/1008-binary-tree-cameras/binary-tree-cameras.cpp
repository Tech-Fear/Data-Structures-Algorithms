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
    int dfs(TreeNode *root,int &sum){
        if(!root) return 1;
        int left=dfs(root->left,sum);
        int right=dfs(root->right,sum);
        if(left==0 || right==0){
            sum++;
            return 2;
        }
        if(left==1 && right==1) return 0;
        if(left==2 || right==2) return 1;
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(dfs(root,sum)==0) sum++;
        return sum;
    }

};
auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'W';
}();