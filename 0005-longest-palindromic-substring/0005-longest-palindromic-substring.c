int start, maxLen;
char ans[1005]; 

char* longestPalindrome(char* s) 
{
    int n = strlen(s);
    if (n <= 1) return s;

    start = 0;
    maxLen = 1;
    
    for (int i = 0; i < n; i++) 
    {
        //Tam la ki tu
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) 
        {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--; r++;
        }
        //Tam la khoang trong giua 2 ki tu
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) 
        {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--; r++;
        }
    }

    strncpy(ans, s + start, maxLen);
    ans[maxLen] = '\0'; 

    return ans;
}