#include <bits/stdc++.h>

using namespace std;

void printCycle(int numerator, int denominator)
{
    cout << numerator << '/' << denominator << '=';
    cout << (numerator / denominator) << '.';
    numerator %= denominator;

    if (numerator == 0) { cout << "0\n"; return; }

    vector<int> digits(denominator + 1), position(denominator + 1);
    vector<bool> appeared(denominator + 1);

    fill(appeared.begin(), appeared.end(), false);

    int index = 0;
    while (!appeared[numerator] && numerator > 0)
    {
        appeared[numerator] = true;
        digits[index] = 10 * numerator / denominator;
        position[numerator] = index++;
        numerator = 10 * numerator % denominator;
    }

    int loopStart = 0;
    if (numerator > 0)
    {
        loopStart = position[numerator];
        for (int i = 0; i < position[numerator]; i++) cout << digits[i];
        cout << '(';
    }
    for (int i = loopStart; i < index; i++) cout << digits[i];
    if (numerator > 0) cout << ')';
    cout << '\n';
}

int main(int argc, char *argv[])
{
    int cases, numerator, denominator;

    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cin >> numerator >> denominator;
        printCycle(numerator, denominator);
    }

    return 0;
}
