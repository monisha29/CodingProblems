// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/785/

 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
         // get lengths of both LL
        int l1_s = 0;
        set<ListNode*> set1 ;
        while(tmp1 != NULL) {
            //set1.insert(tmp1);
            tmp1 = tmp1->next;
            l1_s++;
        }
        
        int l2_s = 0;
        while(tmp2 != NULL) {
//             if (set1.find(tmp2) != set1.end()) {
//                 return tmp2;
//             }           
            tmp2 = tmp2->next;
            l2_s++;
        }
        tmp1 = headA;
        tmp2 = headB;
        // find difference in sizes
        int diff = abs(l1_s - l2_s);   
      
        // Increment the start pointer of the longer list to make diff between then as zero
        // so that both lists become equal in length
        if (l1_s > l2_s) {
            while(diff != 0 && tmp1 != NULL) {
                tmp1 = tmp1->next;
                diff--;
            }            
        } else {
            while(diff != 0 && tmp2 != NULL) {
                tmp2 = tmp2->next;
                diff--;
            }
        }
        
        // Compare one on one basis
        while(tmp1 != NULL && tmp2 != NULL) {
            if (tmp1 == tmp2)
                return tmp1;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        
        return NULL;
    }
};
