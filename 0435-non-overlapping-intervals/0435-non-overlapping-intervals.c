int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) 
{
    int cmp(const void *a, const void *b)
    {
        int **x = (int **)a;
        int **y = (int **)b;
        if(*(*x + 1) < *(*y + 1)) 
            return -1;
        else
            return 1;
    }

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int ans = 1;
    int last_end = intervals[0][1];
    for(int i = 1; i < intervalsSize; i++)
    {
        if(intervals[i][0] >= last_end)
        {
            ans ++;
            last_end = intervals[i][1];
        }
    }
    return intervalsSize - ans;
}

