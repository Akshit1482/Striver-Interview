class Solution {
public:
    bool isPossible( vector<int>& weights, int days, int n, int mid ){
        int count = 1;
        int weightSum = 0;

        for( int i=0; i<n; i++){
            if( weightSum + weights[i] <= mid ){
                weightSum += weights[i];
            }
            else{
                count++;
                if( count > days || weights[i] > mid ){
                    return false;
                }
                weightSum = weights[i]; // for the next day
            }
            if( count > days ){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = 0;
        int sum = 0;
        for( int i=0; i<n; i++ ){
            sum += weights[i];
        }
        int e = sum;

        int ans = -1;
        int mid = s + (e-s)/2;

        while( s<=e ){
            if( isPossible(weights,days,n,mid)){
                ans = mid;
                e = mid-1; // becausee all solution after this will be the soltion
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
