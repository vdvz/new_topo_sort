#include <stdio.h>
#include <stdlib.h>


//Zeroing array
void zeroing_array(int *ar,int N){
    for(int i=0;i<N;i++){
        for(int j = 0 ;j<N;j++){
            *(ar+i*N+j)=0;
        }
    }
}

int found_zero(const int *ar,int N){
    int count;
    for(int i = 0;i<N;i++){
        count = 0;
        for(int j = 0;j<N;j++){
            if(*(ar+N*j+i)==0){
                count++;
            }
        }
        if(count == N){
            printf("%i",i);
            return i;
        }
    }
    //Out error_msg
    return 0;
}




int main() {
    //Scanning values of vertexis
    int N = 0;
    if(scanf_s("%i",&N) == EOF){
        printf("bad number of lines");
        return 0;
    }
    if(N < 0 || N > 1000){
        printf("bad number of vertices");
        return 0;
    }

    char * colour_ar=(char*)malloc(sizeof(char)*N);
    for(int i = 0;i<N;i++){
        *(colour_ar + i)='W';
    }


//Scanning values of ribs
    int M = 0;
    if(scanf_s("%i",&M) == EOF){
        printf("bad number of lines");
        return 0;
    }
    if(M==0){
        for(int i =1 ;i<=N;i++){
            printf("%i ",i);
        }
        return 0;
    }
    if(M < 0 || M > (N*(N-1)/2)){
        printf("bad number of edges");
        return 0;
    }

//Malloc memory and zeroing array
    int * ar = (int*)malloc(sizeof(int)*(N+1)*(N+1));
    zeroing_array(ar,N+1);

//Add graph_ribs with adjecency matrix
    int c1,c2;
    int count=0;
    while((scanf_s("%i",&c1)) != EOF){
        scanf_s("%i",&c2);
        if(c1<0 ||c1>N || c2<0 || c2>N){
            printf("bad vertex");
            return 0;
        }
        *(ar+(c1-1)*N+c2-1)+=1;
        *(ar+(N)*N+c2-1)+=1;
        getchar();
        count++;
    }
    if(count == 0){
        printf("bad number of lines");
        return 0;
    }


//    for(int i = 0;i <= N;i++){
//        for(int j = 0;j <= N;j++){
//            printf("%i ",*(ar+(i)*N+(j)));
//        }
//        printf("\n");
//    }
//    printf("\n");


    if(count > M+2 ){
        printf("bad number of lines");
        return 0;
    }
    int k = N;
    int k1 = 0;
    int e = 0;
    int * subar = (int*)malloc(sizeof(int)*(N));
    while(k!=0){
        for(int i = 0;i<N;i++) {
            if (*(ar + N * N + i) == 0) {
                subar[e]=i+1;
                e++;
                for (int j = 0; j < N; j++) {
                    if (*(ar + i * N + j) == 1) {
                        *(ar + i * N + j) = 0;
                        *(ar + N * N + j) -= 1;
                        k1++;
                    }
                }
                //Тут могут быть ошибки чекни это потом
                *(ar + N * N + i) = -1;
            }
        }
        k--;
    }
    if(k1==M){
        for(int i = 0;i<e;i++){
            printf("%i ",subar[i]);
        }
     }
    else{
        printf("impossible to sort");
        return 0;
    }



//    printf("\n");
//    for(int i = 0;i <= N;i++){
//        for(int j = 0;j <= N;j++){
//            printf("%i ",*(ar+(i)*N+(j)));
//        }
//        printf("\n");
//    }
    free(ar);
    free(subar);
    return 0;
}