#include<iostream>
#include<vector>
using namespace std;
template<typename T>
int partition(vector<T> &A, int start, int last)
{
    T  x = A.at(last);
    int i = start - 1;
    for (int j=start;j<last;++j)
    {
        if (A.at(j)<=x)
        {
            i++;
            T tmp = A.at(j);
            A.at(j)=A.at(i);
            A.at(i) = tmp;
        }
    }
    A.at(last) = A.at(i+1);
    A.at(i+1) = x;
    return i+1;

}

template<typename T>
void quick_sort(vector<T> &A, int start, int last)
{
    if (start<last)
    {
        int p = partition(A,start,last);
        quick_sort(A,start, p-1);
        quick_sort(A,p+1,last);
    }
}

