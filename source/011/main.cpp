#include "Grid.hpp"
#include <fstream>
#include <iomanip>
using namespace std;

int64_t FindLargestHorizontalProduct(const Grid& grid)
{
    int64_t largestProduct = 0;
    std::size_t rowCount = grid.RowCount();
    std::size_t columnCount = grid.ColumnCount() - 4;
    
    for (std::size_t i = 0; i < rowCount; ++i)
    {
        for (std::size_t j = 0; j < columnCount; ++j)
        {
            int64_t product = 1;
            
            for (std::size_t k = 0; k < 4; ++k)
                product *= grid.Get(i, j + k);
               
            if (product > largestProduct)
                largestProduct = product;
        }
    }
    
    return largestProduct;
}

int64_t FindLargestVerticalProduct(const Grid& grid)
{
    int64_t largestProduct = 0;
    std::size_t rowCount = grid.RowCount() - 4;
    std::size_t columnCount = grid.ColumnCount();
    
    for (std::size_t i = 0; i < rowCount; ++i)
    {
        for (std::size_t j = 0; j < columnCount; ++j)
        {
            int64_t product = 1;
            
            for (std::size_t k = 0; k < 4; ++k)
                product *= grid.Get(i + k, j);
               
            if (product > largestProduct)
                largestProduct = product;
        }
    }
    
    return largestProduct;
}

int64_t FindLargestDiagonalProduct(const Grid& grid)
{
    int64_t largestProduct = 0;
    std::size_t rowCount = grid.RowCount() - 4;
    std::size_t columnCount = grid.ColumnCount() - 4;
    
    for (std::size_t i = 0; i < rowCount; ++i)
    {
        for (std::size_t j = 0; j < columnCount; ++j)
        {
            int64_t downProduct = 1;
            int64_t upProduct = 1;
            
            for (std::size_t k = 0; k < 4; ++k)
            {
                downProduct *= grid.Get(i + k, j + k);
                upProduct *= grid.Get(i + 3 - k, j + k);
            }
               
            if (downProduct > largestProduct)
                largestProduct = downProduct;
            
            if (upProduct > largestProduct)
                largestProduct = upProduct;
        }
    }
    
    return largestProduct;
}

int main(int argc, char** argv)
{
    ifstream fin("input.txt", ifstream::binary);
    
    if (fin)
    {
        Grid grid(fin);
        fin.close();
        
        cout << "Largest Horizontal Product: "
            << FindLargestHorizontalProduct(grid) << endl;
        cout << "Largest Vertical Product: "
            << FindLargestVerticalProduct(grid) << endl;
        cout << "Largest Diagonal Product: "
            << FindLargestDiagonalProduct(grid) << endl;
    }
    
    return 0;
}
