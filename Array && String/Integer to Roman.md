# Problem

Transform Integer to Roman.

[Integer to Roman - LeetCode](https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150)

# Approach

greedy - Use a map(descending order values -- symbols) 

For each value, repeatedly subtracts the value from number and appends symbol to the result string until the number is reduced to 0.

# Complexity

Time: O(1)

Space: O(1)

# Code

```c++
    string intToRoman(int num) {
        unordered_map<int, string> hash = {
            {1000, "M"}, {900, "CM"}, {500, "D"},
            {400, "CD"}, {100, "C"},  {90, "XC"},
            {50, "L"},   {40, "XL"},  {10, "X"},
            {9, "IX"},   {5, "V"},    {4, "IV"},
            {1, "I"}};
        int a[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s = "";
        for(int i = 0; i < 13; i++)
        {
            while(num >= a[i])
            {
                s += hash[a[i]];
                num -= a[i];
            }
        }
        return s;
    }
```

# Notes

better way to record map

```c++
string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    string s = "";
    for (auto& [value, symbol] : roman) {
        while (num >= value) {
            s += symbol;
            num -= value;
        }
    }
    return s;
}
```

