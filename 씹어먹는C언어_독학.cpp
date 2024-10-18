/* <씹어먹는 C언어> 독학 */
/* #include <stdio.h>란 stdio.h라는 파일을 포함하라는
뜻입니다. 이 파일에는 여러분이 화면에 메세지를 띄울 수 있게 도와주는
여러가지 함수들이 포함되어 있습니다. */
// main 함수는 프로그램이 시작되는 함수입니다.
// {}는 함수의 몸체를 알려주는데 사용됩니다.
// printf는 화면에 내용을 출력해주는 함수입니다.
// return 0; 는 0을 반환한다는 의미입니다.
// //와 /* */는 주석으로, 컴파일러는 무시하지만 프로그래머를 위해 남겨놓는 코멘트입니다.


#include <stdio.h>
int main() {
    /*
    printf("Hello, World!\n");
    printf("Hi, Human \n");
    */
    printf("Hi, Computer \n");

    return 0;
}

#include <stdio.h>
int main() {
    printf("Hello, World! \n");
    return 0;
}

/* 변수 알아보기 */
#include <stdio.h>
int main() {
    int a; /* 이 문장의 뜻은 a 라는 변수를 우리가 쓰겠다고 컴파일러에게 알리는 것. 
    이때, a 앞에 붙은 int라는 것은 int형의 데이터를 보관한다는 뜻으로, 
    a 에 -2147483648에서부터 2147483647까지의 정수를 보관할 수 있게 됨.
    (a에 보관할 수 있는 범위를 초과하는 수를 보관하려 하면 이상한 결과가 나오게 됨.)
    어쨌든, 일반적인 경우 정수 데이터를 보관할 때 int형 변수를 사용한다.*/
    a = 10; /* 변수 a에 10을 집어넣는다는 것.*/
    printf("a의 값은 : %d \n", a); /* %d가 출력될 자리에 a의 값인 10을 10진수로 출력하라는 뜻.*/
    return 0;
}

/* 변수 알아보기 2*/
#include <stdio.h>
int main(){
    int a;
    a = 127;
    printf("a 의 값은 %d 진수로 %o 입니다. \n", 8, a);
    printf("a 의 값은 %d 진수로 %d 입니다. \n", 10, a);
    printf("a 의 값은 %d 진수로 %x 입니다. \n", 16, a);
    return 0;
}

/* 실수형 변수*/
// 실수형에는 float와 double이 있다. 
// double의 경우, int형에 비해 덩치가 2배나 크지만 그만큼 엄청난 크기의 숫자를 다룰 수 있습니다. 
// 그대신 처음 15개의 숫자들만 정확하고 나머지는 10의 지수 형태로 표현됩니다. 
// 또한 float과 double의 장점은 소수를 표시할 수 있다는 점인데, 정수형 변수(int)에서 소수를 넣는다면, 소수 부분은 다 잘린 채 출력될 것입니다.

/* 변수 알아보기 3*/
# include <stdio.h>
int main() {
    float a = 3.141592f; /*왜 float 형 변수 a를 선언할 때에는 숫자 뒤에 f를 붙였는데 double형에서는 f를 안 붙였는지 이유??
    이유: 왜냐하면 그냥 뒤에 f를 안 붙이고 float a = 3.141592로 하면 이를 double형으로 인식하여 문제가 생길 수도 있다.
    따라서, float 형이라는 것을 확실히 표시해 주기 위해 f를 끝에 붙이는 것임. */ 
    double b = 3.141592;
    printf("a: %f \n", a); /* %d, %o, %x도 아닌 %f가 등장. 
    만약 여기서 a를 %d 형식으로 출력하면 이상한 숫자가 출력되게 된다. 
    왜냐하면, a는 지금 정수형(int) 변수가 아니기 때문!!
    이미 a와 b를 실수형(float) 변수로 선언하였기 때문에 컴퓨터는 a, b를 절대 정수로 보지 않음.
    따라서 실수형 변수를 출력하는 형식인 %f를 사용해야 한다.
    참고로, 주의할 사항은 printf에서 %f를 이용해 수를 출력할 때는 다음과 같이 언제나 소수점을 뒤에 붙여주어야 한다는 점
    예시: printf("%f", 1.0)*/
    printf("b: %f \n", b);
    return 0;
}

/* printf의 또다른 형식*/
#include <stdio.h>
int main() {
    float a = 3.141592f;
    double b = 3.141592;
    int c = 123;
    printf("a : %.2f \n", a); /* %.2f는 소수점 이하 둘째 자리까지만 표시하라는 의미.
    따라서 3.14로 출력함.*/
    printf("b : %5d \n", c);/* %5d는 숫자의 자리수를 되도록 5자리로 맞추라는 의미.
    따라서 123을 표시할 때, 5자리를 맞추어야 하므로 앞에 공백을 2개 남기고 그 뒤에 123을 표시.
    다만, 123456(6자리)을 표시할 때 %5d 조건을 준다면 이때는 그냥 123456을 전부 표시함.
    앞의 %.?f는 ?의 수만큼 무조건 소수점 자리수를 맞추어야 하지만 %?d의 경우는 반드시 지켜야 되는 것은 아닙니다. */
    printf("c : %6.3f \n", b); /* 위에서 사용한 두 가지 형식을 한꺼번에 적용한 것. 전체 자리수는 6자리로
    맞추되, 반드시 소수점 이하 3째 자리까지만 표시한다는 의미.*/
    return 0;
}

/* 변수 작명하기*/
// 앞서 보았듯이 변수를 선언하는 것은 어려운 일이 아닙니다.
// 단지, 아래의 형태를 맞추어 주기만 하면 됩니다.
// 형태: (변수의 자료형) 변수1, 변수2, ......;
/*예를 들어*/
int a, b, c, hi;
float d, e, f, bravo;
double g, programming;
long h;
short j;
char j, k, hello, mineral;

/* 변수 선언시 주의해야 할 점*/
/* 만약에 오래된 버전의 C언어(C89)를 사용한다면, 변수 선언 시 반드시 최상단에 위치해야 한다.
하지만, 우리가 지금 사용하고 있는 최신 버전의 C의 변수 사용하기 전 아무데나 변수를 선언해도 상관 없다.*/
#include <stdio.h>
int main() {
    int a;
    a = 1;
    printf("a 는 : %d", a);
    int b; // 괜찮음!!
    return 0;
}

/* 변수 선언시 주의해야 할 점 2*/
/* 사람의 이름을 지을 때 여러가지를 고려하듯이 변수의 이름에서도 여러가지 조건들이 있다. */

#include <stdio.h>
int main() {
    int a, A; // a 와 A 는 각기 다른 변수이다.
    int 1hi;
    // (오류) 숫자가 앞에 위치할 수 없다.
    int hi123, h123i, h1234324; // 숫자가 뒤에 위치하면 괜찮습니다.
    int 한글이좋아;
    /*
    (오류)
    변수는 오직 알파벳, 숫자, 그리고 _(underscore)로만으로 이루어져야합니다.
    */
    int space bar;
    /*
    (오류)
    변수의 이름은 띄어쓰기하면 안됩니다. 그 대신 _로 대체하는 것이
    읽기 좋습니다.
    */
    int space_bar; // 이것은 괜찮습니다.
    int enum, long, double, int;
    /*
    (오류)
    지금 나열한 이름드은 모두 '예약어'로 C 언어에서 이미 쓰이고 있는 
    것들입니다. 따라서 이러한 예약어들은 사용하면 안됩니다. 
    이를 구분하는 방법은 1) 예약어들을 모두 외우거나, 2) 파란색으로 표시되는
    것들은 예약어로 판단하면 됩니다. 
    */
    return 0;
}

/* 
이 안에 모든 내용이 들어 있습니다.
변수의 이름은 반드시
-숫자가 앞에 위치하면 안됩니다. -> 그러나, 중간이나 뒤는 괜찮습니다.
-변수명은 오직 영어, 숫자, _로만 구성되어 있어야 합니다.
-변수의 이름에 띄어쓰기가 있으면 안됩니다. -> 띄어쓰기 대신에 _를 넣으면 됩니다.
-변수의 이름이 C 언어 예약어이면 안됩니다. -> 보통 예약어를 쓰면 에디터에서 다른 색깔로 
 표시되어 예약어를 썼는지 안썼는지 알 수 있습니다. 
 -또한 C 언어는 대소문자를 구별합니다. -> 따라서, VARiable과 Variable은 다른 변수입니다.
*/

/* 산술 연산*/
#include <stdio.h>
int main() {
    int a, b;
    a = 10;
    b = 3;
    printf("a + b 는 : %d \n", a + b);
    printf("a - b 는 : %d \n", a - b);
    printf("a * b 는 : %d \n", a * b);
    printf("a / b 는 : %d \n", a / b); /* a/b의 값은 3으로 출력된다.
    이유: a와 b는 모두 int형으로 선언된 변수. 즉, a 와 b는 오직 '정수' 데이터만 담당함.
    a와 b는 모두 정수 데이터만 처리하기 떄문에 a를 b로 나누면 3.3333...이 되겠지만 정수 
    부분인 3만 남기게 되는 것임.
    따라서, 값은 3이 출력됨. */
    printf("a %% b 는 : %d \n", a % b); /* %%는 %를 '표시'하기 위한 방법임.
    이유: 왜냐하면 % 하나로는 %d, %f와 같이 사용될 수 있기 때문에, 구분을 위해서 이렇게 사용함.*/
    return 0;

}

/* 나눗셈 시에 주의할 점 */
#include <stdio.h>
int main() {
    int a, b;
    a = 10;
    b = 3;
    printf("a / b 는 : %f \n", a / b); // 해서는 안될 짓
    return 0;
} /*
컴파일 후 실행한다면, 실행 결과는 다음과 같이 출력됨.
a / b 는 : 0.000000 
이유: (정수형 변수) (연산) ( 정수형 변수)는 언제나 (정수)로 유지된다.
따라서, 실수형 데이터를 출력하는 %f를 정수형 값 출력에 사용하면 위와 같이 이상한 결과가 나오게 된다.
(*알아두기: %d는 정수형 값을 출력하는 방식임!!)
*/

/* 산술 변환 */
#include <stdio.h>
int main() {
    int a; // a는 정수형 변수로 설정
    double b; // b는 실수형 변수로 설정

    a = 10;
    b = 3;
    printf("a / b 는 : %f \n", a / b);
    printf("b / a 는 : %f \n", b / a);
    return 0;
}
/*
위의 코드에서, a는 정수형 변수이고 b는 실수형 변수이다.
그런데 a와 b에 대한 연산을 한 후에 결과를 실수형(%f 사용)으로 출력하였는데
결과가 정상적으로 출력되었다. 왜일까?? 
이유: 컴파일러가 '산술 변환'이라는 과정을 거치기 때문.
즉, 어떠한 자료형이 다른 두 변수를 연산할 때, 숫자의 범위가 큰 자료형으로 자료형들이 바뀜.
(실수 범위 > 정수 범위)
따라서 printf(" a / b 는 : %d \n", a / b); 와 같이 하면 오류가 발생하게 된다.
왜냐하면 %d는 정수형 값을 출력하는 방식이기 때문이다. 
*/

/* 대입 연산자 */
#include <stdio.h>
int main() { 
    int a = 3; // a라는 변수를 선언하고, a 변수에 3의 값을 대입함.
    a = a + 3;
    printf("a 의 값은 : %d \n", a);
    return 0;
}

/* 더하기 1을 하는 방법 */
#include <stdio.h>
int main() {
    int a = 1, b = 1, c = 1, d = 1;

    a = a + 1;
    printf("a : %d \n", a);
    b += 1; /* 복합 대입연산: b = b + 1과 의미가 동일함.*/
    printf("b : %d \n", b);
    ++c; /* 증감 연산자(++ 형태)-전위형(prefix) : c를 1씩 증가시켜줌.
    먼저 1을 더해준 후, 결과를 돌려줌.*/
    printf("c : %d \n", c);
    d++; /* 증감 연산자(++ 형태)-후위형(postfix) : d를 1씩 증가시켜줌.
    결과를 돌려준 이후, 1을 더해줌.*/
    printf("d : %d \n", d);
    
    return 0;
}

/* 비트 연산 */
/*
1. a & b : 둘 다 1인 비트만 1로 남긴다. (그 외는 0으로 설정)
2. a | b : 둘 중 하나라도 1인 비트는 1로 설정한다. (그 외는 0으로 설정)
3. a ^ b : 두 비트가 다르면 1로 설정한다. 
4. ~a : 모든 비트를 반전시킨다. 
5. a << 2 : 비트들을 2칸 왼쪽으로 이동한다.
6. b >> 3 : 비트들을 3칸 오른쪽으로 이동한다. 
*/
#include <stdio.h>
int main() {
    int a = 0xAF; // 10101111
    int b = 0xB5; // 10110101

    printf("%x \n", a & b);  // a & b(비트 AND 연산) = 10100101 -> 결과: 0xA5(16진수)
    printf("%x \n", a | b);  // a | b(비트 OR 연산) = 10111111 -> 결과: 0xBF(16진수)
    printf("%x \n", a ^ b);  // a ^ b(비트 XOR 연산) = 00011010 -> 결과: 0x1A(16진수)
    printf("%x \n", ~a);     // ~a(비트 NOT 연산) = 1....1 01010000 -> 결과: 0xFFFFFF50(32비트 정수에서는 앞에 부호 비트가 붙어서 '0xFFFFFF50')
    printf("%x \n", a << 2); // a << 2(비트 왼쪽 시프트 연산) = 1010111100 -> 결과: 0x2BC(16진수)
    printf("%x \n", b >> 3); // b >> 3(비트 오른쪽 시프트 연산) = 00010110 -> 결과: 0x16(16진수)
    
    return 0;
}

/* 컴퓨터가 음수를 표현하는 방법(2의 보수) */
#include <stdio.h>
int main() {
    int a = 2147483647;
    printf("a: %d \n", a);

    a++;
    printf("a: %d \n", a);

    return 0;
}

/* 컴퓨터가 음수를 표현하는 방법(2의 보수) */
#include <stdio.h>
int main() {
    int a = 2147483647;
    printf("a: %d \n", a); /*a 라는 변수를 정의한 뒤에 
    int가 표현할 수 있는 최대값인 2147483647 대입*/ 

    a++;
    printf("a: %d \n", a); /* 반면에 a++을 해서 int가 
    표현할 수 있는 최대값(2147483647)을 1만큼 넘어가버렸더니, 값이 
    -2147483648이 나왔다.
    어떻게 양수에서 1을 더했는데 음수가 나올 수 있을까??
    */

    return 0;
}

/* 음수 표현 아이디어 */
/*
이진수로 0111은 십진수 7이 될 것이고, 
1111은 맨 왼쪽 부호 비트가 1이므로 -7을
나타내게 된다. 
따라서 0000도 0이고, 1000 역시 0이다.
(-0은 0이기 때문.)
0을 표현하는 방식이 2개라는 것은 매우 큰 문제이다.
첫 번째 문제로는, 0을 표현하는 방법이 2가지라면, 어떠한 데이터가
0인지 확인하기 위해서 +0인지 -0인지 2번이나 확인
해야 합니다. 
따라서 이상한 데이터 표현법 덕분에 쓸데없이 컴퓨터 
자원을 낭비하게 된다.
두 번째 문제로는, 양수의 음수의 덧셈을 수행할 때 부호를 고려해서
수행해야 한다는 점이다. 
예를 들어서 0001과 0101을 더한다면 그냥 0110이 되겠지만,
0001과 1001을 더할 때에는 1001이 사실은 -1이므로 뺼셈을 수행해야 한다.
따라서 덧셈 알고리즘이 좀 더 복잡해진다.
*/

/* 2의 보수(2's complement)*/
/* 
예를 들어서 7을 이진수로 나타내면 0111
이 되는데, 여기에 더해서 0000이 되는 
이진수가 있을까??
*/

/* 음수가 없는 자료형은 어떨까?*/
/*
unsigned int의 경우 음수가 없고 0부터 4294967295까지의 수를 표현할 수를 표현할 수 있다.
unsigned int 역시 int와 같이 똑같딩 32비트를 
*/

#include <stdio.h>
int main() {
    unsigned int b = -1;
    printf("b 에 들어있는 값을 unsigned int 로 해석했을 때 값: %u \n", b);
    /* 참고로 printf에서 %u는 unsigned 타입으로 해석하라는 의미이다.*/
    return 0;
}

/* 오버플로우(overflow) */
/* 오버플로우: 자료형의 최대 범위보다 큰 수를 대입함으로써 발생하는 문제. 
C언어 차원에서 오버플로우가 발생하였다는 사실을 알려주는 방법은 없기 때문에 
우리가 스스로 항상 사용하는 자료형의 크기를 신경써주어야 한다. */
/* 물론 unsigned int 상에서도 오버플로우가 발생하지 않으라는 법은 없다.
예를 들어서 b에 최대값을 대입한 뒤에 1을 추가한다면 결과는 아래와 같다.*/
#include <stdio.h>
int main() {
    unsigned int b = 4294967295;
    printf("b: %u \n", b);

    b++;
    printf("b : %u \n", b); /* 오버플로우 발생-> 자료형의 크기를 초과하는 비트는 그대로 버려지무로 그냥 0으로 해석된 것!! */

    return 0;
}
/*실행 결과*/
/* b : 4294967295 */
/* b : 0 (오버플로우로 인한 비트 버려짐으로 0으로 해석됨.)*/
/* 즉, unsigned int를 포함한 C 언어 상의 모든 자료형은 오버플로우의 위험으로부터 자유롭지 않다. 
따라서 C 언어에서 코딩을 할 때에는 언제나 오버플로우 문제에 신경써야 한다. 
그러면 아니 int 에 분명히 양수만 더했는데 왜 음수가 나왔지?와 같은 상황에 
당황하지 않고 대처하는 것이 가능하다. */


/* 문자를 저장하는 변수 */
#include <stdio.h>
int main() {
    char a; /* char형 변수를 선언하는 부분 */
    a = 'a'; /* a 라는 변수에 문자 a를 대입하고 있다.
    이때, 모든 문자들은 모두 작은 따옴표('')로 묶어 주어야 한다. 
    이유: 변수 a와 문자 a를 구분하기 위해서 */

    printf("a 의 값과 들어 있는 문자는? 값: %d , 문자: %c \n", a, a);
    /* 문자를 대입하는 것도 숫자를 대입하는 것과 동일하다.-> 대입연산자를 이용한다. */
    return 0;
}

/* 개요 */
/* 프로그래밍에서는 숫자 뿐만 아니라 문자도 다뤄야 하기 때문에 문자를 위한 변수형으로 
character의 약자인 char이 존재한다. 서식문자는 %c이고  이러한 서식문자로 입력 및 출력이 
가능하다. 
만일 C언어에서 문자 a를 그냥 a로 표기한다면 
이게 변수 a를 말하는 것인지 문자 a를 말하는 것인지 알 수 없다. 
예를 들어, 변수a에 문자a를 넣고 싶을 때 a = a;라는 구문을 쓴다면 
a라는 변수에 a 변수의 값을 넣게 되니 아무 일도 일어나지 않을 것이다. 
따라서 문자는 아래와 같이 '문자'의 형식으로 표기하도록 되어 있습니다. 
형식: 작은 따옴표 안에 문자를 쓰는 형식 
*/
// code by https://www.weeklyps.com/entry/C%EC%96%B8%EC%96%B4-7-%EB%B3%80%EC%88%98-3-%EB%B3%80%EC%88%98%ED%98%95-char
#include <stdio.h>

int main() {
    char a;
    a = 'a';
    printf("%c\n", a);
    a = 'e';
    printf("%c", a);
    return 0;
}

/* <scanf의 도입> */
/* 섭씨온도를 화씨온도로 바꾸기 */
#include <stdio.h>
int main() {
    double celsius; // 섭씨 온도(celsius)라는 double형 변수를 선언함.

    printf("섭씨 온도를 화씨 온도로 바꿔주는 프로그램입니다. \n");
    printf("섭씨 온도를 입력해 주세요: ");
    scanf("%lf", &celsius); // 섭씨온도를 입력 받는다. -> 파이썬의 input()함수와 매우 비슷한 것 같다!!!
    /* printf가 화면에 결과를 출력해주는 함수였다면, 
    scanf는 화면(키보드)로부터 결과를 받아들이는 입력함수이다. */
    
    printf("섭씨%f 도는 화씨로 %f 도입니다\n", celsius, 9 * celsius /5 + 32); // 섭씨와 화씨의 환산 작업이 이루어진다.

    return 0;

}

/* 문제1- 생각해보기 */
/* 앞서 섭씨를 화씨로 바꿀 때 9*celsius/5+32라고 하였습니다. 만약에 이를 
9/5*celsius+32로 바꾸면 결과가 달라질까요?? 
답: 결과가 달라진다. 이는 정수 나누기와 실수 나누기의 차이 때문에 비롯된다.

C언어에서 9 / 5 는 두 정수 간의 나눗셈이다. 정수 나눗셈의 결과는 소수 부분을 버리고
정수 부분만 남기기 때문에 9 / 5 는 1이 된다. 따라서 바꾼 식인 '9 / 5 * celsius + 32'는 
'1 * celsius + 32'와 같게 되어 잘못된 결과를 초래하게 된다. 

반면에, 처음의 '9 * celsius / 5 + 32'는 먼저 '9 * celsius'가 계산되고, 이 결과를 5로 나눈 후 
32를 더하게 되므로 올바른 화씨 온도를 계산할 수 있다. */

/*
printf 와 scanf를 가리켜 입출력함수라고 한다. 
scanf함수는 우리가 어떠한 입력을 하기 전까지 계속 기다리고, 입력을 할 때 
엔터를 눌러야지만 입력으로 처리된다. 
scanf와 printf의 공통점: 각 변수의 타입마다 입/출력받는 포맷(%d, %f, %c 등)을 달리 해야 한다. 
 " "  차이점: printf는 double이나 float 모두 %f로 출력하지만, scanf의 경우 float은 무조건 %f로 
입력받아야하고, double형 변수도 무조건 %lf로 입력받아야한다. 
그 외에도 printf는 정수형 변수는 모두 %d로 출력 가능했던 반면에 scanf는 각 자료형마다 포맷이 다 정해져 있다.  
*/

/* scanf 총정리 */
#include <stdio.h>
int main() {
    char ch; // 문자

    short sh; // 정수
    int i;
    long lo;

    float fl; // 실수
    double du;

    printf("char 형 변수 입력: ");
    scanf("%c", &ch);

    printf("short 형 변수 입력: ");
    scanf("%hd", &sh);
    printf("int 형 변수 입력: ");
    scanf("%d" , &i);
    printf("long 형 변수 입력: ");
    scanf("%ld", &lo);

    printf("float 형 변수 입력: ");
    scanf("%f", &fl);
    printf("double 형 변수 입력: ");
    scanf("%lf", &du);

    printf("char : %c, short : %d, int : %d", ch, sh, i);
    printf("long : %ld, float : %f, double : %f \n", lo, fl, du);

    return 0;
}

/* <만약에...(조건문)> */
/* if문 시작하기-if문이란?? */
#include <stdio.h>
int main() {
    int i;
    printf("입력하고 싶은 숫자를 입력하세요! : ");
    scanf("%d" , &i);

    if (i == 7) { // == 은 '관계연산자'라 부른다. 
    /* 관계연산자는 어떠한 관계를 연산한 후에 그것이 참이면 1을, 거짓이면 0을 나타내게 된다. 
    다시 말해, if 문은 참/거짓에 따라서 중괄호 속의 내용을 실행하느냐, 하지 않느냐 결정하는
    것처럼 보이지만 실제로는
    if 문 속의 조건이 0인가(거짓인 경우), 혹은 0이 아닌가(참인 경우)에 따라서 실행의 
    유무를 판별하게 된다. 
    따라서 if (0)이라 한다면 그 중괄호 속의 내용은 절대로 실행되지 않고, if (1) 이라 한다면 
    그 중괄호 속의 내용은 100% 실행되게 됩니다. */
        printf("당신은 행운의 숫자 7을 입력했습니다.");
    }
    
    return 0;
}

/* 나눗셈 예제 */
#include <stdio.h>
int main() {
    double i, j;
    printf("나누고 싶은 두 정수를 입력하세요 : ");
    scanf("%lf %lf", &i, &j); // %lf 는 double 타입의 입력을 받기 위해 사용된다.

    printf("%f 를 %f 로 나눈 결과는 : %f \n", i, j, i / j);
    /* printf에서 %f는 float 타입에 맞춰진 포맷 지정자이며, 
    double 타입의 값을 출력할 때는 %lf 를 사용하는 것이 올바르다. 
    따라서 정확한 결과를 위해 %lf 를 사용하는 것이 좋다. 
    수정된 코드: printf("%lf 를 %lf 로 나눈 결과는 : %lf \n", i, j, i / j);
    */

    return 0;
    /* 해당 코드에서 주의할 점*/
    /* 입력된 두 수 중, 나누는 수(j)가 0일 경우 프로그램에서는 에러가 발생한다. 
    왜냐하면 수학(그리고 컴퓨터)에서 어떠한 수를 0으로 나누는 것은 금지되어
    있기 때문이다. 위의 i 와 j 변수가 double로 선언되어 있어서 망정이지, 
    i, j 변수를 int 형으로 선언하였다면 프로그램은 에러를 내뿜고 종료된다. 이는 
    파일이 날아갈 수도 있는 치명적인 문제를 가지고 있기 때문에 우리는 나누는 수(=제수)
    가 10이 아닌지 확인할 필요성이 있다. 
    즉, 제수(j)가 0이면 나누지 않고 0이 아니면 나누는 것이다. 
    따라서 아래의 코드와 같은 수정이 필요하다. */
}

/* 나눗셈 예제 수정본 */
#include <stdio.h>
int main() {
    double i, j;
    printf("나누고 싶은 두 정수를 입력하세요 : ");
    scanf("%lf %lf", &i, &j);

    if (j == 0) {
        printf("0 으로 나눌 수 없습니다. \n");
        return 0;
    }
    printf("%f 를 %f 로 나눈 결과는 : %f \n", i, j, i / j);

    return 0;
}

/* 합격? 불합격? */
#include <stdio.h>
int main() {
    int score;
    
    printf("당신의 수학점수를 입력하세요! : ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("당신은 합격입니다! \n"); 
    }

    if (score < 90) {
        printf("당신은 불합격입니다! \n");
    }

    return 0;
}

/* 크기 비교하기 */ //단점: if 문으로만 연결해서 코드가 매우 길어진다는 단점이 있음...꽤 치명적&비효율적
#include <stdio.h>
int main() {
    int i, j;

    printf("크기를 비교할 두 수를 입력해 주세요 : ");
    scanf("%d %d", &i, &j);

    if (i > j) // i가 j보다 크면
    {
        printf("%d 는 %d 보다 큽니다.\n", i, j);
    }
    if (i < j) // i가 j보다 작으면
    {
        printf("%d 는 %d 보다 작습니다.\n", i, j);
    }
    if (i >= j) // i가 j보다 크거나 같으면
    {
        printf("%d 는 %d 보다 크거나 같습니다.\n", i, j);
    }
    if (i <= j) // i가 j보다 작거나 같으면
    {
        printf("%d 는 %d 보다 작거나 같습니다.\n", i, j);
    }
    if (i == j) // i가 j와 같으면
    {
        printf("%d 는 %d 와 같습니다.\n", i, j);
    }
    if (i != j) // i가 j와 다르면
    {
        printf("%d 는 %d 와 다릅니다.\n", i, j);
    }

    return 0;
}

/* if-else 문 시작하기 */
#include <stdio.h>
int main() {
    int num;

    printf("아무 숫자나 입력해 보세요 : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("행운의 숫자 7 이군요!\n");
    } 
    else {
        printf("그냥 보통 숫자인 %d 를 입력했rns요\n", num);
    }
    return 0;
}

/* if-else 죽음의 숫자??  */
#include <stdio.h>
int main() {
    int num;

    printf("아무 숫자나 입력해보세요 : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("행운의 숫자 7 이군요!\n");
    }
    else {
        if (num == 4) {
            printf("죽음의 숫자 4인가요 ;;;\n");
        }
        else {
            printf("그냥 평범한 숫자 %d 이군요!\n");
        }
    }
    return 0;
}



/* 쓰레기 코드 */
#include <stdio.h>
int main() {
    int num;
    
    printf("아무 숫자나 입력해보세요 : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("행운의 숫자 7이군요!\n");
    }
    else {
        if (num == 4) {
            printf("죽음의 숫자 4인가요 ;;;\n");
        }
        else {
            if (num == 1) {
                printf("첫번째 숫자!! \n");
            }
            else {
                if (num == 2) {
                    printf("이 숫자는 바로 두번째 숫자 \n");
                }
                else {
                    ............(생략).........
                }
            }
        }
    }

    return 0;
    
/* 정말 끝도 없이 길어져서 나중에는 중괄호가 너무 많아 헷갈리기도 하고, 보기도 불편하게 된다. 
하지만 C언어는 이 문제를 간단히 해결할 수 있다. 수정 코드는 아래와 같다. */
}

/* 새로 쓰는 죽음의 숫자 예제 */
#include <stdio.h>
int main() {
    int num;

    printf("아무 숫자나 입력해 보세요 : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("행운의 숫자 7 이군요!\n");
    }
    else if (num == 4) {
        printf("죽음의 숫자 4 인가요 ;;;\n");
    }
    else {
        printf("그냥 평범한 숫자 %d \n", num);
    }
    
    return 0;
}

/* 성적 입력 프로그램 만들기 */
#include <stdio.h>
int main() {
    float ave_score;
    float math, english, science, programming;

    printf("수학, 영어, 과학, 컴퓨터 프로그래밍 점수를 각각 입력해주세요! : ");
    scanf("%f %f %f %f", &math, &english, &science, &programming);

    ave_score = 
        (math + english + science + programming) / 4; // 4과목의 평균을 구한다. 
    printf("당신의 평균 점수는 %f 입니다.\n", ave_score);
    if (ave_score >= 90) {
        printf("당신은 우등생입니다.");
    } else if (ave_score >= 30) {
        printf("조금만 노력하세요!!\n");
    } else {
        printf("공부를 발로 합니까??\n");
    }
    return 0;
}

/* 성적 입력 프로그램 만들기 */
#include <stdio.h>
int main() {
    float ave_score;
    float math, english, science, programming;

    printf("수학, 영어, 과학, 컴퓨터 프로그래밍 점수를 각각 입력해주세요! : ");
    scanf("%f %f %f %f", &math, &english, &science, &programming);

    ave_score = 
        (math + english + science + programming) / 4; // 4과목의 평균을 구한다. 
    printf("당신의 평균 점수는 %f 입니다.\n", ave_score);
    if (ave_score >= 90) {
        printf("당신은 우등생입니다.");
    } else if (ave_score >= 30) {
        printf("조금만 노력하세요!!\n");
    } else {
        printf("공부를 발로 합니까??\n");
    }
    return 0;
}
/* \n을 붙이고 안 붙이고의 차이가 있을까...
적어도 이 코드에서는 붙이고 안 붙이고의 차이가 별로 없는 것 같다;; 
*/

/* 논리 연산자 */
#include <stdio.h>
int main() {
    int a;
    printf("아무 숫자나 입력하세요 : ");
    scanf("%d", &a);

    if (a >= 10 && a < 20) {
        printf(" %d 는 10 이상, 20 미만인 수입니다. \n", a);
    }
    /* && 는 논리곱(AND)라고 불리는 '논리 연산자'이다.
    따라서 &&는 두 개의 조건식이 모두 '참'이 되어야 IF문 속의 내용을 실행하는 것이 된다.
    * & 하나는 숫자 사이의 AND 연산을 사용할 때 쓰고
    논리 곱 연산자인 &&는 두 개 이상의 조건식 사이에서 사용된다.
    따라서 if (a >= 10 & a < 20) 이나 0x10 && 0xAE와 같은 연산은 모두 틀린 것이 된다.
    주의 : 0 <= a <= 1은 잘못된 사용의 예이다. 대신 0 <= a && a <= 1과 같이 사용해야 한다. */
    return 0;
}

/* 논리 합 */
#include <stdio.h>
int main() {
    int height, weight;
    printf("당신의 키와 몸무게를 각각 입력해주세요 : ");
    scanf("%d %d", &height, &weight);

    if (height >= 190 || weight >= 100) {
        printf("당신은 '거구' 입니다. \n");
    }
    if (!(height >= 190 || weight >= 100)) { /* !는 NOT을 취해주는 연산자이다. 
    다시 말해, '반전'을 시켜주는 것이다. 
    위의 경우, height >= 190 || weight >= 100 의 경우가 거짓일 때만,
    정리하자면 height < 190 && weight < 100 인 경우에만 중괄호 속의 내용이 실행된다. */
        printf("당신은 거구가 아닙니다. \n");
    }
    /* || 는 OR 을 나타내는 논리 연산자이다. 두 조건이 모두 참일 때 참을 반환하는
    AND와는 달리, OR 은 두 조건이 모두 거짓일 때만 거짓을 반환한다. 
    다시 말해, (참) || (거짓) == (참) 이 된다. */
    return 0;
}

