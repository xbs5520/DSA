# Problem

you can buy and sell multi-time. Find and return max profit.

[Best Time to Buy and Sell Stock II - LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150)

# Approach

update max profit everyday, if next price is higher plus profit, if price is next lower we sell today.

# Complexity

Time: O(n)

Space: O(1)

# Code

```c++
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int low = 0;
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if(!low) low = prices[i];
            if(prices[i + 1] > low) max += prices[i + 1] - low;
            low = prices[i + 1];
        }
        return max;
    }
```
