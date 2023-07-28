class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>result;
            int n = haystack.size() - needle.size();
            
            // now we traverse on txt
            for( int i=0; i<=n; i++ ){
                string temp = haystack.substr(i, needle.size());
                if( temp == needle ){
                    result.push_back( i );
                }
            }
            if( result.size() == 0 ){
                result.push_back(-1);
            }
            return result[0];
    }
}; 
