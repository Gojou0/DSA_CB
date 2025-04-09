class Solution {
    public:
        bool Solve(vector<int>& nums, int t_sum, int i = 0, int leftsum = 0){
            if (leftsum == t_sum - leftsum && i == nums.size()){
                return true;
            }
    
            if (i == nums.size()){
                return false;
            }
    
            leftsum += nums[i];
            return canPartition(nums, i+1, leftsum);
            leftsum -= nums[i];
    
            return canPartition(nums, i+1, leftsum);
        }
        bool canPartition(vector<int>& nums, int i = 0, int leftsum = 0) {
            int totalsum = 0;
            for (int a = 0; a < nums.size(); a++) totalsum += nums[a];
    
            return Solve (nums, totalsum);
        }
    };