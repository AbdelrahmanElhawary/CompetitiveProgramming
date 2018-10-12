#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const long long mod = 1e9 + 7;

ll pwr(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient 
		ll q = a / m;
		ll t = m;

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t;
		t = y;

		// Update y and x 
		y = x - q * y;
		x = t;
	}

	// Make x positive 
	if (x < 0)
		x += m0;

	return x;
}

ll v[1000 * 1000 + 1];
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 100;
	scanf("%d", &t);
	while (t--){
		int n = 1e5;
		scanf("%d", &n);
		ll mul = 1;
		for (int i = 0; i < n; i++){
			scanf("%lld", &v[i]);
			//v[i]=1e5;
			mul = (mul * v[i]);
			mul = (mul + mod) % mod;
			assert(mul >= 0);
		}
		ll ans = 0;
		for (int i = 0; i < n; i++){
			ll  fi = (mul * (v[i] - 1)) % mod;
			ll sec = pwr(v[i], mod);
			ans = ans + (fi * sec);
			assert(ans >= 0);
			ans %= mod;
		}
		assert(ans >= 0);
		printf("%lld\n", ans);
	}
	return 0;
}