/*반복문(for, while)*/
/*1. for 문(for statement)*/
#include <stdio.h>
int main() {
    int i;
    for (i = 0; i < 20; i ++) {
        /* 증감식에 i++이 써져 있다면 한 번 실행할 때마다 
        i 의 값을 1 씩 증가시킨다.
        마찬가지로 증감식 부분에 i -= 2 라면, 한 번 실행할 떄마다 2씩 감소하는 것을 확인할 수 있다. 
        위의 소스 코드(for 문)를 보고 컴퓨터는 
        음, i 의 값을 0으로 해야겠다.(초기식)
        for 문에 i < 20 으로 되어 있으므로(조건식)
        i < 20 이 맞나? 맞으면 중괄호 속의 내용을 실행해야지. 숫자 0 출력!!
        또한 for 문에 i ++ 로 되어 있으므로(증감식)
        이제 i 의 값을 1 증가시켜야겠다.
        따라서 i의 값은 1이 된다.
        i 의 값이 20 미만인가?? 맞다면 한 번 더 실행해야겠다. (조건식) 숫자 1 출력
        ...(생략)...
        이제 i 의 값을 1 증가시켜야겠다.(증감식)
        20번의 실행 후, i 의 값이 마침내 20이 되었다. 
        i 의 값이 20 미만인가? 어? 아니잖아.(조건식) 그러면 이제 for문을 빠져나가야지
        하며, 더이상 중괄호 속의 내용을 실행하지 않는다. 숫자 20이 출력되지 않는다.*/
        printf("숫자: %d \n", i);
    }

    return 0;
}
// /* for 문의 기본 구조
// /* for (/*초기식 */; /* 조건식 */; /* 증감식 */) {
//     // 명령1;
//     // 명령2;
//     // .....
// }
// */


/* for 문은 의외로 간단하다. 단지 기억해야 하는 것은 for문은 {} 안에 
작업들을 조건식이 성립할 동안 반복해주는 것이고, 매 반복마다 증감식을 실행
한다라고 이해하면 된다. */

/* 1부터 19까지의 합*/
#include <stdio.h>
int main() {
    int i, sum = 0; // int i와 sum = 0이라는 의미인가..??i와 sum 둘 다 초기값이 0이라는 의미는 아니지 않을까?? i는 밑의 줄에서 초기값이 정해지는데...
    for (i = 0; i < 20; ++i) {
        sum = sum + i;
    }
    printf("1부터 19까지의 합 : %d", sum);

    return 0;
}

/* for 문 응용*/
#include <stdio.h>
int main() {
    int i;
    int subject, score;
    double sum_score = 0;

    printf("몇 개의 과목 점수를 입력받을 것인가요?");
    scanf("%d", &subject);

    printf("\n 각 과목의 점수를 입력해주세요\n");
    for (i = 1; i <= subject; i++) {
        printf("과목%d : ", i);
        scanf("%d", &score);
        sum_score = sum_score + score;
    }

    printf("전체 과목의 평균은 : %.2f \n", sum_score / subject);

    return 0;
}

/* break 문*/
#include <stdio.h>
int main() {
    int usranswer;

    printf("컴퓨터가 생각한 숫자를 맞추어보세요!! \n");

    for (;;) { /*for 문에 초기식, 조건식, 증감식이 모두 없다!!
    이러한 for 문은 해당 반복문의 조건식이 명시되지 않는다면 항상 참이라고 인식되기 때문에
    이 for 문은 언제나 참이 되어 무한히 중괄호 속의 내용을 실행하게 된다. 
    그래서 break문을 사용하지 않으면 프로그램 자체가 강제적으로 종료되기 전까지 for 문이
    무한번 실행되게 된다. 
    break는 사실 for 문의 조건식에 상관없이 일단 실행이 되기만 하면 for 문을 그대로 탈출시킨다. 
    (그렇지만 break문이 등장하기 위해서는 for 문을 만족시켜야 하게 프로그램을 짰기 때문에 for 문을 
    만족시켜야 break 문이 등장하게 되는 것이다. )*/
        scanf("%d", &usranswer);
        if (usranswer == 3) {
            printf("맞추셨군요!! \n");
            break;
        } else {
            printf("틀렸어요!! \n");
        }
    }

    return 0;
}

/* continue 문- 5의 배수를 제외한 숫자 출력 */
#include <stdio.h>
int main() {
    int i;

    for (i = 0; i < 100; i ++) {
        if (i % 5 == 0) continue;
        /* continue 문은 break 문처럼 아래 모든 내용을 무시한다는 점에서 동일하지만, 
        break 문은 루프를 빠져나가버리는 반면 continue는 다시 조건 점검부로 점프하게 된다.
        continue 는 마치 카드 게임에서의 스킵과 같은 역할을 하게 된다.
        (break 문이 카드게임에서 퇴출되는 것이라면.)
        따라서 i 의 값이 5의 배수인 경우에만 printf("%d ", i)가 실행이 되지 않고, 다른 경우에는 
        전부 실행되는 것이다. */
        printf("%d ", i);
    }

    return 0;
}

/* 구구단 */
#include <stdio.h>
int main() {
    int i, j;

    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++) {
            /* if 문에 if 문을 넣을 수 있는 것처럼 
            for 문 안에도 for 문을 넣을 수 있다. */
            printf(" %d x %d = %d \n", i, j, i * j);
        }
    }
    return 0;
}

/* 다음 소스만 보고 무슨 숫자가 출력될 지 맞춰보세요 */
#include <stdio.h>
int main() {
    int i, j;

    for (i = 1; i < 10; i ++) {
        for (j = 1; j < i; j ++) {
            printf("%d ", j);
        }
    }
    return 0;
}

/* while 문*/
#include <stdio.h>
int main() {
    int i = 1, sum = 0;

    while (i <= 100) {
        sum += i;
        i ++;
    }

    printf("1 부터 100 까지의 합 : %d \n", sum);

    return 0;
}

/* do-while 문*/
#include <stdio.h>
int main() {
    int i = 1, sum = 0;

    do {
        sum += i;
        i ++;
    } while (i < 1);

    printf(" sum : %d \n", sum);
    return 0;
}
/* do-while 문은 사실 while 문과 거의 비슷합니다. 
한 가지 차이점은 앞서 말했듯이 while 문은 명령을 실행하기 전에 
조건식이 참인지 먼저 검사합니다. 
따라서, 조건식이 처음부터 참이 아니라면 while 문 안의 내용은 
결코 실행될 수 없다. 
그런데 do-while 문은 먼저 명령을 실행한 후에 조건식을 검사한다. 
따라서 처음부터 조건식이 참이 아니더라도 명령을 먼저 실행한 다음 조건식을
검사하기 때문에 최소한 한 번은 실행되게 된다. 
그러므로 위의 경우 i 가 1로 i < 1 이었지만 조건식을 나중에 검사하기 때문에 
일단 sum += i; 와 i ++ 을 실행한 다음에 i < 1 이 검사되어 sum의 값인 1이
출력될 수 있었던 것이다. 
*/


/* switch 문*/
/* switch 문은 if 문의 친구. 그 이유는 switch 문과 if 문이 
매우 비슷하기 때문이다. 
아래의 간단한 강아지 시뮬레이션 프로그램을 보자.*/

/* 마이펫*/
#include <stdio.h>
int main() {
    int input;

    printf("마이펫\n");
    printf("무엇을 하실 것인지 입력하세요 \n");
    printf("1. 밥주기\n");
    printf("2. 씻기기\n");
    printf("3. 재우기\n");

    scanf("%d", &input);

    if (input == 1) {
        printf("아이 맛있어\n");
    } else if (input == 2) {
        printf("아이 시원해\n");
    } else if (input == 3) {
        printf("zzz \n");
    } else {
        printf("무슨 명령인지 못 알아듣겠어. 왈왈\n");
    }
    /* 만약 강아지가 위의 3가지 명령에 대해 반응하는 것이 아니라 10가지 명령에 
    반응하게 하고싶다고 하자. 그렇다면 if와 else if 문을 여러 개 이어붙이는 것은
    소스코드를 보는 사람을 상당히 불편하게 만들 정도로 길어질 것이다. 
    따라서, 위와 같이 동일한 변수에 대해 비교문이 반복되는 경우에 아래와 같이 깔끔한 switch 문을
    적용시킬 수 있다. */
    return 0;
}

/* 업그레이드 버전*/
#include <stdio.h>
int main() {
    int input;

    printf("마이펫 업그레이드\n");
    printf("무엇을 하실 것인지 입력하세요\n");
    printf("1. 밥주기\n");
    printf("2. 씻기기\n");
    printf("3. 재우기\n");

    scanf("%d", &input);

    switch (input) {
        /* 변수 부분에 해당하는 input의 타입은 char, short, int, long 중의 하나여야 한다. 
        왜냐하면 switch 문에 사용될 변수는 반드시 정수 데이터를 보관하는 변수여야 하기 때문이다.
        만약 input 부분에 float이나 double(실수 타입)이 들어가게 되면 컴파일 시 오류가 발생하게 된다. */
        case 1:
            printf("아이 맛있어\n");
            break;
            /* 변수 == 값1 일 때, case 1의 명령이 실행된다. 해당 예제의 경우 1이 입력되면 case 1이 
            참이므로 그 case 안의 내용들이 모두 실행된다. 각 명령들을 모두 실행한 후 break를 만나면 
            switch 문을 빠져나가게 된다. (break 문의 기능 때문임.)*/
        case 2:
            printf("아이 맛있어\n");
            break;
        case 3:
            printf("zzz\n");
            break;

        default:
        /* switch 문의 default는 if 문의 else 와 같은 역할을 한다. 
        default 문은 이도저도 아닌 case들(예외들)이 온다. 
        즉, 해당 예제의 경우 input의 값이 1도 2도 3도 아닌 정수 데이터가 
        올 때 도달하는 경우가 해당한다. */
            printf("무슨 명령인지 못 알아듣겠어. 왈왈\n");
            break;
    }
    return 0;
}

/* 영어 말하기 */
#include <stdio.h>
int main() {
    char input;

    printf("(소문자) 알파벳 읽기\n");
    printf("알파벳 : ");

    scanf("%c", &input);

    switch (input) {
        /* 위에서 switch 문은 정수 데이터만 처리한다고 했는데, 해당 프로그램에서
        문자 데이터 처리가 가능한 이유
        : 컴퓨터는 문자와 숫자를 구분하지 못하기 때문이다. 컴퓨터는 문자를 모두 숫자로
        처리한뒤, 우리에게 보여줄 때에만 문자로 보여주는 것이다. 
        따라서, 문자 = 정수 라고 생각해도 거의 무방하다. */
        case 'a': 
            printf("에이\n");
            break;
        case 'b':
            printf("비\n");
            break;
        case 'c':
            printf("씨\n");
            break;
        
        default:
            printf("죄송해요...머리가 나빠서 못 읽어요\n");
            break;
    }
    return 0;
    
}

/* 문제(3문제)*/
/* 문제 1 : switch 문의 '값' 부분에 왜 정수만 와야 하는가??
    문제 2 : 각 case 문 안에서 적절히 break 하는 것을 빠뜨리면 안된다. 
    문제 3: default를 사용하여 else 문과 같은 효과를 낼 수 있다. */


/* 형 변환(타입 캐스팅)*/
/* C언어에서 각 변수들에는 고유의 형(type)이 있다. 
형(type) 종류 예시: int, char float, double
그런데 가끔씩 프로그래밍을 하다 보면 형이 다른 변수끼리 대입을
하는 연산을 필요로 하게 된다. 
예를 들어서 double 형 변수의 값을 int 형 변수에 대입하거나, 
float 형 벼눗에 double 형 변수의 값을 대입하는 것 등이 있다.
하지만 형이 다른 변수끼리의 대입이나 연산들은 모두 허용되지 않는다. */

/* 무시 */
#include <stdio.h>
int main() {
    int a;
    double b;

    b = 2.4;
    a = b;

    printf("%d", a);
    return 0;
    /* 출력해서 결과를 확인해보면 데이터 손실이 발생하였음을 알 수 있다.
    실행 결과를 보게 된다면 분명히 a 에 2.4를 대입하였지만 a의 결과는 2로 
    나온다. 
    int 형 변수에 double 형 변수를 대입하면 소수 부분이 잘려서 정수 부분만
    들어가게 된다. 이는 각 변수들이 메모리 상에 저장되는 특징들이 다르기 떄문이다. 
    왜냐하면 int 형 변수는 처음 정의되는 시작부터 메모리 상에 오직 정수 데이터만
    받아들이도록 설계되기 때문이다. */
}

/* 무한대 */
#include <stdio.h>
int main() {
    float a = 1. / 0.f;
    printf("a : %f \n", a);
    return 0;
    /* 부호 비트 덕분에 IEEE 754 방식으로 음의 무한대와 양의 무한대를 표현할 수 있다. 
    무한대는 연산 과저에서 표현할 수 있는 가장 큰 수보다 더 큰 값이 들어간다면 자동으로 
    발생하게 된다. 
    성공적으로 컴파일하였으면 
    a : int
    와 같이 진짜로 무한대로 결과가 출력됨을 확인할 수 있다. */
}

/* 형변환(캐스팅)-위위의 코드인 '무시' 수정버전 */
#include <stdio.h>
int main() {
    int a;
    double b;

    b = 2.4;
    a = (int)b;

    printf("%d" , a);
    /* C 표준에서는 main 함수가 명시적으로 return 문을 포함하지 않더라도 프로그램의 
    종료 상태는 0으로 간주한다. 이는 성공적인 실행을 의미한다. 
    따라서, return 0;이 뒤에 붙어있지 않더라도 프로그램은 정상적으로 종료되며, 이는 
    대부분의 C 컴파일러에서 적용되는 규칙이다. */

    /* 해당 코드의 실행 결과는 아까와 동일하게 2이다. 그렇지만 위의 코드에서와는 다르게 
    경고 메세지는 출력이 되지 않는다. 
    그 이유는 바로 해당 코드에서는 강제로 형변환(캐스팅)을 하였기 때문이다. 
    어떠한 변수의 형을 바꾸려면 형식은 다음과 같다.
    형태: (바꾸려는 형) 변수 이름
    예를 들어, 위의 경우 double로 선언된 b를 int로 바꾸었으므로 (int)b라 하면 된다. 
    이때, 형을 바꾼다는 것은 영구적으로 바뀌는 것이 아니다.
    다시 말해 double인 b를 int로 캐스팅 한다고 해도 b가 int인 변수가 되는 것은 아니고 
    계산식에서만 일시적으로 int형 변수로 바꾼 후 생각하라는 것이다.
    즉, 형변환(캐스팅)을 하고도 
    printf("%f", b);를 하게 되면 2.4가 성공적으로 출력된다. */
}

/* 두 수의 비율 */
#include <stdio.h>
int main() {
    int a, b; // a, b는 정수형(int) 변수
    float c, d; // c, d는 실수형(float, double) 변수

    printf("두 숫자 입력 : ");
    scanf("%d %d", &a, &b);

    c = a / b; // 형변환 하지 않음.
    d = (float)a / b; // 형변환 함.

    printf("두 수의 비율: %f %f", c, d);

    return 0;

}

/* 생각해보기-문제 */
/* 문제 1: 임의의 실수에서 소수점 이하 두자리수만 추출하여
정수형 변수에 대입하라. 예를 들어 사용자로부터 입력받은 실수 f가 12.3456이라면
34만 추출한다. 이때 반올림은 고려하지 않아도 상관없다.
f가 달러 단위의 화폐 액수라고 할 때 센트 단위만 추출해내는 
경우라고 생각하면 된다. 다음????자리에 적합한 연산식을 작성하는 문제이다.
printf("실수를 입력하시오: ");
scanf("%f", &f);
i = ????
printf("i=%d\n", i);
이 문제의 핵심은 음수이거나 소수점 이하의 자리수가 없는 경우까지 잘 고려하여
항상 잘 동작하는 코드를 만드는 것이다.*/

/* 배열-C언어의 아파트 */
/*배열(Array): 변수들의 집합.*/

/* 배열 기초 */
#include <stdio.h>
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Array 3 번째 원소 : %d \n", arr[2]);
    return 0;
}

/* 배열 가지고놀기-배열 출력하기 */
#include <stdio.h>
int main() {
    int arr[10] = {2, 10, 30, 21, 34, 23, 53, 21, 9, 1};
    int i;
    for ( i = 0; i < 10; i++) {
        printf("배열의 %d 번째 원소 : %d \n", i + 1, arr[i]);
        /* 배열의 n번째 원소를 참조하려면 arr[n-1] 로 입력해야 한다. 
        (arr[n]이 절대 아니다!!)*/
    }
    return 0;
}

/* 더러운 코드-배열 없이 작성한 코드 */
#include <stdio.h>
int main() {
    int a, b, c, d, e, f, g, h, i, j;
    a = 2;
    b = 10;
    c = 30;
    d = 21;
    e = 34;
    f = 23;
    g = 53;
    h = 21;
    i = 9;
    j = 1;

    printf("1 째 값 : %d \n", a);
    printf("2 째 값 : %d \n", b);
    printf("3 째 값 : %d \n", c);
    printf("4 째 값 : %d \n", d);
    printf("5 째 값 : %d \n", e);
    printf("6 째 값 : %d \n", f);
    printf("7 째 값 : %d \n", g);
    printf("8 째 값 : %d \n", h);
    printf("9 째 값 : %d \n", i);
    printf("10 째 값 : %d \n", j);

    return 0;

}

/* 평균 구하기 */
#include <stdio.h>
int main() {
    int arr[5]; // 성적을 저장하는 배열!!
    int i, ave = 0;

    for (i = 0; i < 5; i++) // 학생들의 성적을 입력받는 부분
    {
        printf("%d 번째 학생의 성적은?? ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 5; i++) // 전체 학생의 평균을 구하는 부분
    {
        ave = ave + arr[i];
    }

    printf("전체 학생의 평균은: %d \n", ave / 5); // 평균이기 때문에 5로 나누기
    return 0;
}

/* 친구의 부탁 */
#include <stdio.h>
int main() {
    int arr[10];
    int i, ave = 0;
    for (i = 0; i < 10; i++) {
        printf("%d 번째 학생의 성적은? ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 10; i++) {
        ave = ave + arr[i];
    }
    ave = ave / 10;
    printf("전체 학생의 평균은: %d \n", ave);
    
    for (i = 0; i < 10; i++) {
        printf("학생%d : ", i + 1);
        if (arr[i] >= ave)
            printf("합격\n");
        else
            printf("불합격\n");
    }
    return 0;
}


/* 소수 찾기(어려움....ㅠㅠ삼성노트기준 141p(책기준 137p)) */     // 코드 작성할 때 위치 주의하자....위치 잘못써서 결과 이상하게 나왔어서 눈이 빠져라 틀린 부분 찾고 있었다ㅠㅠㅠ
#include <stdio.h>
int main() {
    /* 우리가 소수인지 판별하고 있는 수*/
    int guess = 5; // 소수의 배열. 
    /* 해당 코드는 guess가 5로 초기화되어있기 때문에 첫번째 소수 후보가 5로 시작한다. 
    또한, 1은 소수가 아니므로 출력에서 제외되고 2와 3은 이미 prime 배열에 초기화되어
    있으므로 첫번째 출력에서 제외된다. */
    int prime[1000]; /* 현재까지 찾은 (소수의 개수 - 1) 아래 두 개의 소수를 
    미리 찾았으므로 초기값은 1이 된다. */

    int index = 1; /* for 문 변수 */
    int i;
    int ok;
    prime[0] = 2; // 배열의 첫 번째 요소를 2로 초기화
    prime[1] = 3; // 배열의 두 번째 요소를 3으로 초기화
    for (;;) {
        ok = 0;
        for (i = 0; i <= index; i++) {
            if (guess % prime[i] != 0) {
                ok++;
            } else {
                break;
            }
        }
        if (ok == (index + 1)) {
                index++;
                prime[index] = guess;
                printf("소수 : %d \n", prime[index]);
                if (index == 999) break;
            }
            guess += 2;    
    }
        return 0;
    
}

/* 과연 될까? */
#include <stdio.h>
int main() {
    int total;
    printf("전체 학생 수: ");
    scanf("%d", &total);
    int arr[total]; // 처음에 배열의 원소의 수를 숫자로 지정하지 않고, 변수로 지정한 것.
    /* 오류 발생의 원인이 된다......
    이유: 변수는 무조건 최상단에 선언되어야 하기 때문이다. 위와 같이 배열 arr과 변수 i, ave가 
    변수 선언문이 아닌 다른 문장 다음에 나타났으므로 C 컴파일러는 무조건 오류로 처리하게 된다.
    (물론 C++에서는 가능하다. 따라서 내가 사용하는 VSCODE에서는 C++도 가능해서 결과가 정상적으로
    출력되긴 한다.)*/
    int i, ave = 0;

    for (i = 0; i < total; i++) {
        printf("%d 번째 학생의 성적은? ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < total; i ++) {
        ave = ave + arr[i];
    }

    ave = ave /total;
    printf("전체 학생의 평균은: %d \n", ave);

    for (i = 0; i < total; i++) {
        printf("학생%d : ", i + 1);
        if (arr[i] >= ave)
            printf("합격\n");
        else
            printf("불합격\n");
    }

    return 0;
}

/* 설마 이것도?? */
#include <stdio.h>
int main() {
    int total = 3;
    int arr[total];
    int i, ave = 0;

    for (i = 0; i < total; i++) {
        printf("%d 번째 학생의 성적은??: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < total; i++) {
        ave = ave + arr[i];
    }

    ave = ave / total;
    printf("전체 학생의 평균은: %d \n", ave);

    for (i = 0; i < total; i++) {
        printf("학생%d : ", i + 1);
        if (arr[i] >= ave)
            printf("합격\n");
        else
            printf("불합격\n");
    }
    return 0;
    /* 해당 코드는 사실 c언어에 한해서는 오류가 나야 한다.(그렇지만 내가 설치한 첨파일러 프로그램들이 
    새거라서 c언어와 c++ 둘 다 가능하기 때문에 오류가 나진 않는다.) 
    어쨌든 오류의 가능성이 있기 때문에 이런 식으로 작성하면 안 된다!!! 주의하기
    오류의 이유: 처음에 컴파일러가 배열을 처리할 때 메모리 상에 공간을 잡아야 하는데,
    이때 잡아야 되는 공간의 크기가 반드시 상수로 주어져야 하기 때문이다. 
    간략하게 말해서, '배열의 크기는 변수로 지정할 수 없다' 정도로 이해하면 됨.*/
}

/* 상수 */
#include <stdio.h>
int main() {
    const int a = 3; // a 라는 이름의 int 형 상수이고, 그 값은 3이라는 의미.

    printf("%d", a);
    return 0;
    /* 상수는 변수의 정반대의 성질을 가진 것으로, 처음 정의 시
    그 값이 바로 주어지고, 그 값이 영원히 바뀌지 않는다. 
    형태: const (상수의 형) (상수 이름) = (상수의 값); */
}


/* 초기화 되지 않은 값 출력 */
#include <stdio.h>
int main() {
    int arr[3];
    arr[0] = 1;

    printf("니 값은 모니: %d", arr[1]);
    return 0;
    /* 출력은 가능하지만, 출력값을 예측할 수 없음.
    초기화되지 않은 변수는 예측 불가능한 동작을 초래할 가능성이 있으므로,
    항상 변수를 선언할 때는 초기화하여 예측 가능한 결과와 안정적인 프로그램 동작을
    보장하는 것이 좋다. */
}

/* 생각해볼 문제 */
/* 문제 1: 위 입력받는 학생들의 성적을 높은 순으로 정렬하는 프로그램을 만들어라.*/

/* 문제 2: 입력받은 학생들의 성적을 막대 그래프로 나타내는 프로그램을 만들어라.*/
#include <stdio.h>

#define MAX_STUDENTS 100 // 프로그램이 처리할 수 있는 최대 학생 수
#define MAX_GRADE 100 // 성적의 최대 값(여기서는 100으로 설정)
#define GRAPH_HEIGHT 10 // 막대 그래프의 최대 높이 (여기서는 10으로 설정)

void print_bar(int score, int max_score) {
    /* print_bar */
    /* 역할: 주어진 성적을 기반으로 막대 그래프를 출력한다. score와 max_score를 
    사용하여 막대의 길이를 계산하고, 해당 길이만큼 "#" 문자를 출력한다. */
    int bar_length = (score * GRAPH_HEIGHT) / max_score;
    for (int i = 0; i < bar_length; i++) {
        printf("#");
    }
}

int main() {
    /* main 함수: 
    1. 학생 수와 성적을 입력받는다.
    2. 성적의 유효성을 검사한다.
    3. 가장 높은 성적을 찾는다.
    4. 모든 학생의 성적을 막대 그래프로 출력한다.*/
    int total_students;
    int scores[MAX_STUDENTS];

    printf("학생 수를 입력하세요 (최대 %d명): ", MAX_STUDENTS);
    scanf("%d", &total_students);

    if (total_students < 1 || total_students > MAX_STUDENTS) {
        printf("학생 수가 유효 범위를 벗어났습니다.\n");
        return 1; /* return 1;은 프로그램이 비정상적으로 종료되었음을 나타낸다. 
        즉, 오류가 발생했음을 의미한다. 
        main 함수에서 return 1;을 사용하면 운영 체제에 오류가 발생했음을 알리는 
        신호를 보낸다.
        많은 프로그램에서 return 1; 또는 다른 비제로 값을 반환함으로써 실행 중 
        오류가 있었음을 나타낸다.
        (return 0;은 프로그램이 정상적으로 종료되었음을 나타내며, '0'은 일반적으로 
        성공적인 실행을 의미한다.)*/
    }

    int max_score = 0;

    for (int i = 0; i < total_students; i++) {
        printf("학생 %d의 성적을 입력하세요 (0 ~ %d): ", i + 1, MAX_GRADE);
        scanf("%d", &scores[i]);

        if (scores[i] < 0 || scores[i] > MAX_GRADE) {
            printf("성적이 유효 범위를 벗어났습니다.\n");
            return 1;
        }

        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    printf("\n학생들의 성적을 막대 그래프로 나타내겠습니다:\n");

    for (int i = 0; i < total_students; i++) {
        printf("학생 %d: ", i + 1);
        print_bar(scores[i], max_score);
        printf(" (%d)\n", scores[i]);
    }

    return 0;
}

/* 2차원 배열 */
#include <stdio.h>
int main() {
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};

    printf("arr 배열의 2 행 3 열의 수를 출력: %d \n", arr[1][2]);
    printf("arr 배열의 1 행 2 열의 수를 출력: %d \n", arr[0][1]);
    return 0;
}

/* 학생 점수 입력받기 */
#include <stdio.h>
int main() {
    int score[3][2]; // 앞의 3은 학생 수, 뒤의 2는 과목 수(국어, 수학) -> i = 학생수, j = 과목수
    int i, j;

    for (i = 0; i < 3; i++) // 총 3 명의 학생의 데이터를 받는다.
    {
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                printf("%d 번째 학생의 국어 점수: ", i + 1);
                scanf("%d", &score[i][j]);
            } else if (j == 1) {
                printf("%d 번째 학생의 수학 점수: ", i + 1);
                scanf("%d", &score[i][j]);
            }
        }
    }

    for (i = 0; i < 3; i++) {
        printf("%d 번째 학생의 국어 점수: %d, 수학 점수: %d \n", i + 1,
            score[i][0], score[i][1]); // c언어는 입력한 순서대로 읽어나가기 때문에 순서대로 출력됨(%d 말하는 것임.)
    }

    return 0;
    /* 예제에서 int arr[2][3] = {1,2,3,4,5,6};과 같이 2차원 배열을 선언했을 때는 줄 수를 줄이기 위해서
    int arr[2][3] = {{1,2,3}, {4,5,6}};과 같이 해도 의미가 동일하므로 사용이 가능하다. */
}

/* 포인터(pointer): 주소값.
포인터는 특정한 데이터가 저장된 (시작)주소값을 보관하는 변수이다. */

/* &  연산자*/
#include <stdio.h>
int main() {
    int a;
    a = 2;

    printf("%p \n", &a); /* &a 의 값을 16진수 형태(%p)로 출력하라는 명령의 의미*/
    return 0;
    /* & 연산자를 사용하면 특정한 데이터의 메모리 상의 주소값을 알 수 있다. */
}



/* 포인터의 시작 */
#include <stdio.h>
int main() {
    int *p; /* *p 는 p 가 int 형 데이터를 가리키는 포인터임을 선언한다. 
    *p 는 포인터가 가리키는 주소에 저장된 값을 참조한다. */
    int a;

    p = &a; /* p = &a; 는 변수 a 의 주소를 포인터 p 에 저장한다. &a 는 변수 a 의 메모리 주소를 나타낸다. */

    printf("포인터 p 에 들어있는 값: %p \n", p); /* %p 는 포인터 변수의 주소를 출력하는 서식 지정자이다. 
    p 는 포인터 변수 자체를 의미하기 때문에, p 는 변수 a 의 메모리 주소를 저장하고 있으며, p 를 출력하면 a 의 주소가 출력된다. 
    *p 는 포인터가 가리키는 주소에 저장된 값을 참조한다. 하지만 여기에서는 *p 가 아니라 p 를 사용하여 포인터가 저장하고 
    있는 주소 자체를 출력하는 것이다. */
    printf("int 변수 a 가 저장된 주소: %p \n", &a); /* &a 는 변수 a 의 메모리 주소를 나타낸다. 
    이 주소는 p 가 저장하고 있는 주소와 동일해야 한다. */
    
    return 0;
    /* 포인터를 출력할 때 *p 를 사용하는 것이 아니라 p 를 사용하는 이유는 p 가 이미 주소를 저장하고 있기 때문이다.
    *p 를 사용하면 포인터가 가리키는 메모리 위치의 값을 출력하게 되며, 이 경우에는 a 의 값을 출력하게 된다. 
    하지만 코드에서는 포인터가 저장한 주소를 직접 확인하고자 하므로 p 를 사용하여 주소를 출력하는 것이다. */
    
    /* 출력값은 두 개가 동일하게 나온다. 그 이유는 포인터 p 에 a 의 주소를 대입하였기 때문이다. 
    따라서 아래 printf 에서 포인터 p 에 저장된 값과 변수 a 의 주소값이 동일하게 나오게 된다. 
    (참고로, 한 번 정의된 변수의 주소값은 바뀌지 않는다.)*/
}

/* 연산자- * 연산자의 이용!!! */
#include <stdio.h>
int main() {
    int *p; /* 
    *의 의미는 '나에 저장된 주소값에 해당하는 데이터로 생각하시오!!'로 하게 하는 연산자의 의미라고 보면 된다. 
    따라서 *p 를 통해 p 에 저장된 주소(변수 a 의 주소)에 해당하는 데이터, 즉 변수 a 그 자체를 의미할 수 있게 된다.
    그러므로 *p 와 변수 a 는 정확히 동일하다. 
    */
    int a;

    p = &a;
    a = 2;

    printf("a 의 값: %d \n", a);
    printf("*p 의 값: %d \n", *p);

    return 0;
}

/* * 연산자 */
#include <stdio.h>
int main() {
    int *p;
    int a;

    p = &a;
    *p = 3;

    printf("a 의 값: %d \n", a);
    printf("*p 의 값: %d \n", *p);

    return 0;
    /* 해당 코드도 위의 코드와 마찬가지로 p 에 변수 a 의 주소를 집어넣었다. 
    그리고 *P 를 통해 "나에 저장된 주소(변수 a 의 주소)에 해당하는 데이터(변수 a)로 생각하시오"를 
    의미하여 *p = 3 은 a = 3 과 동일한 의미를 지니게 되었다. */
}


/* 포인터도 변수이다. */
#include <stdio.h>
int main() {
    int a;
    int b;
    int *p;

    p = &a;
    *p = 2;
    p = &b;
    *p = 4;
    /* 포인터는 변수이다. 즉, 포인터에 들어간 주소값이 바뀌는 것이 가능하다.
    (상수가 아니므로) */

    printf("a : %d \n", a);
    printf("b : %d \n", b);
    return 0;
}

/* 상수 포인터? */
#include <stdio.h>
int main() {
    int a;
    int b;
    const int* pa = &a; /* int* pa 와 같이 정의해도 int *pa와 동일한 의미이다!!*/
    /* const 라는 키워드는 '이 데이터의 값은 절대로 바뀌면 안된다' 라고 일러주는 키워드이다.
    다시 말해, const int a 라는 변수는 그냥 int 형 변수 a 인데 값이 절대로 바뀌면 안되는 변수일
    뿐이다. 따라서, const int a 변수도 그냥 int 형이라고 말할 수 있다. (다만 '변'수가 아닐 뿐..)
    그러므로 const int* 의 의미는 const int 형 변수를 가리킨다는 것이 아니라, int 형 변수를 가리키는데
    '그 값을 절대로 바꾸지 말라'라는 의미이다. 
    즉, pa 는 어떠한 int 형 변수를 가리키고 있다. 그런데 const 가 붙었으므로 pa 가 가리키는 변수의 
    값은 절대로 바뀌게 하면 안된다. 
    여기서 pa 가 라는 부분을 강조한 이유는 a 자체는 변수이므로 값이 자유롭게 변경될 수 있기 때문이다.
    하지만 pa 를 통해서 a 를 간접적으로 가리킬 때에는 컴퓨터가 아, 내가 const 인 변수를 가리키고 있구나
    로 생각하기 때문에(const int* 로 포인터를 정의하였스므로) 값을 바꿀 수 없게 된다. */

   // *pa = 3; // 올바르지 않은 문장
    
    pa = &b; // 올바른 문장
    return 0;
}

/* 상수 포인터??-2 */
#include <stdio.h>
int main() {
    int a;
    int b;
    int* const pa = &a;
    /* 해당 코드는 출력했을 때 오류가 난다. 
    우리는 int* 를 가리키는 pa 라는 포인터를 정의하였다. 이번에는 앞서 짠 코드와는 달리
    const 키워드가 int* 앞에 있는 것이 아니라 int* 와 pa 사이에 놓이고 있다. 
    이는 pa 의 값이 바뀌는 것이 안된다는 의미이다. 
    그런데 제일 처음에 포인터를 배울 때 강조했듯이, 포인터에는 가리키는 데이터의 주소값,
    즉 위 경우 a 의 주소값이 pa 에 저장된다. 따라서 이 pa 가 const 라는 의미는 pa 의 값이
    절대로 바뀔 수 없다는 것인데, pa 는 포인터가 가리키는 변수의 주소값이 들어 있으므로 
    결과적으로 pa 가 처음에 가리키는 것인 변수 a 말고 다른 것(=다른 변수들)은 절대로 건드릴 수 없다는 것이다. */

    *pa = 3; // 올바른 문장
    // pa = &b; // 올바르지 않은 문장

    return 0;
}


/* 포인터의 덧셈 */
#include <stdio.h>
int main() {
    int a;
    int* pa;
    pa = &a;

    printf("pa 의 값: %p \n", pa);
    printf("(pa + 1) 의 값: %p \n", pa + 1);

    return 0;
}


/* 과연? */
#include <stdio.h>
int main() {
    int a; // 4 바이트
    char b; // 1 바이트
    double c; // 8바이트
    int* pa = &a;
    char* pb = &b;
    double* pc = &c;

    printf("pa 의 값: %p \n", pa);
    printf("(pa + 1)의 값: %p \n", pa + 1);
    printf("pb 의 값: %p \n", pb);
    printf("(pb + 1)의 값: %p \n", pb + 1);
    printf("pc 의 값: %p \n", pc);
    printf("(pc + 1) 의 값: %p \n", pc + 1);

    return 0;
    /* 출력 결과는 pb 의 경우 1 이 더해졌고, pc 의 경우 8 이 더해졌다. 
    char 은 1 바이트, double 은 8 바이트 이기 때문이다. 
    하지만 왜 하라는 대로 1씩 더하지 않고 포인터가 가리키는 형의 크기만큼 더할까??
    (이에 대한 해답은 뒤에서 설명할 것임-교재 피셜...) */
}

/* 포인터 뺄셈 */
#include <stdio.h>
int main() {
    int a;
    int* pa = &a;

    printf("pa 의 값: %p \n", pa);
    printf("(pa = 1) 의 값: %p \n", pa - 1);

    return 0;
    /* 해당 코드를 출력해보면 4만큼의 값이 빠졌음을 알 수 있다. (16진수 기준.)*/
}


/* 포인터끼리의 덧셈 */
#include <stdio.h>
int main() {
    int a;
    int *pa = &a;
    int b;
    int *pb = &b;
    // int *pc = pa + pb; // 오류 발생함.(두 포인터는 더할 수 없다.)

    return 0;
    /* 포인터끼리의 덧셈은 아무런 의미가 없을 뿐더러 필요하지 않다. 따라서 C 에서는 두 포인터끼리의 덧셈을 허용하지 않는다.
    두 변수의 메모리 주소를 더해서 나오는 값은 이전에 포인터들이 가리키던 두 개의 변수와 아무런 관련이 없는 메모리 속의
    임의의 지점이다. 아무런 의미가 없는 프로그램 상에 상관없는 지점을 말하는 것이다. 
    (물론 앞서 짜여진 코드와 같이 포인터에 정수를 더하는 것이 되는 이유는 후에 설명할 것이다.-교재 피셜...)
    그런데 한 가지 놀라운 점은 포인터끼리의 뺄셈은 가능하다는 것이다. 
    (이것 역시 그 이유에 대한 상세한 설명은 나중에 할 것이다.- 교재 피셜...)*/
}

/* 포인터의 대입 */
#include <stdio.h>
int main() {
    int a;
    int* pa = &a;
    int* pb;

    *pa = 3;
    pb = pa;

    printf("pa 가 가리키고 있는 것: %d \n", *pa);
    printf("pb 가 가리키고 있는 것: %d \n", *pb);

    return 0;
}

/* 배열의 존재 상태? */
#include <stdio.h>
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;

    for (i = 0; i < 10; i++) {
        printf("arr[%d] 의 주소값: %p \n", i, &arr[i]);
    }
    return 0;
}


/* 과연?? */
#include <stdio.h>
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int* parr;
    int i;
    parr = &arr[0]; /* parr 이라는 int 형을 가리키는 포인터는 arr[0] 이라는 int 형 변수를 가리킨다. 
    (배열의 각 원소는 하나의 변수로 생각할 수 있다는 사실 까먹지 말기!!)*/

    for (i = 0; i < 10; i++) {
        printf("arr[%d] 의 주소값: %p ", i, &arr[i]);
        printf("(parr + %d) 의 값: %p ", i, (parr + i));

        if (&arr[i] == (parr + i)) {
            /* 만일 (parr + i) 가 성공적으로 arr[i] 를 가리킨다면 */
            printf(" --> 일치\n");
        } else {
            printf("--> 불일치\n");
        }
    }
    return 0;
    /* parr 이 int 형이므로 + i 를 하면 주소값에는 사실상 4*i 가 더해지게 된다. 
    이때 arr[i] 의 주소값도 i 가 하나씩 커질 때마다 4씩 증가하므로(int 형 배열이므로) 
    결과적으로 모든 결과가 일치하게 되는 것이다. 
    이처럼 포인터에 정수를 더하는 것만으로도 배열의 각 원소를 가리킬 수 있다.
    그렇다면 *를 이용하여 원소들과 똑같은 역할을 할 수 있게 된다.
    (바로 아래의 코드가 예제.) */
}

/* 우왕 */
#include <stdio.h>
int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int* parr;

    parr = &arr[0];

    printf("arr[3] = %d, *(parr + 3) = %d \n", arr[3], *(parr + 3));
    return 0;
    /* parr + 3 을 수행하면 arr[3] 의 주소값이 되고, 거기에 *을 붙여주면 *의 연산자의 역할이 
    '그 주소값에 해당하는 데이터를 의미해라!' 라는 뜻이므로 *(parr + 3)은 arr[3]과 동일하게 
    된다는 것이다. */
}


