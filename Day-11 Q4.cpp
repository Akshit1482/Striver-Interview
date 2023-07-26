class Solution {
private:
    int getPivot( vector<int>& nums, int n ){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while( s<e ){
            if( nums[mid] >= nums[0] ){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    int binarySearch(vector<int>&nums, int start, int end, int k){
        int s = start;
        int e = end;
        int mid = s + (e-s)/2;
        while( s<=e ){
            if( nums[mid] == k ){
                return mid;
            }
            else if( k > nums[mid] ){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums,n);
        // checking if the target is in left or right  of the pivot
        if( target >= nums[pivot] && target <= nums[n-1] ){ // as due to roatated sorted, arr[n-1]
        // is smaller than arr[0]
            return binarySearch(nums, pivot, n-1, target );
        }
        else{
            return binarySearch(nums, 0, pivot-1, target );
        }
    }
};
