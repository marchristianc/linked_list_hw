#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

dnode* dnode_create(int data, dnode* prev, dnode* next){
    dnode* t_node;
    t_node = malloc(sizeof(dnode));
    t_node->data = data;
    t_node->prev = prev;
    t_node->next = next;
    return t_node;
}

dlist* dlist_create(void){
    dlist* t_list;
    t_list = malloc(sizeof(dlist));
    t_list->head = NULL;
    t_list->tail = NULL;
    t_list->size = 0;
    return t_list;
}

bool dlist_empty(dlist* list){
    return (list->size) == 0;
}

size_t dlist_size(dlist* list){
    return (list->size);
}

void dlist_popfront(dlist* list){
    if(list->size < 1)
        return;
    dnode* t_node;
    t_node = malloc(sizeof(dnode));
    t_node = (list->head)->next;
    free(list->head);
    (t_node->next)->prev = t_node;
    list->head = t_node;
    list->size--;
}

void dlist_popback(dlist* list){
    if(list->size < 1)
        return;
    dnode* t_node;
    t_node = malloc(sizeof(dnode));
    t_node = (list->tail)->prev;
    free(list->tail);
    list->tail = t_node;
    (list->tail)->next = NULL;
    list->size--;
}

void dlist_pushfront(dlist* list, int data){
    dnode* t_node;
    t_node = malloc(sizeof(dnode));
    t_node->data = data;
    t_node->prev = NULL;
    t_node->next = (list->size > 0) ? list->head : NULL;
    if(list->size == 0)
        list->tail = t_node;
    list->head = t_node;
    if(t_node->next != NULL)
        (t_node->next)->prev = t_node;
    list->size++;
}

void dlist_pushback(dlist* list, int data){
    dnode* t_node;
    t_node = malloc(sizeof(dnode));
    t_node->data = data;
    t_node->next = NULL;
    t_node->prev = (list->size > 0) ? list->tail : NULL;
    if(list->size == 0)
        list->head = t_node;
    list->tail = t_node;
    if(t_node->prev != NULL)
        (t_node->prev)->next = t_node;
    list->size++;
}

void dlist_clear(dlist* list){
    dnode* t_node;
    dnode* t_temp;
    t_node = malloc(sizeof(dnode));
    t_temp = malloc(sizeof(dnode));
    while(t_node != NULL){
        t_temp = t_node->next;;
        free(t_node);
        t_node = t_temp;
    }
    list->size = 0;
}

void dlist_print(dlist* list, const char* msg){
    printf("%s\n", msg);
    dnode* t_node;
    t_node = malloc(sizeof(dnode));
    t_node = list->head;
    while(t_node != NULL){
        printf("%d --> %p\n", t_node->data, &(t_node->data));
        t_node = t_node->next;
    }
}

int dlist_front(dlist* list){
    return (list->head)->data;
}

int dlist_back(dlist* list){
    return (list->tail)->data;
}