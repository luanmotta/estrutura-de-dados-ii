/*
TITULO: Biblioteca com fun��es para calcular o tempo
DATA: 19/Mar�o/2012


ATEN��O. Nova fun��o tempo() para Windows. Agora creio que ela funciona.
Testem (mensagem de 2012)
*/

/* AGORA a fun��o funciona com precis�o de microssegundos tamb�m
 * para o Windows. Testado com SUCESSO no Dev++ (em 2012)
 */
#ifndef __TEMPO__
/* Sempre que se cria uma biblioteca � prudente usar um define para ela.
 * Veja, as defini��es abaixo s� ocorrer�o se N�O HOUVER AINDA a constante
 * __TEMPO__. Isto evita erros com duplas inclus�es, ou seja, dois ou mais
 * #include "tempo.h". Apenas o primeiro ter� efeito e os demais nada
 * definir�o. Todos os .h deveriam usar isto.
 * */
#define __TEMPO__

/* para muitos c�digos, um inteiro longo sem sinal � o ideal.
Se for um compilador de 32 bits, isto resultar� em um inteiro
de 32 bits. Por�m se for um compilador de 64 bits, ser� um inteiro
de 64 bits.

Crio um typedef pois � muita coisa ficar digitando unsigned long int
Assim, s� se coloca ulong
*/

#ifndef LINUX
typedef unsigned int ulong;
#endif

/* Se for usar ela no LINUX, insira um #define LINUX no in�cio do teu c�digo,
 * antes do include para o tempo.h
 * */
#ifdef LINUX
#include <sys/time.h>
#include <termios.h>
#include <time.h>
#define clrscr()    printf("\033[2J")

/* Parte exclusiva do Windows */
#else
#include <conio.h>
#include <time.h>
#include <windows.h>

/* Elgio em Mar�o de 2012 */
/* Fun��o tempo para Windows.
 * Descobri que tem como calcular quantos microssegundos se passaram
 * dentro do mesmo segundo!
 * Aliando isto a fun��o time que retorna quantos segundos, foi poss�vel
 * calcular */
ulong tempo()
{
    LARGE_INTEGER ticksPerSecond;
    static LARGE_INTEGER timeI, timeF;
    static unsigned int usec=0;

    QueryPerformanceFrequency(&ticksPerSecond);
    QueryPerformanceCounter(&timeF);

    /* Primeira invocacao */
    if (usec==0) {
       timeI=timeF;
       usec=1;
       return(0);
    }

    usec = ((double)(timeF.QuadPart-timeI.QuadPart)/ticksPerSecond.QuadPart)*1000000;

    QueryPerformanceCounter(&timeI);

    return usec;

}

#endif
/* Fim da parte exclusiva para Windows */


/* Agora para Linux 
 * Observa��o: retornar� LIXO na primeira invoca��o, pois
 * tf e ti n�o foram inicializados (n�o vejo problema nisto. Seria
 * f�cil corrigir, mas desnecess�rio. Como a fun��o retorna quanto
 * tempo se passou desde a �ltima invoca��o, na primeira deve-se
 * desconsiderar o retorno mesmo)
 * */
#ifdef LINUX
ulong tempo()
{
    static struct timeval ti, tf;
    ulong ms;

/* pega o tempo atual. */
    gettimeofday(&tf, NULL);

    ms = (tf.tv_sec - ti.tv_sec) * 1000000 + (tf.tv_usec - ti.tv_usec);

    gettimeofday(&ti, NULL); 
    // Ajusta ti que ficar� com este valor na pr�xima invoca��o, pois ti � est�tico
    
    /* retorna o tempo que se passou em microsegundos
       1s = 1.000.000 us
     */
    return (ms);
}
#endif

/* Retorna uma string com o tempo formatado em  seg,  mseg e useg */
char *formata(ulong m)
{
    static char tempo[30];
    ulong s, ms, us;

    s = m / 1000000;
    ms = (m % 1000000) / 1000;
    us = (m % 1000);

    sprintf(tempo, "%02lus %03lums %03luus", s, ms, us);
    return (tempo);
}
#endif

/* Dispon�vel como tempo.h
 * Para usar coloque o tempo.h no mesmo diret�rio do teu c�digo fonte e 
 * inclua ele da seguinte forma:
 * 
 * #include "tempo.h"
 * 
 */