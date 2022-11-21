int cmp(const void* a, const void* b){
    const int* ia = (const int*)a;
    const int* ib = (const int*)b;
    return (*ia<*ib)-(*ia>*ib);
}