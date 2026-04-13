int mem[100005]; bool comp[100005];

int maxsub(int *nums, int k)
{
    if(k == 0) 
    {
        mem[0] = nums[0];
        comp[0] = true;
        return mem[0];
    }

    if(comp[k]) 
        return mem[k];
    else   
    {
        mem[k] = fmax(maxsub(nums, k-1) + nums[k], nums[k]);
        comp[k] = true;
    }
    return mem[k];
}


int maxSubArray(int* nums, int numsSize) 
{
    int max = INT_MIN;
    memset(comp, false, sizeof(comp));
    maxsub(nums, numsSize-1);
    for(int i = 0; i < numsSize; i++)
    {
        max = fmax(max, mem[i]);
    }
    return max;
}   