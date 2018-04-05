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
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
#define endl '\n'
#define mk make_pair
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m; bool f;
char arr[17][2];
int x2, y2; bool vis[17][2];
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
set<vector<int>>s;
bool check(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)return 0;
	return 1;
}
void solve(vector<int>v,int vis[])
{
	if (v.size() == n)
	{
		s.insert(v);
		return;
	}
	for (int i = 2; i <= n; i++)
	{
		if(v.size()<n-1)
		{
			if(check(v[v.size() - 1]+i)&&!vis[i])
			{
				v.push_back(i); vis[i] = 1;
				solve(v,vis);
				v.pop_back(); vis[i] = 0;
			}
		}
		else if (v.size() == n - 1)
		{
			if (check(v[v.size()-1]+i)&&check(v[0]+i) && !vis[i])
			{
				v.push_back(i); vis[i] = 1;
				solve(v, vis);
				v.pop_back(); vis[i] = 0;
			}
		}
	}
	
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int tt = 1;
	while (cin >> n)
	{
		vector<int>v;
		v.push_back(1);
		int vis[17]{0};
		vis[1] = 1;
		solve(v,vis);
		if (tt > 1)cout << endl;
		cout << "Case " << tt++ << ":\n";
		while (s.size())
		{
			v = *s.begin();
			for (int i = 0; i < v.size()-1; i++)
				cout << v[i] << " "; cout << v[v.size() - 1] << endl;
			s.erase(s.begin());
		}
	}
	
//	system("pause");
	return 0;
}