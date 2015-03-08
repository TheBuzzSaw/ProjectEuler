#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rational
{
    int a;
    int b;
};

constexpr bool operator==(const Rational& a, const Rational& b)
{
    return a.a == b.a && a.b == b.b;
}

ostream& operator<<(ostream& stream, const Rational& rational)
{
    return stream << rational.a << '/' << rational.b;
}

int main(int argc, char** argv)
{
    vector<Rational> digits;
    size_t numberWithLongestRepeat = 0;
    size_t longestRepeat = 0;
    
    for (int i = 2; i < 1000; ++i)
    {
        int remainder = 1;
        
        digits.clear();
        auto repeat = digits.end();
        
        while (remainder > 0)
        {
            int next = remainder * 10;
            Rational digit = { next / i, next };
            remainder = next - digit.a * i;
            
            repeat = find(
                digits.begin(),
                digits.end(),
                digit);
            
            if (repeat != digits.end())
            {
                break;
            }
            else
            {
                digits.push_back(digit);
                repeat = digits.end();
            }
        }
        
        cout << "1/" << i << " : 0.";
        
        for (auto j = digits.begin(); j != repeat; ++j)
            cout << j->a;
        
        if (repeat != digits.end())
        {
            size_t repeatLength = 0;
            cout << '(';
            
            for (auto j = repeat; j != digits.end(); ++j)
            {
                cout << j->a;
                ++repeatLength;
            }
            
            cout << ')';
            
            if (repeatLength > longestRepeat)
            {
                longestRepeat = repeatLength;
                numberWithLongestRepeat = i;
            }
        }
        
        cout << '\n';
    }
    
    cout << "Answer is 1/" << numberWithLongestRepeat << endl;
    
    return 0;
}