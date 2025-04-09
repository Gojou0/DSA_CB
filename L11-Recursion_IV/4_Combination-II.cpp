// on leetcode
class Solution {
    public:
        vector<vector<int>> answer;
        void combination(vector<int>& candidates, vector<int> ans, int i, int target){
            if (target <= 0){
                if (target == 0){
                    answer.push_back(ans);
                }
                return;
            }
    
            for (int j = i; j < candidates.size(); j++){
                if (j > i && candidates[j] == candidates[j-1]) continue;
                ans.push_back(candidates[j]);
                combination(candidates, ans, j+1, target - candidates[j]);
                ans.pop_back();
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<int> ans;
            combination(candidates, ans, 0, target);
            return answer;
        }
    };