/* 배열의 이름의 비밀 */
#include <stdio.h>
int main() {
    int arr[3] = {1, 2, 3};
    printf("%d", arr); // arr는 배열의 첫 번째 요소의 주소를 가리킨다. 
    // arr 앞에 &가 붙지 않는 이유는?
    /* 이유를 알기 위해서는 우선 '배열과 포인터의 관계'에 대해서 알아야 한다.
    배열과 포인터의 관계: 배열의 이름은 배열의 첫 번째 요소의 주소를 가리키는 포인터로 취급된다.
    따라서 배열의 이름 자체가 이미 주소를 의미한다. 이를 통해 배열과 포인터가 어떻게 상호작용하는지 
    이해할 수 있다. 
    - 배열의 이름(여기서는 arr)은 배열의 첫 번째 요소의 주소를 나타낸다. 따라서 arr 은 &arr[0] 과 동일한 의미를 가진다.
    -&arr 는 배열 전체의 주소를 나타낸다. 배열의 이름 arr 는 배열의 첫 번째 요소의 주소를 가리키므로 arr 과 &arr 은 
      다르게 해석될 수 있다. 하지만 arr 를 단독으로 사용할 때는 첫 번째 요소의 주소를 의미하므로 &를 추가로 사용할 필요는 없다.  */

    /* 주소를 출력할 때는 %p 포맷 specifier를 사용하는 것이 더 적절하다. */
}

/* 배열은 배열이고 포인터는 포인터이다.*/
#include <stdio.h>
int main() {
    int arr[6] = {1,2,3,4,5,6};
    int* parr = arr; // arr은 int arr[6] 배열의 첫 번째 요소의 주소를 가리킨다. 
    // 따라서 int* parr = arr;는 parr 포인터가 배열 arr 의 첫 번째 요소를 가리키도록 한다. 


    printf("Sizeof(arr): %d \n", sizeof(arr));
    /* sizeof 를 arr 자체에 그대로 썼을 경우 배열의 실제 크기가 나온다.
    해당 코드에서는 arr 배열에 int 원소 6 개가 있으므로 크기는 24 가 된다. (int 원소는 1개당 4비트)*/
    printf("Sizeof(parr) : %d \n", sizeof(parr));
    /* 위의 줄과는 달리, parr 에 sizeof 연산자를 사용하였을 경우, 배열 자체의 크기가 아니라 
    그냥 포인터의 크기를 알려준다. 
    (64 비트 컴퓨터이므로 출력된 값은 8(비트) 이다. */
}

/* [] 연산자 */
#include <stdio.h>
int main() {
    int arr[5] = {1,2,3,4,5};

    printf("a[3] : %d \n", arr[3]);
    printf("*(a + 3) : %d \n", *(arr + 3)); 
    /*arr[3] 이라 사용한 것은 사실 *(arr + 3) 으로 바꾸어서 처리가 가능하다.
    그리고 arr 은 + 연산자와 사용되기 때문에, 첫 번째 원소를 가리키는 포인터로
    변환되어서 arr + 3 이 포인터 덧셈을 수행하게 된다. 이는 arr 배열의 4번째 원소인 4를 가리키게 된다. */
    return 0;
}

/* 신기한 [] 사용 */
#include <stdio.h>
int main() {
    int arr[5] = {1,2,3,4,5};

    printf("3[arr] : %d \n", 3[arr]); // 3[arr] 은 조금 이상한 표현같지만, 위의 코드와 같은 의미를 가지며 출력이 가능하다.
    printf("*(3 + a) : %d \n", *(arr + 3));
    return 0;
    /* 3[arr] 은 무언가 조금 이상한 표현이다. 이렇게 사용한다면 가독성도 떨어지고 한 번에 이해되기 어렵다는 단점이 있다.
    하지만, 앞에서도 [] 는 연산자로 3[arr] 을 *(3 + arr) 로 바꿔주기 때문에 arr[3] 과 동일한 결과를 출력할 수 있다. */
}

/* 생각해볼 문제 */
/* 문제 1
int arr[3][3]; 과 같은 배열은 내부저긍로 어떻게 처리되는지 생각해보세요*/
/* 문제 2
int* arr[3]; 과 같은 배열이 가지는 의미는 무엇일까요??*/

/* "배열은 배열이고 포인터는 포인터이다." */
// sizeof 와 주소값 연산자(예시: parr)와 함께 사용할 때를 제외하면, 배열의 이름은 첫 번째 원소를 가리킨다.
// arr[i] 와 같은 문장은 사실 컴파일러에 의해 *(arr + i) 로 변환된다. 

/* 1차원 배열 가리키기 */
#include <stdio.h>
int main() {
    int arr[3] = {1,2,3};
    int *parr; // 정수형(int) 형 포인터 parr 을 선언하는 부분.(당연히 이 포인터는 정수형 데이터를 가리킬 수 있다.)

    parr = arr; // arr 를 parr 에 대입하는 부분이다. 
    /* arr 은 배열의 첫 번째 원소를 가리키는 포인터로 변환되고, 그 원소의 타입이 int이므로, 
    포인터의 타입은 int* 가 된다. */
    /* * parr = &arr[0]; 도 동일한 의미를 가진다!! */

    printf("arr[1] : %d \n", arr[1]); // 배열을 통해 접근 -> arr[1] 은 배열의 두 번째 요소에 접근한다.
    printf("parr[1] : %d \n", parr[1]); // 포인터를 통해 접근 -> parr[1] 은 포인터가 가리키는 배열의 두 번째 요소에 접근한다.
    /* 위의 두 printf(~)의 경우 모두 동일한 메모리 위치에 접근하므로, 같은 값을 출력한다.*/
    return 0;
}

/* 포인터 이용하기 */
#include <stdio.h>
int main() {
    int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};

    int *parr = arr; // int 형 1차원 배열을 가리킬 수 있는 int* 포인터를 정의한다. 
    //이 parr은 배열 arr을 가리키게 된다.
    int sum = 0;

    while (parr - arr <= 9) { // 해당 while 문은 parr - arr 이 9 이하일 동안 돌아가게 된다. (parr - arr >= 10 이 된다면 parr[10 이상의 값]을 접근하게 되므로, 오류를 뿜게 된다.)
        sum += (*parr);
        parr++; // parr 을 1 증가시킨다.
        /* 포인터 연산에서 1 증가시킨다면, parr 에 저장된 주소값에 1이 더해지는 것이 아니라
        1 * (포인터가 가리키는 타입의 크기) 가 더해진다. 
        따라서 int 형 포인터이므로 4 가 더해지게 돼서 배열의 그 다음 원소를 가리킬 수 있게 된다. 
        (따라서, arr[n+1]이 된다!!위치가 한 칸씩 뒤로 가는 것이 되는 것이므로 배열을 순서대로 읽고 출력하게 된다. )*/
    }

    printf("내 시험 평균: %d \n", sum / 10);
    return 0;
}

/* 포인터의 포인터 */
#include <stdio.h>
int main() {
    int a;
    int *pa;
    int **ppa; // ppa 는 int* 를 가리키는 포인터이다. (포인터의 포인터!!)

    pa = &a; // pa 에는 a 의 주소값이 들어간다. -> 따라서, &a 와 pa 는 동일한 값을 가지게 된다. 
    ppa = &pa; // ppa 에는 pa 의 주소값이 들어가게 된다. -> *ppa 를 하면 pa 를 지칭하는 것이 되므로, pa 의 값인 &a 를 출력하게 된다. (동일한 값을 가짐.)

    a = 3;

    printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
    printf("&a : %p // pa : %p // *ppa : %p \n", &a, pa, *ppa);
    printf("&pa : %p // ppa : %p \n" , &pa, ppa);

    return 0;
    /* 위의 포인터들에 의하여, 출력된 값들은 같은 행에 있는 값들이 서로 동일한 값을 가진다.*/
}


/* 배열 이름의 주소값?*/
/* 지난번에 배열 이름에 sizeof 연산자와 주소값 연산자를 사용할 때 빼고는 
전부 다 포인터로 암묵적 변환이 이루어진다고 하였다. 그렇다면 주소값 연산자를
사용하면 어떻게 되는지 코드를 통해서 알아보자. */
#include <stdio.h>
int main(){
    int arr[3] = {1,2,3};
    int (*parr)[3] = &arr; // &arr 은 int ** 의 의미가 아니다!!!!(주의하기)
    /* 이전에 arr 은 int * 로 암묵적 변환된다고 하였으니까 &arr 은 int ** 의 의미를 
    가질 것이라고 생각할 수도 있지만, 그렇지 않다.
    이유 : 암묵적 변환은 주소값 연산자가 왔을 때에는 이루어지지 않는다. 
    arr 이 크기가 3인 배열이기 때문에, &arr 을 보관할 포인터는 크기가 3인 배열을 가리키는
    포인터가 되어야 할 것이다. 
    참고로 parr 을 정의할 때 *parr 을 꼭 소괄호()로 감싸야만 한다. 만약 괄호를 빼버린다면 
    int *parr[3]; 과 같이 되어서 C 컴파일러가 int * 원소 3 개를 가지는 배열을 정의하는 것으로
    오해하게 된다.  */

    printf("arr[1] : %d \n", arr[1]);
    printf("parr[1] : %d \n", (*parr)[1]);
    /* parr 은 크기가 3인 배열을 가리키는 포인터이기 때문에 배열을 직접 나타내기 위해서는 
    * 연산자를 통해 원래의 arr 을 참조해야 한다. 
    따라서 (*parr)[1] 과 arr[1] 은 동일한 문장이 된다. 
    (한 가지 알아두어야 하는 것은 parr 과 arr 은 동일한 값을 가진다는 점이다.)*/
}

/* 배열 이름의 주소값?-2 */
#include <stdio.h>
int main() {
    int arr[3] = {1,2,3};
    int(*parr)[3] = &arr;

    printf("arr : %p \n", arr);
    printf("parr : %p \n", parr);
}

/* 정말로?? */
#include <stdio.h>
int main() {
    int arr[2][3];

    printf("arr[0] : %p \n", arr[0]);
    printf("&arr[0][0] : %p \n", &arr[0][0]);

    printf("arr[1] : %p \n", arr[1]);
    printf("&arr[1][0] : %p \n", &arr[1][0]);

    return 0;
    /* 출력된 주소값을 보면, arr[0] 의 값이 arr[0][0] 의 주소값과 같고 
    arr[1] 의 값이 arr[1][0] 의 주소값과 같다. 
    이를 통해 알 수 있는 사실은 기존의 1차원 배열과 마찬가지로 sizeof 나 주소값 연산자와
    사용되지 않을 경우, arr[0] 은 arr[0][0] 을 가리키는 포인터로 암묵적으로 타입변환되고,
    arr[1] 은 arr[1][0] 을 가리키는 포인터로 타입변환된다는 뜻이 된다. 
    따라서 sizeof 를 사용하였을 경우 2 차원 배열의 열의 수를 계산할 수 있다. 
    (아래의 코드가 그 예시이다.)*/
}


/* sizeof 연산자를 사용해였을 경우, 2차원 배열의 열의 개수를 계산할 수 있다.*/
#include <stdio.h>
int main() {
    int arr[2][3] = {{1,2,3}, {4,5,6}};
    printf("전체 크기: %d \n", sizeof(arr)); 
    /* 배열에 sizeof 를 할 경우, 당연하게도 배열의 전체 크기가 나오게 된다. */
    printf("총 열의 개수: %d \n", sizeof(arr[0]) / sizeof(arr[0][0]));
    /* 위 문장에서 sizeof(arr[0])를 하면 0번째 행의 길이(총 열의 개수)가 나온다. 
    앞에서 강조한 것과 같이, sizeof 연산자의 경우 포인터로 타입 변환을 시키지 않기 때문에
    sizeof(arr[0])는 마치 sizeof 에 1차원 배열을 전달한 것과 같다. 따라서 그 크기는 3 으로 출력된다. */
    printf("총 행의 개수: %d \n" , sizeof(arr) / sizeof(arr[0]));
}


/* 포인터의 형(type) 을 결정짓는 두 가지 요소 */
/* 과연 될까?? */ 
#include <stdio.h>
int main() {
    int arr[2][3] = {{1,2,3}, {4,5,6}};
    int **parr;

    parr = arr;

    printf("arr[1][1] : %d \n", arr[1][1]);
    printf("parr[1][1] : %d \n", parr[1][1]);

    return 0;
    // --> 해당 코드를 출력하면 오류가 발생한다!!!
}

/* 1 증가하면? */
#include <stdio.h>
int main() {
    int arr[2][3] = {{1,2,3}, {4,5,6}};

    printf("arr : %p, arr + 1 : %p \n", arr, arr + 1);

    return 0;
    /* 출력값을 빼면 (arr + 1) - arr = 0xC(16진수) 가 나오는데 0xC 는 십진수로 12이다.
    위 배열의 b 값은 3 이고 int 의 크기는 4 바이트이므로, 3 * 4 = 12 가 딱 맞게 된다. */
}

/* 드디어!! 배우는 배열의 포인터 */
#include <stdio.h>
int main() {
    int arr[2][3] = {{1,2,3}, {4,5,6}};
    int(*parr)[3]; // 괄호를 꼭 붙이기

    parr = arr; // parr 이 arr 을 가리키게 한다.

    printf("parr[1][2] : %d , arr[1][2] = %d \n", parr[1][2], arr[1][2]);

    return 0;
}

/* 배열 포인터 */
#include <stdio.h>
int main() {
    int arr[2][3];
    int brr[10][3];
    int crr[2][5];

    int(*parr)[3];

    parr = arr; // o.k
    parr = brr; // o.k
    parr = crr; // 오류!!!!!!!
    /* parr 라는 포인터 변수가 arr 과 brr 에는 할당될 수 있지만 crr 에는 할당될 수 없는 이유
    : 배열의 크기 때문!!
    parr 의 선언은  int(*parr)[3]; 이다. 이는 parr 가 int 타입의 3개 요소로 구성된 배열을 가리킬 수 있다는 뜻이다.
    1. parr = arr; , parr = brr;
    -arr 는 int[2][3] 타입이다. 
    -arr 는 두 개의 int[3] 배열을 가지고 있다.
    -parr 는 int[3] 배열을 가리킬 수 있으므로, 이는 올바른 할당이다. 
    2. parr = crr;
    -crr 는 int[2][5] 타입이다.
    -crr 는 두 개의 int[5] 배열을 가지고 있다. 
    -parr 는 int[3] 배열을 가리킬 수 있어야 하는데, crr 는 int[5] 배열을 가지고 있으므로 이는 잘못된 할당이다. 
    --> parr 가 crr 를 가리키게 되면 parr 는 int[3] 타입의 배열을 기대하지만 실제로는 int[5] 배열을 가리키게 되므로
    이는 잘못된 할당에 해당한다.*/

    return 0;
}

/* 포인터 배열 */
#include <stdio.h>
int main() {
    int *arr[3]; // int* arr[3] 과 동일한 의미!!!!!
    /* 우리가 배열의 형을 int, char 등으로 하듯이, 배열의 형을 역시 int* 으로도 할 수 있다.
    다시말해, 배열의 각각의 원소는 int 를 가리키는 포인터 형으로 선언된 것이다. 
    따라서 int 배열에서 각각의 원소를 int 형 변수로 취급했던 것처럼 int* 배열에서 각각의 원소를 포인터로 취급할 수 있다. */
    int a = 1, b = 2, c = 3;
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    printf("a : %d, *arr[0] : %d \n", a, *arr[0]);
    printf("b : %d, *arr[1] : %d \n", b, *arr[1]);
    printf("c : %d, *arr[2] : %d \n", c, *arr[2]);

    printf("&a : %p, arr[0] : %p \n", &a, arr[0]);
    return 0;
}

/* 생각해볼 문제 */
/* 문제 1
: 3차원 배열의, 배열 이름과 동일한 포인터는 어떻게 정의될 것인가??
(참조: 2차원 배열에선 int (*arr)[4]; 와 같은 꼴이었다.)*/
/* 문제 2
: 포인터 간의 형변환은 무엇을 의미하는가?? 그리고, C 언어에서 포인터 간의 형변환이
위험한 것인가?? 
(참고적으로, 포인터 간의 형변환은 아직 이야기한 적이 없으나 한 번 시도는 해보세요.)*/


/* 함수(function)- 함수의 시작*/
#include <stdio.h>
int print_hello() { // 함수를 호출하기 위해서는 '함수의 이름()' 형태로 작성하면 된다. 
/* 만일 함수를 호출하려고 print_hello; 라고 쓴다면, 컴파일러는 '어딘가에 print_hello 라는
변수에 접근하였네' 라고 생각하는데, print_hello 라는 변수가 없으므로 오류를 출력하게 된다. */
    printf("Hello!! \n");
    return 0;
    /* return 을 실행하면 함수는 무조건 종료되어 함수를 호출하였던 부분으로 돌아가게 된다. */
}

int main() {
    printf("함수를 불러보자 : ");
    print_hello();

    printf("또 부를까?? ");
    print_hello();
    return 0;
    /* 보통 C 언어에서, 좋은 함수의 이름은 그 함수가 무슨 작업을 하는지 명확히 하는 것이다.
    수학에서는 f(x), g(x) 로 막 정하지만, C 언어에서는 그 함수가 하는 작업을 설명해주는 이름을 
    하는 것이 좋다. */
}

/* 함수의 리턴 */
#include <stdio.h>
int return_func() {
    printf("난 실행된다.\n");
    return 0;
    printf("난 안돼ㅠㅠ\n");
}
int main() {
    return_func();
    return 0;
    /* return 이 실행되면 프로그램은 바로 함수를 호출하였던 부분으로 넘어가버려 
    그 다음에 오는 모든 것들(위 예제에선 printf("난 안돼ㅠㅠ\n");) 이 실행되지 않는다. */
}

/* 반환값 */
#include <stdio.h>
int ret() { return 1000; } // 함수의 이름은 ret 이고, int 형을 반환한다. 그리고 { return 1000; }는 "이 함수를 호출하면 1000 을 리턴한다."라는 뜻이다.
int main() {
    int a = ret(); /* ret() 는 함수이기에 이 위치에 쓰면 안될 것 같지만, ret() 를 코드에 쓰게 된다면,
    이 말은 'ret() 함수의 반환값' 이라는 의미를 가지게 된다. 
    즉, 컴퓨터가 위 코드를 실행한다면 a 에는 ret 함수의 반환값인 1000 이 들어가게 된다.
    ('호랑이는 죽어서 가죽을 남기고, 함수는 죽어서 리턴값을 남긴다!!')*/
    printf("ret() 함수의 반환값: %d \n", a);

    return 0;
}

/* 메인(main) 함수 */
/* 왜 하필이면 main 을 정의하는지??
이유: 프로그램을 실행할 때, 컴퓨터는 main 함수부터 찾기 때문이다!!!!
(물론 모든 경우가 그런 것은 아니지만, 적어도 우리가 앞으로 만들게 될 C 프로그램의 경우.)
즉, 컴퓨터는 프로그램을 실행할 때 프로그램의 main 함수를 호출함으로써 시작한다.
만일 main 함수가 없다면 컴퓨터는 프로그램의 어디서부터 실행할 지 모르게 되어 오류가 난다.*/

/* 마술 상자 */
#include <stdio.h>
int magicbox() {
    i += 4;
    return 0;
}
/* 해당 함수(magicobx())는 인자로 아무것도 받지 않는다. 
함수 내부에서 i 를 사용하고 있지만, i 가 함수 내에서 정의되지 않았기 때문이다.
따라서 i 는 전역 변수로 선언되지 않았기 때문에, 컴파일러는 i 를 알 수 없어서 오류가 발생한다. */
int main() {
    int i;
    printf("마술 상자에 집어넣을 값: ");
    scanf("%d" , &i);

    magicbox();
    printf("마술 상자를 지나면: %d \n", i);
    return 0;
    /* 결과적으로, main() 함수에서는 magicbox() 함수를 호출하지만, magicbox() 함수는 i 를 전역변수로 인식하지 못하기 때문에 오류가 발생한다.
    i 는 main() 함수 내에서만 유효한 변수이므로 magicbox() 함수는 main() 함수 내의 변수를 직접 수정할 수 없다. */
}


/* 함수의 인자 */
#include <stdio.h>
int slave(int master_money) {
    master_money += 10000;
    return master_money;
}
int main() {
    int my_money = 100000;
    printf("2009.12.12 재산: $%d \n", slave(my_money));

    return 0;
}

/* 될까용 */
#include <stdio.h>
int slave(int my_money) {
    my_money += 10000;
    return my_money;
}
int main() {
    int my_money = 100000;
    printf("2009.12.12 재산 : $%d \n", slave(my_money));
    printf("my_money : %d", my_money);

    return 0;
}

/* 생각해보기-문제 */
/* 문제 1 :
이 강좌 최상단에서 이야기했던 마술 상자를 함수로 제작해보세요.
(난이도: 못한다면 강좌를 다시 읽어보아야 할 것입니다.)*/
/* 문제 2: 
어느날 귀족이 돈벌이가 시원치 않아져서 일전에는 일정하게 10000 달러씩 챙겼지만
이제 일정치 않은 수입을 얻게 되었습니다. 여러분은 slace 함수를 인자를 2개를 가져서, 
하나는 현재 귀족의 재산, 다른 하나는 오늘 귀족의 수입을 인자로 전달받는 새로운 함수를 
만들어보세요. (난이도: 하)*/
/* 문제 3:
1 부터 n 까지의 합을 구하는 함수를 작성해보세요. 수학적인 공식을 써도 되지만 for 문으로 
작성하는 것이 연습하는 데에는 도움이 될 듯 합니다. (난이도: 하)*/
/* 문제 4:
N 값을 입력받아서 1 부터 N 까지의 소수의 개수를 출력하는 함수를 제작해보세요. (난이도: 하)*/
/* 문제 5: 
특정한 수 N 을 입력받아서 N 을 소인수분해한 결과가 출력되게 해보세요. (난이도: 중)
(예: factorize(10); 출력결과: 2CE5, factorize(180); 출력결과: 2CE2CE3CE3CE5)*/
/* 문제 6:
int function(int *arg) 와 같은 함수가 무엇을 뜻하는지 생각해보세요. */

/* 앞선 강의에서의 포인터 내용 간단 리뷰 */
/* 포인터는 특정한 변수의 메모리 상의 주소값을 저장하는 변수로, int 형 변수의 주소값을 저장하면 
int*, char 이면 char* 형태로 선언된다. 또한 * 단항 연산자를 이용하여 자신이 가리키는 변수를 지칭
할 수 있으며 & 연산자를 이용하여 특정한 변수의 주소값을 알아낼 수 있다.*/


/* 이상한 짓*/
#include <stdio.h>
int change_val(int i) {
    i = 3;
    return 0;
}
int main() {
    int i = 0;

    printf("호출 이전 i 의 값: %d \n", i);
    change_val(i);
    printf("호출 이후 i 의 값: %d \n", i);

    return 0;
}




















/* 드디어 써먹는 포인터 */
#include <stdio.h>
int change_val(int *pi) { // int 형 변수를 가리키는 pi 라는 이름의 포인터로 인자를 받고 있다.
    printf("----- change_val 함수 안에서-----\n");
    printf("pi 의 값: %p \n", pi);
    printf("pi 가 가리키는 것의 값: %d \n", *pi);

    *pi = 3;

    printf("----- change_val 함수 끝~~ -----\n");
    return 0;
}
int main() {
    int i = 0;    // 

    printf("i 변수의 주소값: %p \n", &i);
    printf("호출 이전 i 의 값: %d \n", i);
    change_val(&i);     // 인자에 main 함수에서 정의된 i 라는 변수의 '주소값'을 인자로 전달하고 있다.
    /* 따라서 change_val 함수를 호출하였을 때 pi 에는 i 의 주소값이 들어가게 된다. 
    즉, pi 는 i 를 가리키게 된다. */
    printf("호출 이후 i 의 값: %d \n", i);

    return 0;
}

/* 두 변수의 값을 교환하는 함수 */
#include <stdio.h>
int swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    return 0;
}

int main() {
    int i, j;

    i = 3;
    j = 5;
    
    printf("SWAP 이전: i : %d, j : %d \n", i, j);

    swap(i, j); // swap 함수 호출~~

    printf("SWAP 이후: i : %d, j : %d \n", i, j);

    return 0;
    // 출력값이 i 는 5, j 는 3 이 나오도록 의도하여 짰지만, 의도대로 잘 되지는 않음.
    // 이럴 때는 아래의 코드처럼 포인터를 사용하기!!
}

/* 올바른 swap 함수(포인터 사용한 수정 코드) */
#include <stdio.h>
int swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;

    return 0;
}
int main() {
    int i, j;

    i = 3;
    j = 5;

    printf("SWAP 이전: i : %d, j : %d \n", i, j);

    swap(&i, &j);  // 호출

    printf("SWAP 이후: i : %d, j : %d \n", i, j);

    return 0;
    /* 해당 코드와 같이 포인터를 사용하면 swap 함수를 제대로 호출하여 출력값을 내는 것이 가능하다!!!*/
}


/* 우리가 여태까지 사용하였던 함수들은 모두 main 함수 위에서 정의되고 있었다.
그러면 그 정의를 main 함수의 아래에서 한다면 어떻게 될까?? 사실, 대부분의 사람들의 경우 main 
함수를 제일 위에 놓고 나머지 함수들은 main 함수 뒤에 정의하게 된다. */

/* 될까?? */
#include <stdio.h>
int main() {
    int i, j;
    i = 3;
    j = 5;
    printf("SWAP 이전: i : %d, j : %d \n", i, j);
    swap(&i, &j);
    printf("SWAP 이후: i : %d, j : %d \n", i, j);

    return 0;
}
int swap(int *a, *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
    
    return 0;
    /* 해당 함수를 출력하면 오류가 발생하게 된다. */
}

/* 함수의 원형 */
#include <stdio.h>
int swap(int *a, int *b); // 이것이 바로 함수의 원형!!!
/* 이는 사실 함수의 정의 부분을 한 번 더 써준 것일 뿐. 
(주의할 점: 함수의 원형에는 정의와는 달리 뒤에 ; 를 붙인다는 것!!)
함수의 원형에 해당하는 이 한 줄은 컴파일러에게 " 이 소스코드에 이러이러한 함수가 
정의되어 있으니까 잘 살펴봐"라는 의미를 전달한다. 
다시 말해, 컴파일러에게 이 소스코드에 사용되는 함수에 대한 정보를 제공한다. 이는 
실제 프로그램에는 전혀 반영되지 않는 정보이다. */
int main() {
    int i, j;
    i = 3;
    j = 5;
    printf("SWAP 이전: i : %d, j : %d \n", i, j);
    swap(&i, &j);
    printf("SWAP 이후: i : %d, j : %d \n", i, j);

    return 0;
}
int swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;

    return 0;
    /* 함수의 원형을 집어넣는 일은 '반드시' 해야 하는 일이다. 물론, main 함수 위에 함수를 정의하면
    상관 없지만 사실 99.9%의 프로그래머들은 함수를 main 함수의 뒤에 정의하고 원형을 앞에 추가하는 
    것을 선호하니, 이러한 트렌드를 따르는 것이 좋다. */
}

/* 배열을 인자로 받기 */
#include <stdio.h>
int add_number(int *parr); // 함수의 원형!!!
int main() {
    int arr[3];
    int i;
    
    /* 사용자로부터 3개의 원소를 입력받는다. */
    for (i = 0; i < 3; i++) { /* i < 3 은 루프가 3번 반복된다는 의미이다.
    i = 0, i = 1, i = 2 이렇게 3번 반복하고, 그 이후에는 루프가 종료된다. */
        scanf("%d", &arr[i]);
    }

    add_number(arr);

    printf("배열의 각 원소: %d, %d, %d", arr[0], arr[1], arr[2]);

    return 0;
}
int add_number(int *parr) {
    int i;
    for (i = 0; i < 3; i++) {
        parr[i]++;
    }
    return 0;
}


