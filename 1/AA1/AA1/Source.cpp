#include "Utils.h"
#include "Data_structs.h"

int main() {
    rapidxml::xml_document<> doc;
    std::ifstream file;
    file.open("files/config.xml"); // Replace with your XML file path
    if (!file.is_open()) {
       return 1;
    }

    // Llegir i parsejar
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    file.close();

    //ficant el nom del node puc accedir directament a aquell node especific
    for (rapidxml::xml_node<>* enemyNode = doc.first_node("enemies")->first_node("enemy"); enemyNode; enemyNode = enemyNode->next_sibling()) {
        Enemy enemies;

        //Aconseguir atributs a partir de stoi (string to int) 
        enemies.name = enemyNode->first_node("Name")->value();
        enemies.attack = std::stoi(enemyNode->first_node("attack")->value());
        enemies.defense = std::stoi(enemyNode->first_node("defense")->value());
        enemies.experience = std::stoi(enemyNode->first_node("Experience")->value());
        enemies.atk_rate = std::stoi(enemyNode->first_node("attack_rate_per_second")->value());

        //Bucle per ajuntar
        for (rapidxml::xml_node<>* weaponNode = enemyNode->first_node("weapons")->first_node("weapon"); weaponNode; weaponNode = weaponNode->next_sibling()) {
            Weapon weaponry;

            //Parsejo atributs
            weaponry.id = std::stoi(weaponNode->first_node("ID")->value());
            weaponry.type = weaponNode->first_node("type")->value();
            weaponry.range = weaponNode->first_node("range")->value();

            enemies.myweapon.push_back(weaponry);
        }

        myenemies.push_back(enemies);
    }

    //Printem les dades guardades en el struct
    for (const Enemy& enemy : myenemies) {
        std::cout << "Name: " << enemy.name << std::endl;
        std::cout << "Attack: " << enemy.attack << std::endl;
        std::cout << "Defense: " << enemy.defense << std::endl;
        std::cout << "Experience: " << enemy.experience << std::endl;
        std::cout << "Attack rate: " << enemy.atk_rate << std::endl;
        std::cout << "Weapons: " << std::endl;

        for (const Weapon& weapon : enemy.myweapon) {
            std::cout << "  Id: " << weapon.id << std::endl;
            std::cout << "  Type: " << weapon.type << std::endl;
            std::cout << "  Range: " << weapon.range << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
