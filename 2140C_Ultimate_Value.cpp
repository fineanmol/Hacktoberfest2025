#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    // your code goes here
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += (i % 2 == 0) ? a[i] : -a[i];
        }

        int ans = temp;

        for (int i = 0; i < n; i++) {
            ans = max(ans, temp + i - (i % 2));
        }
        int minEven = LLONG_MAX / 2;
        int minOdd = LLONG_MAX / 2;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                ans = max(ans, temp + i + 2 * a[i] - minEven);
                minOdd = min(minOdd, i - 2 * a[i]);
            } else {
                ans = max(ans, temp + i - 2 * a[i] - minOdd);
                minEven = min(minEven, i + 2 * a[i]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
