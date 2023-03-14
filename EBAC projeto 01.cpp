#include <stdio.h> //biblioteca de comunic��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca reponsavel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio de cria��o de variaveis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis
    
    printf("Digite o cpf para cadastro"); //coletando informa��es de usuarios
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar valores das string
    
    FILE *file; //cria arquivo 
	file = fopen(arquivo, "w"); //cria arquivo e "w" segnifica escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("digite o nome para cadastro: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("digite o sobrenome para cadastro: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("digite o cargo para cadastro: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");
	
    char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf para consulta");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
		
}

int deletar()
{
    char cpf[40];
	
	printf("digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuario n�o se encontra no sistema! .\n");
		system("pause");
	}	
}



int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  
	  system("cls"); // responsavel por limpar a tela
	
	  setlocale(LC_ALL,"portuguese"); //definindo linguagem
	
	  printf("### cart�rio da EBAC ###\n\n"); //inicio do menu
	  printf("escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - consultar nomes\n");
	  printf("\t3 - Deletar nomes\n"); 
	  printf("op��o: "); //fim do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usuario
	
	  system("cls");
	  
	  
	  switch(opcao) //inicio da sele��o dos menu
	  {
	  	 case 1:
	  	 registro(); //chamada de fun��o	
	  	 break;
		   
		 case 2:
		 consulta();
		 break;
		 
		 case 3:
		 deletar();	
		 break;
		 
		 default:
		 printf("essa op��o n�o esta disponivel!\n");
		 system("pause");
		 break;  	
	  	 } //fim da sela��o
	
    }
}
