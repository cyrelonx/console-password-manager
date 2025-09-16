#include "classess.h"

string xorEncryptDecrypt(const string& text, char key)
{
    string output = text;
    for (char& c : output)
    {
        c ^= key;
    }
    return output;
}

void PasswordManager::addAccount(const string& service, const string& name, const string& password)
{
    int newID = nextID++;
    accounts.push_back(Account(newID, service, name, password));

    cout << "\nAccount successfully created!\nService: " << service << "\nName: " << name << "\nPassword: " << password << "\n\n";
}

void PasswordManager::deleteAccount(int id)
{
    auto it = find_if(accounts.begin(), accounts.end(),
                [id](const Account& acc) { return acc.getID() == id; });

    if (it != accounts.end())
    {
        accounts.erase(it);
        cout << "Account successfully deleted!\n";
    }
    else
        cout << "Account not found!\n";
}

void PasswordManager::searchAccount(const string& service)
{
    bool found = false;
    for (const auto& acc : accounts)
    {
        if (acc.getServiceName() == service)
        {
            cout << "# " << acc.getID() << " " << acc.getServiceName() << "\nUser: " << acc.getUsername() << "\nPassword: " << acc.getPassword() << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "Can't find any accounts with that service!\n";
}

void PasswordManager::listAccounts()
{
    if (accounts.empty())
        cout << "Can't find any accounts!\n";
    else
    {
        cout << "\nLIST OF ALL ACCOUNTS\n";
        for (const auto& acc : accounts)
        {
            cout << "#" << acc.getID() << " " << acc.getUsername() << " - " << acc.getServiceName() << " - " << acc.getPassword() << "\n\n";
        }
    }
}

void PasswordManager::saveToFile()
{
    ofstream out("accounts.txt");
    if (!out)
    {
        cout << "Error opening file accounts.txt!\n";
        return;
    }

    for (const auto& acc : accounts)
    {
        out << acc.getID() << ";"
            << acc.getServiceName() << ";"
            << acc.getUsername() << ";"
            << xorEncryptDecrypt(acc.getPassword()) << "\n";
    }

    out.close();
}

void PasswordManager::loadFromFile()
{
    ifstream in("accounts.txt");
    if (!in)
    {
        cout << "Error opening file accounts.txt!\n";
        return;
    }

    accounts.clear();
    nextID = 1;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string idStr, service, name, passwd;

        getline(ss, idStr, ';');
        getline(ss, service, ';');
        getline(ss, name, ';');
        getline(ss, passwd, ';');

        int id = stoi(idStr);
        accounts.push_back(Account(id, service, name, xorEncryptDecrypt(passwd)));

        if (id >= nextID)
            nextID = id + 1;
    }

    in.close();
}