#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int x = a[i] + a[j];
            int k = lower_bound(a + j + 1, a + n, x) - a - j - 1;
            ans += k;
        }
    cout << ans;
    return 0;
}
