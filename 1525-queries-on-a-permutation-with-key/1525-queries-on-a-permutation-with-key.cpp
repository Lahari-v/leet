class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m, 0);
        vector<int> res;
        for(int i=0; i<m; i++) {
            p[i] = i+1;
        }
        int n = queries.size();
        for(int i=0; i<n; i++) {
            int ele = queries[i];
            int pos = -1;
            for(int j=0; j<m; j++) {
                if(p[j] == queries[i])
                    pos = j;
            }
            int temp = p[pos];
            for(int k=pos; k>0; k--) {
                p[k] = p[k-1];
            }
            p[0] = temp;
            res.push_back(pos); 
        }
        return res;
    }
};