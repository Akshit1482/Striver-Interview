class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        map<int,int>m;
        s.push( INT_MAX ); // as we're finding greater element

        for( int i=nums2.size()-1; i>=0; i-- ){
            int curr = nums2[i];
            if( curr )
            while( s.top() <= curr ){
            s.pop(); // pooping top as it is smaller than curr                }
            }
            m[nums2[i]] = s.top() == INT_MAX ? -1:s.top();
            // backtrack
            s.push( curr ); // for next elements
        }
        vector<int>ans;
        for( auto i:nums1 ){
            ans.push_back( m[i] );
        }
        return ans;
    }
};
