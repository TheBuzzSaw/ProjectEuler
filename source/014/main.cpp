#include <iostream>
#include <sstream>
#include <cstdint>
using namespace std;

int64_t CollatzLength(int64_t start)
{
    int64_t result = 1;
    int64_t next = start;
    
    while (next > 1)
    {
        ++result;
        
        if (next & 1)
        {
            next = next * 3 + 1;
        }
        else
        {
            next >>= 1;
        }
    }
    
    return result;
}

void FindLongestCollatzLength(int64_t max)
{
    int64_t startOfLongestLength = 0;
    int64_t longestLength = 0;
    
    for (int64_t i = 1; i < max; ++i)
    {
        int64_t length = CollatzLength(i);
        
        if (length > longestLength)
        {
            longestLength = length;
            startOfLongestLength = i;
        }
    }
    
    cout
        << "longest length under "
        << max
        << " is "
        << longestLength
        << " which starts with "
        << startOfLongestLength
        << endl;
}

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        stringstream ss;
        ss << argv[i];
        
        int64_t max;
        
        if (ss >> max)
            FindLongestCollatzLength(max);
        else
            cerr << "invalid input: " << argv[i] << '\n';
    }
    
    return 0;
}
