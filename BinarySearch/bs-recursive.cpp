public:
    int binarySearch(vector<int>& nums, int target, int lo, int hi){
        if(lo <= hi) {
            int mid = lo + (hi-lo)/2 ;

            if(target == nums[mid]){
                return mid;
            }   
            else if(target < nums[mid]){
                return binarySearch (nums, target, lo, mid-1);
            }
            else if(target > nums[mid]){
                return binarySearch (nums, target, mid+1, hi);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int lo = 0;
       int hi = nums.size()-1;
       return binarySearch(nums, target, lo, hi);
    }
};

/* test cases
nums = [-1,0,3,5,9,12]
target = 9
https://leetcode.com/problems/binary-search/description/
*/
