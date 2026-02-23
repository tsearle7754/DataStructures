#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
public:
    Board();

    void print() const;
    void place_queens();

    // TODO
    // MAKE CODE PRETTIER

    // TODO
    void place_queens_all();    // don't stop when you finish - search for all combinations but don't repeat combinations (64 combinations)
    // use helper to loop through columns and rows then check and call recursively
    

private:
    bool check_place(const int row, const int col) const;
    void place_queen_helper(int row, int col, int queens_placed, bool& finished);

    std::vector<std::string> board;
    unsigned board_size;
};

#endif