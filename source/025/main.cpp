#include <iostream>
#include <vector>
using namespace std;

void Add(vector<char>& a, const vector<char>& b)
{
    for (size_t i = 0; i < b.size(); ++i)
    {
        if (i < a.size())
        {
            a[i] += b[i];
            
            size_t j = i;
            
            while (a[j] > 9)
            {
                a[j] -= 10;
                
                if (++j < a.size())
                    a[j] += 1;
                else
                    a.push_back(1);
            }
        }
        else
        {
            a.push_back(b[i]);
        }
    }
}

ostream& Write(ostream& stream, const vector<char>& number)
{
    for (auto i = number.crbegin(); i != number.crend(); ++i)
        stream << char('0' + *i);
    
    return stream;
}

int main(int argc, char** argv)
{
    vector<char> a{1};
    vector<char> b{1};
    vector<char> c;
    
    a.reserve(1000);
    b.reserve(1000);
    c.reserve(1000);
    
    size_t n = 2;
    
    while (b.size() < 1000)
    {
        c = b;
        Add(c, a);
        swap(a, b);
        swap(b, c);
        ++n;
    }
    
    cout << "First term to have 1000 digits: " << n << "\n\nTerm: ";
    
    Write(cout, b) << endl;
    
    return 0;
}