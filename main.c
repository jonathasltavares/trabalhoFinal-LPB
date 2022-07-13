#include <time.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include "lbp.h"
#include "pgm.h"

#define QTDIMG 656

int main(){
	int k;
	clock_t begin, end;
	double time_per_img, time_total=0;
	long long int a = 999999999;
  
  int *dec = NULL;
  struct pgm img;
  FILE *arqHist;
  if (!(arqHist = fopen("histogram.txt", "w"))) {
	  printf("Unavailable histogram file.\n");
    exit(1);
  }
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
        char tipoImg[2];     
        memcpy(tipoImg, &dir->d_name[0], 1);
        dec = malloc((img.c*img.r)*sizeof(int));
        
        begin = clock();
        //lbp 
        gerarBinarios(img.pData, img.r, img.c, dec);   
        end = clock();
		    time_per_img = (double)(end - begin) / CLOCKS_PER_SEC;
        time_total += time_per_img;
        //histograma
        verificar(tipoImg, dec, img.mv, img.r, img.c, arqHist);
        free(dec);               
      }       
    }   
    closedir(d);        
  }
printf("Tempo médio: %lf\n",time_total/QTDIMG);
printf("Tempo Total: %lf\n",time_total);
fclose(arqHist);
return(0);
}