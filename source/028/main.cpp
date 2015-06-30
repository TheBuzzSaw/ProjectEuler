#include <iostream>
#include <sstream>
#include <cstdint>
using namespace std;

int64_t GetTotal(int64_t edgeSize)
{
    int64_t result = 1;
    int64_t n = 1;
    
    for (int64_t i = 2; i < edgeSize; i += 2)
    {
        for (int j = 0; j < 4; ++j)
        {
            result += (n += i);
        }
    }
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        stringstream ss;
        ss << argv[1];
        
        int64_t edgeSize;
        
        if (ss >> edgeSize)
            cout << "total: " << GetTotal(edgeSize) << endl;
    }    
        
    return 0;
}

