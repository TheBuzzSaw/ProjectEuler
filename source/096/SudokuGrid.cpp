#include "SudokuGrid.hpp"
#include <cstdint>

static constexpr int IndexOf(int row, int column)
{
    return row * 81 + column * 9;
}

bool SudokuGrid::Set(int row, int column, int value) noexcept
{
    int index = IndexOf(row, column);

    if (_banned.test(index + value))
        return false;

    for (int i = 0; i < 9; ++i)
        _banned.set(index + i, i != value);

    SpreadBan(row, column, value);

    return true;
}

bool SudokuGrid::Solve() noexcept
{
    int minCount = 10;
    int row = -1;
    int column = -1;

    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            int index = IndexOf(r, c);
            int valueCount = CountLegalValues(index);

            if (valueCount == 0)
            {
                return false;
            }
            else if (valueCount > 1 && valueCount < minCount)
            {
                minCount = valueCount;
                row = r;
                column = c;
            }
        }
    }

    if (minCount < 10)
    {
        int index = IndexOf(row, column);

        for (int i = 0; i < 9; ++i)
        {
            if (!_banned.test(index + i))
            {
                SudokuGrid grid(*this);
                grid.Set(row, column, i);

                if (grid.Solve())
                {
                    *this = grid;
                    return true;
                }
                else
                {
                    Ban(row, column, i);
                }
            }
        }

        return false;
    }

    return true;
}

bool SudokuGrid::IsSolved() const noexcept
{
    for (int i = 0; i < 81; ++i)
    {
        if (CountLegalValues(i * 9) != 1)
            return false;
    }

    return true;
}

bool SudokuGrid::CanBeSolved() const noexcept
{
    for (int i = 0; i < 81; ++i)
    {
        if (CountLegalValues(i * 9) == 0)
            return false;
    }

    return true;
}

int SudokuGrid::Value(int row, int column) const noexcept
{
    int index = IndexOf(row, column);
    int result = NoValues;

    for (int i = 0; i < 9; ++i)
    {
        if (!_banned.test(index + i))
        {
            if (result == NoValues)
                result = i;
            else
                return MultipleValues;
        }
    }

    return result;
}

std::ostream& SudokuGrid::Write(std::ostream& stream) const
{
    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            int index = IndexOf(r, c);
            char value = 'x';

            for (int i = 0; i < 9; ++i)
            {
                if (!_banned.test(index + i))
                {
                    if (value == 'x')
                    {
                        value = '1' + i;
                    }
                    else
                    {
                        value = '.';
                        break;
                    }
                }
            }

            stream << value;

            if (c == 2 || c == 5)
                stream << '|';
        }

        stream << '\n';

        if (r == 2 || r == 5)
            stream << "---+---+---\n";
    }

    return stream;
}

void SudokuGrid::Ban(int row, int column, int value) noexcept
{
    int index = IndexOf(row, column);

    if (!_banned.test(index + value))
    {
        _banned.set(index + value);

        bool found = false;
        int legalValue = -1;

        for (int i = 0; i < 9; ++i)
        {
            if (!_banned.test(index + i))
            {
                if (found)
                {
                    return;
                }
                else
                {
                    legalValue = i;
                    found = true;
                }
            }
        }

        if (found) SpreadBan(row, column, legalValue);
    }
}

void SudokuGrid::SpreadBan(int row, int column, int value) noexcept
{
    for (int r = 0; r < 9; ++r)
        if (r != row) Ban(r, column, value);

    for (int c = 0; c < 9; ++c)
        if (c != column) Ban(row, c, value);

    int boxRow = (row / 3) * 3;
    int boxColumn = (column / 3) * 3;

    for (int r = 0; r < 3; ++r)
    {
        int rr = boxRow + r;
        if (rr == row) continue;

        for (int c = 0; c < 3; ++c)
        {
            int cc = boxColumn + c;
            if (cc == column) continue;

            Ban(rr, cc, value);
        }
    }
}

int SudokuGrid::CountLegalValues(int index) const noexcept
{
    int result = 0;

    for (int i = 0; i < 9; ++i)
        result += !_banned.test(index + i);

    return result;
}

std::ostream& operator<<(std::ostream& stream, const SudokuGrid& grid)
{
    return grid.Write(stream);
}
