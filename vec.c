
typedef float float8 __attribute__((ext_vector_type(8)));

#define PF_DIST 8
void matmul8x8(float *m1, int p1, float *m2, int p2, float *mo)
{
    float8 vrow[8];
    for(int y = 0; y < 8; y++){
        vrow[y] = (float8)0.0f;
    }

    for(int idx = 0; idx < p1; idx+= 8){
        float8 vm2[8];
        int ofs = idx*p2;
        int ofs2 = PF_DIST*p2;
        for(int y = 0; y < 8; y++, ofs+=p2){
            vm2[y] = *((float8*)(m2+ofs));
            __builtin_prefetch(m2+ofs+ofs2);
        }
        ofs = 0;
        for(int y = 0; y < 8; y++, ofs+=p1){
            float8 vm1 = *((float8*)(m1+ofs+idx));
            __builtin_prefetch(m1+ofs+idx+PF_DIST);
            vrow[y] += vm1.s0 * vm2[0];
            vrow[y] += vm1.s1 * vm2[1];
            vrow[y] += vm1.s2 * vm2[2];
            vrow[y] += vm1.s3 * vm2[3];
            vrow[y] += vm1.s4 * vm2[4];
            vrow[y] += vm1.s5 * vm2[5];
            vrow[y] += vm1.s6 * vm2[6];
            vrow[y] += vm1.s7 * vm2[7];
        }
    }
    int ofs = 0;
    for(int y = 0; y < 8; y++, ofs+=p2){
        *((float8*)(mo+ofs)) = vrow[y];
    }
}
