#include "../../include/exceptions/NoDataException.h"

NoDataException::NoDataException(const std::string& data) {
    this->data = "Error: [" + data + "] not found!!";
}

const char* NoDataException::what() const noexcept {
    return data.c_str();
}
