#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define maxn 100005
typedef struct{
    int id;
    int total_ac;
    int total_penalty;
    int num_sub[10];
    int penalty[10];
    bool sub[10];
    bool ac[10];
}Student;
Student st[maxn];
int used[maxn], idx = 1;
int getTime(char *c){
    int h = 10*(c[-2]-'0')+(c[-1]-'0');
    int m = 10*(c[1]-'0')+(c[2]-'0');
    return 60*h+m;
}
int getId(char *c){
    int ans = 0;
    while(isdigit(*c)){
        ans = 10*ans+(*c-'0');
        c++;
    }
    return ans;
}
int cmp(const void *a, const void *b){
    const Student *sa = (const Student*)a;
    const Student *sb = (const Student*)b;
    if(sa->total_ac<sb->total_ac) return 1;
    else if(sa->total_ac==sb->total_ac && sa->total_penalty>sb->total_penalty) return 1;
    else if(sa->total_ac==sb->total_ac && sa->total_penalty==sb->total_penalty && sa->id>sb->id) return 1;
    return -1;
}
void storeData(int, int, int, int);
void printData();
int main(void){

    char s[105];
    int T = 11;
    while(T--) fgets(s, sizeof(s), stdin);
    while(true){
        int time, id, prob, ac, L;
        //time
        fgets(s, sizeof(s), stdin);
        L = strlen(s);
        for(int i = 0; i < L; i++){
            if(s[i] == ':') {
                time = getTime(s+i);
                break;
            }
        }
        //printf("%d\n", time);
        //id
        fgets(s, sizeof(s), stdin);
        L = strlen(s);
        for(int i = 0; i < L; i++){
            if(isdigit(s[i])){
                id = getId(s+i);
                break;
            }
        }
        //printf("%d\n", id);
        //prob
        fgets(s, sizeof(s), stdin);
        L = strlen(s);
        for(int i = 0; i < L; i++){
            if(isupper(s[i])){
                prob = s[i]-'A';
                break;
            }
        }
        //printf("%d\n", prob);
        //ac;
        fgets(s, sizeof(s), stdin);
        L = strlen(s);
        for(int i = 0; i < L; i++){
            if(s[i] == 'A'){
                ac = 1;
                break;
            }
            if(s[i] == 'W'){
                ac = 0;
                break;
            }
        }
        //printf("%d\n", ac);
        //check
        fgets(s, sizeof(s), stdin);
        fgets(s, sizeof(s), stdin);
        L = strlen(s);
        bool end = false;
        for(int i = 0; i < L; i++){
            if(s[i] == '/'){
                end = true;
                break;
            }
        }
        storeData(time, id, prob, ac);
        if(end){
            fgets(s, sizeof(s), stdin);
            break;
        }
    }
    qsort(st+1, idx-1, sizeof(Student), cmp);
    printData();
    return 0;
}
void storeData(int time, int id, int prob, int ac){
    if(used[id] == 0){
        st[idx].id = id;
        st[idx].sub[prob] = true;
        st[idx].num_sub[prob]++;
        if(ac){
            st[idx].ac[prob] = true;
            st[idx].penalty[prob] = time;
            st[idx].total_ac++;
            st[idx].total_penalty += time;
        }
        used[id] = idx;
        idx++;
    }
    else if(st[used[id]].ac[prob] != true){
        int tmp = used[id];
        st[tmp].sub[prob] = true;
        st[tmp].num_sub[prob]++;
        if(ac){
            st[tmp].ac[prob] = true;
            st[tmp].penalty[prob] = 20*(st[tmp].num_sub[prob]-1)+time;
            st[tmp].total_ac++;
            st[tmp].total_penalty += st[tmp].penalty[prob];
        }
    }
}
void printData(){
    for(int i = 1; i < idx; i++){
        printf("%d ", st[i].id);
        for(int j = 0; j < 10; j++){
            if(st[i].sub[j]) printf("%d", st[i].num_sub[j]);
            else printf("-");
            printf("/");
            if(st[i].ac[j]) printf("%d ", st[i].penalty[j]);
            else printf("- ");
        }
        printf("%d %d\n", st[i].total_ac, st[i].total_penalty);
    }
}