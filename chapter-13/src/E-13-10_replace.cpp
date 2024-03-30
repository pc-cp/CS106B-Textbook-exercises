
bool EditorBuffer::replace(std::string str, std::string des) {
    std::string src = "";
    for(int i = after + 1; i < capacity; ++i) {
        src += array[i];
    }

    int res = searchKMP(src, str);
    if(res == -1) {
        return false;
    }
    else {
        int newCurosorPosition = res - str.size();
        while(newCurosorPosition--) {
            moveCursorForward();
        }
        int deleteStr = str.size();
        while(deleteStr--) {
            deleteCharacter();
        }

        for(int i = 0; i < des.size(); ++i) {
            insertCharacter(des[i]);
        }

        return true;
    }
}
