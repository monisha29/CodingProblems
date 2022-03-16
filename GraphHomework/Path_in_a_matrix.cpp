//https://www.interviewbit.com/problems/path-in-matrix/
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>>& visited, int x , int y, bool& found, vector<vector<int>>& A, int n) {
   // cout << "i , j " << x << " , " << y << endl;
     if (A[x][y] == 2) {
            found = true;
    } else {
        visited[x][y] = 1;

        for(int i = 0 ; i < 4 ; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a >=0 && b >= 0 && a < n && b < n  && visited[a][b] == 0 && (A[a][b] == 3 || A[a][b] == 2)) {
                dfs(visited, a,b ,found, A, n);
            }
        }
    }
}



int Solution::checkPath(vector<vector<int> > &A) {
    int n = A.size();
    bool found = false;
    vector<vector<int>> visited;

    for(int i = 0 ; i < n ; i++) {
        vector<int> vec(n,0);
        visited.push_back(vec);
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
         //   cout << "i , j " << i << " , " << j << endl;
            if (A[i][j] == 1) {
                dfs(visited, i, j, found, A, n);
            }
        }
    }

    return found;

}
