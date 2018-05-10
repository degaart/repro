#pragma once

#include <functional>
#include <string>
#include <vector>

namespace repro {

    std::vector<std::string> split(const std::string& str, char delim);
    void rtrim(std::string* str, std::function<bool(char)> strip_fn);
    void ltrim(std::string* str, std::function<bool(char)> strip_fn);
    void trim(std::string* str, std::function<bool(char)> strip_fn);
    std::string rtrim(std::string str, std::function<bool(char)> strip_fn);
    std::string ltrim(std::string str, std::function<bool(char)> strip_fn);
    std::string trim(std::string str, std::function<bool(char)> strip_fn);
    std::string rtrim(const std::string& str, const std::string& chars);
    std::string ltrim(const std::string& str, const std::string& chars);
    std::string trim(const std::string& str, const std::string& chars);
    std::string rtrim(const std::string& str);
    std::string ltrim(const std::string& str);
    std::string trim(const std::string& str);
    std::string encode_hex(const std::vector<unsigned char>& data, bool lcase = false);
    std::string encode_hex(const void* data, size_t size, bool lcase = false);

}


