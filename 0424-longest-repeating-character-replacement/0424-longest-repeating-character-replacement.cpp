class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int ans = 0, mxcount=0;
        int n = s.size();
        int right = 0, left = 0;
        while (right < n) {
            freq[s[right] - 'A']++;
            mxcount = max(mxcount, freq[s[right] - 'A']);

            while ((right - left + 1) - mxcount > k) {
                freq[s[left] - 'A']--, left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};