/* 입력받은 배열의 10 개의 원소들 중 최대값을 출력 */
#include <stdio.h>
/* max_number: 인자로 전달받은 크기 10 인 배열로부터 최대값을 구하는 함수 */
int max_number(int *parr); // 함수의 원형!!!
int main() {
    int arr[10];
    int i;
    /* 사용자로부터 원소를 입력받는다. */
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("입력한 배열 중 가장 큰 수: %d \n", max_number(arr));
    return 0;
}
int max_number(int *parr) {
    int i;
    int max = parr[0];

    for (i = 1; i < 10; i++) {
        if (parr[i] > max) {
            max = parr[i];
        }
    }

    return max;
    /* 처음 max 에 parr 이 가리키는 배열의 [0], 즉 첫번째 원소의 값을 넣었다. 
    그리고 아래 for 문에서 만약 parr[i] 가 max 보다 크면 max 의 값을 parr[i] 의 값으로 
    대체하고 있다. 
    결과적으로 i 의 값이 9 까지 되었을 때에는 max 에 parr 중 가장 큰 원소의 값이 
    들어가게 된다. 만일, max 보다 더 큰 원소가 parr 에 있다면 max 의 값은 그 큰 
    원소의 값으로 바뀌었기 때문에 모순이다. 
    결과적으로 사용자가 입력한 10 개의 원소들 중 가장 큰 원소가 출력된다. */
}

/* 함수 사용 연습하기 */
/* 함수를 이용하지 않은 버전 */
#include <stdio.h>
int main() {
    char input; // char 을 사용했기 때문에, 내가 십진수로 입력값을 대입하더라도 컴퓨터는 ASCII 코드로 변환하여 이해하고, 자신이 이해한 바를 출력하게 된다. 

    scanf("%c", &input);

    if (48 <= input && input <= 57) {
        printf("%c 는 숫자입니다. \n", input);
    } else {
        printf("%c 는 숫자가 아닙니다. \n", input);
    }

    return 0;
    /* 출력했을 때, 66을 입력하면 6이 출력되는 문제가 발생한다.
    이는 scanf 함수가 한 번에 한 문자만 읽기 때문이다. 따라서 코드를 입력할 때 66을 입력하면
    scanf 는 첫 번째 6만 읽고 나머지 6은 무시하게 된다. */
}

/* 함수 사용 연습하기 */
/* 함수를 이용하지 않은 버전-위의 코드 수정 버전 */
#include <stdio.h>
int main() {
    char input[100]; // 문자열로 입력받기 위해 크기를 충분히 크게 잡음

    scanf("%s", input); // 문자열로 입력받기

    if (48 <= input[0] && input[0] <= 57) { // 첫 번째 문자가 숫자인지 확인
        printf("%c 는 숫자입니다. \n", input[0]);
    } else {
        printf("%c 는 숫자가 아닙니다. \n", input[0]);
    }

    return 0;
}

/* 함수를 이용한 버전 */
#include <stdio.h>
int isdigit(char c); // c 가 숫자인지 아닌지 판별하는 함수
int main() {
    char input;

    scanf("%c", &input);

    if (isdigit(input)) {
        printf("%c 는 숫자입니다. \n", input);
    } else {
        printf("%c 는 숫자가 아닙니다. \n", input);
    }

    return 0;
}
int isdigit(char c) {
    if (48 <= c && c <= 57) { 
        /* if (48 <= c && c <= 57) 조건문은 input 변수에 저장된 ASCII 코드 값이 숫자(0-9)에 해당하는지 확인한다.
        - 48 은 문자 0의 ASCII 코드 값이다.
        - 57은 문자 '9'의 ASCII 코드 값이다.
        따라서 input 값이 48 에서 57 사이에 있다면, 이는 입력된 문자가 0 에서 9 사이 숫자라는 것을 의미한다. */
        return 1;
    } else
        return 0;
}

/* 생각해보기 */
/* 문제 1:
위 10 개의 원소들 중 최대값을 구하는 함수를 이용하여, 10 개의 원소를 입력받고 그 원소를 큰 순으로 
출력하는 함수를 만들어보세요.(난이도: 중) */
/* 문제 2: 
2차원 배열의 각 원소에 1을 더하는 함수의 인자는 어떤 모양일까요?? (난이도: 중하)*/


/* 지난번 내용 요약: "어떠한 함수가 특정한 타입의 변수/배열의 값을 바꾸려면 함수의 인자는 반드시 
타입을 가리키는 포인터 형을 이용해야 한다." */
/* 눈 돌아가는 예제. 포인터가 가리키는 변수를 서로 바꾼다. */
#include <stdio.h>

int pswap(int **pa, int **pb);
int main() {
    int a, b;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf("pa 가 가리키는 변수의 주소값: %p \n", pa);
    printf("pa 의 주소값: %p \n \n", &pa);
    printf("pb 가 가리키는 변수의 주소값: %p \n", pb);
    printf("pb 의 주소값: %p \n", &pb);

    printf(" ---------------------호출-------------------- \n");
    pswap(&pa, &pb);
    printf(" ---------------------호출-------------------- \n");

    printf("pa 가 가리키는 변수의 주소값: %p \n", pa);
    printf("pa 의 주소값: %p \n \n", &pa);
    printf("pb 가 가리키는 변수의 주소값: %p \n", pb);
    printf("pb 의 주소값: %p \n", &pb);
    return 0;
}
int pswap(int **ppa, int **ppb) {
    int *temp = *ppa;

    printf("ppa 가 가리키는 변수의 주소값: %p \n", ppa);
    printf("ppb 가 가리키는 변수의 주소값: %p \n", ppb);
    *ppa = *ppb;
    *ppb = temp;

    return 0;
    /* 결과를 출력하면 두 포인터가 가리키는 변수가 서로 뒤바뀐 것을 확인할 수 있다. */
}

/* 2차원 배열의 각 원소를 1 씩 증가시키는 함수 */
#include <stdio.h>
/* 열의 개수가 2 개인 2차원 배열과, 총 행의 수를 인자로 받는다. */
int addl_element(int (*arr)[2], int row);
int main() {
    int arr[3][2];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    addl_element(arr, 3);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
        }
    }
    return 0;
}
int addl_element(int (*arr)[2], int row) { 
    /* 이 함수는 인자를 두 개 받고 있는데, 하나는 열의 개수가 2 개인 이차원 배열을 가리키는 포인터이고
    나머지 하나는 함수의 행의 수를 받는 인자이다. */
    /* 오직 함수의 인자인 경우에만 한해서, 위 형태의 인자를 다음과 같이 표현하는 것 역시 가능하다.
    int addl_element(int arr[][2], int row)*/
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 2; j++) {
            arr[i][j]++;
            /* 우리는 row 를 통해서 이 이차원배열의 행의 개수를 알 수 있고, 열의 개수는 이미 알고 있으므로 
            (배열 포인터에서) 각 원소를 1씩 증가시키는 작업을 시행할 수 있게 된다. */
        }
    }

    return 0;
}


/* 상수를 인자로 받아들이기 */
#include <stdio.h>
int read_val(const int val);
int main() {
    int a;
    scanf("%d", &a);
    read_val(a);
    return 0;
}
int read_val(const int val) {
    val = 5; // 허용되지 않는다.
    return 0;
    /* 해당 코드를 출력하면 오류가 발생한다. 
    이 오류는 이전에 상수의 값을 변경하려고 했었을 때 만났던 오류와 동일하다. 
    우리가 val 을 const int 로 선언하였기 때문에 함수를 호풀할 떄, val 의 값은
    인자로 전달된 값으로 초기화되고 결코 바뀌지 않는다. 
    즉, val은 a 의 값으로 상수로 초기화된 것이다. 
    따라서 함수 내부에서 val = 5 와 같이 val 의 값을 바꾸려 한다면 오류가 발생한다. (왜냐하면 val 은 상수이기 때문이다.)*/
}


/* 함수 포인터 */
#include <stdio.h>
int max(int a, int b);
int main() {
    int a, b;
    int (*pmax)(int, int); // 함수 포인터 pmax 의 정의!!
    /* pmax 의 정의를 보고 '이 함수 포인터 pmax 는 함수의 리턴값이 int 형이고, 인자 두 개가 각각 int 인 함수를 가리키는구나!!'라는 사실을 알 수 있다. 
    따라서, pmax 함수 포인터로 특정한 함수를 가리킬 때, 그 함수는 반드시 pmax 의 정의와 일치해야 한다. */
    pmax = max; // max 함수를 살펴보면 pmax 의 정의와 일치하므로, max 함수의 시작 주소값을 pmax 에 대입할 수 있게 된다. 이때, 특정한 함수의 시작 주소값을 
    // 알려면 그냥 함수 이름을 넣어주면 된다. 결과적으로 max(a, b) 를 하나 pmax(a, b)를 하나 출력값은 동일하게 나온다. 

    scanf("%d %d", &a, &b);
    printf("max(a, b) : %d \n", max(a, b));
    printf("pamx(a, b) : %d \n", pmax(a, b));

    return 0;
}
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;

    return 0;
}


/* 함수 포인터-2 */
#include <stdio.h>
int max(int a, int b);
int donothing(int c, int k);
int main() {
    int a, b;
    int (*pfunc)(int, int);
    /* 위의 줄은 리턴형이 int 이고 두 개의 인자 각각의 포인터 형이 int 인 함수를 가리킨다. 
    그런데 donothing 함수와 max 함수 모두 이 조건을 만족하고 있다.
    즉, 이들은 인자의 변수들도 다르고 하는 일도 다르지만, 리턴값이 int 로 같고 두 개의 인자 모두 
    int 이므로 pfunc 이 이 두 개의 함수를 가리킬 수 있는 것이다. */
    pfunc = max;

    scanf("%d %d", &a, &b);
    printf("max(a, b) : %d \n", max(a, b));
    printf("pfunc(a, b) : %d \n", pfunc(a, b));

    pfunc = donothing;

    printf("donothing(1, 1) : %d \n", donothing(1, 1));
    printf("pfunc(1, 1) : %d \n", pfunc(1, 1));
    return 0;
}
int max(int a, int b) {
    if (a > b)
        return a;
    else 
        return b;

    return 0;
}
int donothing(int c, int k) { return 1;}

/* 생각해보기 */
/* 문제 1 :
사용자로부터 5 명 학생의 수학, 국어, 영어 점수를 입력받아서 평균이 가장 높은 사람부터 평균이 가장 낮은 
사람까지 정렬되어 출력하도록 하자. 특히, 평균을 기준으로 평균 이상인 사람 옆에는 '합격', 아닌 사람은 
'불합격' 을 출력하게 해보자. (난이도: 중상) */
/* 문제 2: 
유클리드 호제법 이용해서 N 개들의 수들의 최대공약수를 구하는 함수를 만들어보자. 
(유클리드 호제법이 무엇인지 모른다면, 인터넷 검색을 활용하는 것을 추천한다.)
(난이도: 중상)*/
/* 문제 3: 
자기 자신을 호출하는 함수를 이용해서 1부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보자. (난이도: 하)*/
/* 문제 4: 
계산기를 만들어보자. 사용자가 1을 누르면 +, 2를 누르면 - 와 같은 방식으로 해서 
만들면 된다. 물론 이전의 계산 결고는 계속 누적되어야 하고, 지우기 기능도 있어야 한다.
(물론 하나의 함수에 구현하는 것이 아니라 여러 개의 함수로 분할해서 만들어야 한다.)
(난이도: 중)*/
/* 문제 5: 
N 진법에서 M 진법으로 변환하는 프로그램을 만들어보자 (난이도: 중)*/
/* 문제 6:
에라토스테네스의 체를 이용해서 1부터 N 까지의 소수를 구하는 프로그램을 만들어보자. (난이도: 중)*/
/* 문제 7: 
1000 자리의 수들의 덧셈, 뺼셈, 곱셈, 나눗셈을 수행하는 프로그램을 만들어보자. 나눗셈의 경우 소수 부분을 
잘라버리자. 물론, 소수 부분도 1000 자리로 구현해도 된다. 1000 자리 수들의 연산 수행 시간은 1초 미만이어야 한다. 
(난이도: 상) */


/* 다음의 코드를 복사해 넣어보자. */
#include <stdio.h>
int main() {
    char a, b, c;
    a = 100;
    b = 300;
    c = a + b;

    printf("%d + %d = %d \n", a, b, c);
    return 0;
    /* a 는 char 타입으로 100을 저장한다. 
    b 는 char 타입으로 300을 저장한다. 하지만 char 는 8비트이므로, 값이 256을 초과할 경우
    범위를 초과한 값을 가지게 된다. 따라서 b 에 실제 저장되는 값은 300 % 256 = 44 이다.
    c 에는 100 + 44 의 결과인 144가 들어가게 된다. 하지만 144를 char 로 변환하면 144 - 256 = -112
    가 된다. 
    결과적으로 출력값은 100 + 44 = -112 가 된다. */
}


/* 널 뽀개기*/
#include <stdio.h>
int main() {
    char null_1 = '\0'; // 이 3 개는 모두 동일한 의미이다!! 그리고 \0의 아스키 값은 0이다. 
    char null_2 = 0;
    char null_3 = (char)NULL; // 모두 대문자로 써야 하는 것을 주의!!! 그리고 NULL 은 0이라고 정의되어 있는 상수이다!!

    char not_null = '0';

    printf("NULL 의 정수(아스키) 값: %d, %d, %d \n" , null_1, null_2, null_3);
    printf("'0' 의 정수(아스키) 값: %d \n", not_null);  // 문자 '0' 의 아스키 값은 48이ㅏㄷ. 

    return 0;
}


/* 문자열의 시작 */
#include <stdio.h>
int main() {
    char sentence_1[4] = {'P', 's', 'i', '\0'}; // \0 은 널 종료 문자로, 문자열의 끝을 의미한다. 문자열을 올바르게 출력하게 위해서 필요하다. 
    // \0 이라고 쓰는 이유는 '0'이 아스키값인 48을 가지고 있기 때문이다. 
    char sentence_2[4] = {'P', 's', 'i', 0}; // '0' 은 널 종료 문자(= \0)와 동일하게 작동한다.
    char sentence_3[4] = {'P', 's', 'i', (char)NULL}; // (char)NULL 은 '0'과 동일한 역할을 한다. 따라서 널 종료 문자로 사용된다. 
    /* C 에서 NULL 은 포인터 타입에 대한 정의이지만, 이를 (char) 로 캐스팅하면 '0'이 되어 널 종료 문자로 사용된다. */
    char sentence_4[4] = {"Psi"}; // "Psi" 는 문자열 리터럴로, 컴파일러가 자동으로 널 종료 문자를 추가한다. 

    printf("sentence_1 : %s \n", sentence_1); // %s 를 통해서 문자열을 출력한다.
    printf("sentence_2 : %s \n", sentence_2);
    printf("sentence_3 : %s \n", sentence_3);
    printf("sentence_4 : %s \n", sentence_4);

    return 0;
}


/* 포인터 복습 */
#include <stdio.h>
int main() {
    char word[30] = {"long sentence"};
    char *str = word;

    printf("%s \n", str);

    return 0;
    /* 이전에 배운 내용에 따르면 char* 을 이용해서 char 배열을 가리킬 수 있다고 했다. 
    해당 코드는 이를 그대로 적용시킨 것으로, str 이라는 char 을 가리키는 포인터가 배열 
    word 를 가리키고 있다. 따라서, printf("%s \n", str); 에서 str 이 가리키는 것을 
    문자열로 출력(즉, 널이 나올 때까지 출력)해서 다음과 같이 long sentence 가 출력된 것이다. */
}

/* 문자열 바꾸기 */
#include <stdio.h>
int main() {
    char word[] = {"long sentence"}; /* [] 안을 빈칸으로 두었다는 것은 컴파일러가 알아서 원소의 수를 세어서 빈칸을 채워넣으라는 뜻이다. */

    printf("조작 이전: %s \n", word);

    word[0] = 'a';
    word[1] = 'b';
    word[2] = 'c';
    word[3] = 'd';
    /* 위와 같이 word 배열의 첫 4 개의 원소를 각각 a, b, c, d 로 변경하였다. 
    따라서 아래 printf 문에서 long 부분이 abcd 로 변경된 모습을 볼 수 있다. */

    printf("조작 이후: %s \n", word);

    return 0;
}


/* 문자의 개수를 세자 */
/* 나중에 프로그래밍을 하다보면 특정한 문자열에 들어 있는 문자의 개수를 세는 일이 많을 것이다. 
이를 수행하는 함수를 만들어보자.*/
#include <stdio.h>
int str_length(char *str);
int main() {
    char str[] = {"What is your name?"};

    printf("이 문자열의 길이: %d \n", str_length(str));

    return 0;
}
int str_length(char *str) {
    int i = 0;
    while (str[i]) {
        /* while 문의 조건 부분에 있는 str[i] 의 의미는 str[i] 가 0 이 될 때까지 i 의 값을 계속 증가시키겠다는 것이다.
        그런데 문자열에서 str[i] 가 0이 되는 순간은 바로 NULL 문자일 때이다.
        즉, 문자열의 끝 부분에 도달하였을 때 str[i] 가 0이 되는 것이다. 
        따라서 i 에는 맨 마지막의 NULL 문자를 제외한 나머지 문자들의 총 개수가 들어가게 된다. */
        i++;
    }

    return i;
}


/* 문자열 입력 */
#include <stdio.h>
int main() {
    char words[30]; /* 일단 최대 29 글자까지 저장할 수 있는 문자 배열 words 를 생성했다.
    30 글자가 아닌 29 글자까지 저장 가능한 이유는 끝에 '널'이 들어가기 때문이다. */

    printf("30 자 이내의 문자열을 입력해주세요! : ");
    scanf("%s", words);  /* words 앞에 &를 붙이지 않은 이유는 다음과 같다.
    words 라는 배열의 이름 자체가 배열을 가리키고 있는 포인터이기 때문에 words 의 값을 전달함으로써 배열의 (시작) 주소값을 잘 전달하는 것이 가능하다. */

    printf("문자열: %s \n", words);

    return 0;
}

/* 생각해보기- 문제*/
/* 문제 1:
놀랍게도 배열을 할당하지 않고도 다음과 같이 문자열을 지정할 수 있다. 
char *str = "abcdefghi";
printf("%s", str);  // 하면 잘 출력된다.
그렇다면 위 str 과 char c_str[] = {"abcdefghi"}; 의 차이점은 무엇일까요?(난이도: 상)
*/
/* 문제 2:
다음 문장이 왜 성립하지 않는지 생각해보자. (난이도: 중상)
char str_a[] = "abc";
char str_b[] = "abc";

if (str_a == str_b) {
    // 이 부분이 실행되지 않는다. 
}
*/
/* 문제 3: 
(2) 의 답을 얻었다면 두 개의 문자열을 비교하는 함수를 만들어서 같으면 1, 다르면 0 을 리턴하게 해보자.(난이도: 중)*/


/* 버퍼에 대한 이해-이상한 scanf*/
#include <stdio.h>
int main() {
    int num;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    printf("문자를 입력하세요 : ");
    scanf("%c", &c);
    return 0;
    /* 이부분은 중요한 부분!! 근데 하나하나 적기가 번거로우니 교재 284page 를 참고하도록 하자.*/
}


/* 그렇다면 %s 는?? */
#include <stdio.h>
int main() {
    char str[30];
    int i;

    scanf("%d", &i);
    scanf("%s", str);

    printf("str : %s", str);

    return 0;
    /* 결론적으로 요약하자면, %s 나 %d 그리고 다른 모든 수 데이터를 입력받는 형식은 
    버퍼에 신경 쓸 필요없이 자유롭게 사용할 수 있다. 하지만 %c 를 이용할 때에는 버퍼에
    무엇이 남아있는지를 잘 고려해야 한다. */
}



/* 마지막 stdin 예시 */
#include <stdio.h>
int main() {
    char str1[10], str2[10];

    printf("문자열을 입력하세요: ");
    scanf("%s", str1);
    printf("입력한 문자열: %s \n", str1);

    printf("문자열을 입력하세요: ");
    scanf("%s", str2);
    printf("입력한 문자열: %s \n", str2);

    return 0;
    /* scanf 함수는 stbin 으로부터 의미가 있는 문자(공백 문자(' ', '\n', '\t')를 제외한 나머지 문자)
    가 나올 때까지 모든 공백 문자들을 무시한다. 위의 경우, stdin 에서 처음에 공백 문자가 하나도 없으므로
    바로 stdin 으로부터 데이터를 가져올 것이다. 
    데이터를 가져오다가 공백 문자를 만나게 되면 입력을 중지한다. 
    위의 경우 ' '이 공백 문자의 역할을 하기 때문에 str1 에는 hello 까지만 입력이 되고 baby 는 뒤에 입력이 된다.
    그 떄, 처음에 있는 공백 문자인 \n 는 무시하고 넘어간 뒤 마지막의 공백 문자인 \n 을 보고 입력을 중지한다.
    따라서 메모리에는 마지막 공백 문자인 \n 만이 덩그러니 남게 된다. */
}

/* 도대체 이 문제를 어떻게 해결할 것인가?? */
/* 아무리 %c 를 사용하지 않는다고는 해도, 필연적으로 사용할 일이 생길 수밖에 없다.
그렇다면 그때마다 이처럼 버퍼에 \n 이 남아 있는 것을 고려해야할까?? 
이를 해결할 수 있는 방법을 알아보자. */
/* 버퍼 비우기

주의할 점은, 반드시 MS 계여르이 컴파일러로 컴파일 해주어야 한다는 것이다. 
즉, Visual Stdio 계열의 컴파일러로 말이다. (이 말이 무슨 말인지 잘 모르겠으면 그냥 늘
하던대로 하면 된다. )

gcc 에서는 정상적으로 작동되지 않는 위험한 코드이다. */

#include <stdio.h>
int main() {
    int num;
    char c;

    printf("숫자를 입력하세요: ");
    scanf("%d", &num);

    fflush(stdin); /* 해당 문장은 'stdin 을 비워버려라'는 의미이다. 
    다시말해 stdin 에 있는 모든 데이터들을 날려버리게 되는 것이다. 
    따라서 버퍼가 완전히 비워지게 되고, 이것은 버퍼에 남아있던 \n 이 사라지게 되었다는 것을 의미한다. */

    printf("문자를 입력하세요: ");
    scanf("%c", &c);
    /* 위의 ffluch 에 의해서 %c 는 버퍼에 남아있는 것이 아무것도 없게 되므로 
    사용자의 입력을 차분히 기다리고 있게 된다. 
    즉, 우리가 c 에 원하는 값을 넣을 수 있다는 뜻이다. 
    그렇지만 사실 해당 코드는 추천하지 않는다. 왜냐하면 fflush 가 표준으로 '무슨 역할을 한다'고 정해진 것이
    아니기 때문이다. */

    return 0;
}


/* getchar 함수 이용 */
#include <stdio.h>
int main() {
    int num;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num); /* 일단 해당 부분까지만 실행하면 역시 stdin 에는 \n 이 남아있게 된다. (상당히 곤란한 상태)*/

    getchar(); /* getchar 함수의 역할은 'stdin 에서 한 문자를 읽어와서 그 값을 리턴한다'는 의미이다. 
    물론 한 문자를 읽어오면 읽어온 문자는 stdin 에서 사라지게 된다. 
    따라서 우 ㅣ함수를 호출함으로써 \n 을 stdin 에서 읽어와 지워버릴 수 있게 된다. */

    printf("문자를 입력하세요 : ");
    scanf("%c", &c);

    return 0;
    /* getchar 함수를 호출하는 방법은 꽤 자주 쓰이는 방법이다.
    기본적으로 scanf 에서 %c 형식을 사용하는 것을 권하고 싶지는 않지만, 정 사용하고자 한다면 
    getchar() 을 scanf 이전에 호출해서 버퍼를 비워주는 방법을 사용하길 바란다. 
    다만, 해당 방법도 문제가 없는 것은 아니다. 
    만일 버퍼에 한 문자(= \n)만 남겨져 있는 것이 아니면 문제가 발생한다. */
}

/* c 에 무엇이 들어가는지 살짝 보아야 하므로 코드를 약간 수정했다. */
#include <stdio.h>
int main() {
    int num, i;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);

    getchar();

    printf("문자를 입력하세요 : ");
    scanf("%c", &c);

    printf("입력한 문자 : %c", c);
    return 0;
    /* 실행 순서는 다음과 같다. 
    사용자가 123abc 를 치면 버퍼에는 123abc\n 으로 입력된다. 
    그 다음에 scanf 함수가 stdin 에서 차례차례 데이터를 읽어온다. 앞서 말했듯이 데이터를
    읽어올 때 공백문자나 숫자가 아닌 것들을 만나게 되면 stdin 에서부터 그만 읽어오게 된다. 
    이때 a 가 숫자가 아니기 때문에 123까지 읽은 후 stdin 에서부터 그만 읽어온다. 
    따라서 stdin 에는 abc\n 이 남게 된다. getchar()는 a 를 읽어오게 되고, 결과적으로는 bc\n 이 
    남아서 버퍼가 깔끔하게 비워지지 못한 상태가 된다. 
    
    아무튼 여기서 내릴 수 있는 결론은 "되도록이면 %c 를 사용하지 말자" 이다. scanf 에서 %c 를 
    사용하는 것은 정말 권장하고 싶지 않은 일이다. 만일 정말로 문자 하나만을 입력받는 프로그램을 
    만드려면 scanf 에서 %s 형태로 문자열을 입력받은 뒤에 맨 앞의 한 문자만 취하는 식으로 만들면 된다. */
}

/* 생각해보기- 문제*/
/* 문제 1:
키보드로부터 입력을 받는 함수는 scanf 나 getchar 말고도 여러가지가 있다. 이들에 대해 조사해 보는 것이 어떨까??(난이도: 없음) */
/* 문제 2:
화면에 출력하는 함수도 printf 만 있는 것이 아니다. 화면에 출력하는 함수에 대해서 알아보는 것이 어떨까?? (난이도: 없음)*/


/* 문자열 리터럴에 대한 이해 */
/* 문자열*/
#include <stdio.h>
int main() {
    char str[] = "sentence";
    char *pstr = "sentence"; /* pstr 는 char 형을 가리키는 포인터이므로, 원래는 char 형 변수의 주소값이 들어가야 한다.
    그런데 해당 줄은 마치 'sentence' 를 특정한 주소값마냥 사용하고 있다. 
    그러나 알고보면 'sentence' 는 주소값이 맞다. 이건 'sentence' 라는 문자열이 저장된 주소값(=시작 주소값)을 말한다. 
    */

    printf("str : %s \n", str);
    printf("pstr : %s \n", pstr);

    return 0;
}

/* 문자열-sentence의 정체를 파악하기 위한 예시 */
#include <stdio.h>
int main() {
    char str[] = "hello";
    char *pstr = "goodbye";

    str[1] = 'a';
    pstr[1] = 'a'; // 이부분에서 문제 발생한다!!!!!!-> 이부분을 주석 처리한 후 다시 실행해보면 제대로 실행됨을 확인할 수 있다. 

    return 0;
    /* 해당 코드에서는 왜 문제가 발생한 것일까??
    위의 예제에서 pstr 의 값을 읽기 만 했을 때(printf 함수를 값을 읽기만 하지 변경하지 않는다.) 정상적으로 
    실행되었지만 아래에서 pstr[1] = 'a'; 를 통해 pstr 의 값을 변경하였을 때 오류가 출력된 것을 보아 마치 
    상수처럼 컴퓨터에서 값을 변경하도록 허락하지 않는 것 같은 느낌이다. */
}/* */



/* 리터럴(literal) */
/* 프로그래밍 언어에서 리터럴(literal) 이란, 소스 코드 상에서 고정된 값을 가지는 것을 일컫는다. 
특히 C 언어의 경우, 큰 따옴표("") 로 묶인 것들을 문자열 리터럴(string literal) 이라 부른다. 
컴퓨터는 이러한 리터럴들을 따로 모아서 보관한다. 즉, 프로그램을 실행하면 메모리 상의 특별한 곳에 
리터럴 들이 쭈르륵 보관되어 있는 공간이 생긴다는 것이다. 
따라서 char *pstr = "goodbye"; 을 실행하게 되면 컴퓨터는 "goodbye 의 시작 주소값 좀 가져와서 
pstr 에 대입 좀 해라" 라는 의미의 작업을 실행하게 된다. 결과적으로, pstr 은 "goodbye" 라는 리터럴을
가리키고 printf("%s", pstr) 을 했을 때 goodbye 를 성공적으로 출력할 수 있게 되었던 것이다. 

그런데 아까 분명히 리터럴은 소스 코드 상에서 고정된 값을 가지는 것들이라고 말했다. 다시 말해서 실제 프로그램 
실행 중에서도 리터럴의 값은 절대로 변경 되어서는 안된다는 것이다. 따라서 리터럴이 보관되는 곳은 오로지 
읽기만 가능한 곳이 된다. 만일, 이곳을 함부로 변경하려고 하는 시도가 있다면 바로 프로그램이 강제로 종료되게 된다. 

다만 char str[] = "hello"; 라는 코드에서 "hello" 는 리터럴이라고 부르기 애매하다. 
왜냐하면 위 배열의 정의는 사실 컴파일러에서 char str[] = {'h', 'e', 'l', 'l', 'o', '\0'}; 으로 해석된다. 
이는 그냥 str 이라는 배열에 hello 라는 문자열을 복사하게 될 뿐이다. 그리고 위 배열은 텍스트 새그먼트가 아니라 
스택(stack) 이라는 메모리 수정이 가능한 영역에 정의가 된다. 
따라서 str 안의 문자열은 수정이 가능하다. */


/* 문자열 다시 가지고 놀기 */
/* C 언어에서 문자열을 다루는 일은 생각보다 불편한 편이다. 예를 들어서 int 형 변수의 경우
int i, j = 0;
i = j + 3;
과 같이 값을 더하는 것이 가능하지만 문자열의 경우 (아래와 같이) 더하는 것이 어렵다.  
char str1[] = {"abc"};
char str2[] = {"def"};
str1 = str1 + str2;
를 한다고 해서 str1 이 "abcedf" 가 되는 것은 절대로 아니다. str1 + str2 는 각 배열의 주소값을
더하는 것인데, 이전에도 말했듯이 배열의 이름은 포인터 상수이기 때문에 대입 연산을 수행하게 될 시, 
오류가 나게 된다. 
뿐만 아니라, 다음과 같이 문자열을 비교하는 것 역시 불가능하다. 
if (str1 == str2) '''
왜냐하면 위 문장의 의미는 "'str1' 의 문자열이 들어있는 메모리 상의 (시작) 주소와 
'str2' 의 문자열이 들어있는 메모리 상의 (시작) 주소값을 비교해라" 라는 의미의 문장이기 때문입니다. 따라서 
역시 우리가 원하던 기능이 실행 될 수가 없습니다. 물론 다음과 같은 문장도 원하는 대로 실행이 되지 않습니다. */

/* 일단, 위에서 지적한 내용을 바탕으로 문자열을 자유롭게 다루려면 다음과 같은 함수들이 필요하다.
-문자열 내의 총 문자의 수를 세는 함수
-문자열을 합치는 함수(즉 더하는)
-문자열을 복사하는 함수
-문자열을 비교하는 함수
*/

/* 문자열을 복사하는 함수 */
/* 문자열을 복사하는 함수는 어떻게 하면 만들 수 있을까?? 무언가를 작업하는 함수를 
만들기 전에 반드시 고려해야 하는 사항들은 다음과 같다.
1. 이 함수는 무슨 작업을 하는가??(자세할수록 좋다.)
2. 함수의 리턴형이 무엇이면 좋을까??
3. 함수의 인자로는 무엇을 받아야 하는가?? */

/* 
int copy_str(char *dest, char *src);
src 의 문자열을 dest 로 복사한다. 단, dest 의 크기가 반드시 src 보다 커야 한다.
*/
int copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++; // 그 다음 문자를 가리킨다. 
        dest++;
    }
    *dest = '\0';

    return 1;
}


