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
#include <assert.h>
#include<complex>
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
#define MAX 1000
int cnt[12];
int multiply(int x, int res[], int res_size) {
	int carry = 0;
	for (int i = 0; i<res_size; i++) {
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}
void factorial(int n)
{
	int res[MAX];
	res[0] = 1;
	int res_size = 1;
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);
	for (int i = res_size - 1; i >= 0; i--) {
		cnt[res[i]]++;
	}
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(3);
	int x;
	while (scanf("%d",&x)&&x)
	{
		memset(cnt, 0, sizeof cnt);
		factorial(x);
		printf("%d! --\n", x);
		for (int i = 0; i < 5; i++) {
			if (i) printf("    ");
			else printf("   ");
			printf("(%d)%5d", i, cnt[i]);
		}
		printf("\n");
		for (int i = 5; i < 10; i++) {
			if (i >5) printf("    ");
			else printf("   ");
			printf("(%d)%5d", i, cnt[i]);
		}
		printf("\n");
	}

	pause();
	return 0;
}