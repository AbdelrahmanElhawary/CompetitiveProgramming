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
int arr[100001];
int main()
{
	int n, m,ans=0; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		arr[x] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		int t1 = arr[x], t2 = arr[y];
		if (abs(t1 - t2) % 2 && abs((n + min(t1, t2)) - max(t1, t2)) % 2)continue;
		else ans++;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}