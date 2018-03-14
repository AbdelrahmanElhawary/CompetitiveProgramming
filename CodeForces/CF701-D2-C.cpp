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
int vis[200];
vector<ll>v;
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int n, m = 0; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (!vis[s[i]])m++;
		vis[s[i]] = 1;
	}
	memset(vis, 0, sizeof vis);
	int p2 = 0,ans=1e9,cnt=0;
	for (int i = 0; i < n; i++)
	{
		for (; p2 < n; p2++)
		{
			if (cnt == m)break;
			if (!vis[s[p2]])cnt++;
			vis[s[p2]]++;
		}
		if(cnt>=m)ans = min(p2 -i, ans);
		vis[s[i]]--;
		if (!vis[s[i]])cnt--;
	}
	cout << ans << endl;
	//	system("pause");
	return 0;
}