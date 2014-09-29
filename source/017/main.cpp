#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

static const int DigitLengths[] = {
    4, // zero
    3, // one
    3, // two
    5, // three
    4, // four
    4, // five
    3, // six
    5, // seven
    5, // eight
    4, // nine
};

static const int TeenLengths[] = {
    3, // ten
    6, // eleven
    6, // twelve
    8, // thirteen
    8, // fourteen
    7, // fifteen
    7, // sixteen
    9, // seventeen
    8, // eighteen
    8, // nineteen
};

static const int TenLengths[] = {
    0,
    3, // ten
    6, // twenty
    6, // thirty
    5, // forty
    5, // fifty
    5, // sixty
    7, // seventy
    6, // eighty
    6, // ninety
};

static const int ScaleLengths[] = {
    0,
    8, // thousand
    7, // million
    7, // billion
    8, // trillion
    11, // quadrillion
};

static const int NegativeLength = 8; // "negative"
static const int HundredLength = 7; // "hundred"
static const int AndLength = 3; // "and";

int GetLengthOfText(int number)
{
    int result = 0;
    
    if (number == 0) return DigitLengths[0];
    
    if (number < 0)
    {
        result += NegativeLength;
        number = -number;
    }
    
    int scale = 0;
    for (int n = number; n > 0; n /= 1000)
    {
        int chunk = n % 1000;
        int lastTwo = chunk % 100;
        
        int hundred = chunk / 100;
        int ten = lastTwo / 10;
        int one = chunk % 10;
        
        if (hundred > 0)
        {
            result += DigitLengths[hundred] + HundredLength;
            
            if (lastTwo > 0)
                result += AndLength;
        }

        if (ten > 0)
        {
            if (ten == 1)
            {
                result += TeenLengths[one];
                one = 0;
            }
            else
            {
                result += TenLengths[ten];
            }
        }
        
        if (one > 0)
        {
            result += DigitLengths[one];
        }
        
        if (chunk > 0)
            result += ScaleLengths[scale];
        
        ++scale;
    }
    
    return result;
}

int GetLengthOfAllText(int limit)
{
    int result = 0;
    
    for (int i = 1; i <= limit; ++i)
        result += GetLengthOfText(i);
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            stringstream ss;
            ss << argv[i];
            
            int limit;
            
            if (ss >> limit && limit > 0)
            {
                cout
                    << "length of "
                    << limit
                    << ": "
                    << GetLengthOfText(limit)
                    << "\nlength of all words from 1 to "
                    << limit
                    << ": "
                    << GetLengthOfAllText(limit)
                    << endl;
            }
            else
            {
                cerr << "invalid: " << argv[i] << '\n';
            }
        }
    }
    else
    {
        cerr << "requires limit >= 1\n";
    }

    return 0;
}
