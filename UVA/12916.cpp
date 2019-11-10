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

int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	//freopen("input.txt", "r", stdin);
	int t; cin >> t;
	int tt = 1;
	while (t--)
	{
		string s; cin >> s;
		for(int i=1;i<=s.size();i++)
		{
			if (s.size() % i)continue;
			bool f = 1;
			for(int j=0;j+i<s.size();j++)
				if(s[j]!=s[j+i])
				{
					f = 0; break;
				}
			if (f) { cout << i << endl; break; }
		}
	}
	pause();
	return 0;

}