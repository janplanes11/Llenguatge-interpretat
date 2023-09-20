#include <iostream>
#include <fstream>
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
        return 1; // Return a non-zero value to indicate an error
    }

    // Rest of your code here

    file.close(); // Don't forget to close the file when you're done with it
    return 0;
}
