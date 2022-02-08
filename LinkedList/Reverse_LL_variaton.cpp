/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public :
    ListNode* reverse(ListNode* head) {
        
        ListNode* nl = NULL;
        if (!head)
            return NULL;
        ListNode* p = head;
        ListNode* q = p->next;
        
        while(p != NULL) {
            cout << "Reverse " << p->val << endl;
            q = p->next;
            p->next = nl;
            nl = p;
            p = q;
        }
        return nl;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* slo  = NULL;
        ListNode* elo = NULL;
        ListNode* rev = NULL;
        ListNode* temp = head;
        int counter = 0;
        if (head != NULL)
            counter = 1;
        while(temp->next != NULL) {
            cout << "temp :: " << temp->val << endl ;
            if (counter + 1 == left) {
                cout << "Inside slo " << endl;
                slo = temp;
                rev = temp->next;
                cout << slo->val << " , " << rev->val << endl ; 
            }
            
            if (counter == right) {
                cout << " Inside elo " << endl;
                elo = temp->next;
                temp->next = NULL;
                cout << elo->val << endl;
                break;
            }
            temp = temp->next;
            counter++;
        }
        
        if (slo != NULL) {
            cout << "slo :: " << slo->val << endl ;
        }
        if (elo != NULL) {
            cout << "elo 2 :: " << elo->val << endl ;
        }
        if (left == 1) {
            rev = head;
        }
            
        ListNode* rev2 = reverse(rev);
        if (slo != NULL)
           slo->next = rev2;
        
        temp = rev2;
        
        while(temp && temp->next != NULL) {
            cout << "where are you :: " << temp->val << endl ;
            temp = temp->next;
        }
        if (temp != NULL) {
            
            temp->next = elo;
        }
        
        if (left == 1) {
            head = rev2;
        }
        
        return head;
        
        
    }
};
