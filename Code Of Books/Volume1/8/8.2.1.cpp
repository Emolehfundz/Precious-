#include <bits/stdc++.h>

using namespace std;

int gcd1(int a, int b)
{
    if (a < b) swap(a, b);
    return b ? gcd1(b, a % b) : a;
}

int gcd2(int a, int b)
{
    if (a < b) swap(a, b);
    int t;
    while (b != 0) t = a, a = b, b = t % b;
    return a;
}

int gcd3(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (a != b) if (a > b) a -= b; else b -= a;
    return a;
}

int main(int argc, char *argv[])
{
    int a, b;
    
    while (cin >> a >> b)
    {
        cout << gcd1(a, b) << '\n';
        cout << __gcd(a, b) << '\n';
    }
}
