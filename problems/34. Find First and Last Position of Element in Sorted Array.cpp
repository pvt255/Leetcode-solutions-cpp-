// 34. Find First and Last Position of Element in Sorted Array34. Find First and Last Position of Element in Sorted Array
// Difficulty: Med
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
/*
    int firstIndex(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        
        int ans = -1;
        while (s <= e){
            int mid = s+ (e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    int lastIndex(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        
        int ans = -1;
        while (s <= e){
            int mid = s+ (e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    */
    vector<int> findIndex(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        vector<int> v(2,-1);
        while (s <= e){
            int mid = s+ (e-s)/2;
            if(nums[mid]==target){
                int l = mid-1;
                int r = mid+1;
                while(l >= s){
                    if (nums[l] < target){
                        break;
                    }else l--;
                }
                while (r <= e){
                    if (nums[r] > target){
                        break;
                    }else r++;
                }
                v = {l+1,r-1};
                return v;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return v;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        v = findIndex(nums,target);
            
        return v;
    }
};