#include <list_basic.h>
#include <string.h>

int8_t list_add_b_node(list_b_t *l, uint32_t pos, node_b_t *n)
{
	if(!l || !n)
		return -1;

	// Not first elem
	if (!list_b_init_node(l)) {
		list_b_init_node(l) = n;
		list_b_last_node(l) = n;
	} else {
		node_b_t * aux = list_b_init_node(l);
		GET_NODE_LIST(aux, pos);

		if((!aux) || (pos == 0xFFFFFFFF)) {
			list_b_last_node(l)->next = n;
			n->prev = list_b_last_node(l);
			list_b_last_node(l) = n;
		} else {
			n->next = aux;
			/* Check if exists a previous of the current node,
			 * otherwise we're at the first position */
			(aux->prev) ? (aux->prev->next = n) : (list_b_init_node(l) = n);
			n->prev = aux->prev;
			aux->prev = n;
		}
	}

	return 0;
}

// FALTA UN GET SIN SACAR :). PONER UN ARGUMENTO EXTRA
int8_t list_get_b_node(list_b_t *l, uint32_t pos, node_b_t **fnode, uint8_t delete)
{
	if(!l)
		return -1;

	node_b_t *n = list_b_init_node(l);
	if(pos == 0xFFFFFFFF)
		n = list_b_last_node(l);
	else
		GET_NODE_LIST(n, pos);
#if 0
	if((!n) || (pos == 0xFFFFFFFF)) {
		list_b_last_node(l)->next = n;
		n->prev = list_b_last_node(l);
		list_b_last_node(l) = n;
	} else {
		n->next = n;
		/* Check if exists a previous of the current node,
		 * otherwise we're at the first position */
		(n->prev) ? (n->prev->next = n) : (list_b_init_node(l) = n);
		n->prev = n->prev;
		n->prev = n;
	}
#endif
	if(delete) {
		/* Reorganize the previous and next pointer
		 * of the list after removing a node
		 */
		(!n->next) ? (list_b_last_node(l) = n->prev) : (n->next->prev = n->prev);
		(!n->prev) ? (list_b_init_node(l) = n->next) : (n->prev->next = n->next);
	}

	if(fnode)
		*fnode = n;

	return 0;
}


int8_t list_b_init(list_b_t * l)
{
	if(!l)
		return -1;

	memset(l, 0, sizeof(list_b_t));
	return 0;
}


