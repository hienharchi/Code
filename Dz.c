#include<stdio.h>

#include<conio.h>

int main(void) {
  char c;
  int i, j, d;
  do {
    int n, t, k = 0, g[10][10], dem = 0, count = 0, har = 0, count2 = 0;
    printf("\nThe number of vertices: n= "); // количество вершин
    scanf("%d", & n);
    char x[n];
    printf("\nEnter the names of the vertices: ");
    for (i = 0; i < n; i++) {
      printf("\nx[%d]=", i);
      x[i] = getche(); //возвращает очередной символ, считанный с консоли, и выводит этот символ на экран.
    }
    //--------------------------------------------------------------//
    //	     	    Ввод динамической матрицы	                	//
    //--------------------------------------------------------------//
    printf("\nEnter adjacentry matrix: \n");
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        scanf("%d", & t);
        g[i][j] = t;
      }
    //--------------------------------------------------------------//
    //	            	Проверка ли является граф деревом	     	//
    //--------------------------------------------------------------//
    for (i = 0; i < n; i++) {
      if (g[i][i] > 0) {
        printf("Graf multigrf not tree \n"); //Нет дерево
        dem = dem + 1;
        goto exit; // goto - Оператор безусловно передает управление оператору, помеченному указанным идентификатором.
      }
    }
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        if (g[i][j] > 1) {
          printf("Multigraph not tree \n"); //Нет дерево
          dem = dem + 1;
          goto exit;
        }
      }
    printf("Simple graph\n");
    goto exit;

    exit:
      if (dem == 0) {
        for (i = 0; i < n; i++) {
          for (j = 0; j < n; j++)
            if (g[i][j] > 0) k += 1;
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < n; j++) {
            if (g[i][j] == 0) count = count + 1;
          }
          if (count < n) count = 0;
          else har++; //Проверка сущеуствуются вершины в отдельности ?
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < n; j++) {
            if (g[i][j] != 0) count2 = count2 + 1;
          }
        }
        //--------------------------------------------------------------//
        //		     	Проверка на связность                   		//
        //--------------------------------------------------------------//
        if (k >= ((n - 1) * (n - 2) / 2) && har == 0)
          printf("\nConnected graph ");
        else
          printf("\nGraph is not connected \n");
        if ((count2 / 2) == n)
          printf("but not tree");
        getch();
      }
    //--------------------------------------------------------------//
    //		            	Работа с  файлом	             		//
    //--------------------------------------------------------------//
    FILE * f;
    f = fopen("grap.dot", "w"); // открыли файл Dot_file.txt для записи
    fprintf(f, "graph mygrap{ \n");
    for (i = 0; i < n; i++)
      fprintf(f, "%c\n", x[i]);
    for (i = 0; i < n; i++)
      for (j = 0; j <= i; j++) {
        if (g[i][j] != 0) {
          for (d = 0; d < g[i][j]; d++)
            fprintf(f, "%c--%c\n", x[i], x[j]);
        }

      }
    fprintf(f, "}");
    printf("\n\n Do you want to do again? (yes (y) or no (n))");
    printf("%d", count);
    c = getche();
  } while ((c == 'y') || (c == 'Y'));
  getch();
  return 0;
}