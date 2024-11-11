#include <stdio.h>
#include <stdlib.h>

// Structure for BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // Insert the node if the tree is empty
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);  // Insert in the left subtree
    } else {
        root->right = insertNode(root->right, data);  // Insert in the right subtree
    }
    return root;
}

// Function for Inorder traversal (left, root, right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);     // Visit root node
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Function for Preorder traversal (root, left, right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);     // Visit root node
        preorderTraversal(root->left);  // Traverse left subtree
        preorderTraversal(root->right); // Traverse right subtree
    }
}

// Function for Postorder traversal (left, right, root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // Traverse left subtree
        postorderTraversal(root->right); // Traverse right subtree
        printf("%d ", root->data);       // Visit root node
    }
}

// Function to create the BST from a list of integers
struct Node* createBST(struct Node* root) {
    int values[] = {8, 10, 3, 1, 6, 14, 7};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insertNode(root, values[i]);  // Insert each value into the BST
    }

    return root;
}

// Main function with menu-driven interface
int main() {
    struct Node* root = NULL;
    int choice;

    // Create the BST with predefined integers
    root = createBST(root);

    do {
        printf("\nMenu:\n");
        printf("1. Traverse the BST in Inorder\n");
        printf("2. Traverse the BST in Preorder\n");
        printf("3. Traverse the BST in Postorder\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
