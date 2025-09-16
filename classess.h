#ifndef CLASSESS_H
#define CLASSESS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

string xorEncryptDecrypt(const string& text, char key = 0xAA);

class Account
{
    private:
        int id;
        string serviceName, username, password;
    public:
        Account() = default;
        Account(int _id, const string& service, const string& name, const string& passwd)
            : id(_id), serviceName(service), username(name), password(passwd) {}
    
        void setID(int _id) { id = _id; }
		int getID() const { return id; }
            
        void setServiceName(const string& name) { serviceName = name; }
        string getServiceName() const { return serviceName; }
        
        void setUsername(const string& name)  { username = name; }
        string getUsername() const { return username; }
        
        void setPassword(const string& passwd) { password = passwd; }
        string getPassword() const { return password; }
};

class PasswordManager
{
    private:
        vector<Account> accounts;
        int nextID = 1;
    public:
        void addAccount(const string& service, const string& name, const string& password);

        void deleteAccount(int id);

        void searchAccount(const string& service);

        void listAccounts();

        void saveToFile();

        void loadFromFile();
};

#endif