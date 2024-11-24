#include <exception>
#include <iostream>
#include <stdexcept>
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
    for(size_t i = 0; i < msgs.size(); ++i) 
        std::cout << i + 1 << ". " << msgs[i] << std::endl;
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
                    array.reserve(size);
                    std::cout << "Input array's elements\n>>> ";
                    for(size_t i = 0; i < size; ++i) array.push_back(chk::getNum<int>());
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
                    for(int i = 0; i < array.size(); ++i){
                        if(i) std::cout << " ";
                        std::cout << array[i];
                    }
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