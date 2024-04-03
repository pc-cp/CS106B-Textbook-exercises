
#ifndef _mygrid_h
#define _mygrid_h

#include "error.h"
#include "myvector.h"
#include "strlib.h"

template <typename ValueType>
class MyGrid {
public:
    /*
     * Construcor: MyGrid
     * Usage:
     *             MyGrid<ValueType> grid;
     *             MyGrid<ValueType> grid(nRows, nCols);
     *             MyGrid<ValueType> grid(nRows, nCols, value);
     * --------------------------------------------------------
     * the first constructor is Initializes a new empty 0x0 grid.
     * the second is Initializes a new grid of the given size.
     * the third is Initializes a new grid of the given size, with every element set to the specified value.
     */
    MyGrid();
    MyGrid(int nRows, int nCols);
    MyGrid(int nRows, int nCols, ValueType value);

    /*
     * Destructor: ~MyGrid
     * Usage: (usually implicit)
     * -------------------------
     * Free any heap storage allocated by this grid.
     */
    ~MyGrid();

    /*
     * Method: clear
     * Usage: mygrid.clear();
     * ----------------------
     * Removes all elements from this grid.
     */
    void clear();

    /*
     * Method: equals
     * Usage: if(mygrid.equals(grid2)) . . .
     * -------------------------------------
     * Returns true if the two grids contain the same elements.
     */
    bool equals(const MyGrid<ValueType> &grid) const;

    /*
     * Method: fill
     * Usage: mygrid.fill(value);
     * --------------------------
     * Sets every element in this grid to the given value.
     */
    void fill(ValueType value);

    /*
     * Method: get
     * Usage: mygrid.get(row, col)
     * ---------------------------
     * Returns the element at the specified row/col in this grid.
     */
    ValueType get(int row, int col) const;

    /*
     * Method: isBounds
     * Usage: if(mygrid.inBounds(row, col));
     * -------------------------------------
     * Returns true if the specified row/col is inside the bounds of this grid.
     *
     */
    bool inBounds(int row, int col) const;

    /*
     * Method: isEmpty
     * Usage: if(grid.isEmpty()) . . .
     * -------------------------------
     * Returns true if this grid has 0 rows and/or 0 columns.
     */
    bool isEmpty() const;

    /*
     * Method: numCols
     * Usage: grid.numCols();
     * ----------------------
     * Returns the number of columns in this grid.
     */
    int numCols() const;

    /*
     * Method: numRows
     * Usage: grid.numRows();
     * ----------------------
     * Returns the number of rows in this grid.
     */
    int numRows() const;

    /*
     * Method: resize
     * Usage: grid.resize(rows, cols);
     * -------------------------------
     * Reinitializes this grid to have the specified number of rows and columns.
     * If the optional retain argument is true, it retains whatever previous grid contents can be.
     */
    void resize(int nRows, int nCols, bool retain = false);

    /*
     * Method: set
     * Usage: grid.set(row, col, value);
     * ---------------------------------
     * Replaces the element at the specified row/col in this grid with a new value.
     */
    void set(int row, int col, ValueType value);

    /*
     * Method: size
     * Usage: grid.size();
     * -------------------
     * Returns the total number of elements in this grid.
     */
    int size() const;

    /*
     * operator []
     * Usage: grid[row][col];
     * ----------------------
     * Overloads [] to select elements from this grid by row/col.
     */
    MyVector<ValueType> & operator[] (int row);

    /*
     * Copy constructor and assignment operator
     * ----------------------------------------
     * These methods implement deep copying for grid.
     */
    MyGrid(const MyGrid<ValueType> &src);

    MyGrid<ValueType> & operator= (const MyGrid<ValueType> &src);

private:

    MyVector<ValueType> *array;
    int rows, cols;

    void deepCopy(const MyGrid<ValueType> &src);
    // void expandCapacity();
};

/*
 * Implementation notes: MyGrid constructor and destructor
 *
 */

template <typename ValueType>
MyGrid<ValueType>::MyGrid() {
    array = NULL;
    rows = cols = 0;
}

template <typename ValueType>
MyGrid<ValueType>::MyGrid(int nRows, int nCols) {
    rows = nRows;
    cols = nCols;
    /*
     * code first allocates space for rows number of MyVector objects,
     * initializing them with the default constructor, and then reassigns
     * each to a new MyVector object created with the parameterized
     * constructor that initializes each vector with cols elements.
     */
    array = new MyVector<ValueType> [rows];

    for(int i = 0; i < rows; ++i) {
        array[i] = MyVector<ValueType> (cols);
    }
}

template <typename ValueType>
MyGrid<ValueType>::MyGrid(int nRows, int nCols, ValueType value) {
    rows = nRows;
    cols = nCols;
    /*
     * code first allocates space for rows number of MyVector objects,
     * initializing them with the default constructor, and then reassigns
     * each to a new MyVector object created with the parameterized
     * constructor that initializes each vector with cols elements.
     */
    array = new MyVector<ValueType> [rows];

    for(int i = 0; i < rows; ++i) {
        array[i] = MyVector<ValueType> (cols, value);
    }
}

template <typename ValueType>
MyGrid<ValueType>::~MyGrid() {
    delete [] array;
}

/*
 * Method: clear
 * -------------
 * just set rows to 0.
 */
template <typename ValueType>
void MyGrid<ValueType>::clear() {
    rows = 0;
    cols = 0;
}

