#include <bits/stdc++.h>

using namespace std;

int minimumIdx(string &s)
{
    int i = 0, j = 1, k, n = s.length();
    while (i < n && j < n)
    {
        k = 0;
        while (k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        if (k == n) break;
        if (s[(i + k) % n] > s[(j + k) % n])
        {
            i = max(j, i + k + 1);
            j = i + 1;
        }
        else j += k + 1;
    }
    return i;
}

int main(int argc, char *argv[])
{
    string s = "axyxdeeaabmnnaaatkaapsaaaraq";
    int mi = minimumIdx(s);
    cout << mi << '\n';
    cout << s.substr(mi) << s.substr(0, mi) << endl;
    return 0;
}
