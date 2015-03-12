#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int64_t SumOfPrimesBelow(int64_t n)
{
    if (n < 3) return 0; // Crashing is bad.
    
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    int64_t sum = 2;
    
    for (int64_t i = 4; i < n; i += 2) isPrime[i] = false;
    
    for (int64_t i = 3; i < n; i += 2)
    {
        if (isPrime[i])
        {
            sum += i;
            
            for (int64_t j = i * i; j < n; j += i + i)
                isPrime[j] = false;
        }
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
