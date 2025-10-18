// Simple C++17 template for competitive programming (Codeforces)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

// fast input/output
static void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// place your solution for one test case here
void solve() {
    // Example: read n and array, print sum
    int n;
    if (!(cin >> n)) return;         // defensive: in some one-case problems
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll sum = 0;
    for (ll x : a) sum += x;
    cout << sum << '\n';
}

int main() {
    fast_io();

    int T = 1;
    // if multiple testcases, uncomment the next line
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
