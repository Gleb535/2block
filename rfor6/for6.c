#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    char log[20], psw[20];

    printf("Выбери действие:\n");
    printf("1 - войти в аккаунт\n2 - зарегистрировать аккаунт\n3 - не туда попал\n");
    printf("что выбрал: ");
    scanf("%d", &n);

    if (n == 1)
    {
        system("clear");
        printf("\nВведите логин: ");
        scanf("%s", log);
        FILE *f = fopen(log, "r");
        if (f == NULL)
        {
            perror(log);
        }
        else
        {
            char buf[20];
            fgets(buf, sizeof(buf), f);

            printf("\nВведите пароль: ");
            scanf("%s", psw);
            if (strcmp(psw, buf) == 0)
            {
                system("clear");
                printf("\nВы вошли в аккаунт!\n\nДоступные действия:\n1 - выйти\nчто выбрал: ");
                scanf("%d", &n);
                if (n == 2)
                    return 0;
                if (n == 1)
                    return 0;
            }
            else
            {
                system("clear");
                printf("\nНе тот пароль >:(\n");
                return 0;
            }
        }
        fclose(f);
    }

    if (n == 2)
    {
        system("clear");
        printf("\nВведите логин для нового аккаунта: ");
        scanf("%s", log);
        FILE *f = fopen(log, "w");
        if (f == NULL)
        {
            perror(log);
            return 0;
        }
        else
        {
            printf("\nВведите пароль: ");
            scanf("%s", psw);
            fputs(psw, f);
            system("clear");
            printf("\nВы успешно зарегистрировались)\n");
        }
        fclose(f);
    }

    if (n == 3)
    {
        system("clear");
        printf("ну пока(\n");
        return 0;
    }

    return 0;
}