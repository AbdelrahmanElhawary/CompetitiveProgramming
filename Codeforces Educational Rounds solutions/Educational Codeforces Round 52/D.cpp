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
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
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
int lx[] = { 2,2,-1,1,-2,-2,-1,1 };
int ly[] = { -1,1,2,2,1,-1,-2,-2 };
const int N = 2e5 + 100;
ll arr[12][12];
int vis[12][12][4][110][200];
int n;
bool valid(int x, int y)
{
	int nn = n;
	return x >= 0 && x < nn&&y >= 0 && y < nn;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	 cin >> n; int sx, sy;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				sx = i, sy = j;
		}
	memset(vis, -1, sizeof vis);
	vis[sx][sy][0][1][0] = 0;// horse
	vis[sx][sy][1][1][0] = 0;// knight
	vis[sx][sy][2][1][0] = 0;// bishop

	queue<pair<pair<pair<int,int>, pair<int, int>>,int>>q;// move , goal , (x , y) , change
	q.push({ { {0,1},{ sx,sy } },0 });
	q.push({ { { 1,1 },{ sx,sy } },0 });
	q.push({ { { 2,1 },{ sx,sy } },0 });
	ll ans = 1e9,ans2=1e9;
	while(q.size())
	{
		auto temp = q.front();
		q.pop();
		int x = temp.first.second.first, y = temp.first.second.second;
		int move = temp.first.first.first, cur = temp.first.first.second;
		int change = temp.second;
		ll last = vis[x][y][move][cur][change];
		if (cur == n * n)
		{
			//cout<<last<<" "<<change<<endl;
			if (last < ans)
			{
				ans = last;
				ans2 = change;
			}
			else if (last == ans)
			{
				ans2 = min(ans2, (ll)change);
			}
			continue;
		}
		for (int i = 0; i < 8; i++)// horse
		{
			int xx = x + lx[i], yy = y + ly[i];
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][0][k][change + (move != 0)] == -1) {
					vis[xx][yy][0][k][change + (move != 0)] = last + 1+(move != 0);
					q.push({ {{0,k},{xx,yy}},change + (move != 0) });
				}
			}
			else if (vis[xx][yy][0][cur][change + (move != 0)] == -1) {
				vis[xx][yy][0][cur][change + (move != 0)] = last + 1 + (move != 0);
				q.push({ { { 0,cur },{ xx,yy } },change + (move != 0) });
			}
		}
		for (int i = 1; i <= n; i++)// bishob
		{
			int xx = x + i, yy = y;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][1][k][change + (move != 1)] == -1) {
					vis[xx][yy][1][k][change + (move != 1)] = last + 1+(move!=1);
					q.push({ { { 1,k },{ xx,yy } },change + (move != 1) });
				}
			}
			else if (vis[xx][yy][1][cur][change + (move != 1)] == -1) {
				vis[xx][yy][1][cur][change + (move != 1)] = last + 1+(move != 1);
				q.push({ { { 1,cur },{ xx,yy } },change + (move != 1) });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int xx = x, yy = y - i;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][1][k][change + (move != 1)] == -1) {
					vis[xx][yy][1][k][change + (move != 1)] = last + 1 + (move != 1);
					q.push({ { { 1,k },{ xx,yy } },change + (move != 1) });
				}
			}
			else if (vis[xx][yy][1][cur][change + (move != 1)] == -1) {
				vis[xx][yy][1][cur][change + (move != 1)] = last + 1 + (move != 1);
				q.push({ { { 1,cur },{ xx,yy } },change + (move != 1) });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int xx = x - i, yy = y;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][1][k][change + (move != 1)] == -1) {
					vis[xx][yy][1][k][change + (move != 1)] = last + 1 + (move != 1);
					q.push({ { { 1,k },{ xx,yy } },change + (move != 1) });
				}
			}
			else if (vis[xx][yy][1][cur][change + (move != 1)] == -1) {
				vis[xx][yy][1][cur][change + (move != 1)] = last + 1 + (move != 1);
				q.push({ { { 1,cur },{ xx,yy } },change + (move != 1) });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int xx = x, yy = y+i;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][1][k][change + (move != 1)] == -1) {
					vis[xx][yy][1][k][change + (move != 1)] = last + 1 + (move != 1);
					q.push({ { { 1,k },{ xx,yy } },change + (move != 1) });
				}
			}
			else if (vis[xx][yy][1][cur][change + (move != 1)] == -1) {
				vis[xx][yy][1][cur][change + (move != 1)] = last + 1 + (move != 1);
				q.push({ { { 1,cur },{ xx,yy } },change + (move != 1) });
			}
		}
		// last but not least
		for (int i = 1; i <= n; i++)
		{
			int xx = x + i, yy = y + i;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][2][k][change + (move != 2)] == -1) {
					vis[xx][yy][2][k][change + (move != 2)] = last + 1 + (move != 2);
					q.push({ { { 2,k },{ xx,yy } },change + (move != 2) });
				}
			}
			else if (vis[xx][yy][2][cur][change + (move != 2)] == -1) {
				vis[xx][yy][2][cur][change + (move != 2)] = last + 1+ (move != 2);
				q.push({ { { 2,cur },{ xx,yy } },change + (move != 2) });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int xx = x - i, yy = y + i;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][2][k][change + (move != 2)] == -1) {
					vis[xx][yy][2][k][change + (move != 2)] = last + 1 + (move != 2);
					q.push({ { { 2,k },{ xx,yy } },change + (move != 2) });
				}
			}
			else if (vis[xx][yy][2][cur][change + (move != 2)] == -1) {
				vis[xx][yy][2][cur][change + (move != 2)] = last + 1 + (move != 2);
				q.push({ { { 2,cur },{ xx,yy } },change + (move != 2) });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int xx = x + i, yy = y - i;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][2][k][change + (move != 2)] == -1) {
					vis[xx][yy][2][k][change + (move != 2)] = last + 1 + (move != 2);
					q.push({ { { 2,k },{ xx,yy } },change + (move != 2) });
				}
			}
			else if (vis[xx][yy][2][cur][change + (move != 2)] == -1) {
				vis[xx][yy][2][cur][change + (move != 2)] = last + 1 + (move != 2);
				q.push({ { { 2,cur },{ xx,yy } },change + (move != 2) });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int xx = x - i, yy = y - i;
			if (!valid(xx, yy))
				continue;
			int k = arr[xx][yy];
			if (k == cur + 1) {
				if (vis[xx][yy][2][k][change + (move != 2)] == -1) {
					vis[xx][yy][2][k][change + (move != 2)] = last + 1 + (move != 2);
					q.push({ { { 2,k },{ xx,yy } },change + (move != 2) });
				}
			}
			else if (vis[xx][yy][2][cur][change + (move != 2)] == -1) {
				vis[xx][yy][2][cur][change + (move != 2)] = last + 1 + (move != 2);
				q.push({ { { 2,cur },{ xx,yy } },change + (move != 2) });
			}
		}
	}
	cout << ans << " " << ans2 << endl;
	pause();
	return 0;
}