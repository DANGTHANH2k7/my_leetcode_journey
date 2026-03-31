int cmp(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *y - *x;
}

bool makesquare(int* matchsticks, int matchsticksSize)
{
    if(matchsticksSize < 4) return false;

    int total = 0;
    for(int i = 0; i < matchsticksSize; i++)
    {
        total += matchsticks[i];
    }

    int side = total / 4;

    if(total%4) 
        return false;

    qsort(matchsticks, matchsticksSize, sizeof(int), cmp);

    if(matchsticks[0] > side)
        return false;


    bool Try(int k, int currLen, int startIndex)
    {
        if(k == 3) return true;
        for(int i = startIndex; i < matchsticksSize; i++)
        {
            if(matchsticks[i] != 0)
            {   
                if(i >= 1 + startIndex && matchsticks[i] == matchsticks[i - 1])
                    continue;
                int nextLen = currLen + matchsticks[i];
                int temp = matchsticks[i]; matchsticks[i] = 0;
                bool found = false;
                if(nextLen < side) found = Try(k, nextLen, i + 1);
                if(nextLen == side) found = Try(k+1, 0, 0);
                // nextLen > side: Skip, Backtrack
                matchsticks[i] = temp;
                if(found) return true;

                if(currLen == 0 || nextLen == side) 
                    return false;
            }
        }
        return false;
    }    

    return Try(0, 0, 0);
}
