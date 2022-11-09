#ifndef __LIST_H__
#define __LIST_H__

#include "compile.h"

struct list_head {
    struct list_head *next, *prev;
};

static _inline void list_init(struct list_head *head)
{
    head->next = head->prev = head;
}

static _inline void list_add(struct list_head *node, struct list_head *head)
{
    node->next = head->next;
    node->prev = head;
    head->next = node;
    node->next->prev = node;
}

static _inline void list_del(struct list_head *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

#define list_empty(head) ((head) == (head)->next)
#define list_first_node(head, type, member) \
    (list_empty(head) ? NULL : container_of((head)->next, type, member))

#endif