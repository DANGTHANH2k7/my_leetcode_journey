int start, maxLen;
int memo[1005][1005]; char ans[1005]; // N*: Length, -1: Original, -2: No substring end i:j
int dp(char*s, int i, int j)
{
    if(i == j) return 1;
    if(i > j) return 0;

    if(memo[i][j] != -1) return memo[i][j];

    if(s[i] == s[j])
    {
        int inner = dp(s, i+1, j-1);
        if(inner != -2)
        {
            memo[i][j] = inner + 2;
            return memo[i][j];
        }
        else memo[i][j] = -2;
    }
    else memo[i][j] = -2;
    
    return memo[i][j];
}

char* longestPalindrome(char* s) 
{
    start = 0, maxLen = 1;
    memset(memo, -1, sizeof(memo));
    int slen = strlen(s);
    for(int i = 0; i < slen; i++)
    {
        for(int j = i; j < slen; j++)
        {
            int curLen = dp(s, i, j);
            if(curLen > maxLen)
            {
                maxLen = curLen;
                start = i;
            }
        }
    }
    strncpy(ans, s+start, maxLen);
    ans[maxLen] = '\0';
    return ans;
}