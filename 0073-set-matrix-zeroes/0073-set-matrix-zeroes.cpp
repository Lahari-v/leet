class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int x = 0, y = 0;

        for(int i=0; i<r; i++) {
            if(matrix[i][0] == 0) {
                y = -1;
                break;
            }
        }
        for(int j=0; j<c; j++) {
            if(matrix[0][j] == 0) {
                x = -1;
            }
        }

        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<r; i++) {
            if(matrix[i][0] == 0) {
                for(int j=1; j<c; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1; j<c; j++) {
            if(matrix[0][j] == 0) {
                for(int i=1; i<r; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(x == -1) {
            for(int j=0; j<c; j++) {
                    matrix[0][j] = 0;
                }
        }
        if(y == -1) {
            for(int i=0; i<r; i++) {
                    matrix[i][0] = 0;
                }
        }
    }
};