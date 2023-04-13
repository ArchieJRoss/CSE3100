#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    // TODO

    // create a pointer to the struct.
    thread_arg_t *my_data = p_arg;

    //init variables to for ease of reading.
    // Getting parameters for thread.
    int i = my_data->id;
    TMatrix *m = my_data->m;
    TMatrix *n = my_data->n;
    TMatrix *t = my_data->t;


    // loop through matrix m rows.
    while(i < m->nrows){

        //loop through matrix n cols and matrix m cols.
        for(int j = 0; j < n->ncols; j++){
            TElement sum = (TElement) 0;
            for(int k = 0; k < m->ncols; k++){
                sum += m->data[i][k] * n->data[k][j];
            }
            t->data[i][j] = sum;
        }
        // increment i by thread amounts.
        i += NUM_THREADS;
    } 
    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    int rc;
    pthread_t threads[NUM_THREADS];

    // init an array to store a thread arguments.
    thread_arg_t thread_args[NUM_THREADS];

    // Loop through the list.
	for(int i = 0; i < NUM_THREADS; i++ ) {
        thread_args[i].id = i;
        thread_args[i].m = m;
        thread_args[i].n = n;
        thread_args[i].t = t;
      
        rc = pthread_create(&threads[i], NULL, thread_main, &thread_args[i]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // thread join (wait).
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    return t;
}