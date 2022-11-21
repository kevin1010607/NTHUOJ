#include<iostream>
#include<queue>
using namespace std;
typedef struct{int l, hp, mhp, cnt;}node;
queue<node> q;
int L, HP, MHP, MDMG, DMG[20], HL[20], used[20][305][405];
int main(void){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> L >> HP >> MHP >> MDMG;
    for(int i = 1; i <= L; i++) cin >> DMG[i] >> HL[i];
    q.push(node{1, HP, MHP, 0});
    while(q.size()){
        node n = q.front(); q.pop();
        if(n.mhp == 0) {cout << n.cnt << '\n'; return 0;}
        if((n.hp-MDMG>0 || n.mhp-DMG[n.l]<=0) && !used[n.l][max(0, n.hp-MDMG)][max(0, n.mhp-DMG[n.l])]){
            q.push(node{n.l, max(0, n.hp-MDMG), max(0, n.mhp-DMG[n.l]), n.cnt+1});
            used[n.l][max(0, n.hp-MDMG)][max(0, n.mhp-DMG[n.l])] = 1;
        }
        if(min(HP, n.hp+HL[n.l])-MDMG>0 && n.hp!=HP && !used[n.l][min(HP, n.hp+HL[n.l])-MDMG][n.mhp]){
            q.push(node{n.l, min(HP, n.hp+HL[n.l])-MDMG, n.mhp, n.cnt+1});
            used[n.l][min(HP, n.hp+HL[n.l])-MDMG][n.mhp] = 1;
        }
        if(n.hp-MDMG>0 && n.l<L && !used[n.l+1][n.hp-MDMG][n.mhp]){
            q.push(node{n.l+1, n.hp-MDMG, n.mhp, n.cnt+1});
            used[n.l+1][n.hp-MDMG][n.mhp] = 1;
        }
    }
    cout << "-1\n";
    return 0;
}