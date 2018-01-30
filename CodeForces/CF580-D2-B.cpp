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
#define F first
#define S second
#define ll long long
using namespace std;
pair<int, int>arr[100001];
int main()
{
	int n, m;
	cin >> n >> m;
	ll ansy1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first>> arr[i].second;
	}
	sort(arr, arr + n);
	int p1 = 0,p2=0;
	ll ansy = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (p2 < n&&abs(arr[p1].F - arr[p2].F) < m) ansy += arr[p2++].second; 
		ans = max(ans, ansy);
		ansy -= arr[p1++].second;
	}
	cout << ans << endl;
//	system("pause");
	return 0;
}