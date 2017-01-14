
void matmul8x8(float *m1, int p1, float *m2, int p2, float *mo)
{
    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            *(mo+y*p2+x) = 0.0f;
        }
    }

    for(int idx = 0; idx < p1; idx+= 8){
        for(int y = 0; y < 8; y++){
            for(int x = 0; x < 8; x++){
                for(int idx2 = 0; idx2 < 8; idx2++){
                    *(mo+y*p2+x) += (*(m1+y*p1+(idx+idx2))) * (*(m2+(idx+idx2)*p2+x));
                }
            }
        }
    }
}
