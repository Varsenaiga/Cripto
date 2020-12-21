#include <fstream>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>

#include "seal/seal.h"

#include "encryptions/database/database_encryption.h"
#include "encryptions/data/data_encryption.h"

using namespace std;

string get_client_input();