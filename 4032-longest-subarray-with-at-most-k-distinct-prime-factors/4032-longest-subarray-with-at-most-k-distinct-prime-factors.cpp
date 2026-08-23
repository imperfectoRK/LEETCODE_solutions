class Solution {
public:
    unordered_set<int> getPrimeFactors(int n) 
    {
        unordered_set<int> factors;
        for (int d = 2; d * d <= n; ++d) 
            if (n % d == 0) {
                factors.insert(d);
                while (n % d == 0)  n /= d;
            }
        if (n > 1) factors.insert(n);
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<unordered_set<int>> num_factors(n);

        for(int i=0;i<n;i++) num_factors[i] = getPrimeFactors(nums[i]);
        int left = 0, max_len = 0;
        unordered_map<int, int> prime_counts;

        for(int right=0;right<n; right++)
        {
            for(int p: num_factors[right]) prime_counts[p]++;
            while(prime_counts.size()>k)
            {
                for(int p:num_factors[left])
                {
                    prime_counts[p]--;
                    if(prime_counts[p]==0)prime_counts.erase(p);
                }
                left++;
            }
            max_len=max(max_len,right-left+1);
        }
        return max_len;
        
        
    }
};