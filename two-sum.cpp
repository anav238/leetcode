class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> used;
        vector<int> solution;
        for(int i = 0; i < nums.size(); i++) {
            if(used.count(target-nums[i]) > 0) {
                int j = used[target-nums[i]];
                solution.push_back(i);
                solution.push_back(j);
                break;
            }
            used[nums[i]] = i;
        }
        return solution;
    }
};