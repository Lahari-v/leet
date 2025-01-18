class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        int n1 = n; 
        if(n1<0) {
            n1 = -(long long)n;
            x = 1/x;
        }
        if(n1%2 == 0)
            return myPow(x*x, n1/2);
        else
            return x*myPow(x*x, n1/2);
    }
};