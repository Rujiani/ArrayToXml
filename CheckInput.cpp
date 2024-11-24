#include "CheckInput.hpp"
#include <string>
namespace chk{
    std::string getStr(std::istream &ist){
        std::string result;
        ist >> result;
        if (ist.eof())
                throw std::runtime_error("Failed: EOF reached unexpectedly");
        if (ist.bad())
            throw std::runtime_error("Failed to read string: " + std::string(std::strerror(errno)));
        if (ist.fail()) {
            ist.clear();
            throw std::runtime_error("Failed: Stream is in a bad state");
        }
        return result;
    } 
}