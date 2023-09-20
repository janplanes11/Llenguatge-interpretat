#include <iostream>
#include <fstream>
#include <string>
#include "includes/rapidxml.hpp"
#include "includes/rapidxml_iterators.hpp"
#include "includes/rapidxml_print.hpp"
#include "includes/rapidxml_utils.hpp"

int main() {
    rapidxml::xml_document<> doc;
    std::ifstream file;
    file.open("files/enemies.xml");
    if (!file.is_open()) {
        std::cout << "File not opened" << std::endl;
        return 0;
    }
    else {
        std::cout << "yay its open"<<std::endl;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    file.close(); 
    return 0;
}
