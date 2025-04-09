class Solution {
    public:
        void permute(vector<int> &nums, vector<vector<int>> &ans, int i){
            if (i == nums.size()){
                ans.push_back(nums);
                return;
            }
            
            unordered_map<int, bool> mp;
            for (int j = i; j < nums.size(); j++){
                if (mp.find(nums[j]) != mp.end()) continue;
                mp[nums[j]] = true;
                swap(nums[i], nums[j]);
                permute(nums, ans, i+1);
                swap(nums[i], nums[j]);
            }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            // sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            permute(nums, ans, 0);
            return ans;
        }
    };