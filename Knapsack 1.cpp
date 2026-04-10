////https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> dp(w + 1, 0), prev(w + 1, 0);
    vector<pair<ll, ll>> items(n);
    for (ll i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= w; j++)
        {
            if (j >= items[i - 1].first)
            {
                ///  cout << j << " " << prev[j] << " " << prev[j - items[i - 1].first] + items[i - 1].second << endl;
                dp[j] = max(prev[j], prev[j - items[i - 1].first] + items[i - 1].second);
            }
        }
        prev = dp;
    }
    cout << dp[w] << endl;
}