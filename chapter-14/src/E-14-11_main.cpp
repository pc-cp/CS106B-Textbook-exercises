
#include <iostream>
#include <cassert>
#include "mygrid.h"

using namespace std;

template <typename ValueType>
void print(MyGrid<ValueType> &grid) {
    for(int i = 0; i < grid.numRows(); ++i) {
        for(int j = 0; j < grid.numCols(); ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    // Initial setup for testing copy constructor and assignment operator
    MyGrid<int> original(2, 2);
    original.set(0, 0, 1);
    original.set(0, 1, 2);
    original.set(1, 0, 3);
    original.set(1, 1, 4);

    // // Test copy constructor
    MyGrid<int> copyConstructedGrid = original;
    assert(copyConstructedGrid.numRows() == original.numRows() && copyConstructedGrid.numCols() == original.numCols());
    // // Check if the copied grid has the same content but is a separate object
    for(int i = 0; i < original.numRows(); i++) {
        for(int j = 0; j < original.numCols(); j++) {
            assert(copyConstructedGrid.get(i, j) == original.get(i, j));
        }
    }
    // // Modify the original grid to ensure it doesn't affect the copied grid
    original.set(0, 0, 5);
    assert(original.get(0, 0) != copyConstructedGrid.get(0, 0));

    // // Test assignment operator
    MyGrid<int> assignedGrid;
    assignedGrid = original;
    assert(assignedGrid.numRows() == original.numRows() && assignedGrid.numCols() == original.numCols());
    // // Check if the assigned grid has the same content but is a separate object
    for(int i = 0; i < original.numRows(); i++) {
        for(int j = 0; j < original.numCols(); j++) {
            assert(assignedGrid.get(i, j) == original.get(i, j));
        }
    }
    // // Modify the original grid again to ensure it doesn't affect the assigned grid
    original.set(1, 1, 6);
    assert(original.get(1, 1) != assignedGrid.get(1, 1));


    // // Test default constructor
    MyGrid<int> grid1;
    assert(grid1.isEmpty());
    assert(grid1.numRows() == 0 && grid1.numCols() == 0);

    // // Test parameterized constructor for size initialization
    MyGrid<int> grid2(5, 10);
    assert(!grid2.isEmpty());
    assert(grid2.numRows() == 5 && grid2.numCols() == 10);

    // // Test fill and access
    grid2.fill(42);
    for(int i = 0; i < grid2.numRows(); i++) {
        for(int j = 0; j < grid2.numCols(); j++) {
            assert(grid2.get(i, j) == 42);
        }
    }

    // // Test set and inBounds
    grid2.set(0, 0, 24);
    assert(grid2.get(0, 0) == 24);
    assert(grid2.inBounds(0, 0));
    assert(!grid2.inBounds(-1, -1)); // Test boundary check

    // // Test resize
    grid2.resize(3, 3);
    print(grid2);
    assert(grid2.numRows() == 3 && grid2.numCols() == 3);
    // // After resizing, test if an old position is out of bounds
    assert(!grid2.inBounds(4, 9));

    // // Test operator[]
    MyVector<int> &row = grid2[0]; // Should not cause assertion
    row[0] = 100; // Use MyVector's operator[] to set a value
    assert(grid2[0][0] == 100);

    // // Test clear
    grid2.clear();
    assert(grid2.isEmpty());

    MyGrid<int> grid3(3, 4, 10), grid4;
    print(grid3);

    grid4 = grid3;

    grid4.resize(2, 2, true);
    print(grid4);
    std::cout << "All tests passed, including copy constructor and assignment operator." << std::endl;
    return 0;
}
