#include<iostream>
#include<vector>
using namespace std;
template<typename T>
int merge(vector<T>&arr, int p, int q, int r)
{
    int n1 = q - p; //left array size
    int n2 = r - q; //right array size
    vector<T>L,R;

//    cout<<"Left array:: "<<endl;
    for (int i=0;i<=n1;i++)
    {
        L.push_back(arr.at(p+i));
//        cout << arr.at(p+i)<<" ";
    }
//    cout<<endl;
    //copy the right subarray
//    cout<<"Right array:: "<<endl;
    for(int j=0;j<n2;j++)
    {
        R.push_back(arr.at(q+j));
//        cout <<arr.at(q+j)+" ";

    }
//    cout<<endl;
    //get two iterator for two subarray

    int i=0,j=0;
    for (int k=0;k<r;k++)
    {

            if (i<=n1 && j<n2 && L.at(i)<=R.at(j))
            {
                arr.at(k) = L.at(i);
                i++;
            }
            else if (j<n2)
            {
                arr.at(k) = R.at(j);
                j++;
            }
    cout<<arr.at(k)<<" "<<endl;
    }
    return 0;
}
template<typename T>
void merge_sort(vector<T> &arr, int p, int r)
{
    if (p<r)
    {
        int q = (p+r)/2;
//        cout<<q<<endl;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
