#include <iostream>
#include <cstdint>
using namespace std;

int64_t GetTotal(int64_t limit)
{
    int64_t total = 0;
    
    for (int64_t i = 1; i < limit; ++i)
    {
        if (!(i % 3) || !(i % 5))
            total += i;
    }
    
    return total;
}

int main(int argc, char** argv)
{
    cout << "Limit of 10: " << GetTotal(10) << endl;
    cout << "Limit of 1000: " << GetTotal(1000) << endl;
    return 0;
}