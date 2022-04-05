
//partially 
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    queue<pair<int,int>> q;
	    
	    pair<int,int> src;
	    src.first = KnightPos[0]-1;
	    src.second = KnightPos[1]-1;
	    
	    vector<vector<int>> visited;
	    
	    for(int i = 0 ; i < N ; i++) {
	        vector<int> vec(N,0);
	        visited.push_back(vec);
	    }
	    q.push(src);
	    bool found = false;
	    int lvl = 0;
	    while(!q.empty()) {
	       
	        
	        int size = q.size() ;
	        lvl++;
	        while(size > 0) {
	             pair<int,int> ele = q.front();
	             q.pop();
	             visited[ele.first][ele.second] = 1;
	            // cout << "At :: " << ele.first << " , " << ele.second << endl;
	             if (ele.first == TargetPos[0]-1 && ele.second == TargetPos[1]-1) {
	                 lvl--;
	                 found = true;
	                 break;
	             }
	             
	             for (int i = 0 ; i < 8 ; i++) {
	                 int x = ele.first + dx[i];
	                 int y = ele.second + dy[i];
	                //  cout << "To :: " << x << " , " << y << endl;
	                 if ( x >= 0 && y >= 0 && x < N && y < N && visited[x][y] == 0) {
	                   //  cout << "Push :: " << x << " , " << y << endl;
	                      pair<int,int> newele;
	                      newele.first = x;
	                      newele.second = y;
	                      q.push(newele);
	                 }
	             }
	            size--;
	        }
	        
	        if(found)
	            break;
	    }
	    
	    return lvl;
	    
	}
