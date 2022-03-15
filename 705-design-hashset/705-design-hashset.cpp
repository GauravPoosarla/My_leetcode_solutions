class MyHashSet {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) 
        {
            this->val = x;
            this->next = NULL;
        }
    };
    
    ListNode* head;
    
    MyHashSet() {
        head = new ListNode(-1);
    }
    
    void add(int key) {
        ListNode* curr = head;
        if(contains(key)) return;
        
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        
        curr->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* curr = head;
        ListNode* prev = head;
        
        while(curr != NULL and curr->val != key)
        {
            prev = curr;
            curr = curr->next;
        }
        
        if(curr != NULL)
            prev->next = curr->next;   
    }
    
    bool contains(int key) {
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            if(curr->val == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */