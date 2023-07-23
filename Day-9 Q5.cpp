class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>numbers; // created to track from which numbers we have to use
        // we'll create a fact block of possibilities after picking one elment
        for( int i=1; i<n; i++ ){
            fact = fact*i;
            numbers.push_back(i);
        }
        // placing the last n
        numbers.push_back(n);
        string ans = "";
        k = k-1;
        while( true ){
            ans = ans + to_string(numbers[k/fact]);
            // removing the added number
            numbers.erase( numbers.begin() + k/fact );
            // base case
            if( numbers.size() == 0 ){
                break;
            }
            // updating k for next iteratioon, as for remaing openings, less possibilities are there
            k = k % fact;
            // updating the fact, fact decrease by factorial, as for first block of possibilites was 3!,
            // it has been reduced to 2! for next iteratiom
            fact = fact/numbers.size();
        }
        return ans;
    }
};
