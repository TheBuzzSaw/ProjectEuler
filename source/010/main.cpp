#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int64_t SumOfPrimesBelow(int64_t n)
{
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (size_t i = 2; i < (size_t)n; ++i)
    {
        if (!isPrime[i]) continue;
        
        for (size_t j = i + i; j < (size_t)n; j += i)
            isPrime[j] = false;
    }
    
    int64_t sum = 0;
    
    for (int64_t i = 0; i < n; ++i)
    {
        if (isPrime[i]) sum += i;
    }
    
    return sum;
}

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        stringstream ss;
        ss << argv[i];
        
        int64_t n;
        
        if (ss >> n && n > 0)
        {
            cout << "Sum of primes below " << n << ": "
                << SumOfPrimesBelow(n) << endl;
        }
        else
        {
            cout << "invalid input: " << argv[i] << endl;
        }
    }
    
    return 0;
}
