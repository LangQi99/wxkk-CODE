#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <unordered_map>
using namespace std;
#define ll long long
#define ld long double
#define cp complex<ld>
#define endl '\n'
#define FOR(i, l, r) for (ll i = (l); i <= (r); i++)
const double PI = acos(-1);

template <typename _Mn, typename _Nn>
constexpr common_type_t<_Mn, _Nn>
__gcd(_Mn __m, _Nn __n)
{
    return __m == 0   ? abs(__n)
           : __n == 0 ? abs(__m)
                      : __gcd(__n, __m % __n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    unordered_map<int, ll> gcdcnt;
    unordered_map<int, ll> prev;
    for (int num : a)
    {
        unordered_map<int, ll> now;
        now[num]++;
        for (auto [g, cnt] : prev)
        {
            int new_gcd = __gcd(g, num);
            now[new_gcd] += cnt;
        }
        for (auto [g, cnt] : now)
        {
            gcdcnt[g] += cnt;
        }
        prev = now;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << (gcdcnt.find(q) != gcdcnt.end() ? gcdcnt[q] : 0) << " ";
    }
}