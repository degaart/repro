#include "reprolib.hpp"

extern "C" {
#include "reprolib.h"
}

#include <algorithm>
#include <sstream>
#include <locale>
#include <cctype>

namespace repro {

    std::vector<std::string> split(const std::string& str, char delim)
    {
        std::vector<std::string> result;

        std::stringstream s;
        s.str(str);

        std::string part;
        while(std::getline(s, part, delim)) {
            result.push_back(part);
        }

        return result;
    }

    void rtrim(std::string* str, std::function<bool(char)> strip_fn)
    {
        while(!str->empty() && strip_fn(str->back())) {
            str->pop_back();
        }
    }

    void ltrim(std::string* str, std::function<bool(char)> strip_fn)
    {
        while(!str->empty() && strip_fn(str->front())) {
            str->erase(0, 1);
        }
    }

    void trim(std::string* str, std::function<bool(char)> strip_fn)
    {
        ltrim(str, strip_fn);
        rtrim(str, strip_fn);
    }

    std::string rtrim(std::string str, std::function<bool(char)> strip_fn)
    {
        rtrim(&str, strip_fn);
        return str;
    }

    std::string ltrim(std::string str, std::function<bool(char)> strip_fn)
    {
        ltrim(&str, strip_fn);
        return str;
    }

    std::string trim(std::string str, std::function<bool(char)> strip_fn)
    {
        trim(&str, strip_fn);
        return str;
    }

    std::string rtrim(const std::string& str, const std::string& chars)
    {
        return rtrim(str, [&chars](char ch) -> bool {
            return chars.find(ch) != std::string::npos; 
        });
    }

    std::string ltrim(const std::string& str, const std::string& chars)
    {
        return trim(str, [&chars](char ch) -> bool {
            return chars.find(ch) != std::string::npos; 
        });
    }

    std::string trim(const std::string& str, const std::string& chars)
    {
        return ltrim(rtrim(str, chars), chars);
    }

    std::string rtrim(const std::string& str)
    {
        return rtrim(str, [](char ch) -> bool {
            return isspace(ch) != 0;
        });
    }

    std::string ltrim(const std::string& str)
    {
        return ltrim(str, [](char ch) -> bool {
            return isspace(ch) != 0;
        });
    }

    std::string trim(const std::string& str)
    {
        return ltrim(rtrim(str));
    }

    std::string encode_hex(const std::vector<unsigned char>& data, bool lcase)
    {
        return encode_hex(data.data(), data.size(), lcase);
    }

    std::string encode_hex(const void* data, size_t size, bool lcase)
    {
        char* ret = str_encode_hex2(data, size, lcase);
        if(ret) {
            auto result = std::string(ret);
            free(ret);
            return result;
        } else {
            throw std::runtime_error("str_encode_hex failed");
        }
    }

}
