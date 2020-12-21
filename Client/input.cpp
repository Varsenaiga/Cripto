#include <iostream>

#include "input.h"
#include "../Administrator/encryptions.h"

std::vector<std::string> separatewords(string &mystr, string &delimeter1, string &delimeter2, string &delimeter3)
{
    int i = 0, pos = 0, count = 0;
    int len = mystr.find(delimeter3) - delimeter3.length() - mystr.find(delimeter1);
    std::string token = mystr.substr((mystr.find(delimeter1) + delimeter1.length()), len);
    std::vector<std::string> cols;
    while ((pos = token.find(delimeter2)) != std::string::npos)
    {
        cols.resize(++i);
        cols[i - 1] = token.substr(0, token.find(delimeter2));
        token.erase(0, pos + delimeter2.length());
    }
    cols.resize(++i);
    cols[i - 1] = token;

    return cols;
}

string get_client_input()
{
    string mystr, command, id, query, table, buffer;
    ofstream myfile;
    int num, c;
    unsigned int i, pos = 0;
    int **data = nullptr;
    Ciphertext **cypher;
    Ciphertext **bitM;

    cout << "Client id: ";
    getline(cin, id);
    command.append(id);
    command.append("\n");
    cout << "Insert Query: ";
    getline(cin, query);
    command.append(query);
    string com = query.substr(0, query.find(' '));

    if (com.compare("CREATE") == 0)
    {
        c = 1;
    }
    else if (com.compare("INSERT") == 0)
    {
        c = 2;
    }
    else if (com.compare("DELETE") == 0)
    {
        c = 3;
    }
    else if (com.compare("SELECT") == 0)
    {
        query.erase(0, query.find(' '));
        string word = query.substr(0, query.find(' '));
        if (word.compare("SUM") == 0)
        {
            c = 5;
        }
        else
        {
            c = 4;
        }
    }
    else
    {
        cout << "Invalid Request. Please verify your request\n";
        return NULL;
    }

    int count = 0, write = 0, len = 0, index = 0;
    vector<string> result;
    string del1 = "TABLE";
    string del2 = "(";
    string del3 = ", ";
    string del4 = ")";
    string del5 = " LINE ";
    string del6 = " FROM ";
    string del7 = "WHERE";
    string del8 = " ";
    string del9 = "VALUES";
    string del10 = "INTO";

    if (c < 3)
    {
        vector<string> col_names = separatewords(query, del2, del3, del4);
        cout << "size: " << col_names.size() << endl;
        for (i = 0; i < col_names.size(); i++)
            cout << "col_names: " << col_names[i] << endl;

        //Create and add new element
        if (c == 1)
        {
            len = query.find(del2) - del2.length() - query.find(del1) - del1.length();
            string table_name = query.substr(query.find(del1) + del1.length(), len);
            cout << "table_name: " << table_name << endl;
            mystr.append(command);
        }
        else if (c == 2)
        { //INSERT
            len = query.find(del2) - del2.length() - query.find(del10) - del10.length();
            string table_name = query.substr(query.find(del10) + del10.length(), len);
            cout << "table_name:" << table_name << endl;

            cout << query.substr(0, query.find(del9)) << endl;
            mystr.append(id);
            mystr.append("\n");
            mystr.append(query.substr(0, query.find(del9)));
            mystr.append("VALUES (");

            query.erase(0, query.find(del4) + del4.length());
            vector<string> cols = separatewords(query, del2, del3, del4);

            //ENCRIPTAR DADOS guardados em data e mete-los em encr
            cout << "Chega" << endl;
            allocate_data(data, cypher, bitM, 1, cols.size());
            for (unsigned int k = 0; k < cols.size(); k++)
            {
                data[0][k] = stoi(cols[k]);
                cout << "cols: " << data[0][k] << endl;
            }
            data_encryption(data, cypher, bitM, 1, cols.size());

            string filepath = "../assets/certificates/database/";
            string filename = "data.bin";
            string crtpath = "../../../../Administrator/Proj/Clients/";
            string crname = "/client-cert.crt";
            crtpath.append(id);
            crtpath.append(crname);
            encrypt_file(filepath, filename, crtpath);
        }
    } /*else if (c > 2 && c < 5){
        int len = query.find(del6) - del6.length() - query.find(del5);
        string line = query.substr(query.find(del5) + del5.length(), len);
        cout << "line" << line << endl;
        string table_name = query.substr(query.find(del6) + del6.length(), string::npos);
        cout << "name" << table_name << endl;
        //index = find_table(table_vect, table_name, table_vect.size());
        if (c == 3){ //DELETE
            //table_vect[index] = deleterow(stoi(line), table_vect[index]);
            //write_file(table_vect[index].data, table_vect[index].nlines, table_vect[index].ncols);
        } else if (c == 4){ //SELECT
            //result = selectrow(stoi(line), table_vect[index]);
            //write_file(result, 1, result.size());
        }
    } else if (c == 5){
        len = query.find(del4) - del4.length() - query.find(del2);
        string col_name = query.substr(query.find(del2) + del2.length(), len);
        len = query.find(del7) - del7.length() - query.find(del6);
        string table_name = query.substr(query.find(del6) + del6.length() - 1, len);

        vector<string> pal;
        pal.push_back(col_name);
        pal.push_back(table_name);
        query.erase(0, query.find(del7) + del7.length() + 1);

        count = 0;
        while ((pos = query.find(del8)) != string::npos){
            pal.push_back(query.substr(0, query.find(del8)));
            query.erase(0, pos + del8.length());
        }
        pal.push_back(mystr);
        for (int i = 0; i < pal.size(); i++) cout << "pal:" << pal[i] << std::endl;
        //Ciphertext sum = sum_query(pal[0], pal[1], pal[2], pal[3], pal[4], pal[5], pal[6], pal[7], pal[8]);
        //write_cipher(sum);
    }*/

    myfile.open("command.txt");
    myfile << mystr;
    myfile.close();

    return mystr;
}
