#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int maxDigit(int n)
{
	int d = log10(n) + 1;
	int mx = 0;
	while (n)
	{
		if (n % 10 > mx)
			mx = n % 10;
		n /= 10;
	}
	return mx;
}
int step = 0;
int dp(int n)
{
	if (n == 0)
		return 0;
	else
	{
		step++;
		dp(n - maxDigit(n));
	}
	return step;
}
int main()
{
	int n;
	cin >> n;
	cout << dp(n) << '\n';
	return 0;
}