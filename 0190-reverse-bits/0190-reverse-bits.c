int dao(int n, int len)
{
    if(len == 1)
        return n & 1;
    int half = len/2;
    int mask = (1 << len/2) - 1;
    int right = n & mask;
    int left = n >> half;
    return(dao(right, half) << half | dao(left, half));
}

int reverseBits(int n) 
{
    return dao(n, 32);
}