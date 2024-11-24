#include "ArrayToXml.hpp"
#include <string>
#include <string_view>
#include <vector>
#include <format>

namespace atx{

    std::string array_to_xml(const std::vector<int> &array, const std::string &name, const std::string &tag){
        std::string res;
        res += std::format("<{}>", name);
        for(auto i : array) res+= std::format("<{}>{}</{}>", tag, i, tag);
        res += std::format("</{}>", name);
        return res;
    }

    std::string array_to_xml(const array_descriptor &ad){
        return array_to_xml(ad.int_array, ad.name, ad.tag);
    }

    array_descriptor xml_to_array(const std::string xml){

        size_t pos = xml.find(">");
        std::string name = xml.substr(1, pos - 1);
        pos += 2;
        std::string tag = xml.substr(pos, xml.find(">", pos) - pos);

        std::string_view temp_str(xml);
        temp_str.remove_prefix(name.size() + 2);
        temp_str.remove_suffix(name.size() + 3);
        std::vector<int> res;

        while(!temp_str.empty()){
            temp_str.remove_prefix(tag.size() + 2);
            pos = temp_str.find("<");
            res.push_back(std::stoi(std::string(temp_str.substr(0, pos))));
            temp_str.remove_prefix(pos + tag.size() + 3);
        }

        return {res, name , tag};
    }

    array_descriptor xml_to_array(const char* xml){
        return xml_to_array(std::string(xml));
    }
    
    array_descriptor xml_to_array(const char* xml, const size_t size){
        return xml_to_array(std::string(xml, size));
    }
}