#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int max_time(ll a, ll b, ll n, vector<ll> &tools)
{

    ll time = 0;

    sort(tools.begin(), tools.end());

    time += b;

    for (int i =0 ; i < n ; i++){
        b += tools[i];
        if ( i!= n-1){
            if (b > a){
                b -= tools[i];
                time += b-1;
            }

        }

        else {
            if (b>a){
                b -= tools[i];
                time += b-1;
                time += tools[i]-1;


            }
        }
    }

    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        vector<ll> tools(n);
        for (int i = 0; i < n; i++)
        {
            cin >> tools[i];
        }
        cout << max_time(a, b, n, tools) << endl;
    }

    return 0;
}