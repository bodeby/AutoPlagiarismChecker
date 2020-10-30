size_t size_of_arrays_calculated(char text[]){
    size_t start_pos = ftell(text);
    fseek(text, 0, SEEK_END);
    size_t size_of_arr = ftell(text);
    fseek(text, start_pos, SEEK_SET);
    return size_of_arr;
}
