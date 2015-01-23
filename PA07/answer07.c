#include "pa07.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints a linked-list "head" into the output fie "out"
 *
 * NOTE: we have given the code for this function
 */
void List_print(FILE * out, Node * head)
{
 while(head != NULL)
	{
	    fprintf(out, "%5d: %6d\n", head -> index, head -> value);
	    head = head -> next;
	}
    printf("\n");
}


/**
 * Please fill in the code below
 */

/**
 * Destroys a linked list.
 * Arguments:
 * head    A pointer pointing to the first element of the linked list.
 *
 * Returns:
 * void
 *
 * Destroys (frees memory for) the whole linked list. 
 * You can either use recursion or a while loop.
 */
void List_destroy(Node * head)
{
  if(head == NULL)
  {
    return;
  }
  List_destroy(head -> next);
  free(head);

}

/**
 * Create and initialize a linked list. 
 *
 * Arguments:
 * value     The "value" of the new node
 * index     The "index" of the new node
 *
 * Returns:
 * Returns a newly constructed node. The node can be the head of a
 * linked list.
 * 
 * You should allocate memory in this function. 
 */  
Node * List_create(int value, int index)
{
  Node * ln = malloc(sizeof(Node));
  ln -> index = index;
  ln -> value = value;
  ln -> next = NULL;
  return ln;
}

/**
 * Build a sparse array from the given indices and values with 
 * specific length.
 *
 * Arguments:
 * value    Array of values
 * index    Array of indices
 * length   Length of the above arrays
 *
 * Returns:
 * A sparse array.
 *
 * If a sparse array node has { value = 1000, index = 2 }, then that means that
 * the index "2" caries the value "1000". This is meant to convey an array of 1000 
 * "2s", but instead of creating 1000 nodes in your linked list, you only create
 * 1 node, and that note conceptually has 1000 "copies" of it. Hence 
 * each node in a sparse array has a "value" in addition to its "index".
 *
 * Note that an index can never carry the value of "0", because this would not make
 * any sense; however, negative values are fine. A negative value may seem odd
 * at first blush; however, this is like substraction, and makes sense for certain
 * cases.
 *
 * You need to insert nodes in ascending order by inde.
 * See the notes to "List_insert_ascend"
 */
Node * List_build(int * value, int * index, int length)
{
  int lcv;
  Node * head = NULL;
  for(lcv = 0; lcv < length; lcv++)
  {
    if(index[lcv] != 0)
    {
      head = List_insert_ascend(head, value[lcv], index[lcv]);
    }
  }
    return head;
}


/**
 * Inserting "value" and "index" into the correct location in the 
 * sparse array "head"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the linked list.
 * value     The "value" of the value
 * index     The "value" of the index
 *
 * Returns:
 * A sparse array
 *
 * This function inserts the node ["value", "index"] into the sparse
 * array "head", and ensures that the nodes remain in ascending order
 * by their "index".
 *
 * Before and after the call to this function, "head" must be in
 * ASCENDING order by the "index" of each node.
 */
Node * List_insert_ascend(Node * head, int value, int index)
{
  if(head == NULL)
  {
    return List_create(value, index);
  }
  if((head -> index) == index)
  {
    return head;
  }
  if((head -> index) > index)
  {
    Node * p = List_create(value, index);
    p -> next = head;
    return p;
  }
  head -> next = List_insert_ascend(head -> next, value, index);
  return head;
}


/**
 * This function deletes the node with the passed "index"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the sparse array.
 * index     The index to be deleted
 *
 * Returns: 
 * A sparse array with the node removed (the one with index)
 */
Node * List_delete(Node * head, int index)
{
  if(head == NULL)
  {
    return NULL;
  }
  Node * p = NULL;
  if((head -> index) == index)
  {
    p = head -> next;
    free(head);
    head = p;
  }
  head -> next = List_delete(head -> next, index);
  return head;
}

/**
 * Copy a list
 *
 * Arguments:
 * head      A pointer pointing to the first element of the sparse array
 *
 * Returns:
 * A copy sparse array
 *
 * This function will copy the sparse array that is passed to it. The
 * copy will be made into new memory. 
 *
 * This is useful, for example, when we want to merge
 * two linked lists together. We can make a copy of one of the linked
 * lists, and then merge the second into the copy. In this way the
 * original copy of the list is not "mutated".
 */
Node * List_copy(Node * head)
{ 
  if(head == NULL)
  {
    return head;
  }  
  Node * copy = NULL;
  copy = malloc(sizeof(Node));
  copy -> next = NULL;
  copy -> index = head -> index;
  copy -> value = head -> value;
  copy -> next = List_copy(head -> next);
  return copy;
}


/**
 * Merged two linked list together
 * 
 * Arguments:
 * head1      A pointer pointing to linked list 1
 * head2      A pointer pointing to linked list 2
 *
 * Returns:
 * A merged sparse array
 *
 * This function will merge two linked lists. Before merging, you 
 * should make a copy of "head1" so that you will still have the 
 * original array while modifying (merging) the second linked list. 
 *
 * Please refer to the README file for detailed instructions on how to
 * merge two lists.
 *
 * This function should not modify either "head1" or "head2". You only
 * need to make a clone of "head1".
 */

Node * merge_insert(Node * head3, int index, int value);


Node * List_merge(Node * head1, Node * head2)
{
  Node * copy_of_head1 = NULL;
  copy_of_head1 = List_copy(head1);
  while(head2 != NULL)
  {
     /*if(copy_of_head1 != NULL)
     {*/
        copy_of_head1 = merge_insert(copy_of_head1, head2 -> index, head2 -> value);
      //}
    head2 = head2 -> next;
  }
  return copy_of_head1;
  
}



Node * merge_insert(Node * head3, int index, int value)
{
  if(head3 == NULL)
  {
    head3 = List_create(value, index);
    return head3;
  }
  if((head3 -> index) == index)
  {
    head3 -> value += value;
    if((head3 -> value) == 0)
    {
      /*if((head3 -> next) == NULL)
      {
	head3  = List_create(value, index);
      }*/
      Node * q = NULL;
      q = head3 -> next;
      free(head3);
      
      return q;
      
      
      /*Node * q = NULL;
      q  = head3 -> next;
      head3 = head3 -> next;
      q  = List_delete(q, index);
      return head3;*/
    }
    return head3;
  }
  if((head3 -> index) > index)
  {
    Node * p = List_create(value, index);
    p -> next = head3;
    return p;
  }
  head3 -> next = merge_insert(head3 -> next, index, value);
  return head3;
}
    
  
  
  
  
