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
ll n, m,arr[100001],ar2[100001];
pair<bool, ll>check(ll mid)
{
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		ar2[i] = arr[i] + ((i + 1)*mid);
	sort(ar2, ar2 + n);
	for (int i = 0; i < mid; i++)sum += ar2[i];
	if (sum <= m)return make_pair(1, sum);
	 return make_pair(0, sum);
}
void binary_search()
{
	ll s = 0, e = n;
	pair<ll, ll>ret;
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		pair <bool, ll>x = check(mid);
		//cout << x.first << endl;
		if (x.first)
		{
			ret.first = mid; //cout << mid <<" ";
			ret.second = x.second; //cout << x.second << endl;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout << ret.first << " " << ret.second << endl;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	binary_search();
//	system("pause");
	return 0;
}
