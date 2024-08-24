/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*,Node*>mp;
        Node *newNode=new Node(node->val);
        mp[node]=newNode;
        queue<Node*>que;
        que.push(node);
        while(!que.empty()){
            Node* curr=que.front();
            que.pop();
            for(Node* n:curr->neighbors){
                if(mp.find(n)==mp.end()){
                    Node* tmp=new Node(n->val);
                    mp[n]=tmp;
                    que.push(n);
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }
        }
        return newNode;
    }
};