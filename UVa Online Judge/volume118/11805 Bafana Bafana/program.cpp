// Bafana Bafana
// UVa ID: 11805
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

    int N, K, P, cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cout << "Case " << c << ": ";
        cin >> N >> K >> P;
        if ((K + P) % N == 0) cout << N << '\n';
        else cout << (K + P) % N << '\n';
    }

    return 0;
}
