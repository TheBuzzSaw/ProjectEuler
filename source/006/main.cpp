#include <iostream>
#include <cstdint>
using namespace std;

int64_t GetDifference(int64_t n)
{
    int64_t sum = 0;
    int64_t sumOfSquares = 0;
    
    for (int64_t i = 1; i <= n; ++i)
    {
        sum += i;
        sumOfSquares += i * i;
    }
    
    return sum * sum - sumOfSquares;
}

int main(int argc, char** argv)
{
    cout << "10 : " << GetDifference(10) << endl;
    cout << "100 : " << GetDifference(100) << endl;
    
    return 0;
}
