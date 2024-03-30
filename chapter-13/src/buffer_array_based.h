private:
    static const int INITIAL_CAPACITY = 10;
    char *array;
    int count;
    int capacity;
    int cursorPosition;
    void expandCapacity();
