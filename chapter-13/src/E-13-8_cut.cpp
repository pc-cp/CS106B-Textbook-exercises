
void EditorBuffer::cut(int count) {
    copy(count);
    for(int i = 0; i < copyLength; ++i) {
        deleteCharacter();
    }
}
