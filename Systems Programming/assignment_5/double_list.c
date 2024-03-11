/**
 * Kevin McCreary
 */

#include <stdlib.h>
#include "double_list.h"

lst * mk_list(){

  lst * list_head = malloc(sizeof(lst));
  list_head->size = 0;
  list_head->next = list_head;
  list_head->prev = list_head;
  return list_head;

}

void list_push_back(lst * list, void * item){

  lst * new_node = malloc(sizeof(lst));
  new_node->item = item;
  
  new_node->prev = list->prev;
  new_node->next = list;

  list->prev->next = new_node;
  list->prev = new_node;

  list->size++;

}

void list_push_front(lst * list, void * item){

  lst * new_node = malloc(sizeof(lst));
  new_node->item = item;
  
  new_node->prev = list;
  new_node->next = list->next;

  list->next->prev = new_node;
  list->next = new_node;

  list->size++;

}

void * list_get(lst * lst, int index){

  if(index <= lst->size){
    for(int x = 1; x <= index; x++){
      lst = lst->next;
    }
    return lst->item;
  }
  else
    return NULL;
}

void * lst_remove(lst * lst, int index){
  
  if(index <= lst->size){
    lst->size--;
    for(int x = 1; x <= index; x++){
      lst = lst->next;
    }
    void * ret_val = lst->item;
    lst->next->prev = lst->prev;
    lst->prev->next = lst->next;

    free(lst);

    return ret_val;
  }
  else
    return NULL;
}

int list_size(lst * lst){
  return lst->size;
}



itr * mk_iter(lst * lst){

  itr * new_itr = malloc(sizeof(itr));

  new_itr->rmt = 0;
  
  new_itr->curr = lst;
  new_itr->head = lst;

  return new_itr;

}

void iter_add_back(itr * itr, void * item){

  lst * new_node = malloc(sizeof(lst));
  new_node->item = item;

  new_node->prev = itr->curr->prev;
  new_node->next = itr->curr;
  itr->curr->prev->next = new_node;
  itr->curr->prev = new_node;

  itr->head->size++;

}

void iter_add_front(itr * itr, void * item){

  lst * new_node = malloc(sizeof(lst));
  new_node->item = item;

  new_node->prev = itr->curr;
  new_node->next = itr->curr->next;
  itr->curr->next->prev = new_node;
  itr->curr->next = new_node;

  itr->head->size++;

}

void * iter_next(itr * itr){

  if(itr->curr->next != itr->head){
     itr->curr = itr->curr->next;
     itr->rmt = 1;
     return itr->curr->item;
  }
  else
    return NULL;

}

void * iter_prev(itr * itr){

  if(itr->curr->prev != itr->head){
    itr->curr = itr->curr->prev;
    itr->rmt = -1;
    return itr->curr->item;
  }
  else
    return NULL;

}

void * itr_remove(itr * itr){

  void * ret_val = itr->curr->item;

  itr->curr->next->prev = itr->curr->prev;
  itr->curr->prev->next = itr->curr->next;

  switch(itr->rmt){
  case 1:
    itr->curr = itr->curr->prev;
    itr->rmt = 0;
    break;
  case -1:
    itr->curr = itr->curr->next;
    itr->rmt = 0;
    break;
  case 0:
    return NULL;
  default:
    return NULL;
  }
  return ret_val;


  //free(itr->curr);

}

void itr_rewind(itr * itr){

  itr->curr = itr->head;

}

