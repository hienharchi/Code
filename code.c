#include<stdio.h>

#include<stdlib.h>

#define N 1000
int main() {
  int a[N], n, i, b[N], j;

  printf("Decimal Number: ");   //ввод
  scanf("%d", & n);
  for (i = 0; n > 0; i++) {
    a[i] = n % 2;
    n = n / 2;
  }
  if (n < 0) {
    int m = -n;                 //преобразовать отрицательное число в положительное, затем найти его двоичную форму
    for (i = 0; m > 0; i++) {
      b[i] = m % 2;
      m = m / 2;
    }
    for (i = 0; i < 10; i++)
      if (b[i] == 1) break;
    for (j = i + 1; j < 8; j++) b[j] = (b[j] == 1) ? 0 : 1; //преобразовать двоичный код в дополнение до 2
  }
  printf("\nBinary Number:");   //вывод
  for (i = i - 1; i >= 0; i--) {
    printf("%d", a[i]);
  }
  for (j = j - 1; j >= 0; j--) {
    printf("%d", b[j]);
  }
  return 0;
}
