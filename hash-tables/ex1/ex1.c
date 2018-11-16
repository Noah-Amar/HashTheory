#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *ret = malloc(sizeof(Answer));

  if(length < 2) {
    return NULL;
  }
   for(int i = 0; i < length; i++) {
    hash_table_insert(ht, weights[i], i);
  }
   for(int y = 0; y < length; y++) {
    int matching = hash_table_retrieve(ht, limit - weights[y]);
    if(matching != -1) {
      if(y > matching) {
        ret->index_1 = y;
        ret->index_2 = matching;
      } else {
        ret->index_1 = matching;
        ret->index_2 = y;
      }
      destroy_hash_table(ht);
      return ret;
    }
  }
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}