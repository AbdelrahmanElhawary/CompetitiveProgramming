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
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
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
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int arr[1002][1002];
int dp[1002][1002];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(3);
	int n, m,t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		memset(dp, -1, sizeof dp);
		set<pair<int, pair<int, int>>>s;
		s.insert({ arr[0][0],{0,0} });
		while (s.size())
		{
			auto cur = *s.begin();
			s.erase(s.begin());
			int x = cur.second.first, y = cur.second.second, d = cur.first;
			dp[x][y] = d;
			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i], yy = y + dy[i];
				if (xx == n || xx < 0 || yy == m || yy < 0)
					continue;
				if (dp[xx][yy] != -1 && d + arr[xx][yy] >= dp[xx][yy])
					continue;
				s.erase({ dp[xx][yy],{xx,yy} });
				dp[xx][yy] = d + arr[xx][yy];
				s.insert({ dp[xx][yy], { xx,yy } });
			}
		}
		cout << dp[n - 1][m - 1] << endl;
	}
	pause();
	return 0;
}