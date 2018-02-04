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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
vector<int>v;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n, k,ans=0; cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		if (y == 0)ans += x;
		else v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i > -1; i--,k--)
		if(k>0)ans += v[i]; else ans-=v[i];
	cout << ans << endl;
	
//	system("pause");
		return 0;
}