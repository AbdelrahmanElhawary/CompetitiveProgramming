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
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		int n,m; cin >> n>>m;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		queue<pair<int, int>>q;
		vector<int>dp(3601, -1);
		q.push({ 0,0 });
		dp[0] = 0;
		while (q.size())
		{
			int u = q.front().second;
			int d = q.front().first;
			q.pop();
			dp[u] = d;
			for (int i = 0; i < n; i++)
			{
				int x = v[i]+u;
				if (x < 0)x = 0; if (x > 3600)x = 3600;
				if (dp[x] == -1)
					q.push({ d + 1,x }), dp[x] = d + 1;
			}
		}
		for (int i = m; i <= 3600; i++)
		{
			if (dp[i] != -1)
			{
				cout << dp[i] << " "<<i - m << endl;
				break;
			}
		}
	}


	pause();
	return 0;
}