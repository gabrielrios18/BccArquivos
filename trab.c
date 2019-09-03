#include <stdio.h>
#include <string.h>
 
typedef struct _Endereco Endereco;
 
struct _Endereco
{
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char uf[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
};
 
int main(int argc, char**argv)
{
    FILE *f;
    Endereco e;
    int qt;
 	long TamArq,inicio,meio,fim;
    bool achou = false;
    
    if(argc != 2)
    {
        fprintf(stderr, "USO: %s [CEP]", argv[0]);
        return 1;
    }
    
 
 	f = fopen("cep_ordenado.dat","r");
	inicio=0;
    fseek(f,0,SEEK_END);
    TamArq = ftell(f);
    fim = (TamArq/sizeof(Endereco))-1;
    
	i = 0
	
while(inicio <= fim && !achou){
	i++;
	meio = (inicio+fim)/2;
	fseek(f, meio * sizeof(Endereco), SEEK_SET);
    qt = fread(&e, sizeof(Endereco), 1, f);
    
	 if(strncmp(argv[1],e.cep,8)==0)
        {
        	achou=true;
            printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
            break;
        }
        else if(strncmp(argv[1],e.cep,8) > 0){
            inicio = meio + 1;
        }
        else
         fim = meio -1; 
		        }
    
    
    if(!achou){
        printf("CEP nao está no arquivo");
    }
    printf("Numero de ceps verificados :%d", i);
    
    fclose(f);
    return 0;
}
