#include<iostream>
#include<vector>
using namespace std;

/*
 * search a key in O(lg n) time
*/
int binary_search(vector<int> &A, int key, int low, int high)
{
    if (low>high)
    {
        return -1;
    }
    int middle = (low+high)/2; //this is integer division, no need of floor() function

    if (A.at(middle)==key)
    {
        return middle;
    }
    else if (A.at(middle)>key)
    {
        return binary_search(A,key,low, middle-1);
    }
    else if (A.at(middle)<key)
    {
        return binary_search(A,key,middle+1, high);
    }
}
