/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* dfs(queue<string>&que){
        string temp=que.front();que.pop();
        if(temp=="#") return NULL;
        TreeNode* node=new TreeNode(stoi(temp));
        node->left=dfs(que);
        node->right=dfs(que);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string left=serialize(root->left);
        string right=serialize(root->right);
        return to_string(root->val)+","+(left)+","+(right);   
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>que;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            que.push(token);
        }
        return dfs(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));