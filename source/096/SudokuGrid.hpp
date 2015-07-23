#ifndef SUDOKUGRID_HPP
#define SUDOKUGRID_HPP

#include <bitset>
#include <iostream>

const int MultipleValues = -1;
const int NoValues = -2;

template<typename T>
static constexpr bool InRange(T value, T low, T high)
{
    return low <= value && value <= high;
}

class SudokuGrid
{
    public:
        constexpr SudokuGrid() = default;
        constexpr SudokuGrid(const SudokuGrid&) = default;
        ~SudokuGrid() = default;

        SudokuGrid& operator=(const SudokuGrid&) = default;

        bool Set(int row, int column, int value) noexcept;
        bool Solve() noexcept;

        bool IsSolved() const noexcept;
        bool CanBeSolved() const noexcept;
        int Value(int row, int column) const noexcept;
        std::ostream& Write(std::ostream& stream) const;
    protected:
    private:
        std::bitset<9 * 9 * 9> _banned;

        void Ban(int row, int column, int value) noexcept;
        void SpreadBan(int row, int column, int value) noexcept;
        int CountLegalValues(int index) const noexcept;
};

std::ostream& operator<<(std::ostream& stream, const SudokuGrid& grid);

#endif
