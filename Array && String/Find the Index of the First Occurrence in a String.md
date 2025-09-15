# Problem

Implement a function that finds the first occurrence of a substring(strstr)

# Approach

KMP

# Complexity

Time: O(n + m)

Space: O(n)

# Code

```c++
int strStr(string s, string p) {
    int n = p.size();
    int m = s.size();
    int ne[10010];
    s = " " + s;
    p = " " + p;
    for(int i = 2, j = 0; i <= n; i++)
    {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= m; i++)
    {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j++;
        if(j == n)
        {
            return i - n;
            j = ne[j];
        }
    }
    return -1;
}
```

# Notes

template  to remember!

both str must start at 1 !

```c++
const int N = 100010, M = 1000010;
int n, m;
char p[N], s[M];
int ne[N];

int main(){
    int n = p.size();
    int m = s.size();
    int ne[10010];
    s = " " + s;
    p = " " + p;
    for (int i = 2, j = 0; i <= n; i ++ )
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
	// look at O(n^2) but it is O(n)
    for (int i = 1, j = 0; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];		
            // find substr
        }
    }
    return 0;
}
```

