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
int n, m,par[102],rnk[102];
vector<string>str;
int arr[502][502];
int calc(string s1, string s2)
{
	int ans = 0;
	for (int i = 0; i < 4; i++)
		ans += min(abs(s1[i] - s2[i]), 10 - abs(s1[i] - s2[i]));
	return ans;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(2);
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		str.clear();
		str.resize(n + 1);
		str[0] = "0000";
		for (int i = 1; i <= n; i++)
		{
			cin >> str[i];
			for (int j = 0; j < i; j++)
				arr[j][i] = arr[i][j] = calc(str[j], str[i]);
		}
		vector<int>ansy(n + 1, 1e9);
		int ind = 1;
		for (int i = 1; i <= n; i++)
			if (arr[0][i] < arr[0][ind])
				ind = i;
		set<pair<int, int>>s;
		ansy[0] = arr[0][ind];
		s.insert({ ansy[0],ind });
		vector<bool>vis(n + 1);
		int ans = 0;
		while (s.size())
		{
			pair<int,int> cur = *s.begin();
			s.erase(s.begin());
			vis[cur.second] = 1;
			ans += cur.first;
			for (int i = 1; i <= n; i++)
			{
				if (vis[i])continue;
				if (ansy[i] <= arr[cur.second][i])continue;
				s.erase({ ansy[i],i });
				ansy[i] = arr[cur.second][i];
				s.insert({ ansy[i], i });
			}
		}
		cout << ans << endl;

	}
	pause();
	return 0;
}