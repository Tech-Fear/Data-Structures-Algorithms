/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int>ans;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node *tmp=st.top();
            st.pop();
            ans.push_back(tmp->val);
            for(auto &x:tmp->children){
                st.push(x);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};