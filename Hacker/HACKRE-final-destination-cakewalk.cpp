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
		cout << fixed << setprecision(4);
	//	int t,tt=1; cin >> t;
		//while (t--) {
		string s; int x = 0, y = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'L')x--;
			if (s[i] == 'D')y--;
			if (s[i] == 'R')x++;
			if (s[i] == 'U')y++;
		}
		cout << x << " " << y << endl;
		
//		}
		//system("pause");
	return 0;
}