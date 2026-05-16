#pragma once
#include <exception>
#include <string>

class DataConsistencyException : public std::exception {
private:
    std::string data;
public:
    DataConsistencyException(const std::string& data);
    const char* what() const noexcept override;
};
