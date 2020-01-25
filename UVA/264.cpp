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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
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
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
void binary_search(ll n)
{
	ll s = 1, e = 1e4, ret = s;
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		ll c = mid * (mid + 1) / 2;
		if (c < n)
		{
			ret = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	bool f = 0;
	ll x = ret + 1;
	if (x & 1)f = 1;
	ll y = ret = ret * (ret + 1) / 2;
	ll cur = n - y;
	if (f)cur = x - cur + 1;
	cout << "TERM " << n << " IS " << cur << "/" << x - cur + 1 << endl;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	ll n;
	while (cin>>n)
	{
		if (n == 1) { cout << "TERM 1 IS 1/1\n"; continue; }
		binary_search(n);
	}
	pause();
	return 0;
}