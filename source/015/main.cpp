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
    vector<int64_t> grid(w * h, 1);
    
    int64_t x = 0;
    int64_t y = 0;
    
    while (++x < w)
    {
        while (++y < h)
        {
            auto n = y * w + x;
            grid[n] = grid[n - 1] + grid[n - w];
        }
        
        y = 0;
    }
    
    return grid.back();
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
