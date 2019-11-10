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
bool adj[17][17];
int mask[17];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	//freopen("input.txt", "r", stdin);
	string s;
	while (cin >> s)
	{
		cout << s << endl;
		if (s == "TheEnd")
			break;
		int n, s, p;
		cin >> n >> s >> p;
		memset(mask, 0, sizeof mask);
		for (int i = 0; i < p; i++)
		{
			char ch1, ch2;
			cin >> ch1 >> ch2;
			int u = ch1 - 'A'; int v = ch2 - 'A';
			adj[u][v] = adj[v][u] = 1;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mask[i] |= (adj[i][j] << j), adj[i][j] = 0;
		int ans = 0;
		for (int i = 0; i < (1 << n); i++)
		{
			if (__builtin_popcount(i) == s)
			{
				bool f = 1;
				for (int j = 0; j < n; j++)
				{
					if ((i >> j) & 1)continue;
					if(__builtin_popcount(mask[j]&i)>1)
					{
						f = 0; break;
					}
				}
				ans += f;
			}
		}
		cout << ans << endl;
	}
	pause();
	return 0;

}