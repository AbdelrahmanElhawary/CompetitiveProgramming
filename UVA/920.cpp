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
struct Point { int x, y; };
bool cmp(Point a, Point b)
{
		return a.x > b.x;
}
ld dis(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(2);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<Point>v(n+1);
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y;
		sort(v.begin(), v.end(), cmp);
		int mxy = 0;
		ld ansy = 0;
		for (int i = 1; i < n; i++)
		{
			if (v[i].y > mxy)
			{
				ansy += dis(v[i], v[i - 1])*(v[i].y - mxy) / (v[i].y - v[i - 1].y);
				mxy = v[i].y;
			}
		}
		cout << ansy << endl;
	}
	pause();
	return 0;
}