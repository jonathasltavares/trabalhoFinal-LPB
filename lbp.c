#include "lbp.h"

void gerarBinarios(unsigned char *ma, char b[][9], int l, int c){
    for(int i=0;i<((l*c));i++){  
        //bordas laterais esquerda
        if(i%c == 0){
            if(i==0){
                //a
                strcat(b[i], "0");
                //b
                strcat(b[i], "0");
                //c
                strcat(b[i], "0");
                //d
                *(ma+(i+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //e
                *(ma+((i+c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //f
                *(ma+(i+c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //g
                strcat(b[i], "0");
                //h
                strcat(b[i], "0");

            }
            else if(i==((l*c)-c)){
                //a 
                strcat(b[i], "0");
                //b
                *(ma+(i-c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //c
                *(ma+((i-c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //d
                *(ma+(i+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //e
                strcat(b[i], "0");
                //f
                 strcat(b[i], "0");                   
                //g
                strcat(b[i], "0");
                //h
                strcat(b[i], "0");          
            }
            else{
                //a 
                strcat(b[i], "0");
                //b
                *(ma+(i-c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //c
                *(ma+((i-c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //d
                *(ma+(i+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //e
                *(ma+((i+c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //f
                *(ma+(i+c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //g
                strcat(b[i], "0");
                //h
                strcat(b[i], "0");
            }
        }    
        //borda lateral direita
        else if(i%(c) == 0 || (i+1)%(c)==0){
            if(i==(c-1)){
                //a
                strcat(b[i], "0");
                //b
                strcat(b[i], "0");
                //c
                strcat(b[i], "0");
                //d
                strcat(b[i], "0");          
                //e
                strcat(b[i], "0");         
                //f
                *(ma+(i+c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //g
                *(ma+((i+c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");           
                //h
                *(ma+(i-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            }
            else if(i==((l*c)-1)){
                //a
                *(ma+((i-c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0"); 
                //b
                *(ma+(i-c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //c
                strcat(b[i], "0");
                //d
                strcat(b[i], "0");          
                //e
                strcat(b[i], "0");         
                //f
                strcat(b[i], "0");       
                //g
                strcat(b[i], "0");           
                //h
                *(ma+(i-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            }
            else{
                //a
                *(ma+((i-c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0"); 
                //b
                *(ma+(i-c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //c
                strcat(b[i], "0");
                //d
                strcat(b[i], "0");          
                //e
                strcat(b[i], "0");         
                //f
                *(ma+(i+c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
                //g
                *(ma+((i+c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");           
                //h
                *(ma+(i-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            }
        }
        //borda superior
        else if(i<=c && i!=c && i!=0){
            //a
            strcat(b[i], "0");        
            //b
            strcat(b[i], "0");
            //c   
            strcat(b[i], "0");
            //d
            *(ma+(i+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //e
            *(ma+((i+c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //f
            *(ma+(i+c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //g
            *(ma+((i+c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");           
            //h
            *(ma+(i-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
        }
        //borda inferior
        else if(i>=((l*c)-c-1) && i!=(l*c-1) && i!=((l*c)-c-1)){
            //a
            *(ma+((i-c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0"); 
            //b
            *(ma+(i-c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //c
            *(ma+((i-c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //d
            *(ma+(i+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //e
            strcat(b[i], "0");
            //f
            strcat(b[i], "0");
            //g
            strcat(b[i], "0");
            //h
            *(ma+(i-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");       
        }
        else{
            //a
            *(ma+((i-c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0"); 
            //b
            *(ma+(i-c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //c
            *(ma+((i-c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //d
            *(ma+(i+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //e
            *(ma+((i+c)+1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //f
            *(ma+(i+c))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            //g
            *(ma+((i+c)-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");           
            //h
            *(ma+(i-1))>=*(ma+i) ? strcat(b[i], "1") : strcat(b[i], "0");
            
        } 
    }
}

void binParaDec(char a[][9], int l, int c, int *d){
    for(int i=0;i<=((c*l)-1);i++){
        int aux = 0;
        for(int j=0; j<=8;j++){
            if(a[i][j] == '1'){
                aux += pow(2, j);
            }          
        }  
        *(d+i) = aux;
    }
}

void histograma(){
    
}