/* copy_str 사용 예제 */
#include <stdio.h>
int copy_str(char *src, char *dest);
int main() {
    char str1[] = "hello";
    char str2[] = "hi";

    printf("복사 이전: %s \n", str1);

    copy_str(str1, str2);

    printf("복사 이후: %s \n", str1);

    return 0;
}
int copy_str(char *dest, char *src) {
    while (*src) { /* while 문의 조건이 *src 이다. 
    해당 방법은 문자열을 다룰 때 많이 쓰는 방법인데, NULL 문자의 값이 0이므로 *src 가 NULL 문자에 
    도달하기 전까지 while 문이 계속 돌아가게 된다. 
    */
        *dest = *src; /* *dest = *src 를 통해서 src 의 문자를 dest 에 대입하였다.
        그리고 src 와 dest 를 각각 1 씩 증가시켰는데, 포인터의 연산과 마찬가지로 
        단순히 주소값이 1이 늘어나는 것이 아니라, 포인터가 가리키는 타입의 비트 크기를 
        곱한 만큼 증가한다. 
        다시말해, 배열의 그 다음 원소를 가리킬 수 있다는 것이다. */
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}


/* 문자열을 합치는 함수 */
/* stradd 함수 

dest 에 src 문자열을 끝에 붙인다. 
이때 dest 문자의 크기를 검사하지 않으므로 src 가 들어갈 수 있는 충분한 크기가
있어야 한다. 
*/
#include <stdio.h>
int stradd(char *dest, char *src);
int main() {
    char str1[100] = "hello my name is ";
    char str2[] = "Psi";

    printf("합치기 이전: %s \n", str1);

    stradd(str1, str2);

    printf("합친 이후: %s \n", str1);

    return 0;
}

int stradd(char *dest, char *src) {
    /* dest 의 끝부분을 찾는다. -> 이유: dest 의 끝에 문자열을 덧붙이기 우해서는 먼저 dest 문자열의 끝 부분을 찾아야하기 때문이다. */
    while (*dest) {
        dest++;
    }
    /* while 문을 지나고 나면 dest 는 dest 문자열의 NULL 문자를 가리키고 있게 된다. 
    이제 src 의 문자열들을 dest 의 NULL 문자 있는 곳부터 복사해넣는다. */
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    /* 마지막으로 dest 에 NULL 추가 (왜냐하면 src 에서 NULL 이 추가되지 않았으므로) */
    *dest = '\0';

    return 1;
}


/* 문자열을 비교하는 함수 */
#include <stdio.h>
int compare(char *str1, char *str2);
int main() {
    char str[20] = "hello every1";
    char str2[20] = "hello everyone";
    char str3[20] = "hello every1 hi";
    char str4[20] = "hello every1";

    if (compare(str, str2)) {
        printf("%s 와 %s 는 같다. \n", str, str2);
    } else {
        printf("%s 와 %s 는 다르다. \n" , str, str2);
    }

    if (compare(str, str3)) {
        printf("%s 와 %s 는 같다. \n", str, str3);
    } else {
        printf("%s 와 %s 는 다르다. \n", str, str3);
    }

    if (compare(str, str4)) {
        printf("%s 와 %s 는 같다. \n", str, str4);
    } else {
        printf("%s 와 %s 는 다르다. \n", str, str4);
    }

    return 0;
}

int compare(char *str1, char *str2) { 
    /* 일단 while 문에서 str1 의 끝에 도달할때까지 각 문자들을 비교한다. 
    만일 한 문자라도 다르다면 if 문에 의해 0 이 리턴되고 함수는 종료된다.
    그렇지 않다면 while 문을 끝까지 통과하게 된다. */
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1; /* 만일, str1 은 "abc" 이지만 str2 는 "abcd" 처럼 
    부분만 일치한다면 문제가 발생하게 된다. 따라서 str1 이 끝났을 때 str2 도 끝났는지 
    확인을 하기 위한 코드가 해당 줄이다. 
    위의 문장을 추가시킴으로써 사용자는 str2 가 끝이 났는지를 확인할 수 있게 된다. 
    만일 *str2 가 \0 이 아니라면 str1 과 str2 는 다른 것이 되므로 함수는 0을 리턴하게 된다. */

    return 0;
}


/* 생각해보기-문제 */
/* 문제 1: 
길이가 최대 100 인 문자열을 하나 입력받아서 문자열을 역순으로 출력하는 함수를 만들어보세요. (난이도: 하)
예를 들어서 "abcde" 입력 -> "edcba" 출력 */
/* 문제 2: 
길이가 최대 100 인 문자열을 입력받아서 소문자는 대문자로, 대문자는 소문자로 출력하는 함수를 만들어보세요. (난이도: 하)
예를 들어서 "aBcDE" 입력 -> "AbCde" 출력 */
/* 문제 3: 
두 개의 문자열을 입력받아서 같다면 "같다", 다르면 "다르다" 라고 출력하는 함수를 만들어보세요. (난이도: 하) */
/* 문제 4:
문자열을 두 개 입력받아서 먼저 입력받은 문자열에서 나중에 입력받은 문자열의 위치를 검색하는 함수를 만들어보세요. 
만일 없다면 -1 을 리턴하고, 있다면 그 위치를 리턴합니다. (난이도: 중)
예를 들어, 먼저 입력한 것이 I_am_a_boy 이고, 나중에 입력한 것이 am 이었다면 컴퓨터는 I_am_a_boy 에서 am 의 위치를 
찾는다. 이 경우에는 am 의 위치는 2(처음에서 세번째) 이므로 2 를 리턴한다. 만일 am 이라는 문자열이 없다면 -1 을 리턴한다. */
/* 문제 5: 
도서 관리 프로그램을 만들어봅시다. 프로그램에는 다음과 같은 기능들이 구현되어 있어야 합니다. (난이도: 상)
1) 책을 새로 추가하는 기능 (책의 총 개수는 100 권이라 하자. 이때, 각 책의 정보는 제목, 저자의 이름, 출판사로 한다.)
2) 책의 제목을 검색하면 그 책의 정보가 나와야 한다.
3) 위와 마찬가지로 저자, 출판사 검색 기능이 있어야 한다.
4) 책을 빌리는 기능
5) 책을 반납하는 기능
*/


/* 도서검색 프로그램 */
/* 프로그램의 기본 뼈대 */
#include <stdio.h>
int add_book(char (*book_name)[30], char (*auth_name)[30], 
        char (*publ_name)[30], int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30], 
        char (*publ_name)[30], int num_total_book);

int compare(char *str1, char *str2);
int borrow_book(int *borrowed);
int return_book(int *borrowed);



int main() {
    int user_choice; /* 유저가 선택한 메뉴 */
    while (1) { /* while 문의 조건이 1이라는 의미. 이는 while 문의 조건이 언제나 참이라는 것을 의미한다. 
    따라서 이 while 문은 우리가 break 를 하지 않는 한 무한히 반복되게 된다. */
        printf("도서 관리 프로그램\n");
        printf("메뉴를 선택하세요\n");
        printf("1. 책을 새로 추가하기\n");
        printf("2. 책을 검색하기\n");
        printf("3. 책을 빌리기\n");
        printf("4. 책을 반납하기\n");
        printf("5. 프로그램 종료\n");

        printf("당신의 선택은: ");
        scanf("%d", &user_choice);
        if (user_choice == 1) {
            /* 책을 새로 추가하는 함수 호출 */
        } else if (user_choice == 2) {
            /* 책을 검색하는 함수 호출 */
        } else if (user_choice == 3) {
            /* 책을 빌리는 함수 호출 */
        } else if (user_choice == 4) {
            /* 책을 반납하는 함수 호출 */
        } else if (user_choice == 5) {
            /* 프로그램을 종료한다. */
            break;
        }
    } 

    return 0;
}


/* 1번- 책을 주가하는 함수 */
int add_book(char (*book_name)[30], char (*auth_name)[30], 
char (*publ_name)[30], int *borrowed, int *num_total_book) {
    printf("추가할 책의 제목: ");
    scanf("%s", book_name[*num_total_book]);

    printf("추가할 책의 저자: ");
    scanf("%s", auth_name[*num_total_book]);

    printf("추가할 책의 출판사: ");
    scanf("%s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0; /* 빌려지지 않음 */
    printf("추가 완료!! \n");
    (*num_total_book)++;

    return 0;

}

/* 2번- 책을 검색하는 함수 */
int search_book(char (*book_name)[30], char (*auth_name)[30], 
        char (*publ_name)[30], int num_total_book) {
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30];

    printf("어느 것으로 검색할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 지은이 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf("%d", &user_input);

    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);

    printf("검색 결과 \n");

    if (user_input == 1) {
        /* */
        for (i = 0; i < num_total_book; i++) {
            if (compare(book_name[i], user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이: %s // 출판사 : %s \n", i, 
                book_name[i], auth_name[i], publ_name[i]);
            }
        }
    } else if (user_input == 2) {
        /* */
        for (i = 0; i < num_total_book; i++) {
            if (compare(auth_name[i], user_search)) {
                printf("번호 : %d // 책 이름 : %s // 출판사 : %s \n", i, 
                book_name[i], auth_name[i], publ_name[i]);
            }
        } 
    } else if (user_input == 3) {
        /* */
        for (i = 0; i < num_total_book; i++) {
            if (compare(publ_name[i], user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, 
                book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }

    return 0;
}
int compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1;

    return 0;
}


/* 3번- 책을 빌리는 함수 */
int borrow_book(int *borrowed) {
    /* 사용자로부터 책번호를 받을 변수 */
    int book_num;

    printf("빌릴 책의 번호를 말해주세요\n");
    printf("책 번호: ");
    scanf("%d", &book_num);

    if (borrowed[book_num] == 1) {
        printf("이미 대출된 책입니다. \n");
    } else {
        printf("책이 성공적으로 대출되었습니다. \n");
        borrowed[book_num] = 1;
    }

    return 0;
}


/* 4번- 책을 반납하는 함수 */
int return_book(int *borrowed) {
    /* 반납할 책의 번호 */
    int num_book;

    printf("반납할 책의 번호를 써주세요. \n");
    printf("책 번호: ");
    scanf("%d", &num_book);

    if (borrowed[num_book] == 0) {
        printf("이미 반납되어 있는 상태입니다.\n");
    } else {
        borrowed[num_book] = 0;
        printf("성공적으로 반납되었습니다. \n");
    }

    return 0;
}


/* 생각해보기- 문제 */
/* 문제 1: 
위 프로그램(= 도서검색 프로그램)을 다 지우고 다시 말들어보자. 물론 소스가 정확히 일치하지 않아도 된다. 
기능만 통일하면 된다. (난이도: 하) */
/* 문제 2: 
search_book 함수는 살짝 지저분한 편이다. 다른 함수를 제작하여 조금 간추릴 수 있겠는가??
(난이도: 중하) */
/* 문제 3: 
search_book 함수를 조금 개량하여 빌려진 책은 검색결과 출력되지 않게 하거나, "대출됨" 이라는 문구가 출력되게 해보자.
(난이도: 하) */
/* 문제 4: 
search_book 함수를 개량하여 특정한 검색어를 입력했을 때 그 검색어를 포함하는 문자열도 검색되게 해보자. (난이도: 중)
예를 들어, 책 제목이 "leanCfast", "learningC", "whatisC?" 일 때, learn 를 검색하면 "learnCfast"와 "learningC" 가 나온다.
왜냐하면 이들은 모두 "learn" 이라는 문자열을 포함하고 있기 때문이다.  */



/* 구조체(struct) 의 도입 */
#include <stdio.h>
struct Human { // 구조체의 이름: Human
    int age;  /* 나이 */
    int height; /* 키 */
    int weight;  /* 몸무게 */
};  /* ; 를 붙이는 걸 주의하자!!!*/
int main() {
    struct Human Psi;

    Psi.age = 99;
    Psi.height = 185;
    Psi.weight = 80;

    printf("Psi 에 대한 정보 \n");
    printf("나이   : %d \n", Psi.age);
    printf("키   : %d \n", Psi.height);
    printf("몸무게   : %d \n", Psi.weight);
    return 0;
    /* 구조체는 "각 원소의 타입이 제각각인 배열" 이다. 따라서 배열에서는 배열의 타입만으로도 모든 
    원소의 타입을 알 수 있었지만(타입을 동일하게 통일해서 가지기 때문.) 구조체는 그렇지 않다.
    그러므로 구조체는 정의할 때 해당 코드처럼 모든 원소의 타입을 명시해 주어야 한다. */

    /* Human 이라는 이름의 구조체는 3 개의 멤버를 가지고 있는데 (보통 구조체에서는 원소보다는 
    멤버(member) 라고 부른다.) 각각의 멤버는 int age, int height, int weight 로 3 개가 있다. */
}


/* 구조체 예제 2 */
#include <stdio.h>
char copy_str(char *dest, const char *src); /* copy_str 함수는 문자열을 src 에서 dest 로 복사하는 함수이다. 
이처럼 이미 썼던 것을 활용하는 것은 상당히 시간도 절약되고 편리한 방법 중 하나이다. */
struct Books { // 구조체 이름: Book
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 빌려졌는지?? */
    int borrowed;
};
int main() {
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry_Potter");
    copy_str(Harry_Potter.auth, "J.K.Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;

    printf("책 이름: %s \n", Harry_Potter.name);
    printf("저자 이름: %s \n", Harry_Potter.auth);
    printf("출판사 이름: %s \n", Harry_Potter.publ);

    return 0;
}
char copy_str(char *dest, const char *src) { /* 해당 copy_str 함수는 src 문자열을 dest 로 복사한다. 
src 와 dest 는 각각 원본 문자열과 복사할 목적지 문자열을 가리키는 포인터이다. 
while (*src) 루프는 src 가 NULL 문자를 만날 때까지 실행된다. 
*dest = *src; 는 src 가 가리키는 문자를 dest 가 가리키는 위치에 복사한다. 
src++ 과 dest++ 는 각각 src 와 dest 포인터를 다음 위치로 이동시킨다. 
*dest = '\0'; 는 dest 문자열의 끝에 NULL 문자를 추가하여 문자열을 종료한다.
함수는 1 을 반환하지만, 반환 값은 사용되지 않는다. */

/* <반환 값을 사용하지 않는 이유>
1) 함수가 부수 효과(side effect) 로 필요한 작업을 완료할 때
2) 반환 값이 중요한 의미를 가지지 않을 때
3) 함수가 단순히 작업을 완료했음을 나타내기 위해 값을 반환할 때*/
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

    return 1;
}


/* 구조체 예제- 3 */
#include <stdio.h>
struct Books {
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* */
    char publ[30];
    /* */
    int borrowed;
};
int main() {
    struct Books book_list[3];  /* int arr[3] 에서 int 가 하나의 타입이듯이, struct Books 역시 하나의 타입으로 생각하면 된다. 
    int arr[3] 을 하면 arr 에 int 형 원소가 3 개 만들어지듯이, book_list 배열에는 struct Books 형의 변수가 3 개 만들어지는 것이다. */
    int i;

    for (i = 0; i <3; i++) { /* 해당 for 문으 살펴보면 scanf 함수로 book_list 의 i 원소의 name, auth, publ 멤버에 문자열을 
    입력받고 있는 모습을 볼 수 있다. 또한, borrowed 의 값을 0으로 초기화해주고 있다. */
        printf("책 %d 정보 입력 : ", i);
        scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
        book_list[i].borrowed = 0;
        /* 입력을 다 받고 나면 for 문에서 book_list 의 각 원소의 멤버들을 출력해준다. 특히 borrowed 값이 0이면 "안빌려짐", 
        0이 아니면 "빌려짐"이 출력되는데, 위의 경우 0 으로 값을 설정해놓고 이 값을 바꾸는 부분이 없기 때문에 
        언제나 "안빌려짐" 이 출력된다. */
    }

    for (i = 0; i <3; i++) {
        printf("------------------------ \n");
        printf("책 %s 의 정보 \n", book_list[i].name);
        printf("저자 : %s \n", book_list[i].auth);
        printf("출판사 : %s \n", book_list[i].publ);

        if (book_list[i].borrowed == 0) {
            printf("안 빌려짐\n");
        } else {
            printf("빌려짐\n");
        }
    }
    return 0;
}


/* 구조체 포인터 */
/* struct test 역시 하나의 형(타입) 이다. 위 예제들의 struct Human 이나 struct Book 역시 하나의 타입이었다.
즉, 구조체는 한 개의 타입을 창조하는 것과 마찬가지이다. 마치 int 나 char 처럼 말이다. 그런데 이러한 타입들을 가리킬 
때 포인터를 어떻게 사용하였는가?? 바로, int * 나 char * 로 사용했다.
구조체의 포인터도 마찬가지의 형태를 띤다. */
#include <stdio.h>
struct test {
    int a, b;
};
int main() {
    struct test st; // 구조체 포인터
    struct test *ptr; // 구조체 포인터 --> struct test 형을 가리키는 포인터 ptr 을 정의했다. 
    /* 주의해야 할 점: ptr 은 구조체 포인터이지, 절대로 '구조체'가 아니다. ptr 역시 다른 모든 포인터와 동일하게 4 바이트의 공간을 차지한다. */

    ptr = &st; // ptr 에 str 의 주소값을 집어넣는다. --> 이를 통해서 ptr 은 구조체 st 를 가리키는 포인터가 된다. 

    /* ptr 이 가리키는 구조체의 멤버의 값을 변경하는 부분 */
    (*ptr).a = 1; /* (*ptr) 은 st 라는 것과 동일하다. --> 왜냐하면 ptr 이 st 를 가리키고 있기 때문이다. 
    따라서, (*ptr).a = 1; 은 st.a = 1 과 완전히 100% 동일한 문장임을 알 수 있다. (아랫줄 역시 동일하다.)
    결과적으로 아래 printf 문에서 st.a 의 값은 1, st.b 의 값은 2가 출력된 것이다.  */
    (*ptr).b = 2;
    /* 구조체 포인터를 사용해서 멤버에 접근하기 위해서는 (*ptr).a 와 같이 언제나 괄호로 감싸주어야 한다. 
    *ptr.a 는 *(ptr.a) 와 동일한 문장으로 취급되기 때문이다. 
    (. 이 * 보다 우선순위가 높기 때문에 발생하는 문제이다) */

    printf("st 의 a 멤버 : %d \n", st.a);
    printf("st 의 b 멤버 : %d \n", st.b);

    return 0;
}


/* 구조체 포인터-2 */
#include <stdio.h>
struct test {
    int a, b;
};
int main() {
    struct test st;
    struct test *ptr;
    ptr = &st;
    ptr->a = 1;  /* 앞선 코드에서 등장했던 (*ptr).a = 1; 이라는 문장을 ptr->a = 1; 로 간단히 표현하는 것이 가능하다.
    해당 기호(->) 는 단순히 사용자의 편의를 위해서 도입된 것이다. */
    ptr->b = 2;

    printf("st 의 a 멤버 : %d \n", st.a);
    printf("st 의 b 멤버 : %d \n", st.b);
    return 0;
}

/* 생각해보기- 문제 */
/* 문제 1: 
구조체 안에 또다른 구조체 변수를 설정할 수 있을까?? (난이도: 중) */
/* 문제 2: 
구조체를 인자로 가지는 함수를 생각해보기 (난이도: 중) */


/* 구조체 포인터 연습하기-포인터 갖고 놀기 */
#include <stdio.h>
struct TEST {
    int c;
};
int main() {
    struct TEST t;
    struct TEST *pt = &t;
    /* struct TEST 형의 구조체 변수 t 와 struct TEST 형을 가리키는 포인터 pt 를 선언하였다. 
    다시 강조하지만, 우리가 int, char 로 생각하는 것처럼 struct TEST 도 우리가 창조해낸 하나의 타입이며
    이를 가리키는 포인터 역시 다른 모든 포인터와 같은 크기(4비트)라는 것이다. 
    즉, pt 는 절대로 구조체가 아니며, pt 는 단순히 구조체 변수 t 가 저장되어 있는 메모리 공간의 주소값을 보관하고 있을 뿐이다. 
    pt 는 t 의 주소값을 가지고 있으므로 pt 는 t 를 가리키게 된다. (이는 우리가 pt 를 가지고 t 의 값을 마음대로 조작할 수 있다는 것을 의미한다.) */

    /* pt 가 가리키는 구조체 변수의 c 멤버의 값을 0 으로 한다. */
    (*pt).c = 0; // (*pt).c 는 t 의 멤버 c 를 의미한다. 
    printf("t.c : %d \n", t.c);

    /* pt 가 가리키는 구조체 변수의 c 멤버의 값을 1 으로 한다. */
    pt->c = 1; // (*pt).c = 1; 과 동일한 의미이지만, 더 편리하게 사용할 수 있다!!--> 이를 통해서 t 의 멤버 c 의 값을 1 로 바꾸는 것이 가능하다. 

    printf("t.c : %d \n", t.c);

    return 0;
}


/* 헷갈림 */
#include <stdio.h>
struct TEST {
    int c;
    int *pointer;
};
int main() {
    struct TEST t;
    struct TEST *pt = &t;
    /* 앞선 코드와 마찬가지로 pt 는 t 를 가리키게 된다. */
    int i = 0;

    /* t 의 멤버 pointer 는 i 를 가리키게 된다. 이는 t 의 pointer 라는 멤버에 i 의 주소값이 들어간다는 의미이다. 
    따라서 pointer 는 i 를 가리키게 된다. */
    t.pointer = &i;

    /* t 의 멤버 pointer 가 가리키는 변수의 값을 3 으로 만든다. 이때, 우선순위를 고려하면 . 가 * 보다 높으므로 t.pointer 가 먼저 해석되고
    그 다음에 *(t.pointer) 형태로 해석되게 된다. 따라서, *t.pointer 를 통해 구조체 변수 t 의 pointer 멤버가 가리키는 변수를 지칭할 수 있게 된다. */
    *t.pointer = 3;

    printf("i : %d \n", i);

    /*
    -> 가 * 보다 우선순위가 높으므로 먼저 해석하게 된다. 
    *(pt->pointer) 와 *pt->pointer 가 동일한 의미임을 알 수 있다.  
    즉, (pt 가 가리키는 구조체 변수의 pointer 멤버) 가 가리키는 변수의 값을 4로 바꾼다, 
    라는 뜻이다.
    pt->pointer 를 통해 "pt 가 가리키는 구조체 변수의 pointer 멤버", 즉 t.pointer 을 의미하고 *(pt->pointer) = 4 를 
    통해 pointer 가 가리키는  변수의 값을 4로 바꿀 수 있게 된다. 
    */
   *pt->pointer = 4;

   printf("i : %d \n", i);
   return 0;
   /* 해당 코드를 출력하면 
   i : 3
   i : 4
    라는 결과를 볼 수 있다. */
}


/* 구조체 포인터 연습 */
#include <stdio.h>
int add_one(int *a);
struct TEST {
    int c;
};
int main() {
    struct TEST t;
    struct TEST *pt = &t;

    /* pt 가 가리키는 구조체 변수(t)의 c 멤버의 값을 0 으로 한다. */
    pt->c = 0;

    /* add_one 함수의 인자에 t 가 가리키는 구조체 변수의 멤버 c 의 주소값을 전달하고 있다. */
    add_one(&t.c);

    printf("t.c : %d \n", t.c);

    /* add_one 함수의 인자에 pt 가 가리키는 구조체 변수의 멤버 c 의 주소값을 전달하고 있다. */
    add_one(&pt->c);

    printf("t.c : %d \n", t.c);

    return 0;
}
int add_one(int *a) {
    *a += 1;
    return 0;
}



/* 구조체의 대입 */
/* 구조체의 복사는 상당히 단순한 내용이다. 바로, 구조체도 보통의 변수들과 같이 = 를 사용할 수 있다는 것이다. 
(= 는 대입 연산자이다. )*/
#include <stdio.h>
struct TEST { /* 멤버가 i 와 c 인 struct TEST 를 정의하였고,
아래에는 이 구조체의 변수인 st 와 st2 를 정의하였다. */
    int i;
    char c;
};
int main() {
    struct TEST st, st2;

    st.i = 1; /* st 의 각 멤버에 1 과 'c' 를 넣었다. */
    st.c = 'c';

    st2 = st; /* st를 st2 에 대입하였다. 
    우리가 변수 i 를 j 에 대입하면 i 의 값이 j 에 그대로 복사되듯이, 
    st2 의 멤버 i 의 값은 st 의 멤버 i 의 값과 같아지고, 
    st2 의 멤버 c 의 값은 st 의 멤버 c 의 값과 동일해졌다. */

    printf("st2.i : %d \n", st2.i);
    printf("st2.c : %c \n", st2.c);

    return 0;
}


/* 구조체의 대입-2 */
#include <stdio.h>
char copy_str(char *dest, char *src);
struct TEST { 
    /* struct TEST 를 정의하고, int i 와 char str[20] 을 멤버로 가지고 있다. */
    int i;
    char str[20];
};
int main() {
    struct TEST a, b; /* 구조체를 정의한 뒤, 각각의 멤버를 초기화한다. 
    a 는 int i, b 는 char str[20] 에 해당하는 것 같다.(그냥 내 가정. 완전히 같다는 것은 아니고 그냥 대응된다는 의미이다.) */

    b.i = 3;
    copy_str(b.str, "hello, world");
    a = b; /* b 구조체를 a 구조체에 대입하였다. 
    따라서, b 구조체의 모든 멤버의 데이터가 a 구조체에 일대일로 대응이 되어 값이 복사된다. 
    즉 i 는 i 끼리, str 은 str 의 각 원소끼리 쭈르륵 복사가 된다. 
    결과적으로 각각의 멤버의 값을 출력해보면 동일하게 출력된다. */

    printf("a.str : %s \n", a.str);
    printf("a.i : %d \n", a.i);

    return 0;
}
char copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}


/* 구조체를 인자로 전달하기 */
#include <stdio.h>
struct TEST {
    int age;
    int gender;
};
int set_human(struct TEST a, int age, int gender);
int main() {
    struct TEST human;
    set_human(human, 10, 1);
    printf("AGE : %d // Gender : %d ", human.age, human.gender);
    return 0;
}
int set_human(struct TEST a, int age, int gender) {
    a.age = age;
    a.gender = gender;
    return 0;
    /* 해당 코드를 성공적으로 컴파일하였다면, debug error 를 확인할 수 있다!!
    (에러가 발생하는 코드!!)
    에러 이유: '특정한 변수의 값을 다른 함수를 통해 바꾸려면 변수의 주소값을 전달해야 한다.'라는 룰을 지키지 않았기 때문이다. 
    다시말해 해당 코드에서 a.age = age; 를 했을 때 age 의 값이 바뀌는 것은 실제 main 함수에서의 human 이 아니라 set>human 함수의 a 
    라는 human 과 별개의 구조체변수의 age 멤버의 값이 바뀌게 되는 것이다. 
    
    이러한 문제점을 해결하기 위해서는 역시 human 구조체 변수의 주소값을 인자로 받는 함수를 만들어야 한다. 
    (human 구조체 변수의 주소값을 인자로 받는 함수는 아래의 코드이다.) */
}


/* 인자로 제대로 전달하기-human 구조체 변수의 주소값을 인자로 받는 함수 */
#include <stdio.h>
struct TEST {
    int age;
    int gender;
};
int set_human(struct TEST *a, int age, int gender); /* 해당 set_human 함수는 이전 예제에서의 set_human 함수와는 달리
구조체의 포인터를 인자로 취하고 있다. (*a 를 말하는 듯..??) */
int main() {
    struct TEST human;

    set_human(&human, 10, 1); /* 그러므로 set_human 함수를 호출할 때에도 human의 주소값을 인자로 전달하고 있다. (&human 을 말하는 듯...??)
    (주의할 점은 a 는 절대로 구조체 변수가 아니라는 점이다. a 는 단순히 human 구조체 변수가 메모리 상에 위치한 곳의 시작 지점의 주소값을 보관하고 있을 뿐이다. )*/

    printf("AGE : %d // Gender : %d ", human.age, human.gender);
    return 0;
}
int set_human(struct TEST *a, int age, int gender) {
    a->age = age; /* a-> 를 통해서 a 가 가리키고 있는 구조체 변수의 멤버, 즉 위의 경우에서는 human 의 멤버를 지칭할 수 있게 된다. 
    따라서 a->age = age; 를 하게 되면 human 의 age 멤버의 값이 바뀌게 된다. 
    주의할 점은 a->age 와 age 는 다르다는 것이다. a->age 는 human 구조체 변수의 int 형 멤버 age 를 지칭하는 것이고, age 는 단순히 
    set_human 함수에서 인자로 받아들여진 int 형의 age 라는 변수를 가리키는 말이다.(따라서 이 둘은 완전히 다른 것이고, 실제로 컴퓨터 내부에서도 
    다르게 처리된다.)*/
    a->gender = gender;

    return 0;
}


/* 살짝 업그레이드 */
#include <stdio.h>
struct TEST {
    int age;
    int gender;
    char name[20]; /* name[20] 이라는 멤버를 새로 추가해주었다. */
};
int set_human(struct TEST *a, int age, int gender, const char *name); /* set_human 함수에서 name 멤버 역시 함께 초기화해주기 위해
인자로 char * 형의 name 이라는 인자를 추가로 받게 된다. */
char copy_str(char *dest, const char *src);

int main() {
    struct TEST human;

    set_human(&human, 10, 1, "Lee");

    printf("AGE : %d // Gender : %d // Name : %s \n", human.age, 
        human.gender, human.name);
    return 0;
}
int set_human(struct TEST *a, int age, int gender, const char *name) {
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);

    return 0;
}
char copy_str(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1; /* 해당 함수가 문자열 복사를 성공적으로 완료했음을 나타내기 위해서 return 1; 을 사용하는 것이다. 
    사실 해당 코드에서는 함수의 반환값이 실제로 사용되지 않기 때문에, 1 을 반환하든 0 을 반환하든 큰 차이는 없이 
    다 정상적으로 출력하는 것이 가능하다. */
}


/* 생각해보기- 문제 */
/* 문제 1: 
(이전에 만든) 도서 관리 프로그램을 만들되, 구조체를 이용하여 보자. 또한 register_book 과 같은 함수를 이용하여 책을 등록해보자. */
/* 문제 2: 
큰 수를 다루는 구조체를 생각해보자. 그 구조체의 이름은 BigNum 입니다. BigNum 구조체에는 
다음과 같은 멤버들이 있을 수 있습니다.
struct BigNum {
    int i_digit[100];  // 정수 부분
    int d_digit[100];   // 소수 부분
    int i_total_digit;  // 전체 사용되고 있는 정수부분 자리수
    int d_total_digit;  // 전체 사용되고 있는 소수부분 자리수
    char sign;   // 부호, 0 이면 양수, 1 이면 음수, 0 은 양수로 간주한다. 
};
- 이 때, BigNum 구조체의 변수들의 덧셈, 뺄셈을 수행하는 함수를 작성해보세요. (난이도: 중상)
- BigNum 구조체 변수들의 곱셈을 수행하는 함수를 만들어보세요. (난이도: 상)
- BigNum 구조체 변수들의 나눗셈을 수행하는 함수를 만들어보세요. (난이도: 최상)
참고로 BigNum 구조체를 다룰 때 중요한 점은 수의 크기가 위 배열에 들어가지 않을 정도로 클 때를 적절히 처리해 주어야 한다는 점에 있다. 
*/



/* 공용체(union) 와 열거형(enum) */
/* C 언어에서도 사용 비중이 그리 크지는 않지만 어쨌든 알기는 알아야 하는 기능들 */

/* 구조체 안의 구조체 */
#include <stdio.h>
struct employee { /* 해당 구조체에서는 int 형의 age 와 salary 변수 2 개가 멤버로 되어 있다. */
    int age;
    int salary;
};
struct company { /* company 구조체에서는 또다른 구조체 변수를 멤버로 가지고 있음을 볼 수 있다. 
구조체는 int 나 char 과 같이, 사용자가 정의한 또다른 형(type) 이기에 위와 같은 정의가 가능하다. */
    struct employee data;  /* 만들어진 형은 이름이 struct employee 라는 것이고, 그중 data 라는 (구조체) 변수를 생성하였다. 
    이는 int a 와 지극히 똑강은 작업이다.  */
    char name[10];
};
int main() {
    struct company Kim; /* company 구조체를 정의한 뒤, struct company 형의 변수 Kim 을 정의하였다. */

    /* Kim 의 멤버들에 값을 대입한다. */
    Kim.data.age = 31;  /* 연산자의 우선 순위는 기본적으로 왼쪽부터 이므로, Kim data 가 먼저 해석된 후, (Kim.data).age 가 해석이 된다. 
    다시말해, "Kim 의 data 멤버의 age 멤버"로 생각되는 것이다. */
    Kim.data.salary = 3000000;

    printf("Kim's age : %d \n", Kim.data.age);
    printf("Kim's salary : %d$/year \n", Kim.data.salary);

    return 0;
}


/* 구조체를 리턴하는 함수 */
/* 구조체는 말그대로 사용자가 창조한 하나의 형(type) 이기 때문에 int, char 등이 가능했던 모든
것들을 구조체 역시 그대로 할 수 있다. 따라서 구조체 형을 리턴하는 함수 역시 가능하다. */
#include <stdio.h>
struct AA function(int j);
struct AA {  /* AA 라는 구조체를 정의하였다. 
    (편의상 멤버는 int i 로, 하나만 가진다고 한다.) */
    int i;
};

int main() {
    struct AA a;

    a = function(10);
    printf("a.i : %d \n", a.i);

    return 0;
}

struct AA function(int j) {  /* struct AA 형을 리턴하는 함수 function 이다. 인자로는 int j 를 취한다. */
    struct AA A;
    A.i = j;

    return A;
}


/* 구조체 변수의 정의 방법 */

/* 
<구조체 변수를 정의하는 색다른 방법> 
예제를 이렇게 길게 만든 이유는 소스를 읽으면서 구조체와 조금 더 친해지길 바래서이다. 
소스를 천천히 분석해보자. 
*/
#include <stdio.h>
char copy_str(char *dest, char *src);
int Print_Obj_Status(struct obj OBJ);
struct obj { /* struct obj 라는 구조체를 정의하였고, 멤버는 아래와 같다. */
    char name[20];
    int x, y;
} Ball; /* Ball; 은 바로 struct obj 형의 Ball 이란 구조체 변수를 정의하라는 뜻이다. 
사실, 우리가 main 함수 내부에서 
struct obj Ball; 
이라고 써왔던 것과 다를 바가 없다. */

int main() {
    Ball.x = 3;
    Ball.y = 4;
    copy_str(Ball.name, "RED BALL");

    Print_Obj_Status(Ball);

    return 0;
}
int Print_Obj_Status(struct obj OBJ) {
    printf("Location of %s \n", OBJ.name);
    printf("( %d , %d ) \n", OBJ.x, OBJ.y);

    return 0;
}
char copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}



/* 멤버를 쉽게 초기화하기 */
#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN { /* HUMAN 구조체는 아래와 같이 4 개의 int 형 멤버들을 가지고 있다. */
    int age;
    int height;
    int weight;
    int gender;
};

int main() {
    struct HUMAN Adam = {32, 182, 75, 0}; /* main 내부에서 Adam 과 Eve 를 정의하였다. 
    이때, ={} 를 통해서 중괄호 내부의 정보들이 순차적으로 각 멤버에 대입되게 된다. 
    따라서 Adam 의 경우 age 에는 31 이, height 에는 182 가, gender 에는 0 이 들어가게 되낟. */
    struct HUMAN Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(struct HUMAN human) {
    if (human.gender == 0) {
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
        human.weight);
    
    if (human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!! \n");
    } else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER!! \n");
    }

    printf("-------------------------------------------- \n");

    return 0;
    /* 해당 코드는 구조체의 잡다한 기능 중 하나인 '멤버를 초기화하는 방식' 을 보여주고 있다. 
    이 방식을 통해서 우리는 이전까지 멤버를 초기화해온 방식보다 더 쉽게 멤버를 초기화할 수 있다. */
}


