class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // edge cases
        if( n == 1 )  return nums[0];
        if( nums[0] != nums[1] ) return nums[0];
        if( nums[n-1] != nums[n-2] ) return nums[n-1];

        int low = 1, high = n-2;

        while( low <= high ){
            int mid = low + (high-low)/2;

            // condition for single element
            if( nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1] ){
                return nums[mid];
            }

            // as we know nums is of odd length
            // if mid is not single lement it is on one of the side
            // if its on left side, than there will be even number of elements on the left, so they all will be occuring twice
            if(( mid%2 == 1 && nums[mid] == nums[mid-1] )|| 
            ( mid%2 == 0 && nums[mid] == nums[mid+1])){
                // eliminate left half
                low = mid+1;
            }
            // we are in right half
            else{
                high = mid-1;
            }
        }
        // dummy return statement
        return -1;
    }
};
