// My approach 

class Solution {
    
public : 
    void simple_tokenizer(string s, vector<string>& op) {
    stringstream ss(s);
    string word;
    while (ss >> word) {
       op.push_back(word);
    }
}
public:
    string simplifyPath(string path) {

     
    // stringstream class check1
    stringstream check1(path);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
        stack<string> words;
        stack<string> op;
    while(getline(check1, intermediate, '/'))
    {
        if (intermediate.length() > 0 ) {
    //    cout << " test :: " << intermediate << endl;   
        words.push(intermediate);
        }
        //cout << intermediate << endl;
    }
     //   getline(check1, intermediate, '/');
   //   words.push(intermediate);
       // simple_tokenizer(path,op);
        int popvar = 0;
        while(!words.empty()) {
              string curr = words.top();
             if (!words.empty() && popvar > 0) {
                   if (curr != ".." && curr != ".") {
                        words.pop();
                        popvar--;
                        continue;
                   } 
            }
            words.pop();
        //    cout << "curr is :: " << curr << endl ;
            if (curr == "..") {
                popvar++;
                //words.pop();
            } else if (curr == ".") { 
                 //words.pop();
                continue;
            }    else if (popvar == 0 && curr.length() > 0) {
                op.push("/" + curr);
                 //words.pop();
            }
          
           
            
        }
     string ans;   
        while(!op.empty()) {
            ans = ans + op.top() ;
            op.pop();
        }
        
    if (ans.length() == 0)
        ans = "/";
        return ans;
    }
};

/*

// siimpler code

class Solution {
public:
    string simplifyPath(string path) {

     
    // stringstream class check1
    stringstream check1(path);
     
    string t;
     
    // Tokenizing w.r.t. space ' '
        vector<string> words;
        string op;
    while(getline(check1, t, '/'))
    {
        if (t == "" || t == ".") continue;
        if ( t == ".." && words.size() > 0 ) words.pop_back();
        if ( t != "..") words.push_back(t);
    }
        
        for (auto str : words) 
            op = op + "/" + str;
        
        if (op.empty())
            return "/";
        else
            return op;
    }
};



*/
