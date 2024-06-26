/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insert(Node *head){
        while(head){
            Node *temp=new Node(head->val);
            temp->next=head->next;
            head->next=temp;
            head=head->next->next;
        }
    }
    void createRandom(Node *head){
        while(head){
            if(head->random){
                head->next->random=head->random->next;
            }
            head=head->next->next;
        }
    }
    Node *clone(Node *head){
        Node *ans=new Node(0);
        Node *cur=ans;
        while(head){
            cur->next=head->next;
            cur=cur->next;
            head->next=head->next->next;
            head=head->next;
        }
        return ans->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        insert(head);
        createRandom(head);
        return clone(head);
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'W';
}();