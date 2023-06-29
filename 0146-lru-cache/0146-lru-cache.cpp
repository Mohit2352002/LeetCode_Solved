/*
class Node{
    public:
    int key,value;
    Node *right,*left;
    
    Node(int key,int value){
        this->key=key;
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};
class LRUCache {
public:
    Node *head,*tail;
    int capacity,size;
    unordered_map<int,Node *> m;
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
        
    }
    void delete_node(Node *p){
        if(p->left!=NULL){
            p->left->right=p->right;
        }
        else{
            head=p->right;
        }
        if(p->right!=NULL){
            p->right->left=p->left;
            
        }
        else{
            tail=p->left;
        }
        p->left=NULL;
        p->right=NULL;
    }
    
    void insert(Node *q){
       if (head == NULL)
        {
            head = tail = q;
        }
        else{
        tail->right = q;
        q->left = tail;
        tail = q;
        }

    }

    // Logic for get function:
    // -> if key not found return -1
    // ->if found then return val

    int get(int key) {
        if (m.find(key)==m.end())
            return -1;
        Node *x=m[key];
        delete_node(x);
        insert(x);
        //insert the node at last
        
        return x->value;
    }


    // Logic for Put function:
    // ->if key already present thenchange the value of the key insert it at last
    // ->if key not present
    //     Case1:if size== capacity then first value removed in LRU Cache
    //     Case2:if size!=capacity value inserted at last  
    
    void put(int key, int value) {
        Node *y=new Node(key,value);
        if(m.find(key)!=m.end()){
            m[key]->value=value;
            delete_node(m[key]);
            insert(m[key]);
        }else{
            m[key]=y;
            if(size==capacity){
                m.erase(head->key);//remove the least recently used value from map
                delete_node(head);
                insert(y);
            }else{
                size+=1;//size of window increase
                insert(y);
            }
        }
    }
};
 */
 









static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class node{
    public:
    int key, val;
    node *prev, *next;
    node(int _key, int _value){
        key=_key;
        val=_value;
        next=prev=NULL;
    }
};
class LRUCache {
    unordered_map<int,node*>mp;
    int cap;

    node* head;
    node* tail;

    void addnode(node *newnode){
        node*temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
    }

    void deletenode(node *delnode){
        node* delprev=delnode->prev;
        node* delnext= delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        delnode->next=NULL;
        delnode->prev=NULL;
    }

public:
    LRUCache(int capacity) {
        cap=capacity;
        tail=new node(-1,-1);
        head=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* nodeRes=mp[key];
            int res=nodeRes->val;
            deletenode(nodeRes);
            addnode(nodeRes);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* existingNode=mp[key];
            deletenode(existingNode);
            mp.erase(key);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */