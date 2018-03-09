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
int arr[10002],vis[10002];
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n, m,tt=1;
	while (cin >> n >> m)
	{
		if (!n && !m)break;
		cout << "CASE# " << tt++ << ":\n";
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		for (int i = 0; i < n; i++)
			if(!vis[arr[i]])vis[arr[i]] = i + 1;
		for (int i = 0; i < m; i++)
		{
			int x; cin >> x;
			if (vis[x])cout << x << " found at " << vis[x] << endl;
			else cout << x << " not found\n";
		}
		
	}
	//system("pause");
	return 0;
}
