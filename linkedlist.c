#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Description: Push function for the linked list, pushes an item to the list, moves the top
* Input: A pointer to a pointer of the node, indicating the top, int for the data used in the node
*/
void Push(Node** headRef, int newData){
    
    //Node* headNode = (Node*)malloc(sizeof(Node));
    
    Node* newNode;
    newNode = malloc(sizeof(Node));
    newNode->item = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

/*
* Description: Pops the last node from the linked list
* Input: A pointer to a pointer of the node, indicating the top
* Output: int as the data from the item popped
*/
int Pop(Node** headRef){
    if(headRef == NULL)return NULL;
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    int item = temp->item;
    free(temp);
    return item;
}

/*
* Description: returns the number of times the data is found in the linked list
* Input: A pointer  of the node, indicating the top. Int of the data being counted
* Output: int as the count of times the item appears in the list
*/
int Count(Node* head, int searchFor){
    int count = 0;
    while(head != NULL){
        if(head->item == searchFor)count++;
        head = head->next;
    }
    return count;
}

/*
* Description: returns the value of the node at the index position
* Input: A pointer  of the node, indicating the top. Int of the index location being searched for
* Output: int as the index of the node that stores the item
*/
int GetNth(Node* head, int index){
    Node* temp = malloc(sizeof(Node));
    temp = head;
    for(int i = 0; i <= index; i++){
        if(i == index)return temp->item;
        temp = temp->next;
    }
    printf("Error, no item found");
    return NULL;
}

/*
* Description: Deallocates all the memory used in a list
* Input: A pointer to the pointer of the node, indicating the top. 
*/
void DeleteList(Node** head){
    Node* temp = malloc(sizeof(Node));
    while((*head)->next != NULL){
        *head = (*head)->next;
        free(*head);
    }
    *head = NULL;
}

/*
* Description: Inserts a new node at the given index
* Input: A pointer to the pointer of the node, indicating the top. The index of the node, and the data of the node
*/
void InsertNth(Node** head, int index, int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->item = data;
    if(index == 0){
        newNode->next = (*head);
        (*head) = newNode;
    }
    while(index--){
        if(index == 0){
            newNode->next = (*head);
            (*head) = newNode;
            
        }
        else head = &(*head)->next;
    }
}

/*
* Description: Takes the front node of one list and pushes it on to the other list
* Input: A pointer to the pointer of the  source node, indicating the top. A pointer to the pointer  of the destination to be copied
*/
void MoveNode(Node** destRef, Node** sourceRef){
    (*sourceRef)->next = NULL;
    Push(destRef, (*sourceRef)->item);
}

/*
* Description: reverses a list using recursion
* Input: A pointer to the pointer of the node, indicating the top.
*/
void RecursiveReverse(Node** headRef){
    Node* newTop = (*headRef);
    Node* oldTop = (*headRef);
    if(oldTop->next->next != NULL){
        RecursiveReverse(&(oldTop->next));
    }
    while(oldTop->next != NULL){
        oldTop = oldTop->next;
    }
    (*headRef) = (*headRef)->next;
    oldTop->next = newTop;
    newTop->next = NULL;
}