/* 공용체 (union) */
/* 공용체는 많이 사용하는 기능은 아니지만, 그래도 C 언어에서 제공하는 것들 중 하나이니 
간단하게 집고 넘어가도록 한다. 
공용체는 구조체와는 달리 메모리를 '공유' 한다. 
union A 
{
    int i;
    char j;
};
를 했을 때, union A 의 경우 j 의 값을 변경함으로써 i 의 값을 변경할 수 있고,
마찬가지로 i 의 값을 변경함으로써 j 의 값을 변경할 수 있게 된다. 
*/
#include <stdio.h>
union A {
    int i;
    char j;
};
int main() {
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j);
    return 0;
    /* 해당 코드를 출력하면 출력값은 78 이 나온다. 
    우리가 a 의 j 멤버 값을 전혀 설정해주지 않았음에도 불구하고 i 에 0x12345678 을 
    대입하자 j 의 값이 78 로 출력되었다. 그러나 어째서 0x12 가 아닌 78이 출력되었을까??
    분명히 i 와 j 가 동일한 주소값에 위치해 있고 i 가 0x12345678 로 메모리 상에 있다면 
    j 는 처음 두 개인 0x12 가 되어야 하는 것이 아닐까??
    
    물론, 이러한 의문은 옳다. 하지만 컴퓨터에서는 수를 이런 식으로 보관하지 않는다는 점에 유의하자. (적어도 우리의 컴퓨터에서는.)  */
}
/* 빅 엔디안(Big Endian), 리틀 엔디안(Little Endian) */
/* 컴퓨터에서 메모리에 수를 저장할 때, 낮은 주소값에 상위 비트를 적는 방식을 '빅 엔디안' 방식이라 한다. (우리가 생각하는 방법)
그리고 그 정반대로 높은 주소값에 상위 비트를 적는 방식을 '리틀 엔디안' 이라고 한다. 
현재 대부분의 x86 프로세서는 리틀 엔디안 방식을 사용하고 있다. (일부 컴퓨터에서만 빅 엔디안을 사용한다. 따라서 우리들의 컴퓨터도 거의 모두 리틀 엔디안을 사용하고 있을 것이다.) */

/* 따라서, 빅 엔디안에서는 j = 0x12 가 된다. 
하지만 우리가 사용하는 프로세서는 대부분 리틀 엔디안 방식이므로, 
리틀 엔디안에서는 j = 0x78 이 된다. */



/* */
#include <stdio.h>
union A {
    int i;
    short j;
};
int main() {
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j);
    return 0;
    /* 해당 코드를 성공적으로 컴파일하면 5678 이 나온다. (0x5678 의 의미이다.)
    위의 코드를 따르면 0x7856 이 출력되어야 정상이지만 그게 아니라 0x5678 을 출력하였다. 
    그 이유는 j 가 short 형(2 바이트) 이기 때문이다. */
    
    /* 만약 i 의 값을 출력하면 당연히 0x12345678 이 나올 것이다. 왜냐하면 컴퓨터는 자신이 메모리에 수를 '리틀 엔디안' 방식으로 
    저장하고 있다는 것을 알기 때문이다. 따라서 이를 출력할 때에는 적절한 변환을 취해서 0x78563412 가 아니라 0x12345678 을 출력할 것이다. 
    j 의 경우도 마찬가지이다. j 는 현재 '78 56' 부분을 가리키고 있지만, 컴퓨터는 j 가 리틀 엔디안 형식으로 이루어져있다는 것을 알기에
    j 를 출력할 때에는 적절히 변환하여 0x5678 을 출력하게 될 것이다. /
}


/* 열거형(Enum) */
/* 프로그래밍을 하다보면 각 데이터에 수를 대응시키는 경우가 빈번하다. 예를 들어 사람을 처리할 때, 남자에는 0, 여자에는 1 을 대응시켜서 처리하거나 
색깔을 나타낼 때도 빨강에는 0, 흰색에는 1 등을 대응시켜서 나타내게 된다. 
그렇지만 이처럼 수를 대응시켜서 처리하는 방식은 코드를 짜거나 해석할 때 헷갈린다는 문제점이 있다. 
남자에는 0, 여자에는 1 임을 확실하게 기억하고 있다면 상관이 없겠지만, 기억하지 못하게 된다면 성에 대해 무엇을 대응시켰는지 다시 찾아보아야 된다는 번거로운 일이 발생한다. 
남자에ㅣ MALE 이라는 상수를 설정한다면 이해하기 쉽겠지만 이러한 방법은 MALE 이라는 상수의 설정으로 인해서 메모리가 낭비된다는 문제점이 있다. 
따라서 C 에서는 이와 같은 문제를 '열거형(Enum)' 을 통해서 해결한다. */
/* 열거형의 도입 */
#include <stdio.h>
enum { RED, BLUE, WHITE, BLACK }; /* 열거형을 나타내기 위해서는 enum 을 쓰고 중괄호 안에 각각에 대해 써주면 된다. 
그러면 컴파일러는 열거형에 나타나있는 각 원소에 0 부터 차례로 정수값을 매겨 주게 된다. 
즉, RED = 0, BLUE = 1, .. BLACK = 3 와 같이 말이다. 사용자는 이제 이를 자유롭게 이용하면 된다. */
int main() {
    int palette = RED;
    switch (palette) {
        case RED:
            printf("palette : RED \n");
            break;
        case BLUE:
            printf("palette : BLUE \n");
            break;
        case WHITE:
            printf("palette : WHITE \n");
            break;
        case BLACK:
            printf("palette : BLACK \n");
            break;
    }
}


/* 열거형 팁 */
#include <stdio.h>
enum { RED = 3, BLUE, WHITE, BLACK }; /* 열거형에서 처음 수를 0으로 시작하기 싫을 때는, 단순히 원하는 수로 해주면 된다. */
/* 위와 같이 RED = 3 으로 설정하였을 경우, RED = 3 부터 해서 BLUE = 4, WHITE = 5, BLACK = 6 이 된다. 
또한, 
enum { TED = 3, BLUE, WHITE = 3, BLACK }
으로 한다면 수를 지정한 부분부터 다시 시작되는 방식이므로 BLUE = 4, BLACK = 4 가 된다. 
(참고로, 열거형에서는 언제나 '정수값' 이어야 한다.) */
int main() {
    int palette = BLACK;
    printf("%d \n", palette);
}

/* 생각해볼 문제-문제 */
/* 문제 1:
공용체는 도대체 어디에 써먹을 수 있을까요?? */



/* 변수의 접근 범위 */
#include <stdio.h>

void function() {
    int a = 2;
}

int main() {
    int a = 3;
    function();

    printf("a = %d \n", a);
    /* 해당 코드를 출력하면 a = 3 이라고 출력된다.
    분명히 funciton 에서 a 에 2 를 대입했는데도 main 함수에선느 이전의 a 의 값인 3 이 나왔다.
    이런 결과가 나온 이유는 어떠한 함수 내에서 일반적으로 정의된 변수는 해당 함수 내에서만
    접근할 수 있기 때문이다. 
    이와 같이 해당 '지역' 에서만 접근할 수 있다고 해서 위와 같은 변수들을 '지역 변수' 라고 한다. 
    즉, main 함수 안의 a 와 function 안에 a 는 컴파일러가 보기에 다른 변수로 취급된다. */
}


#include <stdio.h>

int main() {
    int a = 3;
    {
        int a = 4;
        printf("a = %d \n", a);
    }

    printf("a = %d \n", a);
    /* 참고로 중괄호 {} 는 하나의 지역으로 취급되는데, 해당 지역에서 정의된 변수는 바깥 지역에서 정의된 같은 이름의 변수를 가리게 된다.
    예를 들어서 4 로 초기화된 a 는 바깥의 3 으로 초기화된 a 를 완전히 가리게 된다. 
    따라서 안의 printf 에서는 4 가 출력되고, 바깥의 printf 에서는 3 이 출력될 것이다. 
    위 두 a 는 아예 다른 변수로 취급된다. 
    또한 바깥 지역에서 안쪽 지역에 정의된 변수는 사용할 수 없다. (아래의 예제 코드에서 확인가능하다.) */
}


/* 예시 코드 */
#include <stdio.h>

int main() {
    { int b = 4; }

    printf("b = %d \n", a);
    /* 해당 코드는 컴파일 오류가 발생한다. 
    왜냐하면 b 는 printf 가 살고 있는 지역보다 안쪽에서 정의된 것이므로 
    바깥에서 볼 수 없기 때문이다. */
}


/* 전역 변수(global variable) */
/* 어떠한 지역에도 속해 있지 않은 변수를 '전역 변수' 라 한다. 
전역 변수는 지역 변수와는 달리 코드 어느 곳에서도 접근이 가능하다. */
#include <stdio.h>

int global = 0;

int function() {
    global++;
    return 0;
}
int main() {
    global = 10;
    function();
    printf("%d \n", global);
    return 0;
    /* 지역 변수의 경우, 함수가 종료될 때 파괴되었는데, 전역 변수의 경우 프로그램이 시작할 때 만들어졌다가 프로그램이 종료될 때 파괴된다. 
    전역 변수는 지역 변수와는 달리 메모리의 데이터 영역(Data segment) 에 할당된다.
    또한, 모든 전역 변수들은 정의 시 자동으로 0 으로 초기화된다는 것을 알고있어야 한다.*/
}


/* 전역 변수의 초기화? */
#include <stdio.h>

int global; /* global 은 전역 변수!! 
만일 global 이 지역 변수였다면 일단 컴파일 시에 global 변수가 초기화 되지 않고 사용되었다는 경고문구가 떴을 것이다.
하지만 컴파일러는 전역 변수는 따로 초기화를 하지 않는다면, 디폴트로 0 으로 초기화해버린다. */
int function() {
    global++;
    return 0;
}
int main() {
    function();
    printf("%d \n", global);
    return 0;
    /* 결과적으로 1 이 출력된다. */
}


/* 함수 호출 횟수 세기 */
#include <stdio.h>

int how_many_called = 0; // 전역변수로 사용된듯!!!
int function() {
    how_many_called++;
    printf("called : %d \n", how_many_called);

    return 0;
}
int main() {
    function();
    function();
    function();
    function();
    return 0;
    /* 해당 프로그램에서는 function 이라는 변수가 몇 번 호출되는지 알려준다. 
    how_many_called 라는 변수는 function 함수를 몇 번이나 호출했는지를 카운트해준다. 
    만일 how_many_called 를 function 함수의 지역변수로 만들었다면 함수 종료 후 바로 
    파괴되므로 정보를 보관할 수 없었을 것이다. 
    (해당 코드에서 how_many_called 는 전역변수인가봄@@!!!)*/
}


/* 전역 변수의 문제점 */
#include <stdio.h>

int how_many_called = 0;
int how_many_called2 = 0;
int function() {
    how_many_called++;
    printf("function called : %d \n", how_many_called);

    return 0;
}
int function2() {
    how_many_called2++;
    printf("function2 called : %d \n", how_many_called2);

    return 0;
}
int main() {
    function();
    function2();
    function();
    function2();
    function2();
    function2();
    function();
    function();
    function2();

    return 0;
    /* 해당 코드에서는 또 다른 함수 function2 의 호출 회수도 세는 변수를 지정하였다.
    전역 변수는 모든 함수에서 접근할 수 있기 때문에 이를 위해 다른 변수 how_many_called2 를 도입하게 되었다.
    그렇다면 위와 같이 10 개의 함수에 대해 각각 호출 회수를 세기 위해서는 아마도 10 개의 
    전역 변수가 필요하게 된다. 
    
    이는 심각한 문제일 수 있다. 전역 변수는 모든 함수에서 접근할 수 있기 때문에 전역 변수를 사용할 때는 매우 주의를
    기울여야 한다. 위와 같이 전역 변수를 수십 개 선언하다보면 필연적으로 문제가 발생할 수밖에 없다. 
    따라서 많은 수의 전역 변수를 선언하지 않는 것을 권장한다. (오류의 원인이 될 가능성 높아지기 때문.) */
}


/* 변수의 생존 기간 */
/* 일반적으로 정의된 변수들은 자신이 정의된 지역을 빠져나갈 때 파괴된다. 
다시말해, 자신이 정의된 위치를 포함하고 있는 중괄호 {} 를 벗어날 때 해당 변수가 사라지게 된다는 것이다. */

#include <stdio.h>

int* function() {
    int a = 2; /* a 는 지역 변수이다. 
    따라서 a 가 정의된 지역인 function 을 빠져나가면 a 는 소멸된다. (a 를 사용할 수 없게 된다는 뜻.)*/
    return &a; 
}

int main() {
    int* pa = function();  /* 하지만 이 줄과 같이 a 의 주소값을 리턴해서 function 외부에서 a 를 사용하려 한다면 어떻게 될까?? 
    이 경우, pa 는 이미 파괴된 변수인 a 를 가리키고 있기 때문에 문제가 된다. 
    따라서 해당 노드는 프로그램 실행 시에 오류를 발생하게 된다. */
    printf("%d \n", *pa);
    /* 해당 코드를 출력하면 오류 메세지가 뜬다. (이유는 윗줄에 적어둠.)*/
}

/* 정적 변수(static variable) */
/* 정적 변수는 지역을 빠져나가도 파괴되지 않는 변수이다. */
#include <stdio.h>
int* function() {
    static int a = 2; /* '정적 변수' 선언*/
    return &a;
}

int main() {
    int* pa = function() ;
    printf("%d \n", *pa);
    /* 정적 변수를 선언하기 위해서는 위와 같이 일반적인 변수 선언 앞에 static 만 붙여주면 된다. 
    그러면 해당 변수(=정적 변수)는 자신이 선언된 범위를 벗어나더라도 절대로 파괴되지 않는다.
    따라서 a 가 정의된 지역 밖에서 접근하더라도 a 는 소멸되지 않았기 때문에 2 라는 값이 잘 출력된다. */
}

/* 그렇다면 function 을 여러 번 호출하면 a 가 여러 번 2 로 초기화될까??
a 는 딱 한 번만 초기화된다. 
다시말해, static int a = 2 라는 문장은 딱 한 번 실행되며, 더 놀라운 점은 function 을 실행하지 않더라도 a 라는 
정적 변수는 이미 정의되어 있는 상태라는 것이다. 
따라서 이와 같은 정적 변수를 사용하면 아래처럼 해당 함수가 몇 번 호출되었는지도 쉽게 추적이 가능하다. */



/* 정적 변수의 활용 */
#include <stdio.h>

int function() {
    static int how_many_called = 0; // function 의 개수와는 관계없이, 전역 변수인 how_many_called 가 한 개만 사용된다. 
    /* (앞선 코드에서는 전역 변수가 여러 개 사용되었지만, 해당 코드는 정적 변수의 활용을 통해서 사용되는 전역 변수의 수를 줄인 것 같다.)*/

    how_many_called++;
    printf("function called : %d \n", how_many_called);

    return 0;
}
int function2() {
    static int how_many_called = 0;

    how_many_called++;
    printf("function2 called : %d \n", how_many_called);

    return 0;
}
int main() {
    function();
    function2();
    function();
    function2();
    function2();
    function2();
    function();
    function();
    function2();

    return 0;
    /* 정적 변수의 경우, 전역 변수처럼 데이터 영역에 저장되고 프로그램이 종료될 때 파괴된다. 
    또한 전역 변수처럼 정적 변수도 정의시 특별한 값을 지정해 주지 않는 한 0으로 자동 초기화된다. */
}

/* 메모리의 배치 모습 */
#include <stdio.h>
int global = 3;
int main() {
    int i;
    char *str = "Hello, Baby";
    char arr[20] = "WHATTHEHECK";

    printf("global : %p \n", &global);
    printf("i : %p \n", &i);
    printf("str : %p \n", str);
    printf("arr : %p \n", arr);
}

/* 생각해보기- 문제 */
/* 문제 1: 
스택에 대한 폭넓은 이해를 위해 아래 글을 보는 것을 추천한다. (동적 할당 부분 전까지만. 현재 교재는 387p)*/



/* 평범한 문장 */
#include <stdio.h>
char compare(char *str1, char *str2);
int main() {
    char str1[20];
    char str2[20];

    scanf("%s", str1);
    scanf("%s", str2);

    if (compare(str1, str2)) { /* 우리가 만든 compare 함수는 두 문자열이 같으면 1, 다르면 0 을 리턴한다. 
    그런데 if 문의 경우 괄호 안의 값이 0 이면 '거짓' 으로, 0 이 아니면 '참' 으로 판단하기 때문에 우리가 원하는 결과를 얻을 수 있는 것이다. */
        printf("%s 와 %s 는 같은 문장입니다. \n", str1, str2);
    } else {
        printf("%s 와 %s 는 다른 문장입니다. \n", str1, str2);
    }
    return 0;
}

char compare(char *str1, char *str2) {  /* compare 함수는 그냥 다 이 형태로 고정되어 있는 듯!!!*/
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }

        str1++;
        str2++;
    }

    if (*str2 == '\0') return 1;

    return 0;
}


/* 헤더 파일(header file) */
/* stdio.h 는 헤더 파일이다. 여태까지 헤더 파일에는 오직 함수의 원형들만을 넣었다. 
하지만 헤더파일에는 함수의 원형뿐만이 아니라 아래의 것들도 함께 주로 쓰는 경우가 대다수이다. 
(물론 헤더 파일에도 보통의 C 코드를 집어넣을 수는 있지만 권장하지는 않는다.)
1) 전역 변수
2) 구조체, 공용체, 열거형
3) 함수의 원형
4) 일부 특정한 함수(인라인 함수......나중에 설명할 것임.)
5) 매크로(나중에 설명함....)
*/

/* human 구조체-human.h */
enum { MALE, FEMALE };
struct Human {
    char name[20];
    int age;
    int gender;
};

struct Human Create_Human(char *name, int age, int gender);
int Print_Human(struct Human *human);
/* human.h 에는 위와 같은 것들이 포함되어 있다. 
일단 열거형으로 남자와 여자에 대한 저웃값들이 선언되어 있으며, Human 구조체, 그리고 한 Human 구조체 변수를 설정하는 Create_Human 함수와 
한 Human 에 대한 정보를 출력하는 Print_Human 함수들이 설정되어 있다. */



/* human.c */
#include <stdio.h>
#include "human.h"
#include "str.h"

struct Human Create_Human(char *name, int age, int gender) {
    struct Human human;

    human.age = age;
    human.gender = gender;
    copy_str(human.name, name);

    return human;
}
int Print_Human(struct Human *human) {
    printf("Name : %s \n", human->name);
    printf("Age : %d \n", human->age);
    if (human->gender == MALE) {
        printf("Gender : Male \n");
    } else if (human->gender == FEMALE) {
        printf("Gender : Female \n");
    }

    return 0;
    /* 해당 코드는 오류가 발생하는 코드이다.
    왜냐하면 일단 Human 구조체를 사용하므로 이 구조체에 대한 설명이 들어있는 human.h 와, printf 를 위한 stdio.h, 
    그리고 copy_str 함수를 위한 str.h 헤더 파일들을 모두 include 해주어야 하는데, 이를 하지 않았기에 함수를 찾을 수 
    없다는 내용의 오류가 발생하게 된다. */
}


/* 다른 사람이 만들어놓은 것 쓰기 */
/* 다른 사람들이 만들어 놓은 것을 가리켜 '라이브러리' 라고 한다. 
사용자는 C 프로그래밍에서 원하는 함수를 라이브러리에서 찾아 사용하는 것이 가능하다. */
/* 아래의 예제 코드는 기존에 우리가 copy_str 을 이용하여 str1 에 str2 를 복사하는 과정을 나타냈다. */

/* test.c */
#include <stdio.h>
#include "str.h"
int main() {
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};

    copy_str(str1, str2);

    printf("str1 : %s \n", str1);

    return 0;
}

/* str.h */
char copy_str(char *dest, char *src);
/* str.c */
#include "str.h"
char copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

    return 1;
    /* 어차피 나는 "str.h" 파일과 "str.c" 파일이 저장되어있지 않기 때문에 
    해당 코드를 출력하면 오류만 난다. */
}

/* 라이브러리의 사용 */
#include <stdio.h>
#include <string.h>
/* 문자열 복사가 필요할 때마다 copy_str 함수를 만들어서 쓰는 것은 귀찮은 일이다. 
따라서 사람들은 이 역할을 하는 함수를 '미리' 만들어놓았다. (string.h 를 의미하는 것.)*/
/* #include <string.h> 라는 명령은 string.h 파일에 있는 내용을 모두 가져다 붙인다는 의미를 가지고 있다. 
그런데 string.h 파일에는 '문자열을 처리하는데 관련된 함수들의 원형' 모음이 있다. 
따라서 우리는 해당 파일을 include 시킴으로써 문자열을 처리하는 여러가지 편리한 함수들을 사용할 수 있다. */
int main() {
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};

    strcpy(str1, str2);  /* strcpy 함수를 이용하면 copy_str 과 정확히 같은 결과를 출력시킬 수 있다. */

    printf("str1 : %s \n", str1);

    return 0;
    /* 이와 같이 사람들이 미리 만든 함수들의 모임을 가리켜서 '라이브러리' 라고 한다.
    우리가 현재 사용한 라이브러리는 문자열(string) 라이브러리이다. 
    또한, stdio.h 역시 라이브러리이다. 이것은 '입출력 라이브러리' 로, 입력과 출력에 관련된 함수들을 모아둔다. 
    대표적으로 printf 와 scanf 가 있고, getchar() 함수나 puts() 등등 수많은 함수가 여기에 정의되어 있다. */
}


/* strcmp 함수 */
#include  <stdio.h>
#include <string.h>
int main() {
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};
    char str3[20] = {"hi"};

    if (!strcmp(str1, str2)) {  /* strcmp 함수:
    해당 함수는 두 문자열을 비교해서, 두 문자열이 같다면 0 을 리턴하고 
    두 문자열이 다르다면 0 이 아닌 값을 리턴하게 되어 있다. 
    이 함수의 사용법도 이전에 우리가 만들었던 compare_str 함수와 동일하다. (첫번째와 두번째 인자에는 비교할 문자들의 주소를 넣어주면 된다. )*/
        printf("%s and %s is equal \n", str1, str2);
    } else {
        printf("%s and %s is NOT equal \n", str1, str2);
    }

    
    if (!strcmp(str1, str2)) {
        printf("%s and %s is equal \n", str1, str3);
    } else {
        printf("%s and %s is NOT equal \n", str1, str3);
    }    

    return 0;
}


/* # 친구들 */
/* # 이 들어간 명령들(예: #include) 은 '전처리기 명령' 이라고 한다. 
전처리기는 컴파일 이전에 처리된다는 의미이다. 
즉, 컴파일이 되기 이전에 #include 라는 부분은 #include 에 해당하는 파일의 
소스코드로 정확하게 변한다. */

/* define */
#include <stdio.h>
#define VAR 10
int main() {
    char arr[VAR] = {"hi"}; /* 본래 배열을 정의할 때, 대괄호 안에는 언제나 숫자가 들어가야 한다. (값이 들어가면 안됨. 상수 역시 올 수 없다!!) */
    /* #difine 명령은 아래와 같은 형태로 사용한다. 
    #difine 매크로이름 값           // 전처리기 문들은 끝에 ; 를 붙이지 않는 것 주의하기!!!
    이는 소스코드에서 '매크로이름' 에 해당하는 부분을 '값' 으로 대체하게 되는 것이다.
    물론, 전처리기 명령이기 때문에 컴파일 이전에 정확하게 대체된다. 
    따라서 
    #include <stdio.h>
    int main() {
        char arr[10] = {"hi"};
        printf("%s\n", arr);
        return 0;
    }
    과 완전히 의미가 동일한 문장이다. 
    해당 작업이 전처리기 문으로 인해 컴파일 이전에 처리되기 때문에 컴파일러 입장에서는 arr[10] 이라는 
    문장을 처리하는 것과 동일하므로 오류 없이 정확하게 수행될 수 있따는 것이다. */    
    printf("%s\n", arr);
    return 0;
}


/* #ifdef, endif */
/* ifdef 와 endif 는 무언가 if 문과 관련이 있을 것 같다. if 문처럼 특정한 조건에만 수행이 될 것이다. */

/* ifdef */
#include <stdio.h>
#define A
/* #define A 를 통해 A 가 정의되어있다면, 아래의 #ifdef 부분과 #endif 부분은 소스에 포함되어 있지 않은 것으로 간주되어 
컴파일러 입장에서는 마치 주석처럼 무시된다. (#define B 면 그 반대의 상황 연출됨.)
이러한 '조건부 컴파일(특정한 조건에 따라 컴파일 되는 부분이 다른 것)' 은 상당히 유용하게 쓰일 수 있다. */
int main() {
    #ifdef A
    printf("AAAA \n");
    #endif
    #ifdef B
    printf("BBBB \n");
    #endif
    return 0;
    /* 해당 코드를 출력하면 AAAA 가 나온다. 
    만일, #define 부분을 #define A 에서 #define B 로 바꾸면 실행결과는 BBBB 일 것이다. */
}


/* 생각해보기 */
/* 문제 1: 
헤더 파일이 두 번 중복되어서 include 되지 않기 위해서는 헤더파일에 어떠한 조건문을 넣으면 좋을지 생각해보세요. */




/* void 타입과 main 함수에 대한 이해 */


/* 리턴값이 없는 함수 */
#include <stdio.h>

void add_one(int* p) {
    (*p) += 1;
}

int main() {
    int a = 1;
    printf("Before : %d \n", a);
    add_one(&a);  /* add_one 함수는 인자로 전달된 포인터가 가리키는 것의 값을 1 증가시킨 뒤 종료된다. */
    printf("After : %d \n", a);
    /* 해당 코드는 return 을 수행하는 문장이 없다. 
    왜냐하면 
    void add_one(int* p) 와 같이 void 형으로 선언되어 있기 때문이다. 
    일반적으로 함수가 무언가를 리턴한다면, 그 무언가는 타입이 있어야 하기 때문에 
    이 void 함수가 가능한 형태는 '아무것도 리턴하지 않는 함수' 가 된다. */

    /* void 형 함수는 많은 곳에서 사용된다.
    주로 리턴을 할 필요가 없는 함수들의 경우가 대부분이다. 
    이런 함수들의 경우, 오히려 불필요하게 swap 의 리턴 타입이 있다면 swap 함수를 사용하는 
    사람의 입장에서 해당 함수의 리턴값은 무슨 의미인지를 이해해야 하므로 불편하다. */
}


/* 리턴값이 필요없는 함수-예제(교재 422p) */
#include <stdio.h>

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    /* 이유는 모르겠지만 출력할때마다 오류가 발생한다.... */
}


/* void 형 변수?? */
#include <stdio.h>
int main() {
    void a;

    a = 3;

    return 0;
    /* 위에서 void 형 함수에 대해 살펴봤다면, void 형 변수 역시 정의할 수 있을 것 같지만 사실 이는 오류이다. 
    컴파일러가 int a; 라는 문장을 보게 된다면 컴파일러는 '아, int 형의 변수 a 를 선언하는구나. 메모리 상에 미리 
    4 바이트의 공간을 마련해 놓아야지' 라고 생각할 것이다. 
    그런데 void a; 를 보게 된다면 컴파일러는 '이 변수의 타입은 뭐지??' 라고 생각하게 된다. 
    다시 말해, 이 변수를 위해서 메모리 상에 얼마나 많은 공간을 설정해 놓아야하는지 모르게 되는 것이다. 
    (참고로 컴파일 때 모든 변수들의 메모리 상의 위치가 결정되어야 한다.) 따라서 이와 같은 형식은 오류가 발생하게 된다. */
}


/* void 형을 가리키는 포인터 */
#include <stdio.h>
int main() {
    void* a;
    
    return 0;
    /* 해당 코드를 출력하면 오류가 발생하지 않는다. 
    왜냐하면 void *a 의 경우 '포인터' 이기 때문에 메모리 상에 8 바이트만큼을 지정하게 된다.
    (64 비트 시스템에서 포인터의 크기는 8 바이트이다.) 
    즉, a 에는 어떠한 지점의 메모리의 주소 값이 들어가게 되는 것이다. 물론, 논리를 따지고 보면 void 형 변수라는 
    것은 존재할 수 없기 때문에 void 형 포인터의 존재는 쓸모가 없어보인다. 하지만 사실 void 는 타입이 
    없기 때문에 거꾸로 생각해보면 어떠한 형태의 포인터의 값이라도 담을 수 있게 된다. */
}


/* b 의 값을 보려면 */
#include <stdio.h>
int main() {
    void *a;
    double b = 123.3;

    a = &b;

    printf("%lf", *a);
    return 0;
    /* 해당 코드를 컴파일하면 오류가 발생한다. 왜냐하면 컴파일러는 *a 가 무엇을 말하는지 알 수 없기 때문이다. 
    여태까지 *a 를 해석할 때 컴파일러는 a 가 가리키는 것의 타입을 보고 메모리 상에서 a 부터 얼마만큼 읽어들여야
    할 지 결정했는데 void a; 의 경우, 메모리 상에서 얼마만큼 읽어들여야할 지 모르게 때문이다.  */
}


/* b 의 값을 보려면-수정 버전!!! */
#include <stdio.h>
int main() {
    void *a;
    double b = 123.3;

    a = &b;

    printf("%lf", *(double *)a); /* 형변환 이용!!!!!!!
    단순히 주소값을 담고 있는 a 에게 (double *) 를 취함으로써 
    컴파일러로 하여금 "이 포인터 a 가 담고 있는 주소값은 double 을 가리키는 주소값이라 생각해" 라고 말한 것이다.
    따라서 (double *)a 부분을 통해 컴파일러는 현재 a 가 가리키고 있는 곳의 주소값을 double 로 생각하게 되어 8바이트를 읽어들이게 된다. 
    
    void 형 포인터는 단순히 어떤 타입의 포인터의 주소값도 편리하게 담을 수 있기 때문에 많은 부분에서 활용되고 있다. */
    return 0;
}


/* 임의의 주소값 p 로부터 byte 만큼 읽은 함수 */
#include <stdio.h>
int read_char(void *p, int byte);
int main() {
    int arr[1] = {0x12345678};

    printf("%x \n", arr[0]);
    read_char(arr, 4);
}
int read_char(void *p, int byte) {
    do {
        printf("%x \n", *(char *)p);
        byte--;

        p = (char *)p +1;  /* (char *)p 는 '이 p 에 들어있는 값을 char 형 변수의 주소값이라 생각해!!' 의 의미이다. 
        그런데 거기에 += 1 을 했으므로 포인터의 덧셈이 행해지는데 컴퓨터는 p 를 'char 형 변수의 주소값' 이라 생각하고 있으므로
        p 에 1 을 더하게 되면 주소값이 char 의 크기, 즉 1 만큼 늘어난다. 
        이와같은 방식으로 p 의 주소값을 계속 1 씩 증가시키는데, 이때 byte 의 값이 0 이 되거나 ((char *)p) 의 값이 0 (즉, NULL) 일 때 while 문이 종료된다. 
        */
    } while (p && byte);

    return 0;
}



/* main 함수의 인자라고?? */
#include <stdio.h>
int main(int argc, char **argv) { // argc : main 함수가 받은 인자의 수, argv : main 함수가 받은 각각의 인자들.
    printf("받은 인자의 개수 : %d \n", argc);
    printf("이 프로그램의 경로 : %s \n", argv[0]);

    return 0;
    /* 해당 코드에서 main 함수가 인자를 받고 있음을 확인할 수 있다. 
    인자는 운영체제에서 알아서 넣어주고 있는 것이다. 
    argc 는 main 함수가 받은 인자의 수이다. 
    argv 는 main 함수가 받은 각각의 인자들을 나타낸다. 
    즉, main 함수는 자신의 실행 경로를 인자로 받게 된다. */
}


/* 인자를 가지는 메인 함수 */
#include <stdio.h>
int main(int argc, char **argv) {
    int i;
    printf("받은 인자의 개수 : %d \n", argc);

    for (i = 0; i < argc; i++) {
        printf("이 프로그램이 받은 인자 : %s \n", argv[i]);
    }

    return 0;
}



/* 생각해보기-문제 */
/* 문제 1 : 
메인함수의 인자를 활용한 계산기를 만들어보자.
예를 들어서 
calc.exe 5 + 10 
을 치면 15 가 나오게 하면 된다. 
이때, 5, +, 10 은 모두 다른 인자로 봐야할 것이다. 기초적인 단계이므로 연산자는 하나만 써도 된다고 하자.
참고로 인자는 모두 문자열 형태로 오기 때문에 문자열로 된 수를 int 형으로 바꾸는 작업이 필요할 것이다. */



/* 동적 메모리 할당 */
/* 말 그대로 '동적으로 메모리를 할당' 한다. 
'동적' 이란 정해진 값으로 고정된다는 것이 아니라 가변성을 띤다는 것이다. 
또한 메모리를 '할당' 한다는 이야기는 역시 우리가 배열을 정의하면 배열에 맞는 메모리의 특정한 공간이 배열을 나타내는 것처럼
메모리의 특정한 부분을 사용할 수 있게 된다. 
(참고로, 할당되지 않는 메모리는 절대로 사용할 수 없다.) */
#include <stdio.h>
#include <stdlib.h>  /* malloc 함수가 <stdlib.h> 에 정의되어 있기 때문에 이 줄 역시 코드에 포함시켜주어야한다. */

int main(int argc, char **argv) {
    int SizeOfArray;
    int *arr;

    printf("만들고 싶은 배열의 원소의 수: ");
    scanf("%d", &SizeOfArray);

    arr = (int *)malloc(sizeof(int) * SizeOfArray); /* int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성 */
    /* malloc 함수는 memory allocation 의 약자이다. 해당 함수는 인자로 전달된 크기의 바이트 수만큼 메모리 공간을 만든다. 
    즉, 메모리 공간을 할당하게 되는 것이다. 
    우리가 원소의 개수가 SizeOfArray 인 int 형 배열을 만들기 위해서는 당연히 (int 의 크기) * (SizeOfArray) 가 된다. 
    이때, int 타입의 크기를 정확하게 알기 위해서 sizeof 키워드를 사용하게 된다. sizeof 는 해당 타입의 크기를 알려준다.
    따라서 sizeof(int) * SizeOfArray 를 인자로 전달해주면 된다.  */

    free(arr);

    return 0;

}


