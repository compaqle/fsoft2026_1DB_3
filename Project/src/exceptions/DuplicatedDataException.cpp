#include "../../include/exceptions/DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(const std::string& data) {
    this->data = "Error: [" + data + "] already exists!!";
}

const char* DuplicatedDataException::what() const noexcept {
    return data.c_str();
}
