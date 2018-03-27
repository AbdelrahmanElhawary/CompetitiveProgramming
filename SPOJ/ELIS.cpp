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
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int n, x[11];
int solve(int last, int ind)
{
	if (ind == n + 2) return 0;
	int option1 = solve(last, ind + 1), option2 = 0;
	if (x[last] < x[ind])
		option2 = 1 + solve(ind, ind + 1);
	return(max(option1, option2));
}int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	cin >> n;
	x[0] = -1;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	cout << solve(0, 1) << endl;
	//system("pause");
	return 0;
}
