// Divisors
// UVa ID: 294
// Verdict: Accepted
// Submission Date: 2016-05-09
// UVa Run Time: 0.020s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int prime[31263] = {0};
vector < int > primes;
int N, L, U;

void getPrime()
{
    for (int i = 2; i < 31263; i++)
        if (prime[i] == 0)
        {
            for (int j = 2 * i; j < 31263; j += i)
                prime[j] = 1;
        }
        
    for (int i = 2; i < 31263; i++)
        if (prime[i] == 0)
            primes.push_back(i);
}

int getCountOfDivisors(int n)
{
    if (n == 1)
        return 1;
    
    if (n < 31263 && prime[n] == 0)
        return 2;
        
    set < int > numbers, divisors;
    numbers.insert(1);
    for (int i = 0; i < primes.size(); i++)
    {
        while (n % primes[i] == 0)
        {
            n /= primes[i];
            
            if (numbers.size())
            {
                for (auto it = numbers.begin(); it != numbers.end(); it++)
                {
                    divisors.insert(*it);
                    divisors.insert(*it * primes[i]);
                }
                numbers.clear();
            }
            else
            {
                for (auto it = divisors.begin(); it != divisors.end(); it++)
                {
                    numbers.insert(*it);
                    numbers.insert(*it * primes[i]);
                }
                divisors.clear();
            }
        }
        
        if (n == 1)
            break;
    }
    
    if (n > 1)
        return 2;
    
    return max(numbers.size(), divisors.size());
}

void getDivisors()
{
    int minN = L, maxNumber = 0, count;
    
    for (int i = L; i <= U; i++)
        if ((count = getCountOfDivisors(i)) > maxNumber)
        {
            maxNumber = count;
            minN = i;
        }
    
    cout << "Between " << L << " and ";
    cout << U << ", " << minN << " has a maximum of ";
    cout << maxNumber << " divisors.\n";
}

int main(int argc, char *argv[])
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    getPrime();
    
    cin >> N;
    while (N--)
    {
        cin >> L >> U;
        getDivisors();
    }
    
	return 0;
}
