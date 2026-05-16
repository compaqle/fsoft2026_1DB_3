#include "../../include/exceptions/DataConsistencyException.h"

DataConsistencyException::DataConsistencyException(const std::string& data) {
    this->data = "Error: [" + data + "] has dependencies!!";
}

const char* DataConsistencyException::what() const noexcept {
    return data.c_str();
}
