#include "SudokuGrid.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdint>
using namespace std;

int64_t GetAnswer()
{
    char line[16];
    
    ifstream fin("p096_sudoku.txt", ifstream::binary);
    
    if (!fin) return 0;
    
    int64_t result = 0;
    
    while (fin.getline(line, sizeof(line)) &&
        !strncmp(line, "Grid", 4))
    {
        SudokuGrid grid;
        
        for (int i = 0; i < 9; ++i)
        {
            fin.getline(line, sizeof(line));
            
            for (int j = 0; j < 9; ++j)
            {
                char c = line[j];
                
                if (InRange(c, '1', '9'))
                    grid.Set(i, j, c - '1');
            }
        }
        
        if (grid.Solve())
        {
            int64_t a = grid.Value(0, 0) + 1;
            int64_t b = grid.Value(0, 1) + 1;
            int64_t c = grid.Value(0, 2) + 1;
            
            result += a * 100 + b * 10 + c;
        }
    }
    
    fin.close();
    return result;
}

int main(int argc, char** argv)
{
    cout << GetAnswer() << endl;
    return 0;
}