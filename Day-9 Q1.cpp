class Solution
{
private:
    void solve( vector<int>&arr, int N, int ind, int sum, vector<int>&ans ){
        // base case
        if( ind == N ){
            ans.push_back(sum);
            return;
        }
        // picking a element
        sum += arr[ind];
        // call for next iteration after picked
        solve( arr, N, ind+1, sum, ans );
        // after this call we backtrack, so see the subset if we exlude this elemnt, in order
        sum -= arr[ind];
        
        // not pick
        solve( arr, N, ind+1, sum, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        int ind = 0;
        int sum = 0;
        solve( arr, N, ind, sum, ans );
        return ans;
    }
};
