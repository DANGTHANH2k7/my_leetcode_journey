int memo[100];

int dp(int* nums, int i)
{
    if(i == 0)
    {   
        memo[0] = nums[0];
        return nums[0];
    }
    if(i == 1)
    {   
        memo[1] = fmax(nums[0], nums[1]);
        return memo[1];
    }

    if(memo[i] != -1) return memo[i];
    memo[i] = fmax(dp(nums, i-1), dp(nums, i-2) + nums[i]);

    return memo[i];
}

int rob(int* nums, int numsSize) 
{
    if(numsSize==1) return nums[0];

    memset(memo, -1, sizeof(memo));
    dp(nums, numsSize-1);
    return fmax(memo[numsSize-1], memo[numsSize-2]);
}