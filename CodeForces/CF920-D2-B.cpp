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
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		vector<int>v;
		int n; cin >> n;
		for (int i = 0,cnt=0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			int ocnt = cnt;
			cnt =max(x,cnt+1); 
			if (cnt <= y)v.push_back(cnt);
			else { v.push_back(0); cnt = ocnt; }
		}
		for (int i = 0; i < v.size() - 1; i++)
			cout << v[i] << " "; cout << v[v.size() - 1] << endl;
	}
	
	//system("pause");
		return 0;
}