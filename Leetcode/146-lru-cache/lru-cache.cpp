class LRUCache {
private:
    struct Node{
        int key,val;
        Node *prev,*next;
        Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
    };
    unordered_map<int,Node*>mp;
    Node *head,*tail;
    int capacity;

    void pushHead(Node *node){
        remove(node);
        add(node);
    }
    void remove(Node* node){
        Node *prev=node->prev;
        Node *next=node->next;
        if(prev){
            prev->next=next;
        }
        if(next){
            next->prev=prev;
        }
    }
    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *node=mp[key];
        pushHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *temp=mp[key];
            temp->val=value;
            pushHead(temp);
        }else{
            if(mp.size()>=capacity){
                Node *y=tail->prev;
                mp.erase(y->key);
                remove(y);
                delete y;
            }
            Node *temp=new Node(key,value);
            mp[key]=temp;
            add(temp);
        }
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */