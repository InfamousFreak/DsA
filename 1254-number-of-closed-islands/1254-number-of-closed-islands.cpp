class Solution {
public:
    int m, n;
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }

        if (grid[r][c] == 1) {
            return true;
        }

        grid[r][c] = 1;  //mark every cell as 1 when visited

        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    if (dfs(grid, r, c)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

// the core observation we need to make sure here is, not every 0 is surrounded by 1 or not, but the 0s, which are adjacent to 1s, if all are adjacent or some are not and connected to the sideline, cause for a closed island u have to be surrounded by 1 by all sides, 

//aproach A is dfs each island and check whether its closed, like traverse every cell, whenever find unvisited land (0), start a dfs to explore its entire connected island, 
//during the dfs, check whether any cell touches the boundary, and if the island never touches a boundary, increment the count, can mark visited cells by chanign 0 to 1, grid allowed to be modified

