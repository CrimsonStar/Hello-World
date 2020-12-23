#include<stdio.h> 
#include<stdlib.h>
struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};
struct node* insert(struct node* node, int data);
struct node* newNode(int item);
struct node* search(struct node* root, int data);
void displayTree(struct node* root);


int main() 
{ 
    int num;
    int threeCount;
    struct node* start = NULL;
	printf("Please enter an integer: ");
	scanf("%d", &num);
	insert(start, num);  
	while (1) {
		printf("Please enter an integer (-100 to exit): ");
		scanf("%d", &num);
		if (num == -100) { break; }
		insert(start, num); 
	}
	displayTree(start);
	int num2;
	for(threeCount=0; threeCount<3;threeCount++){
	    printf("Please Pick a number that you entered into the tree:");
	    scanf("%d", &num2);
	    search(start, num2);
	}
}
struct node* newNode(int item) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}
struct node* insert(struct node* node, int data) 
{ 
    if (node == NULL){ 
        return newNode(data); 
    }
    if (data < node->data){ 
        node->left = insert(node->left, data);
	} 
    else if (data > node->data){ 
        node->right = insert(node->right, data); 
    }
    return node; 
}
 
struct node* search(struct node* root, int data) 
{  
    if (root == NULL || root->data == data){ 
       return root; 
     }
    if (root->data < data){ 
       return search(root->right, data); 
    }
    return search(root->left, data); 
}
void displayTree(struct node* root) 
{ 
    if (root != NULL) { 
        displayTree(root->left); 
        printf("%d \n", root->data); 
        displayTree(root->right); 
    } 
}

