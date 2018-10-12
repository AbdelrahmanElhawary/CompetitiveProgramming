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
struct Point {
	ld x, y;
};
struct Segment {
	Point s, t;
};
bool in(ld a, ld b, ld c) {
	return c >= a && c <= b;
}
bool onLine(Segment a, Point c) {
	ld minx, maxx, miny, maxy;
	minx = min(a.s.x, a.t.x);
	maxx = max(a.s.x, a.t.x);
	miny = min(a.s.y, a.t.y);
	maxy = max(a.s.y, a.t.y);
	if (in(minx, maxx, c.x) != 0 && in(miny, maxy, c.y) != 0) 
		if ((a.s.x - a.t.x)*(c.y - a.s.y) == (a.s.y - a.t.y)*(c.x - a.s.x)) 
			return 1;
	return 0;
}
ld cross(Point o, Point a, Point b) {
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool intersection(Segment& a, Segment& b) {
	if (onLine(a, b.s) || onLine(a, b.t) || onLine(b, a.s) || onLine(b, a.t))
		return 1;
	return cross(a.s, a.t, b.s)*cross(a.s, a.t, b.t) < 0 &&
		cross(a.t, a.s, b.s)*cross(a.t, a.s, b.t) < 0 &&
		cross(b.s, b.t, a.s)*cross(b.s, b.t, a.t) < 0 &&
		cross(b.t, b.s, a.s)*cross(b.t, b.s, a.t) < 0 ;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n; 
	while (cin >> n&&n)
	{
		int ans[1001], sz = 0;
		Segment segy[1001];
		for (int i = 1; i <= n; i++)
		{
			Segment a;
			cin >> a.s.x >> a.s.y >> a.t.x >> a.t.y;
			int cnt = 0;
			for (int j = 0; j < sz; j++)
			{
				if (!intersection(a, segy[j]))
				{
					segy[cnt] = segy[j];
					ans[cnt] = ans[j];
					cnt++;
				}	
			}
			sz = cnt + 1;
			segy[cnt] = a;
			ans[cnt] = i;
		}
		cout << "Top sticks:";
		for (int i = 0; i < sz; i++) {
			if (i)cout << ",";
			cout << " " << ans[i];
		}cout << ".\n";
	}
	pause();
	return 0;
}
