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
int n, m; bool f;
char arr[17][2];
int x2, y2; bool vis[17][2];
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
void solve(int cnt, int last)
{
	if (cnt == n&&last==arr[1][0]) { f = 1; return; }
	if (cnt==n)return;
	for(int i=2;i<m+2;i++)
	{
		if (!vis[i][0]&&!vis[i][1]&&last == arr[i][0])
		{
			vis[i][0] = 1;
			solve(cnt + 1, arr[i][1]);
			vis[i][0] = 0;
		}
		if (!vis[i][1]&&!vis[i][0] && last == arr[i][1])
		{
			vis[i][1] = 1;
			solve(cnt + 1, arr[i][0]);
			vis[i][1] = 0;
		}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	while (cin >> n)
	{
		if (!n)break;
		cin >> m;
		for (int i = 0; i < m+2; i++)
		{
			int x, y; cin >> x >> y;
			arr[i][0] = x; arr[i][1] = y;
		}
		solve(0,arr[0][1]);
		if (f)cout << "YES\n"; else cout << "NO\n";
		f = 0;
	}
	
	//system("pause");
	return 0;
}