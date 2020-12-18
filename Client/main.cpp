#include <iostream>

#include "main.h"

int main()
{
    int buffer;
    int **data = nullptr;
    Ciphertext **cypher;
    Ciphertext **bitM;

    db_key();

    int lines = 4;
    int columns = 3;

    allocate_data(data, cypher, bitM, lines, columns);

    data_encryption(data, cypher, bitM, lines, columns);

    data_decryption(cypher, bitM, lines, columns, data);

    data_destructor(data, cypher, bitM, lines, columns);

    return buffer;
}