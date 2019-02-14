
#include <stdio.h>
#include <stdlib.h>

struct tree{
	struct node* root;
};

struct TreeNode{
	
    int val;
    struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *newNode(int item)
{
    struct TreeNode *temp =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

void print(struct TreeNode *root){
    if (root != NULL){
        print(root->left);
        printf("%d ", root->val);
        print(root->right);  
    }
}

struct TreeNode* insert(struct TreeNode* root, int val){

    if (root == NULL){
    	return newNode(val);
	}
    if (val < root->val){
		root->left  = insert(root->left, val);
	}
    else if (val > root->val){
    	root->right = insert(root->right, val);
	}
    return root;
}

struct TreeNode* search(struct TreeNode* root, int val){
    if(root==NULL || root->val==val){
    	return root;
	}

    if(root->val < val){
    	return search(root->right, val);
	}
    else{
    	return search(root->left, val);
	}  
}

struct TreeNode* minimum(struct TreeNode* node)
{
    struct TreeNode* current = node;
    
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}


struct TreeNode* deleteNode(struct TreeNode* root, int val){
    
	if (root == NULL){ 
    	return root;
	}
    if (val < root->val){
    	root->left = deleteNode(root->left, val);
	}
    else if (val> root->val){
    	root->right = deleteNode(root->right,val);
	}
    else{
        if(root->left == NULL){
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minimum(root->right);
        root->val = temp->val;
 
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}


int main()
{
	int r1,r2;
    struct TreeNode *root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 3);
    insert(root, 8);
    insert(root, 6);
    insert(root, 7);
    insert(root, 9);
    insert(root, 12);
    insert(root, 1);
    print(root);
    printf("\n");
    
    deleteNode(root,4);
    deleteNode(root,7);
    deleteNode(root,2);
    print(root);
    
  
    return 0;
}


