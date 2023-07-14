class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s( nums.begin(), nums.end() );
        int ans = 0;
        for( int i=0; i<n; i++ ){
            // nums[i]-1 must not be in set,
            //basically we will start from lowest of any sequence, if nums[i]-1 exist
            // then that nums[i] is not the lowest
            if(  s.find(nums[i]-1) == s.end()){ // checking for nums-1, if nums-1 exist then its in the consequtive sequence
                int count = 1; // nums[i] will be part of the sequencce
                int num = nums[i]+1; // next in sequence
                while( s.find(num) != s.end() ){
                    // counting all sequence from nums[i]
                    count++; num++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
