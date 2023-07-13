class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Extended Boyer Moore’s Voting Algorithm
        // as we need element gretaer than n/3, so there we'll be two elements max
        // we'll create two counter and two element variable
        // we'll ensure that element ariable should not store same elements
        // and increse counter if encounter same variable
        // decrease if encounters the differnt one
        int cnt1= 0;
        int cnt2 = 0;
        int ans1 = INT_MIN; 
        int ans2 = INT_MIN;

        for( int i=0; i<nums.size(); i++ ){
            if( cnt1 == 0 && ans2 != nums[i] ){
                ans1 = nums[i];
                cnt1 = 1;
            }
            else if( cnt2 == 0 && ans1 != nums[i] ){
                ans2 = nums[i];
                cnt2 = 1;
            }
            else if( ans1 == nums[i] ){
                cnt1++;
            }
            else if( ans2 == nums[i] ){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
         vector<int>ls;
         // checking if the elements found are actually majority or not
         cnt1 = 0; cnt2 = 0;
         for( int i=0; i<nums.size(); i++ ){
             if( nums[i] == ans1 ) cnt1++;
             if( nums[i] == ans2 ) cnt2++;
         }

        int mini = int( nums.size()/3 ) + 1; // 0 based indexing
        if( cnt1 >= mini ) ls.push_back( ans1 );
        if( cnt2 >= mini ) ls.push_back( ans2 );

        return ls;  
    }
};
