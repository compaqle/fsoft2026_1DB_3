#pragma once
#include <exception>
#include <string>

class DuplicatedDataException : public std::exception {
private:
    std::string data;
public:
    DuplicatedDataException(const std::string& data);
    const char* what() const noexcept override;
};
