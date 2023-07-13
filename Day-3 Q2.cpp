class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // because we have to alter n in every step
        if( nn < 0 ){
            nn = -1 * nn; 
        }

        while( nn > 0){
            // checking if nn is odd
            if( nn % 2 == 1 ){
                ans = ans * x; // multiply ans by x one time, to make nn even
                nn = nn-1; // decreasing n to make it even
            }
            else{
                x = x*x;
                nn = nn/2; // as(2)^10 = (2^2)^5 i.e ( 2*2 )^5
            }
        }
        // checking if n is negative
        if( n < 0 ){
            ans = double(1.0) / double(ans);
        }
        return ans;
    }
};
