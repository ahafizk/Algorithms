#include<iostream>
using namespace std;

/*
 *  linked list basic operation : searching, insertion, deletion
*/

typedef struct node_t
{
    int data; // data
    struct node_t* next; //pointer to the next node (successor)
} node_t;

node_t *search_list(node_t *nodes, int key)
{
    if (nodes==NULL) return NULL;
    if (nodes->data==key)
        return nodes;
    else
        return search_list(nodes->next, key);
}

void insert_front(node_t** head, int data)
{
    node_t *node;
    node = new node_t;
    node->data = data;
    node = *head;
    *head = node;

}

node_t* predecessor_node(node_t *head, int data)
{
    if ((head==NULL)||head->next==NULL)
        return NULL;
    if ((head->next)->data == data)
        return head;
    else
    {
        return predecessor_node(head->next,data);
    }
}

void delete_node(node_t **head, int data)
{
    node_t *p, *pred;
    p = search_list(*head, data);
    if (p!=NULL)
    {
        pred = predecessor_node(*head,data);
        if (pred==NULL)
        {
            *head = p->next;
        }
        else
        {
            pred->next = p->next;
        }
        delete p;
    }
}

































