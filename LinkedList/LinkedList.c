/*
    * Module Name : * LinkedList
    * Author :  * Kanwar Adnan
    * Description : * This is the implementation of Linkedlist in C. It will be used in python scripts
    to gain speed.

    * Functions:
        bool isEmpty();

        bool isIndex(int index);

        struct Node * getHead();

        struct Node * getLast();

        struct Node * getNodeById(int index);

        int getLength();
            This functions returns the length of the linkedlist.

        int getFirst();
            This function returns the first element.

        int getLast_();
            This functions returns the integer value of last node.

        int getMiddle();
            This function returns the middle elemnt.

        int getElementById(int index);
            This function returns element at a specific index.

        void insertAtHead(int value);
            This method inserts a node at the head of the linkedlist.

        void insertAtLast(int value);
            This method inserts a node at the last of the linkedlist.

        void removeFirst();
            This method removes first node.

        void removeLast();
            This method removes last node.

        void removeByValue(int value);
            This metohd removes a node by it's value.

        void removeById(int index);
            This method removes a node by it's id.

        void insertAtId(int index , int value);
            This method inserts a node at a specific id.

        bool doesExists(int value);
            This method returns whether an element is present or not.

        void deleteList();
            This method deletes the complete linkedlist.

        void reverse();
            This method reverses the complete linkedlist.

        void printRev();
            This method prints the complete linekdlist in reversed order.

        void print();
            This function prints the complete linkedlist.


    * For any changes or upgrades you may fork and apply for the merge.
    
    * Note:
        You can also contact me or report any bug. Well To be honest this isn't 
        perfect some problems may occur in python program.

    * Contact:
        * email : kanwaradnanrajput@gmail.com
*/
/* Including required headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Defining format for boolean values */
#define formatBool(b) ((b) ? "true" : "false")

/* Our Node */
struct Node{
    int data;
    struct Node *next;
};

/* Node pointers */
struct Node *head = NULL;
struct Node *last = NULL;

/* Keeping the elements of nodes */
int length = 0;

/* -------------List of the functions------------------------ */
bool isEmpty();
bool isIndex(int index);
struct Node * getHead();
struct Node * getLast();
struct Node * getNodeById(int index);
int getLength();
int getFirst();
int getLast_(); // this gives you the integer value of last node
int getMiddle();
int getElementById(int index);
void insertAtHead(int value);
void insertAtLast(int value);
void removeFirst();
void removeLast();
void removeByValue(int value);
void removeById(int index);
void insertAtId(int index , int value);
bool doesExists(int value);
void deleteList();
void reverse();
void printRev();
void print();

/* + Special Helper functions */
struct Node * newNode();
void printRevHelper(struct Node * current);

/* --------------Implemnting the functions------------------ */

/* Helper function, provides the new Node object with future. */
struct Node *newNode(){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = 0;
    temp->next = NULL;
    return temp;
}

/* function NO 1 */
/* This functions returns the length of the linkedlist.*/
int getLength(){
    return length;
}

/* function NO 2 */
/* This method inserts a node at the head of the linkedlist.*/
void insertAtHead(int value){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    if (isEmpty()){
        head = temp;
        head->next = NULL;
        last = head;
    }
    else{
        temp->next = head;
        head = temp;
    }
    length++;
}

/* function NO 3 */
/* This method inserts a node at the last of the linkedlist.*/
void insertAtLast(int value){
    if (isEmpty()){
        insertAtHead(value);
        return;
    }
    else{
        struct Node *temp = newNode();
        temp->data = value;
        last->next = temp;
        last = temp;
    }
    length++;
}

/* function NO 4 */
/* This function returns element at a specific index.*/
int getElementById(int index){
    if (isIndex(index)){
        struct Node * temp = head;
        int count = 1;
        while (count != index){
            count++;
            temp = temp->next;
        }
        return temp->data;
    }
    else {
        printf("\n\nThere is no such node %d",index);
        printf("\n");
        return -1;
    }
}

