#include <stdio.h>
#include <errno.h>

#include "ax12driver.h"
#include "header.h" //il faudrait renommer le fichier, c'est trop général header.h


#define BAUDRATE 9600
#define MAIN_AX12_ID  x
#define SECOND_AX12_ID  x

static char lock = 1;
static char lock2 = 1;
static int current_point = 0;
static int number_points = 0;
static float* angles = NULL;


//à compléter pour le levé de crayon (autre AX ?)
void lift_pencil()
{}

//à compléter pour le posé de crayon (autre AX ?)
void put_pencil()
{}

void end_of_move()
{lock = 0;}

void end_of_move_bis()
{lock2 = 0;}

void block_until_point(float alpha, float beta)
{
    AX12move(MAIN_AX12_ID, alpha, &end_of_move);
    AX12move(SECOND_AX12_ID, beta, &end_of_move_bis);
}

void draw()
{
    AX12move(MAIN_AX12_ID, angles[current_point*2], &end_of_move);
    AX12move(SECOND_AX12_ID, angles[current_point*2+1], &end_of_move);
    current_point++;
}

void start_drawing()
{}


int main(int argc, char* argv[])
{
    if(argc<2)
    {
        if(argc>0)
            printf("[?] Usage: %s <filename>\n", argv[0]);
        else
            printf("[?] Usage: <filename>\n", argv[0]);
        return 0;
    }

    if(initAX12(BAUDRATE)<0)
    {
        fprintf(stderr, "[-] Error during ax12 initialization\n");
        exit(1);
    }

    number_points = getNbPoints(argv[1]);
    if(number_points<=0)
    {
        fprintf(stderr, "[-] Error: not enough points\n");
        exit(1);
    }

    angles = (float*)malloc(sizeof(float)*2*number_points);

    if(!angles)
    {
        perror("[-] Error during malloc :");
        exit(1);
    }

	parsing(argv[1], angles);

    printf("[+] Lifting pencil\n");
    lift_pencil();
    printf("[+] Moving to first point\n");
    block_until_point(angles[0],angles[1]);
    while(lock||lock2)
        ;

    printf("[+] Puting pencil on paper\n");
    put_pencil();

    current_point++;
    while(current_point<number_points)
        if(!lock)
        {
            printf("[+] Going to point %d\n", current_point+1);
            lock = 1;
            draw();
        }

    while(lock)
        ;

    free(angles);

    return 0;
}
