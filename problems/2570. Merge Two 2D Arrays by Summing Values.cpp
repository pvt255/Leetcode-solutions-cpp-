class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        //nums1 = [[1,2],[2,3],[4,5]], 
        //nums2 = [[1,4],[3,2],[4,1]]
        //Output: [[1,6],[2,3],[3,2],[4,6]]
        vector<vector<int>> ans;
        int checkpoint = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int start1 =0, start2 = 0;
        ans.reserve(size1 + size2);//cấp phát bộ nhớ cố định trước cho vector.
        while(start1 < size1 && start2 < size2){
            if(nums1[start1][0]== nums2[start2][0]){
                // thêm vào mảng ans kết quả
                ans.push_back({nums1[start1][0],(nums1[start1][1] + nums2[start2][1])}); 
                start1++;
                start2++;
            }
            else if(nums1[start1][0]> nums2[start2][0]){
                ans.push_back(nums2[start2]);
                start2++;
            } 
            else if (nums1[start1][0]< nums2[start2][0]){
                ans.push_back(nums1[start1]);
                start1++;
            }     
        }
        while(start1 < size1){
            ans.push_back(nums1[start1]);
            start1++;
        }
        while (start2 < size2){
            ans.push_back(nums2[start2]);
            start2++;
        }
        return ans;
    }
};