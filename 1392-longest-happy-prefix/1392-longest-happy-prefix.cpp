class Solution {
public:
    int computeLps(string pattern)
    {
        int m=pattern.size(); vector<int> lps(m);
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m)
        {
            if(pattern[i]==pattern[len])
            {
                len++; lps[i]=len; i++;
            }
            else
            {
                if(len!=0) len=lps[len-1];
                else lps[i]=0, i+=1;
            }
        }
        return lps[m-1];
    }
    string longestPrefix(string s) {
        int b = computeLps(s);
        return b == 0 ? "" : s.substr(0, b);
    }
};