class Solution {
public:
    bool func(int minH, vector<int>& piles, int h) {
        int totHrs = 0;
        for(int i=0; i<piles.size(); i++) {
            totHrs += ceil((double)piles[i] / (double)minH);
        }
        if(totHrs <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN, res;
        for(int i=0; i<piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        for(int i=1; i<=maxi; i++) {
            if(func(i, piles, h)) { ;
                res = i;
                break;
            }
        }
        return res;
    }
};