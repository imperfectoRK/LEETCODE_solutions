class Solution {
public:
    int myAtoi(string s) {
        
        int idx = 0,n=s.size();
        //first we have to skip white space
        while (idx<n && s[idx] == ' ') idx++;

        int sign =1;

        if(idx<n && (s[idx]=='+' || s[idx]=='-'))
        {
            sign=s[idx]=='-' ?-1:1;
            idx++;
        }

        //skip all zeros
        while (idx<n && s[idx] == '0') idx++;

        int idr=idx;
        while (idr<n && isdigit(s[idr])) idr++;

        long long val=0;
        while(idx<idr)
        {

            int digit = s[idx] - '0';
            // Check overflow BEFORE multiplying
            if (val > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            val = val * 10 + digit;
            idx++;
        
        }
        if(sign==-1) return -1*val;
        return val;
    }
};
