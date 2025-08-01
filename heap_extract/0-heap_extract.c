#include "binary_trees.h"
#include <stdlib.h>

typedef struct binary_tree_s heap_t;

/**
 * get_heap_size - Calcule la taille du heap
 * @root: Pointeur vers la racine
 * Return: Taille du heap
 */
size_t get_heap_size(heap_t *root)
{
    if (!root)
        return (0);
    return (1 + get_heap_size(root->left) + get_heap_size(root->right));
}

/**
 * get_last_node - Trouve le dernier nœud en level-order
 * @root: Pointeur vers la racine
 * @index: Index actuel
 * @size: Taille totale du heap
 * Return: Pointeur vers le dernier nœud
 */
heap_t *get_last_node(heap_t *root, size_t index, size_t size)
{
    if (!root || index >= size)
        return (NULL);
    
    if (index == size - 1)
        return (root);
    
    heap_t *left_result = get_last_node(root->left, 2 * index + 1, size);
    if (left_result)
        return (left_result);
    
    return (get_last_node(root->right, 2 * index + 2, size));
}

/**
 * heapify_down - Restaure la propriété de heap vers le bas
 * @root: Pointeur vers le nœud à partir duquel heapify
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    int temp_n;
    
    if (!root)
        return;
    
    /* Trouve le plus grand entre root, left et right */
    if (root->left && root->left->n > largest->n)
        largest = root->left;
    
    if (root->right && root->right->n > largest->n)
        largest = root->right;
    
    /* Si le plus grand n'est pas la racine, échanger */
    if (largest != root)
    {
        temp_n = root->n;
        root->n = largest->n;
        largest->n = temp_n;
        
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extrait le nœud racine d'un Max Binary Heap
 * @root: Double pointeur vers la racine du heap
 * Return: Valeur stockée dans le nœud racine, ou 0 en cas d'échec
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node;
    int root_value;
    size_t size;
    
    if (!root || !*root)
        return (0);
    
    root_value = (*root)->n;
    
    /* Cas spécial : un seul nœud */
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (root_value);
    }
    
    /* Trouver le dernier nœud */
    size = get_heap_size(*root);
    last_node = get_last_node(*root, 0, size);
    
    /* Remplacer la racine par le dernier nœud */
    (*root)->n = last_node->n;
    
    /* Supprimer le dernier nœud */
    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }
    
    free(last_node);
    
    /* Restaurer la propriété de heap */
    heapify_down(*root);
    
    return (root_value);
}
