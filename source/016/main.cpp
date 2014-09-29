#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

int64_t SumDigits(int64_t powerOfTwo)
{
    int64_t result = 0;
    
    vector<char> total { 2 };
    
    for (int64_t i = 1; i < powerOfTwo; ++i)
    {
        char carry = 0;
        
        for (char& c : total)
        {
            char n = c * 2 + carry;
            carry = n / 10;
            c = n - carry * 10;
        }
        
        if (carry > 0)
            total.push_back(carry);
    }
    
    for (auto i : total)
        result += i;
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            stringstream ss;
            ss << argv[i];
            
            int64_t powerOfTwo;
            
            if (ss >> powerOfTwo && powerOfTwo > 0)
            {
                cout
                    << "sum of digits of 2^"
                    << powerOfTwo
                    << " == "
                    << SumDigits(powerOfTwo)
                    << endl;
            }
            else
            {
                cerr << "invalid: " << argv[i] << '\n';
            }
        }
    }
    else
    {
        cerr << "requires power of 2\n";
    }

    return 0;
}
