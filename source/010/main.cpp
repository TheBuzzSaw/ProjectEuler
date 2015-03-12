#include <iostream>
#include <vector>
using namespace std;

int64_t SumOfPrimesBelow(int64_t n)
{
    vector<int64_t> primes{2};
    int64_t sum = 0;
    
    if (n > 2)
    {
        sum = 2;
        
        for (int64_t i = 3; i < n; i += 2)
        {
            bool isPrime = true;
            
            for (auto j : primes)
            {
                int64_t quotient = i / j;
                
                if (i == quotient * j)
                {
                    isPrime = false;
                    break;
                }
                else if (j > quotient)
                {
                    break;
                }
            }
            
            if (isPrime)
            {
                primes.push_back(i);
                sum += i;
            }
        }
    }
    
    return sum;
}

int main(int argc, char** argv)
{
    cout << "Sum of primes below 10: "
        << SumOfPrimesBelow(10) << endl;
        
    cout << "Sum of primes below 2,000,000: "
        << SumOfPrimesBelow(2000000) << endl;

    return 0;
}
