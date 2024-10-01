#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região 
#include <string.h> // biblioteca responsável por cuidar das strings

int registro () // função responsavel por cadastrar os user no sistema
{
	// inicio criação de variáveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser Cadastrado: "); // coletando inf. do user
	scanf ("%s", cpf); // %s usa para salvar a variavel/string
		
		strcpy(arquivo, cpf); // responsável por copiar as string
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo - e o "w" é escrever
		fprintf(file,cpf); // salva o valor da variavel - add "CPF"
		fclose(file); // fecho o arquivo
		
	    file = fopen(arquivo, "a"); // "a" Atualizar o arquivo
	    fprintf(file,","); // salva o valor da variavel - add ","
	    fclose(file); // fecha o arquivo 
	
	printf("\n Digite o nome a ser cadastrado: "); // coletando nome do user
	scanf("%s",nome); // %s usa para salvar a variavel/string
	
	    file = fopen(arquivo,"a"); // "a" atualiza o arquivo
	    fprintf(file,nome); // salvando o valor da variavel - add "nome"
	    fclose(file); // fecha o arquivo
	    
	    file = fopen(arquivo, "a"); // atualiza o arquivo
	    fprintf(file,","); // salvando o valor da variavel - add ","
	    fclose(file); // fechando arquivo
	    
	printf("\n Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // %s usa para salvar a variavel/string

        file = fopen(arquivo, "a"); // "a" atualiza o arquivo
        fprintf(file, sobrenome); // salvando o valor da vairavel - add sobrenome
        fclose(file); // fechando o arquivo
        
        file = fopen(arquivo, "a"); // "a" atualizar o arquivo
	    fprintf(file,","); // salvando o valor da variavel - add ","
	    fclose(file); // fechando o arquivo
	    
	printf("\n Digite o cargo a ser cadastrado: \n ");
	scanf("%s", cargo); // %s usa para salvar a variavel/string
	
	    file = fopen(arquivo, "a"); // "a" atualizando o arquivo
	    fprintf(file, cargo); // salvando o valor da variavel - add "cargo"
	    fclose(file); // fechando o arquivo
	    
	    system ("pause"); 
        
		
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // %s usa para salvar a variavel/string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // "R" Ler o arquivo	
	
	if(file == NULL)
	{
		printf("Arquivo não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL ) // While = Enquanto
	{
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);  // %s usa para salvar a variavel/string
	
	remove(cpf); // remover o arquivo
	
	FILE *file; // 
	file = fopen(cpf, "r"); 
	
	if(file == NULL)
	{
	   
	   printf("O usuário não se encontra no sistema!\n");
	   system("pause"); // comando para pausar na tela e usuário ler a mensagem
	   
	}
}



int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
	
	  system("cls"); // responsavel por limpar a tela 
	
	  setlocale(LC_ALL, "Portuguese"); // Definindo a liguagem
	
	
	  printf(" ### Cartório da EBAC ### \n\n"); // Inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t 1 - Registrar nomes \n");
	  printf("\t 2 - Consultar nomes \n");
	  printf("\t 3 - Deletar nomes \n\n\n");
	  printf("\t Opção:"); // fim do menu
	
	  scanf("%d", &opcao); // armazenando a escolha do usuário
	
	  system("cls"); // responsalvel po limpar a tela
	
	  switch(opcao) // inicio da seleção do menu
	  {
	  	case 1:
	  	registro(); // chamada de função
		break;
		
		case 2:
		consulta(); // chamada de função
		break;
		
		case 3:
		deletar(); // chamada de função
		break;
		
		default:
		printf("Opção não disponível!\n");
		system("pause"); 
		break;
			
	  }
	
	
     }
}
