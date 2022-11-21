#include<stdlib.h>
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***ptn = (unsigned***)malloc(n*sizeof(unsigned**)+n*m*sizeof(unsigned*)+n*m*k*sizeof(unsigned));
    unsigned **ptm = (unsigned**)(ptn+n);
    unsigned *ptk = (unsigned*)(ptn+n+n*m);
    for(int i = 0; i < n; i++){
        ptn[i] = &ptm[m*i];
        for(int j = 0; j < m; j++)
            ptn[i][j] = &ptk[k*m*i+k*j];
    }
    return ptn;
}
void delete_3d_array(unsigned ***arr){
    free(arr);
}
