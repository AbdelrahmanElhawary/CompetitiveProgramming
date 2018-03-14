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
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
ll n;
ll sum_dig(ll mid)
{
	ll c = 0;
	while (mid)
	{
		c += mid % 10;
		mid /= 10;
	}
	return c;
}

int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	cin >> n;
	ll x = sqrt(n);
	x = max(0LL, x - 10000);
	bool f = 0;
	for (ll i = x; i*i <= n; i++)
	{
		if((i*i+sum_dig(i)*i)==n)
		{
			f = 1;
			cout << i << endl;
			break;
		}
	}
	if (!f)cout << -1 << endl;


	//system("pause");
	return 0;
}