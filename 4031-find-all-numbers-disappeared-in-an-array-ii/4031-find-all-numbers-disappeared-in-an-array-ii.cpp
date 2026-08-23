class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        long long current = lower;

        for (int num : nums) {
            if (num < current)
                continue;
            if (num > upper)
                break;
            if (num > current) {
                result.push_back({(int)current, num - 1});
            }
            current = (long long)num + 1;
        }

        if (current <= upper) {
            result.push_back({(int)current, upper});
        }

        return result;
    }
};