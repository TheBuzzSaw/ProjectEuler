#include <iostream>
#include <cstdint>
using namespace std;

int main(int argc, char** argv)
{
    const int64_t Sum = 1000;
    int64_t product = 0;
    
    for (int64_t a = 1; product == 0 && a < Sum; ++a)
    {
        int64_t max = (Sum - a) / 2 + a;
        
        for (int64_t b = a + 1; product == 0 && b < max; ++b)
        {
            int64_t c = Sum - b - a;
            int64_t left = a * a + b * b;
            int64_t right = c * c;
            
            if (left == right) product = a * b * c;
        }
    }
    
    cout << product << endl;

    return 0;
}
