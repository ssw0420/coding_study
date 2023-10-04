#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
   int x = 0;
   int cnt = 0;

   scanf("%d", &x);

   for (int i = 0; x != 1; i++)
   {
      if (x % 3 == 0 && x % 2 == 0) // 6의 배수일때
      {
         x /= 3;
         cnt++;
      }

      else if (x % 3 == 0 && x % 2 != 0) // 3의 배수이고 2의 배수는 아닐때
      {
         x /= 3;
         cnt++;
      }

      else if (x % 3 != 0 && x % 2 == 0) // 2의 배수이고 3의 배수는 아닐때
      {
         if ((x - 1) % 9 == 0)
         {
            x -= 1;
            cnt++;
         }
         else
         {
            x /= 2;
            cnt++;
         }
      }

      else if (x % 3 != 0 && x % 2 != 0) // 3의 배수도 2의배수도 아닐때
      {
         x -= 1;
         cnt++;
      }
   }

   printf("%d", cnt);

   return 0;
}