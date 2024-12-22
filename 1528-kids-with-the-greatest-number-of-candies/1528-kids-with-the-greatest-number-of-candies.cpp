class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), max = 0;
        vector<bool> res;
        for(int i=0; i<n; i++) {
            max = candies[i] > max ? candies[i] : max;
        }
        for(int i=0; i<n; i++) {
            if(candies[i] + extraCandies >= max)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};