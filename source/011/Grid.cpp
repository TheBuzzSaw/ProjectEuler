#include "Grid.hpp"

Grid::Grid(std::istream& stream)
    : _columnCount(20)
{
    int64_t value;
    
    while (stream >> value) _values.push_back(value);
}

Grid::~Grid()
{
}

int64_t Grid::Get(std::size_t row, std::size_t column) const
{
    return _values[row * _columnCount + column];
}

std::size_t Grid::RowCount() const
{
    return (_values.size() + _columnCount - 1) / _columnCount;
}

std::size_t Grid::ColumnCount() const
{
    return _columnCount;
}
