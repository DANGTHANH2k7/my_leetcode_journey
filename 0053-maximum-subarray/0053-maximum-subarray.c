int find(int* nums, int l, int mid, int r)
{
    int sum = 0;
    int maxl = INT_MIN;
    int maxr = INT_MIN;

    for (int i = mid; i >= l; i--)
    {
        sum += nums[i];
        maxl = fmax(maxl, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= r; i++)
    {
        sum += nums[i];
        maxr = fmax(maxr, sum);
    }

    return maxl + maxr;
}
int dq(int* nums, int l, int r)
{
    if(l == r)  return nums[l];

    int m = l + (r - l) / 2;
    
    int res1 = dq(nums, l, m);
    int res2 = dq(nums, m+1, r);
    int res3 = find(nums, l, m, r);

    return fmax(fmax(res1, res2), res3);
}

int maxSubArray(int* nums, int numsSize) 
{
    return dq(nums, 0, numsSize - 1);
}