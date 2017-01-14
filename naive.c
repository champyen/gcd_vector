
void matmul8x8(float *m1, int p1, float *m2, int p2, float *mo)
{
    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            float val = 0.0f;
            for(int idx = 0; idx < p1; idx++){
                val += (*(m1+y*p1+idx)) * (*(m2+idx*p2+x));
            }
            *(mo+y*p2+x) = val;
        }
    }
}
