#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	BSTPtr bst = newBST();
    initBST(&bst);

    // Add elements to the BST
    insertBST(&bst, createProduct(1, "Product 1", 5, 10.99));
    insertBST(&bst, createProduct(2, "Product 2", 3, 5.99));
    insertBST(&bst, createProduct(3, "Product 3", 9, 12.99));
    insertBST(&bst, createProduct(4, "Product 4", 8, 15.99));

    // Display the BST in inorder traversal
    printf("Inorder traversal:\n");
    inorderBST(bst);	

    // Remove an element from the BST
    int productIdToRemove = 2;
    removeElement(&bst, productIdToRemove);
    printf("\nBST after removing product with ID %d:\n", productIdToRemove);
    inorderBST(bst);

	// Find the maximum and minimum elements in the BST
	BSTPtr maxElement = max(bst);
	BSTPtr minElement = min(bst);
	printf("\nMaximum element: ");
	displayProduct(maxElement->data);
	printf("Minimum element: ");
	displayProduct(minElement->data);

    // Check if a product with a specific ID is present in the BST
	int searchId = 3;
	bool isFound = isMember(bst, searchId);
	if (isFound) {
	    printf("\nProduct with ID %d is present in the BST.\n", searchId);
	} else {
	    printf("\nProduct with ID %d is not found in the BST.\n", searchId);
	}
	
	// Free the memory of the BST
	freeBST(bst);


	return 0;
}
