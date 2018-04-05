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
void pause(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
const int MAX = 8 * 7 / 2+1;
bool arr[8][MAX];
bool vis[8][MAX];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--)
	{
		int n, m,cnt1=0; cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		 bool f = 1;
		for (int i = 0; i < m; i++)
		{
			int cnt = 0; vector<int>v2;
			for (int j = 0; j < n; j++)
				if (arr[j][i]) { v2.push_back(j); cnt++; }
			if (cnt != 2) { f = 0; break; }
			if (vis[v2[0]][v2[1]]) { f = 0; break; }
			vis[v2[0]][v2[1]] = 1; vis[v2[1]][v2[0]] = 1;
		}
		if (f)cout << "Yes\n";
		else cout << "No\n";
		memset(vis, 0, sizeof vis);
		/*for (auto& v : adj)
			v.clear();*/
	}
	pause();
	return 0;
}