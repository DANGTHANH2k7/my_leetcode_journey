int memo[46];

int f(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(memo[n]) return memo[n];
    else
    {
        memo[n] = f(n-1) + f(n-2);
    }
    return memo[n];
}

int climbStairs(int n) 
{
    return f(n);
}