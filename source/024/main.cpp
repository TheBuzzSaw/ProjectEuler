#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Analyze(string values)
{
    sort(values.begin(), values.end());
    
    cout << values << endl;
    
    for (int i = 1; i < 1000000; ++i)
        next_permutation(values.begin(), values.end());
    
    cout << values << endl;
}

int main(int argc, char** argv)
{
    Analyze("9876543210");
    return 0;
}