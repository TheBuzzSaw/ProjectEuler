#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
using namespace std;

struct Point
{
    int64_t x;
    int64_t y;
};

ostream& operator<<(ostream& stream, const Point& point)
{
    return stream << '(' << point.x << ", " << point.y << ')';
}

int GetQuadrant(const Point& p)
{
    if (p.y <= 0 && p.x < 0)
        return 1;
    else if (p.y < 0 && p.x >= 0)
        return 2;
    else if (p.y >= 0 && p.x > 0)
        return 3;
    
    return 4; // p.y > 0 && p.x <= 0
}

int64_t CrossZ(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}
bool operator==(const Point& a, const Point& b)
{
    return GetQuadrant(a) == GetQuadrant(b) && CrossZ(a, b) == 0;
}

bool operator<(const Point& a, const Point& b)
{
    auto qa = GetQuadrant(a);
    auto qb = GetQuadrant(b);
    return qa < qb || (qa == qb && CrossZ(a, b) > 0);
}

bool operator<=(const Point& a, const Point& b)
{
    return a < b || a == b;
}

int64_t FindC(int64_t count)
{
    int64_t x = 1;
    int64_t y = 1;
    
    cout << "[" << count << "] Generating...";
    cout.flush();
    
    int64_t originCount = 0;
    vector<Point> points;
    points.reserve(count);
    
    for (int i = 0; i < count; ++i)
    {
        x = (x * 1248) % 32323;
        y = (y * 8421) % 30103;
        
        Point p = { x - 16161, y - 15051 };
        
        if (p.x == 0 && p.y == 0)
            ++originCount;
        else
            points.push_back(p);
    }
    
    if (originCount > 0)
        cout << originCount << " origins\n";
    
    cout << "Sorting...";
    cout.flush();
    
    sort(points.begin(), points.end());
    
    int64_t result = 0;
    
    for (auto i = points.begin();
        i != points.end() && GetQuadrant(*i) < 3;
        ++i)
    {
        Point low = { -i->x, -i->y };
        
        for (auto j = i + 1;
            j != points.end() && *j <= low;
            ++j)
        {
            auto k = j + 1;
            while (k != points.end() && *k < low) ++k;
            
            if (GetQuadrant(*j) < 3)
            {            
                Point high = { -j->x, -j->y };
                while (k != points.end() && *k <= high) ++result, ++k;
            }
            else
            {
                result += distance(k, points.end());
            }
        }
    }
	
    return result;
}

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int64_t n;
        stringstream ss;
        ss << argv[i];
        
        if (ss >> n && n > 0)
        {
            auto result = FindC(n);
            cout << "Result: " << result << endl;
        }
        else
        {
            cerr << "invalid input: " << argv[i] << '\n';
        }
    }
    
    return 0;
}
