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
    TreeNode* LCA(TreeNode *root,int p,int q){
        if(!root) return NULL;
        if(root->val==p || root->val==q) return root;
        TreeNode *leftN=LCA(root->left,p,q);
        TreeNode *rightN=LCA(root->right,p,q);
        if(leftN && rightN) return root;
        return leftN?leftN:rightN;
    }
    bool findPath(TreeNode *lca,int src,string &st){
        if(!lca) return false;
        if(lca->val==src) return true;
        st.push_back('L');
        if(findPath(lca->left,src,st)){
            return true;
        }
        st.pop_back();
        st.push_back('R');
        if(findPath(lca->right,src,st)){
            return true;
        }
        st.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca=LCA(root,startValue,destValue);
        string lcaSRC="";
        string lcadest="";
        findPath(lca,startValue,lcaSRC);
        findPath(lca,destValue,lcadest);
        string result;
        for(int i=0;i<lcaSRC.length();i++){
            result.push_back('U');
        }
        result+=lcadest;
        return result;
    }
};