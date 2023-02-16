include <stdio.h>
#include <time.h> //necessário para usar localtime() e struct tm

int main(void)
{
    
/*struct tm 
int tm_sec; //representa os segundos de 0 a 59
int tm_min; //representa os minutos de 0 a 59
int tm_hour; //representa as horas de 0 a 24
int tm_mday: //dia do mês de 1 a 31
int tm_mon; //representa os meses do ano de 0 a 11
int tm_year; //representa o ano a partir de 1900
int tm_wday; //dia da semana de 0 (domingo) até 6 (sábado)
int tm_yday; // dia do ano de 1 a 365
int tm_isdst; //indica horário de verão se for diferente de zero
*/


  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;     
  
  //variável do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a função localtime  
  data_hora_atual = localtime(&segundos);  
  
  //para acessar os membros de uma struct usando o ponteiro
  //utilizamos o operador -> no nosso caso temos: 
  //data_hora_atual->membro_da_struct
  
  //Acessando dados convertidos para a struct data_hora_atual  
  printf("Dia..........: %d\n", data_hora_atual->tm_mday);  
  
  //para retornar o mês corretamente devemos adicionar +1 no membro da struct
  printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
  
  //para retornar o ano corretamente devemos adicionar 1900 no membro da struct
  printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);  
  
  printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);  
  printf("\nDia da semana: %d\n\n", data_hora_atual->tm_wday);
    
  /* Obtendo os valores da struct data_hora_atual  
    e formatando a saída de dados no formato 
    hora: minuto: segundo*/

  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d\n",data_hora_atual->tm_sec);//segundo  
  
  /* Obtendo os valores da struct data_hora_atual  
     e formatando a saída de dados no formato dia/mes/ano */  
  //dia do mês
  printf("\nData ........: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mês
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano
  
  return 0;
}


/*
FORMA RESUMIDA
#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm *p;
    time_t seconds;

    time(&seconds);
    p = localtime(&seconds);

    printf("Dia do ano: %d\n", p->tm_yday);
    printf("Data: %d/%d/%d\n", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900);
    printf("Hora: %d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);

    printf("\nGeral: %s\n", ctime(&seconds));

    return 0;
}*/