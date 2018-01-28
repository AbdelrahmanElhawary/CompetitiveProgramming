#includeiostream
#includealgorithm
#includestring
#includecmath
#includeiomanip
#includevector
#include utility
#includeset
#includestring.h
#include deque
#define ll long long
using namespace std;
void fast_in_out() {
	stdios_basesync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
		fast_in_out();
		cout  fixed  setprecision(0);
		int a, b, n; cin  a  bn;
		for (int i =1; i = n; i++)
		{
			bool f1 = 0, f2 = 0;
			if (i%a == 0)f1 = 1;
			if (i%b == 0)f2 = 1;
			if (f1&&f2)cout  FizzBuzzn;
			else if (f1)cout  Fizzn;
			else if (f2)cout  Buzzn;
			else cout  i  endl;
		}
		system(pause);
	return 0;
}