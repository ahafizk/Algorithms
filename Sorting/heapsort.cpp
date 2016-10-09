#include<iostream>
#include<vector>
using namespace std;

#define parent(i) (i>0? i/2:i)
#define left_child(i) (2*i)
#define right_child(i) (2*i+1)
//max heap property::   A[parent(i)] >= A[i]
//mean heap property::  A[parent(i)] <= A[i]
/*
max_heapify() -- O(lg n)
build_max_heap() -- O(n)
heap_sort() -- O(n lg n)
max_heap_insert(), heap_extract_max(), heap_increase_key(), heap_maximum() -- O(lg n)
*/

//this function follows heap property accordingly to help and build heap
template<typename T>
void max_heapify(vector<T> &A, int index, int heap_size)
{
    int lc_index, rc_index, largest ;
    lc_index = left_child(index);
    rc_index = right_child(index);
    //check left child is largest?
    if (lc_index< heap_size && A[lc_index]>A[index])
    {
        largest = lc_index;
    }
    else
    {
        largest = index; //parent is the largest node
    }
    //check right child is largest or not
    if (rc_index< heap_size && A[rc_index] > A[largest])
    {
        largest = rc_index;
    }

    //largest is its child node
    if (largest!=index)
    {
        //swap root with the largest
        T temp = A.at(index);
        A.at(index) =  A.at(largest);
        A.at(largest) = temp;
        //process continues down to the leaf
        max_heapify(A,largest,heap_size);
    }
}

//build max_heap function create the heap array using max_heapify algorithm
template<typename T>
void build_max_heap(vector<T>& A,int heap_size)
{
    for (int i=heap_size/2; i>=0;i--)
    {
        max_heapify(A,i, heap_size);
    }
}


//this function sort an array using max_heapify
template<typename T>
void heap_sort(vector<T> &A, int heap_size)
{
    build_max_heap(A,heap_size);

    for (int i=A.size()-1; i>=0;i--)
    {

        T temp = A.at(0);

        A.at(0) = A.at(i);
        A.at(i) = temp;
        --heap_size;
        max_heapify(A,0,heap_size);
    }
}




















































