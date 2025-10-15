/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
class Solution {
private:
    void mergeArray(vector<int>& nums, int s, int e, int mid){
        
        int n1 = mid - s +1;
        int n2 = e - mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i = 0; i < n1; i++){
            left[i] = nums[s + i];
        }
        for(int i = 0; i < n2; i++){
            right[i] = nums[mid + i +1]; 
        }
        int l =0, r = 0, k = s;
        while (l < n1 && r < n2){
            if (left[l] <= right[r]){
                nums[k++] = left[l++];
            }else{
                nums[k++] = right[r++];
            }
        }
        while (l < n1){
            nums[k++] = left[l++];
        }
        while (r < n2){
            nums[k++] = right[r++];
        }
    }
    void mergeSort(vector<int>& nums, int s, int e){
        if (s >= e){
            return;
        }
        int mid = s + (e-s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        mergeArray(nums, s, e, mid);
    }

    
public:
    int majorityElement(vector<int>& nums) {
        /*
       // 1. Brute-force algorithm.
       // Time limited exceeded, 43/53 testcases passed == > worst case.
       int ans = -1;
       for (int i = 0; i < nums.size(); i++){
            int count = 0;
            for (int j =0; j < nums.size(); j++){
                if(nums[j]== nums[i]){
                    count++;
                }
            }
            if (count > nums.size()/2){
                return nums[i];
            }
       }
       return ans;
       */
    /*
    // 2. Hashmap, unordered_map
    // Time: 0ms
    // Memory: 28.22MB (28.55%)
    int ans = -1;
    unordered_map<int, int> freq;
    for(int i = 0; i < nums.size(); i++){
        freq[nums[i]]++;
        if (freq[nums[i]] > nums.size()/2){
            return nums[i];
        }
    }
    return ans;
    */ 
    // 3. Sort then check.
    //  1. Merge sort, use Quicksort3way could be better.
    //  2. because elements occurence is more than n/2 then majority is nums[mid]
    // Result: 141ms (7.34%), 96.99MB (7.76%) == not good
    /*
    int mid = nums.size()/2;
    mergeSort(nums, 0, nums.size()-1);
    return nums[mid];
    */
    // Moore Majority Voting algorithm.
    // Result: 0ms, 28.17MB (62.97%);
    int candidate;
    int count = 0;
    for (int i =0; i < nums.size(); i++){
        if (count == 0){
            candidate = nums[i];
            count = 1;
        }else if (nums[i] == candidate){
            count++;
        }else {
            count--;
        }
    }
    // assume the majority element always exists in the array > dont need to check again > return candidate
    return candidate;
    }
};class Solution {
private:
    void mergeArray(vector<int>& nums, int s, int e, int mid){
        
        int n1 = mid - s +1;
        int n2 = e - mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i = 0; i < n1; i++){
            left[i] = nums[s + i];
        }
        for(int i = 0; i < n2; i++){
            right[i] = nums[mid + i +1]; 
        }
        int l =0, r = 0, k = s;
        while (l < n1 && r < n2){
            if (left[l] <= right[r]){
                nums[k++] = left[l++];
            }else{
                nums[k++] = right[r++];
            }
        }
        while (l < n1){
            nums[k++] = left[l++];
        }
        while (r < n2){
            nums[k++] = right[r++];
        }
    }
    void mergeSort(vector<int>& nums, int s, int e){
        if (s >= e){
            return;
        }
        int mid = s + (e-s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        mergeArray(nums, s, e, mid);
    }

    
public:
    int majorityElement(vector<int>& nums) {
		/*
	   // 1. Brute-force algorithm.
	   // Time limited exceeded, 43/53 testcases passed == > worst case.
	   int ans = -1;
	   for (int i = 0; i < nums.size(); i++){
			int count = 0;
			for (int j =0; j < nums.size(); j++){
				if(nums[j]== nums[i]){
					count++;
				}
			}
			if (count > nums.size()/2){
				return nums[i];
			}
	   }
	   return ans;
       */
		/*
		// 2. Hashmap, unordered_map
		// Time: 0ms
		// Memory: 28.22MB (28.55%)
		int ans = -1;
		unordered_map<int, int> freq;
		for(int i = 0; i < nums.size(); i++){
			freq[nums[i]]++;
			if (freq[nums[i]] > nums.size()/2){
				return nums[i];
			}
		}
		return ans;
		*/ 
		// 3. Sort then check.
		//  1. Merge sort, use Quicksort3way could be better.
		//  2. because elements occurence is more than n/2 then majority is nums[mid]
		// Result: 141ms (7.34%), 96.99MB (7.76%) == not good
		/*
		int mid = nums.size()/2;
		mergeSort(nums, 0, nums.size()-1);
		return nums[mid];
		*/
		// Moore Majority Voting algorithm.
		// Result: 0ms, 28.17MB (62.97%);
		int candidate;
		int count = 0;
		for (int i =0; i < nums.size(); i++){
			if (count == 0){
				candidate = nums[i];
				count = 1;
			}else if (nums[i] == candidate){
				count++;
			}else {
				count--;
			}
		}
		// assume the majority element always exists in the array > dont need to check again > return candidate
		return candidate;
	}
};