#include <stdio.h>
#include <pthread.h>
#include <math.h>

struct thread_args //struct for argument input in threads
{
    int a;
    int b;
    int v;
    float l;
    int x;
};

void *elx(void *la)
{
    int i;
    struct thread_args *arguments = la;
    float c = arguments->l;
    int max1 = arguments->x;
    double rest = 0;
    for (i = 1; i <= max1; i++)
    {
        rest = exp(-c*i);
        printf("THREAD 1 (exp(-lamda*x) RESULT (X=%d) :%1.10lf \n", i, rest);
        if (i == 1)
        {
            FILE *f1 = fopen("ELX.txt", "w");
            if (f1 == NULL)
            {
                printf("Error opening file!\n");
                return(1);
            }
            fprintf(f1, "exp(-%.2f*%d)= %f\n", c, i, rest);
            fclose(f1);
        }
        else
        {
            FILE *f1 = fopen("ELX.txt", "a");
            if (f1 == NULL)
            {
                printf("Error opening file!\n");
                return(1);
            }
            fprintf(f1, "exp(-%.2f*%d)= %f\n", c, i, rest);
            fclose(f1);
        }
    }
    free(arguments);
    return NULL;
}

void *ax2(void *argp)
{
    int j;
    struct thread_args *arguments = argp;
    int d = arguments->a;
    int e = arguments->b;
    int max2 = arguments->x;
    int rest2 = 0;
    for (j = 1; j <= max2; j++)
    {
        rest2 = d*j*j+e*j;
        printf("THREAD 2 (ax^2+bx) RESULT (X=%d) :%d \n", j, rest2);
        if (j == 1)
        {
            FILE *f2 = fopen("AX.txt", "w");
            if (f2 == NULL)
            {
                printf("Error opening file!\n");
                return(1);
            }
            fprintf(f2, "%d*%d^2+%d*%d= %d\n", d, j, e, j, rest2);
            fclose(f2);
        }
        else
        {
            FILE *f2 = fopen("AX.txt", "a");
            if (f2 == NULL)
            {
                printf("Error opening file!\n");
                return(1);
            }
            fprintf(f2, "%d*%d^2+%d*%d= %d\n", d, j, e, j, rest2);
            fclose(f2);
        }
    }
    free(arguments);
    return NULL;
}

void *x4(void *var)
{
    int h;
    struct thread_args *arguments = var;
    int f = arguments->v;
    int max3 = arguments->x;
    int rest3 = 0;
    for (h = 1; h <= max3; h++)
    {
        rest3 = h*h*h*h+f;
        printf("THREAD 3 (x^4+c) RESULT (X=%d) :%d \n", h, rest3);
        if (h == 1)
        {
            FILE *f3 = fopen("X4.txt", "w");
            if (f3 == NULL)
            {
                printf("Error opening file!\n");
                return(1);
            }
            fprintf(f3, "%d^4+%d= %d\n", h, f, rest3);
            fclose(f3);
        }
        else
        {
            FILE *f3 = fopen("X4.txt", "a");
            if (f3 == NULL)
            {
                printf("Error opening file!\n");
                return(1);
            }
            fprintf(f3, "%d^4+%d= %d\n", h, f, rest3);
            fclose(f3);
        }
    }
    free(arguments);
    return NULL;
}

void main()
{
    struct thread_args *arguments = malloc(sizeof *arguments);
    pthread_t t1, t2, t3;
    printf("Please input value of lamda (exp(-lamda*x): ");
    scanf("%f", &(arguments -> l));
    printf("\nPlease input value of a (ax^2+bx): ");
    scanf("%d", &(arguments -> a));
    printf("\nPlease input value of b (ax^2+bx): ");
    scanf("%d", &(arguments -> b));
    printf("\nPlease input value of c (x^4+c): ");
    scanf("%d", &(arguments -> v));
    printf("\nPlease input max value of x (limit): ");
    scanf("%d", &(arguments -> x));
    printf("\nCreating threads\n");
    pthread_create(&t1, NULL, elx, arguments);
    pthread_create(&t2, NULL, ax2, arguments);
    pthread_create(&t3, NULL, x4, arguments);
    printf("\n\nJoining threads\n\n");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("\nPress Any Key to Continue\n");
    getch();
    printf("\nExiting\n");
}
