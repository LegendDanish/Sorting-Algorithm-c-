
#include<iostream>
#include"Credential.h"
#include <vector>
#include<string>
#include<fstream>
#include"queue"
#include<cmath>
#pragma once
using namespace std;

class CredentialDL
{
 public:
    static vector<Credential> readData(string path)
    {
        vector<Credential> record;
        ifstream myFile;
        myFile.open(path,ios::in);
        string line;
        getline(myFile, line);
        while (myFile.good())
        {
            
            getline(myFile, line);
            if (!line.empty())
            {
                int index = stoi(parse(line, 1));
                string organizationID = parse(line, 2);
                string name = parse(line, 3);
                string website = parse(line, 4);
                string country = parse(line, 5);
                string description = parse(line, 6);
                int founded = stoi(parse(line, 7));
                string industry = parse(line, 8);
                int noOfEmployees = stoi(parse(line, 9));
                Credential cre(index, founded, noOfEmployees, organizationID, name, website, country, description, industry);
                record.push_back(cre);
               
            }
            else
            {
                myFile.close();
            }
        }
        myFile.close();
        return record;
    }


    static string parse(string line, int find)
    {
        bool flag = true;
        string parse = "";
        int commas = 1;
        int count = 0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == ',')
            {
                if (flag)
                {
                    commas++;
                }
            }
            else if (commas == find)
            {
                parse = parse + line[i];
            }
            if (line[i] == '"')
            {
                flag = false;
                count++;
            }
            if (count == 2)
            {
                flag = true;
                count = 0;
            }

        }
        return parse;
    }

    static vector<Credential> bubbleSort(vector<Credential> record, bool flag)
    {
        int size = record.size();
        for (int x = 0; x < size - 1; x++)
        {
            bool isSwapped = false;
            for (int y = 0; y < size - x - 1; y++)
            {
                int temp1, temp2;
                if (flag)
                {
                    temp1 = record[y].index;
                    temp2 = record[y + 1].index;
                }
                else
                {
                    temp1 = record[y].noOfEmployees;
                    temp2 = record[y + 1].noOfEmployees;
                }
                if (temp1 > temp2)
                {
                    swap(record[y], record[y + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
            {
                break;
            }
        }
        return record;
    }

    static int findMinimum(vector<Credential> record, int start, int end, bool flag)
    {
        int min;
        if (flag)
        {
            min = record[start].index;
        }
        else
        {
            min = record[start].noOfEmployees;
        }

        int minIndex = start;
        for (int x = start; x < end; x++)
        {
            int temp;
            if (flag)
            {
                temp = record[x].index;
            }
            else
            {
                temp = record[x].noOfEmployees;
            }
            if (min > temp)
            {
                min = temp;
                minIndex = x;
            }
        }
        return minIndex;
    }

    static vector<Credential> selectionSort(vector<Credential> record, bool flag)
    {
        int size = record.size();
        for (int x = 0; x < size - 1; x++)
        {
            int minIndex = findMinimum(record, x, size, flag);
            swap(record[x], record[minIndex]);
        }
        return record;
    }

    static vector<Credential> insertionSort(vector<Credential> record, bool flag)
    {
        int size = record.size();
        for (int x = 1; x < size; x++)
        {
            int y, key;
            if (flag)
            {
                key = record[x].index;
                y = x - 1;
                while (y >= 0 && record[y].index > key)
                {
                    record[y + 1] = record[y];
                    y--;
                }
            }
            else
            {
                key = record[x].noOfEmployees;
                y = x - 1;
                while (y >= 0 && record[y].noOfEmployees > key)
                {
                    record[y + 1] = record[y];
                    y--;
                }
            }
            record[y + 1] = record[x];
        }
        return record;
    }
    static void mergeEmployess(vector<Credential>& arr, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        queue<Credential> tempArr;
        while (i <= mid && j <= end) {
            if (arr[i].noOfEmployees < arr[j].noOfEmployees)
            {
                tempArr.push(arr[i]);
                i++;
            }
            else
            {
                tempArr.push(arr[j]);
                j++;
            }
        }
        while (i <= mid) {
            tempArr.push(arr[i]);
            i++;
        }
        while (j <= end) {
            tempArr.push(arr[j]);
            j++;
        }
        for (int x = start; x <= end; x++) {
            arr[x] = tempArr.front();
            tempArr.pop();
        }
    }
    static void mergeIndex(vector<Credential>& arr, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        queue<Credential> tempArr;
        while (i <= mid && j <= end) {
            if (arr[i].index < arr[j].index)
            {
                tempArr.push(arr[i]);
                i++;
            }
            else
            {
                tempArr.push(arr[j]);
                j++;
            }
        }
        while (i <= mid) {
            tempArr.push(arr[i]);
            i++;
        }
        while (j <= end) {
            tempArr.push(arr[j]);
            j++;
        }
        for (int x = start; x <= end; x++) {
            arr[x] = tempArr.front();
            tempArr.pop();
        }
    }
    static void mergeSort(vector<Credential>& arr, int start, int end, bool flag)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid, flag);
            mergeSort(arr, mid + 1, end, flag);
            if (flag) {
                mergeIndex(arr, start, mid, end);
            }
            else {
                mergeEmployess(arr, start, mid, end);
            }
        }
    }

    static int partitionIndex(vector<Credential>& arr, int start, int end, int pivot)
    {
        int left = start;
        int right = end;
        while (left <= right)
        {
            while (left <= end && arr[left].index < arr[pivot].index)
                left++;
            while (right >= start && arr[right].index >= arr[pivot].index)
                right--;
            if (left < right)
                swap(arr[left], arr[right]);
        }
        swap(arr[right], arr[pivot]);
        return right;
    }

    static int partitionEmployees(vector<Credential>& arr, int start, int end, int pivot)
    {
        int left = start;
        int right = end;
        while (left <= right)
        {
            while (left <= end && arr[left].noOfEmployees < arr[pivot].noOfEmployees)
                left++;
            while (right >= start && arr[right].noOfEmployees >= arr[pivot].noOfEmployees)
                right--;
            if (left < right)
                swap(arr[left], arr[right]);
        }
        swap(arr[right], arr[pivot]);
        return right;
    }
    static void quickSort(vector<Credential>& arr, int start, int end, bool flag)
    {
        if (start < end)
        {
            int pivot = start;
            int mid;
            if (flag)
            {
                mid = partitionIndex(arr, start + 1, end, pivot);
            }
            else {
                mid = partitionEmployees(arr, start + 1, end, pivot);
            }
            quickSort(arr, start, mid - 1, flag);
            quickSort(arr, mid + 1, end, flag);
        }
    }

    static int parentIndex(int i)
    {
        return (i - 1) / 2;
    }
    static int leftChildIndex(int i)
    {
        return (2 * i) + 1;
    }
    static int rightChildIndex(int i)
    {
        return (2 * i) + 2;
    }
    static void swap(Credential& a, Credential& b)
    {
        Credential temp = a;
        a = b;
        b = temp;
    }

    static void heapifyIndex(vector<Credential>& heapArr, int size, int index) {
        int maxIndex;
        while (true) {
            int lIdx = leftChildIndex(index);
            int rIdx = rightChildIndex(index);
            if (rIdx >= size) {
                if (lIdx >= size)
                    return;
                else
                    maxIndex = lIdx;
            }
            else {
                if (heapArr[lIdx].index >= heapArr[rIdx].index)
                    maxIndex = lIdx;
                else
                    maxIndex = rIdx;
            }
            if (heapArr[index].index < heapArr[maxIndex].index) {
                swap(heapArr[index], heapArr[maxIndex]);
                index = maxIndex;
            }
            else
                return;
        }
    }

    static void heapifyEmployess(vector<Credential>& heapArr, int size, int index) {
        int maxIndex;
        while (true) {
            int lIdx = leftChildIndex(index);
            int rIdx = rightChildIndex(index);
            if (rIdx >= size) {
                if (lIdx >= size)
                    return;
                else
                    maxIndex = lIdx;
            }
            else {
                if (heapArr[lIdx].noOfEmployees >= heapArr[rIdx].noOfEmployees)
                    maxIndex = lIdx;
                else
                    maxIndex = rIdx;
            }
            if (heapArr[index].noOfEmployees < heapArr[maxIndex].noOfEmployees) {
                swap(heapArr[index], heapArr[maxIndex]);
                index = maxIndex;
            }
            else
                return;
        }
    }

    static void heapSort(vector<Credential>& heapArr, int size, bool flag)
    {
        for (int x = (size / 2) - 1; x >= 0; x--)
        {
            if (flag)
            {
                heapifyIndex(heapArr, size, x);
            }
            else {
                heapifyEmployess(heapArr, size, x);
            }
        }
        for (int x = size - 1; x > 0; x--)
        {
            swap(heapArr[0], heapArr[x]);
            if (flag)
            {
                heapifyIndex(heapArr, x, 0);
            }
            else {
                heapifyEmployess(heapArr, x, 0);
            }
        }
    }
    static bool writeDataToFile(vector<Credential> record, string path)
    {
        ofstream myFile;
        myFile.open(path, ios::out);
        myFile << "index" << "," << " Organization ID" << "," << "Name" << "," << "Website" << "," << "Country" << "," << "Description" << "," << "Founded" << "," << "Industry" << "," << "No of Employees" << endl;

        for (int i = 0; i < record.size(); i++)
        {
            myFile << record[i].index << "," << record[i].organizationID << "," << record[i].name << "," << record[i].website << ","
                << record[i].country << "," << record[i].description << "," << record[i].founded << "," << record[i].industry << "," << record[i].noOfEmployees << endl;
        }
        myFile.close();
        return true;
    }

    static int max(vector<Credential> arr, bool flag)
    {
        int max;
        if (flag)
        {
            max = arr[0].index;
        }
        else
        {
            max = arr[0].noOfEmployees;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            int value;
            if (flag)
            {
                value = arr[i].index;
            }
            else
            {
                value = arr[i].noOfEmployees;
            }
            if (max < value)
            {
                max = value;
            }
        }
        return max;
    }

    static int min(vector<Credential> arr, bool flag)
    {
        int min;
        if (flag)
        {
            min = arr[0].index;
        }
        else
        {
            min = arr[0].noOfEmployees;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            int value;
            if (flag)
            {
                value = arr[i].index;
            }
            else
            {
                value = arr[i].noOfEmployees;
            }
            if (min > value)
            {
                min = value;
            }
        }
        return min;
    }


    static void countingSortIndex(vector<Credential>& arr, int place, bool radix)
    {
        int range = 0, maximum = 0, minimum = 0;
        if (radix)
        {
            range = 10;
        }
        else
        {
            maximum = max(arr, true);
            minimum = min(arr, true);
            range = maximum - minimum + 1;
        }

        vector<int> count(range);
        vector<Credential> output(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {
            if (radix)
            {
                count[((arr[i].index / place) % 10)]++;
            }
            else
            {
                count[arr[i].index - minimum]++;
            }
        }
        for (int i = 1; i < count.size(); i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--)
        {

            if (radix)
            {
                output[count[((arr[i].index / place) % 10)] - 1] = arr[i];
                count[((arr[i].index / place) % 10)]--;
            }
            else
            {
                output[count[arr[i].index - minimum] - 1] = arr[i];
                count[arr[i].index - minimum]--;
            }
        }
        arr = output;
    }

    static void countingSortEmployee(vector<Credential> arr, int place, bool radix)
    {
        int range = 0, maximum = 0, minimum = 0;
        if (radix)
        {
            range = 10;
        }
        else
        {
            maximum = max(arr, false);
            minimum = min(arr, false);
            range = maximum - minimum + 1;
        }
        vector<int> count(range);
        vector<Credential> output(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {
            if (radix)
            {
                count[(arr[i].noOfEmployees / place) % 10]++;
            }
            else
            {
                count[arr[i].noOfEmployees - minimum]++;
            }

        }
        for (int i = 1; i < count.size(); i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (radix)
            {
                output[count[(arr[i].noOfEmployees / place) % 10] - 1] = arr[i];
                count[(arr[i].noOfEmployees / place) % 10]--;
            }
            else
            {
                output[count[arr[i].noOfEmployees - minimum] - 1] = arr[i];
                count[arr[i].noOfEmployees - minimum]--;
            }
        }
        arr = output;
    }

    static void radixSortIndex(vector<Credential>& arr)
    {
        int maximum = max(arr, true);
        int place = 1;
        while (maximum / place > 0)
        {
            countingSortIndex(arr, place, true);
            place *= 10;
        }
    }
    static void radixSortEmployee(vector<Credential>& arr)
    {
        int maximum = max(arr, false);
        int place = 1;
        while (maximum / place > 0)
        {
            countingSortEmployee(arr, place, true);
            place *= 10;
        }
    }

    static void bucketSort(vector<Credential>& arr, bool flag)
    {
        int maximum;
        if (flag)
        {
            maximum = max(arr, true);
        }
        else
        {
            maximum = max(arr, false);
        }

        int n = ceil(sqrt(arr.size())) + 1;
        int indx = ceil((maximum + 1) / n);
        vector<vector<Credential>> bucket(maximum / indx + 1);

        for (int i = 0; i < arr.size(); i++) {
            int idx;
            if (flag)
            {
                idx = arr[i].index / indx;
            }
            else {
                idx = arr[i].noOfEmployees / indx;
            }
            bucket[idx].push_back(arr[i]);
        }

        for (int i = 0; i < bucket.size(); i++)
            if (flag)
            {
                countingSortIndex(bucket[i], 0, false);
            }
            else
            {
                countingSortEmployee(bucket[i], 0, false);
            }

        int index = 0;
        for (int i = 0; i < bucket.size(); i++)
            for (int j = 0; j < bucket[i].size(); j++)
                arr[index++] = bucket[i][j];
    }
    static void bucketSortReal(vector<Credential>&arr, bool flag)
    {
            int maximum;
            if (flag) {
                maximum = max(arr, true);
            }
            else {
                maximum = max(arr, false);
            }
            vector<vector<Credential>> bucket(maximum + 1);


            for (int i = 0; i < arr.size(); i++) {
                int idx;
                if (flag) {
                    idx = arr[i].index;
                }
                else {
                    idx = arr[i].noOfEmployees;
                }
                bucket[idx].push_back(arr[i]);
            }

            int index = 0;
            for (int i = 0; i < bucket.size(); i++)
                for (int j = 0; j < bucket[i].size(); j++)
                    arr[index++] = bucket[i][j];
    }
};
