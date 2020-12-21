#include "bd.h"
#include "processing/data_processing.h"

struct table
{
        int nlines;
        int ncols;
        int id;
        std::string table_name;
        std::vector<char *> col_names;
        Ciphertext **data;
        Ciphertext **bits;
};

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

table createtable(int ncols, string &table_name, std::vector<std::string> col_names, int id)
{

        //newstruct
        table newtable;

        //Fill the table with the information known
        newtable.nlines = 0;
        newtable.ncols = ncols;
        newtable.id = id;
        newtable.table_name = table_name;
        newtable.col_names.resize(ncols);
        newtable.col_names[0] = "Row";

        for (int i = 1; i < ncols; i++)
        {
                newtable.col_names.resize(i + 1);
                const char *a = col_names[i - 1].c_str();
                char b[col_names[i - 1].size()];
                std::strcpy(b, a);
                newtable.col_names[i] = b;
        }
        //pointer to data matrix
        newtable.data = {};
        newtable.bits = {};

        return newtable;
}

table insertrow(Ciphertext *val, Ciphertext **bits, table tb)
{

        int bit_line = 0;

        if (tb.nlines == 0)
        {
                tb.data = new Ciphertext[1];
                tb.data[0] = new Ciphertext[tb.ncols];

                tb.bits = new Ciphertext[tb.ncols];
                for (int i = 0; i < tb.ncols; ++i)
                        tb.bits[i] = new Ciphertext[8];
        }
        else
        {
                tb.nlines++;
                tb.bits.resize(tb.ncolstb.nlines);
                for (int j = 0; j < tb.ncols; j++)
                        tb.data[j]->resize(tb.nlines);
                tb.bits[tb.nlines + j]->resize(8);
        }

        //Id's on the first col
        tb.data[tb.nlines][1] = tb.nlines + 1;
        //Fill the remaining cols with the data
        for (int i = 1; i < tb.ncols + 1; ++i)
        {
                std::string v = val[i - 1];
                tb.data[tb.nlines][i] = v;
        }
        //Fill the bits matrix
        for (int i = 0; i < tb.ncols; ++i)
        {
                bit_line = tb.nlinestb.ncols + i;
                for (int j = 0; j < 8; j++)
                        tb.bits[bit_line][i] = bits[i][j];
        }
        return tb;
}

table deleterow(int row, table tb)
{
        if (row == tb.nlines)
        {
                delete[] tb.data[row];
                tb.data = {};
                for (int j = 0; j < tb.ncols; j++)
                {
                        delete[] tb.bits[j];
                }
                tb.bits = {};
        }
        else
        {
                for (int i = row + 1; i < tb.nlines; i++)
                {
                        for (int j = 0; j < tb.ncols; j++)
                        {
                                tb.data[i - 1][j] = tb.data[i][j];
                        }
                }
                delete[] tb.data[nlines - 1];

                for (int i = 0; i < tb.ncols; ++i)
                {
                        bit_line = tb.nlinestb.ncols + i;
                        for (int i = bit_line + tb.ncols; i < (tb.nlinestb.ncols); i++)
                        {
                                for (int j = 0; j < 8; j++)
                                {
                                        tb.bits[i - tb.ncols][j] = tb.bits[i][j];
                                }
                        }
                }
                for (int k = ((tb.nlines - 1) tb.ncols); k < (tb.nlinestb.ncols); k++)
                        delete[] tb.bits[k];
        }
        tb.nlines--;
        return tb;
}

Ciphertext *selectrow(int nline, table tb)
{

        Ciphertext *result;
        //the first colum is the indexes column
        for (int j = 1; j < tb.ncols; j++)
        {
                result[j - 1] = tb.data[nline][j];
        }
        bit_line = nlines * tb.ncols;
        for (int j = 0; j < tb.ncols; j++)
        {
                result[j + tb.ncols] = tb.bits[bit_line + j];
        }
        return result;
}