/* 동적 할당의 적용 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int student; // 입력받고자하는 학생 수
    int i, input;
    int *score;  // 학생들의 수학점수 변수
    int sum = 0; // 총점

    printf("학생의 수는? : ");
    scanf("%d", &student);

    score = (int *)malloc(student * sizeof(int));  /* 해당 부분을 통해서 원소의 개수가 student 인 int 형 배열을 생성하였다. 
    따라서 우리는 score 을 int score[student] 로 한 것처럼 사용할 수 있게 된다. 
    
    후에 아래와 같이 score 에 원소를 입력받고, 그 원소들을 모두 더해 평균을 구하게 된다. */

    for (i = 0; i < student; i++) {
        printf("학생 %d 의 점수 : ", i);
        scanf("%d", &input);

        score[i] = input;
    }

    for (i = 0; i < student; i++) {
        sum += score[i];
    }

    printf("전체 학생 평균 점수 : %d \n", sum / student);
    free(score);
    return 0;
}


/* 2차원 배열의 동적 할당 */
/* 2차원 배열을 동적으로 할당할 수 있을까?? 물론 가능하다. 
바로 '포인터 배열' 을 이용하면 된다. 
포인터 배열이라 함은, 배열의 각 원소들이 모두 포인터인 것을 의미한다. 
따라서, 각 원소들이 다른 일차원 배열들을 가리킬 수 있다. 그러므로 해당 배열은 2차원 배열이 된다. 
우리가 해야할 일은 먼저 포인터 배열을 동적으로 할당한 뒤에 다시 포인터 배열의 각각의 우너소들이 가리키는
일차원 배열을 다시 동적으로 할당해주면 된다. */

/* 2차원 배열의 동적 할당 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i;
    int x, y;
    int **arr; // 우리는 arr[x][y] 를 만들 것이다. 
    /* 만일 int array[3]; 이란 배열을 만들었다면 array 의 형은 int * 이다. 그렇다면 int * arr[10]; 이란 배열을 만들었다면 arr 의 형은 int **arr 이다. 
    따라서 우리는 int **arr; 과 같이 선언하였다. */

    printf("arr[x][y] 를 만들 것입니다. \n");
    scanf("%d %d", &x, &y);

    arr = (int **)malloc(sizeof(int *) * x); // int* 형의 원소를 x 개 가지는 1차원 배열 생성.

    for (i = 0; i < x; i++) {
        arr[i] = (int *)malloc(sizeof(int) * y);
    }

    printf("생성 완료! \n");

    for (i = 0; i < x; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}



/* 2차원 배열 동적 할당의 활용 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i, j, input, sum = 0;
    int subject, students;
    int **arr; /* 과목별 학생의 점수를 보관하기 위해서 이차원 배열을 사용하였다. 즉, arr[subject][students] 를 만들었다. */
    // 우리는 arr[subject][students] 배열을 만들 것이다. 

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생의 수 : ");
    scanf("%d", &students);

    arr = (int **)malloc(sizeof(int *) * subject);

    for (i = 0; i < subject; i++) {
        arr[i] = (int *)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("과목%d 점수--------- \n", i);

        for (j = 0; j < students; j++) {  /* arr 은 사실 2차원 배열은 아니지만 2차원 배열과 똑같이 행동하므로 arr[i][j] 와 같은 문장도 맞게 된다.
        arr[i][j] 를 i 행 j 열에 위치한 값이라 생각해도 무방하다.*/
            printf("학생%d 점수 입력 : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    for (i = 0; i < subject; i++) {
        sum = 0;
        for (j = 0; j < students; j++) {
            sum += arr[i][j];
        }
        printf("과목%d 평균 점수 : %d \n", i, sum / students);
    }

    for (i = 0; i < subject; i++) {
        free(arr[i]);
    }
    
    free(arr);

    return 0;
}


/* 할당한 (2차원 배열처럼 생긴) 배열 전달하기 */
#include <stdio.h>
#include <stdlib.h>

void get_average(int **arr, int numStudent, int numSubject);

int main(int argc, char **argv) {
    int i, j, input, sum = 0;
    int subject, students;
    int **arr;
    // 우리는 arr[subject][students] 배열을 만들 것이다. 

    printf("과목 수: ");
    scanf("%d", &subject);

    printf("학생의 수: ");
    scanf("%d", &students);

    arr = (int **)malloc(sizeof(int *) * subject);

    for (i = 0; i < subject; i++) {
        arr[i] = (int *)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("과목 %d 점수-----------\n", i);

        for (j = 0; j < students; j++) {
            printf("학생 %d 점수 입력: ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    get_average(arr, students, subject);

    for (i = 0; i <subject; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
void get_average(int **arr, int numStudent, int numSubject) {  /* 위의 함수와 다른 점: 해당 함수는 void 형 함수를 이용했다. 
해당 void 형 함수는 int **arr 와 numStudent, numSubject 를 인자로 받고 있다. 
(arr 은 2차원 배열처럼 행동함에도 불구하고 사실은 단순히 원소가 int * 형인 배열이기 때문에 위와 같이 int **arr 로 기존의 2차원 배열처럼
열의 개수에 대한 정보가 없어도 된다. (2차원 배열의 경우, int (*arr)[3] 과 같이 열에 관한 정보가 있어야 한다.))*/
    int i, j, sum;

    for (i = 0; i < numSubject; i++) {
        sum = 0;
        for (j = 0; j < numStudent; j++) {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum / numStudent);
    }
}


/* 생각해보기-문제 */
/* 문제 1:
위 성적 프로그램을 개량하여 학생별 평균을 내어 학생의 등수를 출력하는 프로그램을 만들어보아라. 
(난이도: 상) */
/* 문제 2:
동적으로 할당된 배열의 크기를 다시 바꾸는 프로그램을 만들어보아라. 즉 p 가 이미 원소가 10 인 동적으로 할당된 배열을 가리키고 있었는데 
예상치 못하게 원소 5 개를 더 추가하려면 어떻게 해야할까?? (난이도: 중) */



/* 구조체의 동적 할당과 메모리 관리 함수 */

/* 구조체 동적 할당 */
#include <stdio.h>
#include <stdlib.h>
struct Something {
    int a, b;
};
int main() {
    struct Something *arr;  /* 1차원 구조체 배열을 가리키기 위한 arr 을 선언하였다. int 형 배열을 만들기 이해 int *arr; 이라 했던 것과 정확히 일치한다. */
    int size, i;

    printf("원하시는 구조체 배열의 크기 : ");
    scanf("%d", &size);

    arr = (struct Something *)malloc(sizeof(struct Something) * size);

    for (i = 0; i < size; i++) {
        printf("arr[%d].a : ",i);
        scanf("%d", &arr[i].a);
        printf("arr[%d].b : ", i);
        scanf("%d", &arr[i].b);
    } 

    for (i = 0; i < size; i++) {
        printf("arr[%d].a : %d, arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);
    }

    free(arr);

    return 0;
    /* 앞서 말했듯이, 구조체 역시 특별하게 생각해야 하는 것이 아니라 '사용자가 만든 하나의 데이터 타입' 이라고 보면 된다. 
    다시말해, 구조체도 int 처럼 사용할 수 있다는 것이다. 따라서 구조체 배열을 malloc 을 이용하여 지지고 볶는 일은 전혀 이상할 것이 없는 행동이다. */
}


/* 새 노드를 만드는 함수 */
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->neztNode = NULL;

    return newNode;
}

/* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수 */
struct Node* InsertNode(struct Node* current, int data) {
    /* current 노드가 가리키고 있던 다음 노드가 after 이다. */
    struct Node* after = current->nextNode;

    /* 새로운 노드를 생성한다. */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* 새 노드에 값을 넣어준다. */
    newNode->data = data;
    newNode->nextNode = after;

    /* current 는 이제 newNode 를 가리키게 된다. */
    current->nextNode = newNode;

    return newNode;
}



/* 노드(node) 정리 소스코드 */
#include <stdio.h>
#include <stdlib.h>
struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy);
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);

struct Node {
    int data; /* 데이터 */
    struct Node* nextNode; /* 다음 노드를 가리키는 부분 */
};
int main() {
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    /* Node 2 뒤에 Node 4 넣기 */
    struct Node* Node4 = InsertNode(Node2, 400);

    PrintNodeFrom(Node1);
    return 0;
}
void PrintNodeFrom(struct Node* from) {
    /* from 이 NULL 일 때까지, 즉 끝부분에 도달할 때까지 출력 */
    while (from) {
        printf("노드의 데이터 : %d \n", from->data);
        from = from->nextNode;
    }
}
/* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수 */
struct Node* InsertNode(struct Node* current, int data) {
    /* current 노드가 가리키고 있떤 다음 노드가 after 이다. */
    struct Node* after = current->nextNode;

    /* 새로운 노드를 생성한다. */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* 새 노드에 값을 넣어준다. */
    newNode->data = data;
    newNode->nextNode = after;

    /* current 는 이제 newNode 를 가리키게 된다. */
    current->nextNode = newNode;

    return newNode;
} /* 선택된 노드를 파괴하는 함수 */
void DestroyNode(struct Node* destroy, 
                struct Node* head) { /* 다음 노드를 가리킬 포인터 */
    struct Node* next = head;           /* head 를 파괴하려 한다면 */
    if (destroy == head) {
        free(destroy);
        return;
    }           /* 만일 next 가 NULL 이면 종료 */
    while (next) { /* 만일 next 다음 노드가 destroy 라면 next 가 destroy 앞 노드 */
        if (next->nextNode == destroy) { /* 따라서 next 의 다음 노드는 destroy 가 아니라 
                                            destroy 의 다음 노드가 된다. */
            next->nextNode = destroy->nextNode;
        }  /* next 는 다음 노드를 가리킨다. */
        next = next->nextNode;
    }
    free(destroy);
}
/* 새 노드를 만드는 함수 */
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
    /* 해당 코드에서 확인할 수 있는 것처럼, 노드는 배열과는 달리 추가/삭제/삽입이 월등히 편리하다. 
    그러나 그게 노드가 배열보다 월등하다는 것을 말하는 것은 아니다. 왜냐하면 배열의 경우 3 번째 원소에
    접근하기 위해서는 단순히 arr[3] 으로 하면 되지만, 노드의 경우 헤드로부터 3 번째까지 일일이 찾아야
    만 하기 때문이다. 
    따라서 N 개의 노드가 있다면 최악의 경우 N 번 동안 계속 찾아야 하지만 배열의 경우 특정한 상수 시간 내에 
    찾아갈 수 있기 때문에 이 부분에서는 배열이 월등히 좋다고 할 수 있다. 
    또한 노드의 경우 데이터를 위한 공간 말고도 다음 노드를 가리키기 위한 4 바이트가 더 필요하기 때문에 
    공간적으로도 약간 손해를 본다고 생각할 수 있다. */
}


/* 메모리 관련 함수 */
/* 메모리에 관련된 C 표준 라이브러리에서 기본으로 지원되는 것들에 대해서 알아보도록 하자. 
일단 메모리를 직접적으로 가지고 논다고 말할 수 있는 함수들은 memmove, memcpy, memcmp, memset 등이 
있는데, 여기서 대표적인 3 개의 함수인 memmove, memcpy, memcmp 만 알아보도록 한다. */

/* memcpy 함수 */
#include <stdio.h>
#include <string.h>
int main() {
    char str[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1);  /* 해당 문장은 'str 로부터 strlen(str) + 1 만큼의 문자를 str2 로 복사해라' 라는 의미이다. 
    이때, strlen 함수를 문자열의 길이를 리턴해주는 함수로, 예를 들어 strlen("abc"); 를 하면 3 이 리턴된다. 
    여기서 마지막의 NULL 문자는 세지 않으므로 str2 에 memcpy 로 복사할 때에는 1 을 더한만큼을 더 복사해주어야한다. */
    memcpy(str3, "hello", 6);  /* 마찬가지로 str3 의 경우도 hello 의 5 문자와 끝에 NULL 을 위해 총 6 문자를 hello 의 시작 주소로부터 
    복사를 하게 된다. */

    printf("%s \n", str);
    printf("%s \n", str2);
    printf("%s \n", str3);

    return 0;
    /* memcpy 함수는 메모리의 특정한 부분으로부터 얼마까지의 부분을 다른 메모리 영역으로 복사해주는 함수이다. 
    해당 코드와 같이 문자열을 복사하는 데 사용될 수 있다. 
    문자열 복사를 전문적으로 하는 함수는 strcpy 이지만, memcpy 함수를 사용하는 것도 나쁘지 않다. */
}


/* memmove 함수 */
#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "I love Chewing C hahaha";

    printf("%s \n", str);
    printf("memmove 이후 \n");
    memmove(str + 23, str + 17, 6);  /* memmove 함수는 해당 줄의 경우 str + 17 에서 6 개의 문자를 str + 23 에 옮겼다. 
    다시 말해 hahaha 의 시작 부분에서 6 개의 문자인 "hahaha" 를 str 의 맨 마지막 부분으로 복사해 넣었다는 뜻이다.
    결과적으로 str 뒤에 "hahaha" 를 추가하게 된 셈이다. */
    printf("%s", str);

    return 0;
    /* memmove 함수는 memcpy 와 하는 일이 많이 비슷해보인다. 
    하지만 memmove 함수는 memcpy 와는 달리 메모리 공간이 겹쳐도 된다. 
    해당 코드의 경우도 str 과 복사하는 부분이 겹쳤지만 성공적으로 복사가 수행되었따. 
    덕분에 나중에는 memmove 함수를 아주 많이 사용하게 될 것이다. */
}


/* memcmp 함수 */
/* memcmp 함수는 두 개의 메모리 공간을 서로 비교하는 함수이다. */

#include <stdio.h>
#include <string.h>
int main() {
    int arr[10] = {1,2,3,4,5};
    int arr2[10] = {1,2,3,4,5};

    if (memcmp(arr, arr2, 5) == 0)  /* 해당 문장의 경우 arr 과 arr2 를 비교해서 처음 5 개의 바이트가 같다면 0 을 리턴하게 된다. 
    주의해야 할 점은 '5 개의 원소' 가 아니라 5 바이트라는 점이다. 
    만일 arr1 과 arr2 전체를 비교하고 싶다면 3 번째 인자로 sizeof(int) * 5 를 넣어주어야 했을 것이다. */
        printf("arr 과 arr2 는 일치!! \n");
    else
        printf("arr 과 arr2 는 일치 안함!!! \n");

    return 0;
    /* memcmp 함수는 메모리의 두 부분을 원하는 만큼 비교를 한다. 이때 같다면 0, 다르다면 결과에 따라 0이 아닌 값을 리턴하게 된다. */
}


/* 생각해보기-문제 */
/* 앞서 배운 노드는 여러모로 생각해볼 점이 많다. 다음의 과제들을 차례대로 해결해보길 바란다.*/
/* 문제 1:
head 가 주어질 때 전체 노드의 개수를 세는 int CountNode(Node* head) 함수를 작성해라. (난이도: 하)
*/
/* 문제 2: 
head 와 원하는 노드가 주어질 때 원하는 노드의 데이터 값을 출력하는 int SearchNode(Node* head, Node *search) 함수를 작성해라. (난이도: 하)*/
/* 문제 3: 
앞서 구현하였던 Node 의 단점으로는 '이 노드를 가리키는 노드' 를 쉽게 알 수 없다는 점이 있다. 
이를 보완하기 위해 
struct Node {
    int data;               // 데이터
    struct Node* nextNode;  // 다음 노드를 가리키는 부분
    struct Node* prevNode;  // 이전 노드를 가리키는 부분
};
형식으로 노드를 만들어보고 앞서 작성했던 모든 함수들을 다시 작성해보아라. (난이도: 중)
*/
/* 문제 4: 
위와 같은 형식의 노드를 개량하여 head 가 맨 마지막 노드인 tail 을 prevNode 로 가리키는 원형의 노드를
만들어보아라. 다시 말해 노드의 처음과 끝이 없다고 볼 수 있다. 
이러한 형태의 노드를 이용하여 앞서 구현하였던 모든 함수를 구현해보아라. (난이도: 중상)*/
/* 문제 5:
이전 강좌에서 만들었던 도서 관리 프로그램을 동적 할당과 구조체를 이용하여 만들어보아라. (난이도: 중)*/



/* 매크로 함수 */
#include <stdio.h>
#define square(x) x *x  /* square 라는 이름의 매크로 함수이고 인자로 x 를 x*x 로 치환한다는 의미이다. */
/* #define 문은 앞서 배웠듯이 '어떠한 것을 다른 것으로 치환해주는 것' 이다. 
즉 square(x) 부분을 x*x 으로 치환해주게 된다. */
int main(int argc, char **argv) {
    printf("square(3) : %d \n", square(3));


    return 0;
    /* 매크로 함수를 정의하는 방법(형태) : #define 함수 이름(인자) 치환할 것 */

}



/* 매크로 함수-2 */
#include <stdio.h>
#define square(x) x * x
int main(int argc, char **argv) {
    printf("square(3) : %d \n", square(3 + 1));

    return 0;
    /* 해당 코드에서 사용자의 의도는 4*4 를 계산하는 것이었을 것이다. 
    그런데 출력해보면 16 이 아닌 7 이 출력된다. 그 이유는 square(3 + 1) 이 
    전처리기에서 3 + 1 * 3 + 1 로 해석되기 때문이다. 
    이러한 문제를 해결하기 위해서는 어떻게 해야 할까??
    #define square(x) x* x 를 
    #define square(x) (x) * (x) 로 바꾸어주면 된다. 
    그러면 printf 안에 있었던 문장은 printf("square(3) : %d \n", (3 + 1) * (3 + 1)); 이 되어 16 이 성공적으로 출력될 것이다. */
}



/* 라디안에서 도로 바꾸기 */
#include <stdio.h>
#define RADTODEG(x) (x) * 57.295

int main(int argc, char **argv) {
    printf("5 rad 는 : %f 도" , RADTODEG(5));

    return 0;
    /* 해당 코드에서는 RADTODEG(1 + 4) 를 하더라도 (1 + 4) * 57.295 로 바뀌어서 원하는 결과를 출력할 수 있게 된다. */
}



/* 변수의 이름 출력하기 */
#include <stdio.h>
#define PrintVariableName(var) printf(#var "\n");   
/* #define 과 같은 전처리기 문에서만 사용되는 것 중 # 이 있는데,
어떠한 인자 앞에 # 을 붙이게 되면 이 인자를 문자열로 바꾸어 버린다. */

int main(int argc, char **argv) {
    int a;

    PrintVariableName(a);   /* 따라서 PrintVariableName(a); 은 
                                                printf(
                                                "a"
                                                "\n");
                                                으로 바뀌게 된다. 
                                                이때, C 언어에서 연속한 두 개의 문자열은 그냥 하나로 합쳐지므로 위 코드는 
                                                printf("a\n"); 
                                                와 동일하게 된다. 
                                                따라서 결과적으로 a 가 화면에 출력되는 것이다. */
/* 우리들은 # 가 붙으면 단순히 '이것을 문자열로 바꾼다.' 라고 생각만 해주면 된다. */

    return 0;
}


/* ## 의 사용 */
#include <stdio.h>
#define AddName(x, y) x##y
/* 위와 같이 AddName 에서는 x##y 는 x 에 있는 것과 y 에 있는 것을 하나로 합쳐준다. */

int main(int argc, char **argv) {
    int AddName(a, b);  /* 따라서 해당 줄은 전처리기에 의해 int ab; 로 정확히 치환된다. 
    따라서 컴파일러는 ab 라는 이름의 변수를 선언하게 되고 그 뒤로 쭉 가는 것이다. */

    ab = 3;

    printf("%d \n", ab);

    return 0;
    /* ## 는 # 의 친구격이다. 한 가지 명심할 점은 # 와 ## 둘 다 '전처리문' 에서만 사용할 수 있다는 것이다.
    즉 #define 에서만 사용할 수 있다는 정도로만 알아두면 된다. 
    ## 문은 입력된 것을 하나로 '합쳐주는' 역할을 한다. */

    /* 매크로함수가 위와 같이 여러 편리한 점들이 있지만 앞서 집고 나간 것처럼 여러가지 어려운 문제점들도 많다. 
    위에서처럼 괄호를 제대로 쓰지 않아 오류가 나는 경우가 많은데 이 경우 디버깅하기가 매우 까다롭기 때문에 오랜 
    시간을 잡아먹는 경우도 많다. 
    이러한 문제를 해결하기 위해서 C 언어에서는 또다른 해결책을 제시하였다. 이는 바로 '인라인(inline) 함수'이다. */
}



/* 인라인(inline) 함수 */
#include <stdio.h>
__inline int square(int a) { return a * a; }    /* 위 부분은 __inline 을 빼고 본다면 단순히 square 라는 함수를 만든 데 지나지 않는다. 
그러나 위의 줄에서 inline 형식으로 만든 square 함수는 우리가 생각하는 함수가 아니다. 단순히 '함수처럼 보이는 것' 일 뿐이다. 
inline 함수를 사용하게 되면 마치 매크로 함수처럼 아래의 4 줄이 */
int main(int argc, char **argv) {
    printf("%d", square(3));

    return 0;
    /* int main(int argc, char **argv) {
            printf("%d", 3 * 3);
            return 0;
        }
        과 정확히 동일해진다. 
        한 가지 매크로 함수와 차이점이 있다면, 매크로 함수와는 달리 인라인 함수를 전처리기가 무식하게 치환해버리는 것이 아니다. 
        매크로 함수를 사용했었을 때에는 전처리기가 무식하게 치환해버리는 바람에 연산자 우선 순위를 정확하게 고려해서 괄호도 적당히
        묶어주고 해야겠지만 인라인 함수의 경우 똑똑한 컴파일러가 인라인 함수를 사용한 문장 내부에서 적절하게 '우리가 보통 함수를 
        사용하는 것처럼' 바꿔 준다. 
        다시 말해 
        int main(int argc, char **argv) {
            printf("%d", square(3 + 1));
            return 0;
        }
        과 같은 문장은 우리가 보통 함수를 사용하는 것처럼 처리가 되기 때문에 똑똑하게 
        int main(int argc, char **argv) {
            printf("%d", (3 + 1) * (3 + 1));
            return 0;
        }
        이 된다. 
        */
}


/* 다른 인라인 함수 예제 */
#include <stdio.h>
__inline int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int main(int argc, char **argv) {
    printf("3 과 2 중 최대값은 : %d", max(3, 2));
    return 0;
    /* 해당 코드 역시 인라인 함수를 사용하였다. 컴파일러는 max(3, 2) 라는 문장을 보고 max 함수 내부의 코드로 
    max(3, 2) 를 대체할 수 있을지 생각하게 된다. 
    만일 이를 max 함수를 호출하고 리턴 받는 형태보다, 직접 작업하는 비용이 더 작다고 생각할 때에는 이를 치환하게 
    된다. 하지만, 이 비용이 더 크다면(코드 길이가 더 길어지겠지!) inline 키워드를 무시하게 된다. */

    /* 많은 사람들은 매크로 함수보다는 인라인 함수를 사용하도록 권장하고 있다. 이 때문에 원래는 C 표준에 없던 인라인 함수가 
    C99 라는 새로운 C 표준에 포함된 것만 보아도 알 수 있다. 
    인라인 함수를 매크로 함수와는 달리 컴파일러가 처리하기 때문에 훨씬 더 똑똑하게 동작하는데 일단, 매크로 함수와는 달리 인라인
    함수는 인자들의 타입을 확인한다. 
    또한 인라인 함수는 매크로와 달리 단순 치환을 하는 것이 아니라 진짜 함수처럼 동작하기 때문에 훨씬 구현하기 쉽고 편리하다. 
    뿐만 아니라 디버깅 역시 인라인 함수가 편리하다. 
    앞으로 단순한 작업들을 보기 편하게 함수로 처리하고 싶을 떄에는 인라인 함수들을 적극적으로 사용하였으면 한다. */
}



/* 생각해보기-문제 */
/* 문제 1:
다음과 같은 인라인 함수를 하나의 문장으로 바꿀 수 있는지 생각해보아라. 
__inline int some_function(int a) {
    int (a == 0)
        return 1;
    else if (a == 1)
        return 3;
    else
        return a * 2;
}*/



/* 루저 위너 판별 */
#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

int main() {
    struct HUMAN Adam = {32, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(struct HUMAN human) {
    if (human.gender == 0) {
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / weight : %d \n", human.age, human.height, human.weight);

    if (human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!! \n");
    } else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER!!  \n");
    }

    printf("------------------------------------- \n");

    return 0;
    /* 해당 코드는 이전에 구조체 단원에서 만들었던 루저-위너 구분 프로그램이다. 
    그런데 해댱 코드에서는 한 가지 귀찮은 점이 있다. 바로, 구조체를 사용할 때마다 앞에 struct 키워드를 붙여야 한다는 점이다. 
    간혹 struct 키워드를 붙이지 않는 날에는 오류를 맛보게 된다. 
    그렇다면 매번 귀찮게 struct HUMAN 이라 쓰는 대신에 간단하게 쓰는 방법이 없을까?? (물론 있다.)*/
}


/* 루저 위너 판별-typedef 의 이용 */
#include <stdio.h>
struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};
typedef struct HUMAN Human;     /* 해당 코드에서 가장 눈여겨보아야 할 부분. 
형태: typedef (이름을 새로 부여하고자 하는 타입) (새로 준 타입의 이름) 
다시 말해 위의 줄은 struct HUMAN 이라는 타입에 Human 이라는 다른 이름을 붙인 것이다. 
즉 struct HUMAN 이라고 쓸 것을 Human 이라고 써도 된다는 것이다. 
기존의 이름을 없애버린 것은 아니기 때문에 typedef 를 사용한 이후에도 struct HUMAN 이라고 쓴 것은 유효하다. */
int Print_Status(Human human);
int main() {
    Human Adam = {31, 182, 75, 0};
    Human Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(Human human) {
    if (human.gender == 0) {
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height, human.weight);
    if (human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!! \n");
    } else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER!! \n");
    }

    printf("----------------------------------------- \n");

    return 0;
}



/* 간단한 계산기 프로그램 */
#include <stdio.h>
int main() {
    int input;
    int a, b;

    while (1) {
        printf("--- 계산기 --- \n");
        printf("1. 덧셈\n");
        printf("2. 뺄셈\n");
        printf("3. 종료\n");

        scanf("%d", &input);

        if (input == 1) {
            printf("두 수 : ");
            scanf("%d %d" , &a, &b);
            printf("%d 와 %d 의 합: %d \n", a, b, a + b);
        } else if (input == 2) {
            printf("두 수 : ");
            scanf("%d %", &a, &b);
            printf("%d 와 %d 의 차 : %d \n", a, b, a - b);
        } else
            break;
    }
    return 0;
    /* 해당 코드는 잘 실행된다. 
    그러나 이 프로그램을 실제 계산기에 사용한다고 했을 때, 이 계산기는 안타깝게도 CPU 에서 32 비트 정수의 연산을 할 수 없다. 
    오직 16 비트 이하만 연산할 수 있다. 
    그렇다면 이 계산기에서 int 형을 사용하는 것은 불가능하고 short 나 char 형의 변수들만 선언해야할 것이다. 
    이를 위해서는 소스 코드 전체의 모든 변수들을 char 이나 short 로 바꿔주어야 한다. 
    
    그런데 만일 동일한 프로그램인데 다른 기종의 계산기에서는 int 형이 사용가능하다고 하자. 
    그렇다면 이 코드를 다시 또 바꿔줘야 하는 매우 귀찮은 일이 발생한다. 
    이런 상황을 대비해서 다음과 같이 코드를 바꿔보자. */
}



/* 향상된 소스 코드 */
#include <stdio.h>
typedef int CAL_TYPE;
int main() {
    CAL_TYPE input;
    CAL_TYPE a, b;

    while (1) {
        printf("--- 계산기 --- \n");
        printf("1. 덧셈\n");
        printf("2. 뺄셈\n");
        printf("3. 종료\n");

        scanf("%d, &input");

        if (input == 1) {
            printf("두 수 : ");
            scanf("%d %d", &a, &b);
            printf("%d 와 %d 의 합 : %d \n", a, b, a + b);
        } else if (input == 2) {
            printf("두 수 : ");
            scanf("%d %d", &a, &b);
            printf("%d 와 %d 의 차 : %d \n", a, b, a - b);
        } else
            break;
    }

    return 0;
    /* 바뀐 것은 변수들의 타입을 CAL_TYPE 라고 했던 점이다. 
    그리고 위에서 typedef 를 통해 CAL_TYPE 가 int 형과 같다고 정의하였다. 
    만일 이 소스 코드를 short 나 char 만 되는 계산기에 적용시키려면 어떻게 해야할까??
    기존에는 모든 변수의 타입을 전부 다 수정해야 했지만, 이제는 typedef 에서 CAL_TYPE 의 형을 
    short 나 char 로 간단히 바꿔버리면 된다. */
}



/* 여러가지 typedef 예제들 */
#include <stdio.h>
int add(int a, int b) { return a + b; }
typedef int CAL_TYPE;
typedef int (*Padd)(int, int);  /* 위 typedef 명령문은 복잡한 함수 포인터 명령에 Padd 라는 이름을 붙이는 것이다. */
/* 즉, 위의 코드는 다음의 문장과 정확히 동일한 의미를 가지게 된다. 
int (*ptr)(int, int) = add;
Padd ptr = add;
*/

typedef int Arrays[10];     /* '원소가 10 개인 int 형 배열을 선언해라' 라는 문장을 Arrays 라고 하나의 이름으로 바꾼 것이라고 보면 된다. */
/* 즉, 
int arr[10];
Arrays arr; 
은 위의 문장과 정확히 동일한 의미를 가진다. */

int main() {
    CAL_TYPE a = 10;
    Arrays arr = {1, 2, 3, 4, 5, 6, 7,8, 9, 0};
    Padd ptr = add;
    printf("a : %d \n", a);
    printf("arr[3] : %d \n", arr[3]);
    printf("add(3, 5) : %d \n", ptr(3, 5));

    return 0; 
}


/* 그 밖에 키워드들 */
#include <stdio.h>
typedef struct SENSOR {
    /* 감지 안되면 0, 감지되면 1 이다. */
    int sensor_flag;
    int data;
} SENSOR;

int main() {
    SENSOR *sensor;
    /* 값이 감지되지 않는 동안 계속 무한 루프를 돈다. */
    while (!(sensor->sensor_flag)) {
    }
    printf("Data : %d \n", sensor->data);
}



/* 컴파일러가 바꾸는 코드 */
#include <stdio.h>
typedef struct SENSOR {
    /* 감지 안되면 0, 감지되면 1 이다. */
    int sensor_flag;
    int data;
} SENSOR;
int mani() {
    SENSOR *sensor;
    if (!(sensor->sensor_flag)) {
        while (1) {
        }
    }
    printf("Data : %d \n", sensor->data);
}

 


/* volatile 키워드 */
#include <stdio.h>
typedef struct SENSOR {
    /* 감지 안되면 0, 감지되면 1 이다. */
    int sensor_flag;
    int data;
} SENSOR;

int main() {
    volatile SENSOR *sensor;
    /* 값이 감지되지 않는 동안 계속 무한 루프를 돈다. */
    while (!(sensor->sensor_flag)) {
    }
    printf("Data : %d \n", sensor->data);
    /* 이렇게 해준 순간 컴파일러는 sensor 에 대해 최적화를 수행하지 않게 된다. 
    volatile 의 의미는 '변덕스러운' 인데, sensor 에 volatile 키워드를 붙여준 순간 sensor->sensor_flag 의 값이 
    '변덕스럽게 변할 수 있기 때문' 에 이에 대한 최적화 작업들을 수행하지 말라는 의미가 된다. 
    따라서 컴파일러는 위 소스를 의미 그대로 컴파일하게 되어 우리가 원하던 결과를 얻을 수 있게 된다. */
}



/* #pragma */
/* #pragma 는 컴파일러에게 말하는 전처리기 명령이다. 
#include 나 #define 처럼 전처리기에 의해 컴파일 이전에 처리되지만,
그 명령은 컴파일러에게 전달되기 때문이다. */
#include <stdio.h>
struct Weird {
    char arr[2];
    int i;
};
int main() {
    struct Weird a;
    printf("size of a : %d \n", sizeof(a));
    return 0;
    /* 해당 코드를 출력하면 size of a : 8 이 출력된다. 
    이는 상당히 이상한 일이다. 분명히 Weird 구조체 내의 원소들의 총 바이트 수를 계산해보면
    arr 은 char 형 변수 2 개 로 2 바이트이고, i 는 int 형 변수 1 개로 4 바이트 이므로 
    6 이 나와야 정상이다. 
    컴퓨터가 이를 8 로 출력한 이유는 실제로 메모리 상에서 위 구조체의 크기를 8 바이트로 컴파일러가
    지정하였기 때문이다. 
    현재 우리가 사용하는 컴퓨터에서는 언제나 4 바이트 단위로 모든 것을 처리하는 것이 빠르다. 
    따라서 언제나 컴퓨터에서 데이터를 보관할 때에는 4 의 배수로 데이터를 보관하는 것이 처리 시 
    용이하게 된다. 이러한 이유 때문에 위 Weird 구조체 역시 4 의 배수를 맞추기 위해 크기를 8 바이트로 
    '필요없는' 2 바이트를 추가하면서까지 맞춘 것이다. 
    이렇게 컴파일러로 하여금 구조체를 더블 워드 경계에 놓지 말라고 하고 싶을 떄 pragma 키워드를 이용하면 된다. 
    (더블 워드 경계 : 데이터가 4 의 배수 경계에 놓인 것을 뜻한다.)*/
}



/* pragma 키워드 활용 예제 */
#include <stdio.h>
/* 전처리기 명령에는 ; 를 붙이지 않는다. */
#pragma pack(1)     /* 해당 명령은 마이크로소프트 계열의 컴파일러들에만 유효한 문장이다. 
이건 '구조체를 1 바이트 단위로 정렬하라는 뜻' 이다. 
즉, 구조체의 크기가 1 의 배수가 되게 하라는 것이다. (1 외에도 2,4,8,16 등이 오는 것이 가능하다.)
만일 기본값, 즉 더블 워드 경계로 정렬하기 위해서는 #pragma pack(4) 로 하면 된다. */
struct Weird {
    char arr[2];
    int i;
};
int main() {
    struct Weird a;
    printf("size of a : %d \n", sizeof(a));

    return 0;
}


/* weird.h */
struct Weird {
    char arr[2];
    int i;
    /* 위의 Weird 구조체 예제에서 Weird 부분만 다른 헤더파일로 빼놓은 것이다. 
    이 헤더파일의 이름은 weird.h 이다. */
};
/* test.c */
#include <stdio.h>
#include "weird.h"      /* 바로 위에 따로 빼둔 헤더파일을 다시 불러온다.(헤더파일 이름: weird.h)*/
int main() {
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
    /* test.c 에서 weird.h 를 포함했으므로 weird.h 의 내용이 test.c 로 그대로 복사된 셈이다. 
    (즉, #include "weird.h" 부분이 weird.h 의 내용으로 바뀌었다고 보앋 무방하다.)
    따라서 struct Werid 를 사용할 수 있게 되므로 위와 같은 결과가 발생한다. */
}

/* 다시 weird.h 헤더 파일 사용하기 -(근데 내가 헤더 파일을 따로 저장하는 법을 아직 몰라서 헤더 파일이 저장이 안된 듯....)*/
#include <stdio.h>
#include "weird.h"
#include "weird.h"
int main() {
    struct Weird a;
    a.i = 3;
    pritf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
    /* 해당 코드를 컴파일하면 오류가 발생한다. */
}



#include <stdio.h>
struct Weird {
    char arr[2];
    int i;
};
struct Weird {
    char arr[2];
    int i;
};

int main() {
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
    /* 해당 코드를 컴파일하면 오류가 발생한다. 
    왜냐하면 각각 #include "weird.h" 부분이 weird.h 의 내용으로 바뀌어서 
    결과적으로는 struct Weird 를 두 번 정의하였다고 오류가 나게 된다. 
    이러한 문제를 해결하기 위해서는 일단 C 의 기본 전처리기 명령을 이용하여 하는 방법이 있다. 
    */
}



/* 수정된 weird.h */
#ifndef WEIRD_H
#define WEIRD_H
struct Weird {
    char arr[2];
    int i;
};
#endif
/* 이상한 test.c */
#include <stdio.h>
#include "werid.h"
int main() {
    struct Weird a;
    a.i = 3;
    printf("Werid 구조체의 a.i : %d \n", a.i);
    return 0;
    /* 수정된 weird.h 와 해당 코드를 함께 실행하면 오류가 발생하지 않고 정상적으로 출력된다. (출력: Weird 구조체의 a.i : 3)
    오류가 나지 않는 이유는 다음과 같다. 
    우리가 전처리기라고 한다면 맨 처음에 첫번째 #include "weird.h" 를 만났을 때 WEIRD_H 가 정의되어 있지 않으므로 
    #ifndef 가 참이 되어 아래 #define WEIRD_H 가 수행되어 WEIRD_H 라는 것이 정의된다. 
    (값은 모르지만 아무튼, 이러한 이름이 정의되었다고 하자.)
    또한 헤더파일의 내용도 test.c 로 그대로 복사된다. 그 후에 실수로 weird.h 를 다시 한 번 include 하였을 때에는 이미 
    WEIRD_H 가 정의되어 있는 상태이므로 #ifndef WEIRD_H 가 거짓이 되어 #endif 로 넘어가버려 test.c 에 그 내용이 복사가 안 된다. 
    
    이렇게 하면 헤더파일의 내용이 중복으로 포함되는 것을 막을 수 있다.(이는 이미 수많은 헤더파일에서 사용되고 있는 방법이다.)
    하지만 #pragma 를 이용하면 훨씬 단순하게 할 수 있다. (아래의 코드가 그 예시)*/
}




/* #pragma 의 위엄 - weird.h */
#pragma once
struct Weird {
    char arr[2];
    int i;
};
/* test.c */
#include <stdio.h>
#include "weird.h"
int main() {
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
}


 
/* 생각해볼문제-문제 */
/* 문제 1: 
MSDN 에 들어가서 #pragma 와 연관된 키워드들을 잘 살펴보시기 바랍니다. */



/* 파일에 출력하기 */
/* a.txt 에 내용을 기록한다. */
#include <stdio.h>
int main() {
    FILE *fp;
    fp = fopen("a.txt", "w");

    if (fp == NULL) {
        printf("Write Error!!\n");
        return 0;
    }

    fclose(fp);
    return 0;
}



/* stdout 을 닫아버린다. */
#include <stdio.h>
int main() {
    fclose(stdout);
    printf("aaa");
    return 0;
}



/* 파일에서 입력 받기 */
/* fgets 로 a.txt 에서 내용을 입력받는다. */
#include <stdio.h>
int main() {
    FILE *fp = fopen("a.txt", "r");     
    /* "w"가 아니라 "r" 형으로 열었다. (r 은 읽기 형식으로 파일을 연다는 뜻이다.)*/
    char buf[20]; // 내용을 입력받을 곳
    if (fp == NULL) {
        printf("READ ERROR !! \n");
        return 0;
        /* fp 가 NULL 인지 아닌지 확인하는데, 특히 읽기 형식으로 파일을 열 때 주의해야한다.
        왜냐하면 쓰기 형식으로 파일을 열었을 때에는 파일이 존재하지 않는다면 새로 만들었지만
        읽기 형식으로 열 때에는 읽어들일 파일이 없다면 NULL 을 리턴하고 스트림을 만들지 않기 때문이다. */
    }

    fgets(buf, 20, fp);
    /* */
    printf("입력받는 내용 : %s \n", buf);
    fclose(fp);
    return 0;
    /* 왜 안되냐.....챗gpt 한테 물어보기..........*/
}



/* 한 글자씩 입력받기 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("a.txt", "r");
    char c;

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
        /* fgetc 는 fp 에서 문자 하나를 얻어온다. 
        즉, 한 문자씩 읽어들이는 것이다. 이 때 문자열 맨 마지막이 NULL 문자로 종료를 나타내는 것처럼, 
        파일의 맨 마지막에는 EOF 라고 End Of File 을 나타내는 값인 -1 이 들어가 있다. 
        따라서 c 가 EOF 인지 아닌지 비교하는 방법을 통해서 아래의 예제와 같이 파일의 크기를 알아내는 프로그램도 
        만들 수 있다. */
    }

    fclose(fp);
    return 0;
}



/* 파일의 크기를 알아내는 프로그램 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("a.txt", "r");
    int size = 0;

    while (fgetc(fp) != EOF) {
        size++;
    }

    printf("이 파일의 크기는 : %d bytes \n", size);
    fclose(fp);
    return 0;
}



/* 파일 위치 지정자 */
/* 만일 a.txt 에 abcdefg 가 들어있고 우리가 fgetc 로 입력을 받는다고 해보자. 
파일을 맨 처음 열었을 때에는 파일 위치 지정자는 파일의 맨 첫부분을 가리키고 있다. 
따라서 a 를 가리키고 있다고 보아도 무방하다. 
이제, 우리가 fgetc 로 입력을 받는다면 파일 위치지정자는 한 칸 넘어가서 다음에 입력받을 것을 가리키고 있게 된다.
따라서 fgetc 를 한 번 더하면 a 를 다시 입력받는 것이 아니라 그 다음인 b 를 입력받게 된다.
그리고 또 파일 위치지정자는 또 한 칸 이동해서 그 다음인 c 를 가리키고 있게 된다. */

/* 만일 우리가 abcd 까지 파일에서 입력받았는데 다시 처음부터 입력받고 싶다면 두 가지 방법을 사용할 수 있다.
하나는 fopen 으로 파일을 다른 스트림으로 또 여는 것이고, 또다른 하나는 파일 위치지정자를 맨 앞으로 옮기는 것이다. 
(후자의 예시는 아래의 코드와 같다.)*/
#include <stdio.h>
int main() {
    /* 현재 fp 에 abcdef 가 들어있는 상태 */
    FILE *fp = fopen("a.txt", "r");
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    /* d 까지 입력받았으니 파일 위치지정자는 이제 e 를 가리키고 있다. */
    fseek(fp, 0, SEEK_SET);     /* 해당 문장을 통해서 파일 위치지정자를 맨 처음으로 돌려버릴 수 있다. */
    /* fseek 함수를 fp 를 세번째 인자로부터 두번째 인자만큼 떨어진 곳으로 파일 위치지정자를 돌리는데, 
    위의 경우 SEEK_SET 으로부터 0 번째 떨어진 곳, 즉 SEEK_SET 으로 돌린다고 볼 수 있다. 
    이때 SEEK_SET 은 파일의 맨 처음을 일컫는 매크로 상수이다. 따라서 위 함수를 통해 fp 의 파일 위치지정자를 맨 처음으로 
    돌려서 다시 fgetc 를 했을 때 a 를 입력받게 된다. 
    참고로, SEEK_SET 외에도, 현재의 위치를 표시하는 SEEK_CUR 과 파일의 맨 마지막을 표시하는 SEEK_END 상수들이 있다. */
    printf("다시 파일 처음에서 입력 받는다면 : %C \n", fgetc(fp));
    fclose(fp);
    return 0;
}



/* 출력 스트림도 마찬가지 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("a.txt", "w");
    fputs("Psi is an excellent C programmer", fp);
    fseek(fp, 0, SEEK_SET);
    fputs("is Psi", fp);
    fclose(fp);
    return 0;
}



/* 생각해보기-문제 */
/* 문제 1:
사용자로부터 경로를 입력받아서 그 곳에 파일을 생성하고 a 를 입력해놓는 프로그램을 만들어보세요. (난이도: 하)*/
/* 문제 2:
a.txt 에 어떠한 긴 글이 들어있는데, 이 글을 입력받아서 특정한 문자열을 검색하는 프로그램을 만들어보세요. (난이도: 중)*/
/* 문제 3: 
a.txt 에 문자열을 입력받아서 b.txt 에 그 문자열을 역으로 출력하는 프로그램을 만들어보세요. (난이도: 중하) */




/* 파일에서 문자를 하나씩 입력받는다. */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    while ((c = fgetc(fp)) = ! EOF) {
        printf("%c", c);
    }
    /* 파일 위치 지시자는 다음에 입력받아야 할 위치를 기억해놓고 있다. 
    (파일에서 다음에 입력받을 부분의 위치를 가리키고 있다는 말이다.)*/
}



