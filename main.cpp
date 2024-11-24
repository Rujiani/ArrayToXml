#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "ArrayToXml.hpp"
#include "CheckInput.hpp"

const std::vector<std::string> msgs = {
    "Input array",
    "Input xml line",
    "Convert array to xml",
    "Convert xml to array",
    "Print array",
    "Print xml",
    "Exit"
};

enum menuChose{
    Inputarr = 1,
    InputXml,
    ConvertATX,
    ConvertXTA,
    PrintArray,
    PrintXml,
    Exit
};

void PrintMsg(){
    size_t pos = 1;
    std::for_each(msgs.begin(), msgs.end(), [&pos](const std::string &str){
        std::cout << pos++ << ". " << str << std::endl;
    });
}

using namespace atx;
int main(){
    std::string xml, name, tag;
    std::vector<int> array;
    while (true) {
        try{
            PrintMsg();
            std::cout << ">>> ";
            size_t menuCh = chk::getNum<size_t>();
            switch (menuCh) {
                case Inputarr:
                {
                    array.clear();
                    std::cout << "Input name of array\n>>> ";
                    name = chk::getStr();
                    std::cout << "Input tag of array\n>>> ";
                    tag = chk::getStr();
                    std::cout << "Input size of the array\n>>> ";
                    size_t size = chk::getNum<size_t>();
                    array.resize(size);
                    std::cout << "Input array's elements\n>>> ";
                    std::generate(array.begin(), array.end(), [](){
                        return chk::getNum<int>();
                    });
                }
                break;
                
                case InputXml:
                    xml = chk::getStr();
                break;

                case ConvertATX:
                    if(array.empty()) throw std::invalid_argument("Empty array");
                    xml = array_to_xml(array, name , tag);
                    std::cout << "Done!" << std::endl;
                break;

                case ConvertXTA:
                {               
                    if(xml.empty() ) throw std::invalid_argument("Empty string");
                    auto temp_disc = xml_to_array(xml);
                    array = std::move(temp_disc.int_array);
                    name = temp_disc.name;
                    tag = temp_disc.tag;
                    std::cout << "Done!" << std::endl;
                }
                break;

                case PrintArray:
                    std::cout << "Name: " << name << "\nTag: " << tag << "\nArray:\n";
                    std::for_each(array.begin(), array.end(), [](int i){
                        std::cout << i << ' ';
                    });
                    std::cout << std::endl;
                break;

                case PrintXml:
                    std::cout << "Xml:\n" << xml << std::endl;
                break;

                case Exit:
                    std::cout << "Exiting..." << std::endl;
                    return 0;
                break;
            }
        }
        catch(const std::invalid_argument &ia){
            std::cerr << ia.what() << std::endl;
        }
        catch(std::exception &e){
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
}