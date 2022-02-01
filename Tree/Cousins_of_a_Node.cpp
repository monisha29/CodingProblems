/**** My draft of code***********
*/
class Solution
{
    
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int> op;
        queue<Node*> q;
        q.push(root);
        vector<Node*> transfer;
        bool found = false;
        Node* sib = NULL;
        while(!q.empty()) {
            int curr_size = q.size() ;
            while(curr_size != 0) {
                Node* val = q.front();
                q.pop();
                //cout << "val :: " << val->data << " ::: " << found << endl;
                // if the node is found we need to go to next level as this is the level needed , so enabled a flag 
                if (val == node_to_find) {
                    found = true;
                }
                
                if (val->left != NULL) {
                    // when at the parent node of desired node try to find sib so that it can be skipped in final op
                    if (val->left == node_to_find) {
                        sib = val->right;
                    }
                    q.push(val->left);
                }
                if (val->right != NULL) {
                   // when at the parent node of desired node try to find sib so that it can be skipped in final op
                    if (val->right == node_to_find) {
                        sib = val->left;
                    }
                    q.push(val->right);
                }
               // Collect the current level in a transfer list
                transfer.push_back(val);
                curr_size--;
            }
            
            if (found) {
                break;
            } else {
                // if found is not true , then this is not the dersired level , so no use of data in transfer so clear it
                transfer.clear();
            }
        }
        
        for(int i = 0 ; i < transfer.size() ; i++) {
          // skip node and its sibling , since its is a tree there can only be one sibling
            if (transfer[i] != node_to_find && transfer[i] != sib)
                op.push_back(transfer[i]->data);
        }
        if (op.size() == 0) {
            op.push_back(-1);
        }
        return op;
    }
  
  /*
  A more optimised solution
  */
  
  class Solution
{
    
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int> op;
        queue<Node*> q;
        q.push(root);
        //vector<Node*> transfer;
        bool found = false;
        //Node* sib = NULL;
        while(!q.empty()) {
            //copy(q.begin(), q.end(), transfer);
            int curr_size = q.size() ;
            while(curr_size != 0) {
                Node* val = q.front();
                q.pop();
                //cout << "val :: " << val->data << " ::: " << found << endl;
                
                // From the parent itself check , if this node is the parent of the desired node , do not push it in the queue , in that case sibling and node will not compeup
                // enable the flag indicating the to the level which has the node , by pushing its eft and right
                if (val->left == node_to_find || val->right == node_to_find) {
                    found = true;
                } else {
                    if(val->left)
                        q.push(val->left);
                    if (val->right)
                        q.push(val->right);
                }
                curr_size--;
            }
            
            if (found) {
                break;
            } 
        }
        // No need for an extra vector as queue itself has the desried parent 
        while(!q.empty()) {
            Node* val = q.front();
                q.pop();
            op.push_back(val->data);
        }
        /*
        for(int i = 0 ; i < transfer.size() ; i++) {
            if (transfer[i] != node_to_find && transfer[i] != sib)
                op.push_back(transfer[i]->data);
        }*/
        if (op.size() == 0) {
            op.push_back(-1);
        }
        return op;
    }
  
  
    