/* fseek 함수 예제 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r"); 
    /* 참고로, some_data.txt 에 있었던 내용은 이전 내용과 동일하게 There is some data in this FILE!!!! 이다. */
    char data[10];
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    fgets(data, 5, fp);  /* 해당 줄과 같이 fgets 함수를 통해서 fp 로부터 입력을 받는다. 
    이때, 문자열 형태로 입력을 받는데 입력을 받을 때 \n 이 나올 때까지 입력을 받거나 (두번째 인자의 크기 - 1) 만큼 
    입력을 받을 때까지 입력을 받게 된다. 
    위의 경우 \n 이 나오기 전에 4 바이트 만큼 입력을 받으므로 data 에는 Ther 이란 내용의 문자열이 들어간다. 
    (참고로, 왜 1 만큼 뺀 크기로 입력을 받냐면 data 에 문자열을 구성하기 위해 맨 뒤에는 언제나 NULL 문자를 위한 자리를 만들어주어야하기 때문이다.)*/
    printf("입력 받은 데이터 : %s \n", data);
    /* 이렇게 입력을 받게 된다면 이제 파일 위치 지정자는 e 를 가리키게 된다. */
    c = fgetc(fp);
    printf("그 다음에 입력 받은 문자 : %c \n", c);

    /* 그 다음에 fgetc 로 fp 에서 문자를 받아 오면 역시 생각했던 대로 e 가 출력이 된다. 그리고 파일 위치 지정자는 다시 한 칸 옆으로 옮겨가서 '' 을 가리키게 된다. 
    띄어쓰기도 엄연한 문자이기 때문에 띄어쓰기에도 ASCII 값이 대응되어 있다. */
    fseek(fp, -1, SEEK_CUR);
    /* 앞서 말했듯이 SEEK_CUR 은 현재 파일 위치 지정자의 위치를 나타내고, 두번째 인자로 -1 을 전달했으므로 왼쪽으로 1 만큼 옮기라는 것이다. 즉, 현재 파일 위치 지정자의 
    위치에서 왼쪽으로 1 만큼 다시 옮겼으니 '' 을 가리키고 있던 파일 위치 지정자가 이전의 'e' 를 가리키게 된다. */

    c = fgetc(fp);
    printf("그렇다면 무슨 문자가?? : %c \n", c);
    /* 따라서 다시 위의 함수를 호출하여 문자를 입력 받으면 다시 e 가 나오게 되는 것이다. */

    fclose(fp);
}



/* 파일의 마지막 문자를 보기 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    fseek(fp, -1, SEEK_END);
    c = fgetc(fp);
    printf("파일 마지막 문자 : %c \n", c);

    fclose(fp);
}



/* fopen 의 "r+" 인자 이용해보기 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r+");  /* some_data.txt 를 읽기 및 쓰기형식으로 열겠다는 뜻이다. (파일이 존재하지 않는 경우, 열지 않음. )
    반면에 뒤에서 배울 "w+" 도 "읽기 및 쓰기 형식으로 열겠다" 이지만, 이 경우 파일이 존재하지 않는다면 파일을 새로 만들고 파일이 존재한다면 파일의 내용을 싹 지워버리게 된다. */
    char data[100];
    fgets(data, 100, fp);  /* 해당 줄을 통해서 파일의 있는 내용들을 모두 읽어들였다. (정확히 말하면 최대 100 바이트 까지 읽는다.) 이와 함께 파일 위치 지정자도 파일 맨 끝을 가리키고 있다. */
    printf("현재 파일에 있는 내용 : %s \n", data);

    fseek(fp, 5, SEEK_SET);
    /* 위와 같이 fseek 함수를 이용하여 파일의 맨 앞에서 5 칸 떨어진 곳으로 이동해보자. 0 칸 떨어졌을 때는 T, 
    1 칸은 h, ... 와 같은 방식으로 세보면 5 칸 떨어진 곳은 ' ' 임을 알 수 있다. (공백 문자가 위치한 곳) */

    fputs("is nothing on this file", fp);  /* 그리고 여기에 해당 줄을 대입하게 되면 이전에 있던 내용은 무시하고 is nothing on this file 이 차지하는 만큼 
    덮어씌우기가 된다. */

    fclose(fp);
    /* 성공적으로 컴파일하였다면 
    There is some data in this FILE!!!! 
    와 같이 잘 나온다. */
}



/* 특정한 파일을 입력 받아서 소문자를 대문자로, 대문자를 소문자로 바꾸는 프로그램 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char c;

    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다. \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        /* c 가 대문자인 경우 */
        if (65 <= c && c <= 90) {
            /* 한 칸 뒤로 가서 */
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다. */
            fputc(c + 32, fp);

        }
        /* c 가 소문자일 경우 */
        else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
        }
    }

    fclose(fp);
    /* 해당 코드를 성공적으로 컴파일하였다면, 원래는 정상적인 파일이 괴상하게 변하는 것을 확인할 수 있다. (컴파일 할 때는 오류가 발생하는 것은 아니다.)
    그리고 프로그램이 종료되지도 않아서 강제로 종료해야 한다. 
    이러한 문제가 발생한 이유는 스트림 작업에서 읽기/쓰기를 변환할 때는 반드시 fflush 함수를 호출하거나 fseek 이나 rewind 와 같은 함수를 호출하여
    파일 위치 지정자를 다시 설정해주어야 하기 때문이다. 따라서 반드시 위와 같이 쓰기 작업 후 다시 읽기 작업(while 문에서 fputc 를 통해 읽기 작업이 수행된다.) 을 
    할 때에는 fflush 나 fseek 함수를 호출해주어야 한다. 
    이를 토대로 수정한 코드는 아래와 같다. */
}



/* 수정본-특정한 파일을 입력 받아서 소문자를 대문자로, 대문자를 소문자로 바꾸는 프로그램 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r+");
    char c;

    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        /* c 가 대문자일 경우 */
        if (65 <= c && c <= 90) {
            /* 한 칸 뒤로 가서 */
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다. */
            fputc(c + 32, fp);
            /* 
            쓰기-읽기 모드 전환을 위해서는 무조건 
            fssek 함수와 같은 파일 위치 지정자 함수들을 
            호출해야 한다. 
            */
           fseek(fp, 0, SEEK_CUR);
           /* fseek 대신에 fflush를 사용해도 된다.
           fflush(fp);
           를 적으면 된다. */
        }
        /* c 가 소문자일 경우 */
        else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }

    fclose(fp);
    /* 성공적으로 컴파일하면 some_data.txt 파일의 내용이 바뀐다. (대문자는 소문자로, 소문자는 대문자로 변한다.)*/
}



/* fopen 함수의 기타 인자 사용 */
/* fopen 의 'append' 기능 사용 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "a");
    /* fopen 부분을 살펴보면 파일을 "a" 형식으로 열었다. 이 뜻은 파일을 덧붙이기(append) 형식으로 연다는 의미이다. 
    기존의 "w" 로 열었을 때에는 파일의 내용이 모두 지워지는 대신에 맨 앞부터 내용이 쓰여졌는데,
    덧붙이기 형식에서는 파일의 맨 끝부분부터 내용이 쓰여지고 앞부분은 전혀 건들여지지 않는다. 
    즉, 이전에 파일에 들어가 있었던 내용들은 아주 소중하게 보호된다. */
    char c;
    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }
    /* 아래 내용이 파일 뒤에 덧붙여진다. */
    fputs("IS ADDED HAHAHAHA", fp);
    fclose(fp);
    /* "r+" 나 "w+" 와 마찬가지로 "a+" 형식도 있는데, 이도 마찬가지로 읽기/덧붙이기를 번갈아가면서 할 수 있다. 
    참고로 읽는 작업은 파일 어디에서든지 사용할 수 있지만 쓰기 작업의 경우에는 아무리 파일 위치 지시자를 이동시켜보아도 
    기존 파일의 끝 부분 위치에서부터만 사용할 수 있다. */
}



/* fscanf 이용하기 */
#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char data[100];

    if (fp == NULL) {
        printf("파일 열기 오류! \n");
        return 0;
    }

    printf("---- 입력 받은 단어들 ---- \n");

    while (fscanf(fp, "%s", data) != EOF) {  /* fscanf 함수는 우리가 여태까지 사용해왔던 svanf 함수와 아주 아주 유사한데, 사실 scanf 는 stdin 에서만 입력을 받고 fscanf 는 임의의 스트림에서만 입력을 받을 수 있는 좀 더 일반화 된 함수라고 보면 된다. */
        printf("%s \n", data);
    }
    /* fscanf 를 통해 fp 에서 문자열을 읽어오고 있는데 fgets 는 \n 이 나올 때까지 하나의 문자열로 보고 받아들이지만 
    fscanf 는 띄어쓰기나 탭 문자(\t), \n 들 중 어느 하나가 나올 때까지 입력 받으므로 파일에서는 각 단어들을 하나씩 읽어들이게 된다. 
    물론 읽어들인 마늠 파일 위치 지정자는 이동하게 된다. 
    이때 fscanf 가 더 이상 새로운 데이터를 입력받을 수 없는 경우에는 EOF 를 리턴하게 된다. 
    즉, 파일의 끝에 도달하면 EOF 를 리턴하여 while 문을 빠져나간다. */

    fclose(fp);
}



/* 파일에서 'this' 를 'that' 으로 바꾸기 */
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r+");
    char data[100];

    if (fp == NULL) {
        printf("파일 열기 오류!! \n");
        return 0;
    }

    while (fscanf(fp, "%s", data) != EOF) {  /* 이전 예제에서와 동일한 방식으로 fscanf 들을 통해 파일에서 단어들을 입력받는데, 각각의 단어들을 strcmp 함수를 이용하여 this 와 같은지 비교를 한다. 
    만일 같다면 이제 this 를 that 으로 덮어 씌우기만 하면 된다. */
        if (strcmp(data, "this") == 0) {
            fseek(fp, -(long)strlen("this"), SEEK_CUR);
            fputs("that", fp);

            fflush(fp); /* fflush 를 사용했지만, 위의 예시와 같이 fscanf 를 사용해도 된다. */
        }
    }

    fclose(fp);
    /* 성공적으로 컴파일하면 some_data.txt 파일에 들어있던 this is a man and this is a woman, and that is a boy 라는 문장에서
    this 가 전부 that 으로 바뀐 것을 볼 수 있다. 
    (따라서 출력 후 파일을 확인해보면 that is a man and that si a woman, and that is a boy 로 된다.)*/
    
}



/* 파일 입출력 실제로 적용해보기 */
/* 
지난번에 만들었었던 도서 관리 프로그램을 우리가 여태까지 배운 최신 C 언어 기술들(!!) 을 
이용하여 새롭게 만들었다. 어떻게 보면 
앞서 나온 생각해 볼 문제 중 두번째 문제의 해답이 되기도 할 것이다. 
*/
#include <stdio.h>
#include <stdlib.h>

struct BOOK {
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};
typedef struct BOOK BOOK;

char compare(char *str1, char *str2);
int register_book(BOOK 02 * book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);

int main() {
    int user_choice;    /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */
    BOOK *book_list;
    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
    scanf("%d", &user_choice);
    book_list = (BOOK *)malloc(sizeof(BOOK) * user_choice);
    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요. \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);
        if (user_choice == 1) { /* 책을 새로 추가하는 함수 호출 */
            register_book(book_list, &num_total_book);
        } else if (user_choice == 2) { /* 책을 검색하는 함수 호출 */
            search_book(book_list, num_total_book);
        } else if (user_choice == 3) { /* 책을 빌리는 함수 호출 */
            borrow_book(book_list);
        } else if (user_choice == 4) { /* 책을 반납하는 함수 호출 */
            return_book(book_list);
        } else if (user_choice == 5) { /* 프로그램을 종료한다. */
            break;
        }
    }
    free(book_list);
    return 0;
} /* 책을 추가하는 함수 */
int register_book(BOOK *book_list, int *nth) {
    printf("책의 이름: ");
    scanf("%s", book_list[*nth].book_name);
    printf("책의 저자: ");
    scanf("%s", book_list[*nth].auth_name);
    printf("책의 출판사: ");
    scanf("%s", book_list[*nth].publ_name);
    book_list[*nth].borrowed = 0;
    (*nth)++;
    return 0;
} /* 책을 검색하는 함수 */
int search_book(BOOK *book_list, int total_num_book) {
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30];
    printf("어느 것으로 검색할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 지은이 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf("%d", &user_input);
    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);
    printf("검색 결과 \n");
    if (user_input == 1) {
        /* i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을 사용자가 입력한 * 검색어와 비교하고 있다. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].book_name, user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                book_list[i].book_name, book_list[i].auth_name, 
                book_list[i].publ_name);
            }
        }
        /* 이 부분부터 위치 오류 발생한 것 같은데.......잘은 모르겠다. 
        수정한다고 해봤는데,,,,,,자꾸 오류난다ㅠㅠ*/
    } else if (user_input == 2) {
        /* i 가 0부터 num_total_book 까지 가면서 각각의 지은이 이름을 사용자가 * 입력한 검색어와 비교하고 있다. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].auth_name, user_search)) {
            printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, 
            book_list[i].book_name, book_list[i].auth_name,
            book_list[i].publ_name);
            }
        }
    } else if (user_input == 3) {
        /* i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를 사용자가 입력한 * 검색어와 비교하고 있다. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].publ_name, user_search)) {
            printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i, 
            book_list[i].book_name, book_list[i].auth_name,
            book_list[i].publ_name);
            }
        } 
    }
    return 0;
}

char compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == '\0') return 1;
    return 0;
}
int borrow_book(BOOK *book_list) { /* 사용자로부터 책 번호를 받을 변수 */
    int book_num;
    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &book_num);
    if (book_list[book_num].borrowed == 1) {
        printf("이미 대출된 책입니다! \n");
    } else {
        printf("책이 성공적으로 대출되었습니다! \n");
        book_list[book_num].borrowed = 1;
    }
    return 0;
}
int return_book(BOOK *book_list) { /* 사용자로부터 책 번호를 받을 변수 */
    int num_book;
    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &num_book);
    if (book_list[num_book].borrowed == 0) {
        printf("이미 반납되어 있는 상태입니다. \n");
    } else {
        book_list[num_book].borrowed = 0;
        printf("성공적으로 반납되었습니다! \n");
    }
    return 0;
    /* 해당 코드를 출력하면 오류가 발생한다....코드를 쓸 때 위치를 잘못 잡고 쓴 듯....ㅠㅠㅠ
    다시 써봐야 할 것 같다...*/
}


/* 생각해보기-문제 */
/* 문제 1:
위의 도서관리 프로그램에서 출력한 도서 목록을 입력 받아서 배열에 집어 넣는 작업을 만들어보세요. 
참고로 도서 목록 출력 방식은 아래와 같다고 합시다.
-전체 책의 개수 책 이름 저자 이름 출판사 이름 대출 유무 책 이름 저자 이름 출판사 이름 대출 유무
예를 들면 
2 2 C 언어 Psi Psi itguru offset AAA
와 같은 형식이지요. 물론 파일에 도서 목록을 출력하는 작업도 수정해야 되겠지요. (난이도 : 중) */
/* 문제 2: 
파일에서 특정한 단어를 검색하여 몇 번째 줄에 나오는지 모두 출력하는 프로그램을 만드세요. 
(참고로 1 줄의 기준은 \n 의 유무로 합니다. 따라서 fscanf 를 사용하면 안되겠지요??) (난이도 : 상) */
/* 문제 3:
파일에서 특정한 문자를 검색하여 몇 개나 나오는지 출력하는 프로그램을 만드세요. (난이도: 하) */




/* 생각해보기-문제 */
/* 문제 1:
책들의 목록을 html 형식에 맞게 출력하여 표로 깔끔하게 보여질 수 있게 해보세요. html 문법은 
http://www.w3schools.com/html/default.asp 에서 배울 수 있습니다. */




/* C 코드 최적화 */
/* 코드 최적화: 똑같은 일이라도 더 빠르게 수행할 수 있도록 코드를 짜는 행위.
다만, 최적화를 했다고 해도 실제로 성능이 향상될 수 있는지는 알 수 없다.(프로그램 작동 속도에 영향을 줄 수 있는 것들이 무수히 많기 때문이다.)
따라서, 항상 실제 향상 속도를 테스트해보는 것이 중요하다. (이를 프로파일링이라 한다.) */


/* 산술 연산 관련 */
/* 부동 소수점(float, double) 은 되도록 사용하지 말자. 
부동 소수점 수는 그 구조가 매우 복잡하다. 정수 자료형(int, short, ...) 의 경우 단순히 2 진수를 나타낸 것에 불과하지만 
부동 소수점은 그 수의 특정한 규격이 정해진 것이기 때문에 상당히 복잡하다. 
따라서 부동 소수점 수를 가지고 하는 연산 자체도 매우 느릴 수밖에 없다. */

/* 나눗셈을 피해라 */
/* 나눗셈은 매우 느린 연산이다. 다른 덧셈이나 뺄셈에 비해 몇 배 가까이 느리기 때문에 엄청난 시간 손해가 있따. 
따라서 if 문을 사용해주는 것이 나을 떄가 있다. (if 문은 나눗셈보다는 훨씬 빠른 처리가 가능하다.) */

#include <stdio.h>
int main() {
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);

    printf("%d 를 32 로 나누면 : %d \n", i, i / 32);
    printf("%d 를 5 칸 쉬프트하면 : %d \n", i, i >> 5);

    return 0;
}


/* 비트 연산 활용하기 */
/* 비트 연산(OR, AND, XOR 등등) 은 컴퓨터에서 가장 빠르게 실행되는 연산들이다. 
이러한 연산들을 잘 활용하면 유용하다. 
비트 연산은 여러 가지 정보를 하나의 변수에 포함하는 데 유용하다. 예제는 아래의 코드이다. */
#include <stdio.h>
#define ALIVE 0x1 // 2 진수로 1
#define WALKING 0x2 // 2 진수로 10
#define RUNNING 0x4 // 2 진수로 100 
#define JUMPING 0x8 // 2 진수로 1000
#define SLEEPING 0x10 // 2 진수로 10000
#define EATING 0x20 // 2 진수로 100000
int main() {
    int my_status = ALIVE | WALKING | EATING;  /* 위와 같은 방식으로 수를 대응시키고 my_status 에 OR 연산을 시켜주게 되면 
    각 데이터들이 나타내는 자리만 1 이 되고 나머지 모든 자리는 0 이 된다. 
    따라서 my_status 에는 0...0100011 이 될 것이다. */
    
    if (my_status & ALIVE) {  /* 이를 이용해서 if 문에서 단순히 유무를 파악하고자 하는 데이터와 AND 연산을 시키면 된다. */
    /* 예를 들면 내가 현재 WALKING 중인지 아닌지를 파악하기 위해 WALKING 과 AND 연산을 시켜보면
    만일 내가 WALKING 중이었다면 AND 연산 시 '나머지 부분은 모두 0 이고 WALKING 에 해당하는 자리수만 1 이 될 것' 이므로 if 문에서 참으로 판단되고 (if 문은 0 이 아닌 모든 값을 참으로 생각한다.)
    , 내가 WALKING 중이 아니었다면 '나머지 부분은 모두 0 이고 WALKING 에 해당하는 자리수조차 0 이 될 것' 이므로 0 이 되어서 if 문에서 거짓으로 판명된다. */
        printf("I am ALIVE!! \n");
    }
    if (my_status & WALKING) {
        printf("I am WALKING!! \n");
    }
    if (my_status & RUNNING) {
        printf("I am RUNNING!! \n");
    }
    if (my_status & JUMPING) {
        printf("I am JUMPING!! \n");
    }
    if (my_status & SLEEPING) {
        printf("I am SLEEPING!! \n");
    }
    if (my_status & EATING) {
        printf("I am EATING!! \n");
    }
    return 0;
    /* 이처럼 단순히 하나의 int 변수에 위 모든 데이터를 나타낼 수 있다. 
    그 이유는 해당 코드와 같이 define 을 이용해 여러 개의 변수에 값을 대응시켰는데 한 가지 특징은 각 데이터에는 오직 한 개의 비트만 1 이고 나머지는 모두 0 인 것이다. 
    예를 들면 JUMPING 을 보면 16 진수 8 을 대응시켰는데, 이를 2 진수로 보면 끝에서 4 번째 자리만 1 이고 나머지 모든 자리는 0 인 수가 된다. */

    /* 참고로 비트 연산과 관련하여 다음과 같은 내용을 기억하면 편하다. 
    1. 어떠한 정수의 특정 자리를 1 로 만들고 싶다면 그 자리만 1 이고 나머지는 0 인 수와 OR 하면 된다. 
    2. 어떠한 정수의 특정 자리가 1 인지 검사하고 싶다면 그 자리만 1 이고 나머지는 0 인 수와 AND 하면 된다. */
}



/* 비트 연산 활용하기(2) */
/* 비트 연산을 가장 많이 활용하는 예로 홀수/짝수 판별이 있다. */

/* 여태까지의 홀/짝 판별 프로그램 */
if (i % 2 == 1) // 이 수가 홀수인가
{
    printf("%d 는 홀수 입니다. \n", i);
} else {
    printf("%d 는 짝수 입니다. \n", i);
    /* 여태까지는 홀/짝 판별 프로그램을 해당 코드와 같은 구성으로 만들었을 것이다. 
    그러나 앞에서도 계속 강조해왔듯이, 나눗셈 연산은 매우 느리다. 
    이러한 문제점을 비트 함수에서의 단순한 AND 연산 한 번으로 해결이 가능하다. (예제는 아래와 같다.) */
}

if (i & 1) // 이 수가 홀수인가
{
    printf("%d 는 홀수 입니다. \n", i);
} else {
    printf("%d 는 짝수 입니다. \n", i);
}

#include <stdio.h>
int main() {
    int i;
    scanf("%d", &i);

    if (i & 1) // 이 수가 홀수인가
    {
        printf("%d 는 홀수 입니다. \n", i);
    } else {
        printf("%d 는 짝수 입니다. \n", i);
    }
    return 0;
}


/* 루프(loop) 관련 */
/* 루프는 대표적으로 1 부터 n 까지 더하는 함수를 만들 때 사용되는 함수이다. 
이를 통해서 시간 절약을 할 수 있다. 
-알고 있는 일반적인 계산 결과를 이용하라.
-끝낼 수 있을 때 끝내라.
-한 번 돌 때 많이 해라.
-루프에서는 되도록 0 과 비교해라.
-되도록 루프를 적게 사용하라.
*/



/* 설마 이것도?? */
#include <stdio.h>
int main() {
    int total = 3;
    int arr[total];
    int i, ave = 0;

    for (i = 0; i < total; i++) {
        printf("%d 번째 학생의 성적은??: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < total; i++) {
        ave = ave + arr[i];
    }

    ave = ave / total;
    printf("전체 학생의 평균은: %d \n", ave);

    for (i = 0; i < total; i++) {
        printf("학생%d : ", i + 1);
        if (arr[i] >= ave)
            printf("합격\n");
        else
            printf("불합격\n");
    }
    return 0;
}




























































































































































































