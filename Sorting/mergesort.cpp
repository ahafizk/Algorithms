#include<iostream>
#include<vector>
using namespace std;
/*
 * to sort an array -> A, run the code $ merge_sort(A,0, A.length - 1)
*/


template<typename T>
int merge(vector<T>&arr, int p, int q, int r)
{
    int n1 = q - p + 1; //left array size
    int n2 = r - q; //right array size
    vector<T>L,R;
    for (int i=0;i<n1;i++)
    {
        L.push_back(arr.at(p+i));

    }
    //copy the right subarray
    for(int j=0;j<n2;j++)
    {
        R.push_back(arr.at(q+j+1));
    }

    //get two iterator for two subarray
    int i=0,j=0,k=0;
    for (;k<r;k++)
    {
        //breaks the loop if any of the array (L or R) reached to its end
        if (j>=n2 || i>=n1)break;

        if (i<n1 && j<n2 && L.at(i)<=R.at(j))
        {
            arr.at(k) = L.at(i);
            i++;
        }
        else if (j<n2)
        {
            arr.at(k) = R.at(j);
            j++;
        }

    }

    //copy rest of L or R to arr
    while(i<n1)
    {
        arr.at(k)= L.at(i);
        i++;
        k++;
    }
    while(j<n2)
    {
       arr.at(k)= R.at(i);
       i++;
       k++;
    }
    return 0;
}

template<typename T>
void merge_sort(vector<T> &arr, int p, int r)
{
    if (p<r)
    {
        int q = (p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
