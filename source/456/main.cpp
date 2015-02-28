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

Point RotateCW(const Point& point)
{
    return { point.y, -point.x };
}

Point RotateCCW(const Point& point)
{
    return { -point.y, point.x };
}

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

bool operator>(const Point& a, const Point& b)
{
    auto qa = GetQuadrant(a);
    auto qb = GetQuadrant(b);
    return qa > qb || (qa == qb && CrossZ(a, b) < 0);
}

bool operator<=(const Point& a, const Point& b)
{
    return a < b || a == b;
}

bool operator>=(const Point& a, const Point& b)
{
    return a > b || a == b;
}

struct Range
{
    vector<Point>::const_iterator low;
    vector<Point>::const_iterator high;
};

Range FindPoints(
    const vector<Point>& points,
    const Point& low,
    const Point& high)
{
    Range result;
    
    result.low = lower_bound(
        points.begin(),
        points.end(),
        low);
    
    if (low < high)
    {
        result.high = upper_bound(result.low, points.end(), high);
    }
    else
    {
        result.high = upper_bound(points.begin(), result.low, high);
    }
    
    return result;
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
    
    ofstream fout("dump.txt", ofstream::binary);
    fout << "sorted points --";
    for (const auto& point : points) fout << ' ' << point;
    fout << '\n';
    
    for (size_t i = 1; i < points.size(); ++i)
    {
        if (points[i - 1] > points[i] || points[i] < points[i - 1])
            cerr << "BLAM";
    }
    
    cout << "Counting...";
    cout.flush();
    
    int64_t result = 0;
    
    auto countPoints = [&](const Range& range)
    {
        if (range.low < range.high)
            return distance(range.low, range.high);
        
        return distance(range.low, points.cend()) +
            distance(points.cbegin(), range.high);
    };
    
    int logLimit = 1000;
    
    for (auto i = points.begin(); i != points.end(); ++i)
    {
        Point boundaries[3];
        boundaries[0] = RotateCCW(*i);
        boundaries[1] = RotateCCW(boundaries[0]);
        boundaries[2] = RotateCCW(boundaries[1]);
        
        auto a = FindPoints(points, boundaries[0], boundaries[1]);
        auto b = FindPoints(points, boundaries[1], boundaries[2]);
        auto ca = countPoints(a);
        auto cb = countPoints(b);
        
        result += ca * cb;
        
        if (ca > 0 && cb > 0)
        {
            for (auto j = a.low; j != a.high; ++j)
            {
                if (j == points.cend()) j = points.cbegin();
                if (j == a.high) break;
                
                for (auto k = b.low; k != b.high; ++k)
                {
                    if (k == points.cend()) k = points.cbegin();
                    if (k == b.high) break;
                    
                    fout << *i << ' ' << *j << ' ' << *k << '\n';
                    
                    fout << distance(points.begin(), i)
                        << ' ' << distance(points.cbegin(), j)
                        << ' ' << distance(points.cbegin(), k)
                        << '\n';
                    
                    if (--logLimit < 0)
                    {
                        fout << "BLAM\n";
                        fout.close();
                        return 0;
                    }
                }
            }
        }
    }
    
    fout.close();
    
    return result;
}

void TestRotate()
{
    Point point = { 1, 9 };
    for (int i = 0; i < 4; ++i)
    {
        point = RotateCW(point);
        cout << point << endl;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        point = RotateCCW(point);
        cout << point << endl;
    }
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
            // 8 : 20
            // 600 : 8950634
            // 40000 : 2666610948988
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
