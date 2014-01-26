#include <iostream>
#include <cstdint>
using namespace std;

int64_t GetTotal(int64_t limit)
{
    int64_t total = 0;
    
    int64_t a = 0;
    int64_t b = 1;
    
    while (1)
    {
        int64_t c = a + b;
        a = b;
        b = c;
        
        if (a < limit)
        {
            bool isOdd = a & 1;
            
            if (!isOdd)
                total += a;
        }
        else
        {
            break;
        }
    }
    
    return total;
}

int main(int argc, char** argv)
{
    cout << GetTotal(4000000) << endl;
    return 0;
}