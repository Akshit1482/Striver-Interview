// SLIDING WINDOW
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.size() == 0 ){
            return 0;
        }
        int maxAns = INT_MIN;
        int l = 0;
        unordered_set<int>set;
        
        // traversing the string with l and r, and checking for maxlen witjout 
        //duplicates
        for( int r=0; r<s.length(); r++ ){
            if( set.find(s[r]) != set.end() ){ // we have found a duplicate
                while( l<r && set.find(s[r]) != set.end() ){
                    set.erase(s[l]); // we'll start erasing from start, as we 
                    //need subarray
                    l++;
                }
            }
            // now if there are no duplicates in the set
            set.insert(s[r]);
            maxAns = max(maxAns,((r+1)-l)); // zero based indexing
        }
        return maxAns;
    }
};
