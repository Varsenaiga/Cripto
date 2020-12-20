#include <iostream>

#include "input.h"

string get_client_input()
{
    string mystr, id, query;
    ofstream myfile;

    std::cout << "Client id: ";
    getline(std::cin, id);
    std::cout << "Insert Query: ";
    getline(std::cin, query);
    mystr.append(id);
    mystr.append("\n");
    mystr.append(query);
    myfile.open("command.txt");
    myfile << mystr;
    myfile.close();

    return mystr;
}