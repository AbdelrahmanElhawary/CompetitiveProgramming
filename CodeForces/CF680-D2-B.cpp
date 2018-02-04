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
bool ar[101];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n, a, ans = 0; cin >> n >> a;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	if (ar[a])ans++;
	for (int i = 1; i <= n; i++)
	{
		if (a + i > n&&a - i <= 0)break;
		if (a + i > n&&ar[a - i])ans++;
		else
			if (a - i <= 0 && ar[a + i])ans++;
			else
				if (ar[a - i] && ar[a + i])ans += 2;
	}
	cout << ans << endl;
	//system("pause");
		return 0;
}