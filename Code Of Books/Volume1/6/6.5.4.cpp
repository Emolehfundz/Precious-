#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

pair<long long, long long> getFraction(string fraction, int j)
{
    long long numerator, denominator;

    size_t dot = fraction.find('.');
    if (dot != fraction.npos) fraction = fraction.substr(dot + 1);
    
    if (j == 0)
    {
        numerator = stoll(fraction);
        denominator = pow(10, fraction.length());
    }
    else
    {
        int k = fraction.length() - j;
        string preRepeated = fraction.substr(0, k);
        if (preRepeated.length() == 0) preRepeated = "0";
        
        numerator = stoll(fraction) - stoll(preRepeated);
        denominator = pow(10, k + j) - pow(10, k);
    }
    
    long long g = gcd(numerator, denominator);
    if (g > 1) numerator /= g, denominator /= g;
    return make_pair(numerator / g, denominator / g);
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int j, cases = 0;
    string fraction;
    
    while (cin >> j, j >= 0)
    {
        cin >> fraction;

        pair<long long, long long> r = getFraction(fraction, j);

        cout << "Case " << ++cases << ": " << r.first << "/" << r.second << '\n';
    }
    
	return 0;
}
