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
		int t,tt=1; cin >> t;
		while (t--) {
			ll x[3];
			cin >> x[0] >> x[1] >> x[2];
			sort(x, x + 3);
			cout <<"Case "<<tt++<<": "<< x[1] << endl;
			
		}
		//system("pause");
	return 0;
}