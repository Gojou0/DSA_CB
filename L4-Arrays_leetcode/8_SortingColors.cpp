// on leetcode
class Solution {
    public:
        vector <int> sortColors(vector<int>& nums) {
            int n = nums.size();
            int c1 = 0;
            int c2 = 0;
            int c3 = 0;
            for (int i = 0; i < n; i++){
                if (nums[i] == 0){
                    c1++;
                }else if (nums[i] == 1){
                    c2++;
                }else{
                    c3++;
                }
            }
            for (int i = 0; i < n; i++){
                if (i < c1){
                    nums[i] = 0;
                }else if (i >= c1 && i < c2 + c1){
                    nums[i] = 1;
                }else{
                    nums[i] = 2;
                }
            }
            return nums;
        }
};