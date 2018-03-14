// Back to Intermediate Math
// UVa ID: 10773
// Verdict: Accepted
// Submission Date: 2018-02-25
// UVa Run Time: 0.000s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases;
    double d, v, u;

    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cout << "Case " << c << ": ";
        cin >> d >> v >> u;
        if (v >= u || fabs(v) < 1e-7) cout << "can't determine\n";
        else
        {
            double time1 = d / u;
            double time2 = d / sqrt(u * u - v * v);
            cout << fixed << setprecision(3) << fabs(time1 - time2) << '\n';
        }
    }

    return 0;
}
