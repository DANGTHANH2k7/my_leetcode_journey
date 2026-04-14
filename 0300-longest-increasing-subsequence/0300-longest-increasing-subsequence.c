int memo[2501];

int dp(int* nums, int i)
{
    if(i == 0) 
    {
        memo[0] = 1;
        return 1;
    }

    if(memo[i] != 0) return memo[i];    

    int maxi = 1;
    for(int j = 0; j < i; j++)
    {
        if(nums[j] < nums[i])
        {   
            maxi = fmax(maxi, dp(nums, j) + 1);
        }
    }
    memo[i] = maxi;

    return memo[i];
}

int lengthOfLIS(int* nums, int numsSize) 
{
    memset(memo, 0, sizeof(memo));
    int res = -1;
    for(int i = 0; i < numsSize; i++)
    {
        res = fmax(res, dp(nums, i));
    }
    return res;
}