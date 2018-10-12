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
int main() {
	fast_in_out();
//	cout << fixed << setprecision(3);
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		vector<vector<int>>arr(n);
		for (auto&v : arr)
			v.resize(m, 1e9);
		int k; cin >> k;
		for (int i = 0; i < k; i++)
		{
			int x; cin >> x;
			int w; cin >> w;
			for (int ii = 0; ii < w; ii++)
			{
				int y; cin >> y;
				arr[x][y] = -1;
			}
		}
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		set<pair<int, pair<int, int>>>s;
		s.insert({ 0,{sx,sy} });
		while (s.size())
		{
			auto cur = *s.begin();
			s.erase(s.begin());
			int x = cur.second.first, y = cur.second.second, d = cur.first;
		//	cout << x << " " << y << endl;
			arr[x][y] = d;
			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i],yy=y+dy[i];
				if (xx < 0 || xx == n || yy < 0 || yy == m)
					continue;
				if (arr[xx][yy] <= d + 1||arr[xx][yy]==-1)
					continue;
				s.erase({ arr[xx][yy],{xx,yy} });
				arr[xx][yy] = d + 1;
				s.insert({ d + 1,{xx,yy} });
			}
		}
		cout << arr[ex][ey] << endl;
	}
	pause();
	return 0;
}