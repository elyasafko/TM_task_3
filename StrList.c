#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

typedef struct _node 
{
    char *_data;
    struct _node * _next;
}Node;

typedef struct _StrList
{
    Node *_head;
    size_t _size;
}StrList;



Node* Node_alloc(const char *data, Node* next)
{
	Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) 
    {
        return NULL;
    }
	p->_data = strdup(data);
	p->_next = next;
	return p;
}

void Node_free(Node* node) 
{
    if (node == NULL) 
    {
        return;
    }
    free(node->_data);
	free(node);
}

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc()
{
    StrList* p = (StrList*)malloc(sizeof(StrList));
    if (p == NULL) 
    {
        return NULL;
    }
	p->_head= NULL;
	p->_size= 0;
	return p;
}


/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList)
{
    if (StrList==NULL)
    {
        return;
    }
	Node* p1 = StrList->_head;
	Node* p2;
	while(p1 != NULL) 
	{
		p2 = p1;
		p1 = p1->_next;
		Node_free(p2);
	}
	free(StrList);
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList)
{
    return StrList->_size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList,const char* data)
{
    if (StrList == NULL) 
    {
        return;
    }

    Node* p = Node_alloc(data, NULL);
    if (p == NULL) 
    {
        return;
    }
    if(StrList->_head == NULL) 
    {
        StrList->_head = p;
    }
    else 
    {
        Node* q = StrList->_head;
        while(q->_next != NULL) 
        {
            q = q->_next;
        }
        q->_next = p;
    }
    StrList->_size++;
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    if(index<0 || index>StrList->_size) 
    {
        return;
    }
    Node* p= Node_alloc(data, NULL);
    if (p == NULL) 
    {
        return;
    }
    if(index==0) 
    {
        p->_next = StrList->_head;
        StrList->_head = p;
    }
    else 
    {
        Node* q = StrList->_head;
        for(int i=0; i<index-1; i++) 
        {
            q = q->_next;
        }
        p->_next = q->_next;
        q->_next = p;
    }
    StrList->_size++;
}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList)
{
    if(StrList->_head==NULL) 
    {
        return NULL;
    }
    return StrList->_head->_data;

}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
    {
        return;
    }

    Node* p= StrList->_head;
    while(p != NULL) 
    {
        printf("%s ", p->_data);
        p= p->_next;
    }
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index)
{
    if(index<0 || index>=Strlist->_size) 
    {
        return;
    }
    Node* p= Strlist->_head;
    for(int i=0; i<index; i++) 
    {
        p= p->_next;
    }
    printf("%s\n", p->_data);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist)
{
    int count= 0;
    Node* p= Strlist->_head;
    while(p != NULL) 
    {
        count+= strlen(p->_data);
        p= p->_next;
    }
    return count;

}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data)
{
    int count= 0;
    Node* p= StrList->_head;
    while(p != NULL) 
    {
        if(strcmp(p->_data, data)==0) 
            count++;
        p= p->_next;
    }
    return count;
}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data)
{
    Node* p = StrList->_head;
    Node* q = NULL;
    while(p != NULL) 
    {
        if(strcmp(p->_data, data)==0) 
        {
            if(q==NULL)
            {
                StrList->_head= p->_next;
                Node_free(p);
                p = StrList->_head;
            }
            else 
            {
                q->_next= p->_next;
                Node_free(p);
                p = q->_next;
            }
            StrList->_size--;
        }
        else 
        {
            q = p;
            p = p->_next;
        }
    }

}
/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index)
{
    if(index<0 || index>=StrList->_size) 
    {
        return;
    }
    Node* p= StrList->_head;
    if(index==0) 
    {
        StrList->_head = p->_next;
        Node_free(p);
    }
    else 
    {
        Node* q= NULL;
        for(int i=0; i<index; i++) 
        {
            q = p;
            p = p->_next;
        }
        q->_next= p->_next;
        Node_free(p);
    }
    StrList->_size--;

}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    if(StrList1->_size != StrList2->_size) 
    {
        return 0;
    }
    Node* p= StrList1->_head;
    Node* q= StrList2->_head;
    while(p != NULL && q != NULL) 
    {
        if(strcmp(p->_data, q->_data)!=0) 
        {
            return 0;
        }
        p = p->_next;
        q = q->_next;
    }
    return 1;

}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* Strlist)
{
    StrList* p = StrList_alloc();
    Node* q = Strlist->_head;
    while(q != NULL)
    {
        StrList_insertLast(p, q->_data);
        q = q->_next;
    }
    return p;
}

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList)
{
    Node* p= StrList->_head;
    Node* q= NULL;
    Node* r= NULL;
    while(p != NULL) 
    {
        r = q;
        q = p;
        p = p->_next;
        q->_next = r;
    }
    StrList->_head = q;
}

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList)
{
    Node* p= StrList->_head;
    Node* q= NULL;
    Node* r= NULL;
    while(p != NULL) 
    {
        q = p;
        r = p->_next;
        while(r != NULL) 
        {
            if(strcmp(r->_data, q->_data) < 0) 
            {
                q = r;
            }
            r = r->_next;
        }
        char* temp = p->_data;
        p->_data = q->_data;
        q->_data = temp;
        p = p->_next;
    }
}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList)
{
    // Empty list or a list with a single element is considered sorted
    if (StrList->_head == NULL || StrList->_head->_next == NULL) 
        return 1;

    Node* p = StrList->_head;
    while(p->_next != NULL)
    {
        if (strcmp(p->_data, p->_next->_data) > 0) 
            return 0;
        p = p->_next;
    }
    return 1;
}