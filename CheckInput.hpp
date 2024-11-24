#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

#include <cstring>
#include <iostream>
#include <string>
#include <limits>

namespace chk{
        template<class T>
        T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
                T a;
                while(true) {
                        std::cin >> a;
                        if(std::cin.eof())
                        throw std::runtime_error("Failed: EOF");
                        else if(std::cin.bad())
                        throw std::runtime_error(std::string("Failed to read number: ") + std::strerror(errno));
                        else if(std::cin.fail() || a < min || a > max) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "You are wrong; repeat please!" << std::endl;
                        }
                        else 
                        return a;
                }
        }

        std::string getStr(std::istream &ist = std::cin);
}
#endif