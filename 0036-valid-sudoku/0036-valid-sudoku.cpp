class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int> row(10,0);
            vector<int> col(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if(row[num]) return false;
                    row[num] = 1;
                }

                if(board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    if(col[num]) return false;
                    col[num] = 1;
                }
            }
        }

          for(int r = 0; r < 9; r += 3) {
            for(int c = 0; c < 9; c += 3) {
                vector<int> box(10, 0);

                for(int i = r; i < r + 3; i++) {
                    for(int j = c; j < c + 3; j++) {
                        if(board[i][j] != '.') {
                            int num = board[i][j] - '0';
                            if(box[num]) return false;
                            box[num] = 1;
                        }
                    }
                }
            }
          }
        return true;
    }
};