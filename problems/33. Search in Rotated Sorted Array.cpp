class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int mid =0;
        int ans =-1;
        while (s <=e){
            mid = s + (e-s)/2;
            if (nums[mid] == target){
                ans = mid;
                return ans;
            }else if (nums[mid] >= nums[s]){
                if (nums[s] <= target && target < nums[mid]){
                    e = mid -1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[mid] <= nums[e]) {
                if (nums[mid] < target && target <= nums[e]){
                    s = mid+1;
                } else {
                    e = mid -1;
                }
            }
        }
        return ans;
    }
};