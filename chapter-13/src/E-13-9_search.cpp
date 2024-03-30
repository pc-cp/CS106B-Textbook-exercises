
bool EditorBuffer::search(std::string str) {
    std::string src = "";
    for(int i = after + 1; i < capacity; ++i) {
        src += array[i];
    }

    int res = searchKMP(src, str);
    if(res == -1) {
        return false;
    }
    else {
        while(res--) {
            moveCursorForward();
        }
        return true;
    }
}

/*
 * Method: searchKMP
 * Usage: private function used search method
 * ------------------------------------------
 *      assert(searchKMP("12345", "23") == 3); true
 *      assert(searchKMP("12345", "6") == -1); false
 */
int EditorBuffer::searchKMP(std::string src, std::string des) {

    int res = -1;
    des = " " + des;
    src = " " + src;

    int *ne = new int[des.size()];

    ne[0] = ne[1] = 0;

    for(int i = 2, j = 0; i < des.size(); ++i) {
        while(j && des[i] != des[j+1]) j = ne[j];
        if(des[i] == des[j+1]) j++;
        ne[i] = j;
    }
    //0 1 2 3 4 5
    for(int i = 1, j = 0; i < src.size(); ++i) {
        while(j && src[i] != des[j+1]) j = ne[j];
        if(src[i] == des[j+1]) j++;
        if(j == des.size()-1) {
            res = i;
            break;
        }
    }
    delete []ne;
    return res;
}
