#ifndef GridHpp
#define GridHpp

#include <iostream>
#include <vector>
#include <cstdint>

class Grid
{
public:
    Grid(std::istream& stream);
    ~Grid();
    
    int64_t Get(std::size_t row, std::size_t column) const;
    std::size_t RowCount() const;
    std::size_t ColumnCount() const;

private:
    Grid(Grid&&) = delete;
    Grid(const Grid&) = delete;
    Grid& operator=(Grid&&) = delete;
    Grid& operator=(const Grid&) = delete;

    std::vector<int64_t> _values;
    std::size_t _columnCount;
};

#endif
