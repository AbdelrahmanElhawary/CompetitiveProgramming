#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(3);
	int t; cin >> t;
	cin.ignore();
	while (t--)
	{
		ll l, r;
		cin >> l >> r;
		ll le = l;
		ll ans = l,mxd=0;
		for (; l <= r; l++)
		{
			ll cnt = 0;
			for (ll i = 1; i*i <= l; i++)
				if (l%i == 0)
					if (i != l / i)
						cnt += 2;
					else cnt++;
					if (cnt > mxd)
						ans = l, mxd = cnt;
		}
		cout << "Between " << le << " and " << r << ", " << ans << " has a maximum of " << mxd << " divisors.\n";
	}
	pause();
	return 0;
}