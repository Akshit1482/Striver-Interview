class Solution {
public:
    int myAtoi(string s) {
        int i=0, n = s.size();

        while( s[i] == ' '){
            i++; // skipping the empty space
        }
        int positive = 0, negative = 0;
        while( s[i] == '+'){
            positive++;
            i++;
        }
        while( s[i] == '-' ){
            negative++;
            i++;
        }

        double ans = 0;
        while( i<n and s[i] >= '0' && s[i] <= '9' ){
            ans = (ans*10) + ( s[i] - '0' );
            i++;
        }

        if( positive > 1 || negative > 1 ){
            return 0;
        }
        if( negative>0 ){
            ans = -ans;
        }
        if( positive>0 and negative>0 ){
            return 0; // if s = (+-12)
        }

        if( ans > INT_MAX ){
            ans = INT_MAX;
        }
        if( ans < INT_MIN ){
            ans = INT_MIN;
        }

        return (int)ans;
    }
};
