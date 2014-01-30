#include <iostream>
#include <cstdio>
#include <cstdint>
#include <unordered_map>
using namespace std;

int64_t FindSmallestMultiple(int64_t n)
{
    unordered_map<int64_t, int64_t> allPrimeFactors;
    
    for (int64_t i = 2; i <= n; ++i)
    {
        unordered_map<int64_t, int64_t> primeFactors;
        
        int64_t remainder = i;
        for (int64_t j = 2; j <= remainder; ++j)
        {
            if ((remainder % j) == 0)
            {
                ++primeFactors[j];
                remainder /= j;
                j = 1;
            }
        }
        
        for (auto& pair : primeFactors)
        {
            auto key = pair.first;
            allPrimeFactors[key] = max<int64_t>(allPrimeFactors[key], pair.second);
        }
    }
    
    int64_t answer = 1;
    
    for (auto& pair : allPrimeFactors)
    {
        int64_t count = pair.second;
        
        for (int64_t i = 0; i < count; ++i)
            answer *= pair.first;
    }
    
    return answer;
}

int main(int argc, char** argv)
{
    cout << "Smallest Multiple of 10: " << FindSmallestMultiple(10) << endl;
    cout << "Smallest Multiple of 20: " << FindSmallestMultiple(20) << endl;
    
    return 0;
}
