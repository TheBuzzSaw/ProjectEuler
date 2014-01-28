#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

bool IsSymmetric(const char* text, int length)
{
    const char* a = text - 1;
    const char* b = text + length;
    
    while (++a < --b) if (*a != *b) return false;
    
    return true;
}

bool IsPalindrome(int64_t n)
{
    // Big enough to hold the biggest number.
    char text[24];
    
    int length = sprintf(text, "%lld", n);
    
    return IsSymmetric(text, length);
}

int main(int argc, char** argv)
{
    const int64_t Limit = 1000;
    int64_t highest = 0;
    int64_t a = 0;
    int64_t b = 0;

    for (int64_t i = 100; i < Limit; ++i)
    {
        for (int64_t j = i; j < Limit; ++j)
        {
            int64_t product = i * j;
            
            if (product > highest && IsPalindrome(product))
            {
                highest = product;
                a = i;
                b = j;
            }
        }
    }
    
    cout << a << " * " << b << " = " << highest << endl;
    
    return 0;
}
