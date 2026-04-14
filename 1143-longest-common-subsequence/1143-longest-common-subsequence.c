int memo[1001][1001];

int lcs(char* text1, char* text2, int i, int j)
{
    if(i == -1 || j == -1)
        return 0;
    
    if(memo[i][j] != -1)
        return memo[i][j];

    if(text1[i] == text2[j])
        memo[i][j] = lcs(text1, text2, i-1, j-1) + 1;
    else
        memo[i][j] = fmax(lcs(text1, text2, i-1, j), lcs(text1, text2, i, j-1));
    
    return memo[i][j];
}

int longestCommonSubsequence(char* text1, char* text2) 
{
    memset(memo, -1, sizeof(memo));
    int n1 = strlen(text1), n2 = strlen(text2);
    return lcs(text1, text2, n1-1, n2-1);
}   