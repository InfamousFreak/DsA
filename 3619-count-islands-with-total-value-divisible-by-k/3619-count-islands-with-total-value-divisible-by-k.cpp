class Solution {
public:
    int m, n;
    vector<vector<int>>* gridptr;
    vector<vector<int>> vis;
    long long dfs(int r, int c) { //only row and columns as parameter as we are traversing the cells via coordinates
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 0;
        }

        auto& grid = *gridptr;  //assign a pointer to the grid cells
        if (grid[r][c] == 0 || vis[r][c]) {  // check whether the cell is water or already visited
            return 0;
        } 

        vis[r][c] = 1; // mart current cell as vsiited

        long long sum = grid[r][c];

        sum += dfs(r + 1, c); //bottom row
        sum += dfs(r - 1, c); //upper row
        sum += dfs(r, c - 1); //left column
        sum += dfs(r, c + 1); //right column

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        gridptr = &grid;

        vis.assign(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = dfs(i, j);


                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;


    }
};