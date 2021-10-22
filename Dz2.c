#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

int main(void) {
  char c;
  int i, j, d;
  do {
    int m, n, t, k = 0, g[10][10], dem = 0, count = 0, har1 = 0;
    printf("\nThe number of vertices (dinh): n= "); // количество вершин
    scanf("%d", & n);
    printf("\nThe number of edges (canh): m= "); // количество ребер
    scanf("%d", & m);
    char x[n];
    int h[n][n], har[10] = {
      0
    };
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) h[i][j] = 0;
    }
    printf("\nEnter the names of the vertices: ");
    for (i = 0; i < n; i++) {
      printf("\nx[%d]=", i);
      x[i] = getche(); //возвращает очередной символ, считанный с консоли, и выводит этот символ на экран.
    }
    //--------------------------------------------------------------//
    //	     	                 Ввод список ребер	                	//
    //--------------------------------------------------------------//
    printf("\nEnter the edges: \n");
    for (i = 0; i < m; i++)
      for (j = 0; j < 2; j++) {
        scanf("%d", & t);
        g[i][j] = t;
      }
    //--------------------------------------------------------------//
    //		                 	Работа с  файлом	                  		//
    //--------------------------------------------------------------//
    FILE * f;
    f = fopen("grap.dot", "w"); // открыли файл grap.dot для записи
    fprintf(f, "graph mygrap{ \n");
    for (i = 0; i < n; i++)
      fprintf(f, "%c\n", x[i]);
    for (i = 0; i < m; i++) {
      fprintf(f, "%d--%d\n", g[i][0], g[i][1]);
    }
    fprintf(f, "}");
    fclose(f);
    c = getche();
    //Списка ребер преобразуется в динамическую матрицу//
    for (i = 0; i < m; i++) {
      int a = g[i][0];
      int b = g[i][1];
      if (g[i][0] != g[i][1]) {
        h[a - 1][b - 1]++;
        h[b - 1][a - 1]++;
      } else h[a - 1][a - 1]++;
    }
    for (i = 0; i < n; i++) {
      if (h[i][i] != 0) count = count + 1;
    }
    /*printf("Dynamic matrix\n");
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
      {
      printf("%d\t",h[i][j]);
      }
      printf("\n");
      }*/
    //--------------------------------------------------------------//
    //	            	Проверка ли является граф деревом	          	//
    //--------------------------------------------------------------//
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (h[i][j] == 0) har[i] = har[i] + 1;
        else dem = dem + 1;
      }
    }
    
    
    for (i = 0; i < n; i++) {
      if (h[i][i] > 0 && har[i] == n - 1 || har[i] == n) {
        printf("Graph is not connected => Graph is not tree\n");
        return 0;
      }
    }
    if (har1 != n && (dem / 2) >= n - 1) {
      printf("Graph is connected \n");
      if ((dem / 2) == n || count != 0) printf(" but not tree ");
      else printf("Graph is tree");
    } else {
      printf("Graph is not connected => Graph is not tree\n");
    }
    //Команды системы, чтобы передавать файл graph.dot в png и открывать картинку графа//
    system("dot D:\\C\\Dz\\grap.dot -Tpng -o grap.png");
    system("rundll32  \"%ProgramFiles%\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen D:\\C\\Dz\\grap.png");
  } while ((c == 'y') || (c == 'Y'));
  getch();
  return 0;
}
