class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        if(m*n != r*c){
            return mat;
        }
        int i1=0;
        int j1=0;
        for(int i =0; i < m; i++){
            for (int j =0; j < n; j++){
                ans[i1][j1]= mat[i][j];
                j1++;
                if(j1==c){
                    j1=0;
                    i1++;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        if(m*n != r*c){
            return mat;
        }
        int total = m*n;
        for(int i =0; i < total; i++){
            ans[i/c][i%c]= mat[i/n][i%n];
        }
        return ans;
    }
};