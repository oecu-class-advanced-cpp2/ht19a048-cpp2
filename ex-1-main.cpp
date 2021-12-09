#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
/* --------------------------------------------------------------- */
/*
*  is_prime
*
*
与えられた正整数 xに対して素数かどうか判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(int x) {
    //2からx-1までの数がxで割れるかをチェックする
    //もしも割れたらfalseを返す
    if(x==1)
        return false;
    for(int i=2; i < x; i++){
        if(x % i == 0)
            return false;
    };
    return true;
}
/* --------------------------------------------------------------- */
/*
*  nth_prime
*
*
与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
*  素数を返す。
*
*  TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
*  ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(int a,  int d,  int n) {
    int num = a;
    int count = 0; //素数なら増加
    while (num<1000000){
       if (is_prime(num))
           count++;
        if(count == n){
            break;
            cout << 0;
        }
        num = num + d;
       // std::cout << i << std::endl;
    };
    return num;
}
/* --------------------------------------------------------------- */
/*
*  hikaku_prime
*
*
与えられた正整数 yとｚ が同じか調べる
*/
/* -------------------------------------------------------------- */
int hikak_prime(int y,  int z) {
    if( y == z )
        return printf("%dの値で正しい\n",z);
    return printf("%dの値は間違え　出力で%dと出ている\n",z,y);
}

int main() {

    hikak_prime(nth_prime(367,  186, 151),92809);
    hikak_prime(nth_prime(179,  10, 203),6709);
    hikak_prime(nth_prime(271,  37, 39),12037);
    hikak_prime(nth_prime(103,  230, 1),103);
    hikak_prime(nth_prime(27,  104, 185),93523);
    hikak_prime(nth_prime(253,  50, 85),14503);
    hikak_prime(nth_prime(1,  1, 1),2);
    hikak_prime(nth_prime(9075,  337, 210),899429);
    hikak_prime(nth_prime(307,  24, 79),5107);
    hikak_prime(nth_prime(331,  221, 177),412717);
    hikak_prime(nth_prime(259,  170, 40),22699);
    hikak_prime(nth_prime(269,  58, 102),25673);
    // 以下、同様に、入出力例通りになるか確認せよ。
    cin.get();
    return 0;
} 