#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "matmul8x8.h"

void matmul(float *m1, int w1, int h1, float *m2, int w2, int h2, float *mo)
{
    if(w1 != h2){
        printf("wrong width/height\n");
        return;
    }
    for(int y = 0; y < h1; y++){
        for(int x = 0; x < w2; x++){
            float val = 0.0f;
            for(int idx = 0; idx < w1; idx++){
                val += (*(m1+y*w1+idx))*(*(m2+idx*w2+x));
            }
            if(*(mo+y*w2+x) != val){
                printf("diff result %f %f\n", *(mo+y*w2+x), val);
                return;
            }
        }
    }
    printf("ok!\n");
}

#define W1 512
#define H1 512
#define W2 512
#define H2 512

void fillbuf(float *buf, int len)
{
    for(int idx = 0; idx < len; idx++)
        buf[idx] = (float)(rand());
}

int main(void)
{
    float *m1 = (float*)aligned_alloc(64, sizeof(float)*W1*H1);
    float *m2 = (float*)aligned_alloc(64, sizeof(float)*W2*H2);
    float *mo = (float*)aligned_alloc(64, sizeof(float)*W2*H1);

    srand(time(NULL));
    fillbuf(m1, W1*H1);
    fillbuf(m2, W2*H2);
    fillbuf(mo, W2*H1);
    printf("init done\n");

    struct timeval s_time, e_time;
    gettimeofday(&s_time, NULL);
    for(int y = 0; y < H1; y+=8){
        for(int x = 0; x < W2; x+=8){
            matmul8x8(m1+y*W1, W1, m2+x, W2, mo+y*W2+x);
        }
    }
    gettimeofday(&e_time, NULL);
    printf("exec %lld us\n", (e_time.tv_sec - s_time.tv_sec)*1000000ULL + (e_time.tv_usec - s_time.tv_usec));

    matmul(m1, W1, H1, m2, W2, H2, mo);

    free(m1);
    free(m2);
    free(mo);
}
