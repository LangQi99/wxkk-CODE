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
const double PI = acos(-1);

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << max(a, max(b, c)) * 2 << endl;
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
