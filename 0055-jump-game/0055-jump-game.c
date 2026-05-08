int memo[10005];

bool dp(int* nums, int j) // can jump : 0 to j
{
    if(j == 0) return true;
    if(memo[j] != -1) 
    {
        if(memo[j] == 0) return false;
        else return true;
    }

    for(int k = j-1; k >= 0; k--)
    {
        if(dp(nums, k) && nums[k] >= j-k)
        {
            memo[j] = 1;
            return true;
        }
    }

    memo[j] = 0;
    return false;
}
bool canJump(int* nums, int numsSize)
{
    memset(memo, -1, sizeof(memo));
    return dp(nums, numsSize-1);
}