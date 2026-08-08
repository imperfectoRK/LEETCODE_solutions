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
            val=val*10 +(s[idx]-'0');
            if(val>INT_MAX && sign==1) return INT_MAX;
            if(val>2147483648LL && sign==-1) return INT_MIN;
            idx++;
        }
        if(sign==-1) return -1*val;
        return val;
    }
};