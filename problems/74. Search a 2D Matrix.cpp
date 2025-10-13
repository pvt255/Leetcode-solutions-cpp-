class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();//1
        int n = matrix[0].size();//1
        int i =0;
        while(i < m){
            if(matrix[i][0] == target){
                return true;
            }
            if(matrix[i][0]>target){
                break;
            }else{
                i++;
            }
        }
        for(int j =1; j < n; j++){
            if(matrix[i==0?0:i-1][j]==target){
                return true;
            }
        }        
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();//3
        int n = matrix[0].size();//4
        //sử dụng binary search
        int left =0;
        int right = m*n-1;
        while(right >= left){
            int mid = (right+left)/2;
            int check_val = matrix[mid/n][mid%n];
            if(check_val == target){
                return true;
            }else if(check_val> target){
                right = mid-1;
            } else {
                left = mid+1;
            }

        }
        return false;
    }
};