class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();//row
        int m = matrix[0].size();//column
        vector<vector<int>> ans;
        //ans.reserve(m);
        //ans.push_back(vector<int>());
        //ans[0].reserve(n);
        for (int j = 0; j < m; j++){
            vector<int> temp;
            for (int i = 0; i < n; i++){
                temp.push_back(matrix[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};