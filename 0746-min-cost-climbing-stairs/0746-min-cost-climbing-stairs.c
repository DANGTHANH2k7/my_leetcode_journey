//int memo[1000];

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
    //memset(memo, 0, sizeof(memo));
    //memo[0]=cost[0], memo[1]=cost[1];
    int cur;
    int pre2 = cost[0], pre1 = cost[1];
    for(int i = 2; i < costSize; i++)
    {
        cur = fmin(pre1, pre2) + cost[i];
        pre2 = pre1; pre1 = cur;
    }
    return fmin(pre1, pre2);
}