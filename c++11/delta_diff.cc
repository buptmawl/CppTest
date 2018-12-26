#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int a[N];

int main() {
    int n, k; cin >> n >> k;
    a[1] = 1;
    for (int i = 2, j = k; i <= k + 1; i++, j--)
    {
        if (i & 1) a[i] = a[i - 1] - j;
        else a[i] = a[i - 1] + j;
    }
    for (int i = k + 2; i <= n; i++) a[i] = i;
    
    for (int i = 1; i <= n; i++)
        printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}
