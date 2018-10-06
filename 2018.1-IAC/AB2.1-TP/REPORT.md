# Identificação

* Página do repositório do trabalho (<a href="https://github.com/etm1996/teaching/tree/master/2018.1-IAC/AB2.1-TP">GitHub</a>)

* Discente 1
	* Nome: Eduardo Tenório Monteiro
	* Matrícula: 18110628
* Discente 2
	* Nome: Luis Otávio S. de Oliveira
	* Matrícula: 17110133
* **Obs.: Dividir igualmente as notas entre os participantes.**

# Resultados

Gráfico de consumo intenso da UCP (%):

![alt text](https://github.com/etm1996/teaching/blob/master/2018.1-IAC/AB2.1-TP/src/cpu.jpg "Gráfico de consumo da UCP")


Gráfico de consumo de memória (KB):

  <img src="src/memoria.jpg">


# Discussão

## Começando o programa

Começamos utilizando a função fork(), para criar o processo filho que será idêntico ao pai (programa em C que está sendo executado), inclusive tendo as mesmas variáveis, registros, descritores de arquivos etc.
Ou seja, o processo filho é uma cópia do pai, exatamente igual. A função retornará um número chamado **pid**(process identification). Cada processo terá um **pid** diferente. Se o fork retornar um **pid** com valor menor que zero, o fork deu errado, o processo falha e o programa "exita". Se o **pid** for maior que zero ele entrará no processo pai, e se for igual a zero ele entrará no processo filho.

## Utilização intensa da UCP

Utilizando **"if(strcmp(argv[1], "ucp") == 0)"** definimos que para entrar nesse processo o usuário deve digitar "ucp" logo após o nome do programa. Analisando o gráfico de uso intenso da UCP, percebe-se que no primeiro segundo a utilização do processador já beira os 102%, o que não era esperado, pois achava-se que seria uma elevação mais linear. Para conseguir a soma do uso de todos os núcleos do processador utilizamos o comando "ps -p ", pid, " -o %cpu | grep -v %CPU". A partir do quarto segundo a porcentagem de utilização da UCP diminuiu e foi aumentando vagarosamente, como tínhamos esperado.

## Utilização intensa da UCP e memória

O programa foi compilado e rodado em um notebook com 6GB de RAM. No começo estávamos com bastante dificuldade pois estávamos utilizando **malloc**(100000), o que estava resultando numa alocação de memória absurda e o programa estava alocando mais memória que a quantidade suportada pelo computador, congelando e só descongelando ao reinicializar.
A solução encontrada para o citado problema foi substituir pelo "**malloc**(10*sizeof(int));" fazendo com que a memória alocada fosse suportada pelo computador. Utilizamos também a função **clock** da biblioteca **<time.h>** para limitar o número de vezes em que a memória era alocada por segundo durante os 10 segundos. A função **"kill(pid, SIGKILL)"** foi utilizada em vez de **"kill -9"** por motivos de simplificação do código. Sigkill causa uma terminação no processo PID que não pode ser ignorada.
