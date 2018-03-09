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
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int n, k;
bool check(ll m)
{
	ll ans = m,c=k;
	while (ans < n)
	{
		ans += (m / c);
		if ((m / c) == 0)return 0;
		c *= k;
		
	}
	return 1;
}
ll binary_search()
{
	ll s = 1, e = 1e9,ret=1e9;
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (check(mid))
		{
			ret = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return ret;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	cin >> n >> k;
	cout << binary_search() << endl;
	//system("pause");
	return 0;
}
