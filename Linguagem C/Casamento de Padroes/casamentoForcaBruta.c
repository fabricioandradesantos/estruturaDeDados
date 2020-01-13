#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//texto -> n
//padrão -> m

int busca_padao(char t[],int n,char p[],int m){
    int i = 0, j = 0;
    for(i = 0; i<=n-m; i++){
        j = 0;
        while((j<m) && (t[i+j] == p[j]) ){
              j = j +1;
              if(j == m)
                return i;
              }
    }
    return 0;
}


int main(){
    int n = 0, m = 0, valor = -1;
    char p[10];
    char t[] = "Se Deus quiser, vou vou passar em todas as materias";
    printf("%s\n\n",t);

    printf("\nDigite o que se deseja buscar: ");
    scanf("%s",p);

    n = strlen(t);
    m = strlen(p);


    valor = busca_padao(t, n, p, m);
    if ( valor == -1 ){
        printf("\nfunção com problema");
    }else if(valor == 0){
        printf("\nNão encontrado padrão");
    }else{
        printf("\nEncontrado padrão na casa %d", valor);

    }

getchar();

}
