#include "SortingAlgorithm.h"
#include "Credential.h"
#include"CredentialDL.h"
#include"CredentialUI.h"
#include<vector>
#include"SystemTime.h"
using namespace std;
int main()
{
    vector<Credential> record;
    vector<Credential> sortRecord;
    int option = 0;
    while (option != 5)
    {
        system("CLS");
        option = CredentialUI::mainMenu();
        if (option == 1)
        {

            record = CredentialDL::readData("organizations-100.csv");
            cout << record.size();
            CredentialUI::optionMenu(record, sortRecord);
        }
        else if (option == 2)
        {
            record = CredentialDL::readData("organizations-1000.csv");
            CredentialUI::optionMenu(record, sortRecord);
        }
        else if (option == 3)
        {
            record = CredentialDL::readData("organizations-10000.csv");
            CredentialUI::optionMenu(record, sortRecord);
        }
        else if (option == 4)
        {
            record = CredentialDL::readData("organizations-100000.csv");
            CredentialUI::optionMenu(record, sortRecord);
        }
        else if (option == 5)
        {
            record = CredentialDL::readData("organizations-500000.csv");
            CredentialUI::optionMenu(record, sortRecord);
        }
    }
};
