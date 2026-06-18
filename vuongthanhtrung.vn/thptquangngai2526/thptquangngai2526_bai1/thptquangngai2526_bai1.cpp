// Template is provided by github/nomoka-vietnam.
// Solutions are solved by github/nomoka-vietnam.
// Solution code is available at https://github.com/nomoka-vietnam/competitive-programming.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<int, int> mii;

#define FOR(a, b, c) for(int a = (b); a <= (c); a++)
#define REV(a, b, c) for(int a = (b); a >= (c); a--)

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define size(x) (int) x.size()

#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FILESTD(x) if(fopen(x".inp", "r")) freopen(x".inp", "r", stdin), freopen(x".out", "w", stdout)

#define debug(x) clog << x << endl

const ll INF = (int) 1e18;
int n;

void Read()
{
	OPTIMIZE;
	FILESTD("thptquangngai2526_bai1");
	cin >> n;
}

void Find(ll x)
{
    for (ll i = sqrt(x); i >= 1; i--)
    {
        if (x % i == 0)
        {
            ll j = x / i;
            if ((i % 2) == (j % 2))
            {
                ll y = (j - i) / 2;
                if (y > 0)
                {
                    cout << (i + j) / 2 << ' ' << y << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

void Solve()
{
	while(n--)
	{
		ll x;
		cin >> x;
		Find(x);
	}
}

int main()
{
	Read();
	Solve();
	return 0;
}