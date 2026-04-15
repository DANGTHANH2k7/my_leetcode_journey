int memo[100];

int dp(int* nums, int i, int start)
{
    if(start == 1) memo[0] = 0;

    if(i == start)
    {   
        memo[start] = nums[start];
        return nums[start];
    }

    if(start == 0)
    {
        if(i == 1)
        {
            memo[1] = fmax(nums[0], nums[1]);
        }
    }

    if(memo[i] != -1) return memo[i];
    memo[i] = fmax(dp(nums, i-1, start), dp(nums, i-2, start) + nums[i]);

    return memo[i];
}

int rob(int* nums, int numsSize) 
{
    if(numsSize==1) return nums[0];

    memset(memo, -1, sizeof(memo));
    int res1 = dp(nums, numsSize-2, 0);
    memset(memo, -1, sizeof(memo));
    int res2 = dp(nums, numsSize-1, 1);
    return fmax(res1, res2);
}