void write_file(Ciphertext **matrix, int nlin, int ncols)
{
        std::fstream output;
        output.open("response.txt", std::fstream::out);

        output << nlin << std::endl;
        output << ncols << std::endl;
        for (int i = 0; i < nlin; i++)
        {
                for (int j = 0; j < ncols; j++)
                {
                        output << matrix[i][j] << " ";
                }
                output << std::endl;
        }
        for (int i = 0; i < (nlin * ncols); i++)
        {
                for (int j = 0; j < 8; j++)
                {
                        output << bits[i][j];
                }
                output << std::endl;
        }
        output.close();
}

std::vector<std::string> read_command()
{
        //read request
        std::string com;
        int count = 0;
        std::vector<std::string> command;
        std::ifstream datafile;

        datafile.open("command.txt");

        if (datafile.is_open())
        {
                while (!datafile.eof())
                {
                        std::getline(datafile, com);
                        command.resize(++count);
                        command[count - 1] = com;
                }
        }

        datafile.close();
        return command;
}

int find_table(vector<table> vect, std::string table_name, int size)
{
        int index = -1;
        for (int i = 0; i < size; i++)
        {
                if ((vect[i].table_name).compare(table_name) == 0)
                {
                        index = i;
                }
        }
        return index;
}

void execute_command(vector<string> command, vector<table> table_vect, int c)
{

        int count = 0, write = 0, len = 0, index = 0, pos = 0;
        std::string mystr = command[1];
        std::vector<string> result;
        std::string del1 = "TABLE";
        std::string del2 = "(";
        std::string del3 = ", ";
        std::string del4 = ")";
        std::string del5 = " LINE ";
        std::string del6 = " FROM ";
        std::string del7 = "WHERE";
        std::string del8 = " ";
        if (c < 3)
        {
                len = mystr.find(del2) - del2.length() - mystr.find(del1) - del1.length();
                std::string table_name = mystr.substr(mystr.find(del1) + del1.length(), len);
                std::cout << "table_name:" << table_name << std::endl;
                std::vector<std::string> col_names = separatewords(mystr, del2, del3, del4);
                std::cout << "size:" << col_names.size() << std::endl;
                for (int i = 0; i < col_names.size(); i++)
                        std::cout << "col_names:" << col_names[i] << std::endl;
                //Create and add new element
                int id = command[0][0] - '0';
                if (c == 1)
                        table_vect.emplace_back(createtable(col_names.size() + 1, table_name, col_names, id)); //CREATE
                if (c == 2)
                { //INSERT
                        mystr.erase(0, mystr.find(del4) + del4.length());
                        std::vector<std::string> cols = separatewords(mystr, del2, del3, del4);
                        for (int k = 0; k < cols.size(); k++)
                                std::cout << "cols" << cols[k] << std::endl;
                        index = find_table(table_vect, table_name, table_vect.size());
                        std::cout << "index" << index << std::endl;
                        table_vect[index] = insertrow(cols, table_vect[index]);
                }
        }
        if (c > 2 && c < 5)
        {
                int len = mystr.find(del6) - del6.length() - mystr.find(del5);
                std::string line = mystr.substr(mystr.find(del5) + del5.length(), len);
                std::cout << "line" << line << std::endl;
                std::string table_name = mystr.substr(mystr.find(del6) + del6.length(), std::string::npos);
                std::cout << "name" << table_name << std::endl;
                index = find_table(table_vect, table_name, table_vect.size());
                if (c == 3)
                { //DELETE
                        table_vect[index] = deleterow(stoi(line), table_vect[index]);
                        //write_file(table_vect[index].data, table_vect[index].nlines, table_vect[index].ncols);
                }
                if (c == 4)
                { //SELECT
                        result = selectrow(stoi(line), table_vect[index]);
                        //write_file(result, 1, result.size());
                }
        }
        if (c == 5)
        {
                len = mystr.find(del4) - del4.length() - mystr.find(del2);
                std::string col_name = mystr.substr(mystr.find(del2) + del2.length(), len);
                len = mystr.find(del7) - del7.length() - mystr.find(del6);
                std::string table_name = mystr.substr(mystr.find(del6) + del6.length() - 1, len);

                std::vector<std::string> pal;
                pal.push_back(col_name);
                pal.push_back(table_name);
                mystr.erase(0, mystr.find(del7) + del7.length() + 1);

                count = 0;
                while ((pos = mystr.find(del8)) != std::string::npos)
                {
                        pal.push_back(mystr.substr(0, mystr.find(del8)));
                        mystr.erase(0, pos + del8.length());
                }
                pal.push_back(mystr);
                for (int i = 0; i < pal.size(); i++)
                        std::cout << "pal:" << pal[i] << std::endl;
                Ciphertext sum = sum_query(pal[0], pal[1], pal[2], pal[3], pal[4], pal[5], pal[6], pal[7], pal[8]);
                write_cipher(sum);
        }
}

