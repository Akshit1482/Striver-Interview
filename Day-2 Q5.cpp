class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // we'll xor every element with index to find the missing no.
        int ans = 0;
        for( int i=0; i<nums.size(); i++ ){
            ans ^= nums[i];
        }
        for( int i=0; i<=nums.size(); i++ ){
            ans ^= i;
        }
        return ans;
    }
};
