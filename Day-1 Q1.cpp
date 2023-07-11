class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //creating a map
        vector<vector<int>>visited = matrix;
        // initializing the map
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                if( matrix[i][j] == 0 ){
                    // making all roe zero
                    for( int k=0; k<n; k++ ){
                        visited[k][j] = 0;
                    }
                }
            }
        }

        // for coloumn
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                if( matrix[i][j] == 0 ){
                    // making all roe zero
                    for( int k=0; k<m; k++ ){
                        visited[i][k] = 0;
                    }
                }
            }
        }
        // cpoying visited to matrix
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};
