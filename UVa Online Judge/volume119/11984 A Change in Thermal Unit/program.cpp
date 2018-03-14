// A Change in Thermal Unit
// UVa ID: 11984
// Verdict: Accepted
// Submission Date: 2017-12-30
// UVa Run Time: 0.000s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases;
    double C, d;

    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cin >> C >> d;
        cout << "Case " << c << ": ";
        cout << fixed << setprecision(2) << (C + 5 * d / 9) << '\n';
    }

    return 0;
}
