#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void counting_sort(vector<int> A, vector<int>&B)
{
    int max  = *(max_element(A.begin(),A.end()));
//    cout <<max<<endl;
    vector<int> C(max+1,0);
    for (vector<int>::iterator it = A.begin();it!=A.end();++it)
    {
        C[*it] = C[*it]+1;
    }
    for (int i=1; i<C.size();i++)
    {
        C[i] = C[i-1]+C[i];

    }
    for  (int i = A.size()-1; i>=0;i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] = C[A[i]] -1;
    }
}
