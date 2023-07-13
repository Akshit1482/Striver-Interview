class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col-1;

        int mid = start + (end-start)/2;

        while( start <= end ){
            int element = matrix[mid/col][mid%col]; 
            // row is check by mid/col, as for first row, it will rremain zero for first col lements,
            // and then 1 for next col elements
            // col is check by mid%col, as for first col elements it start from 0 to col,
            // then again gets 0 after col elements
            if( element == target ){
                return true;
            }
            else if( element < target ){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return false;
    }
};