/* function NO 5 */
/* This function prints the complete linkedlist. */
void print(){
    if (!isEmpty()){
        struct Node *temp = head;
        while (temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    else{
        printf("NULL\n");
    }
}

/* function NO 6 */
/* This function returns the first element. */
int getFirst(){
    if (!isEmpty()){
        return (head->data);
    }
}

/* function NO 7 */
/* This function returns the last element. */
int getLast_(){
    if (!isEmpty()){
        return (last->data);
    }
}

/* function NO 8 */
/* This function returns whether linkedlist is empty or not. */
bool isEmpty(){
    return (head == NULL);
}

/* function NO 9 */
/* This function returns whether the index is valid or not. */
bool isIndex(int index){
    return (index <= (length) && (index > 0));
}

/* function NO 10 */
/* This function removes the first element. */
void removeFirst(){
    if (isEmpty()){
        return;
    }
    else if (length==1){
            free(head);
            head = NULL;
            free(last);
            last = NULL;
        }
    else {
        struct Node * temp = head->next;
        free(head);
        head = temp;
    }
    length--;
}

/* function NO 11 */
/* This function removes the last element. */
void removeLast(){
    if (isEmpty()){
        return;
    }
    else if (length == 1){
        removeFirst();
        return;
    }
    else {
        int _length = length;
        struct Node * secLast = getNodeById((_length - 1));
        free(last);
        secLast->next = NULL;
        last = secLast;
    }
    length--;
}

/* function NO 12 */
/* This function remove an element at the specific index. */
void removeById(int index){
    if (isIndex(index)){
        if (index == 1){
            return removeFirst();
        }
        else if (index == length){
            return removeLast();
        }
        else {
            struct Node * previous = getNodeById(index - 1);
            struct Node * current = previous->next;
            struct Node * next = current->next;
            previous->next = next;
            free(current);
        }
        length--;
    }
    else {
        printf("\n\nThere are is no such node.\n");
        printf("\n");
    }
}

/* function NO 13 */
/* This function inserts an element at the specific index. */
void insertAtId(int index , int value){
    if (isIndex(index)){
        if (index == 1){
            return insertAtHead(value);
        }
        else if (index == length){
            return insertAtLast(value);
        }
        else {
            struct Node * previous = getNodeById(index - 1);
            struct Node * current = previous->next;

            // Making new node and setting it
            struct Node * temp = newNode();
            temp->data = value;

            // The next of the new node will be the current
            temp->next = current;

            // this node will get the place of node at the index
            previous->next = temp;
        }
        length++;
    }
}

/* function NO 14 */
/* This function returns the head of the linkedlist. */
struct Node * getHead(){
    if (!isEmpty()){
        return head;
    }
}

/* function NO 15 */
/* This function returns the last node of the linkedlist. */
struct Node * getLast(){
    if (!isEmpty()){
        return last;
    }
}

/* function NO 16 */
/* This function returns the specific node by index. */
struct Node * getNodeById(int index){
    if (isIndex(index)){
        // if index is 1 then return the head
        if (index == 1){
            return getHead();
        }
        // If equals to the length then return the last
        else if (index == length){
            return getLast();
        }
        // searching for the Node
        else {
            int count = 1;
            struct Node * temp = head;
            while (count != index){
                count++;
                temp = temp->next;
            }
            return temp;
        }
    }
    else {
        printf("\n\nThere are is no such node\n");
        return NULL;
    }
}

/* This is helper function to do the task easily as C does not support 
    *function overloading
*/
void printRevHelper(struct Node * current){
    if (current == NULL)
        return;
    printRevHelper(current->next);
    printf("<-%d",current->data);
}

/* function NO 17 */
/* This function prints the complete linkedlist in reversed order. */
void printRev(){
    printf("NULL");
    printRevHelper(getHead());
    printf("\n");
}

/* function NO 18 */
/* This function returns whether an element exits or not in the linkedlist. */
bool doesExists(int value){
    if (!isEmpty()){
        if (getFirst() == value){
            return true;
        }
        else if (getLast_() == value){
            return true;
        }
        else {
            struct Node * temp = head;
            while (temp != NULL){
                if (temp->data == value){
                    return true;
                }
                temp = temp->next;
            }
        }
    }
    printf("\n\nThere is no such node\n");
    printf("\n");
    return false;
}

/* function NO 19 */
/* This function removes an element by its value. */
void removeByValue(int value){
    if (!isEmpty()){
        if ( (head->data == value) )
            return removeFirst();
        else {
            struct Node * temp = head;
            struct Node * temp2 = head->next;
            while (temp2->next != NULL){
                if (temp2->data == value){
                    struct Node * next = temp2->next;
                    temp->next = (next);
                    free(temp2);
                    length--;
                    return;
                }
                temp2 = temp2->next;
                temp = temp->next;
            }
            // If the last member is to delete
            if (temp2->data == value){
                return removeLast();
            }
        }
    }
    printf("\n\nThere is no such node.");
    printf("\n");
}

/* function NO 20 */
/* This function returns the middle element. */
int getMiddle(){
    int mid = 0;
    if (length % 2 == 0)
        mid = (length / 2);
    else
        mid = (length / 2) + 1;
    return getNodeById(mid)->data;
}

/* function NO 21 */
/* This function deletes the complete linkedlist. */
void deleteList(){
    if (!isEmpty()){
        struct Node * prev = NULL;
        struct Node * temp = head;
        while (temp != NULL){
            prev = temp;
            temp = temp->next;
            free(prev);
        }
        head = NULL;
    }
}

/* function NO 22 */
/* This function reverses the complete linkedlist. */
void reverse(){
    if (!isEmpty()){
        if (length == 1){
            return;
        }
        last = head; // reserving the last
        struct Node * previous = NULL;
        struct Node * current = head;
        struct Node * next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = (previous);
            previous = current;
            current = next;
        }
        head = previous;
    }
}

int main(){
    // adding 6 
    insertAtHead(1);
    insertAtLast(2);
    insertAtId(1,2);
    insertAtHead(1);
    insertAtLast(2);
    insertAtId(1,2);

    // Removing 4
    removeByValue(2);
    removeFirst();
    removeLast();
    removeById(1);

    // Checking
    isEmpty();
    isIndex(1);

    // getting 8
    getElementById(1);
    getFirst();
    getLast();
    getLast_();
    getLength();
    getMiddle();
    getNodeById(1);
    getHead();

    // some others
    reverse();
    doesExists(1);

    // printing
    print();
    printRev();

    // deleting complete linkedlist
    deleteList();

    printf("\n\nThe Code Worked");
    printf("\n\tCreated By Kanwar Adnan");

}
