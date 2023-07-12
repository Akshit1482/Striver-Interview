Brute Force
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n = intervals.size();
        sort( intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        // we'll check for each row
        for( int i=0; i<n; i++ ){
            int start = intervals[i][0];
            int end = intervals[i][1];

            // skipping all the skipable intervals
            if( !ans.empty() && end <= ans.back()[1] ){
               continue;
            }
            // checking for rest of the matrix
            for( int j=i+1; j<n; j++ ){
                if( intervals[j][0] <= end ){
                    end = max( end, intervals[j][1] );
                }
                else{
                    break; // the next interval don,t lie in the range
                }
            }
            ans.push_back( {start,end} );
        }
        return ans;
    }
};

.............................................................................................................................................................................

Optimize approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // sorting the matrix
        sort( intervals.begin(), intervals.end() );

        vector<vector<int>>ans;
        // iterating the matrix
        for( int i=0; i<n; i++ ){
            // pushing the first interval or the next interval that is to be pushed
            if( ans.empty() || intervals[i][0] > ans.back()[1] ){
                ans.push_back( intervals[i] );
            }
            else{ // if the new interval that is to be pushed arrived
                // updating the end interval
                ans.back()[1] = max( ans.back()[1], intervals[i][1] );
            }
        }
        return ans;
    }
};
  
