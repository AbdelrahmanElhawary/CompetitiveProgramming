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
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int arr[100001];
bool vis[100001];
int ans[100001];
int main()
{
	fast_in_out();
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int c = 0;
	for (int i = n; i >= 1; i--)
	{
		if (!vis[arr[i]])
		{
			ans[i] = ++c;
			vis[arr[i]] = 1;
		}
		else ans[i] = c;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c;
		cout << ans[c] << endl;
	}
	
	//system("pause");
	return 0;
}