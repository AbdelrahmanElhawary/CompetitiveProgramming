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
vector<int>v;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cout << (char)(i%m + 'a'); cout << endl;
	
//	system("pause");
	return 0;
}