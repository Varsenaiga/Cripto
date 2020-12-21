#include "encryptions.h"

void encrypt_file(string filepath, string filename, string crtpath){
    string command;
    string openfilefolder;
    string encfilename = filename;

    openfilefolder = "cd ";
    openfilefolder.append(filepath);
    command = " && sudo openssl smime -encrypt -binary -aes-256-cbc -in ";
    command.append(filename);
    command.append(" -out ");
    encfilename.append(".enc");
    command.append(encfilename);
    command.append(" -outform DER ");
    command.append(crtpath);
    openfilefolder.append(command);
    system(openfilefolder.c_str());
}

void decrypt_file(string filepath, string filename, string keypath){
    string command;
    string openfilefolder;
    string encfilename = filename;

    openfilefolder = "cd ";
    openfilefolder.append(filepath);
    command = " && openssl smime -decrypt -binary -in ";
    command.append(filename);
    command.append(" -inform DER -out ");
    encfilename[encfilename.size()-3] = 'd';
    encfilename[encfilename.size()-2] = 'e';
    command.append(encfilename);
    command.append(" -inkey ");
    command.append(keypath);
    openfilefolder.append(command);
    system(openfilefolder.c_str());
}

void sign_file(string filepath, string keypath, int client){
    string command;
    string serverfolder = "../Proj/Server/";

    serverfolder.append(to_string(client));
    command = "sudo openssl dgst -sha512 -sign ";
    command.append(keypath);
    command.append(" -out ");
    command.append(serverfolder);
    command.append("/digest.sha512 ");
    command.append(filepath);
    system(command.c_str());
}

void verify_file(string filepath, int client){
    string command;
    string serverfolder = "../Proj/Server/";

    serverfolder.append(to_string(client));
    command = "cd ";
    command.append(serverfolder);
    command.append("/ && sudo openssl dgst -sha512 -verify client-pubkey.pem -signature digest.sha512 ");
    command.append(filepath);
    system(command.c_str());
}
