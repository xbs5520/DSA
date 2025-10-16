int lower_bound(const int* a, int n, int target) 
{
    int l = 0, r = n; // [l, r)
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] < target)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int upper_bound(const int* a, int n, int target) 
{
    int l = 0, r = n; // [l, r)
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= target)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

/*
Proof of invariants:
- For lower_bound, at any time, all indices in [0, l) have a[idx] < target, all in [r, n) have a[idx] >= target.
- For upper_bound, at any time, all indices in [0, l) have a[idx] <= target, all in [r, n) have a[idx] > target.
- The loop maintains these invariants and shrinks [l, r) until l == r, which is the answer.
*/

// void test_lower_upper_bound() {
//     int a[] = {1, 3, 3, 5, 7, 9};
//     int n = sizeof(a) / sizeof(a[0]);

//     // lower_bound tests
//     printf("lower_bound 3: %d (expect 1)\n", lower_bound(a, n, 3));
//     printf("lower_bound 4: %d (expect 3)\n", lower_bound(a, n, 4));
//     printf("lower_bound 0: %d (expect 0)\n", lower_bound(a, n, 0));
//     printf("lower_bound 10: %d (expect 6)\n", lower_bound(a, n, 10));

//     // upper_bound tests
//     printf("upper_bound 3: %d (expect 3)\n", upper_bound(a, n, 3));
//     printf("upper_bound 5: %d (expect 4)\n", upper_bound(a, n, 5));
//     printf("upper_bound 9: %d (expect 6)\n", upper_bound(a, n, 9));
//     printf("upper_bound 0: %d (expect 0)\n", upper_bound(a, n, 0));
// }