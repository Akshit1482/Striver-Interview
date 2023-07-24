class Solution {
private:
    void solve( vector<int>&nums, vector<vector<int>>&ans, int ind ){
        // base case
        if( ind >= nums.size() ){
            ans.push_back( nums );
            return;
        }

        for( int k=ind; k<nums.size(); k++ ){
            swap( nums[k], nums[ind] );
            solve( nums, ans, ind+1);
            // backtrack
            swap( nums[k], nums[ind] );
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int ind = 0;
        solve( nums, ans, ind );
        return ans;
    }
};
