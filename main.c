#include <time.h>
#include <string.h>
#include "lbp.h"
#include "pgm.h"
#include <dirent.h>
#include <stdio.h>

void imprimirVetor(unsigned char *p, int t);
int main(void){
    struct pgm img;
    /* char bin[(img.c*img.r)][9];
    int *dec;
    dec = malloc((img.c*img.r)*sizeof(int)); */
    DIR *d;
    struct dirent *dir;
    d = opendir("./datasets");
    if (d){
        while ((dir = readdir(d)) != NULL){  
            if(strstr(dir->d_name, ".pgm")){
                //lendo imagem
                char aux[50];
                strcpy(aux, "datasets/");
                char *path = strcat(aux, dir->d_name);
        
                readPGMImage(&img, path);
                printf("%s\n",path);

                //lbp
                //gerarBinarios(img.pData, bin, img.r, img.c);
                //binParaDec(bin, img.r, img.c, dec);
                /* for (int k=0; k<(img.r*img.c); k++){
                    imprimirVetor(&img.pData[k], (img.r*img.c));
                }  */             
            }
        }   
        closedir(d);
    }
    return(0);
}	
void imprimirVetor(unsigned char *p, int t){
    for (int k=0; k<t; k++){
        printf("[%p] : %d\n",p+k,*(p + k));
    }
}