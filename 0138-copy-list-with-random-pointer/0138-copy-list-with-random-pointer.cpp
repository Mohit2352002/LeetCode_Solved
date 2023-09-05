static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* temp=head;
        while(temp){
            Node* fast= new Node(temp->val);
            fast->next=temp->next;
            temp->next=fast;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            if(temp->random) temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* ans=new Node(0);
        ans->next=head->next;
        while(temp){
            if(temp->next->next){
                Node* temp2=temp->next->next;
                temp->next->next=temp2->next;
                temp->next=temp2;
                temp=temp->next;
            }else break;
        }
        temp->next=NULL;
        return ans->next;
    }
};





/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;

        //inserting clones in between (Step 1)
        while(temp){
            Node* fast= new Node(temp->val);
            fast->next=temp->next;
            temp->next=fast;
            temp=temp->next->next;
        }

        temp=head;
        //placing random of clones to their right places (Step 2)
        while(temp){
            if(temp->random) temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        

        //restoring old list and placing the cloned in new list(Step 3)
        Node* ans=new Node(0); 
        Node* helper=ans;
        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;

            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next;

    }
};










/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // STEP 1: PASS 1
        // Creating a copy (except random pointer) of each old node and insert it next to the old node it's copied from.
        // That is, it will create new alternative nodes which are a copy (except random pointer) of its previous node.
        Node* node=head;
        while(node){
            Node* temp=node->next;
            node->next=new Node(node->val);
            node->next->next=temp;
            node=temp;
        }
        
        // STEP 2: PASS 2
        // Now copy the random pointer (if exists) of the old nodes to their copy new nodes.
        node=head;
        while(node){
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next; // go to next old node
        }
        
        //STEP 3: PASS 3
        // Copy the alternative nodes into "ans" link list using the "helper" pointer along with restoring the old link list.
        Node* ans=new Node(0); // first node is a dummy node
        Node* helper=ans;
    
        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;
            
            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next; // Since first node is a dummy node
    }
};*/