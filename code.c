#include<stdio.h>

#include<stdlib.h>

#define N 1000
int main() {
  int a[N], n, i, b[N], j;

  printf("Decimal Number: ");   //Ð²Ð²Ð¾Ð´
  scanf("%d", & n);
  for (i = 0; n > 0; i++) {
    a[i] = n % 2;
    n = n / 2;
  }
  if (n < 0) {
    int m = -n;                 //Ð¿Ñ€ÐµÐ¾Ð±Ñ€Ð°Ð·Ð¾Ð²Ð°Ñ‚ÑŒ Ð¾Ñ‚Ñ€Ð¸Ñ†Ð°Ñ‚ÐµÐ»ÑŒÐ½Ð¾Ðµ Ñ‡Ð¸ÑÐ»Ð¾ Ð² Ð¿Ð¾Ð»Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÑŒÐ½Ð¾Ðµ, Ð·Ð°Ñ‚ÐµÐ¼ Ð½Ð°Ð¹Ñ‚Ð¸ ÐµÐ³Ð¾ Ð´Ð²Ð¾Ð¸Ñ‡Ð½ÑƒÑŽ Ñ„Ð¾Ñ€Ð¼Ñƒ
    for (i = 0; m > 0; i++) {
      b[i] = m % 2;
      m = m / 2;
    }
    for (i = 0; i < 10; i++)
      if (b[i] == 1) break;
    for (j = i + 1; j < 8; j++) b[j] = (b[j] == 1) ? 0 : 1; //Ð¿Ñ€ÐµÐ¾Ð±Ñ€Ð°Ð·Ð¾Ð²Ð°Ñ‚ÑŒ Ð´Ð²Ð¾Ð¸Ñ‡Ð½Ñ‹Ð¹ ÐºÐ¾Ð´ Ð² Ð´Ð¾Ð¿Ð¾Ð»Ð½ÐµÐ½Ð¸Ðµ Ð´Ð¾ 2
  }
  printf("\nBinary Number:");   //Ð²Ñ‹Ð²Ð¾Ð´
  for (i = i - 1; i >= 0; i--) {
    printf("%d", a[i]);
  }
  for (j = j - 1; j >= 0; j--) {
    printf("%d", b[j]);
  }
  return 0;
}