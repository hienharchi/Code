#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

#include<stdint.h>

#define N 100

void Swap(int * a, int * b) {
  int temp = * a;
  * a = * b;
  * b = temp;
}
void selectionSort(int( * Mang)[N], int n, int v[]) {

  int i, j, min;
  for (i = 0; i < n; i++) {
    Mang[1][i] = v[i];
  }
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (Mang[1][j] < Mang[1][min]) {
        Swap( & Mang[1][j], & Mang[1][min]);
        Swap( & Mang[0][j], & Mang[0][min]);
      }
      min = j;
    }
  }
  printf("\n\nVertex order after sorting    : ");
  for (i = 0; i < n; i++) printf("%d\t", Mang[0][i]);
  printf("\nThe degree of vertices        : ");
  for (i = 0; i < n; i++) printf("%d\t", Mang[1][i]);
  printf("\n");

}
int main(void) {
  char c;
  int i, j, d, min;
  do {
    int m, n, t, k = 0, g[10][10], dem = 0, count = 0, har1 = 0, b[100] = {
      0
    };
    int Max;
    printf("\nThe value maximum degree : Maximumdegree=");
    scanf("%d", & Max);
    printf("\nThe number of vertices (dinh): n= "); // количество вершин
    scanf("%d", & n);
    printf("\nThe number of edges (canh): m= "); // количество ребер
    scanf("%d", & m);
    char x[n];
    int h[n][n], har[10] = {
      0
    };
    int v[n], arr[Max], Mang[1][n];
    int arr1[N] = {
      0
    };
    for (i = 0; i < n; i++) {
      Mang[1][i] = 0;
      Mang[0][i] = i + 1;

    }

    for (i = 0; i < n; i++) v[i] = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) h[i][j] = 0;
    }
    printf("\nEnter the names of the vertices: ");
    for (i = 0; i < n; i++) {
      printf("\nx[%d]=", i);
      x[i] = getche(); //возвращает очередной символ, считанный с консоли, и выводит этот символ на экран.
    }
    //--------------------------------------------------------------//
    //	     	                 Ввод список ребер	                  //
    //--------------------------------------------------------------//
    printf("\nEnter the edges: \n");
    for (i = 0; i < m; i++)
      for (j = 0; j < 2; j++) {
        scanf("%d", & t);
        g[i][j] = t;
      }
    //--------------------------------------------------------------//
    //		                 	Работа с  файлом	                      //
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
    int sum = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        sum += h[i][j] + h[j][i];
      }
      v[i] = (sum + 2 * h[i][i]) / 2;
      sum = 0;
    }
    printf("\n");
    for (i = 0; i < n; i++) {
      Mang[1][i] = v[i];
    }

    printf("\nOrder of the original vertices: ");
    for (i = 0; i < n; i++) printf("%d\t", Mang[0][i]);
    printf("\n");
    printf("The degree of vertices        : ");
    for (i = 0; i < n; i++) printf("%d\t", Mang[1][i]);

    selectionSort(Mang, n, v);

    for (i = 0; i <= Max; i++) arr[i] = 0;

    for (i = 0; i <= Max; i++) {
      for (j = 0; j < n; j++) {
        if (v[j] == i) arr[i]++;
      }
    }
    printf("\nVertex degree frequency\n");
    for (i = 0; i <= Max; i++) printf("\nDegree[%d]=%d\n", i, arr[i]);
    printf("\n");
    system("dot D:\\C\\Dz\\grap.dot -Tpng -o grap.png");
    system("rundll32  \"%ProgramFiles%\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen D:\\C\\Dz\\grap.png");
  } while ((c == 'y') || (c == 'Y'));
  getch();
  return 0;
}
