#include <string>
#include <iostream>
#include <unordered_map>
#include "Direction.hpp"
#include <limits.h>
#define MAX_ROW 100

using namespace std;

namespace ariel{
class Notebook{
public:
    int page;
    int row;
    int col;
    int max_page;
    int max_row;
    int max_col;
    int min_page;
    int min_row;
    int min_col;
    unordered_map<int, unordered_map<int, unordered_map<int, char>>> book;
        Notebook(){
        page = 0;
        row = 0;
        col = 0;
        max_page = 0;
        max_row = 0;
        max_col = 0;
        min_page = INT_MAX;
        min_row = INT_MAX; 
        min_col = 100;
            };
 void write(int page, int row, int col, Direction direction, std::string a);
 string read(int page, int row, int col, Direction direction, int numOfChars);
 void erase (int page, int row, int col, Direction direction, int numOfChars);
 void show(int page);
 void newLine(int page, int row);
};
}