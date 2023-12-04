#include <libprg/libprg.h>

node_t * create_node (int value){
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

void destroy (node_t *node){
    if(node != NULL){
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}

node_t * insert_node (node_t *root, int value){
    if(root == NULL){
        return create_node(value);
    } else if(value < root->value){
        root->left = insert_node(root->left, value);
    } else if(value > root->value){
        root->right = insert_node(root->right, value);
    }
    return root;
}

node_t * search_tree (node_t * root, int value, int * level){
    if(root == NULL) return false;
    if(value == root->value) return root;
    if(value < root->value){
        level ++;
        return search_tree(root->left, value, level);
    } else {
        level ++;
        return search_tree(root->right, value, level);
    }
}


int maxValue(node_t * root){
    if(root != NULL){
        if(root->right != NULL){
            return maxValue(root->right);
        } else {
            return root->value;
        }
    }
}

int minValue(node_t * root){
    if(root != NULL){
        if(root->left != NULL){
            return minValue(root->left);
        } else {
            return root->value;
        }
    }
}

void printTree(node_t *root){
    if(root != NULL){
        printTree(root->left);
        printf("%d ", root->value);
        printTree(root->right);
    }
}

node_t * printTreeSoons(node_t * root, int value, int level){
    if(root == NULL){
        perror("Valor não encontrado!\n");
        return NULL;
    }
    if (value == root->value) {
        printf("O número %d foi encontrado na árvore.\n", value);
        if (root->left != NULL)
            printf("Filho a esquerda: %d\n", root->left->value);
        else
            perror("Não possui filho à esquerda.\n");

        if (root->right != NULL)
            printf("Filho a direita: %d\n", root->right->value);
        else
            perror("Não possui filho à direita.\n");

        printf("O nivel na arvore é: %d\n", level);
        return NULL;
    }
    if (value < root->value) {
        printTreeSoons(root->left, value, level + 1);
    } else {
        printTreeSoons(root->right, value, level + 1);
    }
}

node_t * removeNumber (node_t *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->value)
        root->left = removeNumber(root->left, value);
    else if (value > root->value)
        root->right = removeNumber(root->right, value);
    else {
        if (root->left == NULL) {
            node_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node_t *temp = root->left;
            free(root);
            return temp;
        }

        node_t *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->value = temp->value;

        root->right = removeNumber(root->right, temp->value);
    }
    return root;
}
