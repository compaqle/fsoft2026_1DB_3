#include "../../include/exceptions/InvalidDataException.h"

InvalidDataException::InvalidDataException(const std::string& data) {
    this->data = "Error: [" + data + "] invalid!!";
}

const char* InvalidDataException::what() const noexcept {
    return data.c_str();
}
