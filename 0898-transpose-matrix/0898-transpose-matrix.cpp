class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>res;
        for(int i=0; i<c; i++) {
            vector<int> row;
            for(int j=0; j<r; j++) {
                row.push_back(matrix[j][i]);
            }
            res.push_back(row);
        }
        return res;
    }
};