#pragma once
#include <exception>
#include <string>

class InvalidDataException : public std::exception {
private:
    std::string data;
public:
    InvalidDataException(const std::string& data);
    const char* what() const noexcept override;
};
