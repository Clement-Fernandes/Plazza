/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** saveLog
*/

#include <fstream>
#include <vector>
#include <string>

/*
enregistrer la commande dans un .log pour chaque commande finie
*/

std::vector<std::string> orders;

void extractOrders()
{
    std::ifstream file("include/.log");
    std::string extractedValues;

    for (std::size_t index = 1; file.good(); index++) {
        std::getline(file, extractedValues);
        if (extractedValues.length() != 0)
            orders.push_back(extractedValues);
            //_scoreTable.insert({extractedValues.substr(0, extractedValues.find(":")), std::stoi(extractedValues.substr(extractedValues.find(":") + 1))});
    }
}

// void saveOrder()
// {
//     std::ofstream logFile;
//     bool printed = false;

//     logFile.open ("include/.log", std::fstream::in | std::fstream::out | std::fstream::app);

//     for (auto index = orders.begin(); index != orders.end(); index++) {
//         logFile << "Order n°" << index-> std::to_string(index) + ": " + index-> << "\n";
//     }
//     scoreFile.close();
// }
