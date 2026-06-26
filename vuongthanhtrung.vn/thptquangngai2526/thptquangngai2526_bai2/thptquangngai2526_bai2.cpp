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

int T;

void Read()
{
    OPTIMIZE;
    FILESTD("thptquangngai2526_bai2");
    cin >> T;
}

vi Era_sieve(int MAXPRIME)
{
    vector<bool> isPrime(MAXPRIME + 1, true);
    vi primes;
    primes.reserve(MAXPRIME / 10);
    if (MAXPRIME < 2) return primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXPRIME; i++)
    {
        if (isPrime[i])
        {
            primes.pb(i);
            if (1LL * i * i <= MAXPRIME) {
                for (ll j = 1LL * i * i; j <= MAXPRIME; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    return primes;
}

int Seg_sieve(ll L, ll R)
{
    if (L < 2) L = 2;
    if (L > R) return 0;
    int MAXPRIME = sqrt(R) + 1;
    vi bPrimes = Era_sieve(MAXPRIME);
    int len = R - L + 1;
    vector<bool> isPrime(len, true);
    for (int p : bPrimes)
    {
        if (1LL * p * p > R) break;
        ll start = max(1LL * p * p, (L + p - 1) / p * p);
        for (ll j = start; j <= R; j += p)
        {
            isPrime[j - L] = false;
        }
    }
	int cnt = 0;
	for (bool prime : isPrime)
	{
	    if (prime)
	    {
	    	cnt++;
	    }
	}
    return cnt;
}

void Solve()
{
    while (T--)
    {
        ll L, R;
        cin >> L >> R;
        cout << Seg_sieve(L, R) << endl;
    }
}

int main()
{
    Read();
    Solve();
    return 0;
}