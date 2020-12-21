#include <iostream>
#include <string.h>
#include "encryptions.h"
#include "../Client/encryptions/database/database_encryption.h"

using namespace std;

void generate_root_ca()
{
    system("cd .. && sudo rm -r Proj");
    system("cd .. && sudo mkdir Proj");
    system("cd .. && sudo mkdir Proj/CA");
    system("cd ../Proj/CA && sudo openssl genrsa -out root-ca.key 2048");
    system("cd ../Proj/CA && sudo openssl req -new -x509 -days 3650 -key root-ca.key -out root-ca.crt");
}

void create_server_folder()
{
    string serverfolder;
    string command;
    string openserverfolder;

    command = "sudo mkdir "; //create a directory
    serverfolder = "../Proj/Server/";
    command.append(serverfolder);
    system(command.c_str());
}

void server_privatekey()
{
    string serverfolder;
    string command;
    string openserverfolder;

    openserverfolder = "cd "; //open the directory
    serverfolder = "../Proj/Server/";
    openserverfolder.append(serverfolder);
    command = " && sudo openssl genrsa -out server-key.pem 1024";
    openserverfolder.append(command);
    system(openserverfolder.c_str());
}

void server_certificate()
{
    string serverfolder;
    string command;
    string openserverfolder;
    string servercertdata;

    openserverfolder = "cd "; //open the directory
    serverfolder = "../Proj/Server/";
    openserverfolder.append(serverfolder);
    command = " && sudo openssl req -new -key server-key.pem -out server-cert.csr -subj ";
    openserverfolder.append(command);
    servercertdata = "/C=LX/ST=Portugal/L=Lisbon/O=CSC/OU=CProject/CN=server";
    openserverfolder.append(servercertdata);
    system(openserverfolder.c_str());
}

void install_server_root_CA()
{
    string command1;
    string command2;
    string command3;
    string rootfolder = "../CA/";
    string serverfolder = "../Proj/Server/";
    string rootkey = "root-ca.key";

    command1 = "sudo cp ../Proj/CA/root-ca.crt ../Proj/Server/";
    system(command1.c_str());
    command2 = "cd ";
    command2.append(serverfolder);
    command2.append(" && sudo openssl x509 -req -in server-cert.csr -out server-cert.crt -sha1 -CA root-ca.crt -CAkey ");
    command2.append(rootfolder);
    command2.append(rootkey);
    command2.append(" -CAcreateserial -days 3650");
    system(command2.c_str());
    command3.append("cd ");
    command3.append(serverfolder);
    command3.append(" && sudo openssl x509 -in server-cert.crt -out server-cert.pem -outform PEM");
    system(command3.c_str());
}

void create_client_folder(int client)
{
    string clientfolder;
    string serverfolder;
    string command1;
    string command2;
    string openclientfolder;
    string openserverfolder;

    command1 = "sudo mkdir "; //create a directory
    clientfolder = "../Proj/Clients/";
    clientfolder.append(to_string(client + 1));
    command1.append(clientfolder);
    system(command1.c_str());

    command2 = "sudo mkdir "; //create a directory
    serverfolder = "../Proj/Server/";
    serverfolder.append(to_string(client + 1));
    command2.append(serverfolder);
    system(command2.c_str());
}

void client_privatekey(int client)
{
    string clientfolder;
    string command;
    string openclientfolder;

    openclientfolder = "cd "; //open the directory
    clientfolder = "../Proj/Clients/";
    clientfolder.append(std::to_string(client + 1));
    openclientfolder.append(clientfolder);
    command = " && sudo openssl genrsa -out client-key.pem 1024";
    openclientfolder.append(command);
    system(openclientfolder.c_str());
}

void client_certificate(int client)
{
    string clientfolder;
    string command;
    string openclientfolder;
    string clientcertdata;

    openclientfolder = "cd "; //open the directory
    clientfolder = "../Proj/Clients/";
    clientfolder.append(to_string(client + 1));
    openclientfolder.append(clientfolder);
    command = " && sudo openssl req -new -key client-key.pem -out client-cert.csr -subj ";
    openclientfolder.append(command);
    clientcertdata = "/C=LX/ST=Portugal/L=Lisbon/O=CSC/OU=CProject/CN=client";
    clientcertdata.append(std::to_string(client + 1));
    openclientfolder.append(clientcertdata);
    system(openclientfolder.c_str());
}

void extract_pubkey(int client)
{
    string clientfolder;
    string command;
    string openclientfolder;

    openclientfolder = "cd "; //open the directory
    clientfolder = "../Proj/Clients/";
    clientfolder.append(to_string(client + 1));
    openclientfolder.append(clientfolder);
    command = " && sudo sh -c \"sudo openssl x509 -pubkey -noout -in client-cert.pem > client-pubkey.pem\"";
    openclientfolder.append(command);
    system(openclientfolder.c_str());
}

void install_client_root_CA(int client)
{
    string command1;
    string command2;
    string command3;
    string rootfolder = "../../CA/";
    string clientfolder = "../Proj/Clients/";
    string rootkey = "root-ca.key";

    command1 = "sudo cp ../Proj/CA/root-ca.crt ../Proj/Clients/";
    command1.append(to_string(client + 1));
    system(command1.c_str());
    command2 = "cd ";
    command2.append(clientfolder);
    command2.append(to_string(client + 1));
    command2.append(" && sudo openssl x509 -req -in client-cert.csr -out client-cert.crt -sha1 -CA root-ca.crt -CAkey ");
    command2.append(rootfolder);
    command2.append(rootkey);
    command2.append(" -CAcreateserial -days 3650");
    system(command2.c_str());
    command3.append("cd ");
    command3.append(clientfolder);
    command3.append(to_string(client + 1));
    command3.append(" && sudo openssl x509 -in client-cert.crt -out client-cert.pem -outform PEM");
    system(command3.c_str());
}

void install_client_server_CA(int client)
{
    string command;

    command = "sudo cp ../Proj/Server/server-cert.crt ../Proj/Clients/";
    command.append(to_string(client + 1));
    system(command.c_str());
}

void install_server_client_CA(int client)
{
    string command1;
    string command2;
    string clientfolder = "../Proj/Clients/";
    string serverfolder = "../Proj/Server/";

    clientfolder.append(to_string(client + 1));
    serverfolder.append(to_string(client + 1));
    command1 = "sudo cp ";
    command1.append(clientfolder);
    command1.append("/client-cert.crt ");
    command1.append(serverfolder);
    system(command1.c_str());
    command2 = "sudo cp ";
    command2.append(clientfolder);
    command2.append("/client-pubkey.pem ");
    command2.append(serverfolder);
    system(command2.c_str());
}

int main()
{
    generate_root_ca();
    create_server_folder();
    server_privatekey();
    server_certificate();
    install_server_root_CA();
    db_key();

    system("sudo mkdir ../Proj/Clients");
    for (int i = 0; i < 3; i = i + 1)
    {
        create_client_folder(i);
        client_privatekey(i);
        client_certificate(i);
        install_client_root_CA(i);
        install_client_server_CA(i);
        extract_pubkey(i);
        install_server_client_CA(i);
    }
}
