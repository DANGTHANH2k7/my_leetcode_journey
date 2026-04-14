int memo[1000];

// int dp(int i, int* cost)
// {
//     if(i == 0) return cost[0];
//     if(i == 1) return cost[1];

//     if(memo[i]) return memo[i];

//     memo[i] = fmin(dp(i-1, cost), dp(i-2, cost)) + cost[i];
//     return memo[i];
// }

int minCostClimbingStairs(int* cost, int costSize) 
{
    memset(memo, 0, sizeof(memo));
    memo[0]=cost[0], memo[1]=cost[1];
    for(int i = 2; i < costSize; i++)
    {
        memo[i] = fmin(memo[i-1], memo[i-2]) + cost[i];
    }
    return fmin(memo[costSize-1], memo[costSize-2]);
}