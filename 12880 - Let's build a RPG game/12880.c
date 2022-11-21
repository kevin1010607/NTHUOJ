#include<stdio.h>
int main(void){
    int p[3];
    int e[3];
    scanf("%d %d %d", &p[0], &p[1], &p[2]);
    scanf("%d %d %d", &e[0], &e[1], &e[2]);

    printf("Battle Start \\^_^/\n");
    while(p[0] > 0 && e[0] > 0){
        int p_to_e = p[1]-e[2];
        int e_to_p = e[1]-p[2];
        printf("The player dealt %d damage to the enemy and the enemy dealt %d damage to the player\n", p_to_e, e_to_p);
        p[0] -= e_to_p;
        e[0] -= p_to_e;
        printf("The player has %d HP left and the enemy has %d HP left\n", p[0], e[0]);
    }
    printf("Battle End \\^_^/\n");

    return 0;
}