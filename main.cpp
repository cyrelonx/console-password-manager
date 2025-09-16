#include "classess.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void printMenu()
{
    cout << "1. Create account\n2. Show all accounts\n3. Search account\n4. Delete account\n5. Save and exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    PasswordManager pwdManager;
    pwdManager.loadFromFile();
    printMenu();

    int choice;
    do
    {
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                system("cls");

                string service, name, password;
                cout << "Enter service name: ";
                cin >> service;
                cout << "Enter account name: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> password;

                pwdManager.addAccount(service, name, password);
                pwdManager.saveToFile();

                printMenu();
                break;
            }

            case 2:
            {
                system("cls");

                pwdManager.listAccounts();

                printMenu();
                break;
            }

            case 3:
            {
                system("cls");

                string query;
                cout << "Enter service name you're looking for: ";
                cin >> query;
                pwdManager.searchAccount(query);

                printMenu();
                break;
            }

            case 4:
            {
                system("cls");

                int id;
                cout << "Enter account ID: ";
                cin >> id;

                pwdManager.deleteAccount(id);
                pwdManager.saveToFile();

                printMenu();
                break;
            }

            case 5:
            {
                pwdManager.saveToFile();
                choice = 6;
                break;
            }

            default:
            {
                system("cls");
                
                cout << "Wrong choice!\n";
                printMenu();
                break;
            }
        }
    } while (choice != 6);
    return 0;
}