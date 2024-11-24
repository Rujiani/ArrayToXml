#ifndef ARRAY_TO_XML
#define ARRAY_TO_XML

#include <string>
#include <vector>

namespace atx{
    struct array_descriptor{
        const std::vector<int> int_array;
        std::string name, tag;
    };

    std::string array_to_xml(const std::vector<int> &array, const std::string &name, const std::string &tag);
    std::string array_to_xml(const array_descriptor &ad);

    array_descriptor xml_to_array(const std::string xml);
    array_descriptor xml_to_array(const char* xml);
    array_descriptor xml_to_array(const char* xml, size_t size);
}

#endif