#include<iostream>
#include "Credential.h"
#include "SystemTime.h"
#include "CredentialDL.h"
#pragma once
using namespace std;
class CredentialUI
{
public:
    static int mainMenu()
    {
        int option;
        cout << "1 -> Load 100 Records" << endl;
        cout << "2 -> Load 1000 Records" << endl;
        cout << "3 -> Load 10000 Records" << endl;
        cout << "4 -> Load 100000 Records" << endl;
        cout << "5 -> Load 500000 Records" << endl;
        cout << "6 -> EXIT" << endl;
        cout << "Select one option -> ";
        cin >> option;
        return option;
    }
    static int subMenu()
    {
        int option;
        cout << "1 -> Bubble Sort Algorithm" << endl;
        cout << "2 -> Insertion Sort Algorithm" << endl;
        cout << "3 -> Selection Sort Algorithm" << endl;
        cout << "4 -> Merge Sort Algorithm" << endl;
        cout << "5 -> Quick Sort Algorithm" << endl;
        cout << "6 -> Heap Sort Algorithm" << endl;
        cout << "7 -> Counting Sort Algorithm" << endl;
        cout << "8 -> Radix Sort Algorithm" << endl;
        cout << "9 -> Bucket Sort Algorithm" << endl;
        cout << "10 -> Back" << endl;
        cout << "Select one option -> ";
        cin >> option;
        return option;
    }

    static int subOfSubMenu()
    {
        int option;
        cout << "1 -> Base On Indexes" << endl;
        cout << "2 -> Base On Number Of Employess" << endl;
        cout << "3 -> Back" << endl;
        cout << "Select one option -> ";
        cin >> option;
        return option;
    }

    static void displayRecord(vector<Credential> record)
    {
        for (int i = 0; i < record.size() - 1; i++)
        {
            cout << record[i].index << " " << record[i].organizationID << " " << record[i].name << " " << record[i].country << " " << record[i].website
                << " " << record[i].founded << " " << record[i].industry << " " << record[i].description << " " << record[i].noOfEmployees << endl;
        }
    }

    static void bubbleMenu(vector<Credential> record, vector<Credential>& sortRecord)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                sortRecord = CredentialDL::bubbleSort(record, true);
            }
            else if (subOfSubOption == 2)
            {
                sortRecord = CredentialDL::bubbleSort(record, false);

            }
            else
            {
                break;
            }
            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(sortRecord, "Danish.csv");
        }
    }

    static void insertionMenu(vector<Credential> record, vector<Credential>& sortRecord)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                sortRecord = CredentialDL::insertionSort(record, true);

            }
            else if (subOfSubOption == 2)
            {
                sortRecord = CredentialDL::insertionSort(record, false);

            }
            else
            {
                break;
            }
            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(sortRecord, "Danish.csv");
        }

    }

    static void selectionMenu(vector<Credential> record, vector<Credential>& sortRecord)
    {

        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                sortRecord = CredentialDL::selectionSort(record, true);

            }
            else if (subOfSubOption == 2)
            {
                sortRecord = CredentialDL::selectionSort(record, false);
            }
            else
            {
                break;
            }
            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(sortRecord, "Danish.csv");
        }
    }

    static void mergeSortMenu(vector<Credential> record)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            int size = record.size() - 1;
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                CredentialDL::mergeSort(record, 0, size, true);

            }
            else if (subOfSubOption == 2)
            {
                CredentialDL::mergeSort(record, 0, size, false);
            }
            else
            {
                break;
            }

            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(record, "Danish.csv");
        }
    }

    static void quickSortMenu(vector<Credential> record)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            int size = record.size() - 1;
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                CredentialDL::quickSort(record, 0, size, true);

            }
            else if (subOfSubOption == 2)
            {
                CredentialDL::quickSort(record, 0, size, false);
            }
            else
            {
                break;
            }

            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(record, "Danish.csv");
        }
    }

    static void heapSortMenu(vector<Credential> record)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            int size = record.size() - 1;
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                CredentialDL::heapSort(record, size, true);

            }
            else if (subOfSubOption == 2)
            {
                CredentialDL::heapSort(record, size, false);
            }
            else
            {
                break;
            }

            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(record, "Danish.csv");
        }
    }

    static void countingSortMenu(vector<Credential> record)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                system("pause");
                CredentialDL::countingSortIndex(record, 0, false);

            }
            else if (subOfSubOption == 2)
            {
                CredentialDL::countingSortEmployee(record, 0, false);
            }
            else
            {
                break;
            }

            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(record, "Danish.csv");
        }
    }

    static void radixSortMenu(vector<Credential> record)
    {
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                CredentialDL::radixSortIndex(record);

            }
            else if (subOfSubOption == 2)
            {
                CredentialDL::radixSortEmployee(record);
            }
            else
            {
                break;
            }

            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(record, "Danish.csv");
        }
    }
    
    static void bucketSortMenu(vector<Credential> record)
    {
        
        int subOfSubOption = 0;
        while (subOfSubOption != 3)
        {
            system("CLS");
            subOfSubOption = CredentialUI::subOfSubMenu();
            system("CLS");
            SystemTime time;
            time.BeforeOperation();
            if (subOfSubOption == 1)
            {
                CredentialDL::bucketSort(record,true);
            }
            else if (subOfSubOption == 2)
            {
                CredentialDL::bucketSort(record,false);
            }
            else
            {
                break;
            }
            time.AfterOperation();
            time.TimeDifference();
            system("pause");
            CredentialDL::writeDataToFile(record, "Danish.csv");
        }
    }

    static void optionMenu(vector<Credential> record, vector<Credential>& sortRecord)
    {
        int subOption = 0;
        while (subOption != 10)
        {
            system("CLS");
            subOption = subMenu();
            if (subOption == 1)
            {
                bubbleMenu(record, sortRecord);
            }
            else if (subOption == 2)
            {
                insertionMenu(record, sortRecord);
            }
            else if (subOption == 3)
            {
                selectionMenu(record, sortRecord);
            }
            else if (subOption == 4)
            {
                sortRecord = record;
                mergeSortMenu(sortRecord);
            }
            else if (subOption == 5)
            {
                sortRecord = record;
                quickSortMenu(sortRecord);
            }
            else if (subOption == 6)
            {
                sortRecord = record;
                heapSortMenu(sortRecord);
            }
            else if (subOption == 7)
            {
                sortRecord = record;
                countingSortMenu(sortRecord);
            }
            else if (subOption == 8)
            {
                sortRecord = record;
                radixSortMenu(sortRecord);
            }
            else if (subOption == 9)
            {
                sortRecord = record;
                bucketSortMenu(record);
            }
        }
        return;
    }
};

