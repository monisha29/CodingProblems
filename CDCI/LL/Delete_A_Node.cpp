// Keep Copying the nodes from next node to the curr node , start from the node that needs to be deleted
// IMP :: Will not work if the given node is the last node
class Solution
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        if (n == 1)
            return NULL;
        n = n/2;
        ListNode* prev = NULL;
        temp = head;
        
        while(n > 0 && temp != NULL) {
            prev = temp;
            temp = temp->next;
            n--;
        }
        
        if(prev != NULL) {
            prev->next = temp->next;
        }
        
        
        return head;
    }
}
