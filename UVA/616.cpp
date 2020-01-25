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
bool solve(ll x, ll n)
{
//	cout << n << " " << x << endl;
	for(ll i=0;i<=x;i++)
	{
		if(i!=x)
			n--;
		if (n%x)
			return 0;
		ll k = n / x;
		n -= k;
	//	cout << n << " " << x << endl;
	}

	return 1;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(3);
	ll n;
	while (cin >> n&&n>=0)
	{
		vector<ll>v;
		for (ll i = 2; i <= ceil(sqrt(n)); i++)
		{
			if ((n-1)%i == 0) {
				v.push_back(i);
				if ((n - 1) / i != i)
					v.push_back((n - 1) / i);
			}
		}
		ll mxy = -1;
		for (int i = 0; i < v.size(); i++)
		{
			if (solve(v[i],n))
				mxy = max(v[i], mxy);
		//	cout << endl;
		}
		if (mxy != -1)
			cout << n << " coconuts, " << mxy << " people and 1 monkey\n";
		else
			cout << n << " coconuts, no solution\n";
	}
	pause();
	return 0;
}