#include <iostream>
#include "stl.hpp"


int main() {
    auto stl_obj = stl();
    stl_obj.chars_from_file_to_vect("bible.txt");
    //stl_obj.chars_in_file();
    //stl_obj.lines_in_file();
    //stl_obj.letters_in_file();
    //stl_obj.chars_to_lower_case();
    stl_obj.count_all_letters();
    stl_obj.print_letter_set();
    stl_obj.count_all_words("bible.txt");
    stl_obj.print_word_set();
}
