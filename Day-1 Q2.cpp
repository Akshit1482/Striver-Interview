class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // as ascals triangle is just sum of eelements of previous row
        vector<vector<int>>ans;

        for( int i=0; i<numRows; i++ ){
            // creating a temp vector for each row
            vector<int>temp( i+1, 1);
            // size is because of 0 basedd indexing, and we'll change only elements in middle
            // ans not the first and last element
            for( int j=1; j<i; j++ ){
            // j starts from 1 becuse for 1st cloumn j-1 will be zero nad less than i, because
            // last element is also 1b
            temp[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back( temp );
        }
        return ans;
    }
};
