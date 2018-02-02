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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m, x;
string s[51];
vector<pair<int,int>>ar[26];
vector<pair<int, int>>v;
int vis[26];
bool check(char ch)
{
	if (vis[ch - 'A'] == 1)return 0;
	if (vis[ch - 'A'] == -1)return 1;
	double x1, x2, y1, y2;
	for (int i = 0; i < ar[ch - 'A'].size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			x1 = ar[ch - 'A'][i].first; y1 = ar[ch - 'A'][i].second;
			x2 = v[j].first; y2 = v[j].second;
			double dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
			if (dis <= x) { vis[ch - 'A'] = 1; return 0; }
		}
	}
	vis[ch - 'A'] = -1;
	return 1;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	 cin >> n >> m >> x;
	 for (int i = 0; i < n; i++)
	 {
		 cin >> s[i];
		 for (int j = 0; j < m; j++)
			 if (s[i][j] == 'S')v.push_back(make_pair(i, j));
			 else ar[s[i][j] - 'a'].push_back(make_pair(i,j));
	 }
	 int t; cin >> t;
	 string str; cin >> str;
	 bool f = 1; int ans = 0;
	 for (int i = 0; i < t; i++)
	 {
		 if (str[i] >= 'A'&&str[i] <= 'Z')
		 {
			 if (v.size() == 0) { f = 0; break; }
			 if (ar[str[i] - 'A'].size() == 0) { f = 0; break; }
			 if (check(str[i])) ans++;
		 }
		 if (str[i] >= 'a'&&str[i] <= 'z')
			 if (ar[str[i] - 'a'].size() == 0) { f = 0; break; }
	 }
	 if (f)cout << ans << endl;
	 else cout << -1 << endl;
	//system("pause");
	return 0;
}