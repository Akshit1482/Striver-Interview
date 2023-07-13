class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore Voting Algorithm
        int count = 0;
        int element;
        // we'll traverse the array
        // if count is 0, we select current eleement as element
        // if count != 0, if current == element, count++,
        // else, current != element, count--;
        for( int i=0; i<nums.size(); i++ ){
            if( count == 0 ){
                element = nums[i];
                count++;
            }
            else if( count != 0 && nums[i] == element ){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};
