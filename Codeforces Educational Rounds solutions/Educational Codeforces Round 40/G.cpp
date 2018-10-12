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
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
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
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
ll n,r; ll k;
const int N = 5e5 + 100;
ll arr[N], arr2[N];
bool check(ll mid)
{
	for (int i = 1; i <= n; i++)
		arr2[i] = arr[i];
	ll sum = 0, carry = 0;
	for (int i = 1; i <= r+1; i++)
		sum += arr2[i];
	ll left=1, right=r+1;
	for (int i = 1; i <= n; i++) {
		if (sum<mid) {
			arr2[right] += mid - sum;
			carry += (mid - sum);
			if (carry>k)
				return 0;
			sum = mid;
		}
		if (right < n) { right++; sum += arr2[right]; }
		if (i > r) { sum -= arr2[left]; left++; }
	}
	return 1;
}
ll s, e;
ull bs()
{
	ll ret = s;
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (check(mid))
		{
			ret = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	return ret;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	cin >> n >> r >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		s = min(s, arr[i]);
		e += arr[i];
	}
	e += k;
	cout << bs() << endl;
	pause();
	return 0;
}