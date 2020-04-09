#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

snode* snode_create(int data, snode* next){
    snode* t_node;
    t_node->data = data;
    t_node->next = next;
    return t_node;
}

slist* slist_create(void){
    slist* t_list;
    t_list = malloc(sizeof(slist));
    t_list->head = NULL;
    t_list->tail = NULL;
    t_list->size = 0;
    return t_list;
}

bool slist_empty(slist* list){
    return (list->size) == 0;
}

size_t slist_size(slist* list){
    return list->size;
}

void slist_popfront(slist* list){
    if(list->size < 1)
        return;
    snode* t_node = (list->head)->next;
    t_node = malloc(sizeof(snode));
    free(list->head);
    list->head = t_node;
    list->size--;
}

void slist_popback(slist* list){
    if(list->size < 1)
        return;
    snode* t_node = list->head;
    t_node = malloc(sizeof(snode));
    for(int i = 0; i < (list->size-1); i++)
        t_node = t_node->next;
    free(list->tail);
    list->tail = t_node;
    list->size--;
}

void slist_pushfront(slist* list, int data){
    snode* t_node;
    t_node = malloc(sizeof(snode));
    t_node->data = data;
    if(list->size > 0){
        t_node->next = list->head;
    }else{
        t_node->next = NULL;
        list->tail = t_node;
    }
    list->head = t_node;
    list->size++;
}

void slist_pushback(slist* list, int data){
    snode* t_node;
    t_node = malloc(sizeof(snode));
    t_node->data = data;
    if(list->size > 0){
        (list->tail)->next = t_node;
    }else{
        t_node->next = NULL;
        list->head = t_node;
    }
    list->tail = t_node;
    list->size++;
}

void slist_clear(slist* list){
    snode* t_node;
    snode* t_temp;
    t_node = malloc(sizeof(snode));
    t_temp = malloc(sizeof(snode));
    while(t_node != NULL){
        t_temp = t_node->next;
        free(t_node);
        t_node = t_temp;
    }
    list->size = 0;
}

void slist_print(slist* list, const char* msg){
    printf("%s\n", msg);
    snode* t_node;
    t_node = malloc(sizeof(snode));
    t_node = list->head;
    while(t_node != NULL){
        printf("%d --> %p\n", t_node->data, &(t_node->data));
        t_node = t_node->next;
    }
}

int slist_front(slist* list){
    return (list->head)->data;
}

int slist_back(slist* list){
    return (list->tail)->data;
}