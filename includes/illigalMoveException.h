#ifndef ILLIGAL_MOVE_EXCEPTION
#define ILLIGAL_MOVE_EXCEPTION

#include<string>
#include<exception>

class IlligalMoveException: public std::exception{
private:
    std::string msg;
public:
    IlligalMoveException(const std::string & msg);
    virtual const char* what() const noexcept;
};


#endif