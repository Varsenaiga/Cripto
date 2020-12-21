#include <iostream>
#include <string.h>

using namespace std;

void encrypt_file(string filepath, string filename, string crtpath);
void decrypt_file(string filepath, string filename, string keypath);
void sign_file(string filepath, string keypath, int client);
void verify_file(string filepath, int client);