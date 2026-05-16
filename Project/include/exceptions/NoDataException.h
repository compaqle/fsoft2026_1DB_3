#pragma once
#include <exception>
#include <string>

class NoDataException : public std::exception {
private:
    std::string data;
public:
    NoDataException(const std::string& data);
    const char* what() const noexcept override;
};
