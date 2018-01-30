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
bool ch[101];
int main() {
		fast_in_out();
	//	cout << fixed << setprecision(4);
		int n, p, q; cin >> n >> p;
		for (int i = 0; i < p; i++)
		{
			int x; cin >> x; ch[x] = 1;
		}
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int x; cin >> x; ch[x] = 1;
		}
		for (int i = 1; i <= n; i++)
			if (!ch[i]){cout << "Oh, my keyboard!\n";return 0;}
		cout << "I become the guy.\n";
		
	//	system("pause");
	return 0;
}