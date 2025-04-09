class Solution {
    public:
        void subset(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &answer, int target){
            if (i == nums.size() || target <= 0){
                if (target == 0){
                    answer.push_back(ans);
                }
                return;
            }
            ans.push_back(nums[i]);
            subset(nums, ans, i, answer,target - nums[i]);
            ans.pop_back();
            subset(nums, ans, i+1, answer,target);
            
        }
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            vector<vector<int>> answer;
            vector<int> ans;
            subset(nums, ans, 0, answer, target);
            return answer;
        }
    };