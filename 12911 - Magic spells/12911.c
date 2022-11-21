#include<stdio.h>
#include<string.h>
char A[1005], B[1005];
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s %s", A, B);
        int lenA = strlen(A), lenB = strlen(B);
        int idxA = lenA-1, idxB = 0, id = -1;
        while(1){
            int same = 1;
            for(int i = 0; i <= idxB; i++){
                if(A[idxA+i] != B[i]){
                    same = 0;
                    break;
                }
            }
            if(same) id = idxA;
            idxA--, idxB++;
            if(idxA<0 || idxB>=lenB) break;
        }
        if(id != -1) A[id] = '\0';
        printf("%s%s\n", A, B);
    }
    return 0;
}