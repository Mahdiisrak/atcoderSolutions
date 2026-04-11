/// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll N, W, V = 0;
    cin >> N >> W;
    vector<pair<ll, ll>> items(N);
    for (int i = 0; i < N; i++)
    {
        cin >> items[i].first >> items[i].second;
        V += items[i].second;
    }
    vector<ll> dp(V + 1, W + 1);
    dp[0] = 0;
    for (auto [w, v] : items)
    {
        for (ll j = V; j >= v; j--)
        {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }
    ll ans = 0;
    for (ll j = 0; j <= V; j++)
    {
        if (dp[j] <= W)
        {
            ans = j;
        }
    }
    cout << ans << endl;
    return 0;
}