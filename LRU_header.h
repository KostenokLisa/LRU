

#ifndef LRU_LIZA_LRU_HEADER_H
#define LRU_LIZA_LRU_HEADER_H
//
// Created by Kostenok Elizaveta, Tsepkova Alexandra, Shirikova Ksenia on 10.05.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct page {
    int index;
    char* data;
    int n; //кол-во символов
};

struct hash {
    int capacity;
    struct hash_node* elem;
};

struct node {
    char* data;
    int index;
    struct node* next;
    struct node* prev;
};

struct hash_node {
    int index;
    struct node* n_cache;
    struct hash_node* next;
};

struct queue
{
    int capacity;
    int length;
    struct node* head;
    struct node* tail;
};

//input

void input ();

struct page* input_page (int index);

//hash table

struct hash* create_table();

void print_hash (struct hash* table);

void delete_table(struct hash* table);

//cache

struct queue* queue_ctor();

struct node* add_new_elem(struct queue* list, struct page* page, int* last_idx);

void print_list(struct queue* s);

void delete_queue(struct queue* list);

struct node* move_elem(struct queue* list, struct node* cur_elem);

#endif //LRU_LIZA_LRU_HEADER_H


