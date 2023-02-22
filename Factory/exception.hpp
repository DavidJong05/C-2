#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class end_of_file final : public std::exception{
public:
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "end of file";
};

class unknown_color final : public std::exception{
public:
    unknown_color(const std::string & name):
        message( std::string( "ERROR : !>>> unknown color: ") + name + " <<<!\n")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

class unknown_shape final : public std::exception{
public:
    unknown_shape(const std::string & name):
        message( std::string( "ERROR : !>>> unknown shape: ") + name + " <<<!\n")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

class invalid_position final : public std::exception{
public:
    invalid_position(const char & name):
        message( std::string( "ERROR : !>>> invalid position: ") + name + " <<<!\n")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

class invalid_type : public std::exception {
public:
    invalid_type( std::string & type):
        message{ std::string{ "ERROR : !>>> file contains an invalid type: "+ type+ " <<<!\n"} }
    {}

    const char * what() const noexcept override{
        return message.c_str();
    }

private:
std::string message;
};

class invalid_image : public std::exception {
public:
    invalid_image( std::string & file ):
        message{ std::string{ "ERROR : !>>> couldn't read image file: "+ file+ " <<<!\n"} }
    {}

    const char * what() const noexcept override{
        return message.c_str();
    }
    
private:
std::string message;
};

#endif