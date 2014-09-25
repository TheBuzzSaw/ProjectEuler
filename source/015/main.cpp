#include <iostream>
#include <sstream>
#include <cstdint>
#include <vector>
using namespace std;

int64_t CountPaths(int64_t width, int64_t height)
{
    if (width < 1 || height < 1) return -1;
    
    int64_t w = width + 1;
    int64_t h = height + 1;
    vector<int64_t> grid;
    grid.resize(w * h);
    
    for (size_t i = 0; i < w; ++i)
        grid[i] = 1;
        
    for (size_t i = 1; i < h; ++i)
        grid[w * i] = 1;
    
    size_t x = 1;
    size_t y = 1;
    
    while (x < w)
    {
        while (y < h)
        {
            grid[y * w + x] = grid[y * w + x - 1] + grid[(y - 1) * w + x];
            ++y;
        }
        
        y = 1;
        ++x;
    }
    
    return grid[w * h - 1];
}

int main(int argc, char** argv)
{
    if (argc > 2)
    {
        int64_t width;
        int64_t height;
        
        stringstream ss;
        ss << argv[1] << ' ' << argv[2];
        
        if (ss >> width >> height)
        {
            cout << "path count: " << CountPaths(width, height) << endl;
        }
    }
    else
    {
        cerr << "requires width and height\n";
    }
    
    return 0;
}
