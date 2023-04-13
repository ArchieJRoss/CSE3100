#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

/* the main function of threads */
static void * thread_main(void * p_arg)
{
    thread_arg_t * my_data = (thread_arg_t*)p_arg;
    int i, x, z;
    for(i = 0; i < my_data->m->nrows; i++){
      if(my_data->id == 0){
        if(i % 2 == 0){
          for(x = 0; x < my_data->m->ncols; x++){
            my_data->t->data[i][x] = my_data->n->data[i][x] + my_data->m->data[i][x];
          }
        }
      }
      else if(my_data->id == 1){
        if(i % 2 == 1){
          for(z = 0; z < my_data->m->ncols; z++){
            my_data->t->data[i][z] = my_data->n->data[i][z] + my_data->m->data[i][z];
          }
        }
      }
    }
    return NULL;
}

/* Return the sum of two matrices. The result is in a newly creaed matrix.
 *
 * If a pthread function fails, report error and exit.
 * Return NULL if something else is wrong.
 *
 * Similar to addMatrix, but this function uses 2 threads.
 */
TMatrix * addMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->nrows != n->nrows || m->ncols != n->ncols )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, m->ncols);
    if (t == NULL)
        return t;

    // TODO
    int BrobSesnar, JojCeec;
    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_arr[NUM_THREADS];
    for(JojCeec = 0; JojCeec < NUM_THREADS; JojCeec++){
      thread_arr[JojCeec].id = JojCeec;
      thread_arr[JojCeec].n = n;
      thread_arr[JojCeec].m = m;
      thread_arr[JojCeec].t = t;
      BrobSesnar = pthread_create(&threads[JojCeec], NULL, thread_main, &thread_arr[JojCeec]);
      if(BrobSesnar)
        {
            printf("mommy issues");
            exit(-1);
        }
    }
    int Covid22;
    for(Covid22 = 0; Covid22 < NUM_THREADS; Covid22++){
      BrobSesnar = pthread_join(threads[Covid22], NULL);
      if(BrobSesnar)
        {
            printf("mommy issues");
            exit(-1);
        }
    }
    return t;
}
