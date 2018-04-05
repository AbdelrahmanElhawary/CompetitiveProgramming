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
int n, m;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
set<vector<int>>s;
bool vis[8], vis2[16], vis3[16];
int x, y;
void solve(int r, vector<int>v)
{
	if (r == x)solve(r + 1, v);
	if (r == 8) { s.insert(v);  return; }
	for (int i = 0; i < 8; i++)
	{
		if (!vis[i] && !vis2[r - i + 8] && !vis3[i + r])
		{
			vis[i] = 1; vis2[r - i + 8] = 1; vis3[i + r] = 1;
			v[i] = r;
			solve(r + 1,v);
			vis[i] = 0; vis2[r - i + 8] = 0; vis3[i + r] = 0;
		}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int tt = 1, t; cin >> t;
	while (t--)
	{
		 cin >> x >> y;
		vector<int>v(9);
		y--; x--;
		v[y] = x; vis[y] = 1; vis2[x - y + 8] = 1; vis3[y + x] = 1;
		solve(0,v);
		if (tt > 1)cout << endl;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		int c = 0;
		while (s.size())
		{
			if (c<9)
				cout << " " << ++c << "      ";
			else cout << ++c << "      ";
			v = *s.begin();
			for (int i = 0; i < v.size()-2; i++)
				cout << v[i]+1 << " "; cout << v[v.size() - 2]+1 << endl;
			s.erase(s.begin());
		}
		if (t)cout << endl;
		memset(vis, 0, sizeof vis);
		memset(vis2, 0, sizeof vis2);
		memset(vis3, 0, sizeof vis3);
		
	}
	
	//system("pause");
	return 0;
}