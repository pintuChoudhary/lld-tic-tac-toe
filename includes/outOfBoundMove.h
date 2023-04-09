#ifndef OUT_OF_BOUND_EXCEPTION
#define OUT_OF_BOUND_EXCEPTION

#include<string>
#include<exception>

class OutOfBoundMoveException : public std::exception {
    private:
    std::string msg;
    
    public:
    OutOfBoundMoveException(const std::string &msg);

    virtual const char * what() const noexcept;
};

#endif