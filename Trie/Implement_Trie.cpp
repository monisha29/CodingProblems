struct Node {
   Node *links[26];
   bool flag = false;
    
    bool containsKey(char c) {
        if (links[c - 'a'] == NULL)
            return false;
        else
            return true;
    }
    
    void insert(char c , Node* node) {
        links[c - 'a'] = node;
    }
    
    Node* getNode(char c) {
        return links[c - 'a'];
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.length() ; i++) {
            if (!node->containsKey(word.at(i))) {
                node->insert(word.at(i), new Node());
            }
            
            node = node->getNode(word.at(i));
        }
        
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.length() ; i++) {
            if (!node->containsKey(word.at(i))) {
                return false;
            }
            
            node = node->getNode(word.at(i));
        }
        
        return node->flag;
    }
    
    bool startsWith(string word) {
       Node* node = root;
        for(int i = 0 ; i < word.length() ; i++) {
            if (!node->containsKey(word.at(i))) {
                return false;
            }
            
            node = node->getNode(word.at(i));
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
