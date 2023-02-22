#ifndef STL_HPP
#define STL_HPP

#include <sstream>
#include "fstream"
#include "vector"
#include "iostream"
#include "algorithm"
#include "cctype"
#include "map"
#include "set"
#include "functional"


class stl{

private:
    std::vector<char> the_file = {};
    std::map<char,int> letter_map;
    std::map<std::string, int> word_counts;

public:
    stl(){};

    /// read the chars in from a file
    void chars_from_file_to_vect(std::string file){
        std::ifstream stream(file);
        char c;
        while(stream.get(c)){
            the_file.push_back(c);
        } stream.close();
    }

    /// Print amount of characters in file
    void chars_in_file(){
        std::cout << "Amount of characters in given file: " << the_file.size() << "\n";
    }

    /// Print amount of line in file
    void lines_in_file(){
        // std::count
        int lines = std::count(the_file.begin(), the_file.end(), '\n');
        std::cout << "Amount of lines in given file: " << lines << "\n";
    }

    /// Print amount of letters in file
    void letters_in_file(){
        // std::count_if function returns 1 each time it iterates over a letter
        int letters = std::count_if(the_file.begin(), the_file.end(), [](unsigned char c){ return std::isalpha(c);});
        std::cout << "Amount of letters in given file: " << letters << "\n";
    }

    /// Turn chars to lower case
    void chars_to_lower_case(){
        // using std::transform and std::tolower
        std::transform(the_file.begin(), the_file.end(), the_file.begin(),[](char c){return std::tolower(c);});
    }

    /// Stores the amount of times the letter is used in file
    void count_all_letters(){
        std::string letters = "abcdefghijklmnopqrstuvwxyz";
        for(char c : letters){
            int occurence = std::count(the_file.begin(), the_file.end(), c);
            letter_map[c] = occurence;
        }
    }

    /// Print the entire file
    void print_vect(){
        for(auto i : the_file){
            std::cout << i;
        }
    }

    /// Print the letters used in the given file by descending order
    void print_letter_set(){
        // Making a sorting function called sorter
        typedef std::function<bool(std::pair<char,int>, std::pair<char,int>)> sorter;
        // Defining the sorter as lambda
        sorter sort = [](std::pair<char,int> first_elem, std::pair<char, int> second_elem){
            return first_elem.second > second_elem.second;
        };

        // Making a set 
        std::set<std::pair<char,int>, sorter> letter_set(letter_map.begin(), letter_map.end(), sort);

        // print pairs from set
        for (auto const &pair : letter_set) {
        std::cout << "(" << pair.first << ", "<< pair.second << ")"<< "\n";
        }
    }

    /// Print the words used in the given file by descending order
    void print_word_set(){
        std::vector<std::pair<std::string, int>> word_set;
        for(auto i = word_counts.begin(); i != word_counts.end(); i++){
            word_set.push_back(*i);
        }
        //std::sort
        std::sort(word_set.begin(), word_set.end(), [](std::pair<std::string, int> &x, std::pair<std::string, int> &y)->bool{
		    return x.second > y.second;
	    });

        int i = 1;
        //first 10
	    for(auto it = word_set.begin(); it < (word_set.begin()+10); it++){
		    std::cout << i << ". (" << it->first << ", " << it->second << ") \n";
		    i++;
	    }	
    }

    /// Count the amount of words in given file
    void count_all_words(std::string file){
        std::fstream input(file);
        while(!input.eof()){
            std::string temp_str;
            input >> temp_str;
            if(!temp_str.empty()){
                // Make the string lower case
                std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(),[](char c){return std::tolower(c);});
                std::string word = temp_str;    
                if(!word.empty()){
                    //std::map find(), find a specific key in the map
                    auto iterator = word_counts.find(word);
                    if(iterator == word_counts.end()){ // word cant be found add to the map
                        word_counts[word] = 1;
                    } else{ // if the word is found add a +1 to its value to count
                        iterator->second++;
                    }
                }
            }
        }
    }

};
#endif //STL_HPP