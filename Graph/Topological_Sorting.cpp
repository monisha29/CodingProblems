class Solution
{
    
    public : 
        void top(vector<int> adj[], int x, vector<int>& op, vector<int>& visited) {
            visited[x] = 1;
        
            // for(int j = 0 ; j < adj[x].size() ; j++) {
            //     cout << "here :: " << adj[x][j] << endl;
            //     if (visited[adj[x][j]] == 0) {
            //         top(adj, adj[x][j], op, visited);
            //     }
            // }
             for(auto y : adj[x]) {
                //cout << "here :: " << y << endl;
                if (visited[y] == 0) {
                    top(adj, y, op, visited);
                }
            }
          // Add the element only after visiting all its neighbours
            op.push_back(x);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V,0);
	    vector<int> op;
	    
	    
	    for(int i = 0 ; i < V ; i++) {
	        if (visited[i] == 0)
	      top(adj, i, op, visited);
	    }
	    
	   // for(int i = 0 ; i < op.size() ; i++) {
	   //     cout << op[i] << endl; 
	   // }
	    
	      reverse(op.begin(), op.end());
	    return op;
	}
};
