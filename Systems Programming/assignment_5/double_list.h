/**
 * Kevin McCreary
 */

#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include <stdlib.h>

typedef struct _lst {

  int size;
  void * item;
  struct _lst * next;
  struct _lst * prev;

}lst;

typedef struct _itr {
  
  int rmt;
  lst * curr;
  lst * head;

}itr;

lst * mk_list();

void list_push_back(lst * lst, void * item);

void list_push_front(lst * lst, void * item);

void * list_get(lst * lst, int index);

void * lst_remove(lst * lst, int index);

int list_size(lst * lst);


itr * mk_iter(lst * lst);

void iter_add_back(itr * itr, void * item);

void iter_add_front(itr * itr, void * item);

void * iter_next(itr * itr);

void * iter_prev(itr * itr);

void * itr_remove(itr * itr);

void itr_rewind(itr * itr);

#endif
