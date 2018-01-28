#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include <utility>
#include<set>
#include<string.h>
#include <deque>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
		fast_in_out();
		//cout << fixed << setprecision(0);
		int a, b, ans = 0; cin >> a >> b;
		for (int i = 0; i < a; i++)
		{
			int x; cin >> x;
			if (x <= b)ans++;
			else ans += 2;
		}
		cout << ans << endl;


//	system("pause");
	return 0;
}