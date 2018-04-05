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
int arr[1002];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--)
	{
		int n, mny = 1e9; cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin.ignore();
			getline(cin, s); int cnt = 1;
			for (int j = 0; j < s.size(); j++)
			{
				if (s[j] == ' ')cnt++;
			}
			arr[i] = cnt;
			mny = min(cnt, mny);
		}
		bool f = 0;
		for (int i = 0; i < n; i++)
		{
			if (f&&mny == arr[i])cout << " ";
			if (mny == arr[i]) { cout << i + 1; f = 1; }
		}cout << endl;
		/*for (auto& v : adj)
			v.clear();*/
	}
	pause();
	return 0;
}