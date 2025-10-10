#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pll pair<long long, long long>
#define vi vector<ll>
#define dj main
#define all(x) (x).begin(), (x).end()
#define cout(x) cout << x << "\n";
ll MOD = 1e9+7;

#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cerr << #x << "-->> "; _print(x); cerr << endl;
#endif

void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void inputv(vector<ll> &v, ll n) {
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
}

class PrimeGenerator {
public:
    vector<ll> lp;
    vector<ll> hp;
private:
    static const ll N = 10000000;
    vector<bool> sieve;
    vector<ll> basePrimes;

    void createBaseSieve() {
        sieve.resize(N + 1, true);
        lp.resize(N+1,0);
        hp.resize(N+1,0);
        sieve[0] = sieve[1] = false;
        for (ll i = 2; i * i <= N; i++) {
            if (sieve[i]) {
                lp[i] = hp[i] = i;
                for (ll j = 2 * i; j <= N; j +=  i) {
                    sieve[j] = false;
                    hp[j] = i;
                    if(lp[j] == 0) {
                        lp[j] = i;
                    }
                }
            }
        }
        basePrimes.push_back(2);
        for (ll i = 3; i <= N; i += 2) {
            if (sieve[i]) {
                basePrimes.push_back(i);
            }
        }
    }

public:
    PrimeGenerator() {
        createBaseSieve();
    }

    vector<ll> getPrimes(ll n) {
        if (n <= 1) return {};
        if (n > N) return getPrimesInRange(2, n);
        vector<ll> result;
        if (n >= 2) result.push_back(2);
        for (ll i = 3; i <= n; i += 2) {
            if (sieve[i]) result.push_back(i);
        }
        return result;
    }

    vector<ll> getPrimesInRange(long long l, long long r) {
        vector<ll> result;
        if (l > r || r < 2) return result;
        if (r <= N) {
            if (l <= 2) result.push_back(2);
            for (long long i = max(3LL, l + (l % 2 == 0)); i <= r; i += 2) {
                if (sieve[i]) result.push_back(i);
            }
            return result;
        }
        l = max(2LL, l);
        vector<bool> isPrime(r - l + 1, true);
        if (l == 2) result.push_back(2);
        if (l % 2 == 0) l++;
        for (long long i = l; i <= r; i += 2) isPrime[i - l] = true;
        for (ll prime : basePrimes) {
            if ((long long)prime * prime > r) break;
            long long firstMultiple = (l / prime) * prime;
            if (firstMultiple < l) firstMultiple += prime;
            if (firstMultiple % 2 == 0) firstMultiple += prime;
            for (long long j = max(firstMultiple, (long long)prime * prime); j <= r; j += 2 * prime) {
                isPrime[j - l] = false;
            }
        }
        for (long long i = l; i <= r; i += 2) {
            if (isPrime[i - l]) result.push_back(i);
        }
        return result;
    }

    bool isPrime(long long n) {
        if (n <= 1) return false;
        if (n <= N) return sieve[n];
        for (ll prime : basePrimes) {
            if ((long long)prime * prime > n) break;
            if (n % prime == 0) return false;
        }
        return true;
    }

    vector<pair<ll, ll>> primeFactorization(ll n) {
        vector<pair<ll, ll>> factors;
        for (ll i = 2; i * i <= n; ++i) {
            ll count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            if (count > 0) factors.push_back({i, count});
        }
        if (n > 1) factors.push_back({n, 1});
        return factors;
    }
};

ll arraysum(vector<ll> &v) {
    ll ans = 0;
    for (ll i = 0; i < (ll)v.size(); i++) {
        ans += v[i];
    }
    return ans;
}

vector<ll> find_all_divisors(ll n) {
    vector<ll> x;
    ll s = sqrt(n);
    for (ll i = 1; i <= s; i++) {
        if (n % i == 0) {
            if (n / i == i) x.push_back(i);
            else {
                x.push_back(i);
                x.push_back(n / i);
            }
        }
    }
    return x;
}

ll power(ll x,unsigned ll y, ll m = MOD) {
    if(y == 0) return 1;
    ll ans = 1;
    x = x%m;
    while(y > 0) {
        if(y&1) ans = ((ans%m) * (x%m))%m;
        y = y>>1;
        x = ((x%m) * (x%m)) % m;
    }
    return ans%m;
}

ll moduloinverse(ll a,ll m) {
    return power(a,m-2,m);
}

// Disjoint Set

class DisjointSet {
    vector<ll> rank,parent,size;
public:
    DisjointSet(ll n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(ll i = 0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }


    ll findUParent(ll node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(ll u, ll v) {
        ll ulp_u = findUParent(u);
        ll ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }



    void unionBySize(ll u, ll v) {
        ll ulp_u = findUParent(u);
        ll ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


void solve();
int32_t dj() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("Error.text", "w", stderr);
    #endif
    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

void solve() {
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout("same parent so same comp");
    }else {
        cout("not in same componet");
    }

    ds.unionByRank(3,7);
    

    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout("same parent so same comp");
    }else {
        cout("not in same componet");
    }


    DisjointSet ds1(7);
    ds1.unionBySize(1,2);
    ds1.unionBySize(2,3);
    ds1.unionBySize(4,5);
    ds1.unionBySize(6,7);
    ds1.unionBySize(5,6);

    if(ds1.findUParent(3) == ds1.findUParent(7)) {
        cout("same parent so same comp");
    }else {
        cout("not in same componet");
    }

    ds1.unionBySize(3,7);
    

    if(ds1.findUParent(3) == ds1.findUParent(7)) {
        cout("same parent so same comp");
    }else {
        cout("not in same componet");
    }
}