class Solution {
private:
    void solve( vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp, int ind){
        // we'll directlu put temp into ans,
        // first for empty vector, ans seond for both pick and not pick
        ans.push_back( temp );
        for( int i=ind; i<nums.size(); i++ ){
            if( i != ind && nums[i] == nums[i-1] ){
                continue; // to avoid duplicasies in subsets
            }
            temp.push_back( nums[i] );
            solve( nums, ans, temp, i+1 );
            // popping out the current element for exclude case
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // one solution we can use a set, as it contains only value
        // second APPROACH

        vector<vector<int>>ans;
        vector<int>temp;
        sort( nums.begin(), nums.end());
        solve( nums, ans, temp, 0 );
        return ans;
    }
};
