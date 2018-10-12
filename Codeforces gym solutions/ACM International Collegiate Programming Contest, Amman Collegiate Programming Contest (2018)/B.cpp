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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
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
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	short t; cin >> t;
	while (t--)
	{
		ll x, n;
		cin >> x >> n;
		vector<ll>v(n,0);
		if (n == 1)
		{
			cout << x << endl;
			continue;
		}
		ll n2 = (n-1) * 2;
		ll k = x / n2;
		x = x % n2;
		for (int i = 1; i < n - 1; i++)
			v[i] += k * 2;
		v[0] += k; v[n - 1] += k;
		while (x)
		{
			bool f = 0;
			for (int i = 0; i < n;)
			{
				if (!x)break;
				x--;
				v[i]++;
				if (i == n - 1)f = 1;
				if (i == 0)f = 0;
				if (f)i--;
				else i++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i)cout << " ";
			cout << v[i];
		}
		cout << endl;
	}
	pause();
	return 0;
}