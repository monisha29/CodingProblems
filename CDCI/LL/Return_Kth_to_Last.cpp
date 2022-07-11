// Approach : 1
// recursively return the kth to last
ListNode* func(ListNode* node, int k , int& curr) {
        if (node == NULL)
            return NULL;
        //cout<< node->val << endl;
        ListNode* temp = func(node->next, k , curr);
        
        curr++;
       // cout << node->val << " at " << curr << endl;
        if (temp != NULL) {
            //cout << "Node" << temp->val << endl;
        }
        if (curr == k) {
            return node;
        }
        return temp;
    }


// Approach 2
// keep 2 pointers k distance apart i.e p1 and p2
// when p2 hits the end p1 must be pointing k steps back from p2 
  ListNode* p1 = head;
        ListNode* p2 = head;
        
        ListNode* prev = NULL;
        
        while(n > 0 && p2 != NULL) {
            prev = p2;
            p2 = p2->next;
            n--;
        }
        
        while(p2 != NULL) {
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (prev != NULL && p1 != NULL && prev != p1) {
            prev->next = p1->next;
        } else {
            if( head == NULL)
                return head;
            else 
                return head->next;
        }
        
        
        return head;
