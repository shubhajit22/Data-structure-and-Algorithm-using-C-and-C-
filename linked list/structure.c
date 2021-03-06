// ----------------------------------------This is the code for the lInked list with the explanation----------------------------

#include<stdio.h>
#include<stdlib.h>
#define INT32_MIN -32768 // Defining the min int possible in the 2byte int 


// make the structure for the node
struct node{
    int data; // This is the data field of the Linked list
    struct node *next; // this is the pointer to the next list
}*first = NULL; //There is a 1st pointer for the inicial position set as the null


//creat a Linked- list from the array
void creat (int a[], int n){
    int i;
    struct node *t , *last; // taking a temporary pointer ans last pointer for the linked list
    first = (struct node*) malloc(sizeof(struct node)); // make a frist node in the heap memory and assign it to the varibable to the frist
    first -> data = a[0]; // first element of the array is saved in the first node
    first -> next = NULL; // make rhe nest element to the null
    last = first; // now the last node and frist noed points to the same node

    for ( i = 1; i < n; i++){
        
        t = (struct node *)malloc(sizeof(struct node));
        t ->data = a[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}
// This is the function to display the linked list
void display_list(struct node *p){ // This take thw first pointer as a parameater.
    while (p!= NULL){ // P is used as the contunation Condition
        printf("%d -> ", p -> data);
        p = p -> next;
    }
    printf("End");
}

// This is the display function used by the recursion

void r_display(struct node *p){
    if (p!=NULL){
        printf("%d -> ", p -> data);
        r_display(p ->next);
    }
}

//This is the reverse recursive display function print the list in the reverse order
void rev_r_display(struct node *p){
    if (p!=NULL){
        rev_r_display(p ->next);
        printf("%d -> ", p -> data);
    }
}

// This is for thw counting of the nodes
int list_count(struct node *p){
    int length = 0;
    while (p)       
    {
        length++; // Increase the length 
        p = p->next; // Move the pointer to the next Node
    }
    return length;
}


// This is for the recursive count of the List 
int rec_count_lst(struct node *p){
    if(p!= NULL){
        return rec_count_lst(p->next)+1 ;
    }
    else{
        return 0;
    }
}
// This is the sum of the Elements of the Linked List by the Itertive Process
int sum_lst(struct node *p){
    int sum = 0;
    while (p!= NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
    
}

// This is the sum of the elements of the LInked List By the Recursive Process
int rec_sum_lst(struct node *p){
    if(p==NULL){
        return 0;
    }
    else{
        rec_sum_lst(p->next)+ p->data;
    }
}


// This is for the max elemaent in the Linked list.
int max_element(struct node *p){
    int max = INT32_MIN;// The minimus int possible in the 2byte int
    while (p)
    {
        if(p->data > max){ // If any value founed, grater then the data then assign it to the max
            max = p->data;
        }
        p = p->next; //Update the pointer
    }
    return max;
    
}

// This is the Recursive approach for finding the Max of the Linked List
int rec_max_element(struct node *p){
    int x = 0 ;

    if(p==0){
        return INT32_MIN;
    }
    x = rec_max_element(p -> next);
    return (x > p -> data) ? x : p ->data;
}


// Linier Search In the Linked list

struct node* search(struct node *p, int key){

}













// This is the main Function
int main(){
    int A[] = {3,5,7,10,15,25};
    creat(A, 6);
    // display_list(first);
    // r_display(first);
    // printf("\n");
    // rev_r_display(first);
    printf("%d", rec_max_element(first));
    return 0;
}