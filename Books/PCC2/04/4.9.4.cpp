#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    string line = "bdfejgihca";
    
    nth_element(line.begin(), line.begin() + 5, line.end());
    cout << line << endl;
    
    return 0;
}
