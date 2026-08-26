class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unsigned int totalXor=0;
        for(int num:nums) totalXor^=num;

        int firstSetBit=log2(totalXor&(-totalXor));

        int first=0,second=0;
        for(int num:nums)
        {
            if(num & (1<<firstSetBit))
            {
                first^=num;
            }
            else second^=num;
        }

        return {first,second};
        
    }
};