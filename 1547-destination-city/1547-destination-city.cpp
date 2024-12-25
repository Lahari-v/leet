class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string dest = paths[0][0];
        bool flag = true;
        for(int i=0; i<paths.size(); i++) {
            for(int j=0; j<paths.size(); j++) {
                if(dest == paths[j][0]) {
                    dest = paths[j][1];
                    flag = false;
                }
                if(flag)
                    return dest;
            }
        }
        return dest;
    }
};