char nsub[100];
//a-z: 97 - 122
//A-Z: 65-90

char* daq(char *s, int l, int r)
{
    int cnt[256]; 
    int delimID[100];
    memset(cnt, 0, sizeof(cnt));
    memset(delimID, 0, sizeof(delimID));
    int delimNum = 0;
    int len = r-l+1;

    if(len < 2) return "";

    for(int i = l; i <= r; i++)
    {
        cnt[s[i]]++;
    }

    for(int i = l; i <= r; i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
        {
            if(cnt[s[i]] && !cnt[s[i] + 32])
                delimID[delimNum++] = i;
        }
        if('a' <= s[i] && s[i] <= 'z')
        {
            if(cnt[s[i]] && !cnt[s[i] - 32])
                delimID[delimNum++] = i;
        }
    }

    if(delimNum == 0)
    {
        char *sub = (char *) malloc (sizeof(char) * (len+1));
        strncpy(sub,s+l, len);
        sub[len] = '\0';
        return sub;
    }
 
    char *maxSub = (char *) malloc (sizeof(char) * (len+1));
    maxSub[0] = '\0';
    int curL=l;
    for(int i = 0; i <= delimNum; i++)
    {
        int curR;
        if(i < delimNum) curR=delimID[i] - 1;
        else
            curR = r;
        char* res = daq(s, curL, curR);
        if(strlen(res) > strlen(maxSub))
        {
            strcpy(maxSub, res);
        }
        if(i < delimNum) curL = delimID[i] + 1;
    }
    return maxSub;
}

char* longestNiceSubstring(char* s)
{
    int slen = strlen(s);
    char* nsub = daq(s, 0, slen-1);
    return nsub; 
}
