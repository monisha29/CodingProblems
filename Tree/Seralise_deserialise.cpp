/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // Do preorder and store the tree
public :
    void genPre(TreeNode* node, string& op) {
        if(node) {
            op = op + to_string(node->val) + ",";
            genPre(node->left,op);
            genPre(node->right, op);
        }
    }
    
/*
getNode, string


*/
public :
  // conversion from string to vector of ips
    void getVals(string str, vector<int>& op) {
     
    // stringstream class check1
    stringstream check1(str);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ','))
    {
        op.push_back(stoi(intermediate));
    }
    }
    
public : 
    TreeNode* buildTree(vector<int> ip) {
        if (ip.size() > 0) {
            TreeNode* node = new TreeNode();
            node->left = NULL;
            node->right = NULL;
            node->val = ip[0];
            int i = 1;
             vector<int> left;
            vector<int> right;
            for(; i < ip.size() ; i++) {
              // add larger elements right vector & smaller in left vector
                if (ip[i] > ip[0])
                    right.push_back(ip[i]);
                else
                    left.push_back(ip[i]);
            }
            //cout << "str :: " << s << endl;
            if (left.size() > 0 )
                node->left = buildTree(left);
            if (right.size() > 0 )
                node->right = buildTree(right);
            return node;
        } else 
            return NULL;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string op;
        genPre(root, op);
        return op;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // data to vector 0f integers
        data = data.substr(0, data.length() - 1);
        cout << data << endl;
        vector<int> op;
        getVals(data,op);
        return buildTree(op);   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

/*
2 ,1 , 3 
     10
    5   15
   2 8 12  16
   
   preorder - > 10 (5 2 8) (15 12 16 )
                    5 (2)(8)  15 (12) (16)

*/
