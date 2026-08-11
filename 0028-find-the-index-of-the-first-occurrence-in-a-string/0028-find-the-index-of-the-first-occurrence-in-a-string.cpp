class Solution {
public:
    void computeLPS(vector<int> &lps,string pat)
    {
        int n=pat.length();

        int len=0; lps[0]=0;
        int i=1;
        while(i<n)
        {
            if(pat[i]==pat[len])
            {
                len++; lps[i]=len;i++;
            }
            else 
            {
                if(len!=0) len=lps[len-1];
                else len=0, i+=1;
            }
        }
    } 
    
    int strStr(string haystack, string needle) {
        int n=haystack.length(), m=needle.length();
        vector<int> result;
        vector<int> lps(m,0);
        computeLPS(lps,needle);
        int i=0,j=0;
        while(i<n)
        {
            if(haystack[i]==needle[j]) i++,j++;
            if(j==m) return(i-j);
            // {result.push_back(i-j); j=lps[j-1];}
            else if(i<n && needle[j]!=haystack[i])
            {
                if(j!=0) j=lps[j-1];
                else i++;
            }

        }
        if(result.size()>0) return result[0];
        return -1;
    }
};