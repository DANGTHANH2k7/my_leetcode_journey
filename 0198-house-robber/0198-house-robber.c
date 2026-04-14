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
        memo[1] = nums[1];
        return nums[1];
    } 

    if(memo[i] != -1) return memo[i];

    int max_i = nums[i];
    for(int j = 0; j <= i-2; j++)
    {
        max_i = fmax(max_i, dp(nums, j) + nums[i]);
    }
    memo[i] = max_i;

    return memo[i];
}

int rob(int* nums, int numsSize) 
{
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < numsSize; i++)
    {
        dp(nums, i);
    }
    int res = -1;
    for(int i = 0; i < numsSize; i++)
    {
        res = fmax(res, memo[i]);
    }
    
    return res;
}