#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
using namespace std;

int64_t SumDigits(int factorial)
{
    if (factorial < 2) return 1;
    
    vector<char> total { 1 };
    
    for (int i = 2; i <= factorial; ++i)
    {
        int carry = 0;
        
        for (char& c : total)
        {
            int n = (int)c * i + carry;
            carry = n / 10;
            c = n - carry * 10;
        }
        
        while (carry > 0)
        {
            total.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    int64_t result = 0;
    
    for (auto i : total) result += i;
    
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
            
            int64_t factorial;
            
            if (ss >> factorial)
            {
                cout
                    << "sum of digits of "
                    << factorial
                    << "! == "
                    << SumDigits(factorial)
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
        cerr << "requires factorial\n";
    }
    
    return 0;
}
