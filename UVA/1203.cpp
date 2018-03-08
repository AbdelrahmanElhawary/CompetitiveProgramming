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
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	string str;
	set<pair<pair<int, int>, int >> s;
	pair<pair<int, int>, int > temp;
	while (cin >> str)
	{
		if (str == "#")break;
		int x, y; cin >> x >> y;
		temp.first.first = y;
		temp.first.second = x;
		temp.second = y;
		s.insert(temp);
	}
	int n; cin >> n;
	while (n--)
	{
		temp = *s.begin();
		s.erase(s.begin());
		cout << temp.first.second << endl;
		temp.first.first += temp.second;
		s.insert(temp);
	}
	
	//system("pause");
	return 0;
}
