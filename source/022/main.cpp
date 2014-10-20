#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int64_t GetScore(istream& stream)
{
    vector<string> names;
    string name;
    int64_t result = 0;
    bool isInField = false;
    char c;
    
    while (stream.read(&c, 1))
    {
        if (c == '"')
        {
            if (isInField)
            {
                names.push_back(name);
                name.clear();
            }
        
            isInField = !isInField;
        }
        else if (isInField)
        {
            name += c;
        }
    }
    
    sort(names.begin(), names.end());
    
    //for (const auto& i : names) cout << i << '\n';
    
    int64_t n = 0;
    for (const auto& i : names)
    {
        int64_t score = 0;
        
        for (const char j : i)
            score += j - 'A' + 1;
        
        score *= ++n;
        result += score;
    }
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            ifstream fin(argv[i], ifstream::binary);
            
            if (fin)
            {
                cout
                    << "name score for "
                    << argv[i]
                    << " == "
                    << GetScore(fin)
                    << endl;
                
                fin.close();
            }
            else
            {
                cerr << "invalid: " << argv[i] << '\n';
            }
        }
    }
    else
    {
        cerr << "requires file inputs\n";
    }
    
    return 0;
}
