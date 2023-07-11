class Solution {
private:
    void reverse(vector<int>& nums, int s, int e) {
        while(s < e) {
            swap(nums[s++], nums[e--]);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        // finding the the greatest element from last
        int n = nums.size();
        int index = -1;
        for( int i=n-2; i>=0; i-- ){
            if( nums[i] < nums[i+1] ){
                index = i;
                break; // finding the index which need to be swapped
            }
        }

        if( index != -1 ){
        // we need to swap the first greater element from right with  index element
            for( int i=n-1; i>index; i-- ){
                if( nums[i] > nums[index] ){
                    swap( nums[i],nums[index] );
                    break;
                }
            }
        }
        reverse(nums, index+1, n-1);
    }
};
