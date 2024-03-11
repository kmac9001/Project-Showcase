/**
 * Kevin McCreary
 */

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

int main(){

  lst * test_list = mk_list();
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  int five = 5;

  printf("Testing push to front and list get\nExpecting 1 2 3\n");
  list_push_front(test_list, &three);
  list_push_front(test_list, &two);
  list_push_front(test_list, &one);

  printf("%i %i %i\n", *(int *)list_get(test_list, 1),
	 *(int *)list_get(test_list, 2),
	 *(int *)list_get(test_list, 3));

  printf("Testing push to back\nExpecting 4 5\n");
  
  list_push_back(test_list, &four);
  list_push_back(test_list, &five);

  printf("%i %i\n", *(int *)list_get(test_list, 4),
	 *(int *)list_get(test_list, 5));

  printf("Testing list size\nExpecting 5\n");
  printf("%i\n", list_size(test_list));


  /**
   * Remove calls resolved from last to first in print,
   * thus odd looking order of indexes removed.
   */
  printf("Testing remove\nExpecting 4 2 3 1 5\n");
  printf("%i %i %i %i %i\n",
	 *(int *)lst_remove(test_list, 1),
	 *(int *)lst_remove(test_list, 1),
	 *(int *)lst_remove(test_list, 2),
	 *(int *)lst_remove(test_list, 1),
	 *(int *)lst_remove(test_list, 5));

  itr * iterator = mk_iter(test_list);

  printf("Testing add front, add back, iter next, and iter prev\nExpecting 1 2 3 4 5\n4 3 2 1\n");

  iter_add_front(iterator, &three);
  iter_add_front(iterator, &two);
  iter_add_front(iterator, &one);

  iter_add_back(iterator, &four);
  iter_add_back(iterator, &five);

  
  for(int x = 1; x <= 5; x++){
    printf("%i ", *(int *)iter_next(iterator));
  }
  printf("\n");

  for(int x = 5; x > 1; x--){
    printf("%i ", *(int *)iter_prev(iterator));
  }
  printf("\n");

  printf("Testing remove\nExpecting 1 3\n");

  printf("%i ", *(int *)itr_remove(iterator));
  iter_next(iterator);
  printf("%i", *(int *)itr_remove(iterator));

  printf("\n");

  printf("Testing rewind\nExpecting 4 5 2\n");
  printf("%i ", *(int *)iter_next(iterator));
  printf("%i ", *(int *)iter_next(iterator));
  itr_rewind(iterator);
  printf("%i\n", *(int *)iter_next(iterator));

  free(iterator);

  
}
