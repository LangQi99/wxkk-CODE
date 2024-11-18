#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;
#define ll long long
#define ld long double
#define cp complex<ld>
#define endl '\n'
#define FOR(i, l, r) for (ll i = (l); i <= (r); i++)
#define debug(x) cout << #x << " = " << x << endl;
const double PI = acos(-1);
int mu[2000005];
int pre[2000005];
int prime[2000005];
int tot;
bool b[2000005];
int a[2000005];
ll g[2000005];
ll f[2000005];
int cnt[2000005];
inline void shai_mu(int n)
{
    mu[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!b[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= tot; ++j)
        {
            if (i * prime[j] > n)
                break;
            b[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + mu[i];
}
void solve()
{
    int n, q, MAX = -1;
    cin >> n;
    // shai_mu(n);
    FOR(i, 1, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
        MAX = max(MAX, a[i]);
    }
    FOR(x, 1, MAX)
    {
        for (int y = 2 * x; y <= MAX; y += x)
        {
            cnt[x] += cnt[y];
        }
        debug(cnt[x]);
    }
    FOR(i, 0, MAX)
    {
        f[i] = (1ll << cnt[i]) - 1 - cnt[i];
    }
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << f[x] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
