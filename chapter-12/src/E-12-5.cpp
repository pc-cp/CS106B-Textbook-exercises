
int & IntArray::operator[](int k) {
    if(k >= capacity) {
        error("k is outside the vector bounds.");
    }
    return this->array[k];
}
