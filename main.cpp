#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void feltolt(vector<int> &t, int len)
{
    srand (time(NULL));
    for(int i = 0; i < len; ++i)
    {
        int x = rand() % 1000;
        t.push_back(x);
    }
}

void kiir(vector<int> t)
{
    for(unsigned i = 0; i < t.size(); ++i)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}



void insertSortNo(vector<int> &t)
{
    for(unsigned i = 1; i < t.size(); ++i)
    {
        if(t[i - 1] > t[i])
        {
            int key = t[i];
            t[i] = t[i-1];
            int j = i - 1;
            while(j >= 0 && t[j] > key)
            {
                t[j+1] = t[j];
                j--;
            }
            t[j+1] = key;
        }

        cout << i << endl;
        for(unsigned j = 0; j < t.size(); ++j)
        {
            cout << t[j] << " ";
        }
        cout << "\n" << endl;
    }
}

void insertSortCsokk(vector<int> &t)
{
    for(unsigned i = 1; i < t.size(); ++i)
    {
        if(t[i - 1] < t[i])
        {
            int key = t[i];
            unsigned j = i - 1;

            while(j >= 0 && t[j] < key)
            {
                t[j+1] = t[j];
                j--;
            }
            t[j+1] = key;
        }
    }
}


//MergeSort
void merg(vector<int> &t, int low, int mid, int high)
{
    int i, j, k, c[t.size()];
    i = low;
    k = low;
    j = mid+1;

    while(i <= mid && j <= high)
    {
        if(t[i] < t[j])
        {
            c[k] = t[i];
            k++;
            i++;
        }
        else
        {
            c[k] = t[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        c[k] = t[i];
        k++;
        i++;
    }
    while(j <= high)
    {
        c[k] = t[j];
        k++;
        j++;
    }
    for(i = low; i < k; ++i)
    {
        t[i] = c[i];
    }
}

void mergeSort(vector<int> &t, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;
        mergeSort(t,low,mid);
        mergeSort(t,mid+1,high);
        merg(t,low,mid,high);
    }
}


//QuickSort
void csere(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int particionalas(vector<int> &t, int low, int high)
{
    int pivot = t[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; ++j)
    {
        if(t[j] <= pivot)
        {
            ++i;
            csere(t[i], t[j]);
        }
    }
    csere(t[i+1], t[high]);
    return (i + 1);
}

void quickSort(vector<int> &t, int low, int high)
{
    if(low < high)
    {
        int pivot = particionalas(t,low,high);
        quickSort(t, low, pivot-1);
        quickSort(t, pivot + 1, high);
    }
}

int main()
{


    /*int len;
    cout << "Tomb merete: ";
    cin >> len;*/

    vector<int> t;
    vector<int> t2;
    vector<int> t3;
    vector<int> A = {24,9,2,7,19,28,24,12};
    vector<int> B = {8,11,3,14,5,8,12,1};
    vector<int> C = {7,3,11,4,3,9,2,5};
    cout << "InsertionSort\n";
    /*feltolt(t, len);
    kiir(t);
    insertSortNo(t);
    kiir(t);
    insertSortCsokk(t);
    kiir(t);
    cout << "Merge Sort\n";
    feltolt(t2,len);
    kiir(t2);
    mergeSort(t2,0,len);
    kiir(t2);
    cout << "QuickSort\n";
    feltolt(t3, len);
    kiir(t3);
    quickSort(t3,0,len - 1);
    kiir(t3);*/
    kiir(A);
    insertSortNo(A);
    kiir(A);

    return 0;
}
