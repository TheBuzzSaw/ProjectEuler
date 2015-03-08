#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int64_t SumOfProperDivisors(int64_t n)
{
    int64_t result = 1;
    int64_t test = 2;
    
    while (true)
    {
        int64_t quotient = n / test;
        
        if (quotient < 2)
            return result;
        
        if (quotient * test == n)
            result += test;
        
        ++test;
    }
}

bool IsAbundant(int64_t n)
{
    return n < SumOfProperDivisors(n);
}

void FindSum()
{
    vector<int64_t> abundantNumbers;
    
    for (int64_t i = 2; i <= 28123; ++i)
    {
        if (IsAbundant(i))
            abundantNumbers.push_back(i);
    }
    
    cout << "Found " << abundantNumbers.size() << " abundant numbers." << endl;
    
    int64_t sum = 0;
    
    for (int64_t i = 0; i <= 28123; ++i)
    {
        sum += i;
        
        for (auto j = abundantNumbers.begin();
            j != abundantNumbers.end();
            ++j)
        {
            if (binary_search(j, abundantNumbers.end(), i - *j))
            {
                sum -= i;
                break;
            }
        }
    }
    
    cout << "Sum: " << sum << endl;
}

int main(int argc, char** argv)
{
    FindSum();
    
    for (int i = 1; i < argc; ++i)
    {
        stringstream ss;
        ss << argv[i];
        int64_t n;
        
        if (ss >> n && n > 0)
            cout << n << " : " << SumOfProperDivisors(n) << endl;
        else
            cout << "invalid input: " << argv[i] << endl;
    }
    
    return 0;
}