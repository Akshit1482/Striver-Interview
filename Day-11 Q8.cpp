// User function Template for C++

class Solution {
public:
    bool isPossible( vector<int> &stalls, int n, int k, int mid ){
        int cowCount = 1;
        int lastPos = stalls[0];
        
        for( int i=0; i<n; i++ ){
            if( stalls[i] - lastPos >= mid ){
                cowCount++;
                if( cowCount == k ){
                    return true;
                }
                lastPos = stalls[i];
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // we are sorting the vector, cuz we'll start placing cow from start, and check the differnece in distance 
        // between the cows, by placing them on vector till maxi distance
        sort( stalls.begin(), stalls.end() );
        int s = 0;
        int maxi = -1;
        int ans = -1;
        for( int i=0; i<n; i++ ){
            maxi = max( maxi, stalls[i] );
        }
        int e = maxi;
        int mid = s + (e-s)/2;
        
        while( s<=e ){
            if( isPossible(stalls, n, k, mid )){
                ans = mid; // as we have to return the maximum distance between them
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
