#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void insertion_sort(vector<T>& arr)
{
    int size = arr.size();
    for (int i=1;i<size;i++)
    {
        int key = arr.at(i);
        int j = i-1;
        while(j>-1 && arr.at(j)>key)
        {
            arr.at(j+1)  = arr.at(j);
            j=j-1;
        }
        arr.at(j+1) = key;
    }
}
