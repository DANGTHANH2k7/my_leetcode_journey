int maxArea(int* height, int heightSize)
{
    int n = heightSize;
    int r = 0, l = n-1, maxV = 0;
    while(r < l)
    {
        int hr = height[r];
        int hl = height[l];
        int len = l-r;
        int v = len*fmin(hl, hr);
        maxV = fmax(maxV, v);
        if(hr < hl) r++;
        else if(hr > hl) l--;
        else r++, l--;
    }
    return maxV;
}