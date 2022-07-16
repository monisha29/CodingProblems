
// Aim is to pick the 'O' points on the boundary - > irreplaceable one
// pick other 'O' points adjacent to irreplaceable ones and so onn
// BFS can be used


class Solution {
    int dx[4] = {-1, 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1, 1};
    

public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c , false));
        
        // top + 1 row 
        // bottom - 1 row
        // left + 1 colum
        // right - 1 column
        vector<pair<int,int>> op;
        queue<pair<int,int>> q;
        for(int i = 0 ;i < c ; i++) {
            if (board[0][i] == 'O') {
                pair<int,int> p = make_pair(0,i);
               // op.push_back(p);
                q.push(p);
                visited[0][i] = true;
            }
        }
        for(int i = 0 ;i < c ; i++) {
            if (board[r-1][i] == 'O') {
                pair<int,int> p = make_pair(r-1,i);
               // op.push_back(p);
                q.push(p);
                 visited[r-1][i] = true;
            }
        }
        
        for(int i = 0 ;i < r ; i++) {
            if (board[i][0] == 'O') {
                pair<int,int> p = make_pair(i,0);
                //op.push_back(p);
                q.push(p);
                 visited[i][0] = true;
            }
        }
        
        for(int i = 0 ; i < r ; i++) {
            if (board[i][c-1] == 'O') {
                pair<int,int> p = make_pair(i,c-1);
                //op.push_back(p);
                q.push(p);
                 visited[i][c-1] = true;
            }
        }
        
        //cout << q.size() << endl;
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            op.push_back(p);
            for(int k = 0 ; k < 4 ; k++) {
                int x = p.first + dx[k];
                int y = p.second + dy[k];
                if ( x >= 0 && y >= 0 && x < r && y < c) {
                    if (board[x][y] == 'O' && visited[x][y] == false) {
                        visited[x][y] = true;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        
        
        for(int i = 0 ; i < r ; i++) {
            for(int j = 0 ; j < c ; j++) {
                board[i][j] = 'X';
            }
        }
        
        for(auto x : op) {
            board[x.first][x.second] = 'O';
        }
    
    }
};
