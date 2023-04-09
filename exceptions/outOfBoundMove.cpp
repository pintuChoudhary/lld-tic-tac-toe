#include"outOfBoundMove.h"

OutOfBoundMoveException::OutOfBoundMoveException(const std::string &msg): msg(msg) {}

const char * OutOfBoundMoveException::what() const noexcept {
    return msg.c_str();
}