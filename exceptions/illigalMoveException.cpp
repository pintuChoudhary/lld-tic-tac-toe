#include"illigalMoveException.h"

IlligalMoveException::IlligalMoveException(const std::string &msg): msg(msg) {}

const char * IlligalMoveException::what() const noexcept {
    return msg.c_str();
}