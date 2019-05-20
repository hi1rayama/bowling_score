#include <stdio.h>


void strike_single(int *a, int *b,int *c) {
 int tmp=0;
 tmp+= *a+*b;
 *c += tmp;

}
void strike_double(int *a, int *b) {
 *b = 20 + *a;
}
void spare(int *b, int *c) {
 int tmp= 0;
tmp = 10 + *b;
 *c = tmp;

}
int  sum(int pin[10][4]){
 int sum = 0;
 for (int i = 0; i <= 9; i++) {
  sum += pin[i][3];
 }

 return sum;
}
int main(void)
{
 int error = 0;
 int pin[10][4] = { 0 };
 int pin_s[10] = { 0 };
 int s[11] = { 0 };

 printf("倒したピンの個数を入力\n");
 /*倒したピンの個数を入力*/
 for (int i = 0; i <= 9; i++) {
  pin[i][3] = 0;
  
   do{
    printf("%dフレーム目\n", i + 1);
   error = 0;
  
   
    do{
     for (int j = 1; j <= 2; j++) {

      error = 0;
      printf("%d投目：", j); scanf("%d", &pin[i][j - 1]);
      if ((pin[i][j - 1]) >= 11) {                    /*エラー判定*/
       puts("0～10の範囲で入力してください");
       pin[i][0] = 0;
       pin[i][1] = 0;
       error = 1;
       break;
      }
      else if (i != 9 && pin[i][0] == 10) {                  /*ストライクの判定*/

       pin_s[i] = 1;
       break;
      }
      
      }

    } while (error == 1);
    if (i != 9) {
     if (pin[i][0] + pin[i][1] >= 11) {                 /*エラー判定*/
      puts("もう一度入力し直してください");
      pin[i][0] = 0;
      pin[i][1] = 0;
      error = 1;
     }
    }
  } while (error == 1);

 }
 /*10フレーム目：３投目の有無の判断と入力*/
if (pin[9][0] + pin[9][1] == 10 || pin[9][0] == 10) {
 do {
  error = 0;
  printf("3投目："); scanf("%d", &pin[9][2]);
  if (pin[9][2] >= 11)
  {
   puts("0～10の範囲で入力してください");
   error = 1;
   break;
  }
  
 } while (error == 1);
}
for (int i = 0; i <= 9; i++) {
 for (int j = 0; j <= 2; j++) {
  pin[i][3] += pin[i][j];                      /*各フレームの合計*/
 }
}

/*ストライク・スペアの点数処理*/
for (int i = 0; i <= 9; i++) {
 if (pin_s[i] == 0 && pin[i][0] + pin[i][1] == 10)
  spare(&pin[i + 1][0], &pin[i][3]);

 else if (pin_s[i] == 1 && pin_s[i + 1] == 1)

  strike_double(&pin[i + 2][0], &pin[i][3]);

 else if (pin_s[i] == 1)
  strike_single( &pin[i + 1][0],&pin[i+1][1], &pin[i][3]);

}

for (int i = 0; i <= 9; i++) {
 s[i + 1] += pin[i][3];
}
 for(int i=0;i<=9;i++){
  s[i + 1] += s[i];
 }





 /*最終結果の表示*/
printf("フレーム数|");
 for (int i = 1; i <= 10; i++) {
  printf("%5d",i);
 }
 printf(" 合計\n");
 for (int j = 0; j <= 3; j++) {
  if (j == 3)
   printf("  小計    |");
  else
  printf("%3d投目   |",j+1);
  for (int i = 0; i <= 9; i++) {
   if (j == 3)
    printf("%5d", s[i + 1]);
   else
   printf("%5d", pin[i][j]);
  }if (j == 3)
   printf("%5d", sum(pin));
  puts("");
 }
 return 0;
}
