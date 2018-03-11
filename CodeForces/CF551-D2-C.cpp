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
ll n,k,arr1[100001],arr2[100001];
bool check(ll mid)
{
	
	for (int i = 0; i < n; i++)
		arr2[i] = arr1[i];
	ll N=n;
	while (N>=0 && !arr2[N])N--;
	ll cur;
	for (int i = 0; i < k; i++)
	{
		cur = mid - N-1;
		while (cur > 0)
		{
			ll ansy = min(cur, arr2[N]);
			cur -= ansy;
			arr2[N] -= ansy;
			while (N>=0 && !arr2[N])N--;
			if (N<0)return 1;
		}
	}
	return 0;
}
ll binary_search()
{
	ll s = 0, e = 1e15, ret = 1e15;
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if(check(mid))
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
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	cout << binary_search() << endl;
//	system("pause");
	return 0;
}