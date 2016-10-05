#include<iostream>
#include<vector>
using namespace std;
/*
 * to sort an array -> A, run the code $ merge_sort(A, 0, A.length - 1)
*/
template<typename T>
void print_arr(vector<T>A)
{
    int i=0;
    for (;i<A.size();i++)
        cout<<A.at(i)<<" ";
    cout<<endl;
}

template<typename T>
int merge(vector<T>&arr, int low, int mid, int high)
{

    vector<T> L, R;

    //copy the left sub array
    for (int i=0; i<=mid; i++)
    {
        L.push_back(arr.at(i));

    }


    //copy the right sub array
    for(int j=mid+1; j<=high; j++)
    {
        R.push_back(arr.at(j));
    }



    int i=0, j=0, k=0;
    int n1 = L.size();
    int n2 = R.size();

    //compare and copy from left and right sub array to main array
    for (; k<high; k++)
    {
        //breaks the loop if any of the array (L or R) reached to its end
        if (i >= n1 || j >= n2) break;

        if (L.at(i)<=R.at(j))
        {
            arr.at(k) = L.at(i);
            i++;
        }
        else
        {
            arr.at(k) = R.at(j);
            j++;
        }

    }

    //copy rest of the left sub array to the main array
    while(i<n1)
    {
        arr.at(k)= L.at(i);
        i++;
        k++;
    }
    //copy rest of the right sub array to the main array
    while(j<n2)
    {
       arr.at(k)= R.at(j);
       j++;
       k++;
    }

    return 0;
}

template<typename T>
void merge_sort(vector<T> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
