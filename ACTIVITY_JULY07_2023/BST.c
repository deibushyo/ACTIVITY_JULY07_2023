#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

// using recursive method
BST addElement(BST* list, Product item) {
    if (*list == NULL) {
        *list = malloc(sizeof(NodeType));
        (*list)->data = item;
        (*list)->left = NULL;
        (*list)->right = NULL;
    } else if (item.prodID < (*list)->data.prodID) {
        (*list)->left = addElement(&(*list)->left, item);
    } else if (item.prodID > (*list)->data.prodID) {
        (*list)->right = addElement(&(*list)->right, item);
    }
    return *list;
}

// using iterative method
void insertBST(BSTPtr* list, Product item) {
    NodePtr newNode = malloc(sizeof(NodeType));
    if (newNode == NULL) {
        // Handle memory allocation failure, e.g., display an error message and exit.
        printf("Error: Memory allocation failed for new node.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*list == NULL) {
        *list = newNode;
    } else {
        NodePtr curr = *list;
        while (true) {
            if (item.prodID < curr->data.prodID) {
                if (curr->left == NULL) {
                    curr->left = newNode;
                    break;
                } else {
                    curr = curr->left;
                }
            } else if (item.prodID > curr->data.prodID) {
                if (curr->right == NULL) {
                    curr->right = newNode;
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
}

// using iterative method
void removeElement(BST** list, int prodID) {
    if (*list == NULL) {
        return;
    }
    NodePtr parent = NULL;
    NodePtr current = *list;

    while (current != NULL) {
        if (prodID == current->data.prodID) {
            if (current->left == NULL && current->right == NULL) {
                if (parent == NULL) {
                    *list = NULL;
                } else {
                    if (parent->left == current) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                }
                free(current);
                return;
            } else if (current->left == NULL) {
                if (parent == NULL) {
                    *list = current->right;
                } else {
                    if (parent->left == current) {
                        parent->left = current->right;
                    } else {
                        parent->right = current->right;
                    }
                }
                free(current);
                return;
            } else if (current->right == NULL) {
                if (parent == NULL) {
                    *list = current->left;
                } else {
                    if (parent->left == current) {
                        parent->left = current->left;
                    } else {
                        parent->right = current->left;
                    }
                }
                free(current);
                return;
            } else {
                NodePtr successor = current->right;
                NodePtr successorParent = NULL;

                while (successor->left != NULL) {
                    successorParent = successor;
                    successor = successor->left;
                }

                current->data = successor->data;

                if (successorParent != NULL) {
                    successorParent->left = successor->right;
                } else {
                    current->right = successor->right;
                }

                free(successor);
                return;
            }
        } else if (prodID < current->data.prodID) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    *list = deleteElement(*list, prodID);
}

// using iterative method
BST* deleteElement(BST* list, int prodID) {
    if (list == NULL) {
        return list;
    }
    if (prodID < (*list)->data.prodID) {
        (*list)->left = deleteElement((*list)->left, prodID);
    } else if (prodID > (*list)->data.prodID) {
        (*list)->right = deleteElement((*list)->right, prodID);
    } else {
        if ((*list)->left == NULL) {
            NodePtr temp = (*list)->right;
            free(list);
            return temp;
        } else if ((*list)->right == NULL) {
            NodePtr temp = (*list)->left;
            free(list);
            return temp;
        }
        NodePtr successor = (*list)->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        (*list)->data = successor->data;
        (*list)->right = deleteElement((*list)->right, successor->data.prodID);
    }
    return list;
}

void inorderBST(BST list) {
    if (list != NULL) {
        inorderBST(list->left);
        displayProduct(list->data);
        inorderBST(list->right);
    }
}

void preorderBST(BST list) {
    if (list != NULL) {
        displayProduct(list->data);
        preorderBST(list->left);
        preorderBST(list->right);
    }
}

void postorderBST(BST list) {
    if (list != NULL) {
        postorderBST(list->left);
        postorderBST(list->right);
        displayProduct(list->data);
    }
}

BSTPtr newBST() {
    BSTPtr tree = malloc(sizeof(NodeType));
    if (tree != NULL) {
        tree->data.prodID = 0;
        tree->data.prodName[0] = '\0';
        tree->data.prodQty = 0;
        tree->data.prodPrice = 0.0;
        tree->left = NULL;
        tree->right = NULL;
    }
    return tree;
}


void initBST(BST **list) {
    *list = NULL;
}

bool isEmpty(BST *list) {
    return *list == NULL;
}

Product createProduct(int id, char *name, int qty, float price) {
    Product p;
    p.prodID = id;
    strcpy(p.prodName, name);
    p.prodQty = qty;
    p.prodPrice = price;
    return p;
}

// use the following format {<id> | <prodName>} replacing the angular brackets with data
void displayProduct(Product prod) {
    printf("{%d | %s}\n", prod.prodID, prod.prodName);
}

BSTPtr max(BSTPtr list) {
    if (list == NULL)
        return NULL;
    else if (list->right == NULL)
        return list;
    else
        return max(list->right);
}

BSTPtr min(BSTPtr list) {
    if (list == NULL)
        return NULL;
    else if (list->left == NULL)
        return list;
    else
        return min(list->left);
}

bool isMember(BST list, int prodID) {
    if (list == NULL)
        return false;
    else if (prodID == list->data.prodID)
        return true;
    else if (prodID < list->data.prodID)
        return isMember(list->left, prodID);
    else
        return isMember(list->right, prodID);
}

// Function to free the memory of the BST
void freeBST(BSTPtr list) {
    if (list == NULL)
        return;

    freeBST(list->left);
    freeBST(list->right);
    free(list);
}

