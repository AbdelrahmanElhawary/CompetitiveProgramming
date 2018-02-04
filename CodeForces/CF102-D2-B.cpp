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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int get(int sum)
{
	int c = 0;
	while (sum)
	{
		c += sum % 10;
		sum /= 10;
	}
	return c;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	string s; cin >> s;
	int sum = 0,ans=1;
	if (s.size() == 1) { cout << 0 << endl; return 0; }
	for (int i = 0; i < s.size(); i++)
		sum += s[i] - '0';
	while (sum >= 10)
	{
		ans++;
		sum = get(sum);
	}
	cout << ans << endl;
	//system("pause");
		return 0;
}