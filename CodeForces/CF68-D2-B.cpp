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
double n, k, p;
double arr[10001];
bool check(double mid)
{
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mid) ans += (arr[i]-mid) * p; 
		else ans -= (mid - arr[i]);
	}
	return ans > 0.0;
}
double binary_search()
{
	double s = 0.0, e = 1000.0, ret = 0.0;
	int t = 100;
	while (s<=e)
	{
		double mid = (s + e) / 2.0;
		if (check(mid))
		{
			ret = mid;
			s = mid+(1/1e7);
		}
		else e = mid-(1/1e7);
	}
	return ret;
}
int main() {
	fast_in_out();
		cout << fixed << setprecision(6);
	cin >> n >> k;
	p = 1.0 - (k / 100.0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << binary_search() << endl;
	//system("pause");
	return 0;
}