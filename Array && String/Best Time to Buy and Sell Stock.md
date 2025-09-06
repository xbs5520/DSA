# Problem

Find the best 2days to buy and sell to get max profit.

[Best Time to Buy and Sell Stock - LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

update low-price every time when current price is lower than it.

update result(current - low-price) every time current is higher. 

# Complexity

Time: O(N)

Space: O(1)

# Code

```c++
int maxProfit(vector<int>& prices) {
    int res = 0;
    if(!prices.size()) return 0;
    int low = prices[0];
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] <= low) low = prices[i];
        else res = max(res, prices[i] - low);
    }
    return res;
}
```

# Notes

if size bigger than 0 set the low-price by the first one or return 0.
