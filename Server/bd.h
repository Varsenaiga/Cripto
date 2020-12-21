#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <fstream>

using namespace std;

struct table;

std::vector<std::string> separatewords(string &mystr, string &delimeter1, string &delimeter2, string &delimeter3);

table createtable(int ncols, string &table_name, std::vector<std::string> col_names, int id);

table insertrow(std::vector<std::string> val, table tb);

table deleterow(int row, table tb);

std::vector<string> selectrow(int nline, table tb);

void write_file(std::vector<std::string> matrix, int nlin, int ncols);

std::vector<std::string> read_command();

int find_table(vector<table> vect, std::string table_name, int size);

void execute_command(vector<string> command, vector<table> table_vect, int c);

int find_col(table tb, std::string table_name);

Ciphertext sum_query(string target_add, string col_name, string col1, string bit_pick1s, string target1, string mode, string col2, string bit_pick2, string target2, table tb);

void write_cipher(Ciphertext result);
