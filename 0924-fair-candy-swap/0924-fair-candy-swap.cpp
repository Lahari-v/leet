class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int a1 = aliceSizes.size();
        int b1 = bobSizes.size();
        vector<int> res(2, 0);
        int sumA = 0, sumB = 0;
        for (int i = 0; i < a1; i++) {
            sumA += aliceSizes[i];
        }
        for (int i = 0; i < b1; i++) {
            sumB += bobSizes[i];
        }
        for (int i = 0; i < a1; i++) {
            for (int j = 0; j < b1; j++) {
                if (sumA - aliceSizes[i] + bobSizes[j] == sumB + aliceSizes[i] - bobSizes[j]) {
                    res[0] = aliceSizes[i];
                    res[1] = bobSizes[j];
                }
            }
        }
        return res;
    }
};