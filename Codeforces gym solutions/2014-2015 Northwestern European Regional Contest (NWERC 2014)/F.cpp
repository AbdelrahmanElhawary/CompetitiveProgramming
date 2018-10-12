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
const double EPS = 1e-9;
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
bool isCollinear(point a, point b, point c) {
	return fabs(cp(b - a, c - a)) < EPS;
}

int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	srand(time(NULL));
	int n, p;
	cin >> n >> p;
	if (n == 1)
	{
		cout << "possible\n";
		return 0;
	}
	vector<point>v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i]=point(x,y);
	}
	int t = 1000;
	int mx=2;
	while(t--)
	{
		int a, b;
		a = (rand())*(rand())%n;
		b = (rand())*(rand())%n;
		while(b==a)
			b = (rand())*(rand())%n;
		int cnt = 2;
		for (int i = 0; i < n; i++)
		{
			if (a == i || b == i)
				continue;
			if (isCollinear(v[a], v[b], v[i]))
				cnt++;
		}
		mx = max(mx, cnt);
		if (mx >= ceil(n*1.0*p) / 100)
			break;
	}
	if (mx >= ceil(n*1.0*p) / 100)
		cout << "possible\n";
	else cout << "impossible\n";
	pause();
	return 0;
}