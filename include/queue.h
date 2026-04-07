#ifndef QUEUE_H
#define QUEUE_H

#include <list.h>
#include <list_basic.h>

typedef list_t queue_t;

#define queue_init_queue(q) list_init_list(q)
#define queue_queue_value(q, v, n) list_add_node(q, v, n)
#define queue_unqueue_value(q, v) list_delete_pos_node(q, v, 0)
#define queue_queue_d_value(q, v) list_add_d_node(q, v)
#define queue_unqueue_d_value(q, v) list_delete_d_pos_node(q, v, 0)
#define queue_get_queue_size(q) list_get_total_nodes(q)

typedef list_b_t queue_b_t;

#define queue_b_init_queue(q) list_b_init(q)
#define queue_b_queue_value(q, n) list_add_b_node(q, 0xFFFFFFFF, n)
#define queue_b_unqueue_value(q, n) list_get_b_node(q, 0, n, 1)


#endif
