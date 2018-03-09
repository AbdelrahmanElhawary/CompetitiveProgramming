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
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
multiset<int>ms;
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n;
	while (cin >> n && n)
	{
		int x,y;
		for(int i=0;i<n;i++)
		{
			cin >> x; ms.insert(x);
		}
		ll sum = 0;
		while (ms.size()>1)
		{
			x = *ms.begin();
			ms.erase(ms.begin());
			y = *ms.begin();
			ms.erase(ms.begin());
			x += y;
			sum += x;
			ms.insert(x);
		}
		ms.clear();
		cout << sum << endl;
	}
	
	//system("pause");
	return 0;
}
