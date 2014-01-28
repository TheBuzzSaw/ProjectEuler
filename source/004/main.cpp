#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cmath>
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
    int64_t highest = 0;

    for (int64_t i = 100; i < 1000; ++i)
    {
        for (int64_t j = 100; j < 1000; ++j)
        {
            int64_t product = i * j;
            
            if (product > highest && IsPalindrome(product))
                highest = product;
        }
    }
    
    cout << highest << endl;
    
    return 0;
}