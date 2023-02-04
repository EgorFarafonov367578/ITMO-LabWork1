#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
//#include <filesystem>
#include <cstdint>
#include <queue>

long long int CoutNumberOfLinesInFile(const std::string& file_name);
long long int CoutNumberOfWordsInFile(const std::string& file_name);
long long int CoutNumberOfLettersInFile(const std::string& file_name);
long long int CoutNumberOfBytesInFile(const std::string& file_name);

bool CheckingIfFileIsOkey(const std::string& file_name);

bool is_lines_needed = false;
bool is_words_needed = false;
bool is_letters_needed = false;
bool is_bytes_needed = false;
bool clients_error = false;


std::queue <std::string> file_names;

void ParserOfInputData(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    ParserOfInputData(argc, argv);
    if (clients_error == true)
    {
        return 0;
    }
    //std::cout << "p2" << std::endl;
    while (file_names.empty() == false)
    {
        std::string file_name = file_names.front();
        file_names.pop();
        //std::cout << file_name << std::endl;
        if (CheckingIfFileIsOkey(file_name))
        {
            //std::cout << "p3" << std::endl;
            if (is_lines_needed)
            {
                std::cout << CoutNumberOfLinesInFile(file_name) << " ";
            }
            //std::cout << "p4" << std::endl;
            if (is_words_needed)
            {
                std::cout << CoutNumberOfWordsInFile(file_name) << " ";
            }
            if (is_bytes_needed)
            {
                std::cout << CoutNumberOfBytesInFile(file_name) << " ";
            }
            if (is_letters_needed)
            {
                std::cout << CoutNumberOfLettersInFile(file_name) << " ";
            }
            std::cout << file_name << std::endl;
        }
        else
        {
            std::cout << "Something is wrong with file" << file_name << std::endl;
        }
    }
}

void ParserOfInputData(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "You didn't give us any arguments or file names! \nPlease, try again" << std::endl;
        clients_error = true;
    }
    else
    {
        int posion_of_arg = 1;
        while (posion_of_arg < argc)
        {
            if (argv[posion_of_arg][0] != '-')
            {
                file_names.push(argv[posion_of_arg]);
            }
            else if (argv[posion_of_arg][1] == '\0')
            {
                clients_error = true;
                break;
            }
            else if (argv[posion_of_arg][1] == '-')
            {
                if (std::strcmp(argv[posion_of_arg], "--lines") == 0)
                {
                    is_lines_needed = true;
                }
                else if (std::strcmp(argv[posion_of_arg], "--bytes") == 0)
                {
                    is_bytes_needed = true;
                }
                else if (std::strcmp(argv[posion_of_arg], "--words") == 0)
                {
                    is_words_needed = true;
                }
                else if (std::strcmp(argv[posion_of_arg], "--chars") == 0)
                {
                    is_letters_needed = true;
                }
                else
                {
                    clients_error = true;
                    break;
                }
            }
            else
            {
                int parser_of_arg = 1;
                while (argv[posion_of_arg][parser_of_arg] != '\0')
                {
                    switch (argv[posion_of_arg][parser_of_arg])
                    {
                    case('l'):
                        is_lines_needed = true;
                        break;
                    case('c'):
                        is_bytes_needed = true;
                        break;
                    case('w'):
                        is_words_needed = true;
                        break;
                    case('m'):
                        is_letters_needed = true;
                        break;
                    default:
                        clients_error = true;
                        break;
                    }
                    if (clients_error == true)
                    {
                        break;
                    }
                    parser_of_arg++;
                }
                if (clients_error == true)
                {
                    break;
                }
            }
            posion_of_arg++;
        }
        if (clients_error == true)
        {
            std::cout << "You made mistakes in argument recording" << std::endl;
        }
    }
    if ((!is_lines_needed) && (!is_words_needed) && (!is_letters_needed) && (!is_bytes_needed))
    {
        is_lines_needed = true;
        is_words_needed = true;
        is_letters_needed = false;
        is_bytes_needed = true;
    }
}

bool CheckingIfFileIsOkey(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::in);
    if (file.is_open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long int CoutNumberOfLinesInFile(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::in);
    if (file.is_open())
    {
        long long int counter_of_lines_in_file = 0;
        while (file.eof() != true)
        {

            //std::string place_for_a_line;
            //getline(file,place_for_a_line);
            //getline(file, );
            char letter;
            letter = file.get();
            if (letter == '\n')
            {
                counter_of_lines_in_file++;
            }
        }
        return (counter_of_lines_in_file+1);
    }
    else
    {
        std::cout << std::endl << "Opening file \"" << file_name << "\"  failed" << std::endl;
    }
}

long long int CoutNumberOfWordsInFile(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::in);
    if (file.is_open())
    {
        long long int counter_of_words_in_file = 0;
        while (file.eof() != true)
        {
            std::string place_for_a_word;
            file >> place_for_a_word;;
            counter_of_words_in_file++;
        }
        return counter_of_words_in_file;
    }
    else
    {
        std::cout << std::endl << "Opening file \"" << file_name << "\" failed" << std::endl;
    }
}

long long int CoutNumberOfLettersInFile(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::in);
    if (file.is_open())
    {
        long long int counter_of_letters_in_file = 0;
        while (file.eof() != true)
        {
            char letter;
            letter = file.get();
            if (isalpha(letter))
            {
                counter_of_letters_in_file++;
            }
        }
        return counter_of_letters_in_file;
    }
    else
    {
        std::cout << std::endl << "Opening file \"" << file_name << "\"  failed" << std::endl;
    }
}

long long int CoutNumberOfBytesInFile(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::binary);
    if (file.is_open())
    {
        long long int counter_of_bytes_in_file = 0;
        while (file.eof() != true)
        {
            int8_t byte;
            //file >> byte; // дублирует последний байт
            byte = file.get();
            //std::cout << byte << std::endl;
            if (byte != -1) counter_of_bytes_in_file++; // как оказлось, на канце каждого файла есть странный байт(как я понял, он обозначает конец файла) со значением -1, который нужно проигнорировать
        }
        return counter_of_bytes_in_file;
    }
    else
    {
        std::cout << std::endl << "Opening file \"" << file_name << "\"  failed" << std::endl;
    }
}