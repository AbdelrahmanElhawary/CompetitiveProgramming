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
#define ull unsigned ll 
#define dong long
#define endl '\n'
#define mk make_pair
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
ll n, arr[5], vis[5]; bool fl;
void solve(ll cnt,ll sum,bool f)
{
	if (cnt == 5 && sum == 23) { fl = 1; return; }
	if (cnt == 5)return;
	for (int i = 0; i < 5; i++) {
		if (vis[i])continue;
		vis[i] = 1;
		if (!f) {
			solve(cnt + 1, sum*arr[i], 0);
			solve(cnt + 1, sum + arr[i], 0);
			solve(cnt + 1, sum - arr[i], 0);
		}
		else solve(cnt + 1, arr[i],0);
		vis[i] = 0;
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	while (1)
	{
		bool f = 1;
		for (int i = 0; i < 5; i++)
		{
			cin >> arr[i];
			if (arr[i])f = 0;
		}
		if (f)break;
		solve(0, 0, 1);
		if (fl)cout << "Possible\n"; else cout << "Impossible\n";
		fl = 0;
	}
	//system("pause");
	return 0;
}