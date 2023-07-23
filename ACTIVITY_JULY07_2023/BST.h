#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct {
	int prodID;
	char prodName[20];
	int prodQty;
	float prodPrice;
} Product;

typedef struct node {
	Product data;
	struct node *left;
	struct node*right;
} NodeType, *NodePtr, *BST, *BSTPtr;


//Add element to the BST
BST addElement(BST* list, Product item); // using recursive method
void insertBST(BSTPtr *list, Product item); // using iterative method


// Delete element in  the BST base on the product ID	
void removeElement(BST **list, int prodID); // using iterative method
BST *deleteElement(BST *list, int prodID); // using recursive method


//Dsiplay BST all in recursive method
void inorderBST(BST list); // LEFT - NODE - RIGHT
void preorderBST(BST list); // NODE - LEFT - RIGHT
void postorderBST(BST list); // LEFT - RIGHT - NODE


//Other functions
BSTPtr newBST();
void initBST(BST **list);
bool isEmpty(BST *lsit);
Product createProduct(int id, char *name, int qty, float proce);
// use the following format {<id> | <prodName>} replacing the angular brackets with data
void displayProduct(Product prod);
BSTPtr max(BSTPtr list);
BSTPtr min(BSTPtr list);
bool isMember(BST list, int prodID);

void freeBST(BSTPtr list); // Function to free the memory of the BST


#endif
