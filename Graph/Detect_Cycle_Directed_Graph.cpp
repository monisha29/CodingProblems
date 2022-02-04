class Solution {

 public:
 void is_cyclic(int x, vector<int> adj[], vector<int>& visited, vector<int>& in_stk, bool& flag) {
     visited[x] = 1;
   //to track stack status , in a non-cyclic graph ans element cannot be present twice
     in_stk[x] = 1;
     
     
     for( auto y : adj[x]) {
         if (in_stk[y] == 1) {
             flag = true;
             break;
         }
         if (visited[y] == 0) {
             is_cyclic(y , adj, visited, in_stk, flag);
         }
     }
     
     in_stk[x] = 0;
 }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> visited(V, 0);
        vector<int> in_stk(V,0);
        bool flag = false;
        for(int i = 0 ; i < V ; i++) {
            if(visited[i] == 0) {
                is_cyclic(i , adj, visited, in_stk, flag);
                if (flag)
                return true;
            }
        }
        
        return false;
    }
};
