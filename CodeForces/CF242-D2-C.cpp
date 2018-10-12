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
map<pair<int, int>, bool>mp;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int r; cin >> r;
		int x, y;
		cin >> x >> y;
		for (int j = x; j <= y; j++)
			mp[{r, j}] = 1;
	}
	int ans = -1;
	queue<pair<int, pair<int, int>>>q;
	q.push({ 0,{x1,y1} });
	mp.erase({ x1,y1 });
	while (q.size())
	{
		auto cur = q.front();
		q.pop();
		int d = cur.first;
		int x = cur.second.first, y = cur.second.second;
		if(x==x2&&y==y2)
		{
			ans = d;
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i], yy = y + dy[i];
			if (mp.find({ xx,yy }) != mp.end())
				q.push({ d + 1,{xx,yy} }), mp.erase({ xx,yy });
		}
	}
	cout << ans << endl;


	pause();
	return 0;
}