Ciphertext sum_query(string target_adds, string col_name, string col1, string bit_pick1s, string target1, string mode, string col2, string bit_pick2, string target2, table tb)
{
        Ciphertext sum1;
        Ciphertext sum2;
        ifstream pb_file;
        PublicKey db_pubkey;

        if (bit_pick1s[0] == '>')
        {
                bit_pick1 = 0;
        }
        else if (bit_pick1s[0] == '<')
        {
                bit_pick1 = 2;
        }
        else
        {
                bit_pick1 = 1;
        }
        if (bit_pick2s[0] == '>')
        {
                bit_pick2 = 0;
        }
        else if (bit_pick2s[0] == '<')
        {
                bit_pick2 = 2;
        }
        else
        {
                bit_pick2 = 1;
        }
        int target1 = target1s - '0';
        int target2 = target2s - '0';
        int target_add = target_adds - '0';

        col0 = find_col(tb, col_name);
        col1 = find_col(tb, col1);
        col2 = find_col(tb, col2);

        //instanciacao da encriptacao
        EncryptionParameters parms(scheme_type::bfv); //encriptacao em bfv para calculos em integers encriptados

        parms_file.open("../assets/certificates/database/parms.pem", ios::binary);
        parms.load(parms_file);
        parms_file.close();

        pb_file.open("../assets/certificates/database/db_pbkey.key", ios::binary);

        //contexto e validacao
        SEALContext context(parms);

        if (pb_file.is_open())
        {
                db_pubkey.load(context, pb_file);
                pb_file.close();
        }

        //encriptacao usando public
        Encryptor encryptor(context, db_pubkey);

        //computacao no ciphertext
        Evaluator evaluator(context);

        if (mode == "AND")
        {
        }
        else
        {
                sum1 = query_sum(tb.data, tb.bits, tb.nlines, tb.ncols, target1, col1, col0, bit_pick1);
                sum2 = query_sum(tb.data, tb.bits, tb.nlines, tb.ncols, target1, col1, col0, bit_pick1);
                evaluator.add_inplace(sum1, sum2);
                return sum1;
        }
}

int find_col(table tb, std::string table_name)
{
        int index = -1;
        for (int i = 0; i < tb.col_names.size(); i++)
        {
                if ((tb.col_names[i]).compare(table_name) == 0)
                {
                        index = i;
                }
        }
        return index;
}

void write_cipher(Ciphertext result)
{
        std::fstream output;
        output.open("response.txt", std::fstream::out);

        output << result << std::endl;

        output.close();
}

int main()
{
        int count = 0;
        std::string mystr, word;
        std::string com;
        std::vector<std::string> command;
        vector<table> table_vect;

        command = read_command();
        mystr = command[1];
        com = mystr.substr(0, mystr.find(' '));

        if (com.compare(test) == 0)
        {
                execute_command(command, table_vect, 1);
        }
        else if (com.compare("INSERT") == 0)
        {
                execute_command(command, table_vect, 2);
        }
        else if (com.compare("DELETE") == 0)
        {
                execute_command(command, table_vect, 3);
        }
        else if (com.compare("SELECT") == 0)
        {
                mystr.erase(0, mystr.find(' '));
                word = mystr.substr(0, mystr.find(' '));
                if (word.compare("SELECT") == 0)
                {
                        execute_command(command, table_vect, 4);
                }
                else
                {
                        std::cout << "escolhido SUM";
                        execute_command(command, table_vect, 5);
                }
        }
        else
                cout << "Invalid Request. Please verify your request";

        return 0;
}