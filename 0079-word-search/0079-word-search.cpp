class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (backtrack(board, word, row, col, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
        
    }

private:

    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int wordIndex, vector<vector<bool>>& visited) {

        if (wordIndex == word.length()) {
            return true;
        }

        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        if (visited[row][col]) {
            return false;
        }

        if (board[row][col] != word[wordIndex]) {
            return false;
        }


        visited[row][col] = true;

        bool found = 
            backtrack(board, word, row + 1, col, wordIndex + 1, visited) ||
            backtrack(board, word, row - 1, col, wordIndex + 1, visited) ||
            backtrack(board, word, row, col + 1, wordIndex + 1, visited) ||
            backtrack(board, word, row, col - 1, wordIndex + 1, visited);

        
        visited[row][col] = false;


        return found;
    }
};