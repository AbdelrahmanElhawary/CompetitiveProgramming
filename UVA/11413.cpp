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
ll n, arr[10001], m;
bool check(ll x)
{
	ll c = 0,sum=0;
	for (int i = 0; i < n; i++)
	{
		if (c >= m)return 0;
		sum += arr[i];
		if (sum < x)continue;
		if (sum == x) { c++; sum = 0; continue; }
		sum -= arr[i]; c++;
		sum = 0; i--;
	}
	if (sum)c++;
	if (c > m)return 0;
	return 1;

}

ll binary_search()
{
	ll s = 1, ret=1e12,e=1e12;
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
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << binary_search() << endl;
	}
	//system("pause");
	return 0;
}
