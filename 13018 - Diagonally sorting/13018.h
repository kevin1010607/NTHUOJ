#define min(a,b) ((a)<(b)?(a):(b))
void array2d_sort(int row, int col, long long arr[][500]){
    for(int s = -(col-1); s < 0; s++){
        int len = min(row, col+s);
        for(int k = 0; k < len-1; k++){
            for(int i = 0, j = -s, cnt = 0; cnt < len-1-k; i++, j++, cnt++){
                if(arr[i][j] > arr[i+1][j+1]){
                    long long temp = arr[i][j];
                    arr[i][j] = arr[i+1][j+1];
                    arr[i+1][j+1] = temp;
                }
            }
        }
    }
    for(int s = 0; s < row-1; s++){
        int len = min(col, row-s);
        for(int k = 0; k < len-1; k++){
            for(int i = s, j = 0, cnt = 0; cnt < len-1-k; i++, j++, cnt++){
                if(arr[i][j] > arr[i+1][j+1]){
                    long long temp = arr[i][j];
                    arr[i][j] = arr[i+1][j+1];
                    arr[i+1][j+1] = temp;
                }
            }
        }
    }
}