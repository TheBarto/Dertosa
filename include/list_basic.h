#ifndef LIST_BASIC_H
#define LIST_BASIC_H

#include <stdint.h>

#define GET_NODE_LIST(node, pos) \
do{ \
	for(uint32_t i = 0; ((i < pos) && (node)); i++, node = node->next); \
}while(0)

#define list_b_init_node(n) (n->next)
#define list_b_last_node(n) (n->prev)

/* NODO DE ESTRUCTURA PARA ELEMENTOS IGUALES.
 * EL CASO ES TENER LOS PTRS, Y LUEGO OBTENER
 * LAS POSICIONES CON POSICIONES.POSICIONES.*/
struct node_basic_t {
	struct node_basic_t *next;
	struct node_basic_t *prev;
};

typedef struct node_basic_t node_b_t;
typedef node_b_t list_b_t;


int8_t list_add_b_node(list_b_t *l, uint32_t pos, node_b_t *n);

int8_t list_get_b_node(list_b_t *l, uint32_t pos, node_b_t **fnode, uint8_t delete);

int8_t list_b_init(list_b_t *l);

#endif // LIST_BASIC_H
