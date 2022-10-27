#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Ponto;

void atualizarCoordenadas(Ponto *p)
{
    p->x = p->x * 10;
    p->y = p->y * 10;

}

int main(void)
{
    Ponto p1 = {1,2};
    
    atualizarCoordenadas(&p1);

    printf("\nAs coordenadas de P1 eh x = %d e y = %d", p1.x, p1.y);

    return 0;
} 
