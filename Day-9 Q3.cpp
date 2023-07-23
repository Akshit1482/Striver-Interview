class Solution {
private:
    void solve( vector<int>& candidates, vector<vector<int>>&ans, vector<int>&temp, int ind, int target ){
        //base ccase
        if( ind == candidates.size() ){
            if( target == 0 ){
                ans.push_back( temp );
            }
            return;
        }
        if( candidates[ind] <= target ){
            temp.push_back( candidates[ind] );
            solve( candidates, ans, temp, ind, target-candidates[ind] );
            temp.pop_back();
        }
        solve( candidates, ans, temp, ind+1, target );

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        vector<vector<int>>ans;
        vector<int>temp;
        int ind = 0;
        solve( candidates, ans, temp, ind, target );
        return ans;
    }
};