/*
 * Implementation notes: equals, fill
 * ----------------------------------
 * if they leverage operator[], it will very convenient.
 */
template <typename ValueType>
bool MyGrid<ValueType>::equals(const MyGrid<ValueType> &grid) const {

    if((numRows() != grid.numRows()) || (numCols() != grid.numCols())) {
        return false;
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(array[i][j] != grid.get(i, j)) {
                return false;
            }
        }
    }
    return true;
}

template <typename ValueType>
void MyGrid<ValueType>::fill(ValueType value) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            array[i][j] = value;
        }
    }
}

/*
 * Implementation notes: get, inBounds, isEmpty, numRow, numCols
 * -------------------------------------------------------------
 * they can use instance variable to finish.
 */
template <typename ValueType>
ValueType MyGrid<ValueType>::get(int row, int col) const {
    if(!inBounds(row, col)) {
        error("get: The specified location is outside the grid boundaries");
    }
    return array[row][col];
}

template <typename ValueType>
bool MyGrid<ValueType>::inBounds(int row, int col) const {
    if(row < 0 || row >= numRows() || col < 0 || col >= numCols()) {
        return false;
    }
    return true;
}

template <typename ValueType>
bool MyGrid<ValueType>::isEmpty() const {
    return numRows() == 0 && numCols() == 0;
}

template <typename ValueType>
int MyGrid<ValueType>::numRows() const {
    return rows;
}

template <typename ValueType>
int MyGrid<ValueType>::numCols() const {
    return cols;
}

/*
 * Implementation notes: resize
 * ----------------------------
 * The method first allocates a new array of MyVector<ValueType> to represent the new rows, each initialized with nCols elements.
 * It then iterates over the minimum of the old and new dimensions, copying existing values to the new array (retain = true). This preserves the
 * content as much as possible within the bounds of the new dimensions. After copying, it deletes the old array to free up memory.
 * This operation has a time complexity that depends on the total number of elements being copied.
 */
template <typename ValueType>
void MyGrid<ValueType>::resize(int nRows, int nCols, bool retain) {
    if(!inBounds(nRows, nCols)) error("resize: The specified location is outside the grid boundaries");

    MyVector<ValueType> *oldArray = array;

    array = new MyVector<ValueType> [nRows];
    for(int i = 0; i < nRows; ++i) {
        array[i] = MyVector<ValueType>(nCols);
    }

    if(retain) {
        bool exhaustedNewCapacity = false;
        int posRow = 0, posCol = 0;
        for(int i = 0; i < numRows(); ++i) {
            for(int j = 0; j < numCols(); ++j) {
                if(posCol == nCols) {
                    posCol = 0;
                    posRow ++;
                    if(posRow == nRows) {
                        exhaustedNewCapacity = true;
                    }
                }

                if(exhaustedNewCapacity) {
                    break;
                }

                array[posRow][posCol++] = oldArray[i][j];

            }
            if(exhaustedNewCapacity) {
                break;
            }
        }
    }

    rows = nRows;
    cols = nCols;

    delete [] oldArray;

}

/*
 * Implementation notes: set
 * -------------------------
 * The boundary check ensures the operation's safety by preventing out-of-bounds
 * access, which could lead to undefined behavior. The method relies on the
 * MyVector's operator[] to access and modify elements efficiently.
 */
template <typename ValueType>
void MyGrid<ValueType>::set(int row, int col, ValueType value) {
    if(!inBounds(row, col)) {
        error("set: The specified location is outside the grid boundaries");
    }
    array[row][col] = value;
}

/*
 * Implementation notes: size
 * --------------------------
 * size is equal rows * cols.
 */
template <typename ValueType>
int MyGrid<ValueType>::size() const {
    return rows * cols;
}

/*
 * Implementation notes: operator[]
 * --------------------------------
 * The method returns a reference to the MyVector object at the specified row
 * index by directly accessing the internal array of MyVector objects. This simple
 * approach relies on the encapsulated functionality of MyVector's operator[],
 * ensuring consistency in element access and assignment across the grid.
 */
template <typename ValueType>
MyVector<ValueType> & MyGrid<ValueType>::operator [](int row) {
    if(!(row >= 0 && row < rows)) error("operator []: the index is not in the array index.");
    return array[row];
}

/*
 * Implementation notes: copy constructor ans assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard templates, leaving the work to deepCopy.
 */
template <typename ValueType>
MyGrid<ValueType>::MyGrid(const MyGrid<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyGrid<ValueType> & MyGrid<ValueType>::operator =(const MyGrid<ValueType> &src) {
    if(this != &src) {
        delete [] array;
        deepCopy(src);
    }
    return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object.
 * All dynamic memory is reallocated to create a "deep copy" in
 * which the current object and the source object are independent.
 */
template <typename ValueType>
void MyGrid<ValueType>::deepCopy(const MyGrid<ValueType> &src) {
    array = new MyVector<ValueType> [src.numRows()];
    for(int i = 0; i < src.numRows(); ++i) {
        array[i] = MyVector<ValueType> (src.numCols());
    }

    for(int i = 0; i < src.numRows(); ++i) {
        for(int j = 0; j < src.numCols(); ++j) {
            array[i][j] = src.get(i, j);
        }
    }
    rows = src.numRows();
    cols = src.numCols();
}

#endif

