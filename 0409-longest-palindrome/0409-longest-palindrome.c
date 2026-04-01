int count[125];

int longestPalindrome(char* s) 
{
    memset(count, 0, sizeof(count));
    int ans = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int id = s[i] - 'A';
        count[id]++;
    }
    for(int i = 0; i < 125; i++)
    {
        if(count[i] % 2 == 0)
        {
            ans += count[i];
            count[i]=0;
        }
        if(count[i] % 2 == 1)
        {
            ans += count[i] - 1;
            count[i] = 1;
        }
    }
    for(int i = 0; i < 125; i++)
    {
        if(count[i] == 1)
        {
            ans ++;
            break;
        }
    }
    return ans;
}