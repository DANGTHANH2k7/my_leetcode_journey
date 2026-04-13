int majorityElement(int* nums, int numsSize)
{
    int cnt = 1;
    int cdd = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] != cdd) cnt--;
        else cnt++;

        if(cnt == 0) 
        {
            cdd = nums[i];
            cnt = 1;
        }
    }
    return cdd;
}

