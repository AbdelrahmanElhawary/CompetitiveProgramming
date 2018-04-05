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
void pause(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
vector<int>v[1000001];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int n, m;
	while (cin>>n>>m)
	{
		
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			v[x].push_back(i + 1);
		}
		for (int i = 0; i < m; i++)
		{
			int k, va; 
			cin >> k >> va;
			if (v[va].size() < k)cout << 0 << endl;
			else cout << v[va][k-1] << endl;
		}
		for (auto& v : v)
			v.clear();
	}
	pause();
	return 0;
}