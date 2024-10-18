// 왜 c++ 을 배우냐
/* 
1. 많은 게임들과 게임 엔진들 (Unity, Unreal 등등)
2. 대부분의 컴파일러(gcc, clang 등)
3. 동영상 및 오디오 처리
4. 운영체제 (대표적으로 마이크로소프트의 윈도우즈)
5. 상용 프로그램들
6. 크롬 브라우저
7. 딥러닝 프레임워크
8. 서버 프로그램
9, 그 외 금융쪽이나 많은 연산이 필요한 경우들
*/

/* 강좌 수칙
1. 강좌는 적어도 한 번 꼭 정독해보기 
2. 모르는 것은 꼭 답글 달기
3. 답글로 질문하기 꺼린 내용은 메일 보내기!!
4. '생각해보기' 문제에서 적어도 30 분 이상은 투자하기
5. 이전 강좌를 완벽히 이해했다 싶지 않으면 다음 강좌로 넘어가지 말기 */


/* 나의 첫 C++ 프로그램 */
#include <iostream>     /* iostream 이라는 헤더파일을 include 하고 있다는 의미이다. */
/* iostearm 헤더 파일은 C++ 에서 표준 입출력에 필요한 것들을 포함하고 있다. (예를 들면 std::cout 이나 std::endl 과 같은 것들을 말한다. 이는 C 언어에서의 stdio.h 와 비슷하다고 보면 된다.)
그리고 C 언어와 하나 다른 점은, C++ 에서는 헤터 파일 이름 뒤에 .h 가 붙지 않는다. */
int main() {
    std::cout << "Hello, World!!" << std::endl;     /* std::cout 는 std 라는 이름 공간에 정의되어 있는 cout 을 의미한다. 
    만약에 std:: 없이 그냥 cout 라고 한다면 컴파일러가 cout 를 찾지 못한다. (서울에 사는 철수인지 부산에 사는 철수인지 알 길이 없기 때문이다.) */
    return 0;
}

/* 이름 공간 (namespace) */
/* 위의 코드에서 cout 앞에 붙어 있는 std 는 C++ 표준 라이브러리의 모든 함수와 객체 등이 정의된 '이름 공간(namespace)' 이다. 
이름 공간은 말 그대로 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것과 동일하다. 
코드의 크기가 늘어남에 따라, 혹은 다른 사람들이 쓴 코드를 가져다 쓰는 경우가 많아지면서 중복된 이름을 가진 함수들이 많아졌다.
따라서 C++ 에서는 이를 구분하기 위해, 같은 이름이라도 소속된 '이름 공간' 이 다르면 다른 것으로 취급하게 되었다. (그 예로, 같은 철수라는 이름을 가지고 있어도 부산에 사는 철수와 서울에 사는 철수는 다른 철수이다.) */

// header1.h 의 내용
namespace header1 {
int foo();
void var();
}

// header2.h 의 내용
namespace header2 {
int foo();
void bar();
}

/* 해당 코드들에서 header1 에 있는 foo 는 header1 라는 공간 속에 살고 있는 foo 가 되고, header2 에 있는 foo 의 경우 header2 라는 이름 공간에 살고 있는 foo 가 된다. 
자기 자신이 포함되어 있는 foo 의 경우 header2 라는 이름 공간에 살고 있는 foo 가 된다. 
또한, 자기 자신이 포함되어 있는 이름 공간 안에서는 굳이 앞에 이름 공간을 명시하지 않고 자유롭게 부를 수 있다. */

#include "header1.h"

namespace header1 {
int func() {
    foo();  // 알아서 header1::foo() 가 실행된다. 
    header2::foo();  // header2::foo() 가 실행된다.
}
}  // namespace header1

/* 어떠한 이름 공간에도 소속되지 않는 경우 */
#include "header1.h"
#include "header2.h"
int func() {
    header1::foo();  // header1 이란 이름 공간에 있는 foo 를 호출.
    /* 하지만 만일, 위 같은 foo 을 여러번 반복적으로 호출하게 되는 경우 앞에 매번 header1:: 을 붙이기가 상당히 귀찮을 것이다. 
    그래서 아래의 코드와 같이 '나는 앞으로 header1 이란 이름 공간에 들어있는 foo 만 쓸거다!!' 라고 선언할 수 있다. */
}

#include "header1.h"
#include "header2.h"

using header1::foo;
int main() {
    foo();  // header1 에 있는 함수를 호출
}

/* 뿐만 아니라, 그냥 기본적으로 header1 이름 공간 안에 정의된 모든 것들을 header1:: 없이 사용하고 싶다면 */
#include "header1.h"
#include "header2.h"

using header1::foo;  /* 아예 위와 같이 using namespace header1 과 같이 명시하면 된다. 
물론, 이 경우 역시 header2 에 있는 함수를 못 사용하는 것은 아니다. (아래의 코드와 같이 명시적으로 써주면 된다.)*/
int main() {
    foo();  // header1 에 있는 함수를 호출
}

/* header2 에 있는 함수를 사용하기 위해 명시적으로 써주는 경우 */
#include "header1.h"
#include "header2.h"
using namespace header1;

int main() {
    header2::foo();  // header2 에 있는 함수를 호출(명시적으로!!)
    foo();  // header1 에 있는 함수를 호출한 것(따라서 굳이 앞에 header1 을 써주지 않아도 됨. 기본적으로 header1 안의 함수들을 호출하기 때문이다.)
}


/* 다시 원래 예제로 */
int main() {
    std::cout << "Hello, World!!" << std::endl;
    return 0;
}
/* 여기에서 cout 와 endl 은 모두 iostream 헤더파일의 std 라는 이름 공간에 정의되어 있는 것들이다. 
std 를 붙이기 귀찮은 사람의 경우에는 아래의 코드처럼 쓰면 된다. */
#include <iostream>
using namespace std;
int main() {
    cout << "Hello, World!!" << endl;
    return 0;
    /* 참고로, using namespace std; 와 같이 어떠한 이름 공간을 사용하겠다라고 선언하는 것은 권장되지 않는다. 
    왜냐하면 std 에 이름이 겹치는 함수를 만들게 된다면, 오류가 발생하기 때문이다. 
    게다가 C++ 표준 라이브러리는 매우 거대하므로, 정말 수많은 함수들이 존재하고 있다. 자칫 잘못하다가 이름을 겹치게 사용한다면, 고치느라 시간을 많이 잡아먹을 것이다. 
    std 에는 매번 수많은 함수들이 새롭게 추가되고 있기 때문에 C++ 버전이 바뀔때마다 기존에 잘 작동하던 코드가 이름 충돌로 인해 동작하지 않게 되는 문제가 발생할 수 있다.
    따라서 권장하는 방식은 using namespace std; 를 사용하지 않고, std:: 를 직접 앞에 붙여서 std 의 이름공간의 함수이다 라고 명시해주는 것이 좋다. */
}
/* cout 은 ostream 클래스의 객체로 표준 출력(C 언어에서의 stdout 에 대응된다.) 을 담당하고 있다. */

/* 이름 없는 이름 공간 */
/* C++ 에서는 이름 공간에 굳이 이름을 설정하지 않아도 된다. 이 경우 해당 이름 공간에 정의된 것들은 해당 파일 안에서만 접근할 수 있게 된다. (이 경우, 마치 static 키워드를 사용한 것과 동일한 효과를 낸다.) */
#include <iostream>
namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있다.
// 이는 마치 static int OnlyInThisFile() 과 동일하다.
int OnlyInThisFile() {}

// 이 변수 역시 static int x 와 동일하다.
int only_in_this_file = 0;
}  // namespace

int main() {
    OnlyInThisFile();
    only_in_this_file = 3;
    /* 예를 들어서 위의 경우 OnlyInThisFile 함수나 only_in_this_file 변수는 해당 파일 안에서만 접근할 수 있다.
    헤더파일을 통해서 위의 파일을 받았다 하더라도 (물론 main 함수 부분은 무시하고), 저 익명의 namespace 안에 정의된 모든 것들은 사용할 수 없게 된다. */
}

/* 생각해보기-문제 */
/* 문제 1:
화면에 출력되는 것들을 바꾸어보자. */
/* 문제 2:
아래 문장은 화면에 어떻게 출력될까요??
std::cout << "hi" << std::endl
          << "my name is"
          << "Psi" << std::endl
*/


/* C++ 와 C 언어의 공통 문법 구조 */
/* C 언어에서 작성된 코드를 C++ 에 그대로 붙여넣기 해도 큰 문제가 없을 정도로 C++ 은 C 언어의 문법을 거의 완전하게 포함하고 있다. */

/* 변수의 정의 */
#include <iostream>
int main() {
    int i;
    char c;
    double d;
    float f;

    return 0;
    /* 가장 기초적인 부분인 변수를 정의하는 코드를 보면 C 언어에서 작성한 코드라고 말해도 믿을 정도로 동일하다.
    변수를 정의하는 부분에서만큼은 C 언어때와 달라진 점이 없다. 
    물론 변수명 이름 작성 규칙도 동일하다. 변수명도 C 언어 때와 마찬가지로 알파벳과 _기호, 숫자들을 사용할 수 있고 
    그 외의 것들은 사용할 수 없다. 또한 변수 이름의 맨 앞부분에는 숫자가 오면 안 된다. 
    
    어쨌든 결과적으로 변수의 정의는 물론이고 배열이나 포인터를 정의하는 방법도 C 나 C++ 이 동일하다는 것을 알 수 있다. 
    (물론 포인터의 경우 C 에서 * 와 & 가 했던 역할을 C++ 에서도 그대로 물려받았다.)
    예를 들어 C 에서 
    int arr[10];
    int *parr = arr;
    
    int i;
    int *pi = &i;
    라고 했던 것들을 C++ 에서는 어떻게 할까??
    
    답은 동일하다. C 와 똑같이 
    int arr[10];
    int *parr = arr;
    
    int i;
    int *pt = &i;
    이라고 쓰면 된다. 어떠한 것들을 선언하는 방법은 정말로 C++ 이나 C 가 차이가 없이 똑같음을 알 수 있다. */
}



/* 그렇다면 변수 선언 말고 다른 문법 구조들은 어떨까?? 반복문(for, while) 이라던지 조건문(if, else, switch) 이라던지...일단 for 부터 살펴보도록 하자. */
/* C++의 for 문 */
#include <iostream>
int main() {
    int i;
    
    for (i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
    return 0;
    /* C 언어 때와 for 문은 달라진 점이 없다. 그렇다면 C++ 에서 for 문을 이용해 1 부터 10 까지 더하는 문장은 어떻게 만드는 지 살펴보자. (아래의 예시 코드) */
}


/* C++ 을 이용해 1 부터 10 까지의 합을 구하는 코드 */
#include <iostream>
int main() {
    int i, sum = 0;

    for (i = 1; i <= 10; i++) {
        sum += i;
    }
    std::cout << "합은 : " << sum << std::endl;
    return 0;
    /* 해당 코드를 봤을 때 역시 for 문은 C++ 과 C 언어가 동일한 형태로 사용한다. 
    한 가지 달라진 점은, C++ 에서는 변수의 선언이 반드시 최상단에 있어야 하는 것은 아니다. */
}

/* C 언어 예시-변수를 최상단에 정의 */
int i, sum = 0;

for (i = 1; i <= 10; i++) {
    sum += i;
}


/* C 언어에서는 변수의 선언을 항상 코드의 최상단에 위치시켜야 했다. 
하지만 C++ 에서는 변수를 사용하기 직전 어느 위치에서든지 변수를 선언할 수 있게 된다. */

/* 변수는 변수 사용 직전에 선언해도 된다. */
#include <iostream>
int main() {
    int sum = 0;

    for (int i = 1; i <= 10; i++) {
        sum += i;
    }

    std::cout << "합은 : " << sum << std::endl;
    return 0;
    /* 해당 코드를 컴파일하면 C 언어 때와 동일한 결과를 보여준다. */
}


/* while 문 이용하기 */
#include <iostream> 
int main() {
    int i = 1, sum = 0;

    while (i <= 10) {
        sum += i;
        i++;
    }

    std::cout << "합은 : " << sum << std::endl;
    return 0;
    /* 해당 코드를 성공적으로 컴파일했다면 우리가 기존에 알고 있었던 (C 언어) while 문과 동일한 결과를 나타낸다. 
    C++ 에서 if-else 문 역시 C 와 동일한 문법 구조로 되어 있다. (아래의 예제 코드 참고) */
}


/* 행운의 숫자 맞추기-if else 문 사용 예제 */
#include <iostream>

int main() {
    int lucky_number = 3;
    std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;  /* cout 은 << 를 이용하여 출력을 시킨다. */

    int user_input;  // 사용자 입력

    while (1) {
        std::cout << "입력 : ";
        std::cin >> user_input;  /* cin 은 사용자로부터 입력을 받아서 >> 를 통해 user_input 에 넣는다. 
        cin 도 마찬가지로 std 에 정의되어 있기 때문에 std::cin 과 같이 사용해야 한다. */
        /* 또한, C 언어에서 scanf 는 & 를 붙였는데 C++ 에서는 편리하게도 앞에 & 연산자를 붙일 필요가 없다. 
        심지어, scanf 에서는 int 형태로 입력받을 지 아니면 char 인지에 따라서 %d 냐 %c 냐로 구분하였는데 
        여기서는 그냥 변수를 보고 cin 이 알아서 처리해주어 매우 편리하다. */
        if (lucky_number == user_input) {
            std::cout << "맞추셨습니다~~" << std::endl;
            break;
        } else {
            std::cout << "다시 생각해보세요~" << std::endl;
        }
    }
    return 0;
}


/* switch 문 */
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int user_input;
    cout << "저의 정보를 표시해줍니다." << endl;
    cout << "1. 이름" << endl;
    cout << "2. 나이" << endl;
    cout << "3. 성별" << endl;
    cin >> user_input;

    switch (user_input)
    {
    case 1 /* constant-expression */:
        /* code */
        cout << "Psi ! " << endl;
        break;
    case 2 /* constant-expression */:
        /* code */
        cout << "99 살" << endl;
        break;
    case 3 /* constant-expression */:
        /* code */
        cout << "남자" << endl;
        break;

    default:
        cout << "궁금한 게 없군요~!!" << endl;
        break;
    }

    return 0;
}


/* 참조자의 도입 */
#include <iostream>

int change_val(int *p) {
    *p = 3;

    return 0;
}
int main() {
    int number = 5;

    std::cout << number << std::endl;
    change_val(&number);  /* change_val 함수의 인자 p 에 number 의 주소값을 전달하여, *p 를 통해 number 를 참조하여 number 의 값을 5 에서 3 으로 바꾸었다. */
    std::cout << number << std::endl;
    /* C 언어에서는 어떠한 변수를 가리키고 싶을 때는 반드시 포인터를 사용해야만 했다. 
    그런데 C++ 에서는 다른 변수나 상수를 가리키는 방법으로 또다른 방식을 제공하는데, 이를 바로 '참조자(레퍼런스-reference)' 라고 부른다. */
}


#include <iostream>

int main() {
    int a = 3;  /* 우선 int 형 변수인 a 를 정의하고, 그 안에 3 이란 값을 넣었다. */
    int& another_a = a;  /* 그 후에 a 의 참조자 another_a 를 정의하였다. 
    (참조자를 정하는 방법은, 가리키고자 하는 타입 뒤에 & 를 붙이면 된다. 위처럼 int 형 변수의 참조자를 만들고 싶을 때에는 int& 를 , double 의 참조자를 만들려면 double& 로 하면 된다. 
    심지어 int* 와 같은 포인터 타입의 참조자를 만들려면 int*& 라고 쓰면 된다.) 
    
    위와 같이 선언함으로써 우리는 another_a 는 a 의 참조자다! 라고 공표하게 되었다. 이 말은 즉슨 another_a 는 a 의 또다른 이름이라고 컴파일러에게 알려주는 것이다. 
    따라서 another_a 에 어떠한 작업을 수행하든 이는 사실상 a 에 그 작업을 하는 것과 동일하다. */

    another_a = 5;  /* 따라서 위처럼 another_a 에 5 를 대입하였지만 실제로 a 의 값을 확인해보면 5 로 바뀌었음을 확인할 수 있다. */
    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;

    return 0;
}


/* 어떻게 보면 참조자와 포인터는 상당히 유사한 개념이다. 포인터 역시 다른 어떤 변수의 주소값을 보관함으로써 해당 변수에 간접적으로 연산을 수행할 수 있기 때문이다. 
하지만 레퍼런스와 포인터에는 몇 가지 중요한 차이점이 존재한다. 

1. 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다. 
따라서 int& another_a; 와 같은 문장은 불가능하다. (반면, 포인터의 경우 int* p; 는 전혀 문제없는 코드이다.) 

2. 레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다. 
레퍼런스의 또 한 가지 중요한 특징은 한 번 어떤 변수의 참조자가 되어버린다면, 더이상 다른 변수를 참조할 수 없게 된다는 것이 있다. 
예를 들어
int a = 10;
int &another_a = a; // another_a 는 이제 a 의 참조자!!

int b = 3;
another_a = b; // ??
와 같은 코드를 살펴보자. 마지막에 another_a = b; 문장은 another_a 보고 다른 변수인 b 를 가리키라는 의미가 아니다. 
이는 그냥 a 에 b 의 값을 대입하라는 의미이다. 
앞서 말했듯이 another_a 에 무언가를 하는 것은 사실상 a 에 무언가를 하는 것과 동일하므로 이 문장은 그냥 a = b 와 동치이다. 
(참고로 &another_a = b; 라는 문장은 그냥 &a = b; 가 되어서 말이 안되는 문장이다.) 
반면에 포인터는 
int a = 10;
int* p = &a; // p 는 a 를 가리킨다.

int b = 3;
p = &b // 이제 p 는 a 를 버리고 b 를 가리킨다. 
위의 코드와 같이 포인터는 누구를 가리키는지 자유롭게 바뀌는 것이 가능하다. 

3. 레퍼런스는 메모리 상에 존재하지 않을 수도 있다. 
포인터의 경우, 우리가 아래와 같이 포인터 p 를 정의한다면 
int a = 10;
int* p = &a; // p 는 메모리 상에서 당당히 8 바이트를 차지하게 된다. 
p 는 당당히 메모리 상에서 8 바이트를 차지하는 녀석이 된다. (물론 32비트 시스템에서는 4 바이트겠지.) 
그런데 러퍼런스의 경우를 생각해보면
int a = 10;
int &another_a = a; // another_a 가 자리를 차지할 필요가 있을까?? 
만일 내가 컴파일러라면 another_a 를 위해서 메모리 상에 공간을 할당할 필요가 있을까?? 아니다. 
왜냐하면 another_a 가 쓰이는 자리는 모두 a 로 바꿔치기 하면 되기 때문이다. 따라서 이 경우 레퍼런스는 메모리 상에 존재하지 않게 된다. 
(물론 그렇다고 해서 항상 존재하지 않는 것은 아니다!!--> 아래의 예시 참고) */


/* 함수 인자로 레퍼런스 받기 */
#include <iostream>
int change_val(int &p) {  /* 함수의 인자로 참조자(=레퍼런스) 를 받게 하였다. 
여기서 
"아까 int& p 는 안된다고 하지 않았나요?" 라고 물을 수 있는데,
사실 p 가 정의되는 순간은 change_val(number) 로 호출할 때이므로 사실상 int& p = number 가 실행된다고 생각하면 된다. 따라서 전혀 문제가 없다. */
    p = 3;

    return 0;
}
int main() {
    int number = 5;

    std::cout << number << std::endl;
    change_val(number);  /* 아무튼 위와 같이 참조자 p 에게 '너는 앞으로 number 의 새로운 별명이야' 라고 알려주게 된다. 
    중요한 점은 포인터가 인자일 때와는 다르게 number 앞에 & 를 붙일 필요가 없다는 점이다. (이는 참조자를 정의할 때 그냥 int& a = b 와 같이 한 것과 일맥상통한다.) 
    그 후 change_val 안에서 p = 3; 이라 하는 것은 main 함수의 numver 에 number = 3; 을 하는 것과 정확히 동일한 작업이다. */
    std::cout << number << std::endl;

}


/* 여러가지 참조자 예시들 */
// 참조자 이해하기 
#include <iostream>
int main() {
    int x;
    int& y = x;  /* x 의 참조자로 y 를 정의하였다. 
    따라서 y 는 x 의 또다른 별명이 된다. */
    int& z = y;  /* z 역시 x 의 참조자가 된다. 
    따라서, y 와 z 둘 다 x 의 참조자가 된다. */

    x = 1;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    y = 2;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    z = 3;
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

    /* 결과적으로 위 문장들은 모두 1, 1, 1 과 2, 2, 2 와 3, 3, 3 을 출력한다. 
    
    처음 참조자를 접하는 사용자들은 왜 굳이 포인터로 할 수 있는 것을 참조자로 해야 하는지 의문을 가질 수 있다. 
    참조자를 사용하게 되면 불필요한 & 와 * 가 필요없기 때문에 코드를 훨씬 간결하게 나타낼 수 있다는 이점이 있기 때문이다. 
    예를 들어 지난 강좌에서 변수 입력 시 배웠던 cin 을 기억하고 있다면, 사용자로부터 변수에 값을 입력받을 때 아래와 같이 했을 것이다.
    std::cin >> user_input;
    그런데 무언가 이상하다고 생각할 수 있다. 예전에 scanf 로 이용할 때 분명히 
    scanf("%d", &user_input);
    와 같이 항상 주소값을 전달해 주었는데 말이다. 왜냐하면 어떤 변수의 값을 다른 함수에서 바꾸기 위해서는 항상 포인터로 주소값을 전달해야 하기 때문이다. 
    하지만 여기서는 cin 이라는 것에 그냥 user_input 을 전달했는데 잘 작동한다. 
    그 이유는 바로 cin 이 레퍼런스로 user_input 을 받았기 때문이다. 따라서 굳이 & 를 user_input 앞에 붙일 필요가 없게 되는 것이다. */

}


/* 상수에 대한 참조자 */
#include <iostream>
int main() {
    int &ref = 4;

    std::cout << ref << std::endl;
    /* 해당 코드는 오류가 발생한다. 
    그 이유는 4 라는 상수 값 자체는 리터럴이기 때문이다. 만일 위와 같이 레퍼런스로 참조한다면 ref = 5; 로 리터럴의 값을 바꾸는 말도 안되는 행위가 가능하게 된다. 
    따라서 C++ 문법 상 상수 리터럴을 일반적인 레퍼런스가 참조하는 것은 불가능하게 되어 있다. 
    물론 그 대신에 const int &ref = 4; 와 같이 상수 참조자로 선언한다면 리터럴도 참조할 수 있다. 
    따라서 int a = ref; 는 a = 4; 라는 문장과 동일하게 처리된다. */

    /* 리터럴(literal) : 숫자나 스트링 같은 '값'을 의미한다. 데이터 그 자체를 의미하는 말로, 변수에 넣는 '변하지 않는 데이터'를 의미한다. 
    따라서 일반적으로 상수가 많이 나오기는 하지만, 항상 상수가 리터럴인 것은 아니다. 
    상수: 변하지 않는 변수(메모리 위치 or 메모리 값을 변경할 수 없다.) vs. 리터럴: 변수의 값이 변하지 않는 데이터(메모리 위치 안의 값) */
}



/* 레퍼런스의 배열과 배열의 레퍼런스 */
/* 레퍼런스의 배열이 과연 가능한 것인지에 대해 생각해보자. 앞서 말했듯이 레퍼런스는 반드시 정의와 함께 초기화를 해주어야 한다.
따라서 여러분의 머리속에는 다음과 같이 레퍼런스의 배열을 정의하는 것을 떠올렸을 것이다. */
int a, b;
int& arr[2] = {a, b};
/* 바로 위의 코드를 컴파일하면 오류가 발생한다. 오류를 살펴보면 레퍼런스의 배열을 '불법' 이라고 말하고 있다. 
오류인 이유는 C++ 상에서 배열이 어떤 식으로 처리되는지와 관련이 있다. 문법 상 배열의 이름은 (arr) 첫 번째 원소의 
주소값으로 변환이 될 수 있어야 한다. 이 때문에 arr[1] 과 같은 문장이 *(arr + 1) 로 바꾸어서 처리될 수 있기 때문이다. 
그런데 주소값이 존재한다는 의미는 '해당 원소가 메모리 상에서 존재한다' 는 의미와 동일하다. 따라서 이러한 모순 때문에 
레퍼런스들의 배열을 정의하는 것은 언어 차원에서 금지가 되어 있는 것이다. 
그렇다고 해서 그 반대인 '배열들의 레퍼런스' 가 불가능한 것은 아니다. (예시는 아래 코드.) */



#include <iostream>
int main() {
    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;  /* ref 가 arr 를 참조하도록 하였다. 
    따라서 ref[0] 부터 ref[2] 가 각각 arr[0] 부터 arr[2] 의 레퍼런스가 된다. 포인터와는 다르게 배열의 레퍼런스인 경우, 참조하기 위해서는 반드시 배열의 크기를 명시해야 한다. 
    따라서 int (&ref)[3] 이라면 반드시 크기가 3 인 int 배열의 별명이 되어야 하고 int (&ref)[5] 라면 크기가 5 인 int 배열의 별명이 되어야 한다. 
    int arr[3][2] = {1,2,3,4,5,6};
    int (&ref)[3][2] = arr;
    역시 일차원 배열을 했을 때와 동일하다. */

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}


/* 레퍼런스를 리턴하는 함수 */
int function() {
    int a = 2;
    return a;
}
int main() {
    int b = function();  /* function 안에 정의된 a 라는 변수의 값이 b 에 '복사'되었다.
    function 이 종료되고 나면 a 는 메모리에서 사라지게 된다. 따라서 더이상 main 안에서는 a 를 만날 길이 없다.  */
    return 0;
}


/* 지역변수의 레퍼런스를 리턴?? */
int& function() {  /* function 의 리턴 타입은 int& 이다. 따라서 참조자를 리턴하게 된다. 
그런데 문제는 리턴하는 function 안에 정의되어 있는 a 는 함수의 리턴과 함께 사라진다는 점이다. */
    int a = 2;
    return a;
}
int main() {
    int b = function();  /* 해당 문장은 사실상 
    int& ref = a;
    // 근데 a 가 사라짐 
    int b = ref; // !!!!!
    와 같은 의미이다. function 이 레퍼런스를 리턴하면서 원래 참조하고 있던 변수가 이미 사라져버렸으므로 오류가 발생하게 된다. 
    쉽게 말해서 본체(a)는 이미 사라지고 별명(ref)만 남아 있는 상황이다. 
    이처럼 레퍼런스(별명) 는 있는데 원래 참조하던 본체가 사라진 레퍼런스를 '댕글링 레퍼런스(Dangling reference)' 라고 부른다. 
    어쨌든 위처럼 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심해야 한다. */
    b = 3;
    return 0;
    /* 해당 코드를 컴파일하게 되면 경고가 발생한다. (컴파일 오류는 아니다.)*/
}



/* 외부 변수의 레퍼런스를 리턴 */
int& function(int& a) {  /* 이 코드의 function 역시 레퍼런스를 리턴하고 있다. 하지만 위의 코드와의 차이점은, 
이 function 은 인자로 받은 레퍼런스를 그대로 리턴하고 있다는 점이다. 
function(b) 를 실행한 시점에서 a 는 main 의 b 를 참조하고 있게 된다. 따라서 function 이 리턴한 참조자는 아직 살아있는 변수인 b 를 계속 참조한다. */
    a = 5;
    return a;
}
int main() {
    int b = 2;
    int c = function(b);  /* 결국 해당 문장은 그냥 c 에 현재의 b 의 값인 5 를 대입하는 것과 동일한 문장이 된다. */
    return 0;
    /* 해당 코드와 같이 참조자를 리턴하는 경우의 장점은 출력 속도에 있다. 
    C 언어에서 엄청 큰 구조체가 있을 때 해당 구조체 변수를 그냥 리턴하면 전체 복사가 발생해야 해서 시간이 오래걸리지만, 
    해당 구조체를 가리키는 포인터를 리턴한다면 그냥 포인터 주소 한 번 복사로 매우 빠르게 끝난다. 
    마찬가지로 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관없이 딱 한 번의 주소값 복사로 전달이 끝나게 된다. (따라서 매우 효율적이라고 할 수 있다.) */
}



/* 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기 */
/* 이번에는 반대로 함수가 값을 리턴하는데 참조자로 받는 경우를 생각해보자. */
int function() {
    int a = 5;
    return a;
}
int main() {
    int& c = function();
    return 0;
    /* 해당 코드를 컴파일하면 컴파일오류가 발생한다. 그 이유는 상수가 아닌 레퍼런스가 function 함수의 리턴값을 참조할 수 없기 때문이다. 
    그 이유는 왤까??
    이는 위의 상황들과 마찬가지로 함수의 리턴값은 해당 문장이 끝난 후 바로 사라지는 값이기 때문에 참조자를 만들게 되면 바로 다음에 댕글링 레퍼런스가 
    되기 때문이다. */
}

/* 하지만 C++ 에서 중요한 예외 규칙이 있다. (아래 코드 참조) */
#include <iostream>

int function() {
    int a = 5;
    return a;
}
int main() {
    const int& c = function(); // const 는 constant 의 약자로, '상수' 를 의미한다. (값을 수정하거나 변경하는 것이 불가능하다.)
    /* function() 의 리턴값을 참조자로 받았다. 그런데, const 참조자로 받았더니 위의 코드와는 달리 문제없이 컴파일 되는 모습을 확인할 수 있다. 심지어 그 리턴값도 제대로 출력되었다. */
    std::cout << "c : " << c << std::endl;
    return 0;
    /* 원칙상 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상이다. 따라서 앞선 코드들을 보면 알 수 있듯이, int& 로 받았을 때는 컴파일 자체가 안되었따. 
    하지만 예외적으로 상수(const) 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장된다. (그 연장되는 기간은 레퍼런스가 사라질때까지이다.) */
}


/* 생각해보기-문제 */
/* 문제 1:
레퍼런스가 메모리 상에 반드시 존재해야 하는 경우에는 어떤 것들이 있을까?? 그리고 메모리 상에 존재할 필요가 없는 경우는 또 어떤 경우가 있을까??(난이도: 상) */



/* C 언어에서는 malloc 과 free 함수를 지원하여 힙(heap) 상에서의 메모리 할당을 지원하였다. ('힙' 은 프로그램 시에 자유롭게 주소값을 할당하고 해제할 수 있는 공간이다.)
C++ 에서도 마찬가지로 malloc 과 free 함수를 사용할 수 있다. 
하지만 언어 차원에서 지원하는 것은 바로 new 와 delete 라고 할 수 있다. new 는 말 그대로 malloc 과 대응되는 
것으로, 메모리를 할당한다.
delete 는 free 에 대응되는 것으로, 메모리를 해제한다. */

/* new 와 delete 의 사용 */
#include <iostream>
int main() {
    int* p = new int;  /* int 크기의 공간을 할당하여 그 주소값을 p 에 집어넣었음을 확인할 수 있다. 
    new 를 사용하는 방법은 
    (임의의 타입)* pointer = new (임의의 타입)
    형태이다. */
    *p = 10;  /* 이제 p 위치에 할당된 공간에 해당 코드를 통해서 값을 집어넣었다. 따라서 컴파일하면 10 이 출력된다. */

    std::cout << *p << std::endl;

    delete p;  /* 마지막으로 할당된 공간을 해제하기 위해서 delete 를 사용하였다.
    위와 같이 delete p 를 하게 되면 p 에 할당된 공간이 해제된다. 
    (물론 delete 로 해제할 수 있는 메모리 공간은 사용자가 new 를 통해서 할당한 공간만 가능하다.) */
    return 0;
}



/* 지역변수 delete 하기 */
#include <iostream>
int main() {
    int a = 5;
    delete &a;
    return 0;
    /* 해당 코드를 컴파일하면 완료되지 않는다. 
    만일 해당 코드처럼 지역변수를 무리하게 delete 로 해제해버리려 한다면 
    heap 이 아닌 공간을 해제하려고 한다는 경고 메세지가 뜬다. */
}


/* new 로 배열 할당하기 */
#include <iostream>
int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];  /* 배열의 크기를 잡을 arr_size 라는 변수를 정의하였고, 그 값을 입력받았다. 
    그리고 list 에 new 를 이용하여 크기가 arr_size 인 int 배열을 생성하였다. 
    배열을 생성할 때에는 [] 를 이용하여 배열의 ㅋ기를 넣어주면 되는데, 
    (임의의 타입)* pointer = new (임의의 타입)[size];
    형태로 사용하면 된다. 
    따라서 list 는 이제 크기가 arr_size 인 int 배열을 가지게 된다. */
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list;  /* 앞서 new[] 를 이용해서 할당하였으면 해제할 때는 delete[] 를 이용하면 된다. 
    즉 new - delete 가 짝을 이루고 new[] 와 delete[] 가 짝을 이루는 것이다. */
    return 0;
    /* 중요한 점은, C 언어에서는 변수의 선언을 모두 최상단에 몰아서 해야 했지만 C++ 은 그렇지 않다는 점이다. 
    C++ 에서는 편리하게도 소스의 아무데서나 변수를 선언할 수 있으며, 그 변수를 그 변수를 포함하고 있는 중괄호를 빠져나갈 때 소멸된다. */
}


/* 돌아온 마이펫 */
/* 전에 C 언어에서 switch 문을 배우면서 간단하게 만들어보았던 마이펫을 기억해보자. 
그 때 기억을 살려서 동물 관리 프로그램을 간단하게 만들어보고자 한다. 조건은 아래와 같다.
1) 동물(struct Animanl) 이라는 구조체를 정의해서 이름(char name[30]), 나이(int age), 체력(int health),
    배부른 정도(int food), 깨끗한 정도(int clean) 의 값을 가진다. 
2) 처음에 동물 구조체의 포인터 배열(struct Animal* list[30]) 을 만들어서 사용자가 동물을 추가할 때마다 하나씩 생성한다. 
3) play 라는 함수를 만들어서 동물의 상태를 변경하고 show_stat 함수를 만들어서 지정하는 동물의 상태를 출력한다. 
4) 1 턴이 지날 때마다 동물의 상태를 변경한다. 
*/

#include <iostream>
typedef struct Animal {
    char name[30]; // 이름
    int age; // 나이

    int health; // 체력
    int food; // 배부른 정도
    int clean; // 깨끗한 정도
} Animal;

void create_animal(Animal *animal) {
    std::cout << "동물의 이름? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal *animal) {
    // 하루가 지나면
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal *animal) {
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력   : " << animal->health << std::endl;
    std::cout << "배부름   : " << animal->food << std::endl;
    std::cout << "청결   : " << animal->clean << std::endl;
}

int main() {
    Animal *list[10];
    int animal_num = 0;

    for (;;) {
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기" << std::endl;
        std::cout << "3. 상태 보기" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);

                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀게?? : ";
                std::cin >> play_with;

                if (play_with < animal_num) play(list[play_with]);

                break;
            case 3:
                std::cout << "누구껄 보게?? : ";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(list[play_with]);
                break;
        }

        for (int i = 0; i != animal_num; i++) {
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}


/* 클래스(class) */
#include <iostream>
class Animal {  /* Animal 이라는 클래스를 나타낸 것으로 Animal 클래스를 통해서 생성될 임의의 객체에 대한 설계도라 볼 수 있다. */
/* 즉, Animal 클래스를 통해서 생성될 객체는 food, weight 라는 변수가 있고, set_animal, increase_food, view_stat 이라는 함수들이 있는데
Animal 클래스 상에서 이들을 지칭할 때 각각 멤버 변수(member variable) 과 멤버 함수(member function) 라고 부른다. 
다시 말하면 인스턴스로 생성된 객체에서는 인스턴스 변수, 인스턴스 함수, 그리고 그냥 클래스 상에서는 멤버 변수, 멤버 함수라고 부르는 것이다. 
멤버 변수와 멤버 함수는 실재하는 것이 아니다. 인스턴스가 만들어져야 비로소 세상에 나타나는 것이기 때문이다. (설계도 상에 있다고 해서 아파트가 실제로 존재하는 것이 아닌 것과 같다.) */
    private:  /* '접근 지시자' : 외부에서 멤버 변수(food, weight) 들에 접근을 할 수 있냐 없냐를 지시해주는 것이다. 따라서 접근 지시자 private 는 객체 밖에서 인위적으로 객체 변수들에 접근하는 것은 불가능함을 나타낸다. 
    private 과 반대되는 역할을 하는 것은 public 이다. public 의 경우, 외부에서 객체 변수를 마음대로 이용하는 것이 가능하다. 
    (참고로, 접근 지시자 명시를 하지 않았을 경우에는 기본적으로 private 로 설정된다. 따라서 private 를 생략한다고 하더라도 food 와 weight 는 알아서 private 로 설정된다. )*/
        int food;
        int weight;

    public:
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc) {
        food += inc;
        weight += (inc / 3);
    }
    void view_stat() {
        std::cout << "이 동물의 food  : " << food << std::endl;
        std::cout << "이 동물의 weight  : " << weight << std::endl;
    }
}; // 세미콜론 잊지 말자!!

int main() {
    Animal animal;  /* Animal 클래스의 인스턴스(=객체) animal 을 만들었다. */
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
    /* 해당 코드를 출력하면 
    이 동물의 food  : 130
    이 동물의 weight  : 60
    이라는 결과가 출력된다. */
}


/* 생각해볼문제-문제 */
/* 문제 1: 
여러분은 아래와 같은 Date 클래스를 디자인하려고 한다. SetDate 는 말 그대로 Date 함수 내부를 초기화하는 것이고 
AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 된다. 
한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요?? (난이도: 상) */
class Date {
    int year_;
    int month_;
    int day_;

    public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        void ShowDate();
}


/* 생성자와 함수의 오버로딩 */
/* 본격적으로 객체지향 프로그래밍을 시작하는 단계!!! */

/* 함수의 오버로딩(Overloading) */
/* 오버로드를 사전에서 찾아보면 뜻이 다음과 같다.
1) 과적하다.
2) sb(with sth) 너무 많이 주다[부과하다.]
3) (컴퓨터/전기 시스템 등에) 과부하가 걸리게 하다. 

그렇다면 함수의 오버로딩이라는 것은 '함수에 과부하는 주는 것' 인가 라는 생각도 들 것이다. 사실 맞는 말이다. 
C 언어에서는 하나의 이름을 가지는 함수를 딱 1 개밖에 존재할 수 없기에 과부하라는 말 자체가 성립이 안 됐다. 
printf 는 C 라이브러리에 단 한 개 존재하고 scanf 도 C 라이브러리에 단 1 개만 존재한다. 
하지만 C++ 에서는 같은 이름을 가진 함수가 여러 개 존재하는 것이 가능하다. 즉, 함수의 이름에 과부하가 걸려도 상관이 없다는 말이다. 
그렇다면 C++ 에서는 같은 이름의 함수를 호출했을 때 어떻게 구분하는 것일까?? 이는 함수를 호출했을 때 사용하는 인자를 보고 결정하게 된다.
*/

/* 함수의 오버로딩 */
#include <iostream>
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);  /* 이름이 print 인 함수 3 개가 정의되었다. */
    /* 고전 C 컴파일러에서는 오류가 발생했겠지만 C++ 에서는 함수의 이름이 같더라도 인자가 다르면 다른 함수라고 판단하기 때문에 오류가 발생하지 않는 것이다. */
    print(b);
    print(c);

    return 0;
    /* 해당 함수에서 눈여겨볼 점은 a 는 int, b 는 char, c 는 double 타입이라는 것인데, 
    이에 따라 각각의 타입에 맞는 함수들, 예를 들어 print(b) 는 b 가 char 이므로 char 형의 인자를 가지는 
    두 번째 print 가 호출된 것이다. */

    /* C 언어였을 경우 int, char, double 타입에 따라 함수의 이름을 제각각 다르게 만들어서 호출해주어야 했던 반면, 
    C++ 에서는 컴파일러가 알아서 적합한 인자를 가지는 함수를 찾아서 호출해주게 된다. */
}



/* 함수의 오버로딩-2 */
#include <iostream>
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }
/* 해당 함수는 조금 특이한 경우이다. int 타입의 인자나 double 타입의 인자를 하나 받는 함수 하나밖에 없다. 
하지만 main 에서 각기 다른 타입의 인자들 (int, char, double) 로 print 함수를 호출하게 된다. 
물론 a 나 c 의 경우 각자 자기를 인자로 하는 정확한 함수들이 있어서 성공적으로 호출되는 것이 가능하지만, 
char 의 경우 자기와 정확히 일치하는 인자를 가지는 함수가 없기 때문에 '자신과 최대로 근접한 함수' 를 찾게 된다. */

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);  
    print(b);  /* 1 단계에서는 명백하게도 char 타입의 인자를 가진 print 가 없기에 2 단계로 넘어오게 된다. 
    그런데 2 단계에서는 char 이 int 로 변환된다면 print (int x) 를 호출할 수 있기 때문에 결국 print (int x) 가 호출되게 된다. */
    print(c);

    return 0;
    /* 해당 코드를 출력하면
    int : 1
    int : 99
    double : 3.2 
    가 결과로 출력된다. */
}

/* C++ 컴파일러에서 함수를 오버로딩하는 과정은 다음과 같다. 
    1단계 : 자신과 타입이 정확히 일치하는 함수를 찾는다. 
    2단계 : 정확히 일치하는 타입이 없는 경우, 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
        1) Char, unsigned char, short 는 int 로 변환된다. 
        2) Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다. 
        3) Float 은 double 로 변환된다. 
        4) Enum 은 int 로 변환된다. 
    3단계 : 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀 더 포괄적인 형변환을 통해 일치하는 함수를 찾는다. 
        1) 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)
        2) Enum 도 임의의 숫자 타입으로 변환된다. (예를 들어 Enum -> double)
        3) 0 은 포인터 타입이지만, 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다. 
        4) 포인터는 void 포인터로 변환된다. 
    4단계 : 유저 정의된 타입 변환으로 일치하는 것을 찾는다. (이 부분에 대해서는 나중에 설명한다!!)
            만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우에 
            '모호하다(ambigunous)' 라고 판단해서 오류를 발생하게 된다. */



/* 모호한 오버로딩 */
#include <iostream>
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "double : " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);

    return 0;
    /* 해당 코드를 컴파일하면 오류가 발생한다. 
    일단 해당 코드에서는 함수가 print (int x) 와 print (char x) 밖에 없으므로 관건은 print(c); 를 했을 때 어떠한 함수가 호출되어야 하는지 결정하는 것이다.
    print(c) 를 했을 때 1 단계에서는 명백하게 일치하는 것이 없다. 
    2 단계에서는 마찬가지로 double 의 캐스팅에 관련한 내용이 없기에 일치하는 것이 없어서 마침내 3 단계로 넘어오게 된다. 
    3 단계에서는 '임의의 숫자 타입이 임의의 숫자 타입' 으로 변환되어서 생각되기 때문에 double 은 char 도, int 도 변환할 수 있게 되는 것이다. 
    따라서 같은 단계에 두 개 이상의 가능한 일치가 존재하므로 출력 오류가 발생하게 된다. 
    
    위와 같은 C++ 오버로딩 규칙을 머리속에 숙지하는 것이 매우 중요하다. */
}


/* Date 클래스 */
#include <iostream>

class Date {
    int year_;
    int month_; // 1 부터 12 까지
    int day_;  // 1 부터 31 까지

    public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        int GetCurrentMonthTotalDays(int year, int month);
        void ShowDate();
};

void Date::SetDate(int year, int month, int day) {  /* Date:: 을 함수의 이름 앞에 붙여주게 되면, 해당 함수가 "Date 클래스의 정의된 함수" 라는 의미를 부여하게 된다. */
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_day[month - 1];
    } else if (year %4 == 0 && year % 100 != 0) {
        return 29; // 윤년
    } else {
        return 28;
    }
}

void Date::AddDay(int inc) {
    while (true) {
        // 현재 달의 총 일 수 
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        // 같은 달 안에 들어온다면;
        if (day_ + inc <= current_month_total_days) {
            day_ += inc;
            return;
        } else {
            // 다음달로 넘어가야 한다. 
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc) {
    AddYear((inc + month_ - 1) / 12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }
void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_
                << " 일 입니다." << std::endl;
}

int main() {
    Date day;  /* main 함수를 살펴보면, 위처럼 day 인스턴스를 생성해서 SetDate 로 초기화 한 다음에 ShowDate 로 내용을 한 번 보여주고, 
    또 AddDay 을 해서 30 일을 증가시킨 뒤 다시 새로운 날짜를 출력하도록 하였다. 
    여기서 가장 중요한 부분은 처음의 SetDate 부분이다. 만일 SetDate 를 하지 않았더라면 초기화되지 않은 값들에 덧셈과 출력 명령이 내려져서 이상한 쓰레기 값이 출력되게 된다. 
    그런데 문제는 이렇게 SetDate 함수를 사람들이 꼭 뒤에 써주지 않는다는 것이다. 
    C++ 에서는 이를 언어 차원에서 도와주는 장치가 있는데, 바로 '생성자(constructor) 이다. */
    day.SetDate(2011, 3, 1);
    day.ShowDate();

    day.AddDay(30);
    day.ShowDate();

    day.AddDay(2000);
    day.ShowDate();

    day.SetDate(2012, 1, 31); // 윤년
    day.AddDay(29);
    day.ShowDate();

    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();
    return 0;
}


/* 생성자(constructor) */
#include <iostream>

class Date {
    int year_;
    int month_;  // 1 부터 12 까지
    int day_;  // 1 부터 31 까지

    public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    // 해당 월의 총 일 수를 구한다. 
    int GetCurrentMonthTotalDays(int year, int month);

    void ShowDate();

    Date(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

// 생략

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_ << " 일 입니다." << std::endl;
}
int main() {
    Date day(2011, 3, 1);
    day.ShowDate();

    day.AddYear(10);
    day.ShowDate();

    return 0;
    /* 생성자는 기본적으로 "객체 생성시 자동으로 호출되는 함수" 라고 볼 수 있다. 이때 자동으로 호출되면서 객체를 초기화해주는 역할을 담당하게 된다. 
    생성자는 아래와 같이 정의한다. 
    // 객체를 초기화하는 역할을 하기 때문에 리턴값이 없다!! 
    클래스 이름(인자) {} 
    예를 들어, Date 의 생성자를 정의하면
    Date(int year, int month, int day) 
    로 정의하는 것이 가능하다. 이는 곧 Date 클래스의 day 객체를 만들면서 생성자 Date(int year, int month, int day) 를 호출한다는 의미가 된다.
    Date day(2011, 3, 1);   // 암시적 방법(implicit)
    Date day = Date(2012, 3, 1);  // 명시적 방법(explicit) 
    */
}


/* 디폴트 생성자(Default constructor) */
/* 처음에 생성자 정의를 하지 않은 채로 Date day; 를 했을 때, 과연 생성자가 호출될까?? 만약 호출된다면 어떤 생성자가 호출되는 것일까??
우선, 생성자는 호출된다. 이때 호출되는 생성자는 '디폴트 생성자(default constructor)' 이다. 
디폴트 생성자는 인자를 하나도 가지지 않는 생성자인데, 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자이다. 
(물론 컴파일러가 자동으로 생성할 때에는 아무런 일도 하지 않게 된다. 그렇기에 맨처음에 SetDate 를 하지 않았을 때 쓰레기 값이 나왔던 것이다.) */

/* 당연히 우리가 직접 디폴트 생성자를 정의하는 것도 가능하다. (아래의 예시 코드 참조) */
// 디폴트 생성자 정의해보기
#include <iostream>

class Date {
    int year_;
    int month_;  // 1 부터 12 까지
    int day_;  // 1 부터 31 까지

    public:
    void ShowDate();

    Date() {  /* 디폴트 생성자를 정의하였다. 
    year 에는 2012, month 에는 7, day 에는 2 를 대입한다. */
        year_ = 2012;
        month_ = 7;
        day_ = 12;
    }
};

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_
                << " 일 입니다." << std::endl;
}

int main() {
    Date day = Date();  /* 위에서 디폴트 생성자를 정의하였으므로, 해당 디폴트 생성자를 이용해서 day 와 day 2 를 추가할 수 있게 되는 것이다. 
    한 가지 주의할 점은 인자가 있는 생성자에서 적용했던 것처럼 
    Date day3(); 
    을 하면 day 3 객체를 디폴트 생성자를 이용해서 초기화하는 것이 아니라, 리턴값이 Date 이고 인자가 없는 함수 day 3 을 정의하게 된 것으로 인식한다. 
    이는 '암시적 표현' 으로, 객체를 선언할 때 반드시 주의해 두어야 할 사항이다. */
    Date day2;

    day.ShowDate();
    day2.ShowDate();

    return 0; 
    /* 주의 : 절대로 인자가 없는 생성자를 호출하게 위해서 A a() 처럼 하면 안 된다. 해당 문장은 A 를 리턴하는 함수 a 를 정의한 문장이다. 
    반드시 그냥 A a 와 같은 형태로 호출해야 한다. */
}


/* 명시적으로 디폴트 생성자 사용하기 */
class Test {
    public:
    Test() = default;   // 디폴트 생성자를 정의해라. 
    /* 바로 위처럼 생성자의 선언 바로 뒤에 = default 를 붙여준다면, Test 의 디폴트 생성자를 정의하라고 컴파일러에게 명시적으로 알려줄 수 있다. */
};


/* 생성자 오버로딩 */
/* 앞서 함수의 오버로딩에 대해서 잠깐 짚고 넘어갔는데, 생성자 역시 함수이다.
따라서 생성자도 마찬가지로 함수의 오버로딩이 적용될 수 있다. 
쉽게 말해서 해당 클래스의 객체를 여러가지 방식으로 생성할 수 있게 된다. */
#include <iostream>
class Date {
    int year_;
    int month_;
    int day_;

    public:
        void ShowDate();
        
        Date() {
            std::cout << "기본 생성자 호출!!" << std::endl;
            year_ = 2012;
            month_ = 7;
            day_ = 12;
        }

        Date(int year, int month, int day) {
            std::cout << "인자 3 개인 생성자 호출!!" << std::endl;
            year_ = year;
            month_ = month;
            day_ = day;
        }
};

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_
                << " 일 입니다." << std::endl;
}
int main() {
    Date day = Date();
    Date day2(2012, 10, 31);

    day.ShowDate();
    day2.ShowDate();

    return 0;
    /* 해당 코드에서 생성자는 Date 이다. */
}

/* 생각해보기-문제 */
/* 문제 1: 
Date 클래스에 여러가지 생성자들을 추가해보세요. (난이도 : 하) */
/* 문제 2:
수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다. 중학생용 기하학 소프트웨어를 
만드는 것인데요, 클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 다른 하나는 
Geometry 로 점들을 가지고 연산을 하는 클래스입니다. 즉, 아래와 같은 두 클래스의 함수들을 모두 정의하세요. (난이도: 상) */
class Point {
    int x, y;

    public:
    Point(int pos_x, int pos_y);
};

class Geometry {
    // 점 100 개를 보관하는 배열.
    Point* point_array[100];

    public:
    Geometry(Point **point_list);
    Geometry();

    void AddPoint(const Point &point);

    // 모든 점들 간의 거리를 출력하는 함수입니다.
    void PrintDistance();

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x, y) = ax + by + c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x, y) = 0 을 기준으로 
    // 서로 다른 부분에 있을 족너은 f(x1, y1) * f(x2, y2) <= 0  이면 됩니다.
    void PrintNumMeets();
};


/* 복사 생성자와 소멸자 */

/* 스타크래프트 만들기-마린 */
#include <iostream>
class Marine {
    int hp;  // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    int damage;  // 공격력
    bool is_dead;  // true 또는 false 로 정해지는 값을 가질 수 있는 객체(??)

    public:
    Marine();  // 기본 생성자
    Marine(int x, int y);  // x, y 좌표에 마린 생성

    int attack();  // 데미지를 리턴한다. 
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);  // 새로운 위치

    void show_status();  // 상태를 보여준다. 
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);  // Marine 객체 2 개(marine1, marine2) 를 생성하였다. 
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    /* 해당 코드에는 약간의 문제가 있다. 
    만약 실제 게임과 유사하게 수십 마리의 마린들이 서로 뒤엉켜 싸우기라도 한다면, 
    해당 코드와 같이 marine1, marine2, ... 로 일일이 이름 붙이기도 어려울 뿐더러, 
    사용자가 몇 개의 마린을 만들겠다고 컴파일 시점에 정하는 것도 아니기 때문에 수십개의 marine1, marine2, ... 를 
    미리 만들수도 없는 격이다. 그럼 어떡할까?? 답은 단순하다. 
    marine 들을 배열로 정하면 된다. (아래의 코드 참조) */
}


/* 스타크래프트 만들기-'배열' 이용한 마린 만들기 */
/* int main 전까지 내용은 동일!! */
#include <iostream>
class Marine {
    int hp;  // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    int damage;  // 공격력
    bool is_dead;  // true 또는 false 로 정해지는 값을 가질 수 있는 객체(??)

    public:
    Marine();  // 기본 생성자
    Marine(int x, int y);  // x, y 좌표에 마린 생성

    int attack();  // 데미지를 리턴한다. 
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);  // 새로운 위치

    void show_status();  // 상태를 보여준다. 
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}

int main() {
    Marine* marines[100];
    marines[0] = new Marine(2, 3);  /* new 의 경우, 객체를 동적으로 생성하면서 동시에 자동으로 생성자도 호출해준다. (C 언어에서 사용하는 malloc 과의 차이점이다.)
    해당 부분을 보면 Marine(2, 3) 과 Marine(3, 5) 라는 생성자를 자동으로 호출해주는 것을 확인할 수 있다. 이것이 바로 C++ 에 맞는 새로운 동적 할당이라고 볼 수 있다. */
    marines[1] = new Marine(3, 5);

    marines[0]->show_status();  /* 물론 Marine 들의 포인터를 가리키는 배열이기 때문에 메소드를 호출할 때 . 이 아니라 -> 를 사용해주어야 한다. */
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];  /* 마지막으로, 동적으로 할당한 메모리는 항상 해제해주어야 한다는 원칙에 따라서 delete 를 해주어야 한다. (new-delete 는 세트!!) */
    delete marines[1];

    /* 이전에 new 와 delete 에 대해서 배울 때 malloc 과의 차이점에 관해서 잠깐 언급했던 것이 기억나는지 확인해보자. 
    그때는 아직 내용을 다 배우지 못해서 new 와 malloc 모두 동적으로 할당하지만 '무언가' 다르다고 했었는데, 
    해당 코드에서 아마 눈치챘을 수 있었을 것이라고 생각한다. 
    바로 new 의 경우, 객체를 동적으로 생성하면서 동시에 자동으로 생성자도 호출해준다는 점이다. */
}


/* 소멸자(Destructor) */
/* 알고 보니 각각의 마린에도 이름을 지정할 수 있었다. 그래서 우리가 만들어놓은 Marine 클래스에 name 이라는 이름을 지정할 수 있는 또다른 인스턴스 변수를 추가하도록 하자. */

// 마린의 이름 만들기
#include <string.h>

#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name; 

    public:
    Marine();
    Marine(int x, int y, const char* marine_name);
    Marine(int x, int y);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
    /* 해당 코드에서 name 에 우리가 생성하는 마린의 이름을 넣어줄 때, name 을 동적으로 생성해서 문자열을 복사하였는데,
    이렇게 동적으로 할당된 char 배열에 대한 delete 는 언제 이루어지는 것일까?? 
    
    슬프게도, 우리가 명확히 delete 를 지정하지 않는 한 자동으로 delete 가 되는 경우는 없다. 
    다시 말해서, 우리가 동적으로 할당했던 저 name 은 영원히 메모리 공간 속에서 둥둥 떠다닌다는 말이다. 사실 이러한 데이터는
    몇 바이트밖에 되지는 않지만 위와 같은 name 들이 쌓이고 쌓이게 되면 '메모리 누수(Memory Leak)' 라는 문제점이 발생하게 된다. 
    만일 main 함수 끝에서 Marine 이 delete 될 때, 즉 우리가 생성했던 객체가 소멸될 때 자동으로 호출되는 함수-마치 객체가 생성될
    때 자동으로 호출되었던 생성자처럼 소멸될 때 자동으로 호출되는 함수가 있다면 얼마나 좋을까?? 
    따라서 C++ 에서는 이 기능을 '소멸자(Destructor)' 을 통해서 지원하고 있다. */
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!! " << std::endl;  
    /* std::endl은 줄바꿈 문자(즉, \n)와 비슷한 역할을 합니다. 
    하지만 추가적으로 출력 버퍼를 비우는(flush) 작업도 함께 수행합니다. 
    이 버퍼 비우기는 출력 내용을 즉시 화면에 표시하도록 보장합니다.
    코드에서 두 번 사용된 이유는 메시지 앞뒤로 줄바꿈을 추가하기 위해서입니다. */

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}


/* 소멸자(Destructor)-예시 코드 */
#include <string.h>

#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
    Marine();
    Marine(int x, int y, const char* marine_name);
    Marine(int x, int y);
    ~Marine();

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    void show_status();
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}
Marine::~Marine() {  /* 소멸자 사용!! */
/* 생성자가 클래스 이름과 똑같이 생겼다면 소멸자는 그 앞에 ~ 만 붙여주면 된다. 
형태 : ~(클래스의 이름)
Marine 클래스의 소멸자의 경우, ~Marine(); 의 형태를 가지고 있다. 
소멸자와 생성자의 차이점은, 소멸자는 아무것도 가지지 않는다는 것이다. 소멸하는 객체에 인자를 넘겨봤자 쓸모없는 행위이기 때문이다. 
다시 말해, 소멸자는 오버로딩도 되지 않는다. */
    std::cout << name << " 의 소멸자 호출!! " << std::endl;
    if (name != NULL) {
        delete[] name;  /* name 이 NULL 이 아닐 경우에 (즉 동적으로 할당이 되었을 경우에) 만 delete 로 nanme 을 삭제하는 것을 알 수 있다. 
        참고로 name 자체가 char 의 배열로 동적할당 하였기 때문에 delete 역시 delete [] name, 즉 [] 를 꼭 써주어야 한다. */
    }
}
int main() {
    Marine* marines[100];
    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];  /* 객체가 소멸될 때 소멸자가 호출된다고 출력하도록 했는데, 
                        실제로 위 코드가 실행 시 소멸자 호출 메세지가 뜬다는 것을 확인할 수 있다.(아래의 예시 코드 참고) */
    delete marines[1];
}


/* 소멸자 호출 확인하기-95p */
#include <string.h>
#include <iostream>

class Test {
    char c;  /* 생성자와 소멸자 호출 시 어떤 객체의 것이 호출되는지 확인하기 위해 char c 를 도입하였다. */
    /* 클래스 Test 를 정의하고, 해당 클래스는 char 형 멤버 변수 c 를 가지고 있음을 보여준다. 이 변수(= c) 는 객체가 생성될 때 전달된 문자로 초기화된다. */

    public:
    Test(char _c) {  /* 생성자 Test(char _c) : 객체가 생성될 때 호출된다. 생성자 내부에서 c 를 초기화한 후, '생성자 호출' 메시지와 함께 c 의 값을 출력한다. */
        c = _c;
        std::cout << "생성자 호출" << c << std::endl;
    }
    ~Test() { std::cout << "소멸자 호출" << c << std::endl; }  /* 소멸자 ~Test() : 객체가 소멸될 때 호출된다. 소멸자 내부에서 '소멸자 호출' 메시지와 함께 c 의 값을 출력한다. */
};
void simple_function() { Test b('b'); }  /* 해당 void 함수는 Test 객체 b 를 생성한다. b 는 이 함수의 지역변수로, 함수가 호출될 때 생성되고 함수가 종료될 때 자동으로 소멸된다. */
int main() {
    Test a('a');
    simple_function();
    /* 가장 먼저, main 함수에서 a 객체를 생성하였으므로 a 의 생성자(= a)가 호출된다. 그리고 simple_function 을 실행하게 되면
    simple_function 안에서 또 b 객체를 생성하므로 b 의 생성자(= b)가 호출된다. 하지만 b 는 simple_fumction 의 지역 객체이기 때문에 
    simple_function 이 종료됨과 동시에 b 역시 소멸되게 된다. 따라서 b 의 소멸자(= b)가 호출된다. 
    그리고 simple_function 호출 후, 이제 main 함수가 종료될 때 마찬가지로 main 함수의 지역 객체였던 a 가 소멸되면서 a 의 소멸자(= a) 가 호출된다. 
    최종적으로 출력 결과는 a - b - b - a 순으로 나타나게 된다. */
}
/* 해당 함수의 출력 및 동작 순서 */
/*
1. a 객체 생성(생성자 호출)
    -main 함수 시작 시 Test a('a'); 가 실행되어 a 객체가 생성된다. 
    -출력: "생성자 호출a"
2. b 객체 생성(생성자 호출)
    -simple_functio() 이 호출되고, 이 함수 안에서 Test b('b'); 가 실행되어 b 객체가 생성된다. 
    -출력: "생성자 호출b"
3. b 객체 소멸(소멸자 호출)
    -simple_function() 이 종료되면, 함수의 지역변수 b 가 소멸된다. 
    -출력: "소멸자 호출b"
4. a 객체 소멸(소멸자 호출)
    -main 함수가 종료될 때, main 함수의 지역변수 a 가 소멸된다. 
    -출력: "소멸자 호출a"
5. 최종 호출
    생성자 호출a
    생성자 호출b
    소멸자 호출b
    소멸자 호출a
*/



/* 복사 생성자 */
/* 또 스타크래프트라는 게임이야기.....그중 '포토캐논' */
/* 화면에 등장해있는 포토캐논은 한 개가 아니라 수십 개의 포토캐논이 서로 겹친 모습이다. 
다시말해, 같은 포토캐논들이 수백 개 '복사' 되었다고 볼 수 있다. 
이와 같이 동일한 포토캐논을 만들어 내는 방법은 각가긔 포토캐논을 일일이 생성자로 생성할 수도 있지만,
1 개만 생성해놓고 그 하나를 가지고 나머지 포토캐논들을 '복사 생성' 할 수도 있는 것이다. */

/* 포토캐논 */
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    public:
    Photon_Cannon(int x, int y);  /* 기본 생성자 : 
    - 주어진 (x, y) 좌표에서 포토캐논을 생성한다. 
    - hp 와 shield 는 100 으로 설정되고, damage 는 20 으로 설정된다. 
    - 생성자 호출 시 "생성자 호출!!" 이라는 메시지가 출력된다. */
    Photon_Cannon(const Photon_Cannon& pc);  /* 복사 생성자: 
    - 다른 Phothon_Cannon 객체 pc 의 데이터를 복사하여 새로운 객체를 생성한다. 
    - 복사 생성자 호출 시 "복사 생성자 호출!!" 메시지가 출력된다. 
    - 복사 생성자는 어떤 클래스 T 가 있다면 
        T(const T& a);
      라고 정의된다. 즉, 다른 T 의 객체 a 를 상수 레퍼런스로 받는다는 말이다.
      여기서 a 가 const 이기 때문에 우리는 복사 생성자 내부에서 a 의 데이터를 변경할 수 없고, 
      오직 새롭게 초기화되는 인스턴스 변수들에게 '복사' 만 할 수 있게 된다. */

    void show_status();  /* show_status() 함수:
    - 현재 포토캐논의 상태를 출력한다. 
    - 좌표, HP, 실드 등의 정보를 표시한다. */
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {  
    /* 주의사항: 인자로 받는 변수의 내용을 함수 내부에서 바꾸지 않는다면 앞에 const 를 붙여주는 것이 바람직하다. */
    std::cout << "복사 생성자 호출!!" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출!!" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void Photon_Cannon::show_status() {
    std::cout << "Photo Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
    /* <실행 흐름과 출력 과정> */
    /* 
    1) Photon_Cannon pc1(3, 3); 
        -pc1 객체가 좌표 (3, 3) 에서 생성된다. 
        - 출력: "생성자 호출!!" 이 출력된다.
        - 이 시점에서 pc1 의 멤버 변수들은 아래와 같이 초기화된다. 
            ㄱ) hp = 100, shield = 100
            ㄴ) coord_x = 3, coord_y = 3
            ㄷ) damage = 20
    2) Photon_Cannon pc2(pc1);
        - pc1 객체를 복사하여 pc2 객체를 생성한다. 
        - 출력: "복사 생성자 호출!!" 이 출력된다. 
        - 이 시점에서 pc2 의 멤버 변수들은 pc1 과 동일하게 초기화된다. 
            ㄱ) hp = 100, shield = 100
            ㄴ) coord_x = 3, coord_y = 3
            ㄷ) damage = 20
    3) Photon_Cannon pc3 = pc2;
        - 이 줄은 복사 생성자를 이용해 pc2 를 복사하여 pc3 를 생성하는 것이다. 
        - 출력: "복사 생성자 호출!!" 이 출력된다. 
        - 이 시점에서 pc3 의 멤버 변수들은 pc2 와 동일하게 초기화된다. 
            ㄱ) hp = 100, shield = 100
            ㄴ) coord_x = 3, coord_y = 3
            ㄷ) damage = 20
    4) pc1.show_status();
        - pc1 의 상태를 출력한다. 
        - 출력 :
        Photo Cannon
         Location : (3, 3)
         HP : 100
    5) pc2.show_status();
        - pc2 의 상태를 출력한다. 
        - 출력 : 
        Photo Cannon 
         Location : (3, 3)
         HP : 100
    6) 최종 출력
        - 최종적으로 프로그램이 실행되면 다음과 같은 순서로 출력이 발생한다. 
        생성자 호출!!
        복사 생성자 호출!!
        복사 생성자 호출!!
        Photo Cannon
         Location : (3, 3)
         HP : 100
        Photo Cannon
         Location : (3, 3)
         HP : 100
    
    [요약]
    - 코드에서 첫 번째 객체 pc1 이 기본 생성자로 생성된다.
    - 두 번째 객체 pc2 는 첫 번째 객체 pc1 을 복사하는 '복사 생성자' 로 생성된다. 
    - 세 번째 객체 pc3 도 pc2 를 복사하는 '복사 생성자' 로 생성된다. 
    - sho2_status() 를 통해 pc1 과 pc2 의 상태를 출력하면 동일한 좌표와 HP 가 출력된다. 
    // 이 코드의 핵심은 '복사 생성자' 를 통해 객체를 복사하는 과정을 보여주는 것이다. 
    */
}
/* 참고로, 
Photon_Cannon pc3 = pc2; 와
Photon_Connon pc3;
pc3 = pc2; 
는 엄연히 다른 문장이다. 
왜냐하면 위의 것은 말 그대로 복사 생성자가 1 번 호출되는 것이고, 
아래의 것은 그냥 생성자가 1 번 호출되고 pc3 = pc2; 라는 명령이 실행되는 것이기 때문이다. 
다시 한 번 강조하지만, 복사 생성자는 오직 '생성' 시에 호출된다는 것을 명심하면 된다. */


/* 디폴트 복사 생성자의 한계 */
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    ~Photon_Cannon();

    void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
    // 0 이 아닌 값은 if 문에서 true 로 처리되므로 
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0) 과 동일한 의미를 가질 수 있다.

    // 참고로 if 문 다음에 문장이 1 개만 온다면
    // 중괄호를 생략하는 것이 가능하다. 

    if (name) delete[] name;
}
int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
    /* 해당 소스코드를 컴파일하면 런타임 오류가 발생한다. 
    이 오류는 pc1 의 name 이 동적으로 할당받아서 가리키고 있던 
    메모리 ("Cannon" 이라는 문자열이 저장된 메모리) 를 pc2 의 name 도 
    같이 가리키게 되기 때문에 발생한다. 단순히 같은 메모리를
    두 개의 서로 다른 포인터가 가리켜도 별 문제는 되지 않는다.
    진짜 문제는 소멸자에서 일어난다. 
    main 함수가 종료되기 직전에 생성되었던 객체들은 파괴되면서 소멸자를 호출하게 된다.
    만일 pc1 이 파괴되면 소멸자는 pc1 의 내용을 모두 파괴함과 동시에, pc1 의 name 에 
    할당한 메모리까지 delete 하게 된다. 그런데 문제는 pc2 의 name 이 동일한 메모리를
    가리키고 있다는 것이다. 이미 해제된 메모리를 가리키고 있는 pc2 의 name 이 
    해당 메모리에 접근해서 다시 그 메모리를 해제하려고 시도하기 때문에 (사실 접근하려는 것
    자체만으로도 오류) 런타임 오류가 발생하게 되는 것이다. 
    
    이러한 오류 문제를 막으려면 복사 생성자에서 name 을 그대로 복사하지 말고, 따로 다른 메모리에 
    동적 할당을 해서 그 내용만 복사하면 된다. 
    이렇게 메모리를 새로 할당해서 내용을 복사하는 것을 '깊은 복사(deep copy)' 라고 부르며, 
    아까처럼 단순히 대입만 해주는 것을 '얕은 복사(shallow copy)' 라고 부른다. 
    컴파일러가 생성하는 디폴트 복사 생성자의 경우 '얕은 복사' 밖에 할 수 없으므로 위와 같이 '깊은 복사' 가 
    필요한 경우에는 사용자가 직접 복사 생성자를 만들어야 한다. */
}
/* 위의 내용을 바탕으로 복사 생성자를 만들어 보면 다음과 같다. */



/* 복사 생성자의 중요성 */
#include <string.h>
#include <iostream>
class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon &pc);
    ~Photon_Cannon();

    void show_status();
};
Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) {
    std::cout << "복사 생성자 호출!!" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
    if (name) delete[] name;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
    /* 주의사항: 노파심에 말하지만, C++ 에서 문자열을 다룰 때 C 언어처럼 널 종료 char 배열을 사용하는 것은 매우매우 비추한다. 
    C++ 표준 라이브러리에서 std::string 이라는 훌륭한 문자열 클래스를 제공하므로, 뒤의 강좌들을 읽어서 꼭 사용법을 숙지하길 바란다. */
}

/* 생각해보기-문제 */
/* 문제 1: 
아래와 같은 문자열 클래스를 완성해보세요. (난이도: 중) */
class string {
    char *str;
    int len;

    public:
    string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);  // str 뒤에 s 를 붙인다. 
    void copy_string(const string &s);  // str 에 s 를 복사한다. 
    int strlen();   // 문자열 길이 리턴
};



/* const, const, const!! */

/* 생성자의 초기화 리스트(initializer list) */
/* 지난 강좌에서 만든 Marine 클래스를 변형하는 것에서부터 시작한다. */
#include <iostream>

class Marine {
    int hp;                 // 마린 체력
    int coord_x, coord_y;   // 마린 위치
    int damage;             // 공격력
    bool is_dead;           // true or false 로 값이 나온다....

    public:
    Marine();               // 기본 생성자
    Marine(int x, int y);   // x, y 좌표에 마린 생성

    int attack();                       // 데미지를 리턴한다
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();                 // 상태를 보여준다
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}  /* 초기화 리스트(initializer list) */
/* 초기화 리스트: 생성자 이름 뒤에 위와 같은 값들이 줄줄이 오는 것. 생성자 호출과 동시에 멤버 변수들을 초기화해준다. 
멤버 초기화 리스트의 형태는 다음과 같다. 
형태 : (생성자 이름) : var1(arg1), var2(arg2) {}
여기에서 var 들은 클래스의 멤버 변수들을 지칭하고, arg 는 그 멤버 변수들을 무엇으로 초기화할지 지칭하는 역할을 한다. 
단, var1 과 arg1 의 이름이 같아도 된다. 예를 들어, coord_x(coord_x) 나 coord_y(coord_y) 라 써도 정상적으로 작동하는 것이 가능하다. 
왜냐하면 coord_x(coord_x) 에서 바깥쪽의 coord_x 는 무조건 멤버 변수를 지칭하게 되는데, 이 경우 coord_x 를 지칭하는 것이고, 
괄호 안의 cood_x 는 원칙상 Marine 이 인자로 받은 coord_x 를 우선적으로 지칭하는 것이기 때문이다. 
따라서, 실제로 인자로 받은 coord_x 가 클래스의 멤버 변수 coord_x 를 초기화하게된다. */

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}  /* coord_x 는 x 로 초기화되고, is_dead 는 false 로 초기화된다. */

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();
    /* <초기화 리스트를 사용해야 하는 이유> */
    /* 초기화 리스트를 사용한 버전의 경우, '생성과 초기화를 동시에 하게' 된다. 
    반면에 초기화 리스트를 사용하지 않는다면 생성을 먼저 하고 그 다음에 대입을 수행하게 된다. 
    쉽게 말해, 초기화 리스트를 사용한다는 것은 
    int a = 10;
    이라 하는 것과 같고, 그냥 예전 버전의 생성자를 사용하는 것은 
    int a;
    a = 10;
    이라 하는 것과 동일하다는 것이다. 만약에 int 가 대신에 클래스였다면, 전자의 경우 복사 생성자가 호출되는데, 
    후자의 경우 디폴트 생성자가 호출된 뒤 대입이 수행된다는 이야기일 것이다. 
    딱 봐도 초기화 리스트를 사용하지 않는 후자 쪽이 수행해야 하는 작업이 더 많음을 알 수 있다. 따라서 초기화 리스트를
    사용하는 것이 조금 더 효율적인 작업이다. 
    그뿐만 아니라, 경험상 반드시 '생성과 동시에 초기화 되어야 하는 것들' 이 몇 가지 있다. (대표적으로, 레퍼런스와 상수)
    앞서 배운 바에 따르면 상수와 레퍼런스들은 모두 생성과 동시에 초기화가 되어야 한다. 
    아래를 보자. 아래는 초기화 상수를 쓰지 않은 상수와 레퍼런스를 정의한 소스코드이다. 
    const int a;
    a = 3;

    int& ref;  // 이것이 왜 안되는지 기억이 안난다면
    ref = c;   // 레퍼런스 강좌를 참조
    이들은 모두 컴파일 오류가 날 것이다. 따라서 만약에 클래스 내부에 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 
    무조건 초기화 리스트를 사용해서 초기화 시켜주어야 한다. */
}


#include <iostream>

class Marine {
    int hp;                     // 마린 체력
    int coord_x, coord_y;       // 마린 위치
    bool is_dead;

    const int default_damage;   // 기본 공격력

    public:
    Marine();                   // 기본 생성자
    Marine(int x, int y);       // x, y 좌표에 마린 생성

    int attack();                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();         // 상태를 보여준다. 
};
Marine::Marine()        // '초기화 리스트' 도입!!! -> defualt_damage 를 생성과 동시에 초기화할 수 있도록 하였다--따라서 상수인 default_damage 를 5 로 초기화할 수 있고, 이 값은 영원히 바뀌지 않게 된다. 
        : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
        : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}
int main() {
    Marine marine1(2, 3);   
    /* 마린의 객체들 (marine1, marine2) 를 생성하면서 
    생성자 오버로딩에 따라 Marine(int x, int y) 가 호출되는데
    이를 통해 각각 (2, 3) 과 (3, 5) 에 위치해 있는 마린 객체들을 만들 수 있게 되었다. */
    Marine marine2(3, 5);

    marine1.show_status();  /* show_status() 를 호출해보면 각 위치에 있는 마린 객체들이 제대로 정의되어있다는 것을 알 수 있다. */
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!!" << std::endl;    /* 마찬가지로 Marine 객체들이 서로 공격하는 과정도 잘 실행되고 있음을 알 수 있다. */
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    /* 해당 소스코드를 통해서 알 수 있듯이, 중요한 값들을 상수(변하지 않음!!) 로 처리하는 것은 매우 유용한 일이다. 
    다른 프로그래머가 이 클래스를 사용하면서 실수로 marine 의 default_damage 를 변경하는 명령을 집어넣더라도 컴파일
    오류가 발생하기 때문에(default_damage 값은 상수 5 로 정해졌기 때문이다.) 프로그램을 실행해서 지루한 디버깅 과정을
    거쳐서 알아내는 것보다 훨씬 효율적으로 오류를 발견할 수 있다. */
}


#include <iostream>

class Marine {
    int hp;                     // 마린 체력
    int coord_x, coord_y;       // 마린 위치
    bool is_dead;

    const int default_damage;   // 기본 공격력

    public:
    Marine();                   // 기본 생성자
    Marine(int x, int y);       // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);  /* 이전 예제에서는 default_damage 에 초기화 리스트로 5(상수) 를 전달하였다. 
    이 생성자의 경우, 어떤 값을 전달할지 인자로 받은 다음에 그 내용을 상수로 넣어주었다. 
    마찬가지로 이는
    const int default_damage = ( 인자로 받은 default_damage);
    를 실행한 것과 같기 때문에 잘 작동됨을 확인할 수 있다. 
    그리고, 실제로 5 가 아닌 10 의 HP 가 깎였음을 show_status 를 통해 확인할 수 있다. */

    int attack();                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();         // 상태를 보여준다. 
};
Marine::Marine()        // '초기화 리스트' 도입!!! -> defualt_damage 를 생성과 동시에 초기화할 수 있도록 하였다--따라서 상수인 default_damage 를 5 로 초기화할 수 있고, 이 값은 영원히 바뀌지 않게 된다. 
        : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
        : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
        : coord_x(x),
          coord_y(y),
          hp(50),
          default_damage(default_damage),
          is_dead(false) {}


void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
}
int main() {
    Marine marine1(2, 3, 10);   /* default_damage 에 10 을 넣었으므로, HP 는 10 만큼 감소하게 된다. */
    /* 마린의 객체들 (marine1, marine2) 를 생성하면서 
    생성자 오버로딩에 따라 Marine(int x, int y) 가 호출되는데
    이를 통해 각각 (2, 3) 과 (3, 5) 에 위치해 있는 마린 객체들을 만들 수 있게 되었다. */
    Marine marine2(3, 5, 10);

    marine1.show_status();  /* show_status() 를 호출해보면 각 위치에 있는 마린 객체들이 제대로 정의되어있다는 것을 알 수 있다. */
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!!" << std::endl;    /* 마찬가지로 Marine 객체들이 서로 공격하는 과정도 잘 실행되고 있음을 알 수 있다. */
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    /* 해당 예제에서는 생성자 하나(= default_damage) 를 더 추가하였다. */
}



/* 생성된 총 Marine 수 세기(static 변수) */
/* 여태까지 만들어지는 총 Marine 의 수를 알아내기 위해 코드를 짠다고 생각해보자. 
이를 위해서는 많은 방법들이 있겠지만, 가장 단순한 두 방식을 생각해본다면 
1) 어떠한 배열에 Marine 을 보관해 놓고, 생성된 마린의 개수를 모두 센다. 
2) 어떤 변수들을 만들어서 Marine 의 생성 시에 1 을 추가하고, 소멸 시에 1 을 뺀다. 
를 생각할 수 있을 것이다. 
첫 번째 방법의 경우, 따로 크기가 자유자재로 변할 수 있는 배열을 따로 만들어야 하는 문제점이 있다. 
두 번째 방법의 경우, 만일 어떠한 함수 내에서 이런 변수를 정의하였다면 다른 함수에서도 
그 값을 이용하기 위해 인자로 계속 전달해야 하는 귀찮음이 있다. (전역 변수로 만들 수도 있긴 하지만, 
전역 변수의 경우 프로젝트의 크기가 커질수록 프로그래머의 실수로 인해 서로 겹쳐서 오류가 날 가능성이 다분하기에 
반드시 필요한 경우가 아니면 사용을 하지 않는다. 실제로 꼭 필요한 경우가 아니면 전역 변수는 사용하지 말자.) 

C++ 에서는 위와 같은 문제를 간단히 해결할 수 있는 기능을 제공하고 있다. 바로 'static' 멤버 변수이다. 
이 변수는 마치 전역 변수같지만 클래스 하나에만 종속되는 변수이다. 
어떤 클래스의 static 멤버 변수의 경우, 멤버 변수들과 같은 특성(객체가 소멸될 때 소멸되는 것이 아니라 프로그램이 종료될 때 소멸되는 것.) 을 가진다. 
또한, 이 static 멤버 변수의 경우, 클래스의 모든 객체들이 '공유' 하는 변수로써 각 객체별로 따로 존재하는
멤버 변수들과는 달리 모든 객체들이 '하나의' static 멤버 변수를 사용하게 된다. 
아래의 예제를 확인하자. */

#include <iostream>

class Marine {
    static int total_marine_num;    /* 클래스 static 변수를 정의하였다. */
    /* 모든 전역 및 static 변수들은 정의와 동시에 값이 자동으로 0 으로 초기화되기 때문에 
    이 경우 우리가 굳이 따로 초기화하지 않아도 되지만, 클래스 static 변수들의 경우 아래와 같은 방법으로 초기화한다. */

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();

    ~Marine() { total_marine_num--; }  /* 소멸자 호출 시, total_marine_num 을 1 씩 감소시킨다는 의미이다. */
};
int Marine::total_marine_num = 0;   /* 클래스 static 변수를 0 으로 초기화!! */
/* class Marine {
    static int total_marine_num = 0; 
   과 같이 초기화해도 되지 않냐고 생각할 수 있는데, 멤버 변수들을 위와 같이 초기화시키지 못하는 것처럼
   static 변수 역시 클래스 내부에서 위와 같이 초기화하는 것은 불가능하다. 
   위와 같은 모습이 되는 유일한 경우는 const static 변수일 경우에만 가능한데, 실제로
   class Marine {
    const static int x = 0;
   으로 쓸 수 있다.*/

   /* 실제로 total_marine_num 이 잘 작동하는지 확인해보자. 
   클래스의 편한 점이 생성자와 소멸자를 제공한다는 점인데, 덕분에 Marine 이 생성될 때, 그리고 소멸될 때 
   굳이 따로 처리하지 않고도, 생성자와 소멸자 안에 total_marine_num 을 조작하는 문장을 넣어주면 편하게 
   처리할 수 있다. */

Marine::Marine()
        : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
        total_marine_num++;
        }
Marine::Marine(int x, int y)
        : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
        total_marine_num++;
        }
Marine::Marine(int x, int y, int default_damage)
        : coord_x(x),
          coord_y(y),
          hp(50),
          default_damage(default_damage),
          is_dead(false) {
            total_marine_num++; /* 각 생성자 호출 시에 total_marine_num 을 1 씩 증가시키는 문장을 넣었다.*/
          }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
}
int main() {
    Marine marine1(2, 3, 5);  /* 위를 실행하면 실제로 총 Marine 의 수가 1, 2 늘어나는 것을 확인할 수 있다. */
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();
    

    create_marine();  /* 그리고 create_marine 을 실행하였을 때, 역시 marine3 을 생성함으로써 총 marine 의 수가 3 이 됨을 확인할 수 있다. 
    그런데 marine3 은 create_marine 의 지역 객체이기 때문에 create_marine 이 종료될 때 소멸하게 된다. 
    따라서 다시 main 함수로 돌아와서 (marine1.show_status(); 가 등장하는 줄의 주석과 이어지는 내용이다!!!) */

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();  /* 에서 총 마린수를 표시할 때 2 명으로 나오게 된다. */
    marine2.show_status();
}



/* 그런데 클래스 안에 static 변수만 만들 수 있는 것이 아니다.
클래스 안에는 static 함수도 정의할 수 있는데, static 변수가 어떠한 객체에 종속되는 것이 아니라, 
그냥 클래스 자체에 딱 1 개 존재하는 것인 것처럼, static 함수 역시 어떤 특정 객체에 종속되는 것이 아니라 
클래스 전체에 딱 1 개 존재하는 함수이다. 

즉, static 이 아닌 멤버 함수의 경우 객체를 만들어야지만 각 멤버 함수들을 호출할 수 있지만
static 함수의 경우, 객체가 없어도 그냥 클래스 자체에서 호출할 수 있게 된다. 
아래의 예제에서 확인 가능하다. */

/* static 함수 */
#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {      /* static 함수는 앞에서 이야기한 것과 같이, 어떤 객체에 종속되는 것이 아니라 클래스에 종속된다. 
                                            따라서 이를 호출하는 방법도 (객체).(멤버 함수) 가 아니라,
                                            Marine::show_total_marine();
                                            와 같이 (클래스)::(static 함수) 형식으로 호출하게 된다. 왜냐하면 어떠한 객체도 이 함수를 소유하고 있지 않기 때문이다. 
                                            그렇기에, static 함수 내에서는 클래스의 static 변수만을 이용할 수밖에 없다. */
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
        total_marine_num++;
    } 

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
        total_marine_num++;
    }

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
        total_marine_num++;
      }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}
int main() {
    Marine marine1(2, 3, 5);
    Marine::show_total_marine();

    Marine marine2(3, 5, 10);
    Marine::show_total_marine();

    create_marine();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격!!" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}


/* 자기 자신을 가리키는 포인터 this */
#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    Marine& be_attacked(int damage_earn);
    void move(int x, int y);
    void show_status();
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
        total_marine_num++;
    }

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(5),
      is_dead(false) {
        total_marine_num++;
      }

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
        total_marine_num++;
      }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;

    return *this;     /* this : C++ 언어 차원에서 정의되어 있는 키워드인데, 객체 자신을 가리키는 포인터의 역할을 한다. 
                                즉, 이 멤버 함수를 호출하는 객체 자신을 가리킨다는 것이다. */
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
                << std::endl;
    std::cout << " HP " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}
int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격!! " << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}


/* 레퍼런스를 리턴하는 함수 */
#include <iostream>

class A{    
    int x;

    public:
    A(int c) : x(c) {}

    int& access_x() { return x; }  /* 해당 소스코드의 클래스 A 는 아래와 같이 int 와 int 의 레퍼런스를 리턴하는 두 개의 함수를 가지고 있다. */
    /* access_x 는 x 의 레퍼런스를 리턴하게 되고, get_x 는 x 의 '값' 을 리턴하게 된다. */
    int get_x() { return x; }
    void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    int& c = a.access_x();  /* 여기에서 레퍼런스 c 는 x 의 레퍼런스, 즉 x 의 별명을 받았다. 
    따라서, c 는 x 의 별명으로 탄생하게 되는 것이다. 
    레퍼런스를 리턴하는 함수를 그 함수 부분을 원래의 변수로 치환했다고 생각해도 상관이 없다. 
    다시 말해서, 
    int &c = x;  // 여기서 x 는 a 의 x
    와 동일한 의미라는 말이다. 
    따라서 c 의 값을 바꾸는 것은 a 의 x 의 값을 바꾸는 것과 동일한 의미이므로 (c 는 단순히 x 에 다른 이름을 붙여준 것일뿐!!)
    show_x 를 실행 시에 x 의 값이 5에서 4 로 바뀌었음을 알 수 있다. */
    c = 4;
    a.show_x();

    int d = a.access_x();   /* 이번에는 int& 가 아닌 그냥 int 변수에 'x 의 별명' 을 전달하였다. 
    만일 d 가 int& 였다면 x 의 별명을 받아서 d 역시 또 다른 x 의 별명이 되었겠지만, d 가 그냥 int 변수이므로, 값의 복사가 일어나 
    d 에는 x 의 값이 들어가게 된다. 그리고 당연히, d 는 x 의 별명이 아닌 또 다른 독립적인 변수이기에, d = 3; 을 해도 x 의 값은 바뀌지 
    않은 채, 그냥 4 가 출력되게 한다. */
    d = 3;
    a.show_x();

    // 아래는 오류-> 이유: 레퍼런스가 아닌 타입을 리턴하는 경우는 '값' 의 복사가 이루어지기 때문에 임시 객체가 생성되는데, 임시객체의 레퍼런스를 가질 수 없기 때문이다.(임시객체는 문장이 끝나게 되면 소멸된다.)
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();

    int f = a.get_x();  /* 임시로 생성된 int 변수가 f 에 복사되는데, 역시 f = 1 한 것이 실제 객체 a 의 x 에게는 아무런 영향을 끼칠 수 없다. */
    f = 1;
    a.show_x();
}


/* const 함수 */
/* C++ 에서는 변수들의 값을 바꾸지 않고 읽기만 하는, 마치 상수같은 멤버 함수를 '상수함수' 로써 선언할 수 있다. 
아래의 예제를 살펴보자.
*/
/* 상수 멤버 함수 */
#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;                     // 마린 체력
    int coord_x, coord_y;       // 마린 위치
    bool is_dead;

    const int default_damage;   // 기본 공격력

    public:
    Marine();                   // 기본 생성자
    Marine(int x, int y);       // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);

    int attack() const;                     // 데미지를 리턴한다
    /* 상수함수는 위와 같은 형태로 선언을 하게 된다. 
    형태 : (기존의 함수의 정의) const; */

    Marine& be_attacked(int damage_earn);   // 입는 데미지
    void move(int x, int y);                // 새로운 위치

    void show_status();                     // 상태를 보여준다
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
        total_marine_num++;
    }

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(5),
      is_dead(false) {
        total_marine_num++;
      }

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
        total_marine_num++;
      }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() const { return default_damage; }       /* 상수 함수를 선언하는 형태와 마찬가지로, 함수의 정의 역시 const 키워드를 꼭 넣어주어야 한다. (해당 줄 참고!!)
이렇게 하면 위 attack 함수는 '상수 멤버 함수' 로 정의된 것이다. 우리는 상수 함수로 이 함수를 정의함으로써, 이 함수는 다른 변수의 값을 바꾸지 않는 함수라고 다른 사용자에게 명시할 수 있다. 
당연하게도, 상수 함수 내에서는 객체들의 '읽기' 만이 수행되며, 상수 함수 내에서 호출할 수 있는 함수로는 다른 상수 함수밖에 없다.*/
Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;

    return *this;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격 !! " << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}


/* 생각해보기-문제 */
/* 문제 1 : 
아래와 같은 코드에서 복사 생성은 몇 번이나 표시될까?? 
(난이도 : 상- 사실 이 글을 잘 읽었더라면 틀리게 답하는 것이 맞다. 
컴파일러는 불필요한 복사를 막기 위해 copy elision 이라는 기술을 사용하고 있는데, 
이에 관해서는 추후에 이야기하도록 하겠다.) */
#include <iostream>

class A {
    int x;

    public:
    A(int c) : x(c) {}
    A(const A& a) {
        x = a.x;
        std::Cout << "복사 생성" << std::endl;
    }
};

class B {
    A a;

    public:
    B(int c) : a(c) {}
    B(const B& b) : a(b.a) {}
    A get_A() {
        A temp(a);
        return temp;
    }
};

int main() {
    B b(10);

    std::cout << "-------------" << std::endl;
    A a1 = b.get_A();
}



/* 내가 만들어주는 문자열 클래스 */
/* 이번 강좌에서는 문자열들을 효율적으로 관리하고 보관할 수 있는 문자열 클래스를 만들어보려고 한다. 
그 문자열 클래스는 아래와 같은 내용들을 지원해야 한다. 
1) 문자(char) 로부터의 문자열 생성, C 문자열 (char *) 로부터의 생성
2) 문자열 길이를 구하는 함수
3) 문자열 뒤에 다른 문자열 붙이기
4) 문자열 내에 포함되어 있는 문자열 구하기
5) 문자열이 같은지 비교
6) 문자열 크기 비교(사전 순) 

참고로 C++ 표준에서는 문자열 클래스(string) 을 지원하므로 직접 문자열 클래스를 만들어서 사용할 일은 거의 없을 것이고,
그 성능 역시 C++ 에서 제공하는 문자열 클래스를 이용하는 것이 훨씬 빠를 것이다. 
(하지만, 페이스북이나 구글 같은 큰 회사들에서는 C++ 에서 기본적으로 지원하는 표준 문자열 대신에 자체적으로 최적화 된 버전을 만들어서 사용하고 있기는 하다.) */

class MyString {
    char* string_content;       // 문자열 데이터를 가리키는 포인터
    int string_length;          // 문자열 길이
};                              // 위의 두 정보(string_content, string_length) 는 private 으로 설정하였다. 
// 문자 하나로 생성
MyString(char c);
// 문자열로부터 생성
MyString(const char* str);
// 복사 생성자
MyString(const MyString& str);

/* C 형식의 문자열을 그대로 보관한다면, 문자열의 끝 부분을 쉽게 체크할 수 있다는 장점이 있지만,
이 문제는 우리가 string_length 라는 변수를 같이 도입함으로써 해결할 수 있게 되었다. 
따라서, MyString 클래스에서는 실제 문자에만 해당하는 내용만을 string_content 에 보관하도록 하겠다. */

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_content = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
/* 위와 같이 3 개의 생성자들을 정의하였고, string_content 를 동적 할당으로 처리하였기 때문에 
반드시 소멸자에서 이를 동적 해제하는 것을 처리해주어야 한다. 

이것이 클래스의 큰 장점이라고 볼 수 있는데, C 언어에서 구조체같은 것으로 문자열을 구현하였다면 이를 일일이 해제하는 것도 
처리해주어야 했기 때문이다. 말 그대로, 클래스를 사용하는 사람은 안에서 어떻게 돌아가는지 전혀 신경쓰지 않고도 사용할 수 있게 되는 것이다. 

그럼 이제 매우 쉽게 문자열의 길이를 구하는 함수를 만들 수 있게 되었다. 단순히 string_length 만 리턴해주면 되는 것이다. 참고로 내부 변수의 내용을
바꾸지 않는다면 꼭 상수 함수로 정의해주는 것이 좋다. */

int MyString::length() const { return string_length; }
/* length 함수 역시 string_length 의 값을 '읽기만 하므로', 상수 함수로 정의하였다. 
다만, 이러한 방식으로 문자열의 길이를 구한다면, 문자열 조작시에 string_length 의 값을 올바른 값으로 설정해야 한다. 
예를 들어서, 두 문자열을 서로 더해서 새로운 문자열을 만들 때 새로운 문자열의 string_length 는 두 문자열의 
string_length 의 합이 될 것이다. 마찬가지로 부분 문자열을 추출하거나, 문자 하나를 지우는 등 모든 작업을 할 때 string_length 값을
정확하게 조정해야 한다. */

void MyString::print() {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

/* 위의 소스코드들을 하나로 만든 것은 아래의 코드이다. 잘 작동하는지 확인해보자. */
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 우리가 직접 strlen 과 같은 함수를 만들어서 사용해도 된다.
#include <string.h>

class MyString {
    char* string_content;       // 문자열 데이터를 가리키는 포인터
    int string_length;          // 문자열 길이

    public:
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;

    void print() const;
    void println() const;
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}
int main() {
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();
    /* 해당 소스코드를 컴파일해보면 잘 실행됨을 확인할 수 있다. */
}


/* assign 함수 */
/* assign 함수는 '지정하다' 라는 뜻을 가진 함수로, 우리가 흔히 생각하는 '=' 과 동일한 역할을 한다.
예를 들어서, 우리의 MyString 변수 str 에서 */
str.assign("abc");
/* 를 하게 된다면 str 에는 원래 있었던 문자열이 지워지고 abc 가 들어가게 될 것이다. 
그렇다면 우리는 다음과 같은 두 개의 assign 함수를 준비할 수 있다. */
MyString& assign(const MyString& str);
MyString& assign(const char* str);
/* 물론 이 assign 함수들의 구현 자체는 매우 간단하게 할 수 있다. 그 예시는 아래와 같다. */
MyString& MyString::assign(const MyString& str) {
    if (str.string_length > string_length) {
        // 그러면 다시 할당을 해주어야 한다. 
        delete[] string_content;
        string_content = new char[str.string_length];
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화시킬 필요는 없다. 왜냐하면 거기까지는 읽어들이지 않기 때문이다. 
    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);4
    if (str_length > string_length) {
        // 그러면 다시 할당을 해줘야만 한다. 
        delete[] string_content;

        string_content = new char[str_length];
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}

/* 위의 소스코드들을 하나로 묶어서, 정상적으로 작동하는지 확인해보자. 하나로 묶은 소스코드는 아래와 같다. */

#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen 과 같은 함수를 만들어서 써도 된다. 
#include <string.h>

class MyString {
    char* string_content;           // 문자열 데이터를 가리키는 포인터
    int string_length;              // 문자열 길이
    int memory_capacity;            // 현재 할당된 용량

    public:
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로부터 생성
    MyString(const MyString& str);

    // 복사 생성자
    MyString(const char* str);

    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    char at(int i) const;           // at 함수 선언!!!
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화시킬 필요가 없다.
    // 왜냐하면 거기까지는 읽어들이지 않기 때문이다. 

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면 다시 할당을 해주어야 한다. 
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
        
        delete[] prev_string_content;
    }
    // 만일 예약하려는 size 가 현재 capacity 보다 작다면, 아무것도 안해도 된다. 
}

char MyString::at(int i) const {            // 'at' 함수의 정의는 이미 존재하므로, 그대로 유지한다
/* 이 함수는 임의의 위치의 문자를 리턴하는 함수로, 이전 C 언어에서 [] 로 구현되었던 것이다. 
C 문자열의 경우, 구조상 배열의 범위를 벗어나는 위치에 대한 문자를 요구하여도 이를 처리할 수밖에 없었는데
(이는 결국 심각한 오류로 이루어졌다.) C++ 의 경우, 특정 위치의 문자를 얻는 것을 함수로 만들어서 올바르지 않는
위치에 대한 문제를 처리할 수 있게 되었다. 
그래서 위와 같이 i 가 허용되는 범위를 초과한다면 NULL 을 리턴하도록 하였다. */
    if (i >= string_length || i < 0)
        return NULL;
    else
        return string_content[i];
}

int main() {
    MyString str1("very very very long string");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
    /* 이러한 소스코드를 통해서 우리가 직접 제작한 문자열 클래스 MyString 의 기본적인 함수들은 모두 제작하였다고 볼 수 있다. 
    1) 문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자
    2) 문자열의 길이를 리턴하는 함수(length)
    3) 문자열 대입 함수(assign)
    4) 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
    5) 특정 위치의 문자를 리턴하는 함수(at) 
    이제 MySting 을 사용하는 다른 사용자들은 이 최소한의 인터페이스를 이용해서 여러가지 문자열에 관련한 모든 작업을 수행할 수 있게 된다.
    하지만 실제로 우리가 MySting 함수를 널리 편하게 사용하고 싶다면, 더 많은 기능을 제공해야 할 것이다. */
}


/* 문자열 삽입하기(insert) */
/* 문자열 처리에서 가장 빈번하게 사용되는 작업으로, 문자열 중간에 다른 문자열을 삽입하는 작업을 들 수 있다. 
사실 여태까지 만들어놓은 함수들을 가지고도 insert 작업을 쉽게 구현할 수 있겠지만, 빈번하게 사용되는 작업이다
보니까 미리 만들어 놓아서 인터페이스로 제공하는 것도 나쁘지 않을 것이라고 생각한다. */
#include <iostream>
#include <string.h>

class MyString {
    char* string_content;           // 문자열 데이터를 가리키는 포인터
    int string_length;              // 문자열 길이
    int memory_capacity;            // 현재 할당된 용량

    public:
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();        // 소멸자!!--> 생성자 앞에 '~(틸다)' 가 붙으면 소멸자이다. 
    /* 소멸자는 객체가 소멸될 때 자동으로 호출되고 객체가 사용했던 리소스(예: 동적 메모리, 파일 핸들 등) 를 해제하거나 정리하는 데 사용된다. */

    int length() const;
    int capacity() const;
    void reserve(int size);
    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        // 그러면 다시 할당을 해주어야 한다. 
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str. string_content[i];
    }
    
    // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화시킬 필요가 없다. 
    // 왜냐하면 거기까지는 읽어들이지 않기 때문이다. 

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면 다시 할당을 해줘야만 한다.
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
            delete[] prev_string_content;
    }

    // 만일 예약하려는 size 가 현재 capacity 보다 적다면
    // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다.
    // 예를 들어서 abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다. 

    // 범위를 벗어나는 입력에 대해서는 '삽입' 을 수행하지 않는다.
    if (loc < 0 || loc > string_length) {
        return *this;
    }

    if (string_length + str.string_length > memory_capacity) {
        // 이제 새롭게 동적으로 할당해야 한다. 
        memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 itsert 되는 부분 직전까지의 내용을 복사한다. 
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        // 그리고 새롭게 insert 되는 문자열을 넣는다.
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다. 
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }
    
    // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이때 원래의 문자열 데이터가 사라지지 않게 함
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];

    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str) {      /* insert('삽입') 사용!! */
/* 주로 insert 는 많은 문자열을 한꺼번에 집어넣는 것이 아니라 작은 크기의 문자열들을 자주 집어넣는 경우가 많다. 
즉, 큰 크기의 문자열을 한 번에 insert 하는 작업보다는 작은 크기의 문자열들을 여러번 insert 하는 명령을 많이 수행한다는 것이다. */
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}
int main() {
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "Sting length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();
}
/* 그런데, 만일 이미 capacity 한계에 달한 문자열 클래스에 문자 a 를 계속 추가하는 명령을 생각해보자. */
while (some_condition) {
    str.insert(some_location, 'a');
}
/* 이미 str 가 capacity 한계에 도달했다고 가정했으므로, 매 insert 마다 메모리를 해제하고 1 만큼 큰 메모리를 할당하는 작업을 반복하게 될 것이다. 
이는 str 의 크기가 크다면 엄청난 낭비이다. 
즉, 자잘하게 계속 insert 하는 명령에서 메모리 할당과 해제를 반복하지 않도록 하기 위해서라면, 
통 크게 메모리를 미리 reserve 해놓는 것이 필요하다. 물론, 무턱대고 미리 엄청난 크기의 메모리를 할당해 놓을 수도 없는 일이다. 
만일 10 바이트밖에 사용하지 않는데, 이와 같이 자잘하게 insert 하는 문제를 피하기 위해 미리 1000 바이트를 할당해놓는다면 소중한 자원의 낭비가 될 것이다. 

따라서 "insert 작업에서의 잦은 할당/해제를 피하기 위해 미리 메모리를 할당해놓기" 와 "메모리를 할당해놓되, 많은 자원을 낭비하지 않는다" 라는 
두 조건을 모두 만족하는 방법이 있을까?? 물론 방법은 있다. 
메모리를 미리 할당할 경우, 현재 메모리 크기의 두 배 정도를 할당해 놓는 방법이다. 
이를 코드로 표현하면 아래와 같다. */
MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다.
    // 예를 들어서 abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다. 

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다. 
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        // 이제 새롭게 동적으로 할당을 해야 한다. 

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;
        
        // 생략......
    }
}
/* 즉, 새로 할당해야 할 메모리 크기(string_length + str.string_length) 가 현재의 memory_capacity 의 두 배 이하라면,
아예 memory_capacity 의 두 배에 달하는 크기를 할당해버리는 것이다. 
그리고 물론 insert 되는 문자열의 크기가 (자잘하지 않고) 엄청 커서 memory_capacity 의 두 배를 뛰어넘어버린다면
그냥 예약을 생각하지 않고 필요한 만큼 할당해버리면 된다. 
이와 같은 방식으로 처리한다면, 빈번한 메모리의 할당/해제를 막을 수 있고, 더불어서 많은 메모리 공간을 낭비하지 않을 수 있다. 
(참고로 이 방법은 C++ 에서 동적으로 할당되는 메모리를 처리하는데 매우 빈번하게 사용되는 기법 중 하나이다.) 
이러한 방법을 적용한 전체 코드는 아래와 같다. */

#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 우리가 직접 strlen 과 같은 함수를 만들어서 사용해도 된다.
#include <string.h>

class MyString {            /* 해당 클래스는 C++ 의 기본 "std::string" 을 사용하는 대신, 문자열을 직접 관리하는 방법을 제공한다. */
    char* string_content;   /* 문자열 데이터를 저장할 동적 배열 포인터 */
    int string_length;      /* 문자열의 길이 */
    int memory_capacity;    /* 현재 할당된 메모리의 용량 */

    public:
    // 문자 하나로 생성
    MyString(char c);               /* 단일 문자로부터 객체를 생성하는 생성자!! 'string_content' 는 하나의 문자 크기인 1 만큼 할당되고, 그 문자로 초기화된다. */
    
    // 문자열로부터 생성
    MyString(const char* str);      /* C 스타일 문자열('const char*') 로부터 객체를 생성하는 생성자이다. 문자열의 길이를 계산하고, 그 길이만큼 메모리를 할당한 다음, 각 문자로 초기화한다. */
    
    // 복사 생성자
    MyString(const MyString& str);  /* 복사 생성자. 다른 'MyString' 객체로부터 새 객체를 복사한다. 문자열 길이와 용량을 원본과 동일하게 설정하고, 데이터를 복사한다. */

    ~MyString();                    /* 소멸자. 동적으로 할당된 메모리('string_content') 를 해제하여 메모리 누수를 방지한다. */

    int length() const;             /* 문자열의 길이를 반환한다. */
    int capacity() const;           /* 현재 할당된 메모리의 용량을 반환한다. */
    void reserve(int size);         /* 현재 할당된 메모리 용량을 지정된 크기('size') 이상으로 확보한다. 필요한 경우 기존 내용을 새로운 메모리에 복사하고 이전 메모리를 해제한다. */

    void print() const;             /* 문자열을 출력한다. */
    void println() const;           /* 문자열을 출력하고 줄바꿈한다. */

    MyString& assign(const MyString& str);      /* 다른 'MyString' 객체로 문자열을 대입한다. 필요한 경우, 메모리를 다시 할당하고 내용을 복사한다. */
    MyString& assign(const char* str);          /* C 스타일 문자열('const char*') 로 문자열을 대입한다. */

    char at(int i) const;           /* 인덱스 'i' 에 해당하는 문자를 반환한다. 인덱스가 잘못된 경우, '0' 을 반환한다. */

    MyString& insert(int loc, const MyString& str);     /* 특정 위치('loc') 에 다른 'MyString' 객체의 문자열을 삽입한다. 메모리 확장이 필요한 경우, 이를 처리한다. */
    MyString& insert(int loc, const char* str);         /* 특정 위치('loc') 에 C 스타일 문자열('const char*') 을 삽입한다. */
    MyString& insert(int loc, char c);                  /* 특정 위치('loc') 에 단일 문자를 삽입한다. */
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        // 그러면 다시 할당해주어야한다.
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화시킬 필요 없다.
    // 왜냐하면 거기까지는 읽어들이지 않기 때문이다. 

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면 다시 할당해줘야 한다. 
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }

    // 만약 예약하려는 size 가 현재 capacity 보다 작다면,
    // 아무것도 안해도 된다. 
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 
    // 예를 들어서, abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다. 

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다. 
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        // 이제 새롭게 동적으로 할당을 해야 한다. 

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 되는 부분 직전까지의 내용을 복사한다. 
        int i;
        for (i = 0; i < loc; i ++) {
            string_content[i] = prev_string_content[i];
        }

        // 그리고 새롭게 insert 되는 문자열을 넣는다. 
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다. 
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }

    // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다. 
    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다. 

    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이때 원래의 문자열 데이터가 사라지지 않게 한다. 
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];
        string_length = string_length + str.string_length;
        return *this;
}
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}
/* 위의 클래스 MyString 에서 정의한 것들 다 쓰고 나야지 main 함수가 등장한다!!
(정의한 것들 다 안 쓰면 프로그램이 제대로 동작하지 않을 듯...) */

int main() {
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String Length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5, str2);
    str1.println();

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String Length : " << str1.length() << std::endl;
    str1.println();
    /* 오 대박!!!!!!!이 소스코드 완전 긴데 한번에 컴파일 성공했다!!!!! */
}


/* erase 함수 */
/* 앞서 insert 함수를 만들었으니(삽입 역할), 이번에는 정반대의 역할을 하는 erase 함수를 만들어보도록 하자. 
erase 함수를 insert 함수보다 만들기 훨씬 쉬운데, 그 이유는 기본적으로 데이터의 양이 줄어드는 것이기 때문에 
복잡하게 capacity 같은 것들을 따로 생각할 필요가 없기 때문이다. */
MyString& erase(int loc, int num);
/* erase 함수는 위와 같은 형태를 띠고 있고, loc 은 insert 와 동일하게 loc 에 해당하는 문자 앞을 의미한다. 
그리고 num 은 지우는 문자의 수를 의미한다. 
예를 들어서, abcd 라는 문자열에서 erase(1, 2); 를 하게 된다면 1 에 해당하는 문자 'b' 의 앞에서부터 2 문자를 
지우게 되어, bc 가 지워져서 ad 가 리턴된다. */
MyString& MyString::erase(int loc, int num) {
    // loc 의 앞부터 시작해서 num 문자를 지운다. 
    if (num < 0 || loc < 0 || loc > string_length) return *this;        /* || 는 논리 연산자 'or' 을 의미한다. */

    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고온다고 생각하면 된다. 

    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}
/* string_length 를 도입하는 이점은, 어차피 string_length 뒤에 어떠한 정보가 오든 간에 별로 신경쓸 필요가 없다는 점에 있다. 
위와 같이 앞으로 문자들을 끌고 오면서 뒤의 문자들을 초기화하지 않았지만, string_length 값을 처리하였기 때문에 뒤의 문자들을 
신경쓰지 않아도 된다. */


/* find 함수 */
/* insert 와 erase 이외에 매우 빈번하게 사용하는 또다른 작업으로 find 함수가 있다. 
insert, erase, find 는 문자열 연산 기초 중의 기초라고 불릴 만큼 필수적인 함수들이다. 
그렇기에 find 함수 자체를 어떻게 구현하는가에 따라 문자열 클래스의 전반적인 성능이 좌우되는 경우도 있다. 
연산 시간이 오래 걸리지 않는 insert 와 erase 와는 달리, find 함수는 문자열의 크기가 매우 큰 경우
연산 시간이 매우 오래 걸릴 수 있기 때문이다. 가장 간단한 방법으로 find 알고리즘을 MyString 내에 구현해보면 다음과 같다. */
int find(int find_from, MyString& str) const;

int find(int find_from, const char* str) const;
int find(int find_from, char c) const;
/* 일단, 앞서 insert 함수를 구현한 방법처럼 맨 위의 MyString 을 인자로 받는 find 만 제대로 구현한 후에
아래 두 개의 find 는 맨 위의 함수를 이용해서 구현하는 방식으로 처리하였다. 

참고로 find 함수는 find_from 에서부터 시작해서 가장 첫 번째 str 의 위치를 리턴하게 된다. 
그리고 str 이 이 문자열에 포함되어 있지 않다면, -1 을 리턴하게 된다. 
이러한 방법으로, 어떤 문자열 내에 있는 모든 str 들을 찾을 수 있는 for 문을 생각할 수도 있을 것이다. */
int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if ( str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i;;) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1; // 찾지 못했음.
    /* 해당 소스코드의 경우, 간단한 방법으로 find 함수를 구현하였다. 
    find_from 부터 시작해서 string_content 와 str 가 완벽히 일치하는 부분이 생긴다면
    그 위치를 리턴하고, 찾지 못할 경우 -1 을 리턴하도록 말이다. 
    전체 소스코드를 보고, 잘 작동하는 지 확인해보자.(아래의 소스코드가 전체!!!) */
}

#include <iostream>
/* string.h 는 strlen 때문에 include 했는데, 
사실 사용자가 직접 strlen 과 같은 함수를 만들어서 써도 된다!! */
#include <string.h>

class MyString {
    char* string_content;       /* 문자열 데이터를 가리키는 포인트 */
    int string_length;          /* 문자열 길이 */
    int memory_capacity;        /* 현재 할당된 용량 */

    public:
    /* 문자 하나로 생성 */
    MyString(char c);

    /* 문자열로부터 생성 */
    MyString(const char* str);

    /* 복사 생성자 */
    MyString(const MyString& str);

    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);

    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;
};


MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        // 그러면 다시 할당해줘야한다.
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화시키지 않아도 된다. 
    // 왜냐하면 거기까지는 읽어들이지 않기 때문이다. 

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면 다시 할당을 해줘야만 한다.
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }

    // 만일 예약하려는 size 가 현재 capacity 보다 작다면
    // 아무것도 안해도 된다. 
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}

MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 
    // 예를 들어서 abc 라는 문자열에 insert(1, "d") 를 하게 된다면 abcd 가 된다. 

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다. 
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        // 이제 새롭게 동적으로 할당을 해야 한다. 

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;
        
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 되는 부분 직전까지의 내용을 복사한다. 
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        // 그리고 새롭게 insert 되는 문자열을 넣는다. 
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        // 이제 다시 원 문자열의 나머지 부분을 복사한다. 
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }

    // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다. 
    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다. 

    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이때 원래의 문자열 데이터가 사라지지 않게 한다. 
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];
        string_length = string_length + str.string_length;
        return *this;
}
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // loc 의 앞부터 시작해서 num 문자를 지운다. 
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고 
    // 생각하면 된다. 

    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}
int MyString::find(int find_from, const MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1;      // 찾지 못했음.
}
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int main() {
    MyString str1("this is a very very long string");
    std::cout << "Location of first <very in the string : " << str1.find(0, "very")     /*  첫번째 str1.find(0, "very") 에서는 맨 처음부터 시작해서 "very" 를 찾는다. --> 그 결과, 10 의 위치에 있음을 확인할 수 있다. */
                << std::endl;
    std::cout << "Location of second <very> in the string : " 
                << str1.find(str1.find(0, "very") + 1, "very") << std::endl;            /* "very" 를 찾기 위해 이전의 검색한 위치 바로 다음부터 시작해서 또 "very" 를 찾는다. --> 그 결과, 15 의 위치에 있는 "very" 를 찾을 수 있게 된다. */  
}


/* 크기 비교 함수 compare */
/* 마지막으로 만들 함수는 문자열 간의 크기를 비교하는 compare 함수이다. 
여기서 '크기' 를 비교한다는 의미는 사전식으로 배열해서 어떤 문자열이 더 뒤에 오는지를 판단한다는 의미가 된다. 
이 함수를 이용해서 문자열 전체를 정렬하는 함수라던지, 기존의 C 언어에서 strcmp 함수 등으로 지원하였던 것들을 그대로 사용할 수 있게 된다. 
(참고로, strcmp 는 C 언어에서 문자열을 비교하는 함수이다. 두 문자열을 사전순으로 비교하여 그 결과를 정수값으로 반환하고, 
해당 함수는 <string.h> 헤더 파일에 정의되어 있다.) */
int compare(const MyString& str) const;
/* 일단 함수의 원형은 위와 같이 *this 와 str 을 비교하는 형태로 이루어진다. */
int MyString::compare(const MyString& str) const {
    // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다. 
    // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미,
    // 0 은 (*this), (str) 의 두 문자열이 같다는 의미,
    // -1 은 (*this) 가 사전식으로 (str) 보다 더 앞에 온다는 의미이다. 

    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        /* 참고로, std::min 과 std::max 함수는 iostream 를 include 하면 사용할 수 있는 함수들이므로 굳이 귀찮게 만들 필요는 없다. */
        if (string_content[i] > str.string_content[i])
            return 1;

        else if (string_content[i] < str.stirng_content[i])
            return -1;
    }

    // 여기까지 했는데 끝나지 않았다면 앞부분까지 모두 똑같은 것이 된다. 
    // 만일 문자열 길이가 같다면, 두 문자열은 아예 같은 문자열이 된다. 
    if (string_length == str.string_length) return 0;

    // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다. 
    // (abc 와 abcd 의 크기를 비교하면, abc 가 abcd 보다 사전식으로 더 앞에 오게 된다.)
    else if (string_length > str.string_length)
        return 1;

    return -1;
}

/* 위의 내용들을 합친 소스코드는 아래를 참고한다. */


#include <iostream>
/* string.h 는 strlen 때문에 include 했는데, 
사실 사용자가 직접 strlen 과 같은 함수를 만들어서 써도 된다. */
#include <string.h>

class MyString {
    char* string_content;               /* 문자열 데이터를 가리키는 포인터 */
    int string_length;                  /* 문자열 길이 */
    int memory_capacity;                /* 현재 할당된 용량 */

    public:
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);

    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        //그러면 다시 할당을 해줘야 한다. 
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    // 그리고 굳이 str.string_length + 1 ~ string_length 부분을 초기화시킬 필요는 없다. 
    // 왜냐하면, 거기까지 읽어들이지는 않기 때문이다. 

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면 다시 할당을 해줘야 한다. 
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    } 

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++) 
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }

    // 만일 예약하려는 size 가 현재 capacity(용량) 보다 작다면
    // 아무것도 안해도 된다. 
} char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 
    // 예를 들어서, abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다. 

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다. 
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        // 이제 새롭게 동적으로 할당해야 한다. 

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 가 되는 부분 직전까지의 내용을 복사한다. 
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        // 그리고 새롭게 insert 되는 문자열을 넣는다. 
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다. 
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;

        return *this;
    }

    // 만일 초과하지 않는 경우, 굳이 동적할당을 할 필요가 없게 된다. 
    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다. 

    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이때 원래의 문자열 데이터가 사라지지 않게 한다. 
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++) 
        string_content[i + loc] = str.string_content[i];

    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // loc 의 앞부터 시작해서 num 문자를 지운다. 
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고온다고 생각하면 된다. 

    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}
int MyString::find(int find_from, const MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for ( i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }
    return -1;  // 찾지 못했음.
}
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::compare(const MyString& str) const {
    // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다. 
    // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미이다. 
    // 0 은 문자열 (*this) 와 (str) 이 서로 같다는 의미이다. 
    // -1 은 (*this) 가 사전식으로 (str) 보다 더 앞에 온다는 의미이다. 

    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }

    // 여기까지 했는데 끝나지 않았다면, 앞부분까지 모두 똑같은 것이 된다. 
    // 만일 문자열의 길이가 같다면 두 문자열은 아예 동일한 문자열이 된다. 

    if (string_length == str.string_length) return 0;

    // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 (사전식으로) 더 뒤에 오게 된다. 
    else if (string_length > str.string_length)
        return 1;
    
    return -1;
}
int main() {
    MyString str1("abcdef");
    MyString str2("abcde");

    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}
 

/* 이것으로, 여태까지 배운 C++ 에 대한 내용을 종합해서 훌륭한 MyString 클래스를 만들었다고 볼 수 있다.
우리의 MyString 클래스는 다음과 같은 인터페이스를 제공한다. 
1) 문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자
2) 문자열의 길이를 리턴하는 함수(length)
3) 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
4) 특정 위치의 문자를 리턴하는 함수(at)
5) 특정 위치에 특정 문자열을 삽입하는 함수(insert)
6) 특정 위치의 특정 개수의 문자를 지우는 함수(erase)
7) 특정 위치를 시작으로 특정 문자열을 검색하는 함수(find)
8) 두 문자열을 사전식 비교하는 함수(compare) 
*/

/* 생각해보기-문제 */
/* 문제 1:
사실 위 erase 함수에는 한 가지의 버그가 있다. 바로 사용자가 실수로 문자열의 실제 길이보다 많이 지울 때이다. 
이 문제는 한 번 고쳐보세요(난이도: 하) */
/* 문제 2: 
여러가지 검색 알고리즘(KMP, Boyer-Moore) 들을 이용하는 find 함수를 만들어보아라. 어떤 알고리즘의 경우 미리 
계산된 테이블이 필요할텐데, 이러한 정보들 역시 class 변수로 처리하여도 된다. (난이도: 상) */


/* 클래스의 explicit 과 mutable 키워드 */
/* explicit 과 mutable 은 클래스에서 비교적 자주 쓰이는 편은 아니지만, 나름 중요한 키워드들이다. */

/* explicit */
#include <iostream>

class MyString {
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    int memory_capacity;

    public:
    // capacity 만큼 미리 할당함.
    MyString(int capacity);     /* 우리가 추가해준 이 줄의 생성자가 capacity 를 받아서 
                                    그만큼의 공간을 미리 할당하게 된다. */

    // 문자열로부터 생성
    MyString(const  char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}
MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) 
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

int main() { MyString s(3); }
/* explicit 를 통해서 C++ 에서는 사용자가 원하지 않는 암시적 변환을 할 수 없도록 컴파일러에게 명시할 수 있다. */



/* mutable */
/* 이전에 배운 const 멤버 함수를 기억해보자. const 멤버 함수 내부에서는 멤버 변수들의 값을 바꾸는 것이 불가능하다. 
하지만, 만약에 멤버 변수를 mutable 로 선언하였다면, const 함수에서도 이들 값을 바꿀 수 있다. */
#include <iostream>

class A {
    int data_;

    public:
        A(int data) : data_(data) {}
        void DoSomething(int x) const {
            data_ = x; // 불가능!!
        }

        void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
    /* 해당 소스코드를 컴파일하면 컴파일 오류가 발생한다!! 이 오류는 const 함수 안에서 멤버 변수에 값을 대입했기 때문이다. 
    하지만 data_ 를 mutable 로 선언하면 어떨까?? 아래의 소스코드를 보자. */
}


#include <iostream>

class A {
    mutable int data_;

    public:
        A(int data) : data_(data) {}
        void DoSomething(int x) const {
            data_ = x;  // 가능!!
        }

        void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
    /* 해당 소스코드를 컴파일하면, data_ 의 값이 const 함수 내에서 바뀐 것을 확인할 수 있다. 
    그런데 생각해보면 mutable 을 쓸 바에는 차라리 그냥 DoSomething() 에서 const 를 떼어버리는 게 낫지 않았을까?? 
    왜 mutable 키워드를 만들었을까?? */
}
/* mutable 키워드의 필요성 */
/* 멤버 함수를 const 로 선언하는 것은 클래스의 멤버 함수들은 '이 객체는 이러이러한 일을 할 수 있습니다.' 라는 의미를 가지고 있다. 
그리고 멤버 함수를 const 로 선언하는 의미는 '이 함수는 객체의 내부 상태에 영향을 주지 않습니다.' 를 표현하는 방법이다. 
대표적인 예로, 읽기 작업을 수행하는 함수들을 들 수 있다. 
대부분의 경우에 의미상 상수 작업을 할 때 실제로도 상수 작업을 하게 된다. 하지만, 실제로 꼭 그렇지만은 않다. 
예를 들어서 아래와 같은 서버 프로그램을 만든다고 가정해보자. */
class Server {
    // .....(생략)/........

    // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다. 
    User GetUserInfo(const int user_id) const {
        // 1. 데이터베이스에 user_id 를 검색
        Data user_data = Database.find(user_id);

        // 2. 리턴된 정보로 User 객체 생성
        return User(user_data);
    }
};
/* 이 서버에는 GetUserInfo 라는 함수가 있는데 입력 받은 user_id 로 데이터베이스에서 해당 유저를 조회해서 그 유저의 정보를 리턴하는 함수이다.
당연히도 데이터베이스를 업데이트하지도 않고, 무언가를 수정하는 작업도 당연히 없기 때문에 const 함수로 선언되어 있다. 
그런데 대개 데이터베이스에 요청한 후 받아오는 작업은 꽤나 오래 걸린다. 그래서 보통 서버들의 경우 메모리에 캐쉬(cache) 를 만들어서 자주 요청되는 데이터를 
굳이 데이터베이스까지 가서 찾지 않아도 메모리에서 빠르게 조회할 수 있도록 한다. 

물론 캐쉬는 데이터베이스만큼 크지 않기 때문에 일부 유저들 정보밖에 포함하지 않는다. 
따라서 캐쉬에 해당 유저가 없다면 (이를 '캐쉬 미스' 라고 한다.), 데이터베이스에 직접 요청해야할 것이다. 대신 데이터베이스에서 유저 정보를 받으면 캐쉬에 
저장해놓아서 다음에 요청할 때는 빠르게 받을 수 있게 된다. 
이를 구현한다면 아래와 같다. */
class Server {
    // ....(생략)....

    Cache cache;  // 캐쉬

    // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다. 
    User GetUserInfo(const int user_id) const {
        // 1. 캐쉬에서 user_id 를 검색
        Data user_data = cache.find(user_id);

        // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
        if (!user_data) {
            user_data = Database.find(user_id);

            // 그 후 캐쉬에 user_data 등록
            cache.update(user_id, user_data);  // <-- 불가능
        }

        // 3. 리턴된 정보로 User 객체 생성
        return User(user_data;) 
    }
};
/* 그런데 문제는 GetUserInfo 가 const 함수라는 점이다. (const 함수는 데이터 변경/수정이 불가능!!) 
따라서 */
cache.update(user_id, user_data);  // <-- 불가능
/* 위처럼 캐쉬를 업데이트하는 작업을 수행할 수 없다. 왜냐하면 캐쉬를 업데이트한다는 것은 캐쉬 내부의 정보를 바꾸어야한다는 뜻이기 때문이다.
따라서 저 update 함수는 const 함수가 아닐 것이다. 
그렇다고 해서 GetUserInfo 에서 const 를 떼어내기도 좀 그런 것이, 이 함수를 사용하는 사용자의 입장에선
당연히 const 로 정의되어야 하는 함수이기 때문이다. 따라서 이 경우, Cache 를 mutable 로 선언해버리면 된다. */
mutable Cache cache;  // 캐쉬!!
/* 위처럼 말이다. 이렇듯, mutable 키워드는 const 함수 안에서 해당 멤버 변수에 const 가 아닌 작업을 할 수 있게 
만들어준다. 
그렇다면 이것으로 클래스의 explicit 과 mutable 키워드들에 대해서 알아보았다. 
다음 시간에는 내가 만든 클래스에 연산자를 사용할 수 있게 해주는 '연산자 오버로딩' 에 대해서 배울 것이다. */


/* 연산자 오버로딩(overloading) */
/* MyString 을 이용하여 여러가지 작업을 하면서 다음과 같은 생각을 하였을 것이다. 
1) if(str1.compare(str2) == 0) 하지 말고 if(str1 == str2) 하면 어떨까?? 
2) str1.insert(str1.length(), str2) 하지 말고 str1 = str1 + str2; 하면 어떨까?? 
3) str1[10] = 'c'; 와 같은 것도 할 수 있을까?? */

/* 물론 C 언어에서는 이러한 것을 상상조차 할 수 없었다. =, -, ==, [] 와 같은 기본 연산자들은 모두 C 언어에 
기본적으로 정의되어 있는 데이터 타입(int, float 등) 에만 사용 가능한 것들이었기 때문이다. 
이들을 구조체 변수에 사용한다는 것은 불가능하였다. 
*/
/* 하지만 놀랍게도 C++ 에서는 사용자 정의 연산자를 사용할 수 있다. 어떠한 연산자들이 가능하냐면,
::(범위 지정), .(멤버 지정), .*(멤버 포인터로 멤버 지정) 을 제외한 우리가 상상하는 모든 연산자를 사용할 수 있다는 것이다. 

대표적으로는 
1) =, -, * 와 같은 '산술 연산자' 
2) +=, -= 와 같은 '축약형 연산자'
3) >=, == 와 같은 '비교 연산자'
4) &&, || 과 같은 '논리 연산자'
5) -> 나 * 와 같은 '멤버 선택 연산자' (여기서 * 는 역참조 연산자이다. 포인터에서 *p 할 때처럼)
6) ++, -- '증감 연산자'
7) [] ('배열 연산자') 와 심지어 () 까지 ('함수 호출 연산자') 
까지 모두 우리가 직접 만들 수 있다. 

이때 이러한 기본 연산자들을 직접 사용자가 정의하는 것을 '연산자를 오버로딩(overloading)' 한다고 부른다. 
이전에 같은 이름의 함수를 인자만 다르게 사용하는 것을 '함수를 오버로딩 했다' 라고 불렀던 것처럼, 
기본 연산자를 우리가 설계한 클래스에 맞게 직접 사용하는 것을 '연산자를 오버로딩했다' 라고 부른다. */


/* MyString 의 == 연산자 오버로딩 */
/* 연산자 오버로딩을 사용하기 위해서는 일단 오버로딩을 원하는 연산자 함수를 제작하면 된다. 
형태: (리턴 타입) operator(연산자) (연산자가 받는 인자) --> 참고로, 이 방법 외에는 함수 이름으로 연산자를 절대 넣을 수 없다. 
예를 들어서 우리가 == 를 오버로딩하고 싶다면, == 연산자는 그 결과값이 언제나 bool 이고, 인자로는 == 로 비교하는 것 하나만 받게 된다. 
따라서 다음과 같이 함수를 정의하면 된다. 
bool operator == (MyString& str);
이제, 우리가 str1 == str2 라는 명령을 한다면 이는 str1.operator == (str2) 로 내부적으로 변환되어 처리된다. 
그리고 그 결과값을 리턴하게 된다. 간단하게 만들어보면 다음과 같다. */
bool MyString::operator == (MyString& str) {
    return !compare(str);  // str 과 같으면 compare 
}

/* 여기서 !compare(str) 을 리턴하는 이유는 compare 함수에서 str 과 *this 가 같으면 0 을 리턴하도록 하였는데,
operator== 은 둘이 같으면 true 를 리턴해야 되기 때문이다. 따라서 NOT 연산자인 ! 를 앞에 붙여서 리턴하면 올바르게
작동할 수 있다. 
그럼, 실제로 나의 새롭게 오버로딩한 == 연산자가 잘 작동하는지 살펴보자.
*/
#include <string.h>
#include <iostream>

class MyString {
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    int memory_capacity;    // 현재 할당된 용량
    
    public:

    // 문자 하나로 생성
    MyString(char c);

    // 문자열로부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    char at(int i) const;

    int compare(MyString& str);
    bool operator==(MyString& str);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];

    std::cout << std::endl;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
        
        delete[] prev_string_content;
    }

    // 만일 예약하려는 size 가 현재 capacity 보다 작다면,
    // 아무것도 안해도 된다. 
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0)
        return 0;
    else
        return string_content[i];
}
int MyString::compare(MyString& str) {
    // (*this) - (str) 을 수행해서 그 1, 0, -1 로 결과를 리턴한다. 
    // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미.
    // 0 은 두 문자열이 같다는 의미.
    // -1 은 (*this) 가 사전식으로 더 앞에 온다는 의미.

    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;

        else if (string_content[i] < str.string_content[i])
            return -1;
    } 

    // 여기까지 했는데 끝나지 않았다면 앞부분까지 모두 똑같은 것이 된다. 
    // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다. 

    if (string_length == str.string_length) return 0;

    // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다. 
    else if (string_length > str.string_length)
        return 1;

    return -1; 
}
bool MyString::operator==(MyString& str) {
    return !compare(str);       // str 과 같으면 compare 에서 0 을 리턴한다.
}
int main() {
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3("sentence");

    if (str1 == str2)
        std::cout << "str1 와 str2 같다." << std::endl;
    else
        std::cout << "str1 와 str2 는 다르다." << std::endl;

    if (str2 == str3)
        std::cout << "str2 와 str3 는 같다." << std::endl;
    else
        std::cout << "str2 와 str3 는 다르다." << std::endl;
    
    /* 해당 소스코드를 출력하면 
    str1 와 str2 는 다르다.
    str2 와 str3 는 같다.
    라는 결과가 출력된다. 위 코드에서 확인할 수 있듯이, str1 와 str2 은 다르고,
    str2 와 str3 은 같기 때문에 제대로 처리되고 있음을 알 수 있다. */
}



/* 복소수(Complex number) 만들기 */
/* MyString 클래스가 너무 비대한 바람에 좀 더 간결하게 설명하기 위해 새로운 클래스를 만들어볼 것이다.
바로 '복소수(complex number)' 을 다루는 클래스이다. 
주의: 참고로 C++ 표준 라이브러리에 std::complex 가 정의되어 있어서 굳이 우리가 만들어서 쓸 필요는 없다.
복소수 클래스를 제작하는 이유는 순전히 교육을 위해서이다. */
class Complex {
    private:
        double real, img;

    public:
        Complex(double real, double img) : real(real), img(img) {}
};
/* 복소수는 언제나 실수부와 허수부로 나누어지므로, Complex 클래스 역시 실수부의 값과 허수부의 값을 나타내는
real(실수부) 과 img(허수부) 변수가 있다. 여기서 문제는 이전에 만들었던 MyString 과는 다르게, 사칙 연산이 엄청나게
자주 쓰인다는 점이다. 
당연하게도 덧셈(+ 연산) 까지는 생각할 수 있었다 해도, 곱셈이나 나눗셈 연산 자체는 고려할 필요가 없는데, 
복소수의 경우 당연히 클래스 인터페이스 차원에서 곱셈과 나눗셈을 지원해주어야 한다. 

그래서 만일 다음과 같이 연산자의 오버로딩을 모른다고 가정하고 Complex 클래스를 구성하여 보자. */
class Complex {
    private:
        double real, img;

    public:
        Complex(double real, double img) : real(real), img(img) {}

        Complex plus(const Complex& c);
        Complex minus(const Complex& c);
        Complex times(const Complex& c);
        Complex divide(const Complex& c);
    /* 이렇게 된다면 만일 int 형 변수였다면
    a + b / c + d;
    로 간단하게 쓸 수 있었던 명령을 
    a.plus(b.divide(c)).plus(d);
    와 같이 복잡한 함수식을 이용해서 표현해야만 한다. 이는 가독성이 떨어질 뿐더러 위 식을 딱 보고 
    도대체 무슨 작업을 하려고 하는지도 쉽게 알 수 없다. 
    
    하지만 연산자 오버로딩을 이용해서 plus 를 operator+ 로, divide 를 operator/ 로, 등등 바꿔준다면
    단순히 프로그래머가 a + b/c + d; 라고 쓴다고 해도 컴파일러가 a.operator+(b.operator/(c)).plus(d)
    로 알아서 변환시켜서 처리하기 때문에 속도나 다른 면의 어떠한 차이 없이 뛰어난 가독성과 편리한을 얻을 수 
    있게 된다. 
    이를 바탕으로 간단히 Complex 클래스를 만들어본다면 아래의 소스코드와 같다. (아래의 코드 참고!!!) */
};


/* Complex 클래스 */
#include <iostream>

class Complex {
    private:
        double real, img;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }

        /* 이 코드에서 가장 중요하게 봐야 할 부분인 
        '사칙연산 연산자 함수들의 리턴 타입'!! */
        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);
        /* 두 연산자 함수 모두 Complex& 가 아닌 Complex 를 리턴하고 있다. */
        // 간혹가다 
        // Complex& operator_(const Complex& c) {
        //  real += c.real;
        //  img += c.img;
        //  return *this;
        // }
        // 로 잘못 생각하는 경우도 있다. 물론 이렇게 설계하였을 경우, Complex 를 리턴하는 연산자 함수는 
        // 값의 복사가 일어나기 때문에 속도 저하가 발생하지만 위처럼 레퍼런스를 리턴하게 되면 값의 복사 
        // 레퍼런스만 복사하는 것이므로 큰 속도의 저하는 나타나지 않는다. 
        // 하지만, 위와 같이 operator+ 를 정의할 경우 다음과 같은 문장이 어떻게 처리되는지 생각해보자. 
        
        /* Complex a = b + c + b;
        아마도 위 문장을 쓴 사람 입장에서는 결과적으로 a = 2 * b + c; 를 의도하였을 것이다. 
        하지만, 실제로 처리되는 것을 보자면, (b.plus(c)).plus(b) 가 되는데, b.plus(c) 를 하면서 b 에는 (b + c) 가 들어가고
        거기에 다시 plus(b) 를 하게 된다면 값 자체만 본다면 (b + c) + (b + c) 가 돼서 (왜냐하면 현재 b 에는 b + c 가 들어가 있기 때문에)
        a = 2 * b + 2 * c, 즉 a = 2 * (b + c) 가 되기 때문이다. 
        이러한 문제를 막기 위해서는 반드시 사칙 연산의 경우 무조건 값을 리턴하도록 해야 한다. 
        
        또한 함수 내부에서 '읽기' 만 수행되고 값이 바뀌지 않는 인자들에 대해서는 const 키워드를 붙여주는 것이 바람직하다. 
        operator+ 의 경우, c 의 값을 읽기만 하지 c 의 값에 어떠한 변화도 주지 않으므로 const Complex& 타입으로 인자를 받는다. 
        주의사항: 인자의 값이 함수 내부에서 바뀌지 않는다고 확신할 때에는 const 키워드를 붙여주길 바란다. 이는 나중에 발생할 수 있는 실수들을 방지할 수 있다. */
        void println() { std::cout << "(" << real << " , " << img << " ) " << 
                std::endl; }
};

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
  
int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a * b;

    c.println();
}


/* 대입 연산자 함수 */
/* 아마 Complex 클래스를 구현하면서 한 가지 빠뜨렸다고 생각하고 있는 것이 있을 것이다. 
바로, 대입 연산자(=) 이다. 아마도, 대입 연산자야말로 가장 먼저 구현했어야 할 연산자 함수가 아니었을까 한다. */
Complex& operator=(const Complex& c);
/* 기본적으로 대입 연산자 함수는 기존의 사칙연산 연산자 함수와는 다르게, Complex& 타입을 리턴한다. 
사실 대입 연산자 자체의 의미를 생각해 볼 때 리턴값을 void 로 해도 무방하지만, 프로그래머들은 종종 if((i = x) < y) 와 같은 문장을 사용하기 때문에
리턴값을 주는 것이 인터페이스 차원에서 더 낫다고 생각한다. (챗 gpt 왈, 리턴값을 사용하는 것은 코드를 더 직관적이고 유지보수하기 쉽게 만들며, 
객체의 상태 변경을 방지하여 예측 가능한 코드를 작성할 수 있게 도와준다고 한다.) 

이와 같은 사실을 바탕으로 완성한 operator= 함수는 아래와 같다. */
Complex& Complex::operator=(const Complex& c)
{
    real = c.real;
    img = c.img;
    return *this;
}


/* 대입 연산자 함수 */
#include <iostream>

class Complex {
    private:
    double real, img;

    public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real, img = c.img; }

    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);

    Complex& operator=(const Complex& c);
    void println() { std::cout << " ( " << real << " , " << img << " ) " << 
        std::endl; }
};

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    Complex c(0.0, 0.0);
    c = a * b + a / b + a + b;
    c.println();
    /* 해당 소스코드에서 흥미로운 사실은 굳이 operator= 를 만들지 않더라도, 위 소스를 컴파일하면
    잘 작동한다는 것이다. 이는 컴파일러 차원에서 디폴트 대입 연산자(default assignment operator) 를 지원하고 있기 때문이다. 
    이는 이전에 복사 생성자를 다룰 때 디폴트 복사 생성자가 있었던 것과 일맥상통한다. 
    디폴트 복사 생성자와 마찬가지로 디폴트 대입 연산자 역시 얕은 복사를 수행한다. 따라서, 깊은 복사가 필요한 클래스의 경우
    (예를 들어, 클래스 내부적으로 동적으로 할당되는 메모리를 관리하는 포인터가 있다던지) 대입 연산자 함수를 꼭 만들어주어야할 필요가 있다. */
}

/* 여담이지만, 이제 우리는 다음 두 문장의 차이를 완벽히 이해할 수 있다. */
// Some_Class a = b;    // 1 번
// 와
// Some_Class a;        // 2 번
// a = b; 
// 말이다. 
/* 1 번의 경우, 아예 a 의 '복사 생성자' 가 호출되는 것이고, 2 번의 경우 a 의 그냥 기본 생성자가 호출된다음
다음 문장에서 대입 연산자 함수가 실행되는 것이다. 위 문장은 비슷해보이기는 해도 아예 다른 것이다. 

마찬가지 이유로 대입 사칙연산 함수들인 +=, -= 등을 구현할 수 있다. 일단 = 와 마찬가지로 아래와 같이 Complex& 를 리턴하고 */
Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);
/* 그 내부 구현은 간단히 미리 만들어놓은 operator+, operator- 등을 이용해서 처리하면 된다. */
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Compelx& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
/* 위의 코드들을 합친 전체 소스코드는 아래와 같다. (아래의 코드 참고!!) */

/* 전체 소스코드 */
#include <iostream>

class Complex {
    private:
        double real, img;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        void println() {
            std::cout << " ( " << real << " , " << img << " ) " << std::endl; 
        }
};

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / ( c.real * c.real + c.img * c.img));
    return temp;
}
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this; 
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    a += b;
    a.println();
    b.println();
    /* 해당 소스코드를 출력하면 
    ( 4, 0 )
    ( 3, -2 )
    이 정상적으로 출력됨을 확인할 수 있다. a 의 값만 바뀐 채, b 에는 아무런 영향이 없다. 
    
    참고로, 연산자 오버로딩을 사용하게 된다면 a += b 와 a = a + b; 가 같다고 보장되지 않는다는
    점을 명심해야 한다. 
    컴파일러는 operator+ 와 operator= 를 정의해놓았다고 해서 a += b 를 자동으로 a = a + b; 로 
    바꾸어주지 않는다. 반드시 operator+= 를 따로 만들어야지 += 를 사용할 수 있게 된다. 
    이와 같은 사실은 ++ 을 += 1 로 바꾸어주지 않는다거나 -- 를 -= 1 로 바꾸어주지 않는다는 사실과 일맥상통한다. 
    즉, 연산자 오버로딩을 하게 된다면 우리가 생각하는 모든 연산자들에 대해 개별적인 정의가 필요하다. */
}


/* 문자열로 Complex 수와 덧셈하기 */
/* 이번에는 operator+ 를 개량해서 꼭 Complex 수를 더하는 것이 아니라, 문자열로도 덧셈을 할 수 있도록 operator+ 함수를 만들어보려고 한다. 
다시 말해서, */
y = z + "3+i2";
/* 이런 문장을 사용하였을 경우에도 성공적으로 처리할 수 있게 된다는 의미이다. 참고로, 문자열로 복소수를 어떻게 표현해야 할 지에 대해서는 모종의 약속이 필요하다. 
우리 Complex 클래스의 경우, 복소수를 문자열로 다음과 같은 형태로 표현하도록 정한다. */
// (부호) (실수부) (부호) i (허수부)
/* 예를 들어서 "2+i3" 은 Complex 수 (2, 3) 을 나타낸 것이라 생각한다. 또한 "2-i3" 은 (2, -3) 을 나타낸 것이 된다. 
만일 실수부나 허수부의 값이 0 이라면 굳이 안 써주어도 되는데, 예를 들어서 그냥 "3" 은 (3, 0) 을 나타내며,
"-5i" 는 (0, -5) 를 나타내게 된다. 참고로 우리의 실수부와 허수부는 double 변수이기 때문에 문자열로 입력받을 때 단순히 정수 부분만 받는 것이 아니라 소수점아래 부분도 
처리해주어야만 할 것이다. 이를 바탕으로 만든 operator+ 함수는 아래의 소스코드에 해당한다. (아래의 소스코드 참고!!) */

Complex Complex::operator+(const char* str) {   // 해당 줄은 문자열을 입력으로 받아 복소수로 변환하고 덧셈을 수행한다. 
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야한다. 
    // 문자열의 꼴은 다음과 같다. "[부호] (실수부) (부호) i (허수부)"
    // 이때 맨 앞의 부호는 생략 가능하다. (생략 시, + 라 가정한다.)
    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;

    // 먼저 가장 기준이 되는 "i" 의 위치를 찾는다. 
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 "i" 가 없다면, 이 수는 실수뿐이다. 
    if (pos_i == -1) {
        str_real = get_number(str, begin, end - 1);

        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    // 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다. 
    str_real = get_number(str, begin, pos_i - 1);
    str_img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

    Complex temp(str_real, str_img);
    return (*this) + temp;
}
/* 일단 문자열을 덧셈의 피연산자로 사용하게 되므로, operator+ 의 인자는 Complex& 가 아니라 
const char* 가 된다. 교재의 경우, 입력받은 '문자열 복소수' 를 분석하기 위해서 가장 중요한 'i' 의 위치를 먼저 찾도록 하였다. 
왜냐하면 이 'i' 를 기준으로 복소수의 실수부와 허수부가 나뉘어지기 때문이다. 
따라서 위와 같이 pos_i 에 str 의 'i' 의 위치를 찾도록 하였다. 물론, 입력 받은 문자열에 반드시 'i' 가 있어야만 하는 것은 아니다. 
왜냐하면 이전에도 말했듯이 복소수가 그냥 실수라면 굳이 허수 부분을 표현하지 않을 수 있기 때문이다. 따라서, 아래와 같이 i 가 없을 경우 
간단히 따로 처리할 수 있다. 
참고로 우리가 사용하는 get_number 함수는 특정 문자열에서 수 부분을 double 값으로 반환하는 함수이다. */



/* 합친 코드 */
#include <iostream>
#include <cstring>

class Complex {
    private:
        double real, img;

        double get_number(const char* str, int from, int to);

    public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real, img = c.img; }

    Complex operator+(const Complex& c);
    Complex operator+(const char* str);

    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    Complex& operator=(const Complex& c);

    void println() { std::cout << " (  " << real << " , " << img << " ) " << 
        std::endl; }
};

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;
    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else
            break;      // 그 이외의 이상한 문자들이 올 경우
    }

    if (minus) num *= -1.0;

    return num;
}
Complex Complex::operator+(const char* str) {
    // 입력받은 문자열을 분석하여 real 부분과 img 부분을 찾아야한다. 
    // 문자열의 꼴은 다음과 같다. "[부호](실수부)(부호)i(허수부)"
    // 이때 맨 앞의 부호는 생략 가능하다. (생략시 + 라 가정!!)

    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다. 
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 'i' 가 없다면, 이 수는 실수뿐이다. 
    if (pos_i == -1) {
        str_real = get_number(str, begin, end - 1);

        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    // 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다. 
    str_real = get_number(str, begin, pos_i - 1);
    str_img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

    Complex temp(str_real, str_img);
    return (*this) + temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c. real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
    /* 이 소스코드를 컴파일해보면 잘 작동함을 확인할 수 있다. 
    그런데, + 뿐만 아니라 -, * 등의 모든 연산자들에 대해 이 기능을 지원하기 위해서 
    각각의 코드를 반복적으로 쓰는 것은 매우 귀찮은 일이다. 이와 같은 불편한 작업을 
    막기 위해 아예 const char * 로 오버로딩되는 Complex 생성자를 추가하는 것도 
    괜찮은 방법이다. 
    
    그렇게 된다면 길고 복잡했었던 operator+(const char * str) 부분을 다음과 같이
    간단하게 줄일 수 있기 때문이다. */
    // Complex Complex::operator+(const char* str) {
    // Complex temp(str);
    // return (*this) + temp;
    // }
    /* 간단하게 줄인 코드는 아래와 같다. (아래의 코드 참고!!) */
}

/* 간단한 Complex(const char* str) 코드 */
Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다. 
    // 문자열의 꼴은 다음과 같다. --> [부호](실수부)(부호)i(허수부)
    // 이때 맨 앞의 부호는 생략 가능하다. --> 생략시 + 라 가정한다. 

    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다. 
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 'i' 가 없다면 이 수는 실수뿐이다. 
    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    // 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다. 
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-' img *= -1.0;)
}
/* 이렇게 된다면, 나머지 함수들도 역시 바뀐다. (아래!!) */
Complex Complex::operator-(const char* str) {
    Complex temp(str);
    return (*this) - temp;
}
Complex Complex::operator*(const char* str) {
    Complex temp(str);
    return (*this) * temp;
}
Complex Complex::operator/(cost char* str) {
    Complex temp(str);
    return (*this) / temp;
}
/* 이와 같이, 간단하게 바뀌는 것이 가능하다. */


#include <cstring>
#include <iostream>

class Complex {
    private:
        double real, img;

        double get_number(const char* str, int from, int to);

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex operator+(const char* str);     // operator+(const char *str) 계열들을 모두 지워보고 컴파일해보아도 결과는 동일하게 나온다. 
        Complex operator-(const char* str);
        Complex operator*(const char* str);
        Complex operator/(const char* str);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        Complex& operator=(const Complex& c);

        void println() {
            std::cout << " ( " << real << " , " << img << " ) " << std::endl;
        }
};
Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다. 
    // 문자열의 형태는 다음과 같다. --> [부호](실수부)(부호)i(허수부)
    // 이때 맨 앞의 부호는 생략 가능하다. --> (생략시, + 라 가정!!) 

    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다. 
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 'i' 가 없다면, 이 수는 실수뿐이다. 
    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    // 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다. 
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;
    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else
            break;  // 그 이외의 이상한 문자들이 올 경우
    }

    if (minus) num *= -1.0;

    return num;
}
Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
        return temp;
}

Complex Complex::operator+(const char* str) {       // operator+(const char *str) 계열들을 모두 지워보고 컴파일해보아도 결과는 동일하게 나온다.
    Complex temp(str);
    return (*this) + temp;
}
Complex Complex::operator-(const char* str) {
    Complex temp(str);
    return (*this) - temp;
}
Complex Complex::operator*(const char* str) {
    Complex temp(str);
    return (*this) * temp;
}
Complex Complex::operator/(const char* str) {
    Complex temp(str);
    return (*this) / temp;
}
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
    a = a - "1.2 - i1.823";
    a.println();
    a = a * "2.3 + i22";
    a.println();
    a = a / "-12 + i55";
    a.println();
    /* 해당 코드를 컴파일하면 정상적으로 작동함을 확인할 수 있다. 
    한 가지 재미있는 점은, Complex(const char *str) 생성자만 남겨놓고, 
    operator+(const char *str) 계열들을 모두 지워보고 다시 컴파일해도 
    결과가 이 소스코드와 동일하게 나온다는 것이다.
    다만, 우리가 operator+ 함수의 인자가 const Complex& c 가 아니라
    그냥 Complex& c 로 받도록 하였다면, 위와 같은 변환은 이루어지지 않는다는
    점을 알아두어야한다. 왜냐하면 -1.1 + i3.923 자체가 문자열 리터럴이므로,
    이를 바탕으로 생성된 객체 역시 상수여야하기 때문이다. 
    따라서 여러모로 함수 인자의 값을 변형하지 않는다는 확신이 들면 무조건 const
    인자로 받도록 하는 것이 좋다. */
}
/* 이러한 방식으로 이 Complex 클래스의 문자열을 이용해서 복소수 덧셈을 수행할 수 
있는 훌륭한 기능을 추가하였다. 하지만 다음과 같은 문장은 실행이 가능할까??
a = "-1.1 + i3.923" + a;
사실 이 문장이나, 원래의
a = a + "-1.1 + i3.923"; 
문장이나 정확히 똑같은 식이다. 왜냐하면 + 연산자는 교환법칙이 성립해야만하기 때문이다. 
하지만 전자의 경우에는, 성공적으로 컴파일되지 않는다. 왜냐하면 a + "-1.1+i3.923" 의 경우
이 문장이 a.operator+("-1.1+i3.923") 으로 변환되어서 정확히 수행할 수 있지만, 
"-1.1+i3.923" + a 의 경우에는 이같은 변환이 불가능하기 때문이다. 
그렇다면 이러한 문제를 해결할 수 있는 방법에 대해서는 다음 시간에 다루어보도록 한다. */

/* 생각해보기-문제 */
/* 문제 1:
그렇다면 Complex 클래스의 연산자 오버로딩을 수행하면서 쌓은 지식을 바탕으로 MyString 함수를 
완전하게 만들어보자. 즉, 강좌 서두에서 지적한 사항들을 모두 구현하면 된다. (난이도 : 하) */



/* 잡다한 연산자의 오버로딩 */
#include <cstring>
#include <iostream>

class Complex {
    private:
        double real, img;

        double get_number(const char* str, int from, int to);

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img - c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        Complex& operator=(const Complex& c);

        void println() {
            std::cout << " ( " << real << " , " << img << " ) " << std::endl; 
        }
};

Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a);
    return temp.operator+(b);
}
Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야한다. 
    // 문자열의 꼴은 다음과 같다. --> [부호](실수부)(부호)i(허수부)
    // 이때 맨 앞의 부호는 생략 가능하다. --> 생략 시 + 라 가정!!

    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 가장 먼저 기준이 되는 'i' 의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }
    
    // 만일 'i' 가 없다면 이 수는 실수뿐이다. 
    if (pos_i == -1) {
        real = get_number(str, begin, end -1);
        return;
    }

    // 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다. 
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else
            break;      // 그 외의 이상한 문자들이 올 경우
     }

     if (minus) num *= -1.0;

     return num;
}
Complex Complex::operator+(const Complex& c) {
    /* operator+ 부분을 자세히 살펴보면 다음과 같은 점을 확인할 수 있다. 
    왜 굳이 귀찮게 temp 라는 새로운 Complex 객체를 정의하여 temp 와의 + 연산을
    리턴하는 것일까?? 그냥 a + b 할 것을 불필요하게 복사 생성을 한 번 더 하게 
    돼서 성능의 하락이 발생하게 된다. 
    하지만 그냥 a + b 를 하게 된다면
    Complex operator+(const Complex& a, const Complex& b) { return a + b; }
    위 코드를 컴파일하면 오류가 났다는 경고 메세지가 뜨게 된다. 
    즉, a + b 에서 a.operator+(b) 가 호출되는 것이 아니라, operator+(a, b) 가
    호출되기 때문에 재귀적으로 무한히 많은 함수가 호출되어서 오류가 발생한다는 것이다. 
    실제로 실행해보아도 프로그램이 강제적으로 종료되는 모습을 볼 수 있다. 따라서 이와
    같은 문제를 방지하기 위해서 우리는 다음과 같이 강제로 멤버 함수 opretaor+ 를 호출
    하도록 지정하였다. 
    Complex operator+(const Complex& a, const Complex& b) { return a.operator+(b); }
    이 역시 컴파일되지 않는다. 그 이유는 a 가 const Complex 인데, 우리가 호출하고자 하는 
    멤버 함수 operator+ 는 const 함수가 아니기 때문이다. */

    /* const 객체는 언제나 갑싱 바뀔 수 없으며, 만일 const 객체의 멤버 함수 호출 시에는 그 함수가
    객체의 값을 바꾸지 않는다고 보장할 수 있도록 const 함수여야 한다. 하지만 멤버 함수 operator+ 는 
    const 성이 없으므로, operator+ 를 호출하는 것은 불가능해진다. 
    이 문제를 해결할 수 있는 유일한 방법은 Complex operator+(const Complex& a, const Complex& b) 내부
    에서 다른 함수들을 호출하지 않고 직접 덧셈을 하면 된다. 다만 이 방법도 문제가 있다. 
    멤버 함수가 아닌 외부 함수 operator+ 에서 객체의 private 정보에 접근할 수 있어야만 하는데, 이것이
    불가능하기 때문이다. 하지만 놀랍게도 C++ 에서는 이를 가능케 하는 키워드가 존재한다. */
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
} 
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
    );
    return temp;
}


Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    a.println();
}


/* freind 는 모든 것을 공유한다. */
/* C++ 에서는 freind 키워드를 사용하여 어떠한 정보도 열람할 수 있도록 할 수 있다. */
class Complex {
    private:
        double real, img;

        double get_number(const char* str, int from, int to);

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        Complex& operator=(const Complex& c);

        friend Complex operator+(const Complex& a, const Complex& b);   /* 이와 같이 Complex 클래스 안에서 
        friend 를 쓰면 우리의 Complex operator+(const Complex& a, const Complex& b); 함수는 이제 Complex 의 
        friend 가 된다. 
        즉, Complex 클래스의 입장에서는 자신의 새로운 친구엔 operator+ 에게 마음의 문을 열고 모든 정보에 접근할 수
        있도록 허가하는 것이다. 
        private 냐 public 냐에 관계없이 Complex operator+(const Complex& a, const Complex& b); 함수는 이제 어떤
        Complex 객체라도 그 내부 정보에 접근할 수 있다. 따라서, 다음과 같은 코드를 사용하는 것도 가능하다. 

        Complex operator+(const Complex& a, const Complex& b) {
            Complex temp(a.real +b.real, a.img + b.img);
            return temp;
        }
        이제 이 operator+ 함수는 마치 Complex 클래스의 멤버 변수인 양, 객체들의 정보에 접근할 수 있게 된다. real 변수는 
        private 이지만, a.real 을 해도 무방하다. 이렇게 된다면, 이전의 operator+ 에서 불필요하게 temp 객체를 
        생성했던 것과는 달리 필요한 것만 사용하면 된다. */

        void println() {
            std::cout << " ( " << real << " , " << img << " ) " << std::endl;
        }
};


/* 한 가지 재미있는 사실은 freind 키워드는 함수에만 적용할 수 있는 것이 아니라, 
다른 클래스 자체도 friend 로 지정할 수 있다는 것이다. 예를 들어, */
class A {
    private:
        int x;

        friend B;
};
class B {
    private:
        int y;
};
/* 위와 같이 할 경우, A 는 B 를 friend 로 지정하게 된 것이다. 
한 가지 주의할 사실은, 우리가 흔히 생각하는 friend 관계와는 달리 C++ 에서 friend 는 
짝사랑과 비슷하다는 것이다. 즉, A 는 자기 생각에 B 가 friend 라고 생각하는 것이므로
B 에게 A 의 모든 것을 공개한다.
즉 클래스 B 에서 A 의 private 변수인 x 에 접근할 수 있게 된다. 하지만 B 에는 A 가 
friend 라고 지정하지 않았으므로, B 의 입장에서는 A 에게 어떠한 내용도 공개하지 않는다. 
(public 변수들 빼고.) 따라서 A 는 B 의 private 변수인 int y 에 접근할 수 없게 된다. */

/* 입출력 연산 */
#include <cstring>
#include <iostream>

class Complex {
    private:
        double real, img;

        double get_number(const char* str, int from, int to);

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);
        
        Complex& operator=(const Complex& c);

        friend Complex operator+(const Complex& a, const Complex& b);
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);

        void println() {
            std::cout << " ( " << real << " , " << img << " ) " << std::endl;
        }
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << " ( " << c.real << " , " << c.img << " ) ";
    return os;
}
Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}
Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다. 
    // 문자열의 꼴은 다음과 같다. --> [부호](실수부)(부호)i(허수부)
    // 이때 맨 앞의 부호는 생략 가능하다. --> 생략 시, + 라 가정!!
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 'i' 가 없다면 이 수는 실수뿐이다.
    if (pos_i = -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    // 만일 'i' 가 있다면, 실수부와 허수부를 나누어서 처리하면 된다. 
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else
            break;      // 그 외의 이상한 문자들이 올 경우
    }

    if (minus) num *= -1.0;
    return num;
}
Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        ( img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
    );
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
}



/* 첨자 연산자(operator[]) */
/* 이번에는 배열에서 원소를 지정할 때 사용되는 첨자 연산자 [] 를 오버로디 해보도록 하자. 
우리가 전에 만들었던 MyString 클래스에서 개개의 문자에 접근하기 위해 [] 를 지원해주어야만 
하는데, [] 를 이용해서 str[10] 과 같이 10 번째 문자에 정확하게 접근할 수 있게 된다. 
그렇다면 MyString 클래스의 operator[] 를 추가해보도록 하자. operator[] 함수는 자명하게도 인자로
몇 번째 문자인지, int 형 변수를 인덱스로 받게 된다. 따라서 operator[] 는 다음과 같은 원형을 가진다. 
*/
char& operator[](const int index);
/* index 로 [] 안에 들어가는 값을 받게 된다. 그리고 char& 를 인자로 리턴하는 이유는 
str[10] = 'c' 
와 같은 명령을 수행하기 때문에, 그 원소의 레퍼런스를 리턴하게 되는 것이다. 실제로 operator[] 의 구현은 
아래와 같이 매우 단순하다. 
cahr& MyString::operator[](const int index) { return string_content[index]; }
위와 같이 index 번째의 string_content 를 리턴해서, operator[] 를 사용하는 사용자가, 이의 레퍼런스를
가질 수 있게 된다. 그렇다면, 전체 소스를 한 번 살펴보도록 하자. */

#include <iostream>
#include <cstring>

class MyString {
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이
    int memory_capacity;    // 현재 할당된 용량

    public: 
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length();

    void print() const;
    void println() const;

    char& operator[](const int index);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() { return string_length; }
void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

char& MyString::operator[](const int index) { return string_content[index]; }

int main() {
    MyString str("abcdef");
    str[3] = 'c';

    str.println();
    /* 해당 소스코드를 출력하면 제대로 str[3] 의 'd' 를 'c' 로 바꾸었음을 확인할 수 있다.
    따라서 출력 결과는 'abccef' 이다. */

    /* 이정도만 하면 MyString 클래스는 거의 웬만한 문자열 클래스 뺨치게 완전한 모습을 갖추었다고 볼 수 있다. 
    문자열 삽입, 삭제, 대입 뿐만 아니라 개개의 문자의 조작까지 원활하게 수행할 수 있는 훌륭한 문자열 클래스라고 할 수 있다. */
}


/* int Wrapper 클래스- 타입 변환 연산자 */
/* Wrapper 라는 것은 원래 우리가 흔히 음식을 포장할 때 '랩(wrap) 으로 싼다' 라고 하는 것처럼
'포장지' 라는 의미의 단어이다. 즉 Wrapper 클래스는 무언가를 포장하는 클래스라는 의미인데, C++ 에서
프로그래밍을 할 때 어떤 경우에 기본 자료형들을 객체로써 다루어야할 때가 있다. 
이럴 때, 기본 자료형들(int, float 등등) 을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것ㅇ르
Wrapper 클래스를 이용한다고 표현한다. 
즉, int 자료형을 감싸는 int Wrapper 클래스 int 는 아래와 같은 구성이 가능하다. */
class Int
{
    int data;
    // some other data

    public:
        Int(int data) : data(data) {}
        Int(const Int& i) : data(i.data) {}
};
/* 위 Int 클래스에 int 형 자료형을 보관하는 data 라는 변수를 정의해놓았는데, 이렇게 한다면 
int 형 데이터를 저장하는 객체로 Int 클래스를 사용할 수 있을 것이다. 
우리는 이 Int 형 객체가 int 의 Wrapper 클래스의 객체인 만큼, int 와 정확히 똑같이 작동하도록
만들고 싶다. 다시 말해서, 다음과 같은 명령을 내려도 아무 하자 없이 잘 실행될 수 있도록 말이다. */
Int x = 3;      // Wrapper 객체
int a = x + 4;  // 그냥 평범한 int 형 변수 a


#include <iostream>

class Int {
    int data;                               // Int 클래스의 private 멤버 변수로, 정수를 저장한다.  
    // some other data

    public:
        Int(int data) : data(data) {}
        Int(const Int& i) : data(i.data) {}

        operator int() { return data; }
};
int main() {
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
    /* 코드의 과정 */
    /*  생성자 Int(int data) : 정수를 받아 data 를 초기화한다. 예를 들어 Int x = 3; 을 호출하면 이 생성자가 호출되어 data 에 3 이 저장된다. 
        복사 생성자 Int(const Int& i) : 다른 Int 객체의 data 값을 복사한다. 
        변환 연산자 operator int() : Int 객체를 int 로 변환할 수 있게 한다. 즉, Int 타입 객체가 int 타입처럼 사용될 수 있다. --> 가장 중요한 부분!!!
        main 함수 설명 - Int x = 3;  :  Int(int data) 생성자가 호출되어 x 객체가 생성되고, data 는 3 으로 초기화된다. 
                       - int a = x + 4;  :  여기서 x 는 Int 타입이지만, int 타입의 변수와 덧셈 연산을 하고 있다. 이때 operator int() 가 자동으로 호출되어 x 가 int 로 변환된다. 
                                            즉, x 는 int 로 자동 변환되어 3 으로 평가된다. 
                                            3 + 4 연산이 수행되어 a 는 7 이 된다. 
                       - x = a * 2 + x + 4;  : a * 2 는 7 * 2 로, 14 가 된다. 
                                               x 는 Int 객체지만, int 와의 덧셈 연산에서 int 로 자동 변환된다. (operator int() 호출)
                                               따라서 14 + 3 + 4 가 수행되어 최종적으로 x 는 21 이 된다. 
                                               이 계산의 결과는 다시 Int 객체로 저장된다. 
                       - std::cout << x << std::endl;  :  x 는 Int 객체이지만, 출력 시 int 타입으로 자동 변환된다. 따라서 21 이 출력된다. */
}


/* 전위/후위 증감 연산자 */
/* 마지막으로 살펴볼 연산자로 우리가 흔히 ++, -- 로 사용하는 전위/후위 증감 연산자들이다. 
아마, 이 연산자를 오버로딩하기 전에 한 가지 궁금증이 들었을 것이다. 과연 C++ 컴파일러는
전위/후위 증감을 구분해서 오버로딩 시켜주는지 입니다. 
다시 말해,
a++;
++a;
위 두 ++ 연산자들을 구분해서 오버로딩을 시켜주냐 이 말이다. 두 연산자 모두 operator++ 이기 때문이다. 
C++ 언어에서는 다음과 같은 흥미로운 방법으로 구분한다. 방법은 아래와 같다.
operator++();
operator--();
은 전위 증감 연산자 (++x, --x) 를 오버로딩하게 된다. 그렇다면 후위 증감 연산자 (x++, x--) 는 어떨지 아래를 보자.
operator++(int x);
operator--(int x);
로 구현하게 된다. 물론 인자 x 는 아무런 의미가 없다. 단순히 컴파일러 상에서 전위와 후위를 구별하게 위해 int 인자를 넣어주는 것이다. 
실제로 ++ 을 구현하면서 인자로 들어가는 값을 사용하는 경우는 없다. 따라서 그냥
operator++(int);
operator--(int);
와 같이 구현해도 무방하다. 

한 가지 중요한 점은, 전위 증감 연산의 경우, '값이 바뀐 자기 자신' 을 리턴해야 하고,
후위 증감의 경우 '값이 바뀌기 이전의 객체' 를 리턴해야 한다는 점이다. 
왜냐하면 전위와 후위 연산자가 어떻게 다른지 생각해봤을 때 
int x = 1;
func(++x);
를 하게 되면 func 에는 2 가 인자로 전달되지만
int x = 1;
func(x++); 
의 경우 func 에 1 이 인자로 전달되고, 나중에 x++ 이 실행되어서 x 가 2 가 되기 때문이다. 
따라서 이를 감안하면 아래와 같은 꼴이 된다. 
A& operator++() {
    // A++ 을 수행한다. 
    return *this;
}
전위 연산자는 간단히 ++ 에 해당하는 연산을 수행한 후에 자기 자신을 반환해야 한다. 반면에 후위 연산자의 경우
A operator++(int) {
    A temp(A);
    // A++ 을 수행한다.
    return temp;
}
++ 을 하기 전에 객체를 반환해야하므로, temp 객체를 만들어서 이전 상태를 기록한 후에, ++ 을
수행한 뒤에 temp 객체를 반환하게 된다. 
따라서 후위 증감 연산의 경우, 추가적으로 복사 생성자를 호출하기 때문에 전위 증감 연산보다 더 느리다!!

아래의 예제코드를 살펴보자.
클래스 자체는 별거 없지만 전위와 후위가 호출될 때를 구별하기 위해 메세지를 출력하도록 하였다.
*/
#include <iostream>

class Test {
    int x;

    public:
        Test(int x) : x(x) {}
        Test(const Test& t) : x(t.x) {}

        Test& operator++() {
            x++;
            std::cout << "전위 증감 연산자" << std::endl;
            return *this;
        }

        // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를 
        // 받지만, 실제로는 아무것도 전달되지 않는다. 

        Test operator++(int) {
            Test temp(*this);
            x++;
            std::cout << "후위 증감 연산자" << std::endl;
            return temp;
        }

        int get_x() const {
            return x;
        }
};

void func(const Test& t) {
    std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
    Test t(3);

    func(++t);      // 4
    func(t++);      // 4 가 출력됨 --> 그러나, 후위증감은 전위증감보다 더 속도가 느리다!!
    std::cout << "x : " << t.get_x() << std::endl;
    /* 해당 소스코드를 출력해보면 결과는 다음과 같다. 
    전위 증감 연산자
    x : 4
    후위 증감 연산자
    x : 4
    x : 5
    이와 같이 코드가 제대로 실행되고 있음을 확인할 수 있다. */
}


/* 정리 */
/* 연산자 오버로딩에 대한 몇 가지 중요한 포인트들을 정리해보자. 
1) 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩하는 것이 좋다. 
(예를 들어 Complex 의 operator+(const Complex&, const Complex&) 와 같이 말이다.)
2) 두 개의 객체 사이의 이항 연산자이지만 한 객체만 값이 바뀐다던지 등의 동등하지 않는 이항 연산자는
멤버 함수로 오버로딩하는 것이 좋다. (예를 들어서 operator+= 는 이항 연산자이지만, operator+=(const Complex&) 가 낫다.)
3) 단항 연산자는 멤버 함수로 오버로딩하는 것이 좋다. (예를 들어서 operator++ 의 경우, 멤버 함수로 오버로딩한다.)
4) 일부 연산자들은 반드시 멤버 함수로만 오버로딩해야한다. */

/* 생각해보기-문제 */
/* 문제 1:
N 차원 배열을 제공하는 클래스를 만들어보아라. 이는 우리가 여태까지 배운 내용을 시험할 것이다. 참고로, 원소에 접근하기 위해서는
a[1][2][3] 과 같은 방법으로 접근할 것이다. 다만 N 차원 배열이기 때문에 (N 은 객체 생성시에 사용자가 입력합니다.) 
2 차원 배열은 a[1][2], 3 차원 배열은 a[1][2][3] 과 같은 방식으로 접근할 것이다. (난이도: 최상) */
/* 문제 2:
영어를 잘하는 사람들은 연산자 오버로딩에 관해 정리해 놓은 다음 글(링크를 걸어둔 듯...??교재는 pdf 라서 눌러도 소용없지만--239p) 을 
읽어보는 것을 추천한다. 참고로 이 글에서 다루지만 본 강좌에서는 다루지 않는 일부 내용들은 아직 배운 내용이 아니라서 생략한 것이므로
너무 걱정하지 말고 복습하는 느낌으로 천천히 읽어보면 좋을 것이다. (난이도: 중) */


/* N 차원 배열 만들기 프로젝트 */
/* C++ 스타일의 캐스팅 */
class Array {
    const int dim;  // 몇 차원 배열인지
    int* size;  // size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다.

    public:
        Array(int dim, int* array_size) : dim(dim) {
            size = new int[dim];
            for (int i = 0; i < dim; i++) size[i] = array_size[i];
        }
        /* 우리의 Array 배열에 들어가야 할 중요한 정보로 '몇 차원 배열인지' 에 대한 정보와, 각 차원에서의 크기 정보를 반드시 포함하고 있어야만 할 것이다. 
        따라서, '몇 차원' 인지는 dim 에 아예 상수값으로 저장하도록 하고 (반드시 상수로 정할 필요는 없지만, dim 을 상수로 정한 것은 외부 사용자들에게 한 번 Array 의
        차원을 정하면 바꿀 수 없다는 것을 의미한다.) */
};

class Array {
    const int dim;  // 몇 차원 배열인지
    int* size;      // size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다. 

    struct Address {
        int level;
        // 맨 마지막 레벨 (dim - 1 레벨) 은 데이터 배열을 가리키고, 그 위 상위 레벨에서는 다음 Adress 배열을 가리킨다.
        void* next;
    };
    Address* top;

    public:
        Array(int dim, int* array_size) : dim(dim) {
            size = new int[dim];
            for (int i = 0; i < dim; i++) size[i] = array_size[i];
        }
};
/* 이제 본격적으로 top 을 시작으로 N 차원 배열을 생성해보도록 할 것이다. 위의 그림과 같은 구조를 구현하기 위해서는 
이전에 동적으로 2 차원 배열을 생성하였을 때처럼 for 문으로 간단히 수행할 수 있는 것이 아니다.
왜냐하면 일단 for 문으로 하기 위해서는 몇 중 for 문을 사용할 지 컴파일 시에 정해져야하는데, 이 경우
N 차원인 임의의 차원이므로 그럴 수 없기 때문이다. 
하지만 이와 같은 문제를 해결하는 아주 좋은 방법은 바로 재귀함수를 이용하는 것이다. 
재귀함수를 구성하기 위해서는 다음과 같은 두 가지 스텝만 머리속으로 생각하고 있으면 된다. 
1) 함수에서 처리하는 것, 즉 현재 단계에서 다음 단계로 넘어가는 과정은무엇인가?? 
2) 재귀 호출이 종료되는 조건은 무엇인가?? 

Array 배열을 만드는 전체 코드는 아래와 같다. (아래의 소스코드 참고!!!) */


/* 대망의 Array 배열 */
#include <iostream>

namespace MyArray {     /* 전체 클래스를 MyArray 라는 이름 공간으로 감쌌다는 점이 중요한 포인트!!!--> 이를 통해 혹여라도 다른 라이브러리에서 Array 라는 클래스를 정의하더라도 문제 없을 것이다. 
또한 주목할 점은 두 개ㅡ이 클래스를 한 파일에서 사용하기 때문에 클래스의 정의 순서가 매우 중요하다는 점이다. 
소스코드 상단에 class Array 와 class Int 클래스를 '선언' 하였다. (클래스를 '선언' 하지 않는다면, 아래 Array 클래스에서 friend Int; 를 할 수 없게 된다. 따라서 friend 선언을 하기 전에 이와 같이 class Int 를 먼저 맨 위에 선언해서 사용할 수 있도록 해야 한다.) */
    class Array;
    class Int;

    class Array {
        friend Int;

        const int dim;  // 몇차원 배열인지
        int* size;      // size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다. 

        struct Address {
            int level;
            // 맨 마지막 레벨 (dim - 1 레벨) 은 데이터 배열을 가리키고, 그 위 상위레벨에서는 
            // 다음 Address 배열을 가리킨다.
            void* next;
        };

        Address* top;

        public: 
            Array(int dim, int* array_size) : dim(dim) {
                size = new int[dim];
                for (int i = 0; i < dim; i ++) size[i] = array_size[i];

                top = new Address;
                top->level = 0;

                initialize_address(top);
            }
            Array(const Array& arr) : dim(arr.dim) {
                size = new int[dim];
                for (int i = 0; i < dim; i++) size[i] = arr.size[i];

                top = new Address;
                top->level = 0;

                initialize_address(top);
            }
            // address 를 초기화하는 함수이다. 재귀 호출로 구성되어 있다. 
            void initialize_address(Address* current) {
                if (!current) return;
                if (current->level == dim - 1) {
                    current->next = new int[size[current->level]];
                    return;
                }
                current->next = new Address[size[current->level]];
                for (int i = 0; i != size[current->level]; i++) {
                    (static_cast<Address*>(current->next) + i)->level = current->level + 1;
                    initialize_address(static_cast<Address*>(current->next) + i);
                }
            }
            void delete_address(Address* current) {
                if (!current) return;
                for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
                    delete_address(static_cast<Address*>(current->next) + i);
                }
                delete[] current->next;
            }
            Int operator[](const int index);
            ~Array() {
                delete_address(top);
                delete[] size;
            }
        };
        class Int {
            void* data;

            int level;
            Array* array;

            public:
                Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
                    : level(_level), data(_data), array(_array) {
                        if (_level < 1 || index >= array->size[_level - 1]) {
                            data = NULL;
                            return;
                        }
                        if (level == array->dim) {
                            // 이제 data 에 우리의 int 자료형을 저장하도록 해야 한다. 
                            data = static_cast<void*>((
                                static_cast<int*>(static_cast<Array::Address*>(data)->next) + index));
                        } else {
                            // 그렇지 않을 경우, data 에 그냥 다음 addr 을 넣어준다.
                            data = static_cast<void*>(static_cast<Array::Address*>(
                                                                static_cast<Array::Address*>(data)->next) + index);
                        }
                    };

                    Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

                    operator int() {
                        if (data) return *static_cast<int*>(data);
                        return 0;
                    }
                    Int& operator=(const int& a) {
                        if (data) *static_cast<int*>(data) = a;
                        return *this;
                    }

                    Int operator[](const int index) {
                        if (!data) return 0;
                        return Int(index, level + 1, data, array);
                    }
        };
        Int Array::operator[](const int index) {
            return Int(index, 1, static_cast<void*>(top), this);
        }
}   // namespace MyArray
int main() {
    int size[] = {2, 3, 4};
    MyArray::Array arr(3, size);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
                            << std::endl;
            }
        }
    }
}

/* Array 에 Iterator 라는 클래스를 추가한 전체 코드 */
#include <iostream>

namespace MyArray {
    class Array;
    class Int;

    class Array {
        friend Int;

        const int dim;      // 몇 차원 배열인지
        int* size;          // size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다

        struct Address {
            int level;
            // 맨 마지막 레벨(dim - 1 레벨) 은 데이터 배열을 가리키고, 그 위 상위
            // 레벨에서는 다음 Address 배열을 가리킨다. 
            void* next;
        };

        Address* top;

        public:
            class Iterator {
                int* location;
                Array* arr;

                friend Int;

                public:
                Iterator(Array* arr, int* loc = NULL) : arr(arr) {
                    location = new int[arr->dim];
                    for (int i = 0; i != arr->dim; i++)
                        location[i] = (loc != NULL ? loc[i] : 0);
                }
                Iterator(const Iterator& itr) : arr(itr.arr) {
                    location = new int[arr->dim];
                    for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
                }
                ~Iterator() { delete[] location; }
                // 다음 원소를 가리키게 된다. 
                Iterator& operator++() {
                    if (location[0] >= arr->size[0]) return (*this);

                    bool carry = false;     // 받아올림이 있는지
                    int i = arr->dim - 1;
                    do {
                        // 어차피 다시 돌아온다는 것은 carry 가 true
                        // 라는 의미이므로 ++ 을 해야 한다. 
                        location[i]++;
                        if (location[i] >= arr->size[i] && i >= 1) {
                            // i 가 0 일 경우 0 으로 만들지 않는다. (이러면 begin 과 중복됨)
                            location[i] -= arr->size[i];
                            carry = true;
                            i--;
                        } else
                            carry = false;

                    } while (i >= 0 && carry);

                    return (*this);
                }
                Iterator& operator=(const Iterator& itr) {
                    arr = itr.arr;
                    location = new int[itr.arr->dim];
                    for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];

                    return (*this);
                }
                Iterator operator++(int) {
                    Iterator itr(*this);
                    ++(*this);
                    return itr;
                }
                bool operator!=(const Iterator& itr) {
                    if (itr.arr->dim != arr->dim) return true;

                    for (int i = 0; i != arr->dim; i++) {
                        if (itr.location[i] != location[i]) return true;
                    }

                    return false;
                }
                Int operator*();
            };

            friend Iterator;
            Array(int dim, int* array_size) : dim(dim) {
                size = new int[dim];
                for (int i = 0; i < dim; i++) size[i] = array_size[i];

                top = new Address;
                top->level = 0;

                initialize_address(top);
            }
            Array(const Array& arr) : dim(arr.dim) {
                size = new int[dim];
                for (int i = 0; i < dim; i++) size[i] = arr.size[i];

                top = new Address;
                top->level = 0;

                initialize_address(top);
            }
            // address 를 초기화하는 함수이다. 재귀 호출로 구성되어 있다.
            void initialize_address(Address* current) {
                if (!current) return;
                if (current->level == dim - 1) {
                    current->next = new int[size[current->level]];
                    return;
                }
                current->next = new Address[size[current->level]];
                for (int i = 0; i != size[current->level]; i++) {
                    (static_cast<Address*>(current->next) + i)->level = current->level + 1;
                    initialize_address(static_cast<Address*>(current->next) + i);
                }
            }
            void delete_address(Address* current) {
                if (!current) return;
                for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
                    delete_address(static_cast<Address*>(current->next) + i);
                }

                delete[] current->next;
            }
            Int operator[](const int index);
            ~Array() {
                delete_address(top);
                delete[] size;
            }

            Iterator begin() {
                int* arr = new int[dim];
                for (int i = 0; i != dim; i++) arr[i] = 0;

                Iterator temp(this, arr);
                delete[] arr;

                return temp;
            }    
            Iterator end() {
                int* arr = new int[dim];
                arr[0] = size[0];
                for (int i = 1; i < dim; i++) arr[i] = 0;

                Iterator temp(this, arr);
                delete[] arr;

                return temp;
            }
        };

        class Int {
            void* data;

            int level;
            Array* array;

            public:
                Int(int index, int _level = 0, void* _data = NULL, Array* _array = NULL)
                    : level(_level), data(_data), array(_array) {
                    if (_level < 1 || index >= array->size[_level - 1]) {
                        data = NULL;
                        return;
                    }
                    if (level == array->dim) {
                        // 이제 data 에 우리의 int 자료형을 저장하도록 해야한다.
                        data = static_cast<void*>((
                            static_cast<int*>(static_cast<Array::Address*>(data)->next) + index
                        ));
                    } else {
                        // 그렇지 않을 경우 data 에 그냥 다음 addr 을 넣어준다.
                        data = static_cast<void*>(static_cast<Array::Address*>(
                                                                static_cast<Array::Address*>(data)->next)
 + index                        );
                    }
                    };

                    Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

                    operator int() {
                        if (data) return *static_cast<int*>(data);
                        return 0;
                    }
                    Int& operator=(const int& a) {
                        if (data) *static_cast<int*>(data) = a;
                        return *this;
                    }

                    Int operator[](const int index) {
                        if (!data) return 0;
                        return Int(index, level + 1, data, array);
                    }
        };
        Int Array::operator[](const int index) {
            return Int(index, 1, static_cast<void*>(top), this);
        }
        Int Array::Iterator::operator*() {
            Int start = arr->operator[](location[0]);
            for (int i = 1; i <= arr->dim - 1; i++) {
                start = start.operator[](location[i]);
            }
            return start;
        }
}   // namespace MyArray
int main() {
    int size[] = {2, 3, 4};
    MyArray::Array arr(3, size);

    MyArray::Array::Iterator itr = arr.begin();     /* 눈여겨봐야하는 부분!!!
    이와 같이 반복자를 이용하는 것은 C++ 에서 매우 많이 사용되고 있는 방법으로, 나중에 표준 라이브러리들에 대해
    살펴볼 때 다시 한 번 등장하게 된다. */
    for (int i = 0; itr != arr.end(); itr++, i++) (*itr) = i;
    for (itr = arr.begin(); itr != arr.end(); itr++)
        std::cout << *itr << std::endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1) + arr[i][j][k];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
                            << std::endl;
            }
        }
    }
}

/* 생각해보기-문제 */
/* 문제 1:
앞서 N 차원 배열을 구현하는 또 다른 방법(그냥 X1 * ... * Xn 개의 1 차원 배열을 만든 뒤에,
[] 연산자를 위와 같이 특별한 방법을 이용하여 접근할 수 있게 하는 것) 으로 N 차원 배열을 구현해보자. (난이도: 상) */


/* 클래스의 상속 */
/* 표준 string 클래스 */
/* C 언어 스타일의 문자열은 여러가지 문제점들이 많기 때문에(예를 들어 문자열의 길이를 한 번에 알 수 없고 마지막 null 문자까지 하나하나 읽어야된다던지..)
문자열을 처리할 수 있는 새로운 무언가가 계속 필요해야 했다. 
사실 우리가 예전에 만든 MyString 클래스도 문자열 처리를 꽤 훌륭하게 하지만, 실제로 속도가 매우 중요한 
환경에서 그대로 쓰기에는 부족한 점이 많다. 하지만 많은 프로그래머들의 노력 끝에 string 이라는 빠르고, 안전하고 사용하기 매우 간단한 문자열 클래스가 표준으로 
채택이 된다. 
(이 string 에 들어가 있는 몇 가지 기술을소개해보자면, 짧은 문자열에 대해서는 동저그올 메모리를 할당하지 않고 그냥 지역 변수로 보관을 하고, 
문자열을 복사를 할 때 그 복사된 문자열의 내용이 바뀌지 않는 한 실제로 데이터를 복사하는 것이 아니라 원래 문자열을 가리키기만 한다 등등 속도를 향상시키기 위한 
여러 노력이 접목되어 있다.) */
#include <iostream>
#include <string>

int main() {
    // 표준이므로 std 안에 string 이 정의되어 있다. 
    std::string s = "abc";

        std::cout << s << std::endl;

    return 0;
    /* 일단 기본적으로 "abc" 는 컴파일러 상에서는 C 형식 문자열로 인식된다. 
    즉, 위 문장은 string 클래스의 인자를 const char * 로 받는 생성자를 호출한 것으로 볼수 있다. */
}


#include <iostream>
#include <string>

int main() {
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;

        std::cout << s << " 의 길이 : " << s.length() << std::endl;
        std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t << std::endl;

        if (s == s2) {
            std::cout << s << " 와 " << s2 << " 는 같다. " << std::endl;
        }
        if (s != t) {
            std::cout << s << " 와 " << t << " 는 다르다. " << std::endl;
        }
        return 0;
        /* 해당 소스코드는 몇 가지 string 클래스의 기능들을 간단히 보여준 것이다. 
        예를 들어 문자열의 길이를 출력하는 length 함수라던지, 연산자 오버로딩을 사용해서 + 연산자가 실제로 문자열을 결합시키는 함수로 사용되고 있다. 
        특히 편리한 점으로 C 형식 문자열이었을 경우 문자열을 비교하기 위해서 strcmp 함수를 사용했어야 하고,
        == 나 != 로 비교하는 것이 불가능하였다. (왜냐하면 이는 문자열의 주소값을 비교하는 것이었기 때문이다.)
        하지만 이 string 클래스는 == 와 != 연산자들을 모두 오버로딩해서 제대로 비교를 수행한다. 
        뿐만 아니라 크기 비교인 >=, <= 등도 제대로 수행한다. */
}
/* 사실 string 에서 제공하는 함수와 기능들은 교재에 소개된 것들 말고도 엄청나게 많아서 한 강좌에 다 넣을 수 없을 정도이다.
교재에서는 그 중 가장 많이 쓰는 기능만 소개한 것이다. */


/* 사원 관리 프로그램 */
/* 우리가 만들어야 할 프로그램의 목적은 회사의 사원들의 월급을 계산해서 한달에 총
얼마나 되는 돈을 월급으로 지출해야 하는지를 알려주는 단순한 프로그램이다. 그렇다면
일단 우리는 각 사원들의 정보를 클래스로 만들어서 데이터를 보관하도록 해야 할 것이다. 

사원들의 필요한 데이터는 이름, 나이, 직책과 직책의 순위에 해당하는 숫자값(예를 들어
평사원이면 1, 대리면 2,... 이런 식으로) 정도 입니다. 이를 바탕으로 간단히 클래스를 구성
해본다면 다음과 같이 짤 수 있을 것이다. */
class Employee {
    std::string name;
    int age;

    std::string position;
    int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank) {}

        //
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        //
        Employee() {}

        void print_infto() {
            std::cout << name << " ( " << position << " , " << age << " ) ==> "
                        << calculate_pay() << "만원" << std::endl;
        }
        int 
}




















/* 교재 311p */
/* vitual 키워드 */
#include <iostream>

class Base {
    public:
    Base() { std::cout << "기반 클래스" << std::endl; }

    virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
};
class Derived : public Base {

    public:
        Derived() : Base() { std::cout << "파생 클래스" << std::endl; }

        void what() { std::cout << "파생 클래스의 what()" << std::endl; } 
};
int main() {
    Base p;
    Derived c;

    Base* p_c = &c;     /* p_c 와 p_p 모두 Base 객체를 가리키는 포인터이다. 따라서, p_p->what() 와 p_c->what() 을 하면
    모두 Base 객체의 what() 함수가 실행되어서 둘 다 '기반' 이라고 출력이 되어야만 했다. */
    Base* p_p = &p;

    std::cout << " == 실제 객체는 Base ==" << std::endl;
    p_p->what();

    std::cout << " == 실제 객체는 Derived ==" << std::endl;
    p_c->what();

    return 0;
}


/* override 키워드 */
#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
        Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

        virtual void what() { std::cout << s << std::endl; }
};
class Derived : public Base {
    std::string s;

    public:
        Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

        void what() override { std::cout << s << std::endl; }
};


#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
        Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

        virtual void incorrect() { std::cout << "기반 클래스" << std::endl; }
};
class Derived : public Base {
    std::string s;

    public:
        Derived() : Base(), s("파생") {}

    void incorrect() const { std::cout << "파생 클래스" << std::endl; }
};
int main() {
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    std::cout << " == 실제 객체는 Base == " << std::endl;
    p_p->incorrect();

    std::cout << " == 실제 객체는 Derived == " << std::endl;
    p_p->incorrect();

    std::cout << " == 실제 객체는 Derived == " << std::endl;
    p_c->incorrect();
    return 0;
    /* 해당 코드를 보면 incorrect 함수가 제대로 오버라이드 되지 않았음을 알 수 있다. 
    그 이유는 Base 의 incorrect 함수와 Derived 의 incorrect 함수는 거의 똑같이 생기기는 했지만 사실 다르기 때문이다. 
    왜냐하면 Derived 의 incorrect 함수는 상수 함수이고, Base 의 incorrect 는 아니기 때문이다. */
}


/* Employee 문제를 해결하는 방법 */
#include <iostream>
#include <string>

class Employee {
    protected: 
        std::string name;
        int age;

        std::string position;   // 직책 (이름)
        int rank;               // 순위 (값이 클수록 높은 순위)

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank) {}

        // 복사 생성자
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        // 디폴트 생성자
        Employee() {}

        virtual void print_info() {
            std::cout << name << " ( " << position << " , " << age << " ) ==> "
                << calculate_pay() << "만원" << std::endl;
        }
        virtual int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
    int year_of_service;

    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            : year_of_service(year_of_service), Employee(name, age, position, rank) {}

            int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
            void print_info() override {
                std::cout << name << " ( " << position << " , " << age << " , " 
                        << year_of_service << "년차 ) ==> " << calculate_pay() << "만원"
                        << std::endl; 
            }
};
class EmployeeList {
    int alloc_employee;             // 할당한 총 직원 수
    int current_employee;           // 현재 직원 수
    Employee** employee_list;       // 직원 데이터

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            current_employee = 0;
        }
        void add_employee(Employee* employee) {
            // 사실 current_employee 보다 alloc_employee 가 더 
            // 많아지는 경우 반드시 재할당을 해야하지만, 여기서는
            // 최대한 단순하게 생각해서 alloc_employee 는
            // 언제나 current_employee 보다 크다고 생각한다.
            // (즉, 할당된 크기는 현재 총 직원 수보다 많다.)
            employee_list[current_employee] = employee;
            current_employee++;
        }
        int current_employee_num() { return current_employee; }

        void print_employee_info() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++) {
                employee_list[i]->print_info();                     //
                total_pay += employee_list[i]->calculate_pay();     // 이 두 부분은 employee_list[i] 가 Employee 냐 Manager 냐에 따라서 다르게 동작해야만 한다.
                /* 이렇게 같은 print_into 함수를 호출했음에도 불구하고 어떤 경우는 Employee 의 것이, 어떤 것은 Manager 의 것이 호출되는 일,
                즉 하나의 메소드를 호출했음에도 불구하고 여러가지 다른 작업들을 하는 것을 바로 '다형성(polymorphism)' 이라고 부른다. */
            }

            std::cout << "총 비용 : " << total_pay << "만원" << std::endl;
        }
        ~EmployeeList() {
            for (int i = 0; i < current_employee; i++) {
                delete employee_list[i];
            }
            delete[] employee_list;
        }
};
int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

    emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    emp_list.print_employee_info();
    return 0;
    /* 해당 코드를 컴파일하면 비록 Employee* 가 가리키고 있음에도 불구하고 Manager 면 Manager 의 함수를,
    Employee 면 Employee 의 함수를 잘 호출하고 있음을 알 수 있다. 물론 바뀐 것은 단 두 단어, virtual 키워드들을 Employee 의 함수들 앞에 추가해놓은 것 뿐이다. */
}

/* 생각해보기-문제 */
/* 문제 1:
그렇다면 프로그램 내부적으로 virtual 함수들은 어떻게 처리될까?? 즉, 이 포인터가 어떠한 객체를 가리키는지 어떻게 알 수 있을까??(난이도: 상) */




/* 상속과 관련된 잡다한 내용 */
/* 지난 강좌에서는 virtual 키워드의 기능에 대해서 설명하였다. virtual 키워드를 통해서 
'동적 바인딩' 이라는 것을 이루어낼 수 있었다. 이번 강좌에서는 가상 함수와 상속에 관련하여 잡다한 내용들을 모두 짚고 넘어가도록 하겠다. 

지난 강좌에서 배웠던 것을 간단하게 정리해보자면 다음과 같다. Parent 클래스와 Child 클래스에 모두 f 라는 가상함수가 정의되어 있고, 
Child 클래스가 Parent 를 상속 받는다고 해보자. 그런 다음에 동일한 Parent* 타이브이 포인터들도 각각 Parent 객체와 Child 객체를 가리킨다고 해보자. 
Parent* p = new Parent();
Parent* c = new Child();
컴퓨터 입장에서 p 와 c 는 모두 Parent 를 가리키는 포인터들이므로, 당연히
p->f();
c->f();
를 했을 때 모두 Parent 의 f() 가 호출되어야 하겠지만, 실제로는 f 가 가상함수이므로,
'실제로 p 와 c 가 가리키는 객체' 의 f, 즉 p->f() 는 Parent 의 f 를, c->f() 는 Child 
의 f 가 호출된다. 이와 같은 일이 가능한 이유는 f 를 가상함수로 만들었기 때문이다. */

/* virtual 소멸자 */
/* 사실 클래스의 상속을 사용함으로써 중요하게 처리해야하는 부분이 있다. 상속 시에, 소멸자를 가상함수로 만들어야 된다는 내용이다. */
#include <iostream>

class Parent {
    public:
        Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
        ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
    public:
        Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
        ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};
int main() {
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    { Child c; }
    std::cout << "--- Parent 포인터로 Child 를 가리켰을 때 ---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
    } 
}

/* virtual 키워드를 배운 우리들은 무엇을 해야하는지 알고 있을 것이다. 
단순히 Parent 의 소멸자를 virtual 로 만들어버리면 된다. Parent 의 소멸자를 
virtual 로 만들면, p 가 소멸자를 호출할 때, Child 의 소멸자를 성공적으로
호출할 수 있게 된다. */
#include <iostream>

class Parent {
    public:
        Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
        virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
    public:
        Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
        ~Child() { std::cout << "Child 소멸자 호출" << std::endl; } 
};
int main() {
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    {
        // 이 {} 를 빠져나가면 c 가 소멸된다. 
        Child c;
    }
    std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
    }
    /* 해당 소스코드를 컴파일하면 Child 소멸자가 제대로 호출됨을 확인할 수 있다.
    그렇다면 왜 Parent 소멸자는 호출이 되는지 의문을 가질 수 있다. 그 이유는 Child
    소멸자를 호출하면서, Child 소멸자가 '알아서' Parent 의 소멸자도 호출해주기 때문이다. 
    (Child 는 자신이 Parent 를 상속받는다는 것을 알고 있다.) 
    
    반면에 Parent 소멸자를 먼저 호출하게 되면, Parent 는 Child 가 있는지 없는지 모르므로, 
    Child 소멸자를 호출해줄 수 없다. (Parent 는 자신이 누구에게 상속해주는지 알 수 없다.)
    
    이와 같은 이유로, 상속될 여지가 있는 Base 클래스들은 (위 경우 Parent) 반드시 소멸자를 
    virtual 로 만들어주어야 나중에 문제가 발생할 여지가 없게 된다. */ 
}


/* 레퍼런스도 된다. */
/* 여태까지 기반 클래스에서 파생 클래스의 함수에 접근할 때 항상 기반 클래스의 포인터를
통해서 접근하였다. 하지만, 사실 기반 클래스의 레퍼런스여도 문제 없이 작동한다. 아래의 간단
한 소스코드 예제를 통해서 살펴보자. */
#include <iostream>

class A {
    public:
        virtual void show() { std::cout << "Parent !" << std::endl; }
};
class B : public A {
    public:
        void show() override { std::cout << "Child!" << std::endl; }
};

void test(A& a) { a.show(); }
int main() {
    A a;
    B b;
    test(a);
    test(b);

    return 0;
    /* test  함수를 살펴보면 A 클래스의 레퍼런스를 받게 되어있지만 
    test(b);
    를 통해서 B 클래스의 객체를 전달하였는데도 잘 작동하였다. 이는, B 클래스가 A 클래스를 상속받고있기 때문이다.
    즉, 함수의 타입이 기반 클래스여도 그 파생 클래스는 타입 변환되어 전달할 수 있다. 
    
    따라서 test 함수에서 show() 를 호출하였을 때 인자로 b 를 전달하였다면, 비록 전달된 인지가 
    A 의 객체라고 표현되어 있지만 show 함수가 virtual 으로 정의되어 있기 때문에 알아서 B 가 show 함수를 찾아내서 호출하게 된다. 
    물론 test 에 a 를 전달하였을 때에는 A 의 show 함수가 호출될 것이다. */
}

/* 순수 가상 함수(pure virtual function) 와 추상 클래스(abstract class) */
#include <iostream>

class Animal {
    public:
    Animal() {}
    virtual ~Animal() {}
    virtual void speak() = 0;
};
/* Animal 클래스의 speak 함수를 살펴보자. 다른 함수들과는 달리, 함수의 몸통이 정의되어있지 않고 
단순히 = 0; 으로 처리되어 있는 가상 함수이다. 
그렇다면 이 함수는 무엇을 하는 함수일까?? 그 답은, '무엇을 하는지 정의되어 있지 않은 함수' 이다. 
다시 말해 이 함수는 반드시 오버라이딩 되어야만 하는 함수이다. 
이렇게 가상 함수에 = 0; 을 붙여서 반드시 오버라이딩 되도록 만든 함수를 완전한 가상 함수라고 해서 '순수 가상 함수(pure virtual function)' 라고 부른다. 
당연하게도, 순수 가상 함수는 본체가 없기 때문에 호출하는 것이 불가능하다. 그렇기 때문에 Animal 객체를 생성하는 것 또한 불가능하다. */
/* 따라서 Animal 처럼 순수 가상 함수를 최소 한 개 이상 포함하고 있는 클래스는 객체를 생성할 수 없으며, 인스턴스화 시키기 위해서는 이 클래스를 상속받는
클래스를 만들어서 모든 순수 가상 함수를 오버라이딩 해주어야만 한다. 
이렇게 순수 가상 함수를 최소 한 개 포함하고 있는-반드시 상속되어야하는 클래스를 가리켜 '추상 클래스(abstract class)' 라고 부른다. 
(참고로, private 안에 순수 가상 함수를 정의하여도 문제될 것이 없다. private 에 정의되어 있다고 해서 오버라이드 안된다는 뜻이 아니기 때문이다. 다만 자식 클래스에서 호출을 못할 뿐이다.) */

class Dog : public Animal {
    public:
    Dog() : Animal() {}
    void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
    public:
    Cat() : Animal() {}
    void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();
}


/* A, B 생성자의 호출 순서 알아보기 */
#include <iostream>

class A {
    public:
    int a;

    A() { std::cout << "A 생성자 호출" << std::endl; }
};

class B {
    public:
    int b;

    B() { std::cout << "B 생성자 호출" << std::endl; }
};
class C : public A, public B {
    public:
    int c;

    C() : A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};
int main() { C c; }
/* 위의 소스코드를 호출하면 A -> B -> C 순으로 호출됨을 알 수 있다. 
그리고 
class C : public A, public B
에서 
class C : public B, public A
로 바꾸어서 컴파일을 해보면 재미있게도 결과가 아래와 같은 순서로 나온다. 
B 생성자 호출
A 생성자 호출
C 생성자 호출
순으로 B 의 생성자가 A 보다 먼저 호출됨을 알 수 있다. 몇번 더 실험을 해보면 이 순서는 
다른 것들에 의해 좌우되지 않고 오직 상속하는 순서에만 좌우됨을 확인할 수 있다. */


/* 다중 상속 시 주의할 점 */
/* 다중 상속은 C++ 에서 많이 사용되는 기법 중 하나이다. 하지만, 다중 상속을 올바르게 사용하기 위해서는 몇 가지 주의해야할 점들이 있다. */
class A {
    public:
    int a;
};
class B {
    public:
    int a;
};
class C : public B, public A {
    public:
    int c;
};
/* 위처럼 만일 두 개의 클래스에서 이름이 같은 멤버 변수나 함수가 있다고 해보자. 예를 들어
위의 예에서는 클래스 A 와 B 에 모두 a 라는 이름의 멤버 변수가 들어가 있다. 
int main() {
    C c;
    c.a = 3;
}
그렇다면 만일 클래스 C 의 객체를 생성해서 위처럼 중복되는 멤버 변수에 접근한다면 
B 의 a 인지, A 의 a 인지 구분할 수 없다는 컴파일 오류가 발생하게 된다. 마찬가지로, 
클래스 A 와 B 에 같은 이름의 함수가 있다면 똑같이 어떤 함수를 호출해야될 지 구분할 수 
없을 것이다. */


/* 다중 상속은 언제 사용해야 할까?? */
/* 예를 들어서 우리가 차량(Vehicla) 에 관련한 클래스를 생성한다고 해보자. 
차량의 종류로는 땅에서 다니는 차, 물에서 다니는 차, 하늘에서 다니는 차, 우주에서 다니는 차들이 있다고 해보자.
또한, 이 차량들은 각기 다른 동력원들을 사용하는데, 휘발유를 사용할 수도 있고, 풍력으로 갈수도 있고 원자력으로 갈수도 있고
페달을 밟아서 갈수도 있다. 이러한 차량들을 클래스로 나타내기 위해서, 다중 상속을 활용할 수 있지만 그 전에, 아래와 같은 
질문들에 대한 대답을 생각해보자. 
-LandVehicla 을 가리키는 Vehicle& 레퍼런스를 필요로 할까?? 다시 말해, Vehicle 레퍼런스가 실제로는 LandVehicle 을 참조하고 
있다면, Vehicle 의 멤버 함수를 호출하였을 때, LandVehicle 의 멤버 함수가 오버라이드되어서 호출되기를 바라나??
-GasPoweredVehicle 의 경우도 마찬가지이다. 만일 Vehicle 레퍼런스가 실제로는 GasPoweredVehicle 을 참조하고 있을 때, Vehicle
레퍼런스의 멤버함수를 호출한다면, GasPoweredVehicle 의 멤버함수가 오버라이드 되어서 호출되기를 원하나?? 

만일 두 개의 질문에 대한 대답이 모두 '예' 라면 다중 상속을 사용하는 것이 좋을 것이다. 하지만 그 전에, 몇 가지 고려할 점이 있따. 
만약에 이 차량이 작동하는 환경이 N 개가 있고 (땅, 물, 하늘, 우주 등등) 동력원의 종류가 M 개가 있다고 해보자. 
이를 위해서, 크게 3 가지 방법으로 이러한 클래스를 디자인할 수 있다. 바로 브리지 패턴(bridge pattern), 중첩된 일반화 방식(nested generalization), 다중 상속이다. 
각각의 방식에는 모두 장단점이 있다. 

1) 브리지 패턴의 경우, 차량을 나타내는 한 가지 카테고리를 아예 멤버 포인터로 만들어버린다. 예를 들어서 Vehicle 클래스의 파생 클래스로 LandVehicle, SpaceVehicle 클래스들이 
있고, Vehicle 클래스의 멤버 변수로 어떤 엔진을 사용하는지 가리키는 Engine* 멤버 변수가 있다. 이 Engine 은 GasPowered, NuclearPowered 와 같은 Engine 의 파생 클래스들의
객체들을 가리키게 된다. 그리고 런타임 시에 사용자가 Engine 을 적절히 설정해주면 된다. 이 경우 동력원이나 환경을 하나 추가하더라도 클래스를 1 개만 더 만들면 된다. 
즉, 총 N + M 개의 클래스만 생성하면 된다는 뜻이다. 
하지만 오버라이딩 가짓수가 N + M 개 뿐이므로 최대 N + M 개 알고리즘 밖에 사용할 수 없다. 만일 우리가 N x M 개의 모든 상황에 대한 섬세한 제어가 필요하다면 브리지 패턴을 사용하지
않는 것이 좋다. 또한, 컴파일 타임 타입 체크를 적절히 활용할 수 없다는 문제가 있다. 예를 들어서 Engine 이 페달이고 작동 환경이 우주라면, 애초에 해당 객체를 생성할 수 없어야 하지만
이를 컴파일 타임에서 강제할 방법이 없고 런타임에서나 확인할 수 있게 된다. 뿐만 아니라, 우주에서 작동하는 모든 차량을 가리킬 수 있는 기반 클래스를 만들 수 있지만 (SpaceVehicle 클래스)
, 작동 환경에 관계 없이 휘발유를 사용하는 모든 차량을 가리킬 수 있는 일반 클래스를 만들수는 없다. 
2) 중첩된 일반화 방식을 사용하게 된다면, 한 가지 계층을 먼저 골라서 파생 클래스들을 생성한다. 예를 들어서 Vehicle 클래스의 파생 클래스들로 LandVehicle, EaterVehicle 등등이 있을 것이다.
그후에, 각각의 클래스들에 대해 다른 계층에 해당하는 파생 클래스들을 더 생성한다. 예컨대 LandVehicle 의 경우 동력원으로 휘발유를 사용한다면 GasPoweredLandVehicle, 우너자력을 사용한다면 
NuclearPoweredLandVehicle 클래스를 생성할 수 있다. 따라서 최대 N x M 가지의 파생 클래스들을 생성할 수 있게 된다. 따라서 브릿지 패턴에 비해서 좀 더 섬세한 제어를 할 수 있게 된다. 
왜냐하면 오버라이딩 가짓수가 N + M 이 아니라 N x M 이 되기 때문이다. 하지만 동력원을 하나 더 추가하게 된다면 최대 N 개의 파생 클래스를 더 만들어야 한다. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~(교재 338p 에 나오는 내용들~~너무 많아서 다 적을 수 없었음!! 필요하면 교재의 해당 부분을 복습하기)
가장 중요한 점은, 위 3 가지 방식 중에서 절대적으로 우월한 방식은 없다는 것이다. 상황에 맞게 최선의 방식을 골라서 사용해야 한다. 
다중 상속은 만능 툴이 아니다. 실제로 다중 상속을 이용해서 해결해야 될 것 같은 문제도 알고보면 단일 상속을 통해 해결할 수 있는 경우들이 있다. 하지만 적절한 상황에 다중 상속을 이용한다면 
좋은 도구가 될 수 있다. 

아무래도 이번 강좌는 상속에 대한 중요한 요소들을 간단하게 짚고 넘어가는 것이라 실질적인 프로그램은 만들지 않았다. 하지만, 가상 함수와 상속이 어떻게 돌아가는지 완벽하게 이해하는 것이 좋다. 
저자의 경우, C++ 을 처음 배울 때, 이 부분에서 많이 헷갈려서 고생을 한 기억이 있다. 여러분들도 가상 함수를 포함하는 간단한 프로그램을 작성해서 어떻게 함수들이 호출되는지 살펴보길 바란다. */


/* istream 클래스 */
/* 여태까지 ios_base 와 ios 클래스들이 입출력 작업을 위해 바탕을 깔아주는 클래스였다면, 
istream 은 실제로 입력을 수행하는 클래스이다. 
대표적으로 우리가 항상 사용하던 operator>> 가 이 istream 클래스에 정의되어있는 연산자이다. 
또, cin 은 istream 클래스의 객체 중 하나이다. 그렇기 때문에 우리는
std::cin >> a;
와 같은 작업을 할 수 있었던 것이다. 우리가 어떤 타입에 대해서도 cin 을 사용할 수 있었던 이유는 (cin 은 데이터 입력을 뜻한다.)
(a 가 char 이냐 int 이냐에 상관없이) 바로 operator>> 가 그런 모든 기본 타입들에 대해서는 정의가 되어있기 때문이다. */
istream& operator>>(bool& val);
istream& operator>>(short& val);
istream& operator>>(unsigned short& val);
istream& operator>>(int& val);
istream& operator>>(unsigned int& val);
istream& operator>>(long& val);
istream& operator>>(unsigned long& val);
istream& operator>>(long long& val);
istream& operator>>(unsigned long long& val);
istream& operator>>(float& val);
istream& operator>>(double& val);
istream& operator>>(long double& val);
istream& operator>>(void*& val);
/* 그렇다고 해서, 우리가 언제나 위 타입들 빼고는 operator>> 로 받을 수 없는 것은 아니다. 
실제로 istream 클래스의 멤버 함수로는 없지만,
std::string s;
std::cin >> s;
std::string 클래스의 객체 s 도 cin 으로 입력받을 수 있다. 이와 같은 일이 가능한 이유는 
이전에 연산자 오버로딩 강좌에서 배웠듯이, 멤버 함수를 두는 것 말고도, 외부 함수로 연산자 오버로딩을 할 수 있기 때문이다. */


/* operator>> 의 또다른 특징으로는, 모든 공백믄자(띄어쓰기나 엔터, 탭 등) 을 입력시에 무시해버린다는 점이다.
그렇기 때문에, 만일 cin 을 통해서 문장을 입력받는다면 첫단어만 입력받고 나머지를 읽을 수 없다. 예제로 간단히 살펴보자면
*/
#include <iostream>
#include <string>

int main() {
    std::string s;
    while (true) {
        std::cin >> s;
        std::cout << "word : " << s << std::endl;
    }
    /* 해당 소스코드를 컴파일하면 문장을 입력하더라도 공백문자(띄어쓰기) 에 따라서 각각을 분리해서 입력받게 되는 것이다. 
    위와 같이 비록 operator>> 가 매우 편리해보이지만, 반드시 주의해야 할 점이 있다. (주의점은 아래에 명시) */
}


// 주의할 점
#include <iostream>
using namespace std;
int main() {
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (t == 0) break;
        /* 해당 소스코드는 그냥 평범하게 숫자를 잘 입력받는 프로그램이다. 만일 사용자가 숫자만 꼬박꼬박 잘 입력하면
        정말 좋겠지만, 문제는 그렇지 않다는 점이다. 프로그래머는 언제나 사용자의 기괴한 행동들에 대해서 모두 대응할 수 있어야 한다.
        만일 사용자가, 숫자가 아니라 문자를 입력했다고 하자. 그렇다면 프로그램은 '무한루프' 라는 기괴한 결과를 보여주게 된다. */
        /* 이러한 무한루프에 빠지게 되는 이유는 operator>> 가 어떻게 이를 처리하는지 이해하면 알 수 있다. 
        앞서 ios 클래스에서 스트림의 상태를 관리한다고 하였다. 이때, 스트림의 상태를 관리하는 플래스(flag-그냥 비트 1 개라고 생각하면 된다.)
        는 4 개가 정의되어 있다. 이 4 개의 플래그들이 스트림이 현재 어떠한 상태인지에 대해서 정보를 보관한다는 뜻이다. 이 4 개의 플래그는 각각 
        goodbit, badbit, eofbit, failbit 이렇게 4 개 종류가 있다. 각각의 비트들이 켜져있는지 꺼져있는지(즉 1 인지 0 인지) 에 따라 우리는
        스트림의 상태를 알 수 있게 된다. */
    }
}
/* 각각의 비트들에 대해서 간단히 설명해보자면
-goodbit : 스트림에 입출력 작업이 가능할 때
-badbit : 스트림에 복구 불가능한 오류 발생 시
-failbit : 스트림에 복구 가능한 오류 발생 시
-eofbit : 입력 작업 시에 EOF 도달시
위와 같은 상황일 때 각각의 비트들이 켜지는 것이다. 만일 위와 같이 문자를 입력할 경우 */


// 해결 방안
#include <iostream>
#include <string>

int main() {
    int t;
    while (std::cin >> t) {
        std::cout << "입력::" << t << std::endl;
        if (t == 0) break;
    }
}

/* 형식 플래그(format flag) 와 조작자(Manipulator) */
#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        std::cin >> t;
        std::cout << "입력::" << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();   // 플래그들을 초기화하고
                                // std::cin.ignore(100, 'n');
                                // 개행문자가 나올 때까지 
                                // 무시한다.
        }
        if (t == 0) break; 
    }
}


/* 조작자의 사용 */
#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        std::cin >> std::hex >> t;
        std::cout << "입력 ::" << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();                               // 플래그들을 초기화하고
            std::cin.ignore(100, 'n');                      // 개행문자가 나올 때까지 무시한다.
        }
        if (t == 0) break;
    }
    /* 해당 소스코드도 위의 코드와 마찬가지로 16 진수를 잘 입력받는다는 사실을 확인할 수 있다.
    그 이유는 바로 위에서 hex 가 cin 에서 수를 받는 방식을 바꿔버렸기 때문이다. 이 때문에 hex 와 같이,
    스트림을 조작하여 입력 혹은 출력 방식을 바꿔주는 함수를 조작자라고 부른다. (hex 는 함수이다!!)
    참고로, 위에서 사용하였던 형식 플래스 hex 와 이 hex 는 이름만 같지 아예 다른 것이다. (그렇기에, 위에서는 ios_base::hex 로 사용하였다.)
    위의 형식 플래그 hex 는 ios_base 에 선언되어 있는 단순한 상수 '값' 이다. 반면에 조작자 hex 의 경우 ios 에 
    정의되어 있는 '함수' 이다. 이 조작자 hex 의 정의를 살펴보자면, 아래와 같이 ios_base 객체를 레퍼런스로 받고, 다시 그 객체를 리턴하도록 정의되어있다. */
}

/* 스트림 버퍼에 대해 */
/* 모든 입출력 객체들은 이에 대응되는 스트림 객체를 가지고 있게 된다. 따라서 C++ 의 입출력 라이브러리에는 
이에 대응되는 스트림 버퍼 클래스도 있는데, 이름이 streambuf 클래스이다. 사실, 스트림이라 하면 그냥 쉽게 말해서
문자들의 순차적인 나열이라고 보면 된다. 그냥 문자들이 순차적으로 쭈르륵 들어오는 것이 스트림이라 생각하면 된다. 
예를 들어서 우리가 화면에 입력하는 문자도 스트림을 통해서 프로그램에 전달되는 것이고, 하드디스크에서 파일을 읽는 것도,
다른 컴퓨터와 TCP/IP 통신하는 것도(결국 문자들을 주르륵 주고받는 것이니까) 모두 스트림을 통해 이루어진다는 것이다.
심지어 C++ 에서는 std::stringstream 을 통해서 평범한 문자열을 마치 스트림인 것처럼 이용할 수도 있게 해준다.
streambuf 클래스는 스트림에 대한 가장 기본적인 제어를 담당하고 있다. */


/* C++ 파일 입출력 */
/* 지난 강좌에서 C++ 에서 표준 스트림과의 입출력에 대해서 간단히 다루어보았다. 
이번에는 이를 이용하여 파일 스트림과의 입출력을 다루어 보도록 하겠다. 사실, 파일
입출력은 표준 스트림에서 입출력 하는 것과 크게 다른 점은 없다. 다만, 스트림이 화면 
혹은 키보드에서 파일로 바뀌었을 뿐이다. */

/* fstream */
/* 파일 스트림은 기본적인 istream 이나 ostream 클래스보다 더 지원하는 기능이 많기 때문에
이를 상속 받아서 작성되었으며, 각각을 상속받은 것이 ifstream 과 ofstream 이다. 이들 클래스를
모두 포함하는 라이브러리로 fstream 을 사용하면 된다. */

// 파일에서의 입출력
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    /* 기존에 cout 나 cin 을 사용했을 때는 이미 표준 입출력에 연동이 되어있는 상황이었지만, 파일 입출력의 경우
    어느 파일에 입출력을 해야할지 지정해야 하는데, 이를 ifstream 객체의 생성자에 연동하고자 하는 파일의 경로("C:\\a\\b\\c.txt" 와 같이)
    를 전달하면 된다. 위 경우 편의상 경로를 저렇게 썼지만(이 경우 실행 파일과 같은 경로에 있는 파일을 찾게 된다. 다만 비주얼 스튜디오 상에서
    실행할 경우에는 소스파일과 같은 경로에 있는 것을 찾는다.) */
    std::string s;
    /* 위와 같이 생성자에 파일 경로를 지정하면, 해당하는 파일을 찾고 열게 된다. 만일 파일이 존재하지 않는다면 파일을 열 수 없다. 따라서 파일이 열렸는지의 유무는 아래의 줄과 같이 확인할 수 있다.*/
    if (in.is_open()) {     /* is_open 은 기존의 istream 에는 없고 ifstream 에서 상속받으면서 추가된 함수이다. 파일이 열렸는지의 유무를 리턴한다. 만일 해당 경로에 있는 파일이 존재하지 않는다면 false 를 리턴한다. */
        in >> s;            /* 마지막으로 마치 cin 을 사용하는 것처럼 in 객체를 이용해서 파일로부터 읽을 수 있다. (cin 에서 >> 로 읽을 때 공백 문자가 나올때까지 읽었던 것처럼, 여기도 동일하다.) 
        여기서 한 가지 흥미로운 점이 있다. C 언어에서 기억을 되돌려보자면 파일 입출력을 한 후에 꼭 fclose 를 해주어야 했다. 그런데 여기서는 신기하게도 그러한 작업을 하지 않는다. 
        이미 ifstream 객체의 소멸자에서 자동적으로 close 를 해주기 때문이다. (다만, close 를 직접 해야 하는 경우도 있다.) */
        std::cout << "입력 받은 문자열:: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    return 0;
}


#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열::" << s<< std::endl;
    }

    in.close();
    in.open("other.txt");

    if (in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열::" << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
    }

    return 0;
}
/* 위처럼 새로운 파일에서 같은 객체가 입력을 받기 위해서는 기존 파일 스트림과의 연결을 종료하고, 새로운 파일과 연결을 시켜주면 된다. 
기존 파일과의 스트림 종료는 close 함수가, 새로운 파일과의 연결은 open 함수가 수행하고 있다. open 함수가 있기에 굳이 ifstream 객체 생성자에서 
파일 경로를 바로 지정해줄 필요는 없고, 나중에 open 으로 원하는 파일을 열어도 상관없다. */


/* 이진수로 읽기 */
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt", std::ios::binary);
    std::string s;

    int x;
    if (in.is_open()) {
        in.read((char*)(&x), 4);
        std::cout << std::hex << x << std::endl;    /* 참고로, cout 에서 사용한 hex 역시 지난 강좌에서 cin 에서 사용한 hex 와 비슷한 부류로 16 진수로 정수 데이터를 표시해준다. */
    } else {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
    }
    return 0;
}



/* 파일 전체 읽기 */
/* 파일 전체를 한번에 읽는 방법!! */
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        // 위치 지정자를 파일 끝으로 옮긴다.
        in.seekg(0, std::ios::end);         /* C 언어에서 fseek 과 같은 함수로, 파일 위치 지정자를 사용자의 입맛에 맞게 이리저리 움직일 수 있다.
        두 번째 인자는, 파일 내 위치를 의미하고, 첫 번째 인자는 그 위치로부터 얼마만큼 떨어져 있느냐를 의미한다. 우리의 경우 위치 지정자를 파일의 끝에서
        0 만큼 떨어진 것, 즉 파일의 끝으로 이동시켰다. */

        // 그리고 그 위치를 읽는다. (파일의 크기)
        int size = in.tellg();              /* tellg 함수는 위치 지정자의 위치(시작 지점으로부터의) 를 반환한다. 현재 우리가 위치 지정자를 파일 끝으로 이동시켜놓았기 때문에 
        tellg 함수는 파일의 크기(바이트 단위) 로 반환할 것이다. 그리고 문자열에 그만큼의 크기를 할당해준다. */

        // 그 크기의 문자열을 할당한다. 
        s.resize(size);                   

        // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
        in.seekg(0, std::ios::beg);          /* 이제 파일을 읽어야할텐데, 파일 위치 지정자를 끝으로 옮겨놓았기 때문에 읽기 위해서는 다시 처음으로 옮겨줘야 한다. 
        옮기지 않을 경우 위치 지정자가 파일 끝에 있으므로 아무것도 읽지 못할 것이다. */

        // 파일 전체 내용을 읽어서 문자열에 저장한다. 
        in.read(&s[0], size);               /* 마지막으로, 파일 전체의 내용을 문자열에 저장하면 된다. */
        std::cout << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
    }

    return 0;
}


/* 파일 전체를 한 줄씩 읽기 */
// getline 으로 읽어들이기
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
        return 0;
    }

    while (in) {                        /* ifstream 에는 자기 자신을 bool 로 캐스팅할 수 있는 '캐스팅 연산자(operator bool())' 가 오버로딩 
    되어있다. 따라서 위와 같이 while 문 조건에 in 을 전달한다면 bool 로 캐스팅하는 연산자 함수가 호출된다. 이때 in 이 true 이기 위해서는 다음
    입력 작업이 성공적이어야만 하고 현재 스트림에 오류 플래그가 켜져 있지 않아야 한다. 
    
    하지만 getline 함수는 개행 문자(혹은 지정한 문자) 가 나오기 전에 지정한 버퍼의 크기가 다 차게 된다면 failbit 를 켜게 되므로 버퍼의 크기를 너무 
    작게 만든다면 정상적으로 데이터를 받을 수 없다. 따라서 getline 을 사용하기 전에 이와 같은 조건을 꼭 확인해야 한다. 
    이와 같은 한계점을 극복하기 위해서 std::string 에서 getline 함수를 제공하고 있다. (아래의 소스코드 참고!!!) */
        in.getline(buf, 100);           /* 위 ifstream 객체의 멤버 함수로 존재하는 getline 함수는 파일에서 개행문자(\n) 이 나올 때까지
        최대 지정한 크기 - 1 만큼 읽게 된다. 왜 하나 적게 읽냐면, buf 의 맨 마지막 문자로 널 종료 문자를 넣어주어야하기 때문이다. 
        위의 경우, buf 에 최대 99 글자까지 입력 받을 수 있다. 물론 개행 문자 말고도 우리가 지정한 문자가 나올 때까지 읽는 것을 바꾸는 것 역시 
        가능하다. 이 경우 원하는 문자를 인자로 전달해주면 해당 문자가 나올 때까지 입력받는다. 예를 들어서
        in.getline(buf, 100, '.');
        이런 식으로 하면 마침표 . 가 나올 때까지 입력받게 된다. */
        std::cout << buf << std::endl;
    }

    return 0;
}


// std::string 에 정의된 getline 사용
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");

    if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
        return 0;
    }

    std::string s;
    while (in) {
        getline(in, s);
        std::cout << s << std::endl;
    }

    return 0;
}


/* 파일에 쓰기 */
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 파일 쓰기 준비
    std::ofstream out("test.txt");

    std::string s;
    if (out.is_open()) {
        out << "이걸 쓰자~~~!!";
    }
    return 0;
    /* 해당 코드를 성공적으로 컴파일하면, test.txt 에 있던 내용이 잘 바뀐 것을 확인할 수 있다. 
    만일 test.txt 가 존재하지 않을 경우, test.txt 를 생성한 뒤에, 생성이 성공하였다면 출력하게 된다. 
    ofstream 은 열려는 파일이 존재하지 않으면 해당 파일을 생성하고 열게 된다. 만일, 해당 파일이 이미 
    존재한다면, 특별한 설정을 하지 않은 한 해당 파일 내용이 다 지워지고 새로운 내용으로 덮어씌워지게 된다. */
}


#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 쓰기 준비
    std::ofstream out("test.txt", std::ios::app);

    std::string s;
    if (out.is_open()) {
        out << "덧붙이기";
    }

    return 0;
    /* 성공적으로 컴파일하였다면, test.txt 안에 있던 기존의 내용 뒤에 '덧붙이기'가 더해진다. */
}
/* out 객체를 생성할 때 옵션으로 app 을 주게 되면, 파일에 스트림을 연결할 때 기존 파일의 내용을 지우고 
새로 쓰는 것이 아니라 위 사진처럼 그 뒤에 새로운 내용을 붙여 쓰게 된다.
 
앞서 나왔던 ios::binary 와 ios::app 말고도 4 개가 더 있다. 이들을 나열해보자면
1) ios::ate
자동으로 파일 끝에서부터 읽기와 쓰기를 실시한다. (즉 파일을 열 때 위치 지정자가 파일 끝을 가리키고 있게 된다.) 
2) ios::trunc
파일 스트림을 열면 기존에 있던 내용들이 모두 지워진다. 기본적으로 ofstream 객체를 생성할 때 이와 같은 설정으로 만들어진다. 
3) ios::in, std::ios::out
파일에 입력을 할지 출력을 할지 지정하며, ifstream 과 ofstream 객체를 생성할 때 각각은 이미 설정되어 있다. */
/* 참고로 ios::ate 와 ios::app 은 비슷해보이지만, 차이가 있다면 ios::app 의 경우 원본 파일의 내용을 무조건적으로 보장하지만, 
ate 는 위치 지정자를 그 이전으로 옮길 수 있다. 즉 app 의 경우 파일 위치 지정자가 기존 파일의 끝이 시작점이라고 생각하여 움직이며
ate 의 경우 기존 파일을 포함해서 움직인다. (사실 ate 의 경우 사용할 일이 거의 없을 것이다.) 
그렇다고 해서 ate 를 이용해서 기존에 있는 파일 데이터 한 가운데에 무언가를 끼워 넣을 수 있는 것은 아니다. */

// ate 와 app
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 두 파일에는 모두 abc 라고 써 있었다. 
    //std::ofstream out("test.txt", std::ios::app);
    std::ofstream out2("test.txt", std::ios::ate);

    //out.seekp(3, std::ios::beg);
    out2.seekp(3, std::ios::beg);

    //out << "추가";
    out2 << "추가";

    return 0;
    /* 주의: app 와 ate 를 각각 컴파일해보아야한다~!!
    app 를 사용한 경우, abc 바로 뒤에 '추가' 문자열이 붙어있는 모습으로 나타난다. 비록 파일 위치 지정자를 
    앞에서 3 칸 떨어진 곳으로 이동하였음에도, app 모드로 읽었을 때 현재 파일은 빈 파일이라고 생각되어 
    위치 지정자라 움직일 공간이 없기에, 실제로 위치 지정자는 움직이지 않고 출력되었다. 
    
    반면에 ate 를 사용한 경우, 앞에서 3 칸 띄어진 곳에 '추가' 라고 문자열이 출력되었지만 기존의 abc 라는 데이터는
    지워졌다. 즉 ate 모드로 파일을 열게 되면 비록 스트림 위치 지정자는 움직여서 3 칸 뒤에 출력되기는 하지만 기존에 
    써져 있던 내용은 모두 지워진다. (ate 는 기존 파일의 내용을 보존하지 않는다.) */
}


/* std::ofstream 연산자 오버로딩 하기 */
#include <fstream>
#include <iostream>
#include <string>

class Human {
    std::string name;
    int age;

    public:
    Human(const std::string& name, int age) : name(name), age(age) {}
    std::string get_info() {
        return "Name :: " + name + " / Age :: " + std::to_string(age);
    }

    friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h) {
    o << h.get_info();
    return o;
}
int main() {
    // 
    std::ofstream out("test.txt");

    Human h("이경하", 22);
    out << h << std::endl;

    return 0;
    /* 성공적으로 컴파일하였다면 
    Name :: 이경하 / Age :: 22
    라는 문장이 파일에 저장될 것이다. 
    
    이전 강좌에서 입출력 연산자 오버로딩을 한 번 해보았는데, ofstream 이라고 해서 달라지는 것은 없다.
    단순히 ofstream 객체의 레퍼런스를 받고, 다시 이를 리턴하는 operator<< 함수를 정의해주면 된다. */
}


/* 문자열 스트림(std::stringstream) */
#include <iostream>
#include <sstream>

int main() {
    std::istringstream ss("123");       /* 예를 들어서 우리는 해당 줄을 통해서 문자열 "123" 이 기록되어 있는 입력 스트림을 생성하였다.
    마치 파일에 123 이라 기록해놓고 거기서 입력 받는 것과 동일하다고 생각하면 된다. */
    int x;
    ss >> x;        /* 그래서 마치 파일에서 숫자를 읽어내는 것처럼 std::istringstream 을 통해서 123 을 읽어낼 수 있다. 
    이를 활용하면 atoi 와 같은 함수를 사용할 필요없이 간편하게 문자열에서 숫자로 변환하는 함수를 만들 수 있다. */

    std::cout << "입력 받은 데이터:: " << x << std::endl;

    return 0;
    /* 성공적으로 컴파일 하였다면
    입력 받은 데이터:: 123
    라는 결과가 출력된다. 
    
    sstream 에는 std::istringstream 이 정의되어 있는데 이는 마치 문자열을 하나의 스트림이라 생각하게 해주는 가상화 장치라고 보면 된다. */
}

#include <iostream>
#include <sstream>
#include <string>

double to_number(std::string s) {
    std::istringstream ss(s);
    double x;

    ss >> x;
    return x;
}
int main() {
    std::cout << "변환:: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;

    return 0;
}


/* C++ 파일 입출력 */
/* fstream */
/* 파일 스트림은 기본적인 istream 이나 ostream 클래스보다 더 지원하는 기능이 많기 때문에 
이를 상속받아서 작성되었으며, 각각을 상속받은 것이 ifstream 과 ofstream 이다. 이들 클래스를
모두 포함하는 라이브러리로 fstream 을 사용하면 된다. */

// 파일에서의 입출력
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    /* 이 경우 실행 파일과 같은 경로에 있는 파일(txt) 을 찾게 되지만,
    비주얼 스튜디오 상에서 실행할 경우에는 소스 파일과 같은 경로에 있는 것을 찾게 된다. */
    std::string s;

    if (in.is_open()) {     /* is_open 은 기존의 istream 에는 없고 ifstream 에서 상속받으면서
                                추가된 함수이다. 이 함수는 파일이 열렸는지 유무를 확인한다. 
                                (만일 해당 경로에 있는 파일이 존재하지 않는다면 false 를 리턴할 것이다.) */
        in >> s;            /* 마치 cin 을 사용하는 것처럼 in 객체를 이용해서 파일로부터 읽을 수 있다. 
                                (cin 에서 >> 로 읽을 때, 공백 문자가 나올 때까지 읽었던 것처럼 여기도 동일하다.) */
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다! " << std::endl;
    }
    return 0;
    /* 해당 코드에서는 흥미로운 점이 있다. C 언어에서 기억을 되돌려 보자면 파일 입출력을 한 후에 꼭 fclose 를 해주어야 했다.
    그런데 여기에서는 신기하게도 그러한 작업을 하지 않는다. 그 이유는 이미 ifstream 객체의 소멸자에서 자동적으로 close 를 해주기
    때문이다. 
    다만, close 를 직접 해야 되는 경우도 있다. (바로 아래의 코드 참고!!) */
}


#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in >> s;
        std::cout << "입력받은 문자열:: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    in.close();             /* 해당 코드처럼 새로운 파일(other.txt) 에서 같은 객체가 
                            입력을 받기 위해서는 기존 파일(test.txt) 스트림과의 연결을
                            종료하고, 새로운 파일과 연결을 시켜주면 된다. 
                            기존 파일과의 스트림 종료는 close 함수가, 새로운 파일과의 
                            연결은 open 함수가 수행하고 있다. open 함수가 있기에 굳이 
                            ifstream 객체 생성자에서 파일 경로를 바로 지정해줄 필요는 없고,
                            나중에 open 으로 원하는 파일을 열어도 상관없다. */
    in.open("other.txt");

    if (in.is_open()) {
        in >> s;
        std::cout << "입력받은 문자열:: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
    }

    return 0;
}


// 이진수로 읽기
#include <fstream>
#include <iostream>
#include <string>

int main() {
    //
    std::ifstream in("test.txt", std::ios::binary);
    /* 윗줄과 같이 ifstream 객체를 생성할 때 생성자에 옵션으로 binary 형태로 받겠다고 명시할 수 있다. 
    이 말은 문자열 데이터를 받는게 아니라 그냥 이진 그대로의 값을 받아내겠다는 의미이다. 
    만일 아무것도 명시하지 않는다면 위에서 보았던 것처럼 문자열 형태로 데이터를 받는다. 
    
    이 binary 는 단순한 숫자로 ios 에 정의되어 있다. binary 말고도 설정할 수 있는 여러가지 옵션이 있는데,
    이들을 OR 해서 여러가지 옵션을 조정할 수 있다. */
    std::string s;

    int x;
    if (in.is_open()) {
        in.read((char*)(&x), 4);    /* read 함수는 말 그대로, 4 바이트의 내용을 읽으라는 의미로, 
                                    첫 번째 인자에 해당하는 버퍼를 전달해줘야 한다. 
                                    우리의 경우 int 변수를 마치 4 바이트짜리 char 배열이라 생각하게
                                    해서 이를 전달하였다. 두 번째 인자로 반드시 몇 바이트를 읽을 지 
                                    전달해야 한다. 위처럼 그냥 char 배열에 크기를 지정해서 읽어들이면 된다. */
        std::cout << std::hex << x << std::endl;        /* cout 에서 사용한 hex 역시 바로 전의 코드에서 
                                                        cin 에서 사용한 hex 와 비슷한 부류로, 16 진수로 
                                                        정수 데이터를 표시해준다. */
    } else {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
    }

    return 0;
}


/* 파일 전체 읽기 */
#include <fstream>      /* 파일 입출력에 필요한 헤더 파일 포함 */
#include <iostream>     /* 표준 입출력 스트림에 필요한 헤더 파일을 포함한다. */
#include <string>       /* std::string 클래스를 사용하기 위한 헤더 파일을 포함한다. */

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;      /* 파일의 내용을 저장할 빈 문자열 s 를 선언한다. */

    if (in.is_open()) {
        // 위치 지정자를 파일 끝으로 옮긴다.
        in.seekg(0, std::ios::end); // seekg : 파일 읽기 위치를 설정하는 함수

        // 그리고 그 위치를 읽는다. (파일의 크기)
        int size = in.tellg();      // tellg : 파일의 현재 위치를 반환하는 함수. (파일 끝에 위치하므로, 이 값은 파일의 크기를 의미한다.)

        // 그 크기의 문자열을 할당한다.
        s.resize(size);             // s 문자열의 크기를 size 로 조정한다. --> 이렇게 하면 파일의 크기만큼의 공간을 가진 문자열(s) 이 된다. 

        // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
        in.seekg(0, std::ios::beg); // 파일의 내용을 읽기 위한 준비 완료!!

        // 파일 전체 내용을 읽어서 문자열에 저장한다. 
        in.read(&s[0], size);       // 파일에서 size 바이트 만큼 읽어서 문자열 s 에 저장한다. &s[0] 는 문자열의 내부 버퍼를 가리킨다. 이 함수는 파일의 내용을 읽어 문자열에 직접 저장한다. 
        std::cout << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
    }

    return 0;
}


/* 파일 전체를 한 줄씩 읽기 */
// getline 으로 읽어들이기
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    char buf[100];      /* 해당 코드의 경우, buf 에 최대 99 글자까지 입력받는다. 
                        물론 개행 문자 말고도 우리가 지정한 문자가 나올 때까지 읽는
                        것으로 바꿀 수도 있다. 이 경우, 원하는 문자를 인자로 전달
                        해주면 해당 문자가 나올 때까지 입력 받는다. */

    if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
        return 0;
    }

    while (in) {
        /* ifstream 에는 자기 자신을 bool 로 캐스팅할 수 있는 캐스팅 연산자(operator bool()) 가 오버로딩 되어있다. 
        따라서 위와 같이 while 문 조건에 in 을 전달한다면 bool 로 캐스팅하는 연산자 함수가 호출된다. 
        이때 in 이 true 이기 위해서는 다음 입력 작업이 성공적이어야만 하고, 현재 스트림에 오류 플래그가 켜져 있지 않아야만 한다. */

        in.getline(buf, 100);           /* 위 ifstream 객체의 멤버 함수로 존재하는 getline 함수는 
                                        파일에서 개행문자(\n) 이 나올 때까지 최대 지정한 크기 - 1 
                                        만큼 읽게 된다. 하나 적게 읽는 이유는, buf 의 맨 마지막 문자로
                                        널 종료 문자를 넣어주어야 하기 때문이다. */
        std::cout << buf << std::endl;
    }

    return 0;
    /* getline 함수는 개행 문자(혹은 지정한 문자) 가 나오기 전에 지정한 버퍼의 크기가 다 차게 된다면 
    failbit 를 키게 되므로 버퍼의 크기를 너무 작게 만든다면 정상적으로 데이터를 받을 수 없다. 따라서
    getline 을 사용하기 전에 이와 같은 조건을 꼭 확인해야 한다. 
    이와 같은 한계점을 극복하기 위해서는 std::string 에서 getline 함수를 제공하고 있다. */
}


// std::string 에 정의된 getline 사용
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");

    if (!in.is_open()) {
        std::cout << "파일을 읽을 수 없습니다!!" << std::endl;
        return 0;
    }

    std::string s;
    while (in) {
        getline(in, s);             /* 이 getline 함수는 ifstream 에 정의되어 있는 것이 아니라(위의 코드와는 반대 상황!!) std::string 
                                    에 정의되어 있는 함수로, 첫 번째 인자로 istream 객체를 받고, 두 번째 인자로 입력 받은 문자열을 저장할 
                                    string 객체를 받게 된다. 기존에 ifstream 의 getline 을 활용할 때보다 훨씬 편리한 것이, 굳이 버퍼의 
                                    크기를 지정하지 않아도 알아서 개행문자 혹은 파일에 끝이 나올 때까지 입력받게 된다. */
        std::cout << s << std::endl;
    }

    return 0;
}


/* 파일에 쓰기 */
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 파일 쓰기 준비
    std::ofstream out("test.txt");

    std::string s;
    if (out.is_open()) {
        out << "이걸 쓰자~~!!";
    }

    return 0;
    /* 해당 소스코드를 컴파일한 후, test.txt 를 열어보면 내용이 "이걸 쓰자~~!!" 라는 내용으로 바뀌어 있는 것을 확인할 수 있다.
    만일 test.txt 가 존재하지 않을 경우, test.txt 를 생성한 뒤에, 생성이 성공하였다면 출력하게 된다. 만일, 해당 파일이 이미 존재
    한다면, 특별한 설정을 하지 않는다면 해당 파일 내용이 다 지워지고 새로운 내용으로 덮어씌워지게 된다. */
}


#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 쓰기 준비
    std::ofstream out("test.txt", std::ios::app);
    /* out 객체를 생성할 때 옵션으로 app 을 주게 되면, 파일에 스트림을 연결할 때
    기존 파일의 내용을 지우고 새로 쓰는 것이 아니라 그 뒤에 새로운 내용을 붙여 쓰게 된다. */

    std::string s;
    if (out.is_open()) {
        out << "덧붙이기";
    }

    return 0;
    /* 
    1) ios::ate : 자동으로 파일 끝에서부터 읽기와 쓰기를 실시한다. (즉, 파일을 열 때 위치 지정자가 파일 끝을 가리키고 있게 된다. )
    2) ios::trunc : 파일 스트림을 열면 기존에 있던 내용들이 모두 지워진다. 기본적으로 ofstream 객체를 생성할 때 이와 같은 설정으로 만들어진다. 
    3) ios::in, std::ios::out : 파일에 입력을 할지 출력을 할지 지정하며, ifstream 과 ofstream 객체를 생성할 때 각각은 이미 설정되어 있다. */
}


/* 생각해보기-문제 */
/* 문제 1: 
일단 엑셀의 셀들의 정보( 일단 단순한 std::string 이라고 생각하자.) 에 대한 Cell 클래스가 
있고 이 Cell 객체들을 모아두는 Table 클래스가 있다. Table 클래스에는 2 차원 배열로 Cell 객체들에
대한 정보(참고로 Cell 객체가 생성될 때마다 동적으로 Cell 객체를 생성한다.) 가 보관되어 있다. 
또한 Table 클래스에 전체 데이터를 출력하는 print_table 함수가 가상으로 정의되어 있다. 

우리는 Table 클래스를 상속받는 TextTable, CSVTable, HTMLTable 클래스를 만들어서 print_table 함수를 
오버라이드할 함수들을 제작할 것이다. 예를 들어 TextTable 클래스의 print_table 함수는 텍스트 형식으로, 
CSVTable 은 CSV 파일 형식으로 등등 만들어야겠지요?? 저자가 아래에 대충 프로그램의 골격을 잡아 놓았으니 
우리들은 이를 채우기만 하면 된다. */
class Table;
class Cell {
    Table* table; // 어느 테이블에 속해 있는지 
    std::string data;
    int x, y; // 테이블에서의 위치
    public:
        Cell(const std::string& data) : data(data){};
};

class Table {
    Cell*** data_base;  // 왜 3 중 포인터인지 잘 생각해보기!!
    public:
    Table();
    virtual std::string print_table() = 0;
    void reg_cell(Cell* c, int row, int col);  // Cell 을 등록한다.
    std::string get_cell_std::string(int row,
                                    int col);  // 해당 위치의 Cell 데이터를 얻는다.
    ~Table();
};

ostream operator<<(ostream& o, Table& t) {
    o << t.print_table();
    return o;
}
class TextTable : public Table {};
class CSVTable : public Table {};
class HTMLTable : public Table {};

/* 문제 2: (교재 373P...너무 내용이 기니깐 그냥 교재 보고 풀어라...)
(난이도: 최상-위의 문제와 이어진다.)
하지만 실제 엑셀의 경우 셀이 문자열 데이터만 들어가는 것이 아니라, 숫자나 날짜 심지어 수식까지도 
들어갈 수 있다. 따라서 우리는 Cell 을 상속받는 4 개의 StringCell, NumberCell, DataCell, ExprCell 클래스들을 만들어야한다. 
또한 Cell 클래스에 to_numeric (데이터를 숫자로 바꾼다.) 과 std::stringify(데이터를 문자열로 바꾼다.) 함수들을 
가상으로 정의하고, 4 개의 클래스들이 이를 상속받아서 구현할 수 있게 해야 한다. (참고로 문자열을 숫자로 변환하면 그냥 0 이 되게 
하면 된다.)
또한 ExprCell 의 경우 간단한 수식에 대한 정보를 가지는 객체로, Cell 들 간의 연산을 사용할 수 있다. 예를 
들어서 A1+B2+C6-6 와 같은 데이터가 들어있는 ExprCell 에 to_numeric 함수를 호출하면 A1, B2, C6 의 값을 더하고  */



/* 엑셀 만들기 프로젝트 */
/* 벡터 클래스 */
class Vector {
    string* data;       /* Vector 클래스는 데이터를 보관하기 위한 data(문자열 배열로 만든 것이다.), 
                        현재 할당되어있는 크기를 알려주는 capacity, 그리고 현재 실제로 사용하는 양인 length
                        와 같은 변수로 구성되어 있다. */
    int capacity;
    int length;

    public:
    // 생성자
    Vector(int n = 1);      /* 한 가지 특이한 점은 생성자에서 인자가 int n = 1 과 같이 지정되어 있다는 것이다. 
                            이는 만일 사용자가 인자를 지정하지 않으면, 알아서 n = 1 이 되도록 지정한다는 것이다. 
                            다시 말해,
                            Vector a() Vector a(1)
                            은 동일한 작업이다. 물론 사용자가 인자를 지정하면 해당 인자가 들어갈 것이다. 이렇게 해당 인자의
                            기본 값을 지정해 놓은 것을 '디폴트 인자(Default argument)' 라고 한다. 이렇게 하면 사용자가 
                            지정하지 않아도 디폴트 값이 들어가기 때문에 문제 없이 사용할 수 있다. */

    // 맨 뒤에 새로운 생성자를 추가한다. 
    void push_back(string s);

    // 임의의 위치의 원소에 접근한다. 
    string operator[](int i);

    // x 번째 위치한 원소를 제거한다. 
    void remove(int x);

    // 현재 벡터의 크기를 구한다.
    int size();
    ~Vector();
};


/* 스택 클래스 */
/* 스택의 경우, 위에서 말한 것처럼 링크드 리스트를 사용하기 때문에 
데이터를 보관하기 위해서 배열을 사용하는 것이 아니라 하나의 노드를
만들어서 노드들을 체인처럼 엮을 것이다. 이를 위해 아래와 같이 Stack
클래스 안에 Node 라는 구조체를 정의하였다. */
struct Node {
    Node* prev;
    string s;

    Node(Node* prev, string s) : prev(prev), s(s) {}
}
/* Node 객체에서는 자기보다 하위 Node 를 가리키는 포인터(prev) 와,
자신이 보관하는 데이터에 관한 값(s) 을 보관하는 두 개의 변수로 구성되어 있다. 
아래는 전체 Stack 클래스의 모습이다. */
class Stack {
    struct Node {
        Node* prev;
        string s;

        Node(Node* prev, string s) : prev(prev), s(s) {}
    };

    Node* current;
    Node start;

    public:
    Stack();

    // 최상단에 새로운 원소를 추가한다.
    void push(string s);

    // 최상단의 원소를 제거하고 반환한다. 
    string pop();

    // 최상단의 원소를 반환한다. (제거 안함)
    string peek();

    // 스텍이 비어있는지의 유무를 반환한다.
    bool is_empty();

    ~Stack();
};
/* Node 들의 리스트를 정확히 관리하기 위해서, current 와 start 를 만들어서 current 는 현재 최상위 노드를 가리키게 하고
start 는 맨 밑바닥을 이루는 노드, 즉 최하위 노드를 가리키게 하였다. start 노드를 둔 이유는, 마지막 노드에 도달하였을 때 
그 여부를 알아야 하기 때문이다. */


/* 위의 벡터와 스텍 클래스를 이용해 만든 헤더 파일 utils.h 의 전체 내용 */
#ifndef UTILS_H
#define UTILS_H

#include <string>
using std::string

namespace MyExcel {
    class Vector {
        string* data;
        int capacity;
        int length;

        public: 
        // 생성자
        Vector(int n = 1);

        // 맨 뒤에 새로운 원소를 추가한다.
        void push_back(string s);

        // 임의의 위치의 원소에 접근한다. 
        string operator[](int i);

        // x 번째 위치한 원소를 제거한다. 
        void remove(int x);

        // 현재 벡터의 크기를 구한다.
        int size();

        ~Vector();
    };

class Stack {
    struct Node {
        Node* prev;
        string s;

        Node(Node* prex string s) : prev(prev), s(s) {}
    };

    Node* current;
    Node start;

    public:
    Stack();

    // 최상단에 새로운 원소를 추가한다.
    void push(string s);

    // 최상단의 원소를 제거하고 반환한다. 
    string pop();

    // 최상단의 원소를 반환한다.(제거 안함)
    string peek();

    // 스텍이 비어있는지의 유무를 반환한다.
    bool is_empty();

    ~Stack();
};
class NumStack {
    struct Node {
        Node* prev;
        double s;

        Node(Node* prev, double s) : prev(prev), s(s) {}
    };

    Node* current;
    Node start;

    public:
    NumStack();
    void push(double s);
    double pop();
    double peek();
    bool is_empty();

    ~NumStack();
};
}
#endif
/* 마찬가지로 아래는 해당 헤더파일 내용을 구현한 utilty.cpp 이다. */
#include "utils.h"

namespace MyExcel {
    Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}
    void Vector::push_back(string s) {
        if (capacity <= length) {
            string* temp = new string[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }
    string Vector::operator[](int i) { return data[i]; }
    void Vector::remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }
    int Vector::size() { return length; }
    Vector::~Vector() {
        if (data) {
            delete[] data;
        }
    }

    Stack::Stack() : start(NULL, "") { current = &start; }
    void Stack::push(string s) {
        Node* n = new Node(current, s);
        current - n;
    }
    string Stack::pop() {
        if (current == &start) return "";

        string s = current->s;
        Node* prev = current;
        current = current->prev;

        // Delete popped node
        delete prev;
        return s;
    }
    string Stack::peek() { return current->s; }
    bool Stack::is_empty() {
        if (current == &start) return true;
        return false;
    }
    Stack::~Stack() {
        while (current != &start) {
            Node* prev = current;
            current = current->prev;
            delete prev;
        }
    }
    NumStack::Numstack() : start(NULL, 0) { current = &start; }
    void NumStack::push(double s) {
        Node* n = new Node(current, s);
        current = n;
    }
    double NumStack::pop() {
        if (current == &start) retrun 0;
        double s = current->s;
        Node* prev = current;
        current = current->prev;

        // Delete popped node
        delete prev;
        return s;
    }
    double NumStack::peek() { return current->s; }
    bool NumStack::is_empty() {
        if (current == &start) return true;
        return false;
    }
    NumStack::~NumStack() {
        while (current != &start) {
            Node* prev = current;
            current = current->prev;
            delete prev;
        }
    }
}


/* 본격적인 Cell 과 Table 클래스 */
class Cell {
    protected:      /* Cell 클래스는 큰 테이블에서 한 칸을 의미하는 객체로, 
                        해당 내용을 보관하는 문자열 data 와 어느 테이블에 위치해
                        있는지에 관련한 정보를 가지고 있는 table 과 그 위치 x, y
                        로 구성되어 있다. */
    int x, y;
    Table* table;

    string data;
    
    public:
    virtual string stringity();     /* 또한, Cell 클래스는 
                                    가상함수로 해당 셀 값을 문자열로 변환하는 stringify 함수와, 
                                    정수 데이터로 변환하는 to_numeric 함수도 선언되어 있다. 
                                    물론 문자열에 to_numeric 을 수행하게 되면 당연히 0 을 리턴
                                    하겠지만, 나중에 Cell 클래스를 NumberCell 과 같은 클래스
                                    들이 상속받기 위한 큰 그림이라고 보면 된다. */
    virtual int to_numeric();

    Cell(string data, int x, int y, Table* table);
    /* Cell 멤버 함수들의 정의는 아래와 같이 간단하게 나타낼 수 있다. */
    // Cell::Cell(string data, int x, int y, Table* table)
    //     : data(data), x(x), y(y), table(table) {}
    // string Cell::stringity() { return data; }
    // int Cell::to_numeric() { return 0; }
};


/* Table 클래스의 정의 */
class Table {
    protected:
    // 행 및 열의 최대 크기
    int max_row_size, max_col_size;

    // 데이터를 보관하는 테이블
    // Cell* 을 보관하는 2 차원 배열이라 생각하면 편하다. 
    Cell*** data_table;

    public:
    Table(int max_row_size, int max_col_size);

    ~Table();

    // 새로운 셀은 row 행 col 열에 등록한다. 
    void reg_cell(Cell* c, int row, int col);

    // 해당 셀의 정수값을 반환한다.
    // s : 셀 이름(Ex.A3, B6 과 같이)
    int to_numeric(const string& s);

    // 행 및 열 번호로 셀을 호출한다.
    int to_numveric(int row, int col);

    // 해당 셀의 문자열을 반환한다.
    string stringify(const string& s);
    string stringify(int row, int col);

    virtual string print_table() = 0;
};
/* 일단 Table 클래스는 Cell 객체들을 2 차원 배열로 보관하게 된다. 
이때, 객체 자체를 보관하는 것이 아니라, 객체는 필요할 때마다 동적
으로 생성하고, 그 객체에 대한 포인터를 2 차원 배열로 보관하고 있게 된다. */
Table::Table(int max_row_size, int max_col_size)
    : max_row_size(max_row_size), max_col_size(max_col_size) {
        data_table = new Cell**[max_row_size];
        for (int i = 0; i < max_row_size; i++)
 {
    data_table[i] = new Cell*[max_col_size];
    for (int j = 0; j < max_col_size; j++) {
        data_table[i][j] = NULL;
        }
    }    
 }

 /* 동적 할당으로 Cell* 배열을 생성한 후에, Cell 객체가 필요할 때마다 
 생성해서 배열의 원소들이 이를 가리킬 수 있게 하였다. */

 Table::~Table() {
    for (int i = 0; i < max_row_size; i++) {
        for (int j = 0; j < max_col_size; j++) {
            if (data_table[i][j]) delete data_table[i][j];
        } 
    }
    for (int i = 0; i < max_row_size; i++) {
        delete[] data_table[i];
    }
    delete[] data_table;
 }
/* Table 소멸자도 이와 비슷하다. 일단, 동적으로 생성된 Cell 객체를 모두 지워야 하고
그 다음에 Cell 배열(1 차원) 을 지워야 하고 마지막으로 2 차원 테이블 자체를 메모리에서
지워야한다. 
3 단계에 있어서 Cell 의 흔적으로 메모리에서 날려버릴 수 있다. */

void Table::reg_cell(Cell* c, int row, int col) {
    if (!(row < max_row_size && col < max_col_size)) return;

    if (data_table[row][col]) {
        delete data_table[row][col];
    }
    data_table[row][col] = c;
}
/* 위의 코드는 Table 의 셀을 등록하는 함수이다. 등록하고자 하는 위치를 인자로 받는데,
만일 해당 위치에 이미 다른 셀 객체가 등록되어 있다면 해당 객체를 delete 한 후에 등록
시켜주면 된다. */
int Table::to_numeric(const string& s) {
    // Cell
    int row = s[0] - 'A';
    int col = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size) {
        if (data_table[row][col]) {
            return data_table[row][col]->to_numeric();
        }
    }
    return 0;
}
int Table::to_numeric(int row, int col) {
    if (row < max_row_size && col < max_col_size && data_tavle[row][col]) {
        return data_table[row][col]->to_numeric();
    }
    return 0;
}
string Table::stringify(const string& s) {
    // Cell
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size) {
        if (data_table[row][col]) {
            return data_table[row][col]->stringify();
        }
    }
    return 0;
}
string Table::stringify(int row, int col) {
    if (row < max_row_size && col < max_col_size && data_table[row][col]) {
        return data_table[row][col]->stringify();
    }
    return "";
}
std::ostream& operator<<(std::ostream& o, Table& table) {
    o << table.print_table();
    return o;
}


class TxtTable : public Table {
    string repeat_cahr(int n, char c);

    // 숫자로 된 열 번호를 A, B, .....Z, AA, AB, ... 이런 순으로 매겨준다. 
    string col_num_to_str(int n);

    public:
    TxtTable(int row, int col);

    // 텍스트로 표를 깨끗하게 출력해준다. 
    string print_table();
};
/* 위는 Table 클래스를 상속받는 TxtTable 클래스이다. 
이 클래스는 Table 의 내용을 텍스트의 형태로 예쁘게 정리
해서 출력해주는 역할을 하고 있다. */


TxtTable::TxtTable(int row, int col) : Table(row, col) {}
// 텍스트로 표를 깨끗하게 출력해준다. 
string TxtTable::print_table() {
    string total_table;

    int* col_max_isde = new int[max_col_size];
    for (int i = 0; i < max_col_size; i++) {
        unsigned int max_wide = 2;
        for (int j = 0; j < max_row_size; j++) {
            if (data_table[j][i] &&
                data_table[j][i]->stringify().length() > max_wide) {
                    max_wide = data_table[j][i]->stringify().length();
                }
        }
        col_max_wide[i] = max_wide;
    }
    // 맨 상단에 열 정보 표시
    total_table += "    ";
    int total_wide = 4;
    for (int i = 0; i < max_col_size; i++) {
        if (col_max_wide[i]) {
            int max_len = max(2, col_max_wide[i]);
            total_table += " | " + col_num_to_str(i);
            total_table += repeat_cahr(max_len - col_num_to_str(i).length(), ' ');

            total_wide += (max_len + 3);
        }
    }

    total_table += "\n";
    // 일단 기본적으로 최대 9999 번째 행까지 지원한다고 생각한다. 
    for (int i = 0; i < max_row_size; i++) {
        total_table += repeat_cahr(total_wide, '-');
        total_table += "\n" + to_string(i + 1);
        total_table += repeat_cahr(4 - to_stirng(i + 1).length(), ' ');

        for (int j = 0; j < max_col_size; j++
 {
    if (col_max_wide[j]) {
        int max_len = max(2, col_max_wide[j]);

        string s = "";
        if (data_tavle[i][j]) {
            s = data_table[i][j]->stringify();
        }
        total_table += " | " + s;
        total_tavle += repeat_cahr(max_len - s.length(), ' ');
    }
 }
 total_table += "\n";    
 }
 return tatal_table;

}
//
string TxtTable::col_num_to_str(int n) {
    string s = "";
    if (n < 26) {
        s.push_back('A' + n);
    } else {
        char first = 'A' + n / 26 - 1;
        char second = 'A' + n % 26;

        s.push_back(first);
        s.push_back(second);
    }

    return s;
    /* 해당 코드는 그 구현이다. repeat_char 과 col_num_to_str 함수는 단순히 
    print_table 에서 사용할 부가적인 함수들이다. print_table 함수는 각 열의 
    최대 문자열 길이를 계산한 뒤에, 이를 바탕으로 각 열의 폭을 결정해서 표를
    출력해준다. 
    
    참고로 이 구현 방식에서 한 가지 중요한 것이 빠졌는데, 셀의 문자열 데이터에서
    개행 문자가 있는 경우(즉 특정 셀이 여러 줄이 될 때) 를 고려하지 않았다. 즉, 
    모든 셀은 최대 1 줄로만 그려지게 된다. 따라서 실제로는 각 행의 최대 높이 역시 
    열과 마찬가지로 계산해서 그려야 한다.*/
}


/* Cell 클래스 확장 */
/* 앞서 말했듯이, Cell 클래스에는 string 데이터만 저장할 수 있기 때문에
이를 상속받는 클래스들을 만들어서 셀에 다양한 데이터들을 보관할 수 있게 할 
것이다. */
class Cell {
    protected:
    int x, y;
    Table* table;

    public:
    virtual string stringify() = 0;
    virtual int to_numeric() = 0;

    Cell(int x, int y, Table* table);
};
/* 일단 기존의 Cell 클래스에서 문자열 데이터를 보관했던 것과는 달리
아예 그 항목을 빼버리고, 이를 상속받는 클래스에서 데이터를 보관하도록 하였다. 
또한, stringify 함수와 to_numeric 을 순수 가상 함수로 정의해서 이를
상속받는 클래스에서 이 함수들을 반드시 구현하도록 하였다. */


/* 엑셀 프로그램 */
class Excel {
    Table* current_table;

    public:
    Excel(int max_row, int max_col, int choice);

    int parse_user_input(string s);
    void command_line();
};

Excel::Excel(int max_row, int max_col, int choice = 0) {
    switch (choice) {
        case 0:
        current_table = new TxtTable(max_row, max_col);
        break;
        case 1:
        current_table = new CSVTable(max_row, max_col);
        break;
        default:
        current_table = new HtmlTable(max_row, max_col);
    }
}

int Excel::parse_user_input(string s) {
    int next = 0;
    string command = "";
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            command = s.substr(0, i);
            next = i + 1;
            break;
        } else if (i == s.length() - 1) {
            command = s.substr(0, i + 1);
            next = i + 1;
            break;
        }
    }

    string to = "";
    for (int i = next; i < s.length(); i++) {
        if (s[i] == ' '|| i + s.length() - 1) {
            to = s.suvstr(next, i - next);
            next = i + 1;
            break;
        } else if (i == s.length() - 1) {
            to = s.suvstr(0, i + 1);
            next = i + 1;
            break;
        }
    }

    // Cell
    int col = to[0] - 'A';
    int row = atoi(to.c_str() + 1) - 1;

    string reat = s.substr(next);

    if (command == "sets") {
        current_table->reg_cell(new StringCell(rest, row, col, current_table), row,
                                col);
    } else if (command == "setn") {
        current_table->reg_cell(
            new NumberCell(atoi(rest.c_str()), row, col, current_table), row, col);        
    } else if (command == "setd")   {
        current_table->reg_cell(new DateCell(rest, row, col, current_table), row,
                                col);
    } else if (command == "sete") {
        current_table->reg_cell(new ExprCell(rest, row, col, current_table), row,
                                col);
    } else if (command == "out") {
        ofstream out(to);
        out << *current_table;
        std::cout << to << " 에 내용이 저장되었습니다. " << std::endl;
    } else if (command == "exit") {
        return 0;
    }
    return 1;
}

void Excel::command_line() {
    string s;
    std::getline(cin, s);

    while (parse_user_input(s)) {
        std::cout << *current_table << std::endl; << ">> ";
        getline(cin, s);
    }
}

int main() {
    std::cout 
    << "테이블 (타입) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요. "
    << std::endl;
    std::cout << "* 참고 * " << std::endl;
    std::cout << "1 : 첵스트 테이블, 2 : CSV 테이블, 3 : HTML 테이블"
                << std::endl; 
    
    int type, max_row, max_col;
    std::cin >> type >> max_row >> max_col;
    MyExcel::Excel m(max_row, max_col, type - 1);
    m.command_line();
}


/* 생각해보기-문제 */
/* 문제 1 : 
ExprCell 의 식에서 셀의 이름은 A3 과 같이 단 두 글자만 가능하다는 제약 조건이 있었다. 
이를 임의의 크기의 이름도 가능하게 확장해보아라. (난이도: 하) */
/* 문제 2 :
마찬가지로 가능한 숫자도 임의의 길이가 상관없게 확장해보아라. (난이도: 하) */
/* 문제 3 : 
사실 위와 간이 수식을 계산하는 경우, 한 가지 문제가 있다. 바로 셀들이 서로를 참조할 수
있다는 것이다. 예를 들어서 A1 = B1 이고 B1 = A1 으로 설정하였다면 B1 의 값을 알기 위해
A1 의 값을 알아야 하고, 그럼 A1 의 값을 알기 위해 B1 의 값을 알아야 하고... 와 같은 순환
참조 문제가 발생한다. 
따라서 사용자가 타의든 자의든 순환 참조가 있는 식을 입력하였을 때 이를 감지하고 입력을 방지하는 
루틴을 제공해야 한다. (실제 Excel 에서도 순환 참조되는 식을 입력하면 오류가 발생한다.) */
/* 문제 4 : 
실제 Excel 의 경우 수식에서 여러가지 함수들을 지원한다. 여기서도 수식에서 간단한 함수들을 지원하도록 해보아라. (난이도: 상) */


/* C++ 템플릿 */
/* 벡터(vector) 는 쉽게 생각하면 가변 길이 배열로 사용자가 배열처럼 사용하는데 크기를 마음대로 줄이고 늘릴 수 있는 편리한 자료형이다.
스택(stack) ㅡ이 경우, 나중에 들어간 것이 먼저 나온다.(LIFO-last in first out) 형태의 자료형으로 pop 과 push 를 통해서 여러가지 작
업들을 처리할 수 있다. 
하지만 한 가지 문제는 우리가 담으려고 하는 데이터 타입이 바뀔 때마다 다른 벡터를 만들어주어야 한다는 점이다. 예를 들어서 아래의 Vector 
클래스를 살펴보자. */
class Vector {
    std::string* data;
    int capacity;
    int length;

    public:
    // 생성자
    Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다. 
    void push_back(std::string s) {
        if (capacity <= length) {
            std::string* temp = new std::string[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }

            delete[] data;
            data = temp;
            capacity *= 2;
        }
        data[length] = s;
        length++;
    }

    // 임의의 위치에 있는 원소에 접근한다. 
    std::string operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다. 
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다. 
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};
/* 만약에 우리가 int 를 담는 vector 가 필요할 경우 T 가 int 로
바뀌면 되고, string 을 담는 것이 필요하다면 T 가 string 으로 바뀌면 
된다. 쉽게 말해 컴파일러가 T 부분에 우리가 원하는 타입으로 채워서 코
드를 생성해주면 엄청 편할 것이다. 마치 어떠한 틀에 타입을 집어넣으면 
원하는 코드가 딱딱 튀어나온 틀 같이 말이다.  */

/* 놀랍게도, 우리가 원하는 작업을 C++ 에서는 template 이라는 이름으로 지원하고 있다. 
영어 단어 template 의 뜻을 찾아보자면, '형판' 이라고 나온다. 쉽게 말해 어떠한 물건을
찍어내는 틀이라고 생각하면 된다. C++ 에서도 정확히 같은 의미로 사용되고 있다. 사용자
(프로그래머) 가 원하는 타입을 넣어주면 딱딱 알아서 코드를 찍어내는 틀이라고 생각하면 된다. */


/* C++ 템플릿(template) */
// 템플릿 첫 활용
#include <iostream>
#include <string>

template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

    public:
    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];                                                                                              
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다. 
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다. 
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다. 
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

int main() {
    // int 를 보관하는 벡터를 만든다. 
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "--------- std::string vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;
}


/* 템플릿 특수화(template specialization) */
/* 일부 경우에 대해서 따로 처리하는 것을 '템플릿 특수화' 라고 한다. 템플릿 특수화는
다음과 같이 수행할 수 있다. 예를 들어서
template <typename A, typename B, typename C> 
class test {};
위와 같은 클래스 템플릿이 정의되어 있을 때, "아 나는 A 가 int 고 C 가 double 일 때 따로
처리하고 싶어!!" 면,
template <typename B>
class test<int, B, double> {};
와 같이 특수화하고 싶은 부분에 원하는 타입을 전달하고 위에는 일반적인 템플릿을 사용하면 될
것이다. 만약에 B 조차도 특수화하고 싶다면
template <>
class test<int, int, double> {};
와 같이 써주면 된다. 한 가지 중요한 점은, 전달하는 템플릿 인자가 없더라도 특수화하고 싶다면 
template <>
class Vector<bool> {
    ... // 원하는 코드
} 
와 같이 따로 처리해주면 될 것이다. */


#include <iostream>
#include <string>

template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

    public:
    // 어떤 타입을 보관하는지

    typedef T value_type;

    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다. 
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다. 
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }
    // 현재 벡터의 크기를 구한다. 
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <>
class Vector<bool> {
    /* int 배열로 unsigned int 를 사용하기로 하였다. 굳이 unsigned int 를 사용한 이유는
    그냥 int 를 사용했을 때 shift 연산 시에 귀찮은 문제가 발생할 수 있기 때문이다. 
    capacity 는 생성된 data 배열의 크기를 의미하고, length 는 실제 bool 데이터의 길이를
    의미한다. 즉 1 capacity 에 32 개의 bool 이 들어갈 수 있게 되는 것이다. (int 가 32
    비트라 생각하면)*/
    unsigned int* data;
    int capacity;
    int length;

    public:
    typedef bool value_type;

    // 생성자
    Vector(int n = 1)
        : data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) {
            for (int i = 0; i < capacity; i++) {
                data[i] = 0;
            }
        }

        // 맨 뒤에 새로운 원소를 추가한다. 
        void push_back(bool s) {
            /* push_back 함수를 살펴보면 만일 현재 길이가 capacity 를 초과하게 되면 
            현재 크기의 2 배로 새로 배열을 만들어서 복사하게 된다. 그리고 기본적으로 
            배열 전체를 0 으로 초기화하기 때문에 기본적으로 false 로 설정되어 있다고 
            보면 된다. 
            따라서 true 를 추가하였을 때만 해당 비트를 true 로 바꿔주면 된다. 어떤 비트
            에 1 을 OR 연산하게 되면 그 비트는 무조건 1 이 된다. 그리고 0 을 연산하게 되
            면 그 비트의 값은 그대로 보존이 된다. 따라서 OR 연산은 특정 비트에만 선택적
            으로 1 로 바꾸는데 매우 좋은 연산이다.(주변 나머지 비트들의 값은 보존하면서 
            특정 비트만 1 로 바꿔준다.) */
            if (capacity * 32 <= length) {
                unsigned int* temp = new unsigned int[capacity * 2];
                for (int i = 0; i < capacity; i++) {
                    temp[i] = data[i];
                }
                for (int i = capacity; i < 2 * capacity; i++) {
                    temp[i] = 0;
                }

                delete[] data;
                data = temp;
                capacity *= 2;
            }

            if (s) {
                data[length / 32] |= (1 << (length % 32));
            }

            length++; 
        }
        // 임의의 위치의 원소에 접근한다. 
        bool operator[](int i) { return (data[i / 32] & (1 << (i % 32))) != 0; }

        // x 번째 위치한 원소를 제거한다. 
        void remove(int x) {
            for (int i = x + 1; i < length; i++) {
                int prev = i - 1;
                int curr = i;

                // 만일 curr 위치에 있는 비트가 1 이라면
                // prev 위치에 있는 비트를 1 로 만든다. 
                if (data[curr / 32] & (1 << (curr % 32))) {
                    data[prev / 32] |= (1 << (prev % 32));
                }
                // 아니면 prev 위치에 있는 비트를 0 으로 지운다. 
                else {
                    unsigned int all_ones_except_prev = 0xFFFFFFFF;
                    all_ones_except_prev ^= (1 << (prev % 32));
                    data[prev / 32] &= all_ones_except_prev;
                }
            }
            length--;
        }

        // 현재 벡터의 크기를 구한다. 
        int size() { return length; }
        ~Vector() {
            if (data) {
                delete[] data;
            }
        }
    };
    
int main() {
    // int 를 보관하는 벡터를 만든다. 
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "------- int vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- std::string vector --------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);

    std::cout << "--------- bool vector -----------" << std::endl;
    for (int i = 0; i < bool_vec.size(); i++) {
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;
}


/* 함수 템플릿(Function Template) */
#include <iostream>
#include <string>

template <typename T>
T max(T& a, T& b) {
    return a > b ? a : b;
}

int main() {
    int a = 1, b = 2;
    std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

    std::string s = "hello", t = "world";
    std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
}

#include <iostream>

template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

    public:
    // 어떤 타입을 보관하는지
    typedef T value_type;

    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다. 
    void push_back(int s) {
        if (capacity <= length) {
            int* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }
    // i 번째 원소와 j 번째 원소 위치를 바꾼다. 
    void swap(int i, int j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <typename Cont>
void bubble_sort(Cont& cont) {
    for (int i = 0; i < cont.size(); i++) {
        for (int j = i + 1; j < cont.size(); j++) {
            if (cont[i] > cont[j]) {
                cont.swap(i, j);
            }
        }
    }
}

int main() {
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);

    std::cout << "정렬 이전 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }

    std::cout << std::endl << "정렬 이후 ---- " << std::endl;
    bubble_sort(int_vec);
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;
}


/* 함수 객체(Functon Object-Functor) */
#include <iostream>

template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

    public:
    // 어떤 타입을 보관하는지
    typedef T value_type;

    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다. 
    void push_back(int s) {
        if (capacity <= length) {
            int* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치에 원소에 접근한다. 
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다. 
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다. 
    int size() { return length; }

    // i 번째 원소와 j 번째 원소 위치를 바꾼다.
    void swap(int i, int j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <typename Cont>
void bubble_sort(Cont& cont) {
    for (int i = 0; i < cont.size(); i++) {
        for (int j = i + 1; j < cont.size(); j++) {
            if (cont[i] > cont[j]) {
                cont.swap(i, j);
            }
        }
    }
}
template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
    for (int i = 0; i < cont.size(); i++) {
        for (int j = i + 1; j < cont.size(); j++) {
            if (!comp(cont[i], cont[j])) {
                cont.swap(i, j);
            }
        }
    }
}

struct Comp1 {
    bool operator()(int a, int b) { return a > b; }
};

struct Comp2 {
    bool operator()(int a, int b) { return a < b; }
};
/* Comp1 과 Comp2 모두 아무 것도 하지 않고 단순히 oprator() 만 정의하고 있다. 
그리고 이 Comp1 고 Comp2 객체들은 bubbl_sort 함수 안에서 *
if (!comp(cont[i/, cont[j]))) { 
마치 함수인 양 사용된다. 이와 같이 '함수는 아니지만 함수인 척을 하는 객체를 함수
객체', 혹은 줄여서 Functor 라고 부른다. 이 Functor 덕분에, bubble_sort 함수 내에
서 두 객체간의 비교를 사용자가 원하는 대로 할 수 있게 된다. */

int main() {
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);

    std::cout << "정렬 이전 ------- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    } 

    Comp1 comp1;
    bubble_sort(int_vec, comp1);

    std::cout << std::endl << std::endl << "내림차순 정렬 이후 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;

    Comp2 comp2;
    bubble_sort(int_vec, comp2);

    std::cout << std::endl << "오름차순 정렬 이후 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;
}


/* 타입이 아닌 템플릿 인자 (non-type template argu-ments) */
/* 한 가지 재미있는 점은 템플릿 인자로 타입만 받을 수 있는 것은 아니다. */
#include <iostream>

template <typename T, int num>
T add_num(T t) {    /* template 의 인자로 T 를 받고, 추가적으로 마치 함수의 인자처럼 int num 을 또 받고 있다.
                        해당 템플릿 인자들은 add_num 함수를 호출할 때 <> 를 통해 전달하려는 인자들이 들어가게
                        된다. */
    return t + num;
}

int main() {
    int x = 3;
    std::cout << "x : " << add_num<int, 5>(x) << std::endl; 
    /* 위와 같이 T 에 int 를, num 에 5 를 전달하였으므로 생성되는 add_num 함수를 아래와 같다. 
    int add_num(int t) { return t + 5; }
    
    참고로 만약에 add_num 에 템플릿 인자 <> 를 지정하지 않았더라면 컴파일 오류가 발생하게 된다. 
    왜냐하면 상식적으로 컴파일러가 num 에 뭐가 들어가는지 알 길이 없기 때문이다. 따라서 위처럼 
    num 의 값을 결정할 수 없다고 불만을 제시하는 오류가 발생하게 된다. */
}

/* 한 가지 중요한 점은 템플릿 인자로 전달할 수 있는 타입들이 아래와 같이 제한적이다. 
1) 정수 타입들(bool, char, int, long 등등) --> 당연히 float 과 double 은 제외
2) 포인터 타입
3) enum 타입
4) std::nullptr_t (널 포인터) 
*/


#include <array>
#include <iostream>

int main() {
    // 마치 C 에서의 배열처럼 {} 을 통해 배열을 정의할 수 있다.
    // {} 문법은 뒤에서 자세히 다루므로 여기서는 그냥 이렇게
    // 쓰면 되겠구나 하고 이해하고 넘어가면 된다. 
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    // int arr[5] = {1, 2, 3, 4, 5}; 와 동일

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 


#include <array>
#include <iostream>

void print_array(const std::array<int, 5>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " "; 
        /* 배열의 각 원소를 출력합니다. 
        arr[i]는 i번째 원소를 의미하며, 
        각 원소를 공백으로 구분하여 출력합니다. */
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    print_array(arr);
    /* 해당 소스코드의 문제는 각 array 크기 별로 함수를 만들어줘야 한다는 점이다.
    이 문제를 해결하기 위해서는 템플릿을 쓸 수 있다. (아래의 코드 참고!!!) */
}


#include <array>
#include <iostream>

template <typename T>
void print_array(const T& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 7> arr2 = {1, 2, 3, 4, 5, 6, 7};
    std::array<int, 3> arr3 = {1, 2, 3};

    print_array(arr);
    print_array(arr2);
    print_array(arr3);
}


/* 디폴트 템플릿 인자 */
/* 함수에 디폴트 인자를 지정할 수 있는 것처럼 템플릿도 디폴트 인자를 지정할 수 있다. 
예를 들어서 이전에 만들었던 add_num 함수를 다시 살펴보자. (아래 코드 참고!!!) */
#include <iostream>

template <typename T, int num = 5>  /* 이 경우, num 에 디폴트 로 5 가 전달된다. */
T add_num(T t) {
    return t + num;
}

int main() {
    int x = 3;
    std::cout << "x : " << add_num(x) << std::endl;  /* 이 줄은 마치 add_num<jint, 5> 를 한 것과 동일한 의미를 가진다. 
    (참고로 int 는 컴파일러가 자동으로 추론해주었다. 그리고 타입 역시 디폴트로 지정이 가능하다.) */
    /* 템플릿 디폴트 인자는 함수 디폴트 인자랑 똑같이 인자 뒤에 = (디폴트 값) 을 넣어주면 된다. */
}



#include <iostream>
#include <string>

template <typename T>
struct Compare {
    bool operator()(const T& a, const T& b) const { return a < b; }
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
    Comp comp;
    if (comp(a, b)) {
        return a;
    }
    return b;
}

int main() {
    int a = 3, b = 5;
    std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;

    std::string s1 = "abc", s2 = "def";
    std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2)
                << std::endl; 
    /* 이들 모두 Comp 로 디폴트 타입인 Compare<T> 가 전달되어서 < 를 통해 비교를 수행하였다. */
}

/* 생각해보기-문제 */
/* 문제 1: 
template 을 사용해서 이전에 만들어 놓았던 Excel 프로젝트 코드를 깔끔하게 만들어보아라. 아마 10 배는 더 깔끔해질 것이다. (난이도: 하) */
/* 문제 2:
위 Vector 로 2 차원, 3 차원 배열 등을 똑같이 만들어낼 수 있을까요?? (나닝도: 하) */
/* 문제 3:
위에서 컴파일러가 마법처럼 템플릿 인자에 타입을 정해준다고 하지만 사실은 어떤 타입으로 추측할지 결정하는 일련의 규칙들이 있다. 
(링크 있음--풀 수 있는 문제가 아니라 그냥 링크를 타고 들어가서 설명을 읽으면 되는 듯??) */


/* 가변 길이 템플릿 */
/* 템플릿을 잘 사용한다면 써야 되는 코드의 양을 비약적으로 줄일 수 있다. 
이번 시간에는 템플릿을 사용해서 임의의 개수의 인자를 받는 방법에 대해서 이야기해보도록 할 것이다. */
/* 파이썬의 경우, print 함수를 이용하면 인자로 전달된 것들을 모두 출력할 수 있다. 
C++ 에서도 이와 같은 기능을 구현하는 게 가능하다. C++ 템플릿을 이용하면 임의의 개수의 인자를 받는
함수를 구현하는 게 가능하다. */
#include <iostream>

template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

template <typename T, typename... Types>  /* <~> 를 '템플릿 파리미터 팩' 이라고 부른다. 
                                            템플릿 파라미터 팩의 경우, 0 개 이상의 템플릿 인자들을 나타낸다. */
void print(T arg, Types...args) {          /* 함수에 인자로 ... 로 오는 것을 '함수 파라미터 팩' 이라고 부르며,
                                                0 개 이상의 함수 인자를 나타낸다. 템플릿 파라미터 팩과 함수 파라
                                                미터 팩의 차이점은 템플릿의 경우 타입 앞에 ... 이 오고, 함수의 경우
                                                타입 뒤에 ... 가 온다는 점이다. */
    std::cout << arg << ", ";
    print(args...);
}

int main() {
    print(1, 3.1, "abc");       /* print 함수 호출을 살펴보면, C++ 컴파일러는 이 두 개의 print 함수 정의를
                                살펴보면서 어느 것을 택해야 할지 정해야 한다. 
                                첫 번째 print 의 경우 인자로 단 1 개만 받기 때문에 후보에서 제외되고 두 번째 print 가 택해진다. */

                                /* print 의 첫 번째 인자는 1 이므로 T 는 int 로 추론되고, arg 에는 1 이 오게 된다. 
                                그리고 args 에는 나머지 3.1 과 "abc" 가 오게 된다. 따라서 위 args... 에는 print 에 전달되었던 
                                나머지 인자들이 쭈르륵 오게 된다. 따라서 위 코드는 마치
                                void print(int arg, double arg2, const char* arg3) {
                                    std::cout << arg << ", "
                                    print(arg2, arg3);
                                }
                                을 한 것과 마찬가지의 결과를 가져오게 된다. */
    print(1, 2, 3, 4, 5, 6, 7);
    /* 한 가지 흥미로운 점은 두 print 함수의 위치를 바꾸어서 쓴다면 컴파일 오류가 발생한다는 점이다. (아래의 코드 참고!!) */
}


/* 위치를 바꾼 경우- 오류 발생 */
#include <iostream>

template <typename T, typename... Types>
void print(T arg, Types... args) {
    std::cout << arg << ", ";
    print(args...);
}

template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

int main() {
    print(1, 3.1, "abc");
    print(1, 2, 3, 4, 5, 6, 7);
}


/* 가변 길이 템플릿을 활용한 또 다른 예시로는 임의의 문자열을 합쳐주는 함수를 들 수 있다. 
예를 들어서 std::string 에서 문자열을 합치기 위해서는 
concat = s1 + s2 + s3;
과 같이 해야 했는데, 잘 알다시피 위는 사실
concat = s1.operator+(s2).operator+(s3);
와 같다. 문제는 s2 를 더할 때 메모리 할당이 발생하고, s3 을 더할 때 메모리 할당이 또 한 번 
발생할 수 있다는 뜻이다. 합쳐진 문자열의 크기는 미리 알 수 있으니까 차라리 한 번에 필요한만큼 
메모리를 할당해버리는 게 훨씬 낫다. (메모리 할당/해제는 속도가 매우 느린 작업 중 하나이다.)
std::stirng concat;
concat.reserve(s1.size() + s2.size() + s3.size());  // 여기서 할당 1 번 수행 
concat.append(s1);
concat.append(s2);
concat.append(s3);
를 하게 된다면 깔끔하게 메모리 할당 1 번으로 끝낼 수 있다. 그렇다면 위와 같은 작업을 도와주는
함수를 만들게 된다면 아래와 같을 것이다.
std::string concat = StrCat(s1, "abc", s2, s3);
을 하게 된다면 깔끔하게 concat 에 s1 + "abc" + s2 + s3 한 문자열이 들어가게 된다. 물론 불필요한 메모리 할당은 없이 말이다.
하지만 문제는 StrCat 함수가 임의의 개수의 인자를 받아야 된다는 것이다. 여기서 바로 가변 길이 템플릿을 사용하면 된다. */


/* 첫 번째 시도 */
#include <iostream>
#include <string>

template <typename String>
std::string StrCat(const String& s) {
    return std::string(s);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    return std::string(s) + StrCat(strs...);
}

int main() {
    // std::string 과 const char* 을 혼합해서 사용 가능하다.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
                    " ", std::string("sentence"));
}


/* 전체 코드(완성) */
#include <cstring>
#include <iostream>
#include <string>

size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
size_t AppendToString(std::string* concat_str, const String& s, Strings... strs) {
    concat_str->append(s);
    AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    // 먼저 합쳐질 문자열의 총 길이를 구한다. 
    size_t total_size = GetStringSize(s, strs...);
    //reserve 를 통해 미리 공간을 할당해 놓는다.
    std::string concat_str;
    concat_str.reserve(total_size);

    concat_str = s;
    AppendToString(&concat_str, strs...);

    return concat_str;
}

int main() {
    // std::string 과 const char* 을 혼합해서 사용 가능하다.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
                        " ", std::string("sentence"));
}


/* sizeof... */
/* sizeof 연산자는 인자의 크기를 리턴하지만 파라미터 팩에 sizeof... 을 사용할 경우
전체 인자의 개수를 리턴하게 된다. 예를 들어서 원소들의 평균을 구하는 함수를 생각해보자. 
(아래의 코드 참고!!!) */
#include <iostream>

// 재귀 호출 종료를 위한 베이스 케이스
int sum_all() { return 0; }     /* sum_all 함수는 전달된 인자들의 합을 리턴하는 함수 */

template <typename... Ints>
int sum_all(int num, Ints... nums) {
    return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums) {      /* average 함수의 경우, 전달된 전체 인자 개수로 합을 나눠준다. 
여기서 size0f... 연산자가 활용된다. sizeof... 에 파라미터 팩(nums) 을 전달하면 nums 에 해당하는 실제 인자의 
개수를 리턴해준다. 우리의 경우 인자를 5 개 전달하였으므로 5 가 되었을 것이다. */
    return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}
int main() {
    // (1 + 4 + 2 + 3 + 10) / 5
    std::cout << average(1, 4, 2, 3, 10) << std::endl;
}


/* Fold Expression */
/* C++ 11 에서 도입된 가변 길이 템플릿은 매우 편리하지만 한 가지 단점이 있다. 
재귀 함수 형태로 구성해야 하기 때문에 반드시 재귀 호출 종료를 위한 함수를 따로 
만들어야 한다는 점이다. 
예를 들어서 위의 sum_all 함수를 보면
// 재귀 호출 종료를 위한 베이스 케이스
int sum_all() { return 0; }
위와 같이 재귀 함수 호출을 종료하기 위해 베이스 케이스를 꼭 만들어주어야 한다는 점이다. 
그러나 이는 코드의 복잡도를 쓸데없이 늘리게 된다. 
하지만 C++ 17 에 새로 도입된 Fold 형식을 사용한다면 이를 훨씬 간단하게 표현할 수 있다. */
#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums) {
    return (... + nums);    /* 해당 문장이 바로 C++ 17 에 추가된 Fold 형식이다. 이는 아래와 같이 컴파일러에서 해석된다. */
    /* 해석: return (((1 + 4) + 2) + 10); 
    이와 같은 형태를 '단항 좌측 Fold(Unary left fold) 라고 부른다. C++ 17 에서 지원하는 Fold 방식의 종류로는 총 4 가지가 있다. 
    (교재 455p 확인!!!) 
    주의할 점은, Fold 식을 쓸 때 꼭 소괄호() 로 감싸주어야한다는 점이다. 
    return (... + nums); 대신에 return ... + nums; 로 컴파일하게 되면 컴파일 오류가 발생한다. 
    소괄호() 역시 Fold 식에 포함되어 있는 것이기 때문이다. */
}

int main() {
    // 1 + 4 + 2 + 3 + 10
    std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;
}


/* 이항 Fold 식의 예 */
#include <iostream>

template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums) {
    return (start - ... - nums);    /* 이항 우측 Fold 식 */
}

int main() {
    // 100 - 1 - 4 - 2 - 3 - 10
    std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;
    /* 해당 소스코드를 실행시키면 80 이라는 결과를 얻을 수 있다. */
}


/* 연산자를 사용하면 각각의 인자들에 대해 원하는 식을 실행할 수 있다. */
#include <iostream>

class A {
    public:
    void do_something(int x) const {    /* 클래스 A 는 정수 인자를 받아서 메시지를 출력하는 메서드 do_something 을 포함한다. */
        std::cout << "Do something with " << x << std::endl; 
    }
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums) {
    /* 템플릿 함수 do_many_things 는 fold expression 메서드를 호출한다. */

    // 각각의 인자들에 대해 do_something 함수들을 호출한다. 
    (t.do_something(nums), ...);
}
int main() {    /* main 함수는 do_many_things 를 호출하여 
                A 객체의 do_something 메서드를 여러 번 호출
                하여 각 인자에 대해 메시지를 출력한다. */
    A a;
    do_many_things(a, 1, 3, 2, 4);
    /* 해당 코드는 템플릿과 C++ 17 의 fold expression 을 사용하여 인자 리스트를 처리하고, 특정
    작업을 각 인자에 대해 반복적으로 수행하는 방법을 보여준다. */

    /* 출력되는 값은 아래와 같다.
    Do something with 1
    Do something with 3
    Do something with 2
    Do something with 4
    출력값에 a 가 포함되어 있지 않은 이유는 a 가 객체이기 때문이다. a 는 t 의 자리에 해당하기 때문에 직접 출력되지 않는다. */
}


/* 템플릿 메타 프로그래밍 1 부 */
/* 나만의 std::array 구현 */
#include <iostream>
template <typename T, unsigned int N>
class Array {
    T data[N];

    public:
    // 배열을 받는 레퍼런스 arr
    Array(T (&arr)[N]) {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        }
    }

    T* get_array() { return data; }

    unsigned int size() { return N; }

    void print_all() {
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << " , ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int arr[3] = {1, 2, 3};

    // 배열 wrapper 클래스
    Array<int, 3> arr_w(arr);   /* 위와 같이 템플릿 인스턴스화를 하게 되면, 
                                템플릿에 T 자리에는 int 가, N 자리에는 3 이 들어간다. 
                                그렇다면 컴파일러는 
                                T data[N];
                                를 
                                int data[3];
                                으로 대체해서 코드를 생성하게 된다. */
    /* 마찬가지로 
    // 배열을 받는 레퍼런스 arr
    Array(T (&arr)[N]) {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        }
    }
    생성자 역시 
    // 배열을 받는 레퍼런스 arr
    Array(T (&arr)[3]) {
        for (int i = 0; i < 3; i++) {
            data[i] = arr[i];
        }
    }
    로 아예 코드가 생성되어 실행된다. 참고로 이처럼 배열을 감싸는 wrapper 클래스를 
    만들어서 마치 배열처럼 사용한다면 (물론 그러기 위해서는 [] 연산자도 오버로드 해야한다.)
    배열을 사용하믕로써 발생하는 문제들을 많이 해결할 수 있게 된다. 
    */

    arr_w.print_all();
}


/* 연산자 만들기 */
#include <iostream>
#include <typeinfo>

template <int N>
struct Int {
    static const int num = N;
};

template <typename T, typename U>
struct add {    /* add 클래스의 템플릿은 인자로 두 개의 타입을 받아서 그 타입의 num 멤버를 더해서
                새로운 타입인 result 를 만들어 내게 된다. */
    typedef Int<T::num + U::num> result;
};

int main() {
    typedef Int<1> one;
    typedef Int<2> two;

    typedef add<one, two>::result three;    /* 이 부분은 실제 덧셈을 수행하는 부분이다. add 클래스를 함수라고 생각한다면 
                                            그 계산 결과를 내부 result 타입으로 반환한다고 보면 된다. 아무튼 one 과 two
                                            를 더한 것을 나타내는 타입이 result 로 정의되고, 이를 three 라고 부른다. */

    std::cout << "Addition result: " << three::num << std::endl;    /* 실제로 그 결과를 보면, 3 이 잘 출력됨을 확인할 수 있다. */
    /* 해당 소스코드에서 한 가지 흥미로운 점은 이 3 이라는 출력값이 프로그램이 실행되면서 계산되는 것이 아니라는 점이다.
    컴파일 시에, 컴파일러가 three::num 을 3 으로 치환해버린다. 
    다시 말해, 이 덧셈이 수행되는 시기는 컴파일 타임이고, 런타임 시에는 단순히 그 결과를 보여주게 되는 것이다. */
}


/* 템플릿 메타 프로그래밍(Template Meta Programming - TMP) */
/* 여태까지 타입은 어떠한 객체에 무엇을 저장하느냐를 지정하는 데 사용해왔다.
그러나 타입 자체가 어떠한 값을 가지지는 않았다. 하지만 바로 위의 예제를 통
해서 알 수 있듯이, 템플릿을 사용하면 객체를 생성하지는 않더라도 타입에 어떠
한 값을 부여할 수 있고, 또 그 타입들을 가지고 연산을 할 수 있다.

또한 타입은 반드시 컴파일 타임에 확정되어야 하므로, 컴파일 타임에 모든 연산이 
끝나게 된다. 이렇게 타입을 가지고 컴파일 타임에 생성되는 코드로 프로그래밍을 
하는 것을 '메타 프로그래밍(meta programming)' 이라고 한다. C++ 의 경우 템플
릿을 가지고 이러한 작업을 하기 때문에 '템플릿 메타 프로그래밍', 줄여서 TMP 라
고 부른다. */

/* 컴파일 타임 팩토리얼 계산 */
#include <iostream>
template <int N>
struct Factorial {  /* 이 Factorial 함수는 팩토리얼을 템플릿을 사용해 구현한 구조이다. */
    static const int result = N * Factorial<N - 1>::result;
    /* 만약 Factorial 을 일반적인 함수로 구성하려 했다면 아마 아래와 같은 재귀 함수 형태를 사용했을 것이다.
    int factorial(int n) {
        if (n == 1) return 1;
        
        return n * factorial(n - 1);
    }
    따라서 우리는 위처럼 재귀 함수 호출이 끝나게 하기 위해서는 n 이 1 일때 따로 처리를 해주어야 한다.
    템플릿 역시 마찬가지로 n = 1 일 때 따로 처리할 수 있는데, 바로 아래처럼 '템플릿 특수화' 를 이용해주면 된다. */
};

template <> 
struct Factorial<1> {   /* n = 1 일 때 따로 처리하는 방법-->'템플릿 특수화' 사용!!! */
    static const int result = 1;    /* 컴파일러는 Factorial<1> 타입의 경우만 따로 result = 1 로 
                                    만들어주게 되어서 재귀적 구조가 끝날 수 있게 해준다. */
};

int main() {
    std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
    /* 팩토리얼(factorial) 은 단순히 1 부터 n 까지 곱한 것이라 생각하면 된다. 예를 들어 3 팩토리얼(3!) 은 
    1 * 2 * 3 이라 생각하면 된다. */

    /* 이 소스코드에서 볼 수 있듯이, 여기서 실질적으로 값을 가지는 객체는 아무것도 없다. 
    즉, '720' 이라는 값을 가지고 있는 변수는 메모리 상에서 없다는 뜻이다. 
    (물론 std::cout 에서 출력할 때 제외.) 출력 화면에 나타나는 720 이라는 값은 단순히 
    컴파일러가 만들어낸 Factorial<6> 이라는 타입을 나타내고 있을 뿐이다. */
}
/* 사실 일반적으로 factorial 을 계산하라는 함수를 만들라고 하면 십중팔구 그냥 단순히 for 문으로 구현한다.
하지만 템플릿으로는 for 문을 쓸 수 없기 때문에 위와 같은 재귀적 구조를 사용하였다. 한 가지 다행인 소식은 for
문으로 구현할 수 있는 모든 코드는 똑같이 메타 프로그래밍을 이용해서 구현할 수 있다. 
더군다나 위에서 보았듯이 if 문 역시 템플릿 특수화를 통해 TMP 로 구현할 수 있다. */


#include <iostream>

template <int X, int Y>
struct GCD {
    static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
    static const int value = X;
};

int main() {
    std::cout << "gcd (36, 24) :: " << GCD<36, 24>::value << std::endl;
}
/* 위와 같이 최대 공약수 계산 클래스를 만든 이유는 바로 Ratio 클래스를 만들기 위해서이다. 
Ratio 클래스는 유리수를 오차 없이 표현해주는 클래스이다. 물론 TMP 를 사용하지 않고 간단하게
클래스를 사용해서도 만들 수 있다. 하지만 일단 연습 삼아서 TMP 를 만들어보도록 하자.
(아래 코드 참고!!!) */

#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD {
	static const int value = GCD<Y, X% Y>::value;
};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
	typedef Ratio<N, D> type;
	static const int num = N;	// 분자
	static const int den = D;	// 분모
};

template <class R1, class R2>
struct _Ratio_add {
	typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main() {
	typedef Ratio<2, 3> rat;
	typedef Ratio<3, 2> rat2;
	typedef Ratio_add<rat, rat2> rat3;

	std::cout << rat3::num << " / " << rat3::den << std::endl;

	return 0;
}



#include <iostream>

template <int X, int Y>
struct GCD {
	static const int value = GCD<Y, X% Y>::value;
};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
private:
	const static int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type;
	static const int num = N / _gcd;
	static const int den = D / _gcd;
};

template <class R1, class R2>
struct _Ratio_add {		/* 비율(분수) 끼리의 덧셈 */
	/* _Ratio_add 는 두 비율 R1 과 R2 를 더하는 구조체이다.
	새로운 비율의 분자는 두 비율의 크로스 곱의 합이며, 분모는 두 분모의 곱이다. 
	Ratio_add 는 결과를 약분된 비율로 나타낸다. */
	using type = Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type{};

template <class R1, class R2>
struct _Ratio_subtract {	/* 비율(분수) 끼리의 뺄셈 */
	/* 비율 뺄셈의 경우, _Ratio_subtract 가 정의된다.
	이는 덧셈과 유사하나, 분자가 두 비율의 크로스 곱의 차이다. */
	using type = Ratio<R1::num* R2::den - R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct _Ratio_multiply {	/* 비율 곱셈 */
	/* _Ratio_multiply 는 두 비율을 곱하는 구조체이다.
	분자는 두 분자의 곱이고, 분모는 두 분모의 곱이다. */
	using type = Ratio<R1::num* R2::num, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {		/* 비율 나눗셈 */
	/* _Ratio_divide 는 두 비율을 나누는 구조체이다. 
	분자는 첫 번째 비율의 분자와 두 번째 비율의 곱이고,
	분모는 첫 번째 비율의 분모와 두 번째 비율의 분자의 곱이다. */
	using type = Ratio<R1::num* R2::den, R1::den* R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

int main() {
	using r1 = Ratio<2, 3>;
	using r2 = Ratio<3, 2>;		/* r1 과 r2 는 각각 2/3 와 3/2 로 정의된다. */

	using r3 = Ratio_add<r1, r2>;	/* r3 는 r1, r2 이 두 비율의 합으로 계산되며 결과가 출력된다. */
	std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;
	using r4 = Ratio_multiply<r1, r3>;	/* r4 는 r1 과 3 의 곱으로 계산되어서 출력된다. */
	std::cout << "13 / 6 * 2 / 3 = " << r4::num << " / " << r4::den << std::endl;
}

/* 생각해보기-문제 */
/* 문제 1:
N 번째 피보나치 수를 나타내는 TMP 를 만들어보아라. 참고로 피보나치 수는 N 번째 항이 N - 1 번째 항과
N - 2 번째 항의 합으로 정의되는 수이다. 참고로 1, 1, 2, 3, 5, ... 로 진행된다. (난이도: 하) */
int main() {
    std::cout << "5 번째 피보나치 수:: " << fib<5>::result << std::endl;    // 5
}
/* 문제 2:
TMP 를 사용해서 어떤 수가 소수인지 아닌지를 판별하는 프로그램을 만들어보아라. (난이도: 상)
참고로 이 문제는 다음 강좌에서 다룰 예정이다. */
int main() {
    std::cout << boolalpha;
    std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl;  // true
    std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl; // false
    std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl; // true
    std::cout << "Is prime ? :: " << is_prime<61>::reslut << std::endl; // true
}


/* 템플릿 메타프로그래밍 2부 */
/* 지난 강좌에서 왜 TMP 를 활용하여 힘들게 Ratio 클래스를 만들었는지 아직 설명하지 않아서 
의문을 가진 학생들이 많았을 것이다. 이유에 대해서 설명하기 전에, 지난 강좌의 생각해보기 문제
에 대해서 짚고 넘어가보고자 한다. */

/* 지난 강의 생각해보기 문제 */
/* 지난번 생각해보기 문제는 아래와 같다. 
TMP 를 사용해서 어떤 수가 소수인지 아닌지를 판별하는 프로그램을 만들어 보아라. (난이도: 상) */
int main() {
    std::cout << std::boolalpha;
    std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl;  // true
    std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl; // false
    std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl; // true
    std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl; // true 
}

/* 사실 처음에 딱 보았을 때 어떻게 TMP 로 구현할 것인지 감이 잡히지 않았을 것이다. 
하지만 만약에 소수인지 아닌지 판별하라는 '함수' 를 작성하게 하였다면 잘 작성하였을 
것이다. 아마도 구현한 코드는 아래와 같았을 것이다. */
bool is_prime(int N) {
    if (N == 2) return true;    /* 2 와 3 일 때를 각각 따로 처리하는 이유는 N / 2 까지 나누는 것으로 비교할 때
                                2, 3 일 경우 제대로 처리가 되지 않기 때문이다. */
    if (N == 3) return true;

    for (int i = 2; i <= N / 2; i++) {
        if (N % i == 0) return false;
    }

    return true;
}
/* 이 코드를 TMP 형식으로 옮기면 아래와 같다. */
template <>
struct is_prime<2> {
    static const bool result  = true;
};

template <>
struct is_prime<3> {
    static const bool result = true;
};

template <int N>
struct  is_prime {
    static const bool result = !check_div<N, 2>::result;
};

template <int N, int d>
struct check_div {
    static const bool result = (N  % d == 0) || check_div<N, d + 1>::result;
};

template <int N>
struct  check_div<N, N / 2> {
    static const bool result = (N % (N / 2) == 0);
};

/* 전체 코드 */
#include <iostream>

template <int N>
struct INT {
	static const int num = N;
};

template <typename a, typename b>
struct add {
	typedef INT<a::num + b::num> result;
};

template <typename a, typename b>
struct divide {
	typedef INT<a::num / b::num> result;
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div {
	// result
	static const bool result = (N::num % d::num == 0) ||
		check_div<N, typename add<d, one>::result>::result;
};

template <typename N>
struct _is_prime {
	static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> {
	static const bool result = true;
};

template <>
struct _is_prime<three> {
	static const bool result = true;
};

template <typename N>
struct check_div<N, typename divide<N, two>::result> {
	static const bool result = (N::num % (N::num / 2) == 0);
};

template <int N>
struct is_prime {
	static const bool result = _is_prime<INT<N>>::result;
};

int main() {
	std::cout << std::boolalpha;
	std::cout << "Is 2 prime ? :: " << is_prime<2>::result << std::endl;
	std::cout << "Is 10 prime ? :: " << is_prime<10>::result << std::endl;
	std::cout << "Is 11 prime ? :: " << is_prime<11>::result << std::endl;
	std::cout << "Is 61 prime ? :: " << is_prime<61>::result << std::endl;
}


/* 단위 라이브러리 */
/* 단위라 하면 쉽게 말해 킬로그램(kg), 미터(m), 초(s) 등을 생각하면 된다. 
이러한 것들을 계산하는 프로그램들의 경우, double 이나 float 변수에 들어가
는 값에는 '단위' 가 붙어서 들어갈 것이다. */

/* 전체 코드 */
#include <iostream>

template <int X, int Y>
struct GCD {
    static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
    static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
    private:
    const static int _gcd = GCD<N, D>::value;

    public:
    typdef Ratio<N / _gcd, D / _gcd> type;
    static const int num = N / gcd;
    static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
    using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
    using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_substract : _Ratio_subtract<R1, R2>L::type {};

template <class R1, class R2>
struct _Ratio_multiply {
    using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
    using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim {
    using M = U;
    using L = V;
    using T = W;

    using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
    typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
                typename Ratio_add<typename U::l, typename V::L>::type,
                typename Ratio_add<typename U::T, typename V::T>::type>
            type;
};

template <typename U, typename V>
struct subtract_dim_ {
    typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
                typename Ratio_subtract<typename U::L, typename V::l>::type,
                typename Ratio_subtract<typename U::T, typename V::T>::type>
            type; 
};

template <typename T, typename D>
struct quantity {
    T q;
    using dim_type = D;

    quantity operator+(quantity<T, D> quant) {
        return quantity<T, D>(q+ quant.q);
    }

    quantity operator-(quantity<T, D> quant) {
        return quantity<T, D>(q - quant.q);
    }

    quantity(T q) : q(q) {}
};
int main() {
    using one = Ratio<1, 1>;
    using zero = Ratio<0, 1>;

    quantity<double, Dim<one, zero, zero>> kg(1);
    quantity<double, Dim<zero, one, zero>> meter(1);
    quantity<double, Dim<zero, zero, one>> second(1);

    // Good
    kg + kg;

    // Bad
    kg + meter;
    /* 해당 소스코드를 컴파일하면 컴파일 오류가 발생한다.
    오류가 발생하는 이유는 위 + 에 해당하는 연산자 함수를 찾을 수 없기 때문이다. 
    예상했던 대로 
    // Bad
    kg + meter;
    위 부분에서 오류가 발생하는데, kg 와 meter 의 단위가 다르기 때문에 오류가 발생하게 된다. 
    반면에 
    // Good
    kg + kg;
    는 잘 컴파일된다. 
    그렇다면이제 * 와 / 연산자만 만들어 주면 된다. 하지만 * 와 / 의 경우 + 와 - 보다 좀 더 까다롭다. 
    왜냐하면 * 와 / 의 경우 굳이 Dim 이 일치하지 않아도 되기 때문이다. 다만 이 연산을 수행하였을 때
    새로운 차원의 데이터가 나올 뿐이다. */
}
/* 따라서 operator* 와 operator/ 의 경우, 두 개의 다른 차원의 값을 받아도 처리할 수 있어야 한다. 
따라서 operator* 와 / 를 정의해보자면 아래와 같다. */
template <typename D2>
quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
    return quantity<T, tyepname add_dim_<D, D2>::type>(q * quant.q);
}

template <typename D2>
quantity<T, typename subtract_dim<D, D2>::type> operator/(
    quantity<T, D2> quant) {
        return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
    }
    


/* 타입을 알아서 추측해라! - auto 키워드 */
#include <iostream>
#include <typeinfo>

int sum(int a, int b) { return a + b; }     /* sum 함수는 두 개의 정수 인자를 받아 더한 값을 반환하는 함수이다. 반환 타입은 int 이다. */

class SomeClass {
    int data;

    public:
    SomeClass(int d) : data(d) {}
    SomeClass(const SomeClass& s) : data(s.data) {}
    /* SomeClass 는 int 형 데이터 멤버 data 를 가지고 있다. 생성자는 두 가지가 있다. 
    첫 번째 생성자는 int 값을 받아서 data 를 초기화한다. 
    두 번째 생성자는 복사 생성자로, 다른 SomeClass 객체를 받아서 그 객체의 data 값을 복사한다. */
};

int main() {
    auto c = sum(1, 2);  // 함수 리턴 타입으로부터 int 라고 추측 가능
    auto num = 1.0 + 2.0; // double 로 추측 가능!! --> 1.0 + 2.0 은 double 타입의 연산이므로 num 은 double 타입으로 추론된다. 

    SomeClass some(10);     /* some 은 10 을 이용하여 초기화된 SomeClass 객체이다. */
    auto some2 = some;      /* some 객체를 복사하여 some2 로 할당하므로 some2 는 SomeClass 타입이다. */

    auto some3(10);         /* 이 부분은 혼란을 일으킬 수 있다. 
                            일반적으로 auto some3(10) 은 정수형 int 변수로 추론된다. 이는 직접 초기화 방식이다. 
                            auto 가 초기화 값을 보고 타입을 추론하기 때문에 int some3 = 10; 과 동일하다. 
                            즉, SomeClass 객체가 아니라 int 타입이다. */

    std::cout << "c 의 타입은?? :: " << typeid(c).name() << std::endl;  // 예상되는 출력: int(vscode 에서는 축약되어서 i 로 출력됨.)
    /* 각 변수 c, num, some2, some3 의 타입을 typeid 를 사용해 출력한다. 
    typeid(c).name() 은 c 의 타입 정보를 문자열로 반환하며, 이 결과는 컴파일러마다 다를 수 있다. */
    std::cout << "num 의 타입은?? :: " << typeid(num).name() << std::endl;  // 예상되는 출력: double(vscode 에서는 축약되어서 d 로 출력됨.)
    std::cout << "some2 의 타입은?? :: " << typeid(some2).name() << std::endl;  // 예상되는 출력: SomeClass
    // (vscode 에서는 9SomeClass 라고 출력됨.--> 9 는 SomeClass 라는 클래스 이름의 길이를 나타냄. 
    // SomeClass 와 같은 사용자 정의 타입은 컴파일러가 그 이름을 포함한 여러 정보를 포함하여 내부적으로 맹글링된 이름을 유지한다.)
    std::cout << "some3 의 타입은?? :: " << typeid(some3).name() << std::endl;  // 예상되는 출력: int(vscode 에서는 축약되어서 i 로 출력됨.)
}
/* 왜 SomeClass 가 아니라 9SomeClass 로 출력되는지?? */
/* typeid().name() 의 출력 결과는 C++ 의 맹글링된(mangled) 이름으로 나오기 때문에,
클래스 이름에 숫자가 붙는 경우가 있다. C++ 에서 함수와 클래스 등의 이름을 구분하고 
중복을 피하기 위해, 컴파일러는 '이름 맹글링' 이라는 과정을 거친다.
이 과정에서 함수나 클래스의 이름 앞에 길이 정보를 붙여 다른 타입과 구분한다. 
하지만 Visual Studio 에서는 보통 디맹글링된 이름을 출력하기 때문에, 만약 사람이 읽기
쉬운 방식으로 타입 이름을 출력하고 싶다면 Visual Studio 를 활용하면 된다. */






#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD {
    static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
    static const int value = X;
    /* GCD 구조체 (최대 공약수 계산) 
    GCD 구조체는 재귀 템플릿을 이용해 두 정수 X 와 Y 의 최대공약수(GCD) 를 계산한다.
    기본 템플릿에서는 X % Y (나머지 연산) 를 계산한 후, Y 가 0 이 될 때까지 재귀적으로 호출한다.
    두 번째 템플릿 특수화에서 Y == 0 일 때 재귀가 멈추고, X 를 반환한다. 이는 유클리드 알고리즘을
    템플릿으로 구현한 것이다. */
};

template <int N, int D = 1>
struct Ratio {
    private:
    const static int _gcd = GCD<N, D>::value;

    public:
    typedef Ratio<N / _gcd, D / _gcd> type;
    static const int num = N / _gcd;
    static const int den = D / _gcd;
    /* Ratio 구조체 (분수 표현 및 정규화) 
    Ratio 는 분수를 표현하는 템플릿 구조체로, 분자(numerator) 와 분모(denominator) 를 나타낸다.
    입력된 분자 N 과 분모 D 의 최대공약수를 계산한 후, 이를 나눠 정규화된 분수를 저장한다. 예를 들어
    Ratio<4, 6> 은 Ratio<2, 3> 로 간략화된다. */
};

template <class R1, class R2>  // 분수 연산 - '덧셈'
struct  _Ratio_add {
    using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>  // 분수 연산 - '뺄셈'
struct _Ratio_subtract {
    using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>  // 분수 연산 - '곱셈'
/* Ratio_add 는 두 Ratio 의 분모와 분자를 계산하여 새로운 Ratio 를 만든다. 
    이는 두 분수를 더한 후, 그 결과를 Ratio 로 표현하는 방식이다. */
struct _Ratio_multiply {
    using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>  // 분수 연산 - '나눗셈'
struct _Ratio_divide {
    using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

/* Dim 구조체 (단위 차원 표현) */
template <typename U, typename V, typename W>
struct Dim {
    /* Dim 구조체는 물리적인 차원(Dimension) 을 표현한다. 
    예를 들어, 질량(M), 길이(L), 시간(T) 의 차원을 나타낸다. 
    이 구조체는 세 개의 Ratio 타입을 통해서 각각의 차원을 나타낸다. 
    M 은 질량에 대한 차원
    L 은 길이에 대한 차원
    T 는 시간에 대한 차원을 의미한다. 
    예를 들어, Dim<one, zero, zero> 은 질량만을 나타내며, Dim<zero, one, zero> 는 길이를,
    Dim<zero, zero, one> 는 시간을 나타낸다. */
    using M = U;
    using L = V;
    using T = W;

    using type = Dim<M, L, T>;
};

template <typename U, typename V>
/* 이 구조체는 두 Dim 타입을 받아 각각의 Ratio 차원을 더해 새로운 Dim 을 만든다.
예를 들어, 질량 M 과 시간 T 를 나누는 연산을 할 때, 차원이 적절하게 계산된다. */
struct add_dim_ {
    typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
                typename Ratio_add<typename U::L, typename V::L>::type,
                typename Ratio_add<typename U::T, typename V::T>::type>
        type;
};

template <typename U, typename V>
struct subtract_dim_ {
    typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
                typename Ratio_subtract<typename U::L, typename V::L>::type,
                typename Ratio_subtract<typename U::T, typename V::T>::type>
            type;
};

template <typename T, typename D>
struct quantity {       /* quantity
                        quantity 는 물리량을 나타내는 구조체이다. 
                        T 는 데이터 타입(예: double), D 는 차원을 나타낸다. 
                        operator+, operator- 를 오버로드하여 같은 차원의 물리량끼리
                        더하거나 뺄 수 있도록 정의되었다. */
    T  q;
    using dim_type = D;

    quantity operator+(quantity<T, D> quant) {
        return quantity<T, D>(q + quant.q);
    }

    quantity operator-(quantity<T, D> quant) {
        return quantity<T, D>(q - quant.q);
    }

    template <typename D2>
    /* <단위 차원의 연산>
    물리량 간의 곱셈과 나눗셈 연산을 지원하기 위해 add_dim_ 과 subtract_dim_ 구조체가 사용된다. */
    quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
        return quantity<T, typename add_dim_<D, D2>::type>(q * quant.q);
    }

    template <typename D2>
    quantity<T, typename subtract_dim_<D, D2>::type> operator/(
        quantity<T, D2> quant) {
            return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
        }

        // Scalar multiplication and division
        quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }

        quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }

        quantity(T q) : q(q) {}
};

template <typename T, typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q) {
    out << q.q << "kg^" << D::M::num / D::M::den << "m^" << D::L::num / D::L::den
        << "s^" << D::T::num / D::T::den;

    return out;
}

int main() {
    using one = Ratio<1, 1>;
    using zero = Ratio<0, 1>;

    quantity<double, Dim<one, zero, zero>> kg(2);
    quantity<double, Dim<zero, one, zero>> meter(3);
    quantity<double, Dim<zero, zero, one>> second(1);

    // F 의 타입은 굳이 알 필요 없다!!
    auto F = kg * meter / (second * second);
    std::cout << "2 kg 물체를 2m/s^2 의 가속도로 밀기 위한 힘의 크기는??  " << F
                << std::endl;
    /* kg, meter, second 는 각각 질량, 길이, 시간 단위를 표현하는 quantity 이다.
    kg* meter / (second * second) 는 질량 x 길이 / 시간^2 으로, **힘(force)** 을 나타낸다. 
    여기서 auto F 는 자동으로 타입을 추론하여, quantity<double, Dim<one, one, -2>> 형태의 물리량으로 추정된다. 
    
    출력 결과는 힘의 크기를 나타내는 값과 함께 단위가 "kg x m / s^2" 로 표시된다. */

    /* 해당 소스코드는 템플릿을 이용해서 분수 연산, 차원 연산, 그리고 물리량 계산을 구현한 예제이다.
    quantity 는 Dim 을 사용해 물리량과 단위를 다루며, 연산자 오버로딩을 통해 물리적 계산을 지원한다.
    힘(Force) 계산 예시로, 질량과 가속도를 곱해 힘을 구하고 그 결과를 출력한다.  */
}


/* 생각해보기-문제 */
/* 문제 1: 
컴파일러가 auto 키워드에 들어갈 타입을 추측하는 방법은 템플릿에서 들어갈 타입을 추측하는 방법과 같다. 
(교재 493p-링크 있으니 들어가서 읽어보기!!!) */


/* 버블 정렬의 코드 */
for (int i = 0; i < N; i++) {           /* 외부 반복문 --> 배열의 첫 번째 요소부터 마지막 요소까지 반복한다.
                                        i 는 배열에서 비교할 기준 요소의 인덱스를 나타낸다. */
    for (int j = i + 1; j < N; j++) {   /* 내부 루프에서는 i 다음에 있는 요소들인 j 와 i 를 비교한다. 
                                        즉, i 번째 요소를 기준으로 그 다음 요소들 j 와 비교하면서 배열 내에서 
                                        i 보다 작은 값이 있으면 위치를 바꾸는 방식이다. 
                                        j 는 i + 1 부터 시작하므로 i 다음의 요소들과만 비교한다. */
        if (arr[i] > arr[j]) {          /* 배열의 i 번째 값이 j 번째 값보다 크다면 두 값을 교환한다. 
                                        이때, arr[i] > arr[j] 는 오름차순 정렬을 의미한다. 만약 내림차순으로
                                        정렬하고 싶다면 arr[i] < arr[j] 로 바꾸면 된다. */
            swap(arr, i , j)            /* 값 교환 --> arr[i] 와 arr[j] 의 값을 서로 교환한다. 
                                        이 과정을 통해, 각 반복에서 i 번째 요소는 해당 요소보다 작은 값들을 앞으로
                                        이동시키고, 최종적으로 가장 작은 값이 배열의 앞쪽에 배치된다. */
        }
    }
}


#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    /* 맨 뒤에 원소를 추가할 때: push_back 함수 사용
       맨 뒤에 원소를 제거할 때: pop_back 함수 사용 */
    vec.push_back(10);  // 맨 뒤에 10 추가
    vec.push_back(20);  // 맨 뒤에 20 추가
    vec.push_back(30);  // 맨 뒤에 30 추가
    vec.push_back(40);  // 맨 뒤에 40 추가

    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << "vec 의 " << i + 1 << " 번째 원소" << vec[i] << std::endl;
    }
}


/* 반복자(iterator) */
/* 반복자는 컨테이너에 원소에 접근할 수 있는 포인터와 같은 객체라고 앞서 말했다.
물론 벡터의 경우 [] 를 이용해서 정수형 변수로 마치 배열처럼 임의의 위치에 접근할 수 있지만,
반복자를 사용해서도 마찬가지의 작업을 수행할 수 있다. 특히 후에 배울 알고리즘 라이브러리의 
경우 대부분이 반복자를 인자로 받아서 알고리즘을 수행한다. 
반복자는 컨테이너에 iterator 멤버 타입으로 정의되어 있다. vector 의 경우, 반복자를 얻기 위해서
begin() 함수와 end() 함수를 사용할 수 있는데, 이는 다음과 같은 위치를 리턴한다. 
begin() 함수는 예상했던 대로, vector 의 첫 번째 원소를 가리키는 반복자를 리턴한다. 그런데 흥미롭
게도 end() 의 경우 vector 의 마지막 원소 한 칸 뒤를 가리키는 반복자를 리턴하게 된다. 왜 end 의 
경우 vector 의 마지막 원소를 가리키는 것이 아니라, 마지막 원소의 뒤를 가리키는 반복자를 리턴할까?? 
이에 여러가지 이유가 있겠지만, 가장 중요한 점이 이를 통해 빈 벡터를 표현할 수 있다는 점이다. 만일 
begin() == end() 라면 원소가 없는 벡터를 의미할 것이다. 만약 vec.end() 가 마지막 원소를 가리킨다면
비어있는 벡터를 표현할 수 없게 된다. */


// 반복자 사용 예시
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // 전체 벡터를 출력하기
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    // int arr[4] = {10, 20, 30, 40}
    // *(arr + 2) == arr[2] == 30;
    // *(itr + 2) == vec[2] == 30;

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "3 번째 원소:: " << *itr << std::endl;
}


#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // 전체 벡터를 출력하기 
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
        ++itr) {
        std::cout << *itr << std::endl;
        }
}
int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);
    std::cout << "------------------------" << std::endl;

    // vec[2] 앞에 15 추가
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);
    std::cout << "---------------------" << std::endl;
    // vec[3] 제거--> vec[3] 은 30 이므로, 30 이 제거된 채로 출력된다. 
    vec.erase(vec.begin() + 3);
    print_vector(vec);
}


#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    std::cout << "[ ";
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
        ++itr) {
            std::cout << *itr << " ";
        }
        std::cout << "]";
}
int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(20);

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);

    std::vector<int>::iterator itr = vec.begin();
    std::vector<int>::iterator end_itr = vec.end();

    for (; itr != end_itr; ++itr) {     /* 해당 코드의 오류발생 원인!!! 
                                        컨테이너에 원소를 추가하거나 제거하게 되면 기존에 사용하였던
                                        모든 반복자들을 사용할 수 없게 된다. 다시 말해 위 경우 
                                        vec.erase(itr) 을 수행하게 되면 더 이상 itr 은 유효한 반복자가
                                        아니게 되는 것이다. 또한 end_itr 역시 무효화된다. 
                                        따라서 itr != end_itr 이 영원히 성립되며 무한 루프에 빠지게 되어 
                                        위와 같은 오류가 발생하게 된다. */
        if (*itr == 20) {
            vec.erase(itr);
        }
    }

    std::cout << "값이 20 인 원소를 지운다!!" << std::endl;
    print_vector(vec);
    /* 해당 소스코드를 컴파일하면 오류가 발생한다. */
}


/* const_iterator */
/* vector 에서 지원하는 반복자로 const_iterator 가 있다.
이는 마치 const 포인터를 생각하면 된다. 즉, const_iterator 의
경우 가리키고 있는 원소의 값을 바꿀 수 없다. 예를 들어서 */
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    for (typename std::vector<T>::iterator itr = vec.begin(); itr!= vec.end();
        ++itr) {
        std::cout << *itr << std::endl;
        }
}
int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "초기 vec 상태" << std::endl;
    print_vector(vec);

    // itr 은 vec[2] 를 가리킨다. 
    std::vector<int>::iterator itr = vec.begin() + 2;

    // vec[2] 의 값을 50 으로 바꾼다. 
    *itr = 50;

    std::cout << "---------------------" << std::endl;
    print_vector(vec);

    std::vector<int>::const_iterator citr = vec.cbegin() + 2;

    // 상수 반복자가 가리키는 값은 바꿀 수 없다. 불가능!!
    *citr = 30;
    /* 컴파일하면 const 반복자가 가리키고 있는 값은 바꿀 수 없다고 오류가 발생한다. 
    주의할 점은, const 반복자의 경우
    std::vector<int>::const_iterator citr = vec.cbegin() + 2; 
    와 같이 cbegin() 과 cend() 함수를 이용하여 얻을 수 있다. 많은 경우 반복자의 값을 바꾸지
    않고 참조만 하는 경우가 많으므로, const iterator 를 적절히 이용하는 것이 좋다. */
}


/* 역반복자(reverse iterator) */
/* vector 에서 지원하는 반복자 중 마지막 종류로 '역반복자(reverse iterator)' 가 있다.
이는 반복자와 똑같지만 벡터 뒤에서부터 앞으로 거꾸로 간다는 특징이 있다. (아래 예제 참고!!!) */
#include <iostream>
#include <vector>

template <typename T>   /* : 템플릿을 사용하여 다양한 자료형의 벡터를 받을 수 있게 함수 print_vector 를 정의한다. */
void print_vector(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
    /* std::vector<T>::iterator itr : 벡터의 반복자(iterator) 를 사용하여 벡터를 처음부터 끝까지 순차적으로 출력한다. 
    begin() 은 벡터의 첫 번째 요소를 가리키고, end() 는 마지막 요소의 다음 위치를 가리킨다. 
    *itr 은 반복자가 나타내는 현재 요소의 값을 출력한다. */
        ++itr) {
            std::cout << *itr << std::endl;
        }
}
int main() {
    std::vector<int> vec;   /* std::vector<int> vec: int 형 요소들을 저장할 수 있는 벡터를 선언한다. */
    /* vec.push_back() : 벡터의 끝에 새로운 요소를 추가한다. 예시에서는 10, 20, 30, 40 을 차례대로 추가했다. */
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "초기 vec 상태" << std::endl;
    print_vector(vec);  /* : 벡터의 요소들을 처음부터 순차적으로 출력하는 함수이다. */

    std::cout << "역으로 vec 출력하기!!" << std::endl;
    // itr 은 vec[2] 를 가리킨다. 
    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    /* std::vector<int>::reverse_iterator r_iter: 역반복자(reverse iterator) 를 사용하여 벡터의 마지막 요소부터 처음까지 순차적으로 접근한다. 
       rbegin() : 벡터의 마지막 요소를 가리키는 역반복자를 반환한다. 
       rend() : 벡터의 첫 번째 요소 이전 위치를 가리키는 역반복자를 반환한다. 
       반복자를 r_iter++ 을 사용해 한 요소씩 앞으로 이동하며, 가리키는 요소의 값을 출력한다. */
    for (; r_iter != vec.rend(); r_iter++) {
        std::cout << *r_iter << std::endl;
    }
    /* 처음에는 print_vector 함수로 벡터의 요소들을 순차적으로 출력한다. 
    두 번째로는 reverse_iterator 를 사용해 벡터의 요소들을 역순으로 출력한다. 
    이 코드는 std::vector 의 반복자와 역반복자를 사용해 벡터를 정방향과 역방향으로 출력하는 방법을 보여준다. */
}


#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // 끝에서부터 출력하기
    for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
    /* 해당 코드를 출력하게 되면 오류가 발생하게 된다. 오류가 발생한 이유는 vector 의 index 를 담당하는
    타입이 '부호 없는 정수' 이기 때문이다. 따라서 i 가 0 일 때 i-- 를 하게 된다면 -1 이 되는 것이 아니라,
    해당 타입에서 가장 큰 정수가 되어버리게 된다. 
    따라서 for 문이 영원히 종료될 수 없게 되어버린다. 
    이 문제를 해결하기 위해서는 부호 있는 정수로 선언해야 하는데, 이 경우 vector 의 index 타입과 일치하지
    않아서 타입 캐스팅을 해야 한다는 문제가 발생하게 된다. 
    따라서 가장 현명한 선택으로는 역으로 원소를 참조하고 싶다면, 역반복자를 사용하는 것이다. */
}


/* 범위 기반 for 문(range based for loop) */
/* 위의 코드와 같이 컨테이너의 원소를 for 문으로 접근하는 패턴은 매우 많이 등장하는데, 
C++11 에서부터는 이와 같은 패턴을 매우 간단하게 나타낼 수 있는 방식을 제공하고 있다. 
바로 범위 기반(range-based) for 문이라고 불리는 것이다. */
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // range-based for 문
    for (int elem: vec) {
        std::cout << "원소 : " << elem << std::endl;
        /* elem 에 vec 의 원소들이 매 루프마다 복사되어서 들어가게 된다. 
        마치
        elem = vec[i];
        를 한 것과 같다. 만약에 복사하기보다는 레퍼런스를 받고 싶다면 어떨까?? 매우 간단하다.
        단순히 레퍼런스 타입으로 바꿔버리면 된다. 예를 들어서 기존의 print_vec 함수를 범위 기반 
        for 문을 사용해서 어떻게 바꿀 수 있는지 살펴보자. */
    }

    return 0;
}


#include <iostream>
#include <vector>

template <typename T>   /* 전통적인 반복자(iterator) 를 사용하는 print_vector 함수 */
/* templata <typename T> : 템플릿을 사용하여 T 라는 데이터 타입을 받아들인다. 이는 벡터의 자료형이 무엇이든 동일한 코드를 사용할 수 있게 해준다. */
void print_vector(std::vector<T>& vec) {    /* std::vector<T>& vec : T 타입의 벡터를 참조로 받는다. */
    // 전체 벡터를 출력하기
    for  (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
    /* typename std::vector<T>::iterator itr : 벡터의 반복자이다. 반복자는 벡터의 요소를 가리키는 역할을 하며, 포인터처럼 동작한다. 
        vec.begin() : 벡터의 첫 번째 요소를 가리킨다. 
        vec.end() : 벡터의 마지막 요소 다음을 가리킨다. */
        ++itr) {
            std::cout << *itr << std::endl; /* *itr : 반복자가 가리키는 현재 요소의 값을 출력한다. 
                                                반복자는 ++itr 을 사용해 다음 요소로 이동한다. */
        }
}

template <typename T>   /* 위와 마찬가지로 템플릿을 사용하여 범용적인 데이터 타입을 지원한다. */
void print_vector_range_based(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    for (const auto& elem : vec) {  /* const auto& elem : 범위 기반 for 루프에서 벡터의 각 요소를 가리킨다. 
                                        auto : 자동으로 타입을 추론하는 키워드로, 벡터 내의 데이터 타입에 따라 자동으로 int, float 등으로 변환된다.
                                        const : 요소가 수정되지 않도록 상수로 선언된다. 
                                        & : 요소를 복사하지 않고 참조로 받아온다. 이는 불필요한 복사를 방지하고 성능을 향상시킨다. 
                                    이 방법은 반복자 없이도 벡터의 모든 요소를 순회하며 출력할 수 있는 간단한 구문이다. */
        std::cout << elem << std::endl;
    }
}

int main() {
    std::vector<int> vec;   /* int 타입의 벡터를 선언한다. */
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "print_vector" << std::endl;   
    print_vector(vec);  /* : 전통적인 반복자 방식으로 벡터의 요소를 출력한다. */
    std::cout << "print_vector_range_based" << std::endl;
    print_vector_range_based(vec);  /* : 범위 기반 for 루프 방식으로 벡터의 요소를 출력한다. */

    return 0;
    /* print_vector : 전통적인 반복자(iterator) 를 사용하여 벡터의 요소를 순차적으로 출력한다.
       print_vector_range_based : 범위 기반 for 루프를 사용하여 벡터의 요소를 출력하는 '더 간결한 방법' 이다. 
    두 함수 모두 벡터의 모든 요소를 출력하지만, 범위 기반 for 루프는 코드가 더 간결하고 가독성이 좋다. */
}


#include <iostream>
#include <list>

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}


#include <iostream>
#include <list>

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
    /* 한 가지 흥미로운 점은 리스트의 반복자의 경우, 다음과 같은 연산밖에 수행할 수 없다. 
    itr++   // itr ++
    itr--   // --itr 도 된다. 
    다시 말해, 
    itr + 5 // 불가능!!
    와 같이 임의의 위치에 있는 원소를 가리킬 수 없다는 것이다. 반복자는 오직 한 칸씩밖에 움직일 수 없다. 
    
    이와 같은 이유는 list 의 구조를 생각해보면 알 수 있다. 앞서 말했듯이 리스트는 왼쪽 혹은 오른쪽을 가리키고
    있는 원소들의 모임으로 이루어져 있기 때문에, 한 번에 한 칸씩밖에 이동할 수 없다. 즉, 메모리 상에서 원소들이 
    연속적으로 존재하지 않을 수 있다는 뜻이다. 반면에 벡터의 경우, 메모리 상에서 연속적으로 존재하기 때문에 쉽게
    임의의 위치에 있는 원소를 참조할 수 있다. */
}


#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[ ";
    // 전체 리스트를 출력하기 (이 역시 범위 기반 for 문을 쓸 수 있다.)
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    } 
    std::cout << "]" << std::endl;
}
int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "처음 리스트의 상태" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        // 만일 현재 원소가 20 이라면
        // 그 앞에 50 을 집어넣는다. 
        if (*itr == 20) {
            lst.insert(itr, 50);
            /* 앞서 설명하였지만, 리스트의 반복자는 BidirectionIterator 이기 때문에 ++ 과 -- 연산만
            사용 가능하다. 따라서 위처럼 for 문으로 하나 하나 원소를 확인해보는 것이 가능하다. vector
            와는 다르게 insert 작업은 0(1) 으로 매우 빠르게 실행된다. */
        }
    }

    std::cout << "값이 20 인 원소 앞에 50 을 추가" << std::endl;
    print_list(lst);
    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        // 값이 30 인 원소를 삭제한다. 
        if (*itr == 30) {
            lst.erase(itr);
            break;
            /* 마찬가지로 erase 함수를 이용하여 원하는 위치에 있는 원소를 지울 수도 있다. 
            리스트의 경우는 벡터와는 다르게, 원소를 지워도 반복자가 무효화되지 않는다. 
            왜냐하면, 각 원소들의 주소값은 바뀌지 않기 때문이다. */
        }
    }

    std::cout << "값이 30 인 원소를 제거한다." << std::endl;
    print_list(lst);
}


/* 덱(deque-double ended queue) */
/* 마지막으로 살펴볼 컨테이너는 '덱(deque)' 이라고 불리는 자료형이다. 
덱은 벡터와 비슷하게 O(1) 으로 임의의 위치의 원소에 접근할 수 있으며 맨 뒤에 원소를 
추가/제거하는 작업도 O(1) 으로 수행할 수 있다. 뿐만아니라 벡터와는 다르게 맨 앞에
원소를 추가/제거하는 작업까지도 O(1) 으로 수행 가능하다. 

임의의 위치에 있는 원소를 추가/제거하는 작업은 벡터와 마찬가지로 O(n) 으로 수행 가능하다.
뿐만 아니라 그 속도도 벡터보다 더 빠르다.
그렇다면 덱이 벡터에 비해 모든 면에서 비교 우위에 있는 걸까?? 안타깝게도 벡터와는 다르게
덱의 경우, 원소들이 실제로 메모리 상에서 연속적으로 존재하지는 않는다. 이 때문에 원소들이 
어디에 저장되어 있는지에 대한 정보를 보관하기 위해 추가적인 메모리가 더 필요로 한다. 
(실제 예로, 64 비트 libc++ 라이브러리의 경우 1 개의 원소를 보관하는 덱은 그 원소 크기에 비해 
8 배나 더 많은 메모리를 필요로 한다.)
즉, 덱은 실행 속도를 위해 메모리를 (많이) 희생하는 컨테이너라 보면 된다. */


/* 덱 사용 */
#include <deque>
#include <iostream>

template <typename T>
void print_deque(std::deque<T>& dq) {
    // 전체 덱을 출력하기
    std::cout << "[ ";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << " ] " << std::endl;
}
int main() {
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);

    std::cout << "초기 dq 상태" << std::endl;
    print_deque(dq);    /* 초기 dq 상태
                           [ 40 30 10 20  ]
                           로 출력된다. */

    std::cout << "맨 앞의 원소 제거" << std::endl;
    dq.pop_front();
    print_deque(dq);    /* 맨 앞의 원소 제거
                           [ 30 10 20  ]
                           로 출력된다. */
/* 위와 같이 push_back 과 push_front 를 이용해서 맨 앞과 뒤에 원소들을 추가하였고,
pop_front 함수를 이용해서 맨 앞의 원소를 제거할 수 있다. */
/* 앞서 말했듯이 덱 역시 벡터처럼 임의의 위치에 존재하는 원소에 접근할 수 있으므로 [] 와
at 함수를 제공하고 있고, 반복자 역시 RandomAccessIterator 타입이고 벡터랑 정확히 동일한 
방식으로 작동한다. */
}


/* 그래서 어떤 컨테이너를 사용할까?? */
/* 어떠한 컨테이너를 사용할지는 전적으로 이 컨테이너를 가지고 어떠한 작업들을 많이 하냐에 달려있다.
-일반적인 상황에는 그냥 벡터를 사용한다. (거의 만능이다.)
-만약에 맨 끝이 아닌 중간에 원소들을 추가하거나 제거하는 일을 많이 하고, 원소들을 순차적으로만 접근한다면
리스트를 사용한다. 
-만약에 맨 처음과 끝 모두에 원소들을 추가하는 작업을 많이 한다면 덱을 사용한다. 
참고적으로, O(1) 으로 작동한다는 것은 언제나 이론적 결과일 뿐이며 실제로 프로그램을 짜게 된다면
O(log n) 이나 O(n) 보다도 느릴 수 있다. (n 의 크기에 따라서) 따라서 속도가 중요한 환경이라면 
적절한 벤치마크를 통해서 성능을 가늠해보는 것도 좋다. */

/* 생각해보기-문제 */
/* 문제 1:
deque 를 구현해보아라. (난이도: 하) */
/* 문제 2:
교재 521p 참고!!!--> 자료를 한 번 읽어보기(링크는 교재에 있긴 한 듯..??) */



/* 셋(set) */
/* 셋(set) 은 중복되지 않는 값을 자동으로 정렬하여 저장하는 자료 구조이다. */
#include <iostream>
#include <set>

template <typename T>   /* : set 의 데이터 타입을 템플릿으로 받아들여, 다양한 타입의 set 을 지원할 수 있다. */
void print_set(std::set<T>& s) {
    // 셋의 모든 원소들을 출력하기
    std::cout << "[ ";
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << "] " << std::endl;
}
int main() {
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "순서대로 정렬돼서 나온다. " << std::endl;
    print_set(s);

    std::cout << "20 이 s 의 원소인가요?? :: ";
    auto itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    std::cout << "25 가 s 의 원소인가요?? :: ";
    itr = s.find(25);
    /* set 에는 find 함수가 제공되며, 이 find 함수를 통해 이 셋에 원소가 존재하는지 여부를 확인할 수 있다. 
    만일 해당하는 원소가 존재한다면 이를 가리키는 반복자를 리턴하고 (std::set<>::iterator 타입이다.) 만일
    존재하지 않는다면 s.end() 를 리턴하게 된다. */
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}


/* 셋의 중요한 특징으로는 바로 셋 안에는 중복된 원소들이 없다는 점이 있다. */
#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s) {
    // 셋의 모든 원소들을 출력하기
    std::cout << "[ ";
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << "] " << std::endl;
}

int main() {
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);
    s.insert(10);

    print_set(s);
    /* 해당 소스코드를 출력하면 결과는 다음과 같다. 
    [ 10 20 30 ]
    10 과 20 을 두 번씩 넣었는데 실제로는 한 번씩밖에 출력되지 않은 것을 볼 수 있다. 
    이는 셋 자체적으로 이미 같은 원소가 있다면 이를 insert 하지 않기 때문이다. 따라서 
    마지막 두 insert 작업은 무시되었을 것이다. 
    
    참고로 시퀀스 컨테이너들과 마찬가지로 set 역시 범위 기반 for 문을 지원한다. 원소들의 접근 순서는 반복자를 이용해서 접근했을 때와 동일하다. 
    만약에 중복된 원소를 허락하고 싶다면 멀티셋(multiset) 을 사용하면 되는데, 이는 후에 설명할 것이다. */
}


/* 사용자가 만든 객체를 셋에 넣고 싶을 때 */
/* 위와 같은 기본 타입들 말고, 우리가 만든 클래스의 객체를 셋의 원소로 사용할 때 한 가지 
주의해야 할 점이 있다. 아래는 할 일 (Todo) 목록을 저장하기 위해 셋을 사용하는 예시이다. 
Todo 클래스는 2 개의 멤버 변수를 가지는데 하나는 할 일의 중요도이고, 하나는 해야할 일의 설명이다. */
#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
    // 셋의 모든 원소들을 출력하기 
    std::cout << "[ ";
    for (const auto& elem : s) {
        std::cout << elem << " " << std::endl;
    }
    std::cout << "] " << std::endl;
}
class Todo {
    int priority;   // 중요도. 높을수록 급한 것!!!
    std::string job_desc;

    public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc) {}
};
int main() {
    std::set<Todo> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(2, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));
    /* 컴파일하면, 컴파일 오류가 발생한다. 
    컴파일 오류가 발생한 이유는 다음과 같다. 앞서 셋은 원소들을 저장할 떄 내부적으로 정렬된 상태를 유지한다고 하였다. 
    즉 정렬을 하기 위해서는 반드시 원소 간의 비교를 수행해야 한다. 하지만, Todo 클래스에는 operator< 가 정의되어 있지
    않다. 따라서 컴파일러는 < 연산자를 찾을 수 없기에 위와 같은 오류를 뿜어내는 것이다. 
    그렇다면 오류의 해결방법은 직접 Todo 클래스에 operator< 를 만들어주는 수밖에 없다. */
}


#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
    // 셋의 모든 원소들을 출력하기 
    for (const auto& elem : s) {
        std::cout << elem << " " << std::endl;
    }
}
class Todo {
    int priority;
    std::string job_desc;

    public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc) {}

    bool operator<(const Todo& t) const {
        /* 셋에서 < 를 사용하기 위해서는 반드시 위와 같은 형태로 함수를 작성해야 한다. 
        즉 const Todo 를 레퍼런스로 받는 const 함수로 말이다. 이를 지켜야 하는 이유는
        셋 내부적으로 정렬 시에 상수 반복자를 사용하기 때문이다.
        (상수 반복자는 상수 함수만을 호출할 수 있다.) */
        /* Todo < 연산자는 중요도가 다르면,
        return priority > t.priority;
        로 해서 중요도 값이 높은 일이 위로 가게 하였다. 만약 중요도가 같다면 
        return job_desc < t.job_desc; 
        로 비교해서 job_desc 가 사전상에서 먼저 오는 것이 먼저 나오게 된다. 
        
        한 가지 유의해야 할 점은 셋 내부에서 두 개의 원소가 같냐 다르냐를 판별하기 위해서 == 를 이용하지 않는다는 점이다. 
        두 원소 A 와 B 가 셋 내부에서 같다는 의미는 A.operator<(B) 와 B.operator<(A) 가 모두 false 라는 뜻이다. (예를 
        들어서 a 와 b 가 값이 같다고 하면 a < b 가 false 이고 b < a 도 false 이므로 a == b 이라 생각한다.) */
        if (priority == t.priority) {
            return job_desc < t.job_desc;
        }
        return priority > t.priority;
    }

    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
    o << "[ 중요도: " << td.priority << "] " << td.job_desc;
    return o;
}
int main() {
    std::set<Todo> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));

    print_set(todos);

    std::cout << "-------------" << std::endl;
    std::cout << "숙제를 끝냈다면!!" << std::endl;
    todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
    print_set(todos);
}


#include <iostream>
#include <set>
#include <string>

template <typename T, typename C>
void print_set(std::set<T, C>& s) {
    // 셋의 모든 원소들을 출력하기
    for (const auto& elem : s) {
        std::cout << elem << " " << std::endl;
    }
}
class Todo {
    int priority;
    std::string job_desc;

    public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc) {}

    friend struct TodoCmp;

    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};
struct TodoCmp {
    bool operator()(const Todo& t1, const Todo& t2) const {
        if (t1.priority == t2.priority) {
            return t1.job_desc < t2.job_desc;
        }
        return t1.priority > t2.priority;
    }
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
    o << "[ 중요도: " << td.priority << "] " << td.job_desc;
    return o;
}
int main() {
    std::set<Todo, TodoCmp> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));

    print_set(todos);

    std::cout << "-----------------" << std::endl;
    std::cout << "숙제를 끝냈다면!!" << std::endl;
    todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
    print_set(todos);
    /* 해당 소스코드에서 위의 코드와 달라진 점은 일단 Todo 클래스에서 operator< 가 삭제되었다는 것이다.
    하지만 셋을 사용하기 위해 반드시 Todo 객체 간의 비교를 수행해야 하기 때문에 다음과 같은 TodoCmp 클래스를 만들었다. */
}


/* 맵(map) */
/* 맵은 셋과 거의 똑같은 자료 구조이다. 다만 셋의 경우 키만 보관했지만, 
맵의 경우 키에 대응되는 값(value) 까지도 같이 보관하게 된다. */
#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
    // 맵의 모든 원소들을 출력하기
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitchar_list;     /* 맵의 경우 템플릿 인자로 2 개를 가지는데,
                                                    첫 번째는 키의 타입이고, 두 번째는 값의 타입이다. */

    // 참고로 2017 년 7 월 4 일 현재 투수 방어율 순위이다. 
    // 맵의 insert 함수는 pair 객체를 인자로 받는다. 

    pitchar_list.insert(std::pair<std::string, double>("박세웅", 2.23));    /* 맵에 원소를 넣기 위해서는 반드시 std::pair 객체를 전달해야 한다. 
    std::pair 객체는 별다른 게 아니고,
    template <class T1, class T2>
    struct std::pair {
        T1 first;
        T2 second;
    };
    로 생긴 단순히 2 개의 객체를 멤버로 가지는 객체이다. 문제는 std::pair 객체를 사용할 때 마다 
    위처럼 템플릿 인자를 초기화해야 하는데 그게 꽤나 귀찮다는 점이다. 그래서 STL 에서는 std::make_-pair 
    함수를 제공해주는데, 이 함수는 인자로 들어오는 객체를 보고 타입을 추측해서 알아서 std::pair 객체를
    만들어서 리턴해준다. 따라서 굳이 귀찮게 타입을 명시해줄 필요가 없다. 
    */
    pitchar_list.insert(std::pair<std::string, double>("해커", 2.93));

    pitchar_list.insert(std::pair<std::string, double>("피어밴드", 2.95));

    // 타입을 지정하지 않아도 간단히 std::make_pair 함수로
    // std::pair 객체를 만들 수도 있다.
    pitchar_list.insert(std::make_pair("차우찬", 3.04));
    pitchar_list.insert(std::make_pair("장원준", 3.05));
    pitchar_list.insert(std::make_pair("헥터", 3.09));

    // 혹은 insert 를 안쓰더라도 [] 로 바로
    // 원소를 추가할 수 있다. 
    pitchar_list["니퍼트"] = 3.56;
    pitchar_list["박종훈"] = 3.76;
    pitchar_list["켈리"] = 3.90;
    /* 한 가지 흥미로운 점은 맵의 경우 operator[] 를 이용해서 새로운 원소를 추가할 수도 있다는 점이다.
    (만일 해당하는 키가 맵에 없다면!!) 만일 키가 이미 존재하고 있다면 값이 대체될 것이다. */
    print_map(pitchar_list);

    std::cout << "박세웅 방어율은?? :: " << pitchar_list["박세웅"] << std::endl;
    /* 만일 맵에 저장된 값을 찾고 싶다면 간단히 [] 연산자를 활용하면 된다. [] 연산자는 인자로
    키를 받아서 이를 맵에서 찾아서 대응되는 값을 돌려준다. 
    하지만 [] 연산자를 사용할 때 주의해야 할 점이 있다.(아래의 코드 참고!!!) */
}


#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
    // kv 에는 맵의 key 와 value 가 std::pair 로 들어간다. 
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    pitcher_list["오승환"] = 3.58;
    std::cout << "류현진 방어율은?? :: " << pitcher_list["류현진"] << std::endl;

    std::cout << "---------------" << std::endl;
    print_map(pitcher_list);
    /* 위와 같이 pitcher_list 에 오승환의 방어율만 추가하였기에 류현진의 방어율을 검색하면 아무것도 나오지 않는 게 정상이다. 
    그런데,
    std::cout << "류현진 방어율은?? :: " << pitcher_list["류현진"] << std::endl;
    위처럼 류현진의 방어율을 맵에서 검색하였을 때, 0 이라는 값이 나왔다. 없는 값을 참조하였으니 오류가 발생해야 정상인데 오히려
    값을 돌려주었다. 이는 [] 연산자가, 맵에 없는 키를 참조하게 되면 자동으로 값의 디폴트 생성자를 호출해서 원소를 추가해버리기 때문이다. 
    
    double 의 디폴트 생성자의 경우 그냥 변수를 0 으로 초기화해버린다. 따라서 되도록이면 find 함수로 원소가 키가 존재하는지 먼저 확인한
    후에, 값을 참조하는 것이 좋다. 아래는 find 함수를 이용해서 안전하게 키에 대응되는 값을 찾는 방법이다. */
}



/* find 함수를 이용해서 안전하게 키에 대응되는 값을 찾는 방법 */
#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
    // kv 에는 맵의 key 와 value 가 std::pair 로 들어간다. 
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

template <typename K, typename V>
void search_and_print(std::map<K, V>& m, K key) {
    auto itr = m.find(key);
    /* find 함수는 위처럼 맵에서 해당하는 키를 찾아서 이를 가리키는 반복자를 리턴한다. 
    만약에, 키가 존재하지 않는다면 end() 를 리턴한다. */
    if (itr != m.end()) {
        std::cout << key << " --> " << itr->second << std::endl; 
    } else {
        std::cout << key << "은(는) 목록에 없습니다." << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    pitcher_list["오승환"] = 3.58;

    print_map(pitcher_list);
    std::cout << "---------------------" << std::endl;

    search_and_print(pitcher_list, std::string("오승환"));
    search_and_print(pitcher_list, std::string("류현진"));
    /* 중요한 점은, 맵 역시 셋처럼 중복된 정수를 허락하지 않는다는 점이다. 
    이미 같은 키가 원소로 들어있다면 나중에 오는 insert 는 무시된다. */
}


#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
    // kv 에는 맵의 key 와 value 가 std::pair 로 들어간다. 
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    // 맵의 insert 함수는 std::pair 객체를 인자로 받는다.
    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.93));

    print_map(pitcher_list);

    // 2.23 이 나올까 2.93 이 나올까??
    std::cout << "박세웅 방어율은?? :: " << pitcher_list["박세웅"] << std::endl;
    /* 해당 소스코드를 컴파일하면 결과는 다음과 같다.
    박세웅 2.23
    박세웅 방어율은?? :: 2.23
    와 같이 먼저 insert 된 원소가 결과로 나오게 된다. 즉, 이미 같은 키를 가지는 원소가 있다면
    그 insert 작업은 무시된다. 만약에, 원소에 대응되는 값을 바꾸고 싶다면 insert 를 하지 말고,
    [] 연산자로 대응되는 값을 바꿔주면 된다. */
}


/* 멀티셋(multiset) 과 멀티맵(multimap) */
/* 앞서 셋과 맵 모두 중복된 원소를 허락하지 않았다. 만일, 이미 원소가 존재하고 있는데 insert 를 
하였으면 무시가 되었을 것이다. 하지만 멀티셋과 멀티맵은 중복된 원소를 허락한다. */
#include <iostream>
#include <set>
#include <string>

template <typename K>
void print_set(const std::multiset<K>& s) {
    //
    for (const auto& elem : s) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::multiset<std::string> s;

    s.insert("a");
    s.insert("b");
    s.insert("a");
    s.insert("c");
    s.insert("d");
    s.insert("c");

    print_set(s);
    /* 해당 소스코드를 출력하면 결과는 다음과 같다.
    a
a
b
c
c
d
만약에 기존의 set 이었다면 그냥 a, b, c, d 이렇게 나왔어야 하지만 멀티셋의 경우 중복된 원소를 허락하기 때문에 
insert 한 모든 원소들이 쭈르륵 나오게 된다. */
}


#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
    // 맵의 모든 원소들을 출력하기
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

int main() {
    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "baba"));

    print_map(m);

    // 뭐가 나올까요?? 
    std::cout << "------------------" << std::endl;
    std::cout << m.find(1)->second << std::endl;
    /* 코드를 성공적으로 컴파일하였다면 결과는 다음과 같다.
    1 hello
1 hi
1 ahihi
2 bye
2 baba
------------------
hello
일단 맵과는 다르게, 한 개의 키에 여러 개의 값이 대응될 수 있다는 것을 알 수 있다. 
하지만 이 때문에 [] 연산자를 멀티맵의 경우 사용할 수 없다. 왜냐하면 예를 들어
m[1]
을 했을 때 "hello" 를 리턴해야할지, 아니면 "hi" 를 리턴해야 할지 알 수 없기 때문이다. 따라서 멀티맵의 경우 아예 [] 연산자를 제공하지 않는다. */
}

#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
    //
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

int main() {
    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "baba"));

    print_map(m);

    std::cout << "--------------------" << std::endl;

    // 1 을 키로 가지는 반복자의 시작과 끝을
    // std::pair 로 만들어서 리턴한다. 
    auto range = m.equal_range(1);
    for (auto itr = range.first; itr != range.second; ++itr) {
        std::cout << itr->first << " : " << itr->second << " " << std::endl;
    }
}


/* 정렬되지 않은 셋과 맵(unordered_set, unordered_-map) */
/* unordered_set 과 unordered_map(한글로 하면 너무 길어서 그냥 영문으로 표기한다.)
은 C++ 11 에 추가된 비교적 최근 나온 컨테이너들이다. 
이 두 개의 컨테이너는 이름에서도 알 수 있듯이 원소들이 정렬되어 있지 않다. 
이 말의 의미는, 셋이나 맵의 경우 원소들이 순서대로 정렬되어서 내부에 저장되지만, 
unordered_set 과 unordered_map 의 경우 원소들이 순서대로 정렬되어서 들어가지 않는다는 
뜻이다. 따라서 반복자로 원소들을 하나씩 출력해보면 거의 랜덤한 순서로 나오는 것을 알 수 있다. */
#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    // 셋의 모든 원소들을 출력하기
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::unordered_set<std::string> s;

    s.insert("hi");
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("psi");
    s.insert("welcome");
    s.insert("to");
    s.insert("c++");

    print_unordered_set(s);
    /* 해당 소스코드를 성공적으로 컴파일하면
c++
to
my
name
hi
is
psi
welcome
와 같이 나온다. 
실제로 unordered_set 의 모든 원소들을 반복자로 출력해보면 딱히 순서대로 나오는 것 같지는 않다. 
원소를 넣은 순서도 아니고, string 문자열 순서도 아니고 그냥 랜덤한 순서이다. 
그런데 이 unordered_set 에 한 가지 놀라운 점이 있다. 바로 insert, erase, find 모두가 
O(1) 으로 수행된다는 점이다. 셋이나 맵의 경우 O(logn) 이었지만, unordered_set 과 unordered_map 의 경우
상수 시간에 원소를 삽입하고 검색할 수 있다. */
}



#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    //
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
    auto itr = s.find(key);
    if (itr != s.end()) {
        std::cout << key << " 가 존재!!" << std::endl;
    } else {
        std::cout << key << " 가 없다!!" << std::endl;
    }
}
int main() {
    std::unordered_set<std::string> s;

    s.insert("hi");
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("psi");
    s.insert("welcome");
    s.insert("to");
    s.insert("c++");

    print_unordered_set(s);
    std::cout << "------------------------" << std::endl;
    is_exist(s, std::string("c++"));
    is_exist(s, std::string("c"));

    std::cout << "-----------------------" << std::endl;
    std::cout << "'hi' 를 삭제" << std::endl;
    s.erase(s.find("hi"));
    is_exist(s, std::string("hi"));
    /* 일단 위에서 볼 수 있듯이 unordered_set 과 unordered_map 모두 find 함수를 지원하며, 
    사용법은 셋과 정확히 동일하다. find 함수의 경우 만일 해당하는 원소가 존재한다면 이를 
    가리키는 반복자를, 없다면 end 를 리턴한다. 
    또한 원소를 제거하고 싶다면 간단히 find 함수로 원소를 가리키는 반복자를 찾은 뒤에, 이를
    전달하면 된다. */
}


/* 내가 만든 클래스를 unordered_set/unordered_map 의 원소로 넣고 싶을 때 */
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    // 셋의 모든 원소들을 출력하기 
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
    auto itr = s.find(key);
    if (itr != s.end()) {
        std::cout << key << " 가 존재!!" << std::endl;
    } else {
        std::cout << key << " 가 없다!!" << std::endl;
    }
}
class Todo {
    int priority;   // 중요도. 높을수록 급한 것!!!
    std::string job_desc;

    public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc) {}

    bool operator==(const Todo& t) const {
        if (priority == t.priority && job_desc == t.job_desc) return true;
        return false; 
    }

    friend std::ostream& operator<<(std::ostream& o, const Todo& t);
    friend struct std::hash<Todo>;
};

// Todo 해시 함수를 위한 함수객체(Functor)
// 를 만들어줍니다!!!
namespace std {
    template <>
    struct hash<Todo> {
        size_t operator()(const Todo& t) const {
            hash<string> hash_func;

            return t.priority ^ (hash_func(t.job_desc));
        }
    };
}   // namespace std
std::ostream& operator<<(std::ostream& o, const Todo& t) {
    o << "[중요도 : " << t.priority << " ] " << t.job_desc;
    return o;
}   

int main() {
    std::unordered_set<Todo> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));
    print_unordered_set(todos);
    std::cout << "--------------------" << std::endl;
}


/* 그렇다면 뭘 쓸까?? */
/*
1) 데이터의 존재 유무만 궁금한 경우 --> set
2) 중복 데이터를 허락할 경우 --> multiset( insert, erase, find 모두 O(log N). 최악의 경우에도 O(log N). )
3) 데이터에 대응되는 데이터를 저장하고 싶은 경우 --> map
4) 중복 키를 허락할 경우 --> multimap( insert, erase, find 모두 O(log N). 최악의 경우에도 O(log N). )
5) 속도가 매우매우 중요해서 최적화를 해야하는 경우 --> unordered_set, unordered_map ( insert, erase, find 모두 O(1). 
최악의 경우엔 O(N). 그러므로 해시함수와 상자 개수를 잘 설정해야 한다.) 
*/


/* 정렬 (sort, stable_sort, partial_sort) */
/* 첫번째로 알고리즘 라이브러리에서 지원하는 정렬(sort) 에 대해서 알아보자. 
사실 정렬이라 하면 한 가지밖에 없을 것 같은데 정렬 알고리즘에서는 무려 3 가지 
종류의 함수를 지원하고 있다. 이를 살펴보면 각각 다음과 같다. 
1) sort: 일반적인 정렬 함수와 같다. 
2) stable_sort : 정렬을 하되 원소들 간의 순서를 보존한다. 만약에 벡터에 [a, b]
순으로 있었는데, a 와 b 가 크기가 같다면 정렬을 [a, b] 혹은 [b, a] 로 할 수 있다.
sort 의 경우 그 순서가 랜덤으로 정해진다. 하지만 stable_sort 의 경우, 그 순서를 
반드시 보존한다. 즉 컨테이너 상에서 [a, b] 순으로 있었다면 정렬 시에도 (크기가 같다면)
[a, b] 순으로 나오게 된다. 이 때문에 sort 보다 좀 더 느리다. 
3) partial_sort: 배열의 일부분만 정의한다. (아래에서 자세히 설명!!!) 

그렇다면 각각의 함수들을 사용해보도록 하자!! */



#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end());
    /* sort 함수는 위와 같이 정렬할 원소의 시작 위치와 마지막 위치 바로 뒤를 반복자로 받는다. 
    sort 함수는 기본적으로 오름차순으로 정렬을 한다. 
    참고로 sort 에 들어가는 반복자의 경우 반드시 '임의접근 반복자(RandomAccessIterator) 타입'
    을 만족해야 하므로, 우리가 봐왔던 컨테이너들 중에선 벡터와 데크만 가능하고 나머지 컨테이너
    는  sort 함수를 적용할 수 없다. (예를 들어 리스트의 경우 반복자 타입이 '양방향 반복자
    (BidirectionalIterator)' 이므로 안 된다.) */

    /* 만약에 
    list<int> l;
    sort(l.begin(), l.end());
    이처럼 리스트를 정렬하려고 했다간 컴파일 오류가 발생하게 된다. */

    std::cout << "정렬 후 ----" << std::endl;
    print(vec.begin(), vec.end());
}



#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}
struct int_compare {
    bool operator()(const int& a, const int& b) const { return a > b; }
};
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 --------" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(), int_compare());   
    /* sort 는 기본적으로 오름차순 정렬이지만, 뒤에 int_compare 을 붙여서 내림차순 정렬로 만들었다!! */

    std::cout << "정렬 후 -------" << std::endl;
    print(vec.begin(), vec.end());
}


/* partial_sort 함수 사용 예시 코드 */
#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 ------" << std::endl;
    print(vec.begin(), vec.end());
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end()); /* 위와 같이 vec.begin() 부터 vec.end() 까지 (즉 벡터 전체에서) 원소들 중에서,
                                                                vec.begin() 부터 vec.begin() + 3 까지의 전체에서 가장 작은 애들만 순서대로 저장
                                                                하고 나머지 위치는 상관 없다!! 이런 식이다. 
                                                                따라서 위와 같이 
                                                                5 3 1 6 7 2 
                                                                에서 가장 작은 3 개 원소인 1, 2, 3 만이 정렬되어서 
                                                                1 2 3 6 5 7 4 
                                                                앞에 나타나게 되고 나머지 원소들은 그냥 랜덤하게 남아있게 된다. 
                                                                전체 원소의 개수가 N 개이고, 정렬하려는 부분의 크기가 M 이라면 partial_sort 의 
                                                                복잡도는 O(N logM) 가 된다. */

    std::cout << "정렬 후 -------" << std::endl;
    print(vec.begin(), vec.end());
    /* 해당 소스코드를 컴파일하면 결과는 아래와 같다. 
    정렬 전 ------
5 3 1 6 4 7 2
정렬 후 -------
1 2 3 6 5 7 4
앞서 partial_sort 함수는 일부만 정렬하는 함수라고 하였다. 
partial_-sort 는 인자를 아래와 같이 3 개를 기본으로 받는다. 
std::partial_sort(start, middle, end)
이때 정렬을 [start, end) 전체 원소들 중에서 [start, end) 까지
원소들이 전체 원소들 중에서 제일 작은애들 순으로 정렬시킨다. */

/* 만약에 우리가 전체 배열을 정렬할 필요가 없을 경우, 예를 들어서 100 명의 학생 중에서 상위 10 명의
학생의 성적순을 보고 싶다, 이런 식이면 굳이 sort 로 전체를 정렬할 필요 없이 partial_sort 로 10 개만 
정렬하는 것이 더 빠르게 된다. */
}


/* stable_sort */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
struct User {
    /* User 클래스는 name 과 age 를 멤버로 가지는데, 크기 비교는 이름과 관계없이 모두 age 로 하게 된다. 
    즉 age 가 같다면 크기가 같다고 볼 수 있다. */
    std::string name;
    int age;

    User(std::string name, int age) : name(name), age(age) {}

    bool operator<(const User& u) const { return age < u.age; }
};

std::ostream& operator<<(std::ostream& o, const User& u) {
    o << u.name << " , " << u.age;
    return o;
}

int main() {
    std::vector<User> vec;
    for (int i = 0; i < 100; i++) {
        std::string name = "";
        name.push_back('a' + i / 26);
        name.push_back('a' + i % 26);
        vec.push_back(User(name, static_cast<int>(rand() % 10)));
    }

    std::vector<User> vec2 = vec;

    std::cout << "정렬 전 ------" << std::endl;
    print(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());

    std::cout << "정렬 후 ------" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "stable_sort 의 경우 ---" << std::endl;
    std::stable_sort(vec2.begin(), vec2.end());
    print(vec2.begin(), vec2.end());
}


/* 원소 제거(remove, remove_if) */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 -----" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터에서 값이 3 인 원소 제거 ---" << std::endl;
    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    print(vec.begin(), vec.end());
    /* remove 함수는 원소의 이동만을 수행하지 실제로 원소를 삭제하는 연산을 수행하지는 않는다. 
    따라서 벡터에서 실제로 원소를 지우기 위해서는 반드시 erase 함수를 호출하여 실제로 원소를 지워줘야만 한다. 
    위처럼 remove 함수를 이용해서 값이 3 인 원소들을 뒤로 보내버리고, 그 원소들을 벡터에서 삭제해버리게 된다. 
    
    참고로 말하자면 remove 함수의 경우 반복자의 타입이 ForwardIterator 이다. 즉, 벡터 뿐만이 아니라, 리스트, 
    혹은 셋이나 맵에서도 모두 사용할 수 있다. */
}
/* 그렇다면 이번에는 값이 딱 얼마로 정해진 것이 아니라 특정한 조건을 만족하는 원소들을 제거하려면 어떻게 해야할까??
당연히도 이 원소가 그 조건을 만족하는지 아닌지를 판단할 함수를 전달해야 한다. 이를 위해서는 remove_if 함수를 사용해야 한다. */


/* remove_if 함수의 사용 예시 코드 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
struct is__odd {
    bool operator()(const int& i) { return i % 2 == 1; }
};
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 ------- " << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 제거 ------- " << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is__odd()), vec.end());
    print(vec.begin(), vec.end());
}


/* remove_if 에 조건 추가하기 */
/* remove_if 함수는 함수 객체가 인자를 딱 1 개만 받는다고 가정한다. 
따라서 호출되는 operator() 을 통해선 원소에 대한 정보 말고는 추가적인 정보를 전달하기는 어련다. 

하지만 예를 들어서 홀수인 원소들을 삭제하되 처음 2 개만 삭제한다고 해보자. 함수 객체의 경우
사실 클래스의 객체이기 때문에 멤버 변수를 생각할 수 있다. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
struct is_odd {
    int num_delete;

    is_odd() : num_delete(0) {}

    bool operator()(const int& i) {
        if (num_delete >= 2) return false;

        if (i % 2 == 1) {
            num_delete++;
            return true;
        }

        return false;
    }
};
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    std::cout << "처음 vec 상태 --------" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 앞의 2개 제거 -----" << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    print(vec.begin(), vec.end());
    /* 해당 소스코드를 성공적으로 컴파일하면 결과는 다음과 같다. 
    처음 vec 상태 --------
    [5] [3] [1] [2] [3] [4]
    벡터에서 홀수인 원소 앞의 2개 제거 -----
    [2] [3] [4]
    예상과는 사뭇 다른 결과가 나온 것을 확인할 수 있다. 홀수 원소 2 개가 아니라 3 개가 삭제되었다. 
    분명히 우리는 2 개 이상 되면 false 를 리턴하라고 명시했는데 말이다. 
    
    사실 C++ 표준에 따르면 remove_if 에 전달되는 함수 객체의 경우 이전의 호출에 의해 
    내부 상태가 달라지면 안된다. 다시 말해, 위처럼 함수 객체 안에 인스턴스 변수(num_delete) 를
    넣는 것은 원칙 상 안된다는 것이다. 
    그 이유는 remove_if 를 실제로 구현했을 때, 해당 함수 객체가 여러 번 복사될 수 있기 때문이다. 
    물론, 이는 어떻게 구현하냐에 따라서 달라진다. 예를 들어 아래의 코드를 확인해보자.(아래의 코드 참고!!!) */
}


template <class ForwardIterator, class UnaryPredicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last,
                            UnaryPredicate pred) {
    ForwardIterator result = first;
    while (first != last) {
        if (!pred(*first)) {    // <-- 함수 객체 pred 를 실행하는 부분
            *result = std::move(*first);
            ++result;
        }
        ++first;
    }
    return result;
}
/* 위 버전의 경우 인자로 전달된 함수 객체 pred 는 복사되지 않고 계속 호출된다. 따라서 사실
우리의 원래 코드가 위 remove_if 를 바탕으로 실행됐더라면 2 개만 정확히 지워질 수 있다. 
하지만 문제는 어떤 C++ 표준은 remove)if 함수를 어떤 방시긍로 구현하라고 정해놓지 않았다. 어떤
라이브러리의 경우, 아래와 같은 방식으로 구현되었다. (사실 대부분의 라이브러리들이 아래와 비슷하다.) */

template <class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt alst, UnaryPredicate pred)



#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
struct is_odd {
    int* num_delete;

    is_odd(int* num_delete) : num_delete(num_delete) {}

    bool operator() (const int& i) {
        if (*num_delete >= 2) return false;

        if (i % 2 == 1) {
            (*num_delete)++;
            return true;
        }

        return false;
    }
};
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 앞의 2 개 제거 ----" << std::endl;
    int num_delete = 0;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd(&num_delete)),
            vec.end());
    print(vec.begin(), vec.end());
    /* 해당 코드를 성공적으로 컴파일 하였다면 결과는 아래와 같이
    처음 vec 상태 ------
[5] [3] [1] [2] [3] [4]
벡터에서 홀수인 원소 앞의 2 개 제거 ----
[1] [2] [3] [4]
제대로 나온다. 
위 경우, num_delete 에 관한 정보를 아예 함수 객체 밖으로 빼서 보관해버렸다.
물론 함수 객체에 내부 상태인 num_delete 의 주소값은 변하지 않으므로 문제될 것은 없다. 

그런데 한 가지 안좋은 점은, 이렇게 STL 을 사용할 때마다 외부에 클래스나 함수를 
하나씩 만들어주어야한다는 점이다. 물론 프로젝트의 크기가 작다면 크게 문제가 되지는 않겠지만
프로젝트의 크기가 커진다면, 만약 다른사람이 코드를 읽을 때 '이 클래스는 뭐하는 거지?'
혹은 '이 함수는 뭐하는 거지??' 와 같은 궁금증이 생길 수도 있고 심지어 잘못 사용할 수도 있다.
따라서 가장 이상적인 방법은 STL 알고리즘을 사용할 때 그 안에 직접 써놓는 것이다. 마치
vec.erase(std::remove_if(vec.begin(), vec.end(),
                        bool is_odd(int i) { return i % 2 == 1; }),
            vec.end());
뭐 이런 식으로 말이다. 문제는 위 문법이 C++ 에서 허용되지 않는다는 점이다. 하지만 놀랍게도 C++11 부터
위 문제를 해결할 방법이 나타났다. */
}


/* 람다 함수(lambda function) */
/* 람다 함수는 C++ 에서는 C++ 11 에서 처음으로 도입되었다. 
람다 함수를 통해 쉽게 이름이 없는 함수 객체를 만들 수 없게 되었다. 
아래는 람다 함수를 사용한 예제 코드이다. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 제거 -----" << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                            [](int i) -> bool { return i % 2 == 1; }),  /* 람다 함수를 정의한 부분.*/
                                                                        /* 람다 함수는 위와 같은 꼴로 정의된다. 
                                                                        일반적인 꼴을 살펴보자면
                                                                        [capture list] (받는 인자) -> 리턴 타입 { 함수 본체 }
                                                                        와 같은 형태이다. 리턴 타입을 생략할 경우
                                                                        [capture list] (받는 인자) { 함수 본체 }
                                                                        이런 식으로 더 간단히 쓸 수 있다. */
            vec.end());
    print(vec.begin(), vec.end());
}


/* 캡쳐 목록(capture list) 의 활용 예제 코드!!! */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 -----" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 -----" << std::endl;
    int num_erased = 0;
    vec.erase(std::remove_if(vec.begin(), vec.end(), 
                            [&num_erased](int i) {
                                if (num_erased > 2)
                                    return false;
                                else if (i % 2 == 1) {
                                    num_erased++;
                                    return true;
                                }
                                return false;
                            }),
                            vec.end());
    print(vec.begin(), vec.end());
}



/* 원소 수정하기(transform) */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "벡터 전체에 1 을 더한다." << std::endl;
    std::transform(vec.begin(), vec.end(), vec.begin(),     /* transform 함수는 다음과 같은 꼴로 생겼다. 
                                                            우리가 사용한 예의 경우,
                                                            transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i + 1; });
                                                            로 하였으므로 vec 의 시작(begin) 부터 끝(end) 까지 각 원소에 [] (int i ) { return i + 1 } 함수를 적용시킨 결과를 vec.begin() 부터 저장하게 된다. 
                                                            즉 결과적으로 각 원소에 1 을 더한 결과로 덮어 씌우게 되는 것이다. 상당히 간단하다. 
                                                            한 가지 주의할 점은 값을 저장하는 컨테이너의 크기가 원래의 컨테이너보다 최소한 같거나 커야 된다는 점이다. */
/* 예를 들어서 단순하게
std::transform(vec.begin(), vec.end(), vec.begin() + 1,
                [](int i) { return i + 1; });
이렇게 썼다고 해보자. transform 함수는 vec 의 처음부터 끝까지 쭈르륵 순회하지만
저장하는 쪽의 반복자는 vec 의 두 번째 원소부터 저장하기 때문에 결과적으로 마지막
에 한 칸이 모자라서 오류를 발생하게 된다. */
                    [](int i) { return i + 1; });
    print(vec.begin(), vec.end());
}



#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    // vec2 에는 6 개의 0 으로 초기화한다. 
    std::vector<int> vec2(6, 0);

    std::cout << "처음 vec 과 vec2 상태 -------" << std::endl;
    print(vec.begin(), vec.end());
    print(vec2.begin(), vec2.end());

    std::cout << "vec 전체에 1 을 더한 것을 vec2 에 저장-- " << std::endl;
    std::transform(vec.begin(), vec.end(), vec2.begin(),
                    [](int i) { return i + 1; });
    print(vec.begin(), vec.end());
    print(vec2.begin(), vec2.end());
}


/* 원소를 탐색하는 함수(find, find_if, any_of, all_of 등등) */
/* 마지막으로 살펴볼 함수들은 원소들은 탐색하는 계열의 함수들이다. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto result = std::find(vec.begin(), vec.end(), 3);
    std::cout << "3 은 " << std::distance(vec.begin(), result) + 1 << " 번째 원소"
                << std::endl;
    /* find 함수는 단순히
    template <class InputIt, class T>
    InputIt find(InputIt first, InputIt last, const T& value)
    와 같이 생겼는데, first 부터 last 까지 쭈르륵 순회하면서 value
    와 같은 원소가 있는지 확인하고 있으면 이를 가리키는 반복자를 리턴한다. 
    위의 경우
    auto reault = std::find(vec.befin(), vec.end(), 3);
    vec 에서 값이 3 과 같은 원소를 찾아서 리턴하게 된다. 반복자에 따라서 
    forward_iterator 면 앞에서부터 찾고, reverse_iterator 이면 뒤에서부터
    거꾸로 찾게 된다. 물론 컨테이너에 중복되는 값이 있더라도 가장 먼저 찾은
    것을 리턴한다. 만약에 위 vec 에서 모든 3 을 찾고싶다면 아래와 같이 하면 
    된다. (아래의 코드 참고!!!) */
}


#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto current = vec.begin();
    while (true) {
        current = std::find(current, vec.end(), 3);     /* 이처럼 마지막으로 찾은 위치 바로 다음부터 계속 순차적으로
                                                        탐색해 나간다면 컨테이너에서 값이 3 인 원소들을 모두 찾을 수
                                                        있게 된다. 
                                                        다만 find 계열의 함수들을 사용할 때 한 가지 주의해야 할 점은,
                                                        만약에 컨테이너에서 기본적으로 find 함수를 지원한다면 이를 사용
                                                        하는 것이 훨씬 빠르다. 왜냐하면 알고리즘 라이브러리에서의 find
                                                        함수는 그 컨테이너가 어떠한 구조를 가지고 있는지에 대한 정보가 
                                                        하나도 없기 때문이다. 
                                                        따라서 알고리즘 라이브러리의 find 함수를 사용할 경우 벡터와 같이 
                                                        기본적으로 find 함수를 지원하지 않는 컨테이너에 사용하길 바란다!!! */
        if (current == vec.end()) break;
        std::cout << "3 은 " << std::distance(vec.begin(), current) + 1
                    << " 번째 원소" << std::endl;
        current++;
    }
}


#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
// 교재 587페이지
template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto current = vec.begin();
    while (true) {
        current =
        std::find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
        if (current == vec.end()) break;
        std::cout << "3 으로 나눈 나머지가 2 인 원소는 : " << *current << " 이다. "
                    << std::endl;
        current++;
    }
    /* find 함수가 단순한 값을 받았다면 find_if 함수의 경우 함수 객체를 인자로 받아서 그 결과가 참인 원소들을 찾게 된다.
    위 경우 3 으로 나눈 나머지가 2 인 원소들을 컨테이너에서 탐색하였다. 람다 함수로 사용하면 간결해진다. */
}


/* any_of 와 all_of */
/* 마지막으로 살펴볼 함수들은 any_of 와 all_of 이다. any_of 는 인자로 받은 범위 안의
모든 원소들 중에서 조건을 하나라도 충족하는 게 있다면 true 를 리턴하고 all_of 의 경우 
모든 원소들이 전부 조건을 충족해야 true 를 리턴한다. 즉 any_of 는 OR 연산과 비슷하고
all_of 는 AND 연산과 비슷하다고 할 수 있다. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

struct User {
    std::string name;
    int level;

    User(std::string name, int level) : name(name), level(level) {}
    bool operator==(const User& user) const {
        if (name == user.name && level == user.level) return true;
        return false;
    }
};

class Party {
    std::vector<User> users;

    public:
    bool add_user(std::string name, int level) {
        User new_user(name, level);
        if (std::find(users.begin(), users.end(), new_user) != users.end()) {
            return false;
        }
        users.push_back(new_user);
        return true;
    }

    // 파티원 모두가 15 레벨 이상이어야지 던전 입장 가능
    bool can_join_dungeon() {
        return std::all_of(users.begin(), users.end(),
                            [](User& user) { return user.level >= 15; });
    }

    // 파티원 중 한 명이라도 19 렙 이상이면 특별 아이템 사용 가능!!
    bool can_use_special_item() {
        return std::any_of(users.begin(), users.end(),
                        [](User& user) { return user.level >= 19; });
    }
};
int main() {
    Party party;
    party.add_user("철수", 15);
    party.add_user("영희", 18); 
    party.add_user("민수", 12); /* 민수의 레벨이 15 미만이므로, 던전 입장 불가능!!! */
    party.add_user("수빈", 19); /* 수빈의 레벨이 19 이상이므로, 특별 아이템 사용 가능!! */

    std::cout << std::boolalpha;
    std::cout << "던전 입장 가능?? " << party.can_join_dungeon() << std::endl;
    std::cout << "특별 아이템 사용 가능?? " << party.can_use_special_item()
                << std::endl;
}


/* 숫자들의 순위가 알파벳보다 낮은 문자열 */
#include <cctype>
#include <iostream>
#include <string>

// char_traits 의 모든 함수들은 static 함수이다.
struct my_char_traits : public std::char_traits<char> {
    /* get_real_rank 함수:  
    이 함수는 문자의 '실제 순위' 를 반환한다. 
    숫자 (0-9) 인 경우, 해당 문자의 ASCII 값에 256 을 더하여 우선순위를 낮춘다. 예를 들어,
    '0' 의 ASCII 값은 48 이므로 304 로 변환된다. 
    알파벳인 경우, 그대로 변환된다. */
    static int get_real_rank(char c) {
        // 숫자면 순위를 엄청 떨어뜨린다. 
        if (isdigit(c)) {
            return c + 256;
        }
        return c;
    }

    static bool lt(char c1, char c2) {
        /* lt 함수: 
        두 문자를 비교하여 첫 번째 문자가 두 번째 문자보다 작은지를 판단한다. 
        get_real_rank 를 호출하여 실제 순위에 따라 비교한다. */
        return get_real_rank(c1) < get_real_rank(c2);
    }

    static int compare(const char* s1, const char* s2, size_t n) {
        /* compare 함수:
        두 문자열을 n 개의 문자에 대해 비교한다. 
        각 문자를 get_real_rank 를 통해 비교하고, 첫 번째 문자열이 작으면 -1,
        크면 1 을 반환한다.
        모든 문자가 동일할 경우, 0 을 반환한다. */
        while (n-- != 0) {
            if (get_real_rank(*s1) < get_real_rank(*s2)) {
                return -1;
            }
            if (get_real_rank(*s1) > get_real_rank(*s2)) {
                return 1;
            }
            ++s1;
            ++s2;
        }
        return 0;
    }
};

int main() {
    /* main 함수:
    std::basic_string 을 사용하여 사용자 정의 문자 특성 my_char_traits 를
    적용한 문자열 my_s1 과 my_s2 를 생성한다. */
    std::basic_string<char, my_char_traits> my_s1 = "1a";
    std::basic_string<char, my_char_traits> my_s2 = "a1";

    std::cout << "숫자의 우선순위가 더 낮은 문자열: " << std::boolalpha
                << (my_s1 < my_s2) << std::endl;
                /* my_s1 < my_s2 를 통해 1a 와 a1 을 비교한다. 
                숫자의 순위가 낮기 때문에 1a 가 a1 보다 작지 않아서 false 가 출력된다. */

    std::string s1 = "1a";  /* 일반 문자열 비교 */
    std::string s2 = "a1";
    /* 일반 문자열 s1 과 s2 를 생성하여 비교한다. 
    일반적으로 '1' 은 'a' 보다 작기 때문에 true 가 출력된다. */
    std::cout << "일반 문자열: " << std::boolalpha << (s1 < s2) << std::endl;
    /* 결론:
    이 코드는 사용자 정의 문자 특성을 통해 문자열 비교의 동작을 변경하는 방법을 보여준다. 숫자의 우선순위를 알파벳보다
    낮추어 문자열 비교에서 특수한 기준을 설정할 수 있다. 결과적으로 my_s1 과 my_s2 의 비교 결과는 false 이고, 일반 문자열
    비교는 true 로 나타난다. 이를 통해 특수한 조건에 맞춘 문자열 비교를 할 수 있다. */

    /* basic_string 의 Traits 에는 char_traits 에서 제공하는 모든 멤버 함수들이 구현된 클래스가 전달되어야한다. 
    (꼭 char_traits 를 상속받을 필요는 없다!!) 이를 가장 간편히 만들기 위해서는 그냥 char_traits 를 상속받은 후,
    필요한 부분만 새로 구현하면 된다. */
}


/* 짧은 문자열 최적화(SSO) */
/* basic_string 의 제작자들은 짧은 길이 문자열의 경우, 따로 문자 데이터를 위한
메모리를 할당하는 대신에 그냥 객체 자체에 저장해버린다. (길이가 짧은 문자열을 
여러 번 할당한다면 매번 메모리 할당이 이루어져야 함-> 굉장히 비효율적!!) 
이를 짧은 문자열 최적화(SSO - short string optimization) 이라고 부른다. */
#include <iostream>
#include <string>

// 이와 같이 new 를 정의하면 모든 new 연산자를 오버로딩 해버린다. 
// (어떤 클래스의 멤버 함수로 정의하면 해당 클래스의 new 만 오버로딩된다.)
void* operator new(std::size_t count) {
    std::cout << count << " bytes 할당 " << std::endl;
    return malloc(count);
}

int main() {
    std::cout << "s1 생성 --- " << std::endl;
    std::string s1 = "this is a pretty long sentence!!!";
    std::cout << "s1 크기: " << sizeof(s1) << std::endl;

    std::cout << "s2 생성 --- " << std::endl;
    std::string s2 = "short sentence";
    std::cout << "s2 크기: " << sizeof(s2) << std::endl;
}


/* 문자열 리터럴 정의하기 */
#include <iostream>
#include <string>

using namespace std::literals;

int main() {
    auto s1 = "hello"s;
    std::cout << "s1 길이 : " << s1.size() << std::endl;
    /* 성공적으로 컴파일하면 아래와 같은 결과가 나온다. 
    s1 길이 : 5
    와 같이 제대로 string 으로 auto 가 추론된 것을 확인할 수 있다. */
}


/* C++ 한글 다루기 */
#include <iostream>
#include <string>

int main() {
    //
    std::u32string u32_str = U"이건 UTF-32 문자열입니다.";
    std::cout << u32_str.size() << std::endl;
}


#include <iostream>
#include <string>

int main() {
    std::u16string u16_str = u"안녕하세용 모두의 코드에 온 것을 환영합니다";
    std::string jaum[]  = {"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ",
                        "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ",
                        "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"};
/* 초성을 나타내는 문자열 배열 jaum 을 선언한다. 배열의 인덱스는 각 초성과 매칭된다. */

    for (char16_t c: u16_str) {
        // 유니코드 상에서 한글 범위
        if (!(0xAC00 <= c && c <= 0xD743)) {
            continue;
        }
        // 한글은 AC00 부터 시작해서 한 초성당 총 0x24C 개씩 있다. 
        int offset = c - 0xAC00;
        /* offset 은 현재 문자 c 에서 한글 시작점인 0xAC00 을 빼서 해당 문자의 인덱스를 계산한다. 
        한글 음절은 초성, 종성, 종성으로 구성되며, 한 초성에 해당하는 음절 수는 0x24C (즉 588)이다.
        jau_offset 은 초성을 결정하는 인덱스이다. offset 을 0x24C 로 나누어 초성의 인덱스를 구한다. */
        int jaum_offset = offset / 0x24C;
        std::cout << jaum[jaum_offset]; 
        /* 계산된 jaum_offset 을 사용하여 초성 배열에서 해당 초성을 찾아 출력한다. */
    }
}

#include <iostream>
#include <string>

void* operator new(std::size_t count) {
    std::cout << count << " bytes 할당" << std::endl;
    return malloc(count);
}

// 문자열에 "very" 라는 단어가 있으면 true 를 리턴한다.
bool contains_very(const std::string& str) {
    return str.find("very") != std::string::npos;
}

int main() {
    // 암묵적으로 std::string 객체가 불필요하게 생성된다. 
    std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
                << std::endl;
    std::cout << contains_very("c++ string is not easy to use") << std::endl;
}


#include <iostream>
#include <string>

void* operator new(std::size_t count) {
    std::cout << count << " bytes 할당" << std::endl;
    return malloc(count);
}

// 문자열에 "very" 라는 단어가 있으면 true 를 리턴함.
bool contains_very(std::string_view str) {
    return str.find("very") != std::string_view::npos;
}

int main() {
    // string_view 생성 시에는 메모리 할당이 필요 없다.
    std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
                << std::endl;
    std::cout << contains_very("c++ string is not easy to use") << std::endl;

    std::string str = "some long long long long long string";
    std::cout << "-------------------" << std::endl;
    std::cout << contains_very(str) << std::endl;
    /* 아 전혀 모르겠다....ㅅㅂ */
}


#include <iostream>
#include <string>

void* operator new(std::size_t count) {
    std::cout << count << " bytes 할당" << std::endl;
    return malloc(count);
}

int main() {
    std::cout << "string --------" << std::endl;
    std::string s = "sometimes string is very slow";
    std::cout << "--------------------" << std::endl;
    std::cout << s.substr(0, 20) << std::endl << std::endl;

    std::cout << "string_view -------" << std::endl;
    std::string_view sv = s;
    std::cout << "---------------------" << std::endl;
    std::cout << sv.substr(0, 20) << std::endl;
}


#include <iostream>
#include <string>
/* 교재 610 페이지 */
/* 대박이다 이거도 컴파일이 안돼............개짜증나네 무슨 문제지 
코드 자체에 틀린 점은 없는데 뭐가 문제지 */

std::string_view return_sv() {
    std::string s = "this is a string";
    std::string_view sv = s;

    return sv;
}

int main() {
    std::string_view sv = return_sv();  // <- sv 가 가리키는 s 는 이미 소멸됨!!!

    // Undefined behavior!!
    std::cout << sv << std::endl;
}

/* 보다시피, string 의 substr 은 문자열을 새로 생성하였기에 메모리 할당이 발생하였다. */


#include <iostream>
#include <string>

std::string_view return_sv() {
    std::string s = "this is a string";
    std::string_view sv = s;

    return sv;
}

int main() {
    std::string_view sv = return_sv();  // <- sv 가 가리키는 s 는 이미 소멸됨!!

    // Undefined behavior!!!
    std::cout << sv << std::endl;
    /* 해당 코드를 정상적으로 출력하면 결과가 이상하게 나온다. 
    위의 sv 는 return_sv 안에서 만들어진 s 의 string_view 이지만 함수가 리턴하면서
    지역 객체였던 s 가 소멸하였기 때문에 sv 는 소멸된 문자열을 가리키는 꼴이 되었다. 
    
    따라서 sv 를 사용하면 위와 같이 이상한 결과가 나온다. (물론 프로그램을 crash 시킬
    수도 있을것이다.) 반드시 string_view 가 살아 있는 문자열의 view 인지를 확인하고 
    사용해야 한다. */
}


/* C++ 에서의 예외 처리 */
/* 예외(Exception): 정상적인 상황에서 벗어난 모든 예외적인 상황들. */

/* 기존의 예외 형식 */
/* C 언어에서는 언어 차원에서 제공하는 예외 처리 방식이라는 것이 딱히 따로 존재하지 않았따.
따라서 아래와 같이, 어떤 작업을 실행한 뒤에 그 결과값을 확인하는 방식으로 처리하였다. 예를
들어서 아래 malloc 으로 메모리를 동적으로 할당하는 경우를 생각해보자. */
char *c = (char *)malloc(1000000000);
if (c == NULL) {
    printf("메모리 할당 오류!!!");
    return;
}


/* 예외 발생시키기 - throw */
class Vector {
    public:
    Vector(size_t size) : size_(size) {
        data_ = new T[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = 3;
        }
    }
    const T& at(size_t index) const {
        if (index >= size_) {
            throw out_of_rnage("vector 의 index 가 범위를 초과하였습니다.");
        }
        return data_[index];
    }
    ~Vector() { delete[] data_; }

    private:
    T* data_;
    size_t size;
};


/* 예외 처리하기 - try 와 catch */
/* 그렇다면 이렇게 발생한 예외를 어떻게 처리할까요?? */
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
    public:
    Vector(size_t size) : size_(size) {
        data_ = new T[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = 3;
        }
    }
    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
        }
        return data_[index];
    }
    ~Vector() { delete[] data_; }

    private:
    T* data_;
    size_t size_;
};
int main() {
    Vector<int> vec(3);

    int index, data = 0;
    std::cin >> index;

    try {
        data = vec.at(index);
    } catch (std::out_of_range& e) {
        std::cout << "예외 발생!! " << e.what() << std::endl;
    }
    // 예외가 발생하지 않았다면 3 을 출력되고, 예외가 발생하였다면 
    // 원래 data 에 들어가 있던 0 이 출력된다. 
    std::cout << "읽은 데이터 : " << data << std::endl;
}


/* 스택 풀기(stack unwinding) */
/* 앞서 throw 를 하게 된다면, 가장 가까운 catch 로 점프한다고 하였다. 
이 말의 뜻이 무엇인지 아래 예제로 살펴본다. */
/* 스택 풀기 : 예외가 발생했을 때 함수 호출 스택을 역순으로 되돌아가면서 함수 내에서
생성된 자원(Resource) 이 올바르게 해제되는 과정을 말한다. */
#include <iostream>
#include <stdexcept>

class Resource {
    /* Resource 클래스
    -리소스의 ID 를 받아서 저장하는 생성자와, 소멸될 때 ID 를 출력하는 소멸자를 가지고 있다.
    -소멸자에서 출력하는 메시지를 통해, 객체가 해제될 때의 타이밍을 알 수 있다. */
    public:
    Resource(int id) : id_(id) {}   // 리소스의 ID 를 받아서 저장하는 생성자
    ~Resource() { std::cout << "리소스 해제 : " << id_ << std::endl; }  // 소멸될 때 ID 를 출력하는 소멸자

    private:
    int id_;
};

int func3() {
    /* Resource r(3) 을 통해 ID 가 3 인 리소스 객체를 생성한다. */
    Resource r(3);
    throw std::runtime_error("Exception from 3!\n");    // 예외를 던지는 코드
    /* 이 함수는 예외를 발생시키며, 예외가 발생하면 이후 코드는 실행되지 않는다. 
       예외가 발생하면 func3 을 호출한 함수로 제어가 넘어가고, 이때 리소스가 해제된다. (스택 풀기 과정의 시작) */
}
int func2() {
    /* Resource r(2) 을 통해서 ID 가 2 인 리소스 객체를 생성한다. 
       func3 을 호출한다. func3 에서 예외가 발생하면 func2 로 예외가 전달된다. 
       func2 의 이후 코드(std::cout << "실행 안됨!!" << std::endl;) 는 실행되지 않으며, 
       예외가 발생하는 순간 객체 r(2) 는 해제된다. */
    Resource r(2);
    func3();
    std::cout << "실행 안됨!!" << std::endl;
    return 0;
}
int func1() {
    /* Resource r(1) 을 통해 ID 가 1 인 리소스 객체를 생성한다. 
       func2 를 호출한다. func2 에서 예외가 발생하면 func1 으로 예외가 전달된다. 
       마찬가지로 이후 코드는 실행되지 않으며, 예외가 발생하는 순간 r(1) 도 해제된다. */
    Resource r(1);
    func2();
    std::cout << "실행 안됨!!" << std::endl;
    return 0;
}

int main() {
    /* main 함수는 func1 을 try 블록 안에서 호출한다. 
    func1 에서 발생한 예외는 main 의 catch 블록으로 전달되어 예외 메시지를 출력하게 된다. */
    try {
        func1();
    } catch (std::exception& e) {
        std::cout << "Exception : " << e.what();
        /* e.what() 은 예외 객체에 포함된 예외 메시지를 반환하는 함수이다. 
        이 함수는 std::exception 클래스로부터 상속받은 멤버 함수로, 예외가 
        발생했을 때 그 예외에 대한 정보를 문자열로 제공하는 역할을 한다. 
        이 함수는 예외 처리 시 예외가 발생한 원인을 파악하고나, 로그를 남길 때 유용하게 사용된다. */
        /* 위 코드에서 std::runtime_error 객체가 생성되면서 예외 메시지 "Exception from 3!\n;"  이 전달된다. 
        나중에 catch 블록에서 e.what() 을 호출하면 이 메시지가 반환되어 출력된다. */
    }
}


/* (위의 코드와는 달리) 예외가 발생하지 않았을 경우!! */
#include <iostream>
#include <stdexcept>

class Resource {
    public:
    Resource(int id) : id_(id) {}
    ~Resource() { std::cout << "리소스 해제 : " << id_ << std::endl; }

    private:
    int id_;
};

int func3() {
    Resource r(3);
    return 0;
}
int func2() {
    Resource r(2);
    func3();
    std::cout << "실행!!" <<  std::endl;
    return 0;
}
int func1() {
    Resource r(1);
    func2();
    std::cout << "실행!!" << std::endl;
    return 0;
}

int main() {
    try {
        func1();
    } catch (std::exception& e) {
        std::cout << "Exception : " << e.what();
    }
    /* 위의 코드와 비교해보면, 정상적인 상황에서는 객체의 소멸자들은 함수가 종료될 때 호출되므로 
    "실행!!" 이 먼저 출력되고, 그 뒤에 리소스 해제 되었다는 문장이 출력된다. 
    반면에 예외가 전파되는 과정에서는 바로 catch 부분으로 점프하면서, 각 함수들에 있던 객체들만 
    해제하기 때문에 리소스 해제되었다는 것은 정상적으로 출력되지만, 그 "실행 안됨!!" 부분은 실행
    되지 않는다. 
    이와 같이 catch 로 점프하면서 스택 상에서 정의된 객체들을 소멸시키는 과정을 '스택 풀기(stack unwinding)'
    이라고 부른다. */

    /* 주의 사항: 예외를 생성자에서 던질 때 주의해야 할 점이 하나 있다. 바로 '생성자에서 예외가 발생 시에
    소멸자가 호출되지 않는다.' 라는 점이다. 따라서 만일 예외를 던지기 이전에 획득한 자원이 있다면 catch 에서 
    잘 해제시켜 줘야만 한다. */
}



/* 여러 종류의 예외 받기 */
#include <iostream>
#include <string>

int func(int c) {
    if (c == 1) {
        throw 10;
    } else if (c == 2) {
        throw std::string("hi!!");
    } else if (c == 3) {
        throw 'a';
    } else if (c == 4) {
        throw "hello!!";
    }
    return 0;
}

int main() {
    int c;
    std::cin >> c;

    try {
        func(c);
    } catch (char x) {  /* 첫번째 catch 문: char 형 값을 받는다. */
        std::cout << "Char : " << x << std::endl;   
    } catch (int x) {   /* 두번째 catch 문: int 형 값을 받는다. */
        std::cout << "Int : " << x << std::endl;
    } catch (std::string& s) {  /* 세번째 catch 문: string 객체를 받는다. */
        std::cout << "String : " << s << std::endl;
    } catch (const char* s) {   /* 네번째 catch 문: const char* 형 값을 받는다. */
        std::cout << "String Literal : " << s << std::endl;
        /* 각기 다른 값들을 throw 하였을 때, 작동하는 catch 가 달라지는 것을 확인할 수 있다. */
    } 
}



/* 기반 클래스와 파생 클래스인 경우, 처리하는 방식의 차이 */
#include <iostream>
#include <exception>

class Parent : public std::exception {
    /* Parent 클래스
    std::exceptoin 을 상속받은 예외 클래스이다. 
    what() 함수를 오버라이드하여 "Parent!!\n" 이라는 문자열을 반환하도록 정의되어있다. 
    what() 함수는 예외가 발생했을 때 예외에 대한 정보를 문자열로 제공하는 표준 C++ 함수이다. */
    public:
    virtual const char* what() const noexcept override { return "Parent!!\n"; }
};

class Child : public Parent {
    public:
    const char* what() const noexcept override { return "Child!!\n"; }
    /* Child 클래스
    Parent 클래스를 상속받은 파생 클래스이다. 
    what() 함수를 다시 오버라이드하여 "Child!!\n" 라는 문자열을 반환하도록 정의되어 있다. 
    Parent 와 달리, 이 클래스는 Child 예외를 처리하기 위해 정의되었다. */
};
/* Parent 와 Child 두 클래스가 정의되어 있으며, 두 클래스는 각각 예외로 던져질 수 있고
해당 예외는 catch 블록에서 처리된다. 이 코드에서는 파생 클래스가 기반 클래스의 예외를 
상속받고, 각각의 예외가 다른 방식으로 처리되는 모습을 확인할 수 있다. */

int func(int c) {
    /* func 함수
    -매개변수 int c 에 따라 다른 예외를 던지는 함수이다. 
    -c == 1 일 때 Parent 객체를 던지고, c == 2 일 때 Child 객체를 던진다. 
    이 외의 경우에는 예외를 던지지 않고 정상적으로 종료된다. */
    if (c == 1) {
        throw Parent();
    } else if (c == 2) {
        throw Child();
    }
    return 0;
}

int main() {
    /* main 함수
    -사용자로부터 입력받은 값을 통해 func 함수를 호출한다. 
    -던져진 예외가 Parent 또는 Child 객체인지에 따라 해당 예외를 처리할 catch 블록이 실행된다. */
    int c;
    std::cin >> c;

    try {
        func(c);
    } catch (Parent& p) { // 해당 줄은 Parent 타입의 예외를 잡기 위해서 사용된다. 
    /* 만약 Parent 또는 이를 상속하는 예외가 발생하면, 이 catch 블록에서 처리한다. 
    즉, Child 타입 예외도 이 블록에서 잡힐 수 있다. --> 이는 C++ 의 다형성 때문에 발생하는 문제로,
    Parent& 는 Child 타입의 예외도 참조할 수 있기 때문에 발생한다. 
    여기서는 p.what() 을 호출하여 "Parent!!\n" 또는 "Child!!\n" 을 출력한다. */
        std::cout << "Parent Catch!!" << std::endl;
        std::cout << p.what();
    } catch (Child& c) {
        /* Child 타입의 예외를 명시적으로 잡기 위해서 사용된다. 
        Child 예외가 발생했을 때만 이 catch 블록이 실행된다. 
        c.what() 을 호출하여 "Child!!\n" 을 출력한다. */
        std::cout << "Child Catch!!" << std::endl;
        std::cout << c.what();
    }
    /* 해당 소스코드를 출력하면 결과는 다음과 같다. 
    우선 1 을 입력한 경우의 결과는 아래와 같다. 
    1
    Parent Catch!!
    Parent!!
    그 다음, 2 를 입력한 경우의 결과는 아래와 같다. 
    2
    Parent Catch!!
    Child!!
    이 결과에서 1 을 입력하든 2 를 입력하든 Parent Catch!! 가 나온다는 점이 해당 코드의 문제점이다. 

    이와 같은 일이 발생하는 이유는 catch 문의 경우 가장 먼저 대입될 수 있는 객체를 받는데, 
    Parent& p = Child();
    가 가능하기 때문에 Parent Catch 가 Child Catch 보다 먼저 받아버리는 것이다. 
    따라서, 위와 같은 문제를 방지하게 위해서는 언제나 Parent Catch 를 Child Catch 보다 뒤에 써주는 것이 좋다. 
    왜냐하면 이를 통해서 Child 객체가 Parent Catch 에 들어가는 것을 막을 수 있고,
    Child &c = Parent(); // 오류
    위는 성립되지 않기 때문에 Child Catch 에 Parent 객체가 들어가지도 않기 때문이다. 
    */
}



/* 실제로 예를 보면, */
#include <iostream>
#include <exception>

class Parent : public std::exception {
    public:
    // what 은 std::exception 에 정의된 함수로, 이 예외가 무엇인지 설명하는 문자열을 
    // 리턴하는 함수이다. 
    virtual const char* what() const noexcept override { return "Parent!!\n"; }
};

class Child : public Parent {
    public:
    const char* what() const noexcept override { return "Child!!\n"; }
};

int func(int c) {
    if (c == 1) {
        throw Parent();
    } else if ( c == 2) {
        throw Child();
    }
    return 0;
}

int main() {
    int c;
    std::cin >> c;

    try {
        func(c);
    } catch (Child& c) {
        std::cout << "Child Catch!!" << std::endl;
        std::cout << c.what();
    } catch (Parent& p) {
        std::cout << "Parent Catch!!" << std::endl;
        std::cout << p.what();
    }
    /* 바로 위의 코드와는 다르게, "Child Catch!!" 를 "Parent Catch" 보다 앞에 써줬더니
    의도한대로 결과가 출력되었다!!! */

    /* 주의 사항: 일반적으로 예외 객체는 std::exception 을 상속받는 것이 좋다. 
    왜냐하면 표준 라이브러리의 유용한 함수들(nested_exception 등) 을 사용할 수 있기 때문이다. */
}


/* 예외 받기 */
#include <iostream>
#include <stdexcept>

int func() { throw std::runtime_error("error"); }

int main() {
    try {
        func();
    } catch (int i) {
        std::cout << "Catch int : " << i;
    }
    /* 해당 코드를 성공적으로 컴파일하면 runtime_error 예외를 발생시키며 프로그램이 비정상적으로 종료되었다고 뜨게 된다. 
    따라서, 언제나 예외를 던지는 코드가 있다면 적절하게 받아내는 것이 중요하다. 하지만, 때로는 예외 객체 하나 하나 처리할 
    필요 없이 "그냥 나머지 전부 다!!" 라고 쓰고 싶을 때가 있다. 마치 switch 문의 default 나 if_else 문에서 마지막 else 와 
    같이 말이다. 
    재미있게도, try .. catch 문에서도 이를 잘 지원해준다. */
}


#include <iostream>
#include <stdexcept>

int func(int c) {
    if (c == 1) {
        throw 1;
    } else if (c == 2) {
        throw "hi";
    } else if (c == 3) {
        throw std::runtime_error("error");
    }
    return 0;
}

int main() {
    int c;
    std::cin >> c;
    try {
        func(c);
    } catch (int e) {
        std::cout << "Catch int : " << e << std::endl;
    } catch (...) {
        /* 마지막 catch(...) 에서 try 안에서 발생한 모든 예외들을 받게 된다. 
        당연히도, 어떠한 예외도 다 받을 수 있기 때문에 특정한 타입을 찝어서 객체에 대입시킬 수는 없을 것이다. */

        /* 주의 사항: 템플릿으로 정의되는 클래스의 경우 어떠한 방식으로 템플릿이 인스턴스화 되냐에 따라서 던지는 에외의 
        종류가 달라질 수 있다. 이 때문에 해당 객체의 catch 에서는 모든 예외 객체를 고려해야 한다. */
        std::cout << "Default Catch!!" << std::endl;
    }
}


/* 예외를 발생시키지 않는 함수-noexcept */
/* 만약에 어떤 함수가 예외를 발생시키지 않는다면 noexcept 를 통해 명시할 수 있다. */
int foo() noexcept {}
/* foo 함수의 경우, 예외를 발생시키지 않으므로 위와 같이 함수 정의 옆에 noexcept 를
넣음으로써 나타낼 수 있다. 참고로, 함수에 noexcept 키워드를 붙였다고 해서, 함수가 예외를
절대로 던지지 않는다는 것은 아니다. 실제로 */
#include <iostream>
int foo() noexcept {}
int bar(int x) noexcept { throw 1; }
int main() { foo(); }


/* 이라고 해도 (경고는 뜨지만) 문제 없이 컴파일 한다. 즉 컴파일러는 noexcept 키워드가 붙은 함수가
'이 친구는 예외를 발생시키지 않는구나' 라고 곧이곧대로 믿고, 그대로 컴파일하게 된다. 
대신 noexcept 로 명시된 함수가 예외를 발생시키게 된다면 예외가 제대로 처리되지 않고 프로그램이 종료된다. 
예를 들어서 */
#include <iostream>
/* noexcept 는 함수가 예외를 발생시키지 않겠다는 약속을 컴파일러에 전달하는 기능이다. 
그러나 noexcept 로 선언된 함수에서 예외가 발생하면 프로그램이 정상적으로 예외를 처리하지
못하고 종료된다. 이 코드에서는 그러한 상황을 시뮬레이션하여 보여준다. */
int foo() noexcept {}       
/* foo 함수는 아무 일도 하지 않으며, 예외를 던지지 않기 때문에 프로그램이 정상적으로 실행된다. */
int bar() noexcept { throw 1; }
/* 이 예제에서 foo() 와 bar() 함수는 모두 noexcept 로 선언되어 있지만, bar() 는 예외를 가지고 있다.(문제점의 원인)
이 예제에서는 throw 1; 로 정수형 예외를 던지고 있다. */
int main() {
    foo();
    /* foo() 를 호출하지만 이 함수는 아무것도 하지 않으므로 정상적으로 실행된다. */
    try {
        bar();
        /* bar() 함수가 호출되면 throw 1 로 예외가 발생하지만, 이 함수는 noexcept 로 선언되어 있어서 
        예외 발생 시 프로그램이 비정상적으로 종료될 가능성이 있다. */
    } catch (int x) {
        /* 예외 처리(try-catch 블록) 를 사용하고 있지만, noexcept 함수에서 발생한 예외는 제대로 처리되지 않고
        프로그램이 종료된다. */
        std::cout << "Error : " << x << std::endl; 

        /* 이 코드를 실행하면 foo() 는 아무 문제 없이 호출되고 넘어가지만, bar() 에서 예외가 발생하면서 프로그램이 종료된다.
        catch 블록에서 예외를 잡으려고 시도하지만, noexcept 가 적용된 함수(여기서는 bar() 함수)에서 예외가 발생하면 예외를 
        정상적으로 처리할 수 없다. C++ 표준에 따르면, noexcept 로 선언된 함수에서 예외가 발생하면 프로그램은 종료된다. */
    }
    /* 주의 사항: C++ 11 에서부터 소멸자들은 기본적으로 noexcept 이다. 
        절대로 소멸자에서 예외를 던지면 안 된다!!! */
}


/* 생각해보기-문제 */
/* 문제 1:
C++ 표준 라이브러리에 자주 사용할 만한 예외 객체들이 정의가 되어 있다. --> 교재 629 페이지 참고!!!(링크 있음) */



/* 우측값과 이동 연산 */
/* 우측값 레퍼런스와 이동 생성자 */

/* 복사 생성자(Copy Elision) */
#include <iostream>

class A {
    /* A 클래스에는 일반 생성자와 복사 생성자가 정의되어 있으며, 
    각각 호출될 떄 메시지를 출력한다. */
    int data_;

    public:
    A(int data) : data_(data) { std::cout << "일반 생성자 호출!!" << std::endl; }   // 일반 생성자 정의
    /* 객체가 생성될 때, 정수형 매개변수를 받아 data_ 멤버 변수를 초기화한다. 
       일 반 생성자가 호출될 때, "일반 생성자 호출!!" 이라는 메시지가 출력된다. */

    A(const A& a) : data_(a.data_) {    // 복사 생성자 정의
    /* 객체가 다른 객체로부터 복사될 때 호출된다. 
       매개변수로 받은 객체의 data_ 값을 복사하여 초기화한다. 
       복사 생성자가 호출될 때 "복사 생성자 호출!!" 이라는 메시지가 출력된다. */
        std::cout << "복사 생성자 호출!!" << std::endl;
    }
};

int main() {
    A a(1); // 일반 생성자 호출
    /* 이 구문에서는 일반 생성자가 호출된다. 
    a 라는 객체가 생성되고, data_ 멤버 변수는 1 로 초기화된다. */

    A b(a); // 복사 생성자 호출
    /* 여기서는 기존 객체 a 를 사용하여 복사 생성자가 호출된다. 
    b 라는 객체가 a 의 데이터를 복사하여 생성된다. */


    // 그렇다면 이것은?? 
    A c(A(2));  // 핵심 부분!!!(매우 중요)
    /* 여기서는 임시 객체 A(2) 가 생성되고 그 객체를 통해 c 라는 새로운 객체를 생성한다. 
    이 과정에서는 복사 생성자가 호출되는 것처럼 보일 수 있지만, 실제로는 C++ 컴파일러의 
    최적화 기법인 "복사 생성 제거(Copy Elision)" 가 발생할 수 있다. 
    
    따라서 세 번째 출력인 "일반 생성자 호출!!" 은 A c(A(2)); 에서 복사 생성 제거로 인해
    임시 객체의 복사 과정 없이 일반 생성자가 호출된 결과이다. */
}


/* 이전의 MyString 클래스 */
#include <iostream>
#include <cstring>

class MyString {
    char *string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    int memory_capacity;    // 현재 할당된 용량

    public:
    MyString();

    // 문자열로부터 생성
    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString &str);

    void reserve(int size);
    MyString operator+(const MyString &s);
    ~MyString();

    int length() const;

    void print();
    void println();
};

MyString::MyString() {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;   /* nullptr 는 C++11 에 새로 추가된 키워드로, 기존의 NULL 을 대체한다. 
                                C 언어에서의 NULL 은 단순히 #define 으로 정의되어 있는 상수값 0 인데,
                                이 때문에 NULL 이 값 0 을 의미하는 것인지, 아니면 포인터 주소값 0 을 
                                의미하는 것인지 구분할 수가 없었다. 
                                하지만 nullptr 로 '포인터 주소값 0' 을 정확히 명시해 준다면, 미연에 발생할
                                실수를 줄여줄 수 있게 된다. */
}

MyString::MyString(const char *str) {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) 
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        if (prev_string_content != nullptr) delete[] prev_string_content;
    }
}
MyString MyString::operator+(const MyString &s) {
    /* 위 함수가 str1 + str2 를 실행 시에 호출되는데, 먼저 빈 MyString 객체인 str 을 생성한다. (생성자 호출!! 이 출력됨)
    그 후에, reserve 함수를 이용해서 공간을 할당하고, str1 과 str2 를 더한 문자열을 복사하게 된다. 
    
    이렇게 리턴된 str 은 str3 을 생성하는데 전달되어서, str3 의 복사 생성자가 호출된다. */
    MyString str;
    str.reserve(string_length + s.string_length);
    for (int i = 0; i < string_length; i++)
        str.string_content[i] = string_content[i];
    for (int i = 0; i < s.string_length; i++)
        str.string_content[string_length + i] = s.string_content[i];
    str.string_length = string_length + s.string_length;
    return str;
}
int MyString::length() const { return string_length; }
void MyString::print() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];

    std::cout << std::endl;
}

int main() {
    MyString str1("abc");
    MyString str2("def");
    std::cout << "----------------" << std::endl;
    MyString str3 = str1 + str2;
    str3.println();
}


/* 좌측값(lvalue) 와 우측값(rvalue) */
int a = 3;
/* 우리는 a 가 메모리 상에서 존재하는 변수임을 알고 있다. 즉, a 의 주소값을 & 연산자를 통해 알아낼 수 있다는 것이다. 
보통 이렇게 주소값을 취할 수 있는 값(위의 식에서는 a)을 좌측값(lvalue) 라고 부른다. 그리고 좌측값은 어떠한 표현식의 
왼쪽과 오른쪽 모두에 올 수 있다. 꼭 왼쪽에만 와야 좌측값인 것은 아니다!!!! */

/* 반면에 오른쪽에 있는 '3' 을 살펴보도록 하자. 우리가 '3' 의 주소값을 취할 수 있을까?? 아니다. 
'3' 은 왼쪽의 'a' 와는 달리, 위 표현식을 연산할 때만 잠깐 존재할 뿐 위 식이 연산되고 나면 사라지는 값이다. 
즉, '3' 은 실체가 없는 값이다. 
이와 같이 주소값을 취할 수 없는 값을 우측값(rvalue) 라고 부른다. 이름에도 알 수 있듯이, 우측값은 항상 식의 오른쪽에만
와야 한다. 좌측값이 식의 왼쪽과 오른쪽 모두 올 수 있는 반면, 우측값은 식의 오른쪽에만 존재해야 한다. */
int a;  // a 는 좌측값
int& l_a = a;   // l_a 는 좌측값 레퍼런스
int& r_b = 3;   // 3 은 우측값--> 따라서 오류!!
/* 여태까지 우리가 다루어왔던 레퍼런스는 '좌측값' 에만 레퍼런스를 가질 수 있었다. 예를 들어서, a 의 경우 좌측값이므로 
a 의 좌측값 레퍼런스인 l_a 를 만들 수 있다. 
반면에 3 의 경우 우측값이기 때문에, 우측값의 레퍼런스인 r_b 를 만들 수 없다. 따라서 이 문장은 오류가 발생하게 된다. 
이와 같이 & 하나를 이용해서 정의하는 레퍼런스를 '좌측값 레퍼런스(lvalue reference)' 라고 부르고, 좌측값 레퍼런스 자체도 좌측값이 된다. */


int& func1(int& a) { return a; }
int func2(int b) { return b; }

int main() {
    int a = 3;
    func1(a) = 4;
    std::cout << &func1(a) << std::endl;

    int b = 2;
    a = func2(b);   // 가능
    func2(b) = 5;   // 오류1 !!!! --> 우측값이 왼쪽에 왔기 때문
    std::cout << &func2(b) << std::endl;    // 오류2 !!!! --> 마찬가지로, 우측값의 주소값을 취할 수 없기 때문에 해당 문장이 허용되지 않음!!
    /* 해당 코드를 컴파일하면 컴파일 오류가 발생한다. */
}


/* 우측값 레퍼런스 */
#include <iostream>
#include <cstring>

class MyString {
    char *string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    int memory_capacity;    // 현재 할당된 용량

    public:
    MyString();

    // 문자열로부터 생성
    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString &str);

    // 이동 생성자
    MyString(MyString &&str);

    void reserve(int size);
    MyString operator+(const MyString &s);
    ~MyString();

    int length() const;

    void print();
    void println(); 
};

MyString::MyString() {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = 0; 
    memory_capacity = 0;
    string_content = nullptr;
}

MyString::MyString(const char *str) {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) 
        string_content[i] = str.string_content[i];
}
MyString::MyString(MyString &&str) {
    std::cout << "이동 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // 임시 객체 소멸 시에 메모리를 해제하지 
    // 못하게 한다. 
    str.string_content = nullptr;
}
MyString::~MyString() {
    if (string_content) delete[] string_content;
}
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        if (prev_string_content != nullptr) delete[] prev_string_content;
    }
}
MyString MyString::operator+(const MyString &s) {
    MyString str;
    str.reserve(string_length + s.string_length);
    for (int i = 0; i < string_length; i++)
        str.string_content[i] = string_content[i];
    for (int i = 0; i < s.string_length; i++)
        str.string_content[string_length + i] = s.string_content[i];
    str.string_length = string_length + s.string_length;
    return str;
}
int MyString::length() const { return string_length; }
void MyString::print() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];

    std::cout << std::endl;
}
int main() {
    MyString str1("abc");
    MyString str2("def");

    std::cout << "-----------------" << std::endl;
    MyString str3 = str1 + str2;
    str3.println();
    // 교재 640페이지
}


/* 이동 생성자 작성 시 주의할 점 */
/* 만약에 우리가 MyString 을 C++ 컨테이너들, 예를 들어 vector 에 넣기 위해서는 한 가지
주의할 점이 있다. 바로 이동 생성자를 noexcept 로 명시해야 한다는 점이다. 
이동 생성자를 사용하게 되면 이동 생성하는 과정에서 예외가 발생했다면 꽤나 골치아픈 상황이 된다. 
새로 할당한 메모리를 소멸시켜 버려도, 기존의 메모리에 원소들이 존재하기 때문에 상관 없지만, 이동 
생성의 경우 기존의 메모리에 원소들이 모두 이동되어서 사라져버렸기에, 새로 할당한 메모리를 섯불리 
해제해버릴 수 없기 때문이다. 
반면에 복사 생성자를 사용하였을 경우에는 원소가 하나씩 복사된다. 이 과정에서 예외가 발생하였어도
새로 할당한 메모리를 소멸시켜 버린 후, 사용자에게 예외를 전달하면 된다. 새로 할당한 메모리를 소멸
시키는 과정에서 이미 복사된 원소들도 소멸되므로 자원이 낭비되는 일도 없다. 

이 때문에 vector 는 이동 생성자가 noexcept 가 아닌 이상 이동 생성자를 사용하지 않는다. */

#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    char *string_content;
    int string_length;

    int memory_capacity;

    public:
    MyString();

    // 문자열로부터 생성
    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString &str);

    // 이동 생성자
    MyString(MyString &&str);

    ~MyString();
};

MyString::MyString() {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

MyString::MyString(const char *str) {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::MyString(MyString &&str) {
    std::cout << "이동 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // 임시 객체 소멸 시에 메모리를 해제하지
    // 못하게 한다. 
    str.string_content = nullptr;
}
MyString::~MyString() {
    if (string_content) delete[] string_content;
}

int main() {
    MyString s("abc");
    std::vector<MyString> vec;
    vec.resize(0);

    std::cout << "첫 번째 추가 ----" << std::endl;
    vec.push_back(s);
    std::cout << "두 번째 추가 ----" << std::endl;
    vec.push_back(s);
    std::cout << "세 번째 추가 ----" << std::endl;
    vec.push_back(s);
    /* 해당 코드와 같이, 기껏 이동 생성자를 만들어놓았는데
    vector 가 확장할 때마다 복사 생성자를 이용하는 것을 확인할 수 있다. 

    생성자 호출!!
첫 번째 추가 ----
복사 생성자 호출!!
두 번째 추가 ----
복사 생성자 호출!!
복사 생성자 호출!!
세 번째 추가 ----
복사 생성자 호출!!
복사 생성자 호출!!
복사 생성자 호출!!

    하지만 아래의 코드와 같이 이동 생성자에 noexcept 를 추가하면 어떨까?? (아래의 코드 참고!!) */
}




/* 이동 생성자에 noexcept 를 추가한 예제 코드!! */
#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    char *string_content;
    int string_length;

    int memory_capacity;

    public:
    MyString();

    //
    MyString(const char *str);

    //
    MyString(const MyString &str);

    //
    MyString(MyString &&str) noexcept;

    ~MyString();
};

MyString::MyString() {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = NULL;
}

MyString::MyString(const char *str) {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = strlen(str);
    memory_capacity = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content;
}
MyString::MyString(MyString &&str) noexcept {
    std::cout << "이동 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;
}


/* 생각해보기-문제 */
/* 문제 1:
사실 C++ 에서 값의 종류로 좌측값 우측값만 있는 것이 아니라 조금 더 세부적으로 나눠진다.
이에 대해 자세히 알아보고 싶으면 교재648P 에 있는 링크 확인!!(난이도: 상) */


/* move 문법과 완벽한 전달 */
/* 지난번에 배운 우측값 레퍼런스를 통해서 기존에는 불가능했던 우측값에 대한 복사가 아닌 이동의 구현이 가능해졌다. 
하지만, 만약 좌측값도 이동을 하고싶어지면 어떨까?? 예를 들어서 아래와 같이 두 변수의 값을 바꾸는 swap 함수를 생각해보자. */
template <typename T>
void my_swap(T &a, T & b) {
    T tmp(a);
    a = b;
    b = tmp;
}


 /* 위 my_swap 함수에서 tmp 라는 임시 객체를 생성한 뒤에, b 를 a 에 복사하고, b 에 a 를 복사하게된다.
문제는 복사를 무려 쓸데없이 3 번이나 한다는 점이다. 예를 들어서 T 가 MyString 인 경우를 생각해보자. */

#include <iostream>
#include <cstring>

class MyString {
    char *string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;      // 문자열 길이

    int memory_capacity;    // 현재 할당된 용량

    public:
    MyString();

    // 문자열로부터 생성
    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString &str);

    // 이동 생성자
    MyString(MyString &&str);

    MyString &operator=(const MyString &s);
    ~MyString();

    int length() const;

    void println();
};

MyString::MyString() {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = NULL;
}

MyString::MyString(const char *str) {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!!"  << std::endl;
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::MyString(MyString &&str) {
    std::cout << "이동 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // 임시 객체 소멸 시에 메모리를 해제하지
    // 못하게 한다. 
    str.string_content = nullptr;
}
MyString::~MyString() {
    if (string_content) delete[] string_content;
}

MyString &MyString::operator=(const MyString &s) {
    std::cout << "복사!!" << std::endl;
    if (s.string_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[s.string_length];
        memory_capacity = s.string_length;
    }
    string_length = s.string_length;
    for (int i = 0; i != string_length; i++) {
        string_content[i] = s.string_content[i];
    }
    return *this;
}
int MyString::length() const { return string_length; }
void MyString::println() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];

    std::cout << std::endl;
}
template <typename T>
void my_swap(T &a, T &b) {
    /* my_swap 함수를 살펴보면, 일단 첫번째 줄에서 a 가 좌측값이기 때문에 tmp 의 복사 생성자가 호출된다. 
    따라서 1 차적으로 a 가 차지하는 공간만큼 메모리 할당이 발생한 후 a 의 데이터가 복사된다. */
    T tmp(a);
    a = b;  /* 두 번째로, a = b; 에서 2 차적으로 복사가 발생한다. 그리고 마지막으로, */
    b = tmp;    /* b = tmp; 에서 또 한 번 문자열 전체의 복사가 이루어지게 된다. 
                무려 swap 을 하기 위해 문자열 전체 복사를 3 번이나 해야 한다. */
}

int main() {
    MyString str1("abc");
    MyString str2("def");
    std::cout << "Swap 전 --------" << std::endl;
    str1.println();
    str2.println();

    std::cout << "Swap 후 ------" << std::endl;
    my_swap(str1, str2);
    str1.println();
    str2.println();
}



/* move 함수(move semantics) */
/* 좌측값이 우측값으로 취급될 수 있게 바꿔주는 함수 같은 것이 있을까?? */
#include <iostream>
#include <utility>

class A {
    public:
    /* A 생성자에 아래와 같이 3 가지 형태의 생성자들을 정의하였다. */
    A() { std::cout << "일반 생성자 호출!!" << std::endl; }
    A(const A& a) { std::cout << "복사 생성자 호출!!" << std::endl; }
    A(A&& a) { std::cout << "이동 생성자 호출!!" << std::endl; }
};

int main() {
    A a;

    std::cout << "------------" << std::endl;
    A b(a); /* 일반 생성자와 복사 생성자가 각각 호출되었다!!!
            그 이유는 b(a) 를 했을 때 a 가 이름이 있는 좌측값이므로, 좌측값 레퍼런스가 참조하기 때문이다. */

    std::cout << "------------" << std::endl;
    A c(std::move(a));  /* 놀랍게도 이번에는 이동 생성자가 호출되었다. 
                        그 이유는 std::move 함수가 인자로 받은 객체(여기서는 좌측값인 a)를 우측값으로 변환해서 리턴해주기 때문이다. 
                        사실 이름만 보면 무언가 이동시킬 것 같지만, 실제로는 단순한 타입 변환만 수행할 뿐이다. */
    
    /* 해당 소스코드를 성공적으로 컴파일하면 결과는 아래와 같다.
    일반 생성자 호출!!
    ------------
    복사 생성자 호출!!
    ------------
    이동 생성자 호출!!
    */

   /* 주의사항: std::move 함수는 이동을 수행하지 않는다. 이름만 그럴 뿐, 그냥 인자로 받은 객체를 우측값으로 변환할 뿐이다!!! */
   /* 하지만 std::move 덕분에 강제적으로 우측값 레퍼런스를 인자로 받는 이동 생성자를 호출할 수 있었다. 그렇다면 이 아이디어를 바탕
   으로 우리의 MyString 에 어떻게 적용할 수 있을지 살펴보자.(아래의 코드 참고하기!!!) */
}


/* 좌측값으로 강제적으로 우측값으로 만드는 방법을 MyString 에 적용한 코드!! */
#include <iostream>
#include <cstring>

class MyString {
    char *string_content;   /* 문자열 데이터를 가리키는 포인터 */
    int string_length;      /* 문자열 길이 */

    int memory_capacity;    /* 현재 할당된 용량 */

    public:
    MyString();

    // 문자열로부터 생성
    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString &str);

    // 이동 생성자
    MyString(MyString &&str);

    // 일반적인 대입 연산자
    MyString &operator=(const MyString &s);

    // 이동 대입 연산자
    MyString& operator=(MyString&& s);

    ~MyString();

    int length() const;

    void println();
};

MyString::MyString() {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = 0; 
    memory_capacity = 0;
    string_content = NULL;
}

MyString::MyString(const char *str) {
    std::cout << "생성자 호출!!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::MyString(MyString &&str) {
    std::cout << "이동 생성자 호출!!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // 임시 객체 소멸 시에 메모리를 해제하지 
    // 못하게 한다. 
    str.string_content = nullptr;
    str.string_length = 0;
    str.memory_capacity = 0;
}
MyString::~MyString() {
    if (string_content) delete[] string_content;
}
MyString &MyString::operator=(const MyString &s) {
    std::cout << "복사!!" << std::endl;
    if (s.string_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[s.string_length];
        memory_capacity = s.string_length;
    }
    string_length = s.string_length;
    for (int i = 0; i != string_length; i++) {
        string_content[i] = s.string_content[i];
    }

    return *this;
}
MyString& MyString::operator=(MyString&& s) {   /* 이동 대입 연산자를 적용한 부분!!
                                                이동 대입 연산자 역시 이동 생성자와 비슷하게 매우 간단하다.
                                                전체 문자열을 복사할 필요 없이 그냥 기존의 문자열을 가리키고
                                                있던 string_content 만 복사하면 되기 때문이다. 
                                                여기서 알 수 있는 한 가지 사실은 실제로 데이터가 이동되는 과정은
                                                위와 같이 정의한 이동 생성자나 이동 대입 연산자를 호출할 때 수행
                                                되는 것이지 std::move 를 한 시점에서 수행되는 것이 아니라는 점이다. */
    /* 만일 우리가 MyStirng& MyString::operator=(MyString&& s) 를 정의하지 않았더라면, 일반적인 대입 연산자가 오버로딩 되어서 매우 느린 복사가 수행된다. 
    주의 사항: 다시 한 번 강조하지만, 이동 자체는 std::move 를 실행함으로써 발생하는 것이 아니라 우측값을 받는 함수들이 오버로딩 되면서 수행되는 것이다. */
    std::cout << "이동!!" << std::endl;
    string_content = s.string_content;
    memory_capacity = s.memory_capacity;
    string_length = s.string_length;
    s.string_content = nullptr;
    s.memory_capacity = 0;
    s.string_length = 0;
    return *this;
}

int MyString::length() const { return string_length; }
void MyString::println() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];

    std::cout << std::endl;
}

template <typename T>
void my_swap(T &a, T &b) {
    T tmp(std::move(a));    /* 해당 줄을 통햇 tmp 라는 임시 객체를 a 로부터 이동 생성하였다. 
                            이동 생성이기 때문에 기존에 복사 생성하는 것보다 훨씬 빠르게 수행된다. */
    a = std::move(b);       /* 그 다음에 a 에 b 를 이동시켰고, */
    b = std::move(tmp);     /* b 에 다시 tmp 를 이동시킴으로써 swap 을 수행하게 된다. 
                            왜 여기서 일반적인 '대입' 이 아니라 '이동' 이 되는 것이냐면,
                            우리가 아래와 같이 이동 대입 연산자를 정의하였기 때문이다. */
}
int main() {
    MyString str1("abc");
    MyString str2("def");
    std::cout << "Swap 전 ----" << std::endl;
    std::cout << "str1 : ";
    str1.println();
    std::cout << "str2 : ";
    str2.println();

    std::cout << "Swap 후 ----" << std::endl;
    my_swap(str1, str2);
    std::cout << "str1 : ";
    str1.println();
    std::cout << "str2 : ";
    str2.println();
}


/* 완벽한 전달(perfect forwarding) */
/* 우측값 레퍼런스를 도입함으로써 해결할 수 있었던 또 다른 문제가 있다. 예를 들어서 아래와 같은 wrapper 함수를 생각해보자.
C++11 에 우측값 레퍼런스가 도입되기 전까지 해결할 수 없었던 문제가 있었다. 예를 들어서 아래와 같은 wrapper 함수를 생각해보자. */
template <typename T>
void wrapper(T u) {
    g(u);
    /* 이 함수는 인자로 받은 u 를 그대로 g 라는 함수에 인자로 전달해준다. 물론 왜 저런 함수가 필요하냐고 생각할 수 있다. 
    그냥 저런 wrapper 함수를 만들지 말고 그냥 g(u) 를 호출하면 되지 않을까?? */
}
/* 하지만 실제로 저러한 형태의 전달 방식이 사용되는 경우가 종종 있다. 예를 들어 vector 에는 emplace_back 이라는 함수가 있다. 
이 함수는 객체의 생성자에 전달하고 싶은 인자들을 함수에 전달하면, 알아서 생성해서 vector 의 맨 뒤에 추가해준다. 
예를 들어서 클래스 A 를 원소로 가지는 벡터의 뒤에 원소를 추가하기 위해서는 */
vec.push_back(A(1, 2, 3));
/* 과 같이 객체를 생성한 뒤에 인자로 전달해주어야 한다. 하지만 이 과정에서 불필요한 이동이나 혹은 복사가 발생하게 된다는 단점이 있다.
그 대신, emplace_back 함수를 사용하게 되면 */
vec.emplace_back(1, 2, 3);  // 위와 동일한 작업을 수행한다. 
/* emplace_back 함수는 인자를 직접 전달받아서, 내부에서 A 의 생성자를 호출한 뒤에 이를 벡터 원소의 뒤에 추가하게 된다. 이 과정에서
불필요한 이동/복사 모두 발생하지 않는다. 참고로 새로 생성한 객체를 벡터 뒤에 추가할 경우 위와 같이 push_back 을 이용하는 것보다 
emplace_back 을 이용하는 것이 권장되는 방식이다. */

/* 주의 사항: emplace_back 을 사용 사에 주의할 점으로, 어떤 생성자가 호출되는지 명확히 알고 있어야 한다. 가끔 의도하지 않은 
생성자가 호출되어서 디버깅 시 난항을 겪는 경우가 있다. */


/* 그렇다면 문제는 emplace_back 함수가 받은 인자들을 A 의 생성자에 제대로 전달해야 한다는 점이다. 
그렇지 않을 경우 사용자가 의도하지 않은 생성자가 호출될 수 있기 때문이다. 그렇다면 위와 같은 wrapper 
함수를 어떻게 하면 잘 정의할 수 있을까?? */
#include <iostream>
#include <vector>

template <typename T>
void wrapper(T u) {
    g(u);
}

class A {};
void g(A& a) { std::cout << "좌측값 레퍼런스 호출" << std::endl; }
void g(const A& a) { std::cout << "좌측값 상수 레퍼런스 호출" << std::endl; }
void g(A&& a) { std::cout << "우측값 레퍼런스 호출" << std::endl; }

int main() {
    A a;
    const A ca;

    std::cout << "원본 -----------" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "Wrapper ----------" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
    /* 해당 코드를 성공적으로 컴파일하면 결과는 아래와 같다.
    원본 -----------
    좌측값 레퍼런스 호출
    좌측값 상수 레퍼런스 호출
    우측값 레퍼런스 호출
    Wrapper ----------
    좌측값 레퍼런스 호출
    좌측값 레퍼런스 호출
    좌측값 레퍼런스 호출 
    
    먼저 위의 경우("원본 -------") 예상대로 좌측값 레퍼런스-좌측값 상수 레퍼런스-우측값 레퍼런스가 각각 호출되었다. 
    반면에 wrapper 함수를 거쳐갔을 경우, 공교롭게도 위 세 경우 모두 좌측값 레퍼런스를 받는 g 함수가 호출되었다. 
    이러한 일이 발생한 이유는 C++ 컴파일러가 템플릿 타입을 추론할 때, 템플릿 인자 T 가 레퍼런스가 아닌 일반적인 타입
    이라면 const 를 무시하기 때문이다. 다시 말해,
    template <typename T>
    void wrapper(T u) {
        g(u);
    }
    에서 T 가 전부 다 class A 로 추론된다.
    따라서 위 세 경우 전부 다 좌측값 레퍼런스를 호출하는 g 를 호출한다. 
    
    그렇다고 해서 아래의 모습과 같이 바꾼다면, 컴파일 오류가 발생한다. 
    template <typename T>
    void wrapper(T& u) {
        g(u);
    } 
    컴파일 오류는 g(A()); 에서 발생하게 된다. 
    그렇다면 아예 우측값을 레퍼런스로 받을 수 있도록 const A& 와 A& 를 따로 만들어주는 방법이 있다. (아래의 코드 참고!!!) */
}


/* const A&  와 A& 를 따로 만들어주는 방법 */
#include <iostream>
#include <vector>

template <typename T>
void wrapper(T& u) {
    std::cout << "T& 로 추론됨." << std::endl;
    g(u);
}

template <typename T>
void wrapper(const T& u) {
    std::cout << "const T& 로 추론됨." << std::endl;
    g(u);
}

class A {};
void g(A& a) { std::cout << "좌측값 레퍼런스 호출" << std::endl; }
void g(const A& a) { std::cout << "좌측값 상수 레퍼런스 호출" << std::endl; }
void g(A&& a) { std::cout << "우측값 레퍼런스 호출" << std::endl; }

int main() {
    A a;
    const A ca;

    std::cout << "원본 ---------" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "Wrapper --------" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
    /* 일단, a 와 ca 의 경우 각각 T& 와 const T& 로 잘 추론되어서 올바른 함수를 호출하고 있음을 알 수 있다. 
    반면에 A() 의 경우 const T& 로 추론되면서 g(const T&) 함수를 호출하게 된다. 물론 이는 예상했던 일이다.
    우리가 무엇을 해서 wrapper 안에 u 가 좌측값이라는 사실은 변하지 않고, 이에 언제나 좌측값 레퍼런스를 받는
    함수들이 오버로딩 될 것이다. 
    
    뿐만이 아니라 다음과 같은 문제가 있다. 예를 들어서 함수 g 가 인자를 한 개가 아니라 2 개를 받는다고 가정한다. 
    그렇다면 우리는 다음과 같은 모든 조합의 템플릿 함수들을 정의해야 한다. (교재 666 페이지 참고!!) 
    이는 매우 귀찮은 일이다. 이와 같이 짜야하는 이유는 단순히 일밙거인 레퍼런스가 울측값을 받을 수 없기 때문이다. 
    그렇다고 해서 디폴트로 상수 레퍼런스만 받게 된다면, 상수가 아닌 레퍼런스도 상수 레퍼런스로 캐스팅되어서 들어간다는
    점이다. 
    하지만 놀랍게도 C++ 11 에서는 이를 간단하게 해결할 수 있다!!!(아래의 코드 참고!!!) */
}


/* 보편적 레퍼런스(Universal reference) */
#include <iostream>

template <typename T>
void wrapper(T&& u) {
    /* 해당 코드의 wrapper 함수는 인자로 아예 T && 를 받아버리고 있다. 
    이렇게 템플릿 인자 T 에 대해서, 우측값 레퍼런스를 받는 형태를 '보편적 레퍼런스(Universal reference)' 라고 한다. 
    이 보편적 레퍼런스는 우측값만 받는 레퍼런스와는 다르다. */
    g(std::forward<T>(u));
}

class A {};

void g(A& a) { std::cout << "좌측값 레퍼런스 호출!!" << std::endl; }
void g(const A& a) { std::cout << "좌측값 상수 레퍼런스 호출!!" << std::endl; }
void g(A&& a) { std::cout << "우측값 레퍼런스 호출!!" << std::endl; }

int main() {
    A a;
    const A ca;

    std::cout << "원본 ----" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "Wrapper ----" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
}


/* 생각해보기-문제 */
/* 문제 1: 
실제로 move 와 forward 가 어떠한 방식으로 구현되어 있는지 궁금한 사람들은 교좨 670 페이지 참고하기!!! (난이도: 중) */



/* 자원(resource) 관리의 중요성 */
/* C++ 이후에 나온 많은 언어(Java 등등) 들은 대부분은 가비지 컬렉터라 불리는 자원 청소기가 기본적으로 내장되어 있다. 
이 가비지 컬렉터의 역할은 프로그램 상에서 더 이상 쓰이지 않는 자원을 자동으로 해제해 주는 역할을 한다. 따라서 
프로그래머들이 코드를 작성할 때, 자원을 해제하는 일에 대해 크게 신경 쓸 필요는 없다. 
하지만 C++ 의 경우는 다르다. 우리가 한 번 획득한 자원은, 직접 해제해주지 않는 이상 프로그램이 종료되기 전까지 영원히
남아있게 된다. (프로그램이 종료되면 운영체제가 알아서 해제해준다.) 예를 들어서 */
#include <iostream>

class A {
    int *data;

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함!!" << std::endl;
    }

    ~A() {
        std::cout << "소멸자 호출!!" << std::endl;
        delete[] data;
    }
};

void do_something() { A *pa = new A(); }

int main() {
    do_something();
    // 할당된 객체가 소멸되지 않음!! --> 자원을 획득만 하고, 소멸자는 호출되지 않은 점을 확인할 수 있다!! 
    // 즉, 400 바이트(4 * 100) 만큼의 메모리 누수 발생!! 

    /* 해당 코드를 성공적으로 컴파일 하였다면, 결과는 "자원을 획득함!!" 하나만 출력된다. 
    즉 자원을 획득만 하고, 소멸자는 호출되지 않은 점을 확인할 수 있다. 그 이유는 까먹고 
    delete pa;
    를 해주지 않았기 때문이다. (아시다시피 delete 는 메모리를 해제하기 직전 가리키는 객체의 소멸자를 호출해준다.) */

    /* 만약 delete 를 do_something 함수 안에서 해주지 않는다면, 생성된 개체를 가리키던 pa 는 메모리에서 사라지게 된다. 
    따라서 Heap 어딘가에 클래스 A 의 객체가 남아있지만, 그 주소값을 가지고 있는 포인터는 메모리 상에 존재하지 않게 된다. 
    그 객체는 영원히 해제되지 못한 재 힙에서 자리만 차지하고 있게 된다. 해당 코드의 경우에는 400 바이트의 메모리 누수가 발생하게 된다. */
}


/* 다음과 같은 상황을 가정해보기 */
#include <iostream>

class A {
    int *data;

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함!!" << std::endl;
    }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data;
    }
};

void thrower() {
    // 예외를 발생시킴!! 
    throw 1;
}

void do_something() {
    A *pa = new A();
    thrower();

    // 발생된 예외로 인해 delete pa 가 호출되지 않는다!!! 
    delete pa;
}

int main() {
    try {
        do_something();
    } catch (int i) {
        std::cout << "예외 발생!!" << std::endl;
        // 예외 처리
    }
    /* 보시다시피, thrower() 로에서 발생된 예외로 인해, 밑에 있는 delete pa 가 실행되지 않고 
    넘어가버렸다. 물론 예외는 정상적으로 처리되었지만, 이로 인해 메모리 누수는 피할 수 없게 된다. 
    그렇다면 이 상황을 어떻게 해결할까?? (아래 참고!!!) */
}


/* 객체의 유일한 소유권(unique_ptr) */
/* C++ 에서는 특정 객체에 유일한 소유권을 부여하는 포인터 객체를 unique_ptr 이라고 한다. */
#include <iostream>
#include <memory>

class A {
    int *data;

    public:
    A() {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용 가능!!" << std::endl; }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data; 
    }
};

void do_something() {
    std::unique_ptr<A> pa(new A());     /* 먼저 unique_ptr 을 정의하는 부분을 살펴보면 다음과 같다.
                                        unique_ptr 를 정의하기 위해서는 템플릿에 인자로, 포인터가 가리킬 클래스를 전달하면 된다. 
                                        위의 경우 pa 는 A 클래스의 객체를 가리키는 포인터가 된다. 
                                        위는 마치 
                                        A* pa = new A();
                                        와 동일한 문장이라고 생각하면 된다. */
    pa->some();
}

int main() { do_something(); }


/* 만약에 unique_ptr 을 복사하려고 한다면 어떨까?? */
#include <iostream>
#include <memory>

class A {
    int *data;

    public:
    A() {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용 가능!!" << std::endl; }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data;
    }
};

void do_something() {
    std::unique_ptr<A> pa(new A());

    // pb
    std::unique_ptr<A> pb = pa;
}

int main() { do_something(); }
/* 해당 코드를 컴파일하면 컴파일 오류가 발생한다. 위 오류는 삭제된 함수를 사용하려고 했기에 발생하는데,
삭제된 함수가 도대체 무슨 말일까?? */


/* 삭제된 함수 */
#include <iostream>

class A {
    public:
    A(int a){};
    A(const A& a) = delete;
};

int main() {
    A a(3); // 가능
    A b(a); // 불가능
    /* 해당 코드를 컴파일하게 된다면 복사 생성자를 호출하는 부분에서 오류가 발생함을 알 수 있다. 
    왜냐하면 
    A(const A& a) = delete;
    위와 같이 복사 생성자를 명시적으로 삭제하였기 때문이다. 따라서, 클래스 A 의 복사 생성자는 존재하지 않는다.
    위와 같이 delete; 를 사용하게 되면, 프로그래머가 명시적으로 '이 함수는 쓰지 마!!' 라고 표현할 수 있다. 
    혹시나 사용하더라도 컴파일 오류가 발생하게 된다. */
}


/* unique_ptr 소유권 이전하기 */
/* 앞서 unique_ptr 는 복사가 되지 않는다고 하였지만, 소유권은 이전할 수 있다. */
#include <iostream>
#include <memory>

class A {
    int *data;

    public:
    A() {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용 가능!!" << std::endl; }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data;
    }
};

void do_something() {
    std::unique_ptr<A> pa(new A());
    std::cout << "pa : ";
    pa->some();

    // pb 에 소유권을 이전.
    std::unique_ptr<A> pb = std::move(pa);  /* 이 줄에서는 pa 를 pb 에 강제로 이동시켜버린다. 
                                            이제 pb 가 new A 로 생성된 객체의 소유권을 갖게 되고, pa 는 아무것도 가리키고 있지 않게 된다. 
                                            실제로 
                                            pa.get()
                                            으로 pa 가 가리키고 있는 실제 주소값을 확인해보면 0 (nullptr) 이 나온다. 
                                            따라서 pa 를 이동시켜버린 이후에 pa->some() 을 하게 되면 문제가 발생하게 된다. 
                                            그러므로 소유권을 이동시킨 이후에 기존의 unique_ptr 에 접근하지 않도록 조심해야 한다!! */
    std::cout << "pb : ";
    pb->some();
    /* 주의 사항: 소유권이 이전된 unique_ptr 을 '댕글링 포인터(dangling pointer)' 라고 하며, 이를 재참조할 시에 
    런타임 오류가 발생하도록 한다. 따라서 소유권 이전은, 댕글링 포인터를 절대 다시 참조하지 않겠다는 확신 하에 이동해야 한다. */
}

int main() { do_something(); }
/* 해당 소스코드를 성공적으로 컴파일한다면 결과는 아래와 같다.

    자원을 획득함!!
    pa : 일반 포인터와 동일하게 사용 가능!!
    pb : 일반 포인터와 동일하게 사용 가능!!
    자원을 해제함!!
    
    unique_ptr 은 복사 생성자는 정의되어 있지 않지만, 이동 생성자는 가능하다. 왜냐하면, 마치 소유권을 이동시킨다는 개념으로
    생각하면 되기 때문이다. */



/* unique_ptr 를 함수 인자로 전달하기 */
/* 만약에 어떠한 unique_ptr 를 함수 인자로 전달하고 싶다면 어떨까?? 앞서 말했듯이, 
unique_ptr 는 복사 생성자가 없다고 하였다. 그렇다면, 그냥 함수의 레퍼런스에 전달하면 어떨까?? */
#include <iostream>
#include <memory>

class A {
    int* data;

    public:
    A() {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용가능!!" << std::endl; }

    void do_sth(int a) {
        std::cout << "무언가를 한다!!" << std::endl;
        data[0] = a;
    }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data;
    }
};

// 올바르지 않은 전달 방식
void do_something(std::unique_ptr<A>& ptr) { ptr->do_sth(3); }

int main() {
    std::unique_ptr<A> pa(new A());
    do_something(pa);
    /* 해당 코드에서는 문제점이 있다. 
    해당 코드를 성공적으로 컴파일한 결과는 아래와 같다. 
    자원을 획득함!!
    무언가를 한다!! 
    자원을 해제함!!
    일단, 함수 내부로 unique_ptr 가 잘 전달되었음을 알 수 있다. 하지만, 위와 같이 함수에 unique_ptr 을 전달하는 것이 문맥 상 맞는 코드일까?? 
    앞서 말했듯이, unique_ptr 은 어떠한 객체의 소유권을 의미한다고 했다. 하지만, 위와 같이 레퍼런스로 unique_ptr 을 전달했다면
    do_something 함수 내부에서 ptr 은 더이상 유일한 소유권을 의미하지 않는다. 
    
    물론 ptr 은 레퍼런스이기 때문에, do_something 함수가 종료되면서 pa 가 가리키고 있는 객체를 파괴하지는 않는다. 
    하지만, pa 가 유일하게 소유하고 있던 객체는 이제, 적어도 do_something 함수 내부에서는 ptr 을 통해서도 소유할 수 있게 된다는 것이다. 
    즉, unique_ptr 은 소유권을 의미한다는 원칙에 위배되는 것이다. 
    따라서, unique_ptr 의 레퍼런스를 사용하는 것은 unique_ptr 를 소유권이라는 중요한 의미를 망각한 채 단순히 포인터의 단순한 
    Wrapper 로 사용하는 것에 불과하다. 
    그렇다면, 함수에 올바르게 unique_ptr 를 전달하는 방법이 있을까?? 이는 단순하다.
    그냥 원래의 포인터 주소값을 전달해주면 된다. */
}


#include <iostream>
#include <memory>

class A {
    int* data;

    public:
    A() {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용가능!!!" << std::endl; }

    void do_sth(int a) {
        std::cout << "무언가를 한다!!" << std::endl;
        data[0] = a;
    }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data; 
    }
};

void do_something(A* ptr) { ptr->do_sth(3); }

int main() {
    std::unique_ptr<A> pa(new A());
    do_something(pa.get());
    /* 해당 코드를 성공적으로 컴파일하였다면 결과는 아래와 같다.
    자원을 획득함!! 
    무언가를 한다!!
    자원을 해제함!!
    
    unique_ptr 의 get 함수를 호출하면, 실제 객체의 주소값을 리턴해준다. 위의 경우 do_something 함수가 일반적인 포인터를 받고 있다. 
    이렇게 된다면, 소유권이라는 의미는 버린 채, do_something 함수 내부에서 객체에 접근할 수 있는 권한을 주는 것이다!! 
    정리해보자면,
    1) unique_ptr 은 어떤 객체의 유일한 소유권을 나타내는 포인터이며, unique_ptr 가 소멸될 때, 가리키던 객체 역시 소멸된다. 
    2) 만약에 다른 함수에서 unique_ptr 가 소유한 객체에 일시적으로 접근하고 싶다면, get 을 통해 해당 객체의 포인터를 전달하면 된다. 
    3) 만약에 소유권을 이동하고자 한다면, unique_ptr 를 move 하면 된다. */
}


/* unique_ptr 을 쉽게 생성하기 */
/* C++ 14 부터 unique_ptr 을 간단히 만들 수 있는 std::make_unique 함수를 제공한다. */
#include <iostream>
#include <memory>

class Foo {
    int a, b;

    public:
    Foo(int a, int b) : a(a), b(b) { std::cout << "생성자 호출!!" << std::endl; }
    void print() { std::cout << "a : " << a << ", b : " << b << std::endl; }
    ~Foo() { std::cout << "소멸자 호출!!" << std::endl; }
};

int main() {
    auto ptr = std::make_unique<Foo>(3, 5);
    ptr->print();
    /* 해당 코드를 컴파일하면 다음과 같은 결과가 나오는 것을 확인할 수 있다. 
    생성자 호출!!
    a : 3, b : 5
    소멸자 호출!!
    이처럼 해당 코드는 잘 작동한다. make_unique 함수는 아예 템플릿 인자로 전달된 클래스의 생성자의 인자들에
    직접 '완벽한 전달' 을 수행한다. 따라서 기존처럼 불필요하게 
    std::unique_ptr<Foo> ptr(new Foo(3, 5));
    할 필요 없이 간단히 make_unique 로 만들 수 있다. */
}


/* unique_ptr 를 원소로 가지는 컨테이너 */
/* 이제 마지막으로 unique_ptr 를 원소로 가지는 STL 컨테이너에 대해 알아보도록 하자.
사실, unique_ptr 은 다른 타입들과 큰 차이는 없지만, '복사 생성자가 없다' 라는 특성 
때문에 처음에 사용하는 사람들이 많은 애를 먹는 경우를 종종 보았다. */
#include <iostream>
#include <memory>
#include <vector>

class A {
    int *data;

    public:
    A(int i) {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
        data[0] = i;
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용가능!!" << std::endl; }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data;
    }
};

int main() {
    std::vector<std::unique_ptr<A>> vec;
    std::unique_ptr<A> pa(new A(1));

    vec.push_back(pa);
    /* 해당 코드를 컴파일하면 컴파일 오류가 발생하게 된다. 
    이와 같은 오류가 발생하는 이유는 역시 삭제된 unique_ptr 의 복사 생성자에 접근하였기 때문이다. 
    기본적으로 vector 의 push_back 함수는 전달된 인자를 복사해서 집어넣기 때문에 위와 같은 문제가 발생하게 되는 것이다. 
    
    이를 방지하기 위해서는 명시적으로 pa 를 vector 안으로 이동시켜주어야만 한다. 
    즉, push_back 의 우측값 레퍼런스를 바는 버전이 오버로딩 될 수 있도록 해주어야 하는 것이다. 
    int main() {
        std::vector<std::unique_ptr<A>> vec;
        std::unique_ptr<A> pa(new A(1));
        
        vec.push_back(std::move(pa));   // 수정된 부분-->잘 실행됨!!!
    }
    와 같이 하면 잘 컴파일된다. 
    하지만 재미있게도, emplace_back 함수를 이용하면, vector 안에 unique_ptr 을 직접 생성하면서 집어넣을 수도 있다. 
    즉, 불필요한 이동 과정을 생략할 수도 있다는 것이다. (아래의 코드 참고!!!) */
}


/* emplce_back 함수를 이용하여 vector 안에 unique_ptr 직접 생성하기 */
#include <iostream>
#include <memory>
#include <vector>

class A {
    int *data;

    public:
    A(int i) {
        std::cout << "자원을 획득함!!" << std::endl;
        data = new int[100];
        data[0] = i;
    }

    void some() { std::cout << "값: " << data[0] << std::endl; }

    ~A() {
        std::cout << "자원을 해제함!!" << std::endl;
        delete[] data;
    }
};

int main() {
    std::vector<std::unique_ptr<A>> vec;

    // vec.push_back(std::unique_ptr<A>(new A(1))); 과 동일!!
    vec.emplace_back(new A(1));

    vec.back()->some();
    /* 해당 코드를 성공적으로 컴파일하고 나온 결과는 다음과 같다. 
    자원을 획득함!!
    값: 1
    자원을 해제함!!
    
    emplace_back 함수는 전달된 인자를 '완벽한 전달(perfect forwarding)' 을 통해, 직접 unique_ptr<A> 의 생성자에 전달해서,
    vector 맨 뒤에 unique_ptr<A> 객체를 생성해버리게 된다. 
    따라서, 위에서처럼 불필요한 이동 연산이 필요 없게 된다. (왜냐하면 vector 맨 뒤에 생성하기 때문!!!) */
}

/* 참고로 emplace_back 을 사용 시에 어떠한 생성자가 호출되는지 주의해야한다. 
예를 들어서
std::vector<int> v;
v.emplae_back(100000);
을 하게 되면, 100000 이란 int 값을 v 에 추가하게 되지만
std::vector<std::vector<int>> v;
v.emplace_back(100000);
를 하게 되면 원소가 100000 개 들어있는 벡터를 v 에 추가하게 된다. */

/* 생각해보기-문제 */
/* 문제 1:
unique_ptr 을 어떤 식으로 구현할 수 있을지 생각해보자. (난이도: 중상) */


/* 여러 객체가 소유할 수 있는 포인터 */

/* shared_ptr */
/* shared_ptr 은 앞서 이야기한 방식을 정확히 수행하는 스마트 포인터이다. 
기존에 유일하게 객체를 소유하는 unique_ptr 와는 달리, shared_ptr 로 객체를 가리킬 경우,
다른 shared_ptr 역시 그 객체를 가리킬 수 있다. 예를 들어서 */
std::shared_ptr<A> p1(new A());
std::shared_ptr<A> p2(p1);  // p2 역시 생성된 객체 A 를 가리킨다.--> p1 과 p2 의 참조 카운트는 2 이다!!!

// 반면에 unique_ptr 의 경우
std::unique_ptr<A> p1(new A());
std::unique_ptr<A> p2(p1);  // 컴파일 오류!!
/* p1 과 p2 의 경우, 동일한 객체인 A() 를 가리키지만, unique_ptr 의 경우, 유일한 소유권만이 인정되므로 둘 이상의 스마트 포인터가 
한 자원을 가리킬 경우 컴파일 오류가 발생하게 된다. */


/* 예제 코드 */
#include <iostream>
#include <memory>
#include <vector>

class A {
    int *data;

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함!!" << std::endl;
    }

    ~A() {
        std::cout << "소멸자 호출!!" << std::endl;
        delete[] data;
    }
};

int main() {
    std::vector<std::shared_ptr<A>> vec;

    vec.push_back(std::shared_ptr<A>(new A()));
    vec.push_back(std::shared_ptr<A>(vec[0]));
    vec.push_back(std::shared_ptr<A>(vec[1]));

    // 벡터의 첫번째 원소를 소멸시킨다. 
    std::cout << "첫 번째 소멸!!" << std::endl;
    vec.erase(vec.begin());

    // 그다음 원소를 소멸시킨다. 
    std::cout << "다음 원소 소멸!!" << std::endl;
    vec.erase(vec.begin());

    // 마지막 원소를 소멸시킨다. 
    std::cout << "마지막 원소 소멸!!" << std::endl;
    vec.erase(vec.begin());

    std::cout << "프로그램 종료!!" << std::endl;
    /* 해당 코드를 성공적으로 컴파일한다면 결과는 아래와 같다. 
    자원을 획득함!!
    첫 번째 소멸!!
    다음 원소 소멸!!
    마지막 원소 소멸!!
    소멸자 호출!!
    프로그램 종료!!
    
    해당 예제 코드의 경우 shared_ptr 를 원소로 가지는 벡터 vec 을 정의한 후, vec[0], vec[1], vec[2] 가 
    모두 같은 A 객체를 가리키는 shared_ptr 를 생성하였다. 
    위에서 vec 의 첫 번째 원소부터 차례대로 지워나갔는데, unique_ptr 와는 다르게 shared_ptr 의 경우
    객체를 가리키는 모든 스마트 포인터들이 소멸되어야만 객체를 파괴하기 때문에, 처음 두 번의 erase 에서는
    아무것도 하지 않다가 마지막의 erase 에서 비로소 A 의 소멸자를 호출하는 것을 볼 수 있다. 
    즉, 참조 개수가 처음에는 3 이었다가 2, 1, 0 순으로 줄어들게 된다. */
}


/* 현재 shared_ptr 의 참조 개수가 몇 개인지는 use_count 함수를 통해서 알 수 있다. 
예를 들어서 */
std::shared_ptr<A> p1(new A());
std::shared_ptr<A> p2(p1);  // p2 역시 생성된 객체 A 를 가리킨다. 

std::cout << p1.use_count();    // 2
std::cout << p2.use_count();    // 2
/* 와 같이 출력될 것이다. */


// 교재 693 ㅍㅇㅈ
/* 그렇다면, 위에서도 보시다시피 개개의 shared_ptr 들은 참조 개수가 몇 개인지 알고 있어야 한다. 
이 경우 어떻게 하면 같은 객체를 가리키는 shared_ptr 끼리 동기화를 시킬 수 있을까?? 
만약에 shared+ptr 내부에 참조 개수를 저장한다면 아래와 같은 문제가 생길 수 있다. 만약에 아래와 같이
한 개의 shared_ptr 가 추가적으로 해당 객체를 가리킨다면 어떨까??
std::shared_ptr<A> p3(p2);
와 같이 말이다. 그렇다면 p2 의 참조 카운트 개수는 증가시킬 수 있다고 해도, p1 에 저장되어 있는 참조
개수를 건드릴 수 없다. 즉 아래와 같은 상황이 발생한다. 
따라서 이와 같은 문제를 방지하기 위해서는 처음으로 실제 객체를 가리키는 shared_ptr 가 제어 블록(control block) 을
동적으로 할당한 후, shared_ptr 들이 이 제어 블록에 필요한 정보를 공유하는 방식으로 구현된다. */


/* make_shared 로 생성하자 */
/* 앞서 shared_ptr 를 처음 생성할 때 아래와 같이 하였다. 
std::shared_ptr<A> p1(new A());
하지만 사실 이는 바람직한 shared_ptr 의 생성 방법은 아니다. 왜냐하면 일단 A 를 생성하기 위해서 
동적 할당이 한 번 일어나야 하고, 그 다음 shared_ptr 의 제어 블록 역시 동적으로 할당해야 하기 
때문이다. 즉 두 번의 동적 할당이 발생해야 한다. 
동적 할당은 상당히 비싼 연산이다. 어차피 동적 할당을 두 번 할 것이라는 것을 알고 있다면, 아예 두 개
합친 크기로 한 번 할당하는 것이 훨씬 빠르다. 
std::shared_ptr<A> p1 = std::make_shared<A>();
make_shared 함수는 A 의 생성자들의 인자들을 받아서 이를 통해 객체 A 와 shared_ptr 의 제어 블록까지
한 번에 동적 할당한 후에 만들어진 shared_ptr 을 리턴한다. 

위 경우 A 의 생성자에 인자가 없어서 make_shared 에 아무 것도 전달하지 않았지만, 만약에 A 의 생성자에 인자
가 있다면 make_shared 에 인자로 전달해 주면 된다. (그리고 make_shared 가 A 의 생성자에 완벽한 전달을 해 줄 것이다.) */

/* shared_ptr 생성 시에 주의할 점 */
/* shared_ptr 은 인자로 주소값이 전달된다면, 마치 자기가 해당 객체를 첫번째로 소유하는 shared_ptr 인 것마냥 행동한다. 
예를 들어서
A* a = new A();
std::shared_ptr<A> pa1(a);
std::shared_ptr<A> pa2(a);
를 하게 된다면 아래와 같이 이 두 개의 제어 블록이 따로 생성된다. 
따라서 위와 같이 각각의 제어 블록들은, 다른 제어 블록들의 존재를 모르고 참조 개수를 1 로 
설정하게 될 것이다. pa2 가 아직 가리키고 있는데도 말이다. 
물론 pa2 의 참조 카운트는 계속 1 이기 때문에 자신이 가리키는 객체가 살아있을 것이라 생각할
것이다. 설사 운 좋게도 pa2 를 사용하지 않아도, pa2 가 소멸되면 참조 개수가 0 으로 떨어지고 
자신이 가리키고 있는(이미 해제된) 객체를 소멸시키기 때문에 오류가 발생한다. 
아래 예제를 보면 쉽게 알 수 있다. */



/* 예제 코드 */
#include <iostream>
#include <memory>

class A {
    int* data;

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함" << std::endl;
    }

    ~A() {
        std::cout << "소멸자 호출!!" << std::endl;
        delete[] data;
    }
};

int main() {
    A* a = new A();

    std::shared_ptr<A> pa1(a);
    std::shared_ptr<A> pa2(a);

    std::cout << pa1.use_count() << std::endl;
    std::cout << pa2.use_count() << std::endl;
    /* 성공적으로 컴파일하였다면, 소멸자가 두 번 호출되면서 오류가 발생하게 된다. 
    오류 내용 역시, 이미 해제한 메모리를 또 해제한다는 뜻이다. 
    이와 같은 상황을 방지하려면 shared_ptr 를 주소값을 통해서 생성하는 것을 지양
    해야 한다. 
    하지만, 어쩔 수 없는 상황도 있다. 바로 객체 내부에서 자기 자신을 가리키는 shared_ptr 
    를 만들 때를 생각해보자. */
}


#include <iostream>
#include <memory>

class A {
    int *data;  /* 100 개의 정수를 저장할 수 있는 동적 배열을 가리키는 포인터이다. */

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함" << std::endl;
    }

    ~A() {
        std::cout << "소멸자 호출" << std::endl;
        delete[] data;
    }
    
    std::shared_ptr<A> get_shared_ptr() { return std::shared_ptr<A>(this); }
    /* 윗줄은 this 포인터를 사용하여 std::shared_ptr<A> 객체를 생성하고 반환한다. (여기서 this 는 현재 객체를 가리킨다.) */
};

int main() {
    std::shared_ptr<A> pa1 = std::make_shared<A>(); /* make_shared 를 사용하여 A 객체를 생성하고, 
                                                    그 객체를 관리하는 shared_ptr 인 pa1 을 생성한다. 
                                                    이때 A 객체의 data 가 할당된다. */
    std::shared_ptr<A> pa2 = pa1->get_shared_ptr(); /* pa1 을 통해 A 객체의 get_shared_ptr() 메서드를 호출하여
                                                    this 를 사용하여 shared_ptr 를 생성하고 pa2 에 저장한다. */

    std::cout << pa1.use_count() << std::endl;
    std::cout << pa2.use_count() << std::endl;
    /* 해당 소스코드를 컴파일하게 되면 오류가 발생한다. 해당 오류는 이전과 동일한 이유로 발생한다. 
    get_shared_ptr 함수에서 shared_ptr 을 생성할 때, 이미 자기 자신을 가리키는 shared_ptr 가 있다는 사실을 
    모른 채로 새로운 제어 블록을 생성하기 때문이다. 
    
    이 문제는 enable_shared_from_this 를 통해서 깔끔하게 해결하는 것이 가능하다. */
}


/* enable_shared_from_this */
/* 우리가 this 를 사용해서 shared_ptr 을 만들고 싶은 클래스가 있다면, 
enable_shared_from_this 를 상속받으면 된다. */
#include <iostream>
#include <memory>

class A : public std::enable_shared_from_this<A> {
    int *data;

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함!!" << std::endl;
    }

    ~A() {
        std::cout << "소멸자 호출!!" << std::endl;
        delete[] data;
    }

    std::shared_ptr<A> get_shared_ptr() { return shared_from_this(); }
};

int main() {
    std::shared_ptr<A> pa1 = std::make_shared<A>();
    std::shared_ptr<A> pa2 = pa1->get_shared_ptr();

    std::cout << pa1.use_count() << std::endl;
    std::cout << pa2.use_count() << std::endl;
    /* 해당 코드를 성공적으로 컴파일하면 결과는 아래와 같다. 
    자원을 획득함!!
    2
    2
    소멸자 호출!!
    잘 작동하는 것을 확인할 수 있다. 
    enable_shared_from_this 클래스에는 shared_from_this 라는 멤버 함수를 정의하고 있는데, 
    이 함수는 이미 정의되어 있는 제어 블록을 사용해서 shared_ptr 을 생성한다. 따라서 이전처럼
    같은 객체에 두 개의 다른 제어 블록이 생성되는 일을 막을 수 있다. 
    한 가지 중요한 점은 shared_from_this 가 잘 작동하기 위해서는 해당 객체의 shared_ptr 가
    반드시 먼저 정의되어 있어야만 한다. 즉 shared_from_this 는 있는 제어 블록을 확인만 할 뿐,
    없는 제어 블록을 만들지는 않는다. 쉽게 말해 아래 코드는 오류가 발생한다. 
    A* a = new A();
    std::shared_ptr<A> pa1 = a->get_shared_ptr();
    
    */
}


/* 서로 참조하는 shared_ptr */
/* 앞서 shared_ptr 는 참조 개수가 0 이 되면 가리키는 객체를 메모리에서 해제시킨다고 했다.
그런데, 객체들을 더이상 사용하지 않는데도 불구하고 참조 개수가 절대로 0 이 될 수 없는 상황이
있다. 이와 같은 형태를 '순환 참조' 라고 한다. 서로가 서로를 가리키고 있기에 이도저도 아닌 
상황이 된 것이다. */
#include <iostream>
#include <memory>

class A {
    int *data;
    std::shared_ptr<A> other;

    public:
    A() {
        data = new int[100];
        std::cout << "자원을 획득함!!" << std::endl;
    }

    ~A() {
        std::cout << "소멸자 호출!!" << std::endl;
        delete[] data;
    }

    void set_other(std::shared_ptr<A> o) { other = o; }
};

int main() {
    std::shared_ptr<A> pa = std::make_shared<A>();
    std::shared_ptr<A> pb = std::make_shared<A>();

    pa->set_other(pb);
    pb->set_other(pa);
    /* 해당 소스코드를 출력해보면 
    자원을 획득함!!
    자원을 획득함!!
    라는 결과에서 볼 수 있듯이 소멸자가 제대로 호출되지 않음을 알 수 있다. 
    이 문제는 shared_ptr 자체에 내재되어 있는 문제이기 때문에 shared_ptr 를 통해서는 이를 해결할 수 없다. 
    이러한 '순환참조' 문제를 해결하기 위해 나타난 것이 바로 weak_ptr 이다. */
}

/* weak_ptr */
/* 우리는 트리 구조를 지원하는 클래스를 만들려고 한다. 트리 구조라 함은 가계도와 비슷한 형태를
띠고 있다고 생각하면 되낟. 
즉, 한 개의 노드는 여러 개의 자식 노드를 가질 수 있지만, 단 한 개의 부모 노드를 가진다. 위 그림
에서 부모 노드는 자식 노드들을 가리키고 있고(실선 = 파생), 자식 노드들은 부모 노드들을 가리키고 있다.(점선 = 기반) 
위와 같은 형태를 자료 구조로 나타낸다면 어떻게 할 수 있을까?? */
class Node {
    std::vector<std::shared_ptr<Node>> children;
    /* 어떤 타입이 와야할까?? */ parent;

    public:
    Node(){};
    void AddChild(std::shared_ptr<Node> node) { children.push_back(node); }
};
/* 일단 기본적으로 위와 같은 형태를 취한다고 볼 수 있다. 부모가 여러 개의 자식 노드들을 가지므로
shared_ptr 들의 벡터로 나타낼 수 있고, 그 노드 역시 부모 노드가 있으므로 부모 노드를 가리키는 포인터를 가진다. 
여기서 질문은 과연 parent 의 타입을 무엇으로 하는가이다. 
1) 만약에 일반 포인터(Node *) 로 하게 된다면, 메모리 해제를 까먹고 하지 않을 경우 혹은 예외가 발생하였을 경우 적절하게 
자원을 해제하기 어렵다. 물론 이미 해제된 메모리를 계속 가리키고 있을 위험도 있다. 
2) 하지만 이를 shared_ptr 로 하게 된다면 앞서 본 순환 참조 문제가 생긴다. 부모와 자식이 서로를 가리키기 때문에 참조 개수가
절대로 0 이 될 수 없다. 따라서, 이들 객체들은 프로그램이 끝날 때까지 절대로 소멸되지 못하고 남아있게 된다. 

seak_ptr 는 일반 포인터와 shared_ptr 사이에 위치한 스마트 포인터로, 스마트 포인터처럼 객체를 안전하게 참조할 수 있게 해주지만,
shared_ptr 와는 다르게 참조 개수를 늘리지는 않는다. 이름 그대로 '약한 포인터' 인 것이다. 
따라서 설사 어떤 객체를 weak_ptr 가 가리키고 있다 하더라도, 다른 shared_ptr 들이 가리키고 있지 않다면 이미 메모리에서 소멸되었을
것이다. 이 때문에 weak_ptr 자체로는 원래 객체를 참조할 수 없고, 반드시 shared_ptr 로 변환해서 사용해야 한다. 이때 가리키고 있는 
객체가 이미 소멸되었다면 빈 shared_ptr 로 변환되고, 아닐 경우 해당 객체를 가리키는 shared_ptr 로 변환된다. 
아래 예제를 통해 weak_ptr 을 어떻게 활용할 수 있는지 알아보자. */


#include <iostream>
#include <memory>
#include <string>
#include <vector>

/* 이 코드는 C++ 의 스마트 포인터, 특히 std::shared_ptr 와 std::weak_ptr 를 사용하여 
자원 관리 및 객체의 소멸을 다루는 예제를 보여준다. */
class A {
    std::string s;              /* 객체의 이름이나 데이터를 저장하는 문자열이다. */
    std::weak_ptr<A> other;     /* weak_ptr 사용!! 
                                다른 A 객체를 가리키는 약한 포인터이다. 이는 shared_ptr 의 소유권을 가지지 않고, 참조만 한다. */

    public:
    // 생성자
    A(const std::string& s) : s(s) { std::cout << "자원을 획득함!!" << std::endl; } /* 이 줄은 생성자에서 문자열 s 를 초기화하고, "자원을 획득함!!" 이라는 메시지를 출력한다. */

    // 소멸자
    ~A() { std::cout << "소멸자 호출!!" << std::endl; } /* ~A() : 소멸자가 호출되면 "소멸자 호출!!" 이라는 메시지를 출력하여 객체가 소멸됨을 알린다. */

    // 메서드
    void set_other(std::weak_ptr<A> o) { other = o; }   /* 이 줄은 other 에 다른 A 객체의 약한 포인터를 설정한다. */
    void access_other() {   /* other 를 통해서 다른 객체에 접근한다. 
                            other.lock() 을 호출하여 해당 객체의 shared_ptr 을 얻으려고 시도하며, 객체가 여전히 존재하면
                            그 객체의 이름을 출력한다. 
                            객체가 소멸된 경우에는 "이미 소멸됨 ㅠㅠ" 라는 메시지를 출력한다. */
        std::shared_ptr<A> o = other.lock(); // --> 실제 weak_ptr 를 shared_ptr 로 변환하는 과정(lock 함수를 통한 수행!!)
        /* weak_ptr 에 정의된 lock 함수는 만일 weak_ptr 가 가리키는 객체가 아직 메모리에서 살아있다면(= 즉 참조 개수가 0 이 아니라면)
        해당 객체를 가리키는 shared_ptr 을 반환하고, 이미 해제가 되었다면 아무것도 가리키지 않는 shared_ptr 을 반환한다. */
        if (o) {
            std::cout << "접근: " << o->name() << std::endl;
        } else {
            std::cout << "이미 소멸됨 ㅠㅠ" << std::endl;
        }
    }
    std::string name() { return s; }    /* 이 줄은 객체의 이름을 반환한다. */
};

int main() {
    std::vector<std::shared_ptr<A>> vec;    /* 이 줄은 백터를 생성한다. 
                                            A 객체의 shared_ptr 을 저장할 벡터를 생성한다. */
    vec.push_back(std::make_shared<A>("자원 1"));
    vec.push_back(std::make_shared<A>("자원 2"));   /* 두 개의 A 객체를 생성하고 벡터에 추가한다. */

    vec[0]->set_other(vec[1]);  /* 첫번째 객체가 두번째 객체를 약한 포인터로 참조하도록 설정한다. */
    vec[1]->set_other(vec[0]);  /* 두번째 객체가 첫번째 객체를 약한 포인터로 참조하도록 설정한다. */
    /* set_other 함수는 weak_ptr<A> 를 인자로 받고 있었는데, 여기에 shared_ptr 을 전달하였다.
    즉, weak_ptr 는 생성자로 shared_ptr 나 다른 weak_ptr 를 받는다. 또한 shared_ptr 과는 다르게,
    이미 제어 블록이 만들어진 객체만이 의미를 가지기 때문에, 평범한 포인터 주소값으로 weak_ptr 를 생성할 수는 없다. */

    // pa 와 pb 의 ref count 는 그대로이다.
    std::cout << "vec[0] ref count : " << vec[0].use_count() << std::endl;  /* 참조 카운트 출력 */
    std::cout << "vec[1] ref count : " << vec[1].use_count() << std::endl;  /* 두 객체의 shared_ptr 참조 카운트를 출력한다. 
                                                                            weak_ptr 은 참조 카운트에 영향을 미치지 않기 때문에
                                                                            여전히 두 객체의 카운트는 1 이다. */

    // weak_ptr 로 해당 객체 접근하기
    vec[0]->access_other(); /* 약한 포인터를 통해 접근:
                            첫번째 객체를 통해 두번째 객체에 접근한다. 
                            두번째 객체가 여전히 살아있으므로 이름을 출력한다. */

    // 벡터 마지막 원소 제거(vec[1] 소멸)
    vec.pop_back(); /* 벡터에서 마지막 원소 제거:
                    벡터에서 마지막 원소(두번째 객체) 를 제거한다. 이로 인해 두번째 객체의 
                    shared_ptr 참조 카운트가 0 이 되어 소멸되고, 소멸자 호출 메시지가 출력된다. */
    vec[0]->access_other(); /* 다시 약한 포인터 접근: 
                            이제 첫번째 객체에서 두번째 객체에 접근하려고 시도한다. 그러나 두번째 객체는 
                            소멸되었으므로 "이미 소멸됨 ㅠㅠ" 라는 메시지가 출력된다. */
}


/* 생각해보기- 문제 */
/* 문제 1:
가계도를 관리하는 라이브러리를 만들어보아라. 기본적으로 다음과 같이 생겼을 것이다. (난이도: 상) */
class Member {
    private:
    std::vector<std::shared_ptr<Member>> children;
    std::vector<std::weak_ptr<Member>> parents;
    std::vector<std::weak_ptr<Member>> spouse;

    public:
    void AddParent(const std::shared_ptr<Member>& parent);
    void AddSpouse(const std::shared_ptr<Member>& spouse);
    void AddChildren(const std::shared_ptr<Member>& child);
};
class FamilyTree {
    private:
    std::vector<std::shared_ptr<Member>> entire_family;

    public:
    // 두 사람 사이의 촌수를 계산한다. 
    int CalculateChon(Member* mem1, Member* mem2);
};


/* 함수 객체 */
/* 지난 강좌에서 배운 스마트 포인터 삼형제(unique_ptr, shard_ptr, weak_ptr) 과 같은 스마트 포인터를 도입함으로써 
C++ 에서 메모리 제어를 훨씬 더 쉽게 수행할 수 있었다. 
이번 강좌에서는 C++ 에서 호출 가능한 모든 것을 포괄해서 나타내는 Callable 에 대해서 알아보도록 할 것이다. 이번 강좌는
다음 강좌에서 쓰레드를 배우기 전에 짧게 거쳐가는 징검다리라고 보면 된다. */

/* Callable */
/* Callabel 이란, 이름 그대로 나타내듯이 '호출(Call)' 할 수 있는 모든 것을 의미한다. 
대표적인 예시로 함수를 들 수 있다. 
하지만 C++ 에서는 () 를 붙여서 호출할 수 있는 모든 것을 Callable 이라고 정의한다. 예를 들어서 */
#include <iostream>

struct S {
    void operator()(int a, int b) { std::cout << "a + b = " << a + b << std::endl; }
};

int main() {
    S some_obj;

    some_obj(3, 5);
    /* 해당 코드를 성공적으로 컴파일하였다면 결과는 아래와 같다.
    a + b = 8
    그렇다면 여기서 same_obj 는 함수일까?? 아니다. same_obj 는 same_obj 클래스 S 의 객체이다. 
    그러나 same_obj 는 마치 함수처럼 () 를 이용한 호출이 가능하다. --> "Callabel"!!!!!!
    (실제로는 same_obj.operator()(3, 5) 를 한 것이다.) */
}


/* 또 다른 예시로 람다 함수를 생각해보자. */
#include <iostream>
int main() {
    auto f = [](int a, int b) { std::cout << "a + b = " << a + b << std::endl; };
    f(3, 5);
    /* 해당 코드 역시 출력하면 위와 같은 결과인 "a + b = 8" 가 출력된다. 
    f 역시 일반적인 함수의 모습을 하고 ㅣㅇㅆ지는 않지만, () 를 통해서 호출할 수 있기에 
    Callable 이라 할 수 있다. */
}


/* std::function */
/* C++ 에서는 이러한 Callable 들을 객체의 형태로 보관할 수 있는 std::function 이라는 클래스를 제공한다. 
C 에서의 함수 포인터는 진짜 함수들만 보관할 수 있는 객체라고 볼 수 있다면, 이 std::function 의 경우 함수
뿐만이 아니라 모든 Callable 들을 보관할 수 있는 객체이다. 
이 std::function 을 어떻게 사용할 수 있는지 아래의 예시를 보자. */
#include <functional>
#include <iostream>
#include <string>

int some_func1(const std::string& a) {
    std::cout << "Func1 호출!! " << a << std::endl;
    return 0;
}

struct S {
    void operator()(char c) { std::cout << "Func2 호출!! " << c << std::endl; }
};

int main() {
    // 객체를 정의하는 부분
    std::function<int(const std::string&)> f1 = some_func1;
    std::function<void(char)> f2 = S();
    std::function<void()> f3 = []() { std::cout << "Func3 호출!! " << std::endl; };
    /* function 객체는 템플릿 인자로 전달 받을 함수의 타입을 갖게 된다. 여기서 함수의 타입이라 하면,
    리턴값과 함수의 인자들을 말한다. 따라서 예를 들어 some_func1 의 경우 int 를 리턴하며, 인자로 
    const string& 을 받기 때문에 위와 같이 std::function<int(const string&)> 의 형태로 정의된다. 
    한편 Functor 인 클래스 S 의 객체의 경우, 단순히 S 의 객체를 전달해도 이를 마치 함수인 양 받게 된다. 
    S 의 경우, operator() 가 인자로 char 을 받고 리턴 타입이 void 이므로 std::function<void(char)> 의 꼴로
    표현할 수 있게 된다. 
    마지막으로 람다 함수의 경우 마찬가지로 리턴값이 없고 인자를 받지 않기 때문에 std::function<void()> 로 정의된다. */

    f1("hello");
    f2('c');
    f3();
}
/* 이렇듯 std::function 은 C++ 의 모든 Callable 을 마음대로 보관할 수 있는 유용한 객체이다. 
만약에 함수 포인터로 이를 구현하려고 했다면 Functor 와 같은 경우를 성공적으로 보관할 수 없었을 것이다. */



/* 멤버 함수를 가지는 std::function */
/* 앞서 function 은 일반적인 Callable 들을 쉽게 보관할 수 있었지만, 멤버 함수들의 경우 이야기가 조금 달라진다.
왜냐하면, 멤버 함수 내에서 this 의 경우 자신을 호출한 객체를 의미하기 때문에, 만일 멤버 함수를 그냥 function 에
넣게 된다면 this 가 무엇인지 알 수 없는 문제가 발생하게 된다. 아래의 예시를 보자. */
#include <functional>
#include <iostream>
#include <string>

class A {
    int c;

    public:
    A(int c) : c(c) {}
    int some_func() { std::cout << "내부 데이터: " << c << std::endl; }
};

int main() {
    A a(5);
    std::function<int()> f1 = a.some_func;
    /* 해당 코드를 컴파일한다면, 컴파일 오류가 발생하게 된다. 
    왜냐하면 f1 을 호출하였을 때, 함수의 입장에서는 자신을 호출하는 객체가 무엇인지 알 길이 없기 때문이다.
    따라서 c 를 참조하였을 때 어떤 객체의 c 인지를 알 수 없을 것이다. 그러므로 이 경우 f1 에 a 에 관한
    정보도 추가로 전달해야 한다. 
    그렇다면 이를 어떻게 할까?? 사실 멤버 함수들은 구현 상 자신을 호출한 객체를 인자로 암묵적으로 받고 있었다. 
    따라서 이를 받는 function 은 아래와 같은 형태로 나타나야 한다. */
}


/* function 의 형태 */
#include <functional>
#include <iostream>
#include <string>

class A {
    int c;

    public:
    A(int c) : c(c) {}
    int some_func() {
        std::cout << "비상수 함수: " << ++c << std::endl;
        /* 전위 증가 연산자 ++c : 값을 먼저 1 만큼 증가시킨 후에, 증가된 값을 사용한다. */
        return c;
    }

    int some_const_function() const {
        std::cout << "상수 함수: " << c << std::endl;
        return c;
    }

    static void st() {}
};

int main() {
    A a(5);
    std::function<int(A&)> f1 = &A::some_func;
    std::function<int(const A&)> f2 = &A::some_const_function;

    f1(a);
    f2(a);
}


/* 멤버 함수들을 함수 객체로-mem_fn */
/* 예를 들어서 vector 들을 가지는 vector 가 있을 때, 각각의 vector 들의 크기들을 벡터로 만들어주는 코드를 생각해보자. */
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> a(1);
    vector<int> b(2);
    vector<int> c(3);
    vector<int> d(4);

    vector<vector<int>> container;
    container.push_back(b);
    container.push_back(d);
    container.push_back(a);
    container.push_back(c);

    vector<int> size_vec(4);
    std::transform(container.begin(), container.end(), size_vec.begin(),
            &vector<int>::size);
    for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
        std::cout << "벡터 크기:: " << *itr << std::endl;
    }
    /* 해당 함수를 컴파일하면 컴파일 오류가 발생한다. 이는 전달된 size 함수가 멤버 함수여서 
    발생하는 문제이다. 위 템플릿에 &vector<int>::size 가 들어간다면 해당 unary_op 를 호출하는
    부분은 아래와 같이 변환된다. 
    unary_op(*first1);
    가 
    &vector<int>::size(*first);
    꼴로 되는데, 멤버 함수의 경우
    (*first).(*&vector<int>::size)
    혹은
    first->(*&vector<int>::size)
    와 같이 호출해야 하기 때문이다. 따라서 이를 위해서는 제대로 std::function 으로 변환해서 전달해주어야 한다. */
}


/* 제대로 std::function 으로 변환&전달하는 코드 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using std::vector;

int main() {
    vector<int> a(1);
    vector<int> b(2);
    vector<int> c(3);
    vector<int> d(4);

    vector<vector<int>> container;
    container.push_back(a);
    container.push_back(b);
    container.push_back(c);
    container.push_back(d);

    std::function<size_t(const vector<int>&)> sz_func = &vector<int>::size; // sz_func 를 &vector<int>::size 대신 넣기 위한 작업!!

    vector<int> size_vec(4);
    std::transform(container.begin(), container.end(), size_vec.begin(), sz_func);  // &vector<int>::size 대신 sz_func 를 넣음!! 
    for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
        std::cout << "벡터 크기:: " << *itr << std::endl;
    }
    /* 해당 소스코드를 출력하면 결과는 다음과 같이 성공적으로 출력된다. 
    벡터 크기:: 1
    벡터 크기:: 2
    벡터 크기:: 3
    벡터 크기:: 4
    하지만 매번 위처럼 function 객체를 따로 만들어서 전달하는 것은 매우 귀찮다. 
    따라서 C++ 개발자들은 라이브러리에 위 function 객체를 리턴해버리는 함수를 추가하였다. */
}


/* 라이브러리에 function 객체를 리턴하는 함수 추가 버전!! */
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using std::vector;

int main() {
    vector<int> a(1);
    vector<int> b(2);
    vector<int> c(3);
    vector<int> d(4);

    vector<vector<int>> container;
    container.push_back(a);
    container.push_back(b);
    container.push_back(c);
    container.push_back(d);

    vector<int> size_vec(4);
    transform(container.begin(), container.end(), size_vec.begin(),
            std::mem_fn(&vector<int>::size));       /* mem_fn 함수는 이름 그대로, 전달된 멤버 함수를 function 객체로 예쁘게 만들어서 리턴해준다. */
    for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
        std::cout << "벡터 크기:: " << *itr << std::endl;
    }
    /* 주의 사항: 참고로 mem_fn 은 그리 자주 쓰이지는 않는데, 람다 함수로도 동일한 작업을 수행할 수 있기 때문이다. 
    위 코드의 경우 mem_fn(&vcector<int>::size) 대신에 [](const auto&v){ return v.size() } 를 전달해도 동일한 작업을 수행한다.
    mem_fn 을 사용하기 위해서는 <functional> 헤더를 추가해야 하지만 람다 함수는 그냥 쓸 수 있으니 좀 더 편리한 면이 있다.
    물론, 코드 길이의 면에서는 mem_fn 을 사용하는 것이 좀 더 깔끔한 편이다. */
}


/* std::bind */
/* 재미있게도 함수 객체 생성 시에 인자를 특정한 것으로 지정할 수도 있다. */
#include <functional>
#include <iostream>

/* 해당 코드는 C++ 의 std::bind 를 사용하여 함수의 인자를 바인딩하는 방법을 보여준다. 
std::bind 를 사용하면 특정 인자를 고정하고, 나머지 인자를 나중에 전달하여 함수를 쉽게 호출할 수 있다. */
void add(int x, int y) {    // 두 개의 정수 x, y 를 더하고 결과를 출력한다. 
    std::cout << x << " + " << y << " = " <<  x + y << std::endl;
}

void subtract(int x, int y) {   // 두 개의 정수 x, y 를 빼고 결과를 출력한다.
    std::cout << x << " - " << y << " = " << x - y << std::endl;
}
int main() {
    auto add_with_2 = std::bind(add, 2, std::placeholders::_1); /* add_with_2 생성 : 
                                                                std::bind 를 사용하여 add 함수의 첫 번째 인자를 2 로 고정하고, 
                                                                두 번째 인자는 나중에 전달할 수 있도록 한다. 
                                                                std::placeholders::_1 은 나중에 호출할 때 전달될 인자를 나타낸다. */
    add_with_2(3);  /* add_with_2(3) 을 호출하면, add 함수는 2 와 3 을 인자로 사용하여 실행된다. */

    // 두번째 인자는 무시된다. 
    add_with_2(3, 4);   /* 이 호출에서 두 번째 인자는 무시된다. add_with_2 는 항상 2 와 _1 자리 표시자만 사용한다. */

    auto subtract_from_2 = std::bind(subtract, std::placeholders::_1, 2);   /* 여기서는 subtract 함수의 두 번째 인자를 2 로 고정한다. */
    auto negate = 
        std::bind(subtract, std::placeholders::_2, std::placeholders::_1);  /* negate 는 두 개의 인자를 받아서 subtract 를 호출한다. 이때 첫번째
                                                                            인자는 두 번째 인자로, 두 번째 인자는 첫 번째 인자로 전달된다. 즉, 순서가
                                                                            바뀌어 실행된다. */

    subtract_from_2(3); // 3 - 2 를 계산한다. --> 결과는 1
    negate(4, 2);       // 2 - 4 를 계산한다. --> 결과는 -2
    /* 해당 코드를 성공적으로 컴파일하면 결과는 아래와 같다.
    2 + 3 = 5
    2 + 3 = 5
    3 - 2 = 1
    2 - 4 = -2
     */
}
/* bind 함수는 이름 그대로 원래 함수에 특정 인자를 붙여(bind) 준다. 예를 들어서 
    std::bind(add, 2, std::placeholders::_1);
    위 예시의 경우 add 라는 함수에 첫 번째 인자로 2 를 bind 시켜주고, 두 번째 인자로는 새롭게 만들어진 함수 객체의 첫 번째 인자를 전달해준다. 
    따라서 
    add_with_2(3);
    를 하였을 때, 원래 add 함수의 첫 번째 인자로는 2 가 들어가게 되고, 두 번째 인자로는 add_with_2 의 첫 번째 인자인 3 이 들어갈 것이다. 
    만약에
    add_with_2(3, 4);
    처럼 인자를 여러 개 전달하더라도 뒤의 것들은 무시된다.
    auto negate = std::bind(subtract, std::placeholders:_2, std::placeholders::_1);
    과 같은 경우는 어떨까?? negate 함수는 첫 번째 인자와 두 번째 인자의 순서를 바꾸어서 subtract 함수를 호출하게 된다. 
    즉 negate(3, 5) 를 호출할 경우 실제로는 subtract(5, 3) 이 호출될 것이다. 
    
    한 가지 주의할 점은, 레퍼런스를 인자로 받는 함수들의 경우이다. */


    #include <functional>
#include <iostream>

struct S {
    int data;

    // 생성자 --> 인자를 받아서 data 초기화
    S(int data) : data(data) { std::cout << "일반 생성자 호출!!" << std::endl; }

    // 복사 생성자 --> 다른 S 객체에서 데이터를 복사할 때 호출된다. 
    S(const S& s) {
        std::cout << "복사 생성자 호출!!" << std::endl;
        data = s.data;
    }

    // 이동 생성자 --> rvalue(우측값) 에서 데이터를 이동할 때 호출된다. 
    S(S&& s) {
        std::cout << "이동 생성자 호출!!" << std::endl;
        data = s.data;
    }
};

void do_something(S& s1, const S& s2) { s1.data = s2.data + 3; }    /* 첫번째 인자인 s1 을 두번째 인자인 s2 의 데이터에 3 을 더한 값으로 변경한다. 
                                                                    첫번째 인자는 비변경 레퍼런스이고, 두번째 인자는 상수 비변경 레퍼런스이다. */

int main() {
    S s1(1), s2(2); /* s1 은 1 로 초기화되고, s2 는 2 로 초기화된다. 각 객체에 대해 "일반 생성자 호출!!" 메시지가 두 번 출력된다. */

    std::cout << "Before : " << s1.data << std::endl;   /* 초기 상태 출력!! */

    // s1 이 그대로 전달된 것이 아니라 s1 의 복사본이 전달됨!!
    auto do_something_with_s1 = std::bind(do_something, s1, std::placeholders::_1); /* do_something 함수에 s1 의 복사본과 나중에 전달할 수 있는 자리 표시자 _1 을 바인딩한다. 
                                                                                    s1 은 do_something_with_s1 에 전달될 때 복사되므로, 원본 s1 은 영향을 받지 않는다. */
    do_something_with_s1(s2);   /* s2 를 인자로 전달하면, do_something 이 호출되고 s1 의 복사본이 사용되어 s1.data 는 여전히 1 로 남아있는다. 
                                복사 생성자가 호출되지만, s1 의 실제 데이터는 변하지 않는다. */

    std::cout << "After :: " << s1.data << std::endl;   /* 최종 상태 출력!!! */
    /* 해당 코드를 출력하게 되면 결과는 아래와 같다.
    일반 생성자 호출!!
    일반 생성자 호출!!
    Before : 1
    복사 생성자 호출!!
    After :: 1
    보시다시피 do_something 함수의 경우 첫 번째 인자의 data 를 두 번째 인자의 data + 3 으로 만들어주지만,
    실제로 do_something_with_s1 함수를 실행하였을 때 첫 번째 인자로 s1 을 전달했음에도 불구하고 s1 의 data 가
    바뀌지 않았음을 알 수 있다. 
    그 이유는 bind 함수로 인자가 '복사' 되어서 전달되기 때문이다. 따라서 이를 해결하기 위해서는 명시적으로 s1 의 
    레퍼런스를 전달해주어야 한다. (아래의 코드 참고!!!) */
}


/* 명시적으로 s1 의 레퍼런스를 전달해주는 코드!! */
#include <functional>
#include <iostream>

struct S {
    int data;
    S(int data) : data(data) { std::cout << "일반 생성자 호출!!" << std::endl; }
    S(const S& s) {
        std::cout << "복사 생성자 호출!!" << std::endl;
        data = s.data;
    }

    S(S&& s) {
        std::cout << "이동 생성자 호출!!" << std::endl;
        data = s.data;
    }
};

void do_something(S& s1, const S& s2) { s1.data = s2.data + 3; }

int main() {
    S s1(1), s2(2);

    std::cout << "Before : " << s1.data << std::endl;

    // s1 이 그대로 전달된 것이 아니라 s1 의 복사본이 전달됨!! 
    auto do_something_with_s1 =
        std::bind(do_something, std::ref(s1), std::placeholders::_1);
    do_something_with_s1(s2);

    std::cout << "After :: " << s1.data << std::endl;
    /* 해당 소스코드를 성공적으로 출력하게 되면 결과는 아래와 같음을 확인할 수 있다.
    일반 생성자 호출!!
    일반 생성자 호출!!
    Before : 1
    After :: 5
    실제로 s1 의 값이 잘 바뀌었음을 확인할 수 있다. ref 함수는 전달받은 인자를 복사 가능한 레퍼런스로 
    변환해준다. 따라서 bind 함수 안으로 s1 의 레퍼런스가 잘 전달될 수 있게 된다. 
    참고로 const 레퍼런스의 경우 cref 함수를 호출하면 된다. */
    /* function, mem_fn, bind 들을 적재적소에 잘 사용한다면 C++ 의 강력한 라이브러리를 좀 더 풍요롭게 사용할 수 있을 것이다. 
*/
}



/* C++ 쓰레드 */
/* 멀티 쓰레드 프로그램 */
/* CPU 코어에서 돌아가는 프로그램 단위를 '쓰레드(thread)' 라고 부른다.
즉, CPU 의 코어 하나에서는 한 번에 한 개의 쓰레드의 명령을 실행시키게 된다. 
한 개의 프로세스는 최소 한 개의 쓰레드로 이루어져 있으며, 여러 개의 쓰레드로 구성될 수 있게 된다. 
이렇게 여러 개의 쓰레드로 구성된 프로그램을 '멀티 쓰레드(multithread) 프로그램' 이라고 한다.
쓰레드와 프로세스의 가장 큰 차이점은, 프로세스들은 서로 메모리를 공유하지 않지만 쓰레드는 공유한다는 점이다. 
다시 말해, 프로세스 1 과 프로세스 2 가 있을 때, 프로세스 1 은 프로세스 2 의 메모리에 접근할 수 없고,
마찬가지로 프로세스 2 도 프로세스 1 의 메모리에 접근할 수 없다. 그렇지만 같은 프로세스 내의 쓰레드끼리는 
메모리를 공유하는 것이 가능하다. 
만일 한 프로세스 안에 쓰레드 1 과 쓰레드 2 가 있다면, 서로 같은 메모리를 공유하게 된다. 예컨대, 쓰레드 1과
쓰레드 2 가 같은 변수의 값에 접근할 수 있다. 
여태까지 우리가 작성한 프로그램들은 모두 한 개의 쓰레드로 구성된 싱글 쓰레드 프로그램이다. 하지만, 많은 프로그램
들이 멀티쓰레드 프로그램으로 구성되어 있는데, 맥에서 나오는 작업 관리자 사진의 우측 하단에 현재 시스템의 쓰레드
개수와 프로세스에서도 알 수 있듯이, 프로세스 개수는 348 개인데, 총 쓰레드 수는 1711 개로 써있다. 대량 프로세스
하나 당 5 개의 쓰레드들로 구성되어 있다고 생각하면 된다. */



/* CPU 의 코어는 한 개가 아니다. */
/* 피보나치 수열을 계산하는 프로그램 */
int main() {
    int bef = 1, cur = 1;
    // 물론 100 번째 피보나치 항을 구한다면 int 오버플로우가 나겠지만 일단 그 점은 무시하도록 하자.
    for (int i = 0; i < 98; i++) {
        int temp = cur;
        cur = cur + bef;
        bef = temp;
    }
    std::cout << "F100 : " << cur << std::endl;
}
/* 결과적으로, 이와 같은 방법으로 피보나치 수열을 계산하는 프로그램은 병렬화하는 것이 매우 까다롭다. 
이러한 문제가 발생하는 근본적인 이유는 어떠한 연산(연산 A) 을 수행하기 위해 다른 연산(연산 B) 의 결과가
필요하기 때문이라고 볼 수 있다. 이와 같은 상황을 A 가 B 에 의존(dependent) 한다고 한다. 
프로그램 논리 구조 상에서 연산들 간의 의존 관계가 많을수록 병렬화가 어려워지고, 반대로 다른 연산의 결과와 
관계없이 독립적으로 수행할 수 있는 구조가 많을수록 병렬화가 매우 쉬워진다. */


/* 대기시간이 긴 작업들 */
/* 인터넷에서 웹사이트들을 긁어오는 프로그램을 생각해보자. 아마 아래와 같은 구성을 띨 것이다. */
int main() {
    // 다운받으려는 웹사이트와 내용을 저장하는 앱
    for (auto itr = url_and_content.begin(); itr != url_and_content.end();
        ++itr) {
        const string& url = itr->first;

        // download 함수는 인자로 전달받은 url 에 있는 사이트를 다운받아 리턴한다. 
        itr->second = download(url);
        }
}

/* 이 임의로 만든 download 함수는 인자로 전달한 url 에 위치한 웹사이트를 다운받아서 리턴한다. 
문제는 우리의 CPU 처리 속도에 비해서 인터넷은 매우 느리다는 점이다. 
우리가 흔히 ping 이라고 부르는 것은, 내가 보낸 요청이 상대 서버에 도착해서 다시 나에게 돌아오는데 
걸리는 시간을 의미한다. 보통 우리나라 안에서 웹사이트에 요청을 보낼 시에 ping 이 30 밀리초 정도
나오고, 해외의 경우(예컨대 미국), 150 밀리초에서 멀면 300 밀리초까지 걸리게 된다. 이는 CPU 코어를 
비효율적으로 사용하는 셈이 된다. 
하지만 만일 download 함수를 호출하는 것을 여러 쓰레드에서 부르면 어떻게 될까??
이와 같이 처리하게 된다면 CPU 시간을 낭비하지 않고 효율적으로 작업을 처리할 수 있게 된다. */



/* C++ 에서 쓰레드 생성하기 */
/* 이전에는 C++ 표준에 쓰레드가 없어서, 각 플랫폼마다 다른 구현을 사용해야만 했다. 
하지만 C++ 11 에서부터 표준에 쓰레드가 추가되면서, 쓰레드 사용이 매우 편리해졌다. 
아래의 코드는 첫 번째 멀티 쓰레드 프로그램의 코드이다. */
// 내 생애 첫 쓰레드
#include <iostream>
#include <thread>
using std::thread;

/* func1, func2, func3 는 각각의 쓰레드에서 수행할 작업을 정의한 함수이다. 
    또한, 각 함수는 10 번 반복되며, 해당 쓰레드가 작동 중임을 출력한다. */
void func1() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 1 작동중!!\n";
    }
}

void func2() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 2 작동중!!\n";
    }
}

void func3() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 3 작동중!!\n";
    }
}

int main() {
    /* 각 쓰레드를 생성하고, func1, func2, func3 함수를 각각 실행하도록 설정한다. 
       thread 객체를 통해 쓰레드가 생성되며, 생성 즉시 함수가 병렬로 실행된다. */
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    /* 각각의 쓰레드가 종료될 때까지 메인 쓰레드가 기다리도록 하는 메서드이다. 
       join() 을 호출하지 않으면, 메인 쓰레드는 각 쓰레드의 작업이 완료되기 
       전에 종료될 수 있으므로 반드시 호출해주어야 한다. */
    t1.join();
    t2.join();
    t3.join();
    /* join 은 해당하는 쓰레드들이 실행을 종료하면 리턴하는 함수이다. 따라서 t1.join() 의 경우
    t1 이 종료하기 전까지 리턴하지 않는다. 
    그렇다면 만약에 t2 가 t1 보다 먼저 죵료된다면 어떨까?? 사실 상관없다. 
    t1.join() 이 끝나고 t2.join() 을 하였을 때 쓰레드 t2 가 이미 종료된 상태라면 바로 함수가 리턴하게 된다. */


    /* 이 프로그램은 세 개의 독립적인 쓰레드(t1, t2, t) 를 생성하여
    func1, func2, func3 함수에서 정의된 작업을 병렬로 실행한다. 
    각 쓰레드는 for 루프를 통해 10 번씩 반복하여 메시지를 출력한다. 
    join() 메서드를 통해 모든 쓰레드가 종료될 때까지 메인 쓰레드는 대기하게 된다.
    이렇게 하지 않으면 메인 쓰레드가 먼저 종료되면서, 쓰레드들이 작업을 완료하지 
    못할 수 있다. */

    /* 해당 코드를 vscode 에서 컴파일하면 제대로 컴파일되지 않지만, visual studio 에서 컴파일하면 
    정상적으로 컴파일되어서 교재와 동일한 결과가 출력된다!!! 주의하기 */
}



/* 만약에 join 을 하지 않는다면 어떨까?? */
#include <iostream>
#include <thread>
using std::thread;

void func1() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 1 작동중!!\n";
    }
}

void func2() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 2 작동중!!\n";
    }
}

void func3() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 3 작동중!!\n";
    }
}
int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    /* 해당 코드를 출력하면 쓰레드의 내용이 채 실행되기도 전에 main 함수가 종료되어서 
    쓰레드 객체들(t1, t2, t3) 의 소멸자가 호출되었음을 알 수 있다. 
    C++ 표준에 따르면, join 되거나 detach 되지 않는 쓰레드들의 소멸자가 호출된다면 예외를
    발생시키도록 명시되어 있다. 따라서, 우리의 쓰레드 객체들이 join 이나 detach 가 모두 
    되지 않았으므로 위와 같은 문제가 발생하게 된다.
    그렇다면 detach 는 무엇일까??
    detach 는 말 그대로, 해당 쓰레드를 실행시킨 후, 잊어버리는 것이라고 생각하면 된다.
    대신 쓰레드는 알아서 백그라운드에서 돌아가게 된다. 아래의 예제를 통해서 살펴보자. */
}


/* 예제 코드 */
#include <iostream>
#include <thread>
using std::thread;

void func1() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 1 작동중!!\n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 2 작동중!!\n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		std::cout << "쓰레드 3 작동중!!\n";
	}
}

int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.detach();
	t2.detach();
	t3.detach();
	std::cout << "메인 함수 종료\n";
	/* 해당 코드를 컴파일하면 다양한 결과가 나온다. 
	기본적으로 프로세스가 종료될 때, 해당 프로세스 안에 있는 모든 쓰레드들은 종료 여부와 상관없이
	자동으로 종료된다. 즉 main 함수에서 "메인 함수 종료!!" 를 출력하고 프로세스가 종료하게 되면, 
	func1, func2, func3 모두 더 이상 "쓰레드 작동중!!" 을 출력할 수 없게 된다. */
}


/* 쓰레드에 인자 전달하기 */
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end,
	int* result) {
	/* worker 함수는 주어진 벡터의 일정 구간의 합을 계산하고, 그 결과를 
	result 에 저장한다. 
	start 와 end 는 벡터의 구간을 가리키는 반복자이다. 이 구간의 모든 요소들을 더해 sum 에 젖아한다.
	결과는 *result 에 저장되며, 이 포인터는 메인 쓰레드에서 넘겨준 부분합을 저장하는 벡터의 한 요소를 가리킨다. 
	쓰레드 ID(thread::id this_id = std::this_thread::get_id()) 를 사용하여 현재 쓰레드의 ID 를 가져와, 
	계산 결과와 함께 출력한다. */
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) {
		sum += *itr;
	}
	*result = sum;

	// 쓰레드의 id 를 구한다.
	thread::id this_id = std::this_thread::get_id();
	printf("쓰레드%x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start,    /* std::cout 대신에 printf 함수를 사용한 이유는 
                                                                                printf 가 "..." 안에 있는 문자열을 출력할 때 컨텍스트 스위치가 되더라도 다른 쓰레드들이 그 사이에 메세지를 집어넣지 못하게 막는다. 
                                                                                (std::cout 는 << 를 실행하는 과정 중간중간에 계속 실행되는 쓰레드들이 바뀌면서 결과적으로 메세지가 뒤섞여서 나타나게 된다.) */
		*(end - 1), sum);
}

int main() {
	vector<int> data(10000);	/* 벡터 초기화: 해당 줄은 0 부터 9999 까지의 정수로 구성된 벡터이다. */
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	// 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
	vector<int> partial_sums(4);	/* 부분합 저장을 위한 벡터: 해당 줄은 각 쓰레드가 계산한 부분합을 저장하기 위한 벡터로,
									총 4 개의 부분합을 저장한다. */

	vector<thread> workers;
	for (int i = 0; i < 4; i++) {	/* 쓰레드 생성 및 구간 할당: for 루프에서 4 개의 쓰레드를 생성하며,
									각 쓰레드가 worker 함수를 호출하여 벡터 data 의 2500 개씩의 구간을 
									계산하도록 한다. 
									각 쓰레드는 partial_sums[i] 에 그 결과를 저장한다. */
		workers.push_back(thread(worker, data.begin() + i * 2500,
			data.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();	/* 쓰레드 대기: join() 호출을 통해 모든 쓰레드가 작업을 완료할 때까지 메인 쓰레드가 기다린다. */
	}

	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];	/* 최종합계 계산: 4 개의 부분합을 모두 더해 전체 합을 출력한다. */
	}
	std::cout << "전체 합: " << total << std::endl;
	/* 해당 코드를 출력하면 결과는 아래와 같다.
	쓰레드da18 에서 5000 부터 7499 까지 계산한 결과 : 15623750
	쓰레드3fbc 에서 7500 부터 9999 까지 계산한 결과 : 21873750
	쓰레드ba6c 에서 2500 부터 4999 까지 계산한 결과 : 9373750
	쓰레드3458 에서 0 부터 2499 까지 계산한 결과 : 3123750
	전체 합: 49995000
	(순서는 섞여서 나올 수 있다!!!)
	*/

	/* 결과가 순서대로 출력되지 않는 이유: 
	'멀티쓰레딩의 비결정성' 때문!!! --> 각 쓰레드들은 운영체제(OS) 에 의해서 독립적으로 스케줄링된다. 
	즉, 쓰레드가 언제 시작하고 언제 종료될지는 OS 의 쓰레드 스케줄러가 결정한다. 
	쓰레드들이 병렬로 실행되기 때문에 어느 쓰레드가 먼저 실행되거나 완료될 지 예측할 수 없다. 
	각 쓰레드는 자신의 구간을 독립적으로 계산하므로, 결과 출력 순서도 제각각일 수 있다. 
	따라서 출력 결과는 실행될 때마다 순서가 달라질 수 있다. */

    /* 앞서 말했듯이 쓰레드들은 서로 메모리를 공유한다고 하였다. 실제로 각 쓰레드들에서 data 와 partial_sums 에 서로 접근할 수 있었다.(다른 부분이긴 했지만)
    그렇다면 만약 서로 다른 쓰레드들이 같은 메모리에 서로 접근하고 데이터를 사용한다면 어떠한 일이 발생할까?? (아래의 코드 참고!!! */
}




/* 메모리를 같이 접근한다면?? */
/* 아래의 예제 코드는 서로 다른 쓰레드들에서 counter 라는 변수의 값을 1 씩 계속 증가시키는 연산을 수행한다. */
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;

void worker(int& counter) {
	for (int i = 0; i < 10000; i++) {
		counter += 1;
	}
}

int main() {
	int counter = 0;

	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		//
		workers.push_back(thread(worker, std::ref(counter)));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	std::cout << "Counter 최종 값: " << counter << std::endl;
	/* 해당 코드를 출력하면 값이 계속 다르게 출력된다. */
}


/* 생각해보기-문제 */
/* 문제 1:
피보나치 수열을 멀티 쓰레딩을 활용해서 빠르게 계산할 수 있는 방법은 없을까?? */



/* 뮤텍스와 조건변수 */
/* 지난 강좌에서 다루었듯, 서로 다른 쓰레드에서 같은 메모리를 공유할 때 발생할 수 있는 문제를 보았다.
이와 같이 서로 다른 쓰레드들이 동일한 자원을 공유할 때 발생하는 문제를 경쟁상태(race condition) 이라고 부른다. 
이 경우, counter 라는 변수에 race condition 이 있었다. */

/* Race Condition */
#include <iostream>
#include <thread>
#include <vector>

void worker(int& counter) {
	for (int i = 0; i < 10000; i++) {
		counter += 1;
	}
}

int main() {
	int counter = 0; 

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) {
		// 레퍼런스로 전달하려면 ref 함수로 감싸야한다. (지난 강좌 bind 참조!!)
		workers.push_back(std::thread(worker, std::ref(counter)));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	std::cout << "Counter 최종 값: " << counter << std::endl;
	/* 해당 코드를 출력하면 우리의 예상과는 다른 값이 출력된다. 문제의 원인은 해당 코드 중
	counter += 1;
	라는 명령에 있다. 이 문제가 발생한 근본적인 이유는 이 명령을 여러 쓰레드에서 동시에 실행
	시켰기 때문이다. 
	이러한 문제를 해결하기 위해서는 어떤 경찰관 같은 역할을 하는 것이 있어서, 한 번에 한 쓰레드에서만 
	위의 코드를 실행시킬 수 있어야 한다. 그리고 C++ 에서는 이러한 역할을 하는 것이 '뮤텍스(Mutex)' 이다. */
}


/* 뮤텍스(mutex) */
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
	for (int i = 0; i < 10000; i++) {
		m.lock();	/* m.lock(* 은 뮤텍스 m 을 내가 쓰게 달라!! 라고 이야기하는 것이다. 
					이때 중요한 사실은, 한번에 한 쓰레드에서만 m 의 사용 권한을 갖는다는 것이다. 
					그렇다면, 다른 쓰레드에서 m.lock() 을 하였다면 어떻게 될까?? 이는 m 을 소유한
					쓰레드가 m.unlock() 을 통해 m 을 반환할 때까지 무한정 기다리게 된다. 
					따라서 result += 1; 은 아무리 많은 쓰레드들이 서로 다른 코어에서 돌아가고 있다고
					하더라도, 결국 m 은 한버에 한 쓰레드만 얻을 수 있기 때문에 , result += 1; 은 결국 
					한 쓰레드만 유일하게 실행할 수 있게 된다. */
		result += 1;
		m.unlock();
	}
}

int main() {
	int counter = 0;
	std::mutex m;	// 우리의 mutex 객체!!
	/* mutex 라는 단어는 영어의 상호 배제(mutual exclusion) 라는 단어에서 따온 단어이다. */

	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	std::cout << "Counter 최종 값 : " << counter << std::endl;
	/* 해당 코드를 성공적으로 출력하면 결과는 우리가 의도했던 대로 40000 이 나온다.
	Counter 최종 값 : 40000
	*/

	/* 해당 코드에 쓰인 m.lock() 과 m.unlock() 사이에 한 쓰레드만이 유일하게 실행할 수 있는 
	코드 부분을 '임계 영역(critical section)' 이라고 부른다. 
	만약에 까먹고 m.unlock() 을 하지 않는다면 발생하는 문제를 아래의 코드를 통해서 확인해보자.(아래의 코드 참고!!!) */
}


/* 예제 코드 */
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
    for (int i = 0; i < 10000; i++) {
        // lock 생성 시에 m.lock() 을 실행한다고 보면 된다. 
        std::lock_guard<std::mutex> lock(m);
        result += 1;

        // scope 를 빠져나가면 lock 이 소멸되면서 
        // m 을 알아서 unlock 한다. 
    }
}
int main() {
    int counter = 0;
    std::mutex m;   // 우리의 mutex 객체

    std::vector<std::thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    std::cout << "Counter 최종 값: " << counter << std::endl;
    /* 이 소스코드는 vscode 에서 컴파일하려고 하면 오류가 뜸...
    그래서 visual studio 에서 컴파일하기!!!(이 IDE 에서는 문제 없음!!)-->원래 문제 없는 게 맞긴 한데 어이없음. */
    /* 출력값은 아래와 같다.
    Counter 최종 값: 40000
    lock_guard 객체는 뮤텍스를 인자로 받아서 생성하게 되는데, 이 때 생성자에서 뮤텍스를 lock 하게 된다. 
    그리고 lock_guard 가 소멸될 때 알아서 lock 했던 뮤텍스를 unlock 하게 된다. 
    따라서 사용자가 따로 unlock 을 신경쓰지 않아도 되어서 매우 편리하다. 
    근데 lock_guard 만 있다면 이제 더이상 데드락 상호아은 신경쓰지 않아도 되는 것일까?? */
}


/* 데드락(deadlock) */
#include <iostream>
#include <mutex>
#include <thread>

void worker1(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock1(m1);
        std::lock_guard<std::mutex> lock2(m2);
        // Do something
    }
}

void worker2(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock2(m2);
        std::lock_guard<std::mutex> lock1(m1);
        // Do something
    }
}

int main() {
    int counter = 0;
    std::mutex m1, m2;

    std::thread t1(worker1, std::ref(m1), std::ref(m2));
    std::thread t2(worker2, std::ref(m2), std::ref(m2));

    t1.join();
    t2.join();

    std::cout << "끝!!" << std::endl;
    /* 해당 코드를 컴파일하게 되면 오류가 발생한다.
    (끝나지 않아서 강제 종료) 
    위의 문구와 같이, 프로그램이 끝나지 않아서 강제 종료해야만 한다. 
    이러한 오류가 발생한 이유는 worker1 과 worker2 에서 뮤텍스를 얻는 순서와 관련이 있다.
    worker1 에서는
    std::lock_guard<std::mutex> lock1(m1);
    std::lock_guard<std::mutex> lock2(m2);
    와 같이 m1 을 먼저 lock 한 후 m2 를 lock 하게 된다. 반면에 worker2 의 경우,
    std::lock_guard<std::mutex> lock2(m2);
    std::lock_guard<std::mutex> lock1(m1);
    과 같이 m2 를 먼저 lock 한 후 m1 을 lock 하게 된다. 
    
    이러한 데드락 상황을 해결하기 위한 수정 코드는 아래와 같다. (아래의 코드 참고!!) */
}


/* 데드락 해결 방법-예제 코드!! */
#include <iostream>
#include <mutex>
#include <thread>

void worker1(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10; i++) {
        m1.lock();
        m2.lock();
        std::cout << "Wordr1 Hi!!" << i << std::endl;

        m2.unlock();
        m1.unlock();
    }
}

void worker2(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10; i++) {
        while (true) {
            m2.lock();

            // m1 이 이미 lock 되어 있다면 "야 차 빼!!!!" 를 수행하게 된다. (m2 가 차를 빼야하는 상황인 것!!!)
            if (!m1.try_lock()) {
                m2.unlock();
                continue;
            }

            std::cout << "Worker2 Hi!!" << i << std::endl;
            m1.unlock();
            m2.unlock();
            break;
        }
    }
}

int main() {
    std::mutex m1, m2;

    std::thread t1(worker1, std::ref(m1), std::ref(m2));
    std::thread t2(worker2, std::ref(m1), std::ref(m2));

    t1.join();
    t2.join();

    std::cout << "끝!!!" << std::endl;
    /* 해당 코드를 출력해보면 데드락 상황 없이 잘 실행됨을 확인할 수 있다. */
}



/* C++ 에서 데드락 상황을 피하기 위한 가이드라인 */
/* 
1) 중첩된 LOCK 을 사용하는 것을 피해라.
: 모든 쓰레드들이 최대 1 개의 LOCK 만을 소유한다면 (일반적인 경우에) 데드락 상황이 발생하는 것을 피할 수 있다. 
또한 대부분의 디자인에서는 1 개의 LOCK 만으로도 충분하다. 만일 여러 개의 LOCK 을 필요로 한다면,
'정말 필요로 하는지' 를 되물어 보는 것이 좋다!!
2) LOCK 을 소유하고 있을 때 유저 코드를 호출하는 것을 피해라.
: 사실 이 가이드라인 역시 위에서 말한 내용과 자연스럽게 따라오는 것이긴 한데, 유저 코드에서 LOCK 을 소유할 수도 
있기에 중첩된 LOCK 을 얻는 것을 피하려면 LOCK 소유 시 유저 코드를 호출하는 것을 지양해야 한다. 
3) LOCK 들을 언제나 정해진 순서로 획득해라.
: 만일 여러 개의 LOCK 들을 획득해야 할 상황이 온다면, 반드시 이 LOCK 들을 정해진 순서로 획득해야 한다. 
우리가 앞선 예제에서 데드락이 발생했던 이유 역시, worder1 에서는 m1, m2 순으로 lock 하였지만 worker2 에서는 m2, m1 
순으로 lock 을 하였기 때문이다. 만일 worker2 에서 역시 m1, m2 순으로 lock 을 하였다면 데드락은 발생하지 않았을 것이다. */


/* 생산자(Producer) 와 소비자(Consumer) 패턴 */
/* 생산자-소비자 패턴은 멀티 쓰레드 프로그램에서 가장 많이 등장하는 패턴이다. 
생산자의 경우, 무언가 처리할 일을 받아오는 쓰레드를 의미한다. 예를 들어서, 우리가 인터넷에서
페이지를 긁어서 분석하는 프로그램을 만들었다고 생각해보자. 이 경우, 페이지를 긁어오는 쓰레드가
바로 '생산자' 가 될 것이다. 
'소비자' 의 경우, 받은 일을 처리하는 쓰레드를 의미한다. 앞선 예제의 경우 긁어온 페이지를 분석하는
쓰레드가 해당 역할을 하낟. 
그렇다면 아래의 예제로 이와 같은 상황을 쓰레드로 어떻게 구현할지 살펴보자. */


#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
    int index) {
    for (int i = 0; i < 5; i++) {
        // 웹사이트를 다운로드 하는데 걸리는 시간이라 생각하면 된다.
        // 각 쓰레드별로 다운로드 하는데 걸리는 시간이 다르다.
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
        std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" +
            std::to_string(index) + ")\n";

        // data 는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다. 
        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
    int* num_processed) {
    // 전체 처리하는 페이지 개수가 5 * 5 = 25 개.
    while (*num_processed < 25) {
        m->lock();
        // 만일 현재 다운로드한 페이지가 없다면 다시 대기.
        if (downloaded_pages->empty()) {
            m->unlock();    // (Quiz): 여기서 unlock 을 안한다면 어떻게 될까?? 

            // 10 밀리초 뒤에 다시 확인한다. 
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        // 맨 앞의 페이지를 읽고 대기 목록에서 제거한다. 
        std::string content = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_processed)++;
        m->unlock();

        // content 를 처리한다. 
        std::cout << content;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main() {
    // 현재 다운로드한 페이지 리스트로, 아직 처리하지 않은 것들이다. 
    std::queue<std::string> downloaded_pages;
    std::mutex m;

    std::vector<std::thread> producers;
    for (int i = 0; i < 5; i++) {
        producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
    }

    int num_processed = 0;
    std::vector<std::thread> consumers;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(
            std::thread(consumer, &downloaded_pages, &m, &num_processed));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }
    for (int i = 0; i < 3; i++) {
        consumers[i].join();
    }
    /* 해당 소스코드는 성공적으로 컴파일된다. (물론 visual studio 에서...)
    위 코드가 어떻게 생산자-소비자 패턴을 구현하였는지를 살펴보자.
    먼저 producer 쓰레드에서는 웹사이트에서 페이지를 계속 다운로드하는 역할을 하게 된다. 
    이때, 다운로드한 페이지들을 downloaded_pages 라는 큐에 저장하게 된다. 
    굳이 큐를 사용한 이유는 큐가 바로 먼저 들어온 것이 먼저 나간다는 특성을 가지고 있기 때문이다.
    쉽게 말해, 먼저 다운로드한 페이지를 먼저 처리하기 위함이다. 
    물론 vector 로 구현해도 상관은 없지만, vector 의 경우 가장 먼저 도착한 페이지가 벡터의 첫 번째
    원소로 있을 터인데 이를 제거하는 작업이 꽤나 느리기에 딱히 권장하지 않는 것일 뿐이다. 
    (맨 앞의 원소를 제거하면, 나머지 모든 원소들을 앞으로 한 칸씩 옮겨주어야 한다.)
    하지만 큐의 경우, 그 특성으로 인해서 해당 연산들이 매우 빠르게 이루어질 수 있다. */
}


/* condition_variable */
/* 위와 같은 조건들에서 쓰레드들을 10 밀리초마다 재웠다 깨우는 것을 반복할 수밖에 없었던 이유는 
'어떠어떠한 조건을 만족할 때까지 자라!!' 라는 명령을 내릴 수 없었기 때문이다. 
위의 경우, downloaded_pages 가 empty() 가 참이 아닐 때까지 자라는 명령을 하고 싶었을 것이다. 
이는 '조건 변수(condition_variable)' 을 통해 해결할 수 있다. */



#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
	int index, std::condition_variable* cv) {
	for (int i = 0; i < 5; i++) {
		// 웹사이트를 다운로드 하는데 걸리는 시간이라 생각하면 된다. 
		// 각 쓰레드 별로 다운로드 하는데 걸리는 시간이 다르다. 
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" +
			std::to_string(index) + ")\n";

		// data 는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다. 
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		// consumer 에게 content 가 준비되었음을 알린다. 
		cv->notify_one();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
	int* num_processed, std::condition_variable* cv) {
	while (*num_processed < 25) {
		std::unique_lock<std::mutex> lk(*m);

		cv->wait(
			lk, [&] { return !downloaded_pages->empty() || *num_processed == 25;  });

		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		// 맨 앞의 페이지를 읽고 대기 목록에서 제거한다. 
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		// content 를 처리한다.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() {
	// 현재 다운로드한 페이지들 리스트로, 아직 처리되지 않은 것들이다. 
	std::queue<std::string> downloaded_pages;
	std::mutex m;
	std::condition_variable cv;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.push_back(
			std::thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0; 
	std::vector<std::thread> consumers;
	for (int i = 0; i < 3; i++) {
		consumers.push_back(
			std::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}

	for (int i = 0; i < 5; i++) {
		producers[i].join();
	}

	// 나머지 자고 있는 쓰레드들을 모두 깨운다. 
	cv.notify_all();

	for (int i = 0; i < 3; i++) {
		consumers[i].join();
	}
}


/* 생각해보기-문제 */
/* 문제 1:
condition_variable 에서 wait 말고도 wait_for 과 wait_until 이라는 다른 유용한 함수들이 있다. 
(읽어보기!!) - 교재766페이지 */








/* 교재 767 페이지~: 좀 어렵고 배우는 데 필수적인 내용은 아니므로 처음 배우는 사람들은 넘어가도 ok!! */









/* 비동기 연산을 위한 도구들 */

/* 동기(synchronous) 와 비동기 실행(asynchronous) */
/* 자바스크립트로 프로그램을 짜본 경험이 있는 사람들은 비동기작업(asynchronous) 라는 단어를
수없이 들어봤을 것이다. 
이를 간단하게 설명하면 다음과 같다. 
예를 들어서 우리가 하드 디스크에서 파일을 읽는다고 생각해보자. SSD 가 아니라 하드디스크를 사용
한다면 임의의 위치에 쓰여져 있느 파일을 읽는데 시간이 상당히 오래 걸릴 것이다. 왜냐하면 하드디스크의
경우 '헤드' 라고 부르는 장치가 디스크에 파일이 쓰여져 있는 실제 위치까지 가야 하기 때문이다. 
이는 하드디스크에 있는 모터가 디스크를 돌려서 헤드를 정해진 구역에 위치시킨다. 

한 번에 하나씩 순차적으로 실행되는 작업을 '동기적(synchronous)' 으로 실행된다고 말한다. 
동기적인 작업들은 한 작업이 끝날 때까지 다음 작업으로 이동하지 않기 때문이다. 
만일 read 함수가 CPU 를 계속 사용한다면, 동기적으로 작업을 수행해도 문제될 것은 없다. 하지만
실제로는 read 함수가 하드 디스크에서 데이터를 읽어오는 동안 CPU 는 아무런 작업도 하지 않기 
때문에, 그 시간에 오히려 CPU 를 놀리지 않고 do_other_computation 과 같은 작업을 수행하는 게 
더 바람직하다. (더 효율적이라는 의미) 
그렇다면 이를 C++ 에서는 어떻게 구현할 수 있을까?? 아마 쓰레드를 배운 사람들은 아래와 같은 코드를
짤 수 있을 것이다. */
void file_read(string* result) {
    string txt = read("a.txt");
    *result = do_something_with_txt(txt);
}

int main() {
    string result;
    thread t(file_read, &result);
    do_other_computation();

    t.join();
}
/* 위 코드의 수행시간은 어떻게 될까?? 예를 들어서 쓰레드 t 를 생성한 뒤에 바로 새로운 쓰레드에서 
file_read 함수를 실행한다고 해보자.
file_read 함수 안에서 read("a.txt") 가 실행되는데, 이때 CPU 는 하드 디스크에서 데이터를 기다리지
않고, 바로 다시 원래 main 함수 쓰레드로 넘어와서 do_other_computatio() 을 수행하게 된다. 
5 밀리초 후에 do_other_computation() 이 끝나게 된다면, t.join 을 수행하면서 다시 file_read 쓰레드를
실행할 텐데, 이미 하드 디스크에서 a.txt 파일의 내용이 도착해있을 것이므로 do_someting_with_txt 를 바로 
실행하게 된다. 이 경우, 총 5 + 5 = 10 밀리초만에 수행이 끝나게 된다. CPU 는 단 한 순간도 놀지 않았다.
이와 같이 프로그램의 실행이, 한 갈래가 아니라 여러 갈래로 갈라져서 동시에 진행되는 것을 '비동기적
(asynchronous) 실행' 이라고 부른다. 자바스크립트와 같은 언어들은 언어 차원에서 비동기적 실행을 지원하지만,
C++ 의 경우 위와 같이 명시적으로 쓰레드를 생성해서 적절히 수행해야 했었다. 
하지만 C++ 11 표준 라이브러리를 통해 매우 간단하게 비동기적 실행을 할 수 있게 해주는 도구를 제공하고 있다. */


/* std::promise 와 std::future */
/* 결국 비동기적 실행으로 하고 싶은 일은, 어떠한 데이터를 다른 쓰레드를 통해 처리해서 받아내는 것이다.
내가 어떤 쓰레드 T 를 사용해서 비동기적으로 값을 받아내겠다는 의미는, 미래에(future) 쓰레드 T 가 원하는
데이터를 돌려주겠다는 약속(promise) 라고 볼 수 있다.
이 문장을 그대로 코드로 옮겨보면 아래의 코드와 같다. */
#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) {
    // 약속을 이행하는 모습. 해당 결과는 future 에 들어간다. 
    p->set_value("some data");
}
int main() {
    std::promise<string> p;

    // 미래에 string 데이터를 돌려 주겠다는 약속.
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    // 미래에 약속된 데이터를 받을 때까지 기다린다. 
    data.wait();

    // wait 이 리턴했다는 뜻이 future 에 데이터가 준비되었다는 의미.
    // 참고로 wait 없이 그냥 get 해도 wait 한 것과 같다. 
    std::cout << "받은 데이터 : " << data.get() << std::endl;

    t.join();
    /* 해당 코드를 컴파일하면 성공적으로 결과가 출력됨을 확인할 수 있다. 
    정리해보자면, promise 는 생산자-소비자 패턴에서 마치 생산자(promise) 의 역할을 수행하고, 
    future 는 소비자(consumer) 의 역할을 수행한다고 보면 된다. 
    따라서 아래와 같이 조건 변수를 통해서도 promise-future 패턴을 구현할 수 있다. */
}



#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::condition_variable cv;
std::mutex m;
bool done = false;
std::string info;

void worker() {
    {
        std::lock_guard<std::mutex> lk(m);
        info = "some data";     // 위의 p->set_value("some data") 에 대응
        done = true;
    }
    cv.notify_all();
}

int main() {
    std::thread t(worker);

    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] { return done; });       // 위의 data.wait() 이라 보면 된다. 
    lk.unlock();

    std::cout << "받은 데이터: " << info << std::endl;

    t.join();
    /* 해당 코드를 성공적으로 출력하면 다음과 같이 결과가 출력된다. 
    받은 데이터: some data
    이와 같이 조건 변수를 통해서도 promise-future 패턴을 구현할 수 있다.
    하지만, promise 와 future 를 이용하는 것이 훨씬 더 깔끔하고 더 이해하기도 쉽다.
    또한 위 조건 변수를 사용한 것보다 더 우수한 점은 future 에 예외도 전달할 수 있기
    때문이다. 예를 들어서 아래와 같은 코드를 살펴보자. */
}


#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>
using std::string;

void worker(std::promise<string>* p) {
	try {
		throw std::runtime_error("Some Error!!");
	}
	catch (...) {
		// set_exception 에는 exception_ptr 를 전달해야 한다. 
		p->set_exception(std::current_exception());
	}
}
int main() {
	std::promise<string> p;

	// 미래에 string 데이터를 돌려주겠다는 약속.
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);

	// 미래에 약속된 데이터를 받을 때까지 기다린다. 
	data.wait();

	try {
		data.get();
	}
	catch (const std::exception& e) {
		std::cout << "예외: " << e.what() << std::endl;
	}
	t.join();
	/* 해당 코드를 성공적으로 컴파일하면 결과는 아래와 같다. 
	예외: Some Error!!
	*/
	/* 참고로 set_exception 에는 예외 객체가 아니라 exception_ptr 을 전달해야 한다. 
	이 exception_ptr 는 catch 로 받은 예외 객체의 포인터가 아니라, 현재 catch 된 
	예외에 관한 정보를 반환하는 current_exception 함수가 리턴하는 객체이다. 
	물론 catch 로 전달받은 예외 객체를 make_exception_ptr 함수를 사용해서 exception_ptr 로
	만들 수도 있지만, 그냥 편하게 current_exception 을 호출하는 것이 더 간단하다. */
}


/* wait_for */
/* 그냥 wait 을 하였다면 promise 가 future 에 전달할 때까지 기다리게 된다.
하지만 wait_for 을 사용하면, 정해진 시간 동안만 기다리고 그냥 진행할 수 있다. */
#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

void worker(std::promise<void>* p) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    p->set_value();
}
int main() {
    // void 의 경우 어떠한 객체도 전달하지 않지만, future 가 set 이 되었나
    // 안되었느냐의 유무로 마치 플래그의 역할을 수행할 수 있다. 
    std::promise<void> p;

    // 미래에 string 데이터를 돌려 주겠다는 약속.
    std::future<void> data = p.get_future();

    std::thread t(worker, &p);
    // 미래에 약속된 데이터를 받을 때까지 기다린다. 
    while (true) {
        std::future_status status = data.wait_for(std::chrono::seconds(1));

        // 아직 준비가 안됨.
        if (status == std::future_status::timeout) {
            std::cerr << ">";
        }
        // promise 가 future 를 설정함.
        else if (status == std::future_status::ready) {
            break;
        }
    }
    t.join();
    /* 해당 코드는 성공적으로 컴파일된다. 
    wait_for 함수는 promise 가 설정될 때까지 기다리는 대신에 wait_for 에 전달된 시간만큼 기다렸다가 바로 리턴해버린다. 
    이때 리턴하는 값은 현재 future 의 상태를 나타내는 future_statur 객체이다. 
    future_statur 는 총 3 가지 상태를 가질 수 있다. 먼저 future 에 값이 설정되었을 때 나타나는 future_statur::ready 가 있고,
    wait_for 에 지정한 시간이 지났지만 값이 설정되지 않아서 리턴한 경우에는 future_status::timeout 이 리턴된다. 
    
    마지막으로 future_status::deferred 가 있는데, 이는 결과값을 계산하는 함수가 채 실행되지 않았다는 의미인데, 뒤에서
    좀 더 자세하게 다루도록 할 것이다. */
}



/* shared_future */
/* 앞서 future 의 경우, 딱 한 번만 get 을 할 수 있다고 했다. 왜냐하면 get 을 호출하면
future 내부의 객체가 이동되기 때문이다. 하지만, 종종 여러 개의 다른 쓰레드에서 future
를 get 할 필요성이 있다. 
이 경우 shared_future 를 사용하면 된다. 아래 예제는 달리기를 하는 것ㅇ르 C++ 프로그램으로 
나타내본 것이다. main 함수에서 출발 신호를 보내면 각 runner 쓰레드들에서 달리기를 시작하게 된다. */

#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using std::thread;

void runner(std::shared_future<void>* start) {
	start->get();
	std::cout << "출발!!" << std::endl;
}

int main() {
	std::promise<void> p;
	std::shared_future<void> start = p.get_future();

	thread t1(runner, &start);
	thread t2(runner, &start);
	thread t3(runner, &start);
	thread t4(runner, &start);

	// 참고로 cerr 는 std::cout 과는 다르게 버퍼를 사용하지 않기 때문에 터미널에 바로 출력된다. 
	std::cerr << "준비...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "땅!!" << std::endl;

	p.set_value();

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	/* 해당 코드를 성공적으로 컴파일하게 되면 결과가 정상적으로 출력된다. 
	이 코드 역시 condition_variable 을 이용해서 동일하게 작성할 수 있다. 
	하지만 보다시피, future 를 사용하는 것이 훨씬 편리하다. */
}


/* packaged_task */
/* C++ 에서는 위 promise-future 패턴을 비동기적 함수
(정확히는 Callable - 즉 람다 함수, Functor 포함) 의 리턴값에 
간단히 적용할 수 있는 packaged_task 라는 것을 지원한다. 
packaged_task 에 전달된 함수가 리턴할 때, 그 리턴값을 promise 에 set_value 하고,
만약에 예외를 던졌다면 promise 에 set_exception 을 한다. 해당 future 는 
packaged_task 가 리턴하는 future 에서 접근할 수 있다. 아래 예제를 살펴보자. */
#include <future>
#include <iostream>
#include <thread>

int some_task(int x) { return 10 + x; }

int main() {
	// int(int) : int
	std::packaged_task<int(int)> task(some_task);
	/* packaged_task 는 비동기적으로 수행할 함수 자체를 생성자의 인자로 받는다. 
	또한 템플릿 인자로 해당 함수의 타입을 명시해야 한다. packaged_task 는 전달된
	함수를 실행해서, 그 함수의 리턴값을 promise 에 설정한다. 
	해당 promise 에 대응되는 future 는 아래와 같이 get_future 함수로 얻을 수 있다. */

	std::future<int> start = task.get_future();

	std::thread t(std::move(task), 5);
	/* 생성된 packaged_task 를 쓰레드에 전달하면 된다. 참고로 packaged_task 는 복사 생성이
	불가능하므로 (promise 도 마찬가지!!) 명시적으로 move 해주어야만 한다. */

	std::cout << "결과값: " << start.get() << std::endl;
	t.join();
	/* 해당 코드를 성공적으로 컴파일하면 결과는 다음과 같다.
	결과값: 15
	비동기적으로 실행된 함수의 결과값은 추후에 future 의 get 함수로 받을 수 있게 된다. 
	이와 같이 packaged_task 를 사용하게 된다면 쓰레드에 굳이 promise 를 전달하지 않아도 
	알아서 packaged_task 가 함수의 리턴값을 처리해주어서 매우 편리하다. */
}


/* std::async */
/* 앞서 promise 나 packaged_task 는 비동기적으로 실행을 하기 위해서는, 
쓰레드를 명시적으로 생성해서 실행해야만 했다. 하지만 std::async 에 어떤
함수를 전달한다면, 아예 쓰레드를 알아서 만들어서 해당 함수를 비동기적으로
실행하고, 그 결과값을 future 에 전달한다. */
#include <future>
#include <iostream>
#include <thread>
#include <vector>

// std::accumulate 와 동일
int sum(const std::vector<int>& v, int start, int end) {
	int total = 0;
	for (int i = start; i < end; ++i) {
		total += v[i];
	}
	return total;
}

int parallel_sum(const std::vector<int>& v) {
	// lower_half_future 는 1 ~ 500 까지 비동기적으로 더함.
	// 참고로 람다 함수를 사용하면 좀 더 깔끔하게 표현할 수도 있다.
	// --> std::async([&v]() { return sum(v, 0, v.size() / 2); });
	std::future<int> lower_half_future =
		std::async(std::launch::async, sum, cref(v), 0, v.size() / 2);
	/* async 함수를 인자로 받은 함수를 비동기적으로 실행한 후에, 해당 결과값을 보관할 future 를 
	리턴한다. 첫 번째 인자로는 어떠한 형태로 실행할지를 전달하는데 두 가지 값이 가능하다. 
	1) std::launch::async : 바로 쓰레드를 생성해서 인자로 전달된 함수를 실행한다.
	2) std::launch::deferred : future 의 get 함수가 호출되었을 때 실행한다. (새로운 쓰레드를 생성하지 않음.) 
	즉 launch::async 옵션을 주면 바로 그 자리에서 쓰레드를 생성해서 실행하게 되고, launch::defeffed 옵션을 주면,
	future 의 get 을 하였을 때 비로소 (동기적으로) 실행하게 된다. 다시 말해, 해당 함수를 굳이 바로 당장 
	비동기적으로 실행할 필요가 없다면 deferred 옵션을 주면 된다. 
	*/

	// upper_half 는 501 부터 1000 까지 더함.
	int upper_half = sum(v, v.size() / 2, v.size());

	return lower_half_future.get() + upper_half;	/* async 함수는 실행하는 함수의 결과값을 포함하는 future 을 리턴한다. 
													그 결과값은 해당 줄에 있는 async 함수가 리턴한 future 에 get 을 통해서 
													알아낼 수 있다. */
}

int main() {
	std::vector<int> v;
	v.reserve(1000);

	for (int i = 0; i < 1000; ++i) {
		v.push_back(i + 1);
	}

	std::cout << "1 부터 1000 까지의 합: " << parallel_sum(v) << std::endl;
	/* 해당 코드를 성공적으로 컴파일하면 출력되는 결과는 아래와 같다.
	1 부터 1000 까지의 합: 500500 */
	/* 위 parallel 함수는 1 부터 1000 까지의 뎃셈을 총 2 개의 쓰레드에서 실행한다고 보면 된다. 
	1 부터 500 까지의 합은, async 를 통해 생성된 새로운 쓰레드에서 더하게 되고, 나머지 501 부터 
	1000 까지의 합은 원래의 쓰레드에서 처리하게 된다. 
	물론 위 1 부터 1000 까지의 합은 금방 처리되기 때문에 큰 차이는 나지 않지만, CPU 를 많이 사용하는
	작업을 두 개의 쓰레드에서 나눠 처리한다면(CPU 가 멀티 코어임을 가정할 때) 2 배 빠르게 작업을 
	수행할 수 있다. 
	예를 들어서 아래의 예제 코드를 보자. (아래의 코드 참고!!!) */
}


#include <future>
#include <iostream>
#include <thread>

int do_work(int x) {
	// x 를 가지고 무슨 일을 한다.
	std::this_thread::sleep_for(std::chrono::seconds(3));
	return x;
}

void do_work_parallel() {
	auto f1 = std::async([]() { do_work(3); });
	auto f2 = std::async([]() { do_work(3); });
	do_work(3);		/* 실행하는데 3 초가 걸리는 do_work 함수!!!(비동기적 호출) */

	f1.get();
	f2.get();
}

void do_work_sequential() {
	do_work(3);
	do_work(3);
	do_work(3);
}

int main() { do_work_parallel(); }
/* time 은 프로그램의 실행 시간과 CPU 사용률을 간단히 측정할 수 있는 프로그램이다.
맨 마지막의 total 이 프로그램의 총 실행 시간이다. 
결과를 출력해보면, 실행하는 데 약 3 초가 걸리는 것을 확인할 수 있다.
이는 총 실행하는 데 3 초가 걸리는 do_work 함수를 아래와 같이 비동기적으로 호출하였기 
때문이다. 즉 3 개의 do_work 함수를 동시에 각기 다른 쓰레드에서 실행한 덕분에 3 초 만에 
끝났다. 
반면에 동기적으로 하나씩 실행하는 코드는 아래와 같다. (아래의 코드 참고!!) */


#include <future>
#include <iostream>
#include <thread>

int do_work(int x) {
	// x 를 가지고 무슨 일을 한다. 
	std::this_thread::sleep_for(std::chrono::seconds(3));
	return x;
}

void do_work_parallel() {
	auto f1 = std::async([]() { do_work(3); });
	auto f2 = std::async([]() { do_work(3); });
	do_work(3);

	f1.get();
	f2.get();
}

void do_work_sequential() {
	do_work(3);
	do_work(3);
	do_work(3);
}

int main() { do_work_sequential(); }
/* 해당 코드를 성공적으로 컴파일하였다면,
총 3 + 3 + 3 = 9 초가 걸림을 확인할 수 있다. (확실히 앞의 코드에서 걸린 시간인 3 초보다 느리다.)
이처럼 C++ 에서 제공하는 promise, future, packaged_task, async 를 
잘 활용하면 귀찮게 mutex 나 condition_variable 을 사용하지 않고도
매우 편리하게 비동기적 작업을 수행할 수 있다. 
다음 강좌에서는 여태까지 배운 것들을 총동원해서 ThreadPool 을 만들어볼 것이다. */


/* 생각해보기-문제 */
/* 문제 1:
async 를 사용해서 기존의 find$algorithm 를 더 빠르게 수행하는 함수를 만들어보자. */
/* 문제 2:
쓰레드풀(ThreadPool) 이란, 말 그대로 쓰레드들의 직업 소개소라고 볼 수 있다. 여기에
일거리(함수) 를 던져주면, 직업 소개소에 있던 쓰레드 하나가 그 일감을 받아서 수행하게
된다. 그 일을 다 수행한 쓰레드는 다시 직업 소개소로 돌아온다. 쓰레드풀의 사용자는 원하는
만큼의 쓰레드들을 생성해놓고, 무언가 수행하고 싶은 일이 있다면 그냥 쓰레드풀에 추가하면 된다.
그렇다면 한 번 ThreadPool 클래스를 설계하고 만들어보자. 다음 강좌에서 같이 만들겠지만,
먼저 혼자 자기 힘으로 만들어보는 것이 중요하다. */

/* 뭘 배웠지?? 
1) 한 번 발생하는 이벤트에 대해서 promise-future 패턴을 이용하면 간단하게 처리할 수 있다.
2) shared_future 를 사용해서 여러 개의 쓰레드를 한꺼번에 관리할 수 있다. 
3) packaged_task 를 통해서 원하는 함수의 promise 와 future 패턴을 손쉽게 생성할 수 있다.
4) async 를 사용하면 원하는 함수를 비동기적으로 실행할 수 있다. */









/* ThreadPool 만들기 */
/* 쓰레드풀이란, 쓰레드들을 위한 직업 소개소라고 보면 된다. 여러 개의 쓰레드들이 
대기하고 있다가, 할 일이 들어오게 되면, 대기하고 있던 쓰레드들 중 하나가 이를 받아서
실행하게 된다. 
예를 들어서 서버의 경우, 클라이언트(사용자) 에서 요청이 들어오면 해당 요청에 대한 처리를 
쓰레드풀에 추가만 하면 된다. 그러면 나중에 쓰레드들 중 하나가 처리를 하게 된다. 물론 모든
쓰레드들이 다 다른 것들을 처리하고 있어도 괜찮다. 
보통 이를 구현하는 아이디어는 간단하다. 처리해야 될 작업들을 큐(queue) 에 추가하는 것이다.
큐는 그냥 링크드리스트라고 생각하면 편한데, push 를 하게 되면 큐 맨 뒤에 작업을 추가하게 된다. 
그 다음에 pop 를 하면 맨 앞에 있는 작업을 빼버리게 된다. 
참고로 C++ 에서 제공하는 queue 의 경우, pop 을 하면 맨 앞의 원소를 제거하지만 해당 원소를 리턴
하지 않는다. 해당 원소에 접근하기 위해서는 front 를 호출해야 한다. 
큐를 사용하면 가장 먼저 추가된 작업을 가장 먼저 처리를 시작할 수 있다. 다시 말해, 가장 오래된 작업
요청을 가장 먼저 처리하는 방식이라고 보면 된다. 가장 상식적인 방법이기도 한데, 때때론 가장 최근에 
추가된 작업 요청을 먼저 처리해야 할 때도 있다. 이 경우에는 queue 대신에 다른 자료 구조를 이용하는
것이 좋다. */



/* ThreadPool 코드 전체 구현 */
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool {
    class ThreadPool {
    public:
        ThreadPool(size_t num_threads);
        ~ThreadPool();

        // job 을 추가한다. 
        void EnqueueJob(std::function<void()> job);

    private:
        // 총 Worker 쓰레드의 개수 
        size_t num_threads_;
        // Worker 쓰레드를 보관하는 벡터
        std::vector<std::thread> worker_threads_;
        // 할 일들을 보관하는 job 큐
        std::queue<std::function<void()>> jobs_;
        // 위의 job 큐를 위한 cv 와 m
        std::condition_variable cv_job_q_;
        std::mutex m_job_q_;

        // 모든 쓰레드 종료
        bool stop_all;

        // Worker 쓰레드 
        void WorkerThread();
    };

ThreadPool::ThreadPool(size_t num_threads)
    : num_threads_(num_threads), stop_all(false) {
    worker_threads_.reserve(num_threads_);
    for (size_t i = 0; i < num_threads_; ++i) {
        worker_threads_.emplace_back([this]() { this->WorkerThread(); });
    }
}

void ThreadPool::WorkerThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(m_job_q_);
        cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
        if (stop_all && this->jobs_.empty()) {
            return;
        }

        // 맨 앞의 job 를 뺀다.
        std::function<void()> job = std::move(jobs_.front());
        jobs_.pop();
        lock.unlock();

        // 해당 job 를 수행한다. 
        job();
    }
}

ThreadPool::~ThreadPool() {
    stop_all = true;
    cv_job_q_.notify_all();
    for (auto& t : worker_threads_) {
        t.join();
    }
}

void ThreadPool::EnqueueJob(std::function<void()> job) {
    if (stop_all) {
        throw std::runtime_error("ThreadPool 사용 중지됨.");
    }
    {
        std::lock_guard<std::mutex> lok(m_job_q_);
        jobs_.push(std::move(job));
    }
    cv_job_q_.notify_one();
}

}   // namespace ThreadPool

void work(int t, int id) {
    printf("%d start \n", id);
    std::this_thread::sleep_for(std::chrono::seconds(t));
    printf("%d end after %ds\n", id, t);
}

int main() {
    ThreadPool::ThreadPool pool(3);

    for (int i = 0; i < 10; i++) {
        pool.EnqueueJob([i]() { work(i % 3 + 1, i); });
    }
}



#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool {
	class ThreadPool {
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

	// job 을 추가한다. 
		template <class F, class... Args>
		std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
			F f, Args... args);

	private:
		// 총 Worker 쓰레드의 개수
		size_t num_threads_;
		// Worker 쓰레드를 보관하는 벡터
		std::vector<std::thread> worker_threads_;
		// 할 일들을 보관하는 job 큐
		std::queue<std::function<void()>> jobs_;
		// 위의 job 큐를 위한 cv 와 m
		std::condition_variable cv_job_q_;
		std::mutex m_job_q_;

		// 모든 쓰레드 종료
		bool stop_all;

		// Worker 쓰레드
		void WorkerThread();
	};

ThreadPool::ThreadPool(size_t num_threads)
	: num_threads_(num_threads), stop_all(false) {
	worker_threads_.reserve(num_threads_);
	for (size_t i = 0; i < num_threads_; ++i) {
		worker_threads_.emplace_back([this]() { this->WorkerThread(); });
	}
}

void ThreadPool::WorkerThread() {
	while (true) {
		std::unique_lock<std::mutex> lock(m_job_q_);
		cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
		if (stop_all && this->jobs_.empty()) {
			return;
		}

		// 맨 앞의 job 을 뺀다.
		std::function<void()> job = std::move(jobs_.front());
		jobs_.pop();
		lock.unlock();

		// 해당 job 을 수행한다. 
		job();
	}
}

ThreadPool::~ThreadPool() {
	stop_all = true;
	cv_job_q_.notify_all();

	for (auto& t : worker_threads_) {
		t.join();
	}
}

template <class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(
	F f, Args... args) {
	if (stop_all) {
		throw std::runtime_error("ThreadPool 사용 중지됨");
	}

	using return_type = typename std::result_of<F(Args...)>::type;
	std::packaged_task<return_type()> job(std::bind(f, args...));

	std::future<return_type> job_result_future = job.get_future();
	{
		std::lock_guard<std::mutex> lock(m_job_q_);
		jobs_.push([&job]() { job(); });
	}
	cv_job_q_.notify_one();

	return job_result_future;
}

}	// namespace ThreadPool

int work(int t, int id) {
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}

int main() {
	ThreadPool::ThreadPool pool(3);

	std::vector<std::future<int>> futures;
	for (int i = 0; i < 10; i++) {
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) {
		printf("result : %d \n", f.get());
	}
	/* 해당 코드를 컴파일한 후 실행하면 런타임 오류가 발생한다. 
	오류 창에서 보다시피 Broken promise 예외가 던져졌다. Broken promise 예외는 
	promise 에 set_value 를 하기 전에 이미 promise 의 future 객체가 파괴되었다면 
	발생하는 예외이다. 그렇다면 왜 future 객체가 파괴되었을까?? 그 이유는 간단하다. 
	std::packaged_task<return_type()> job(std::bind(f, args...));
	EnqueueJob 함수에 정의된 job 객체는 지역 변수이다. 즉, EnqueueJob 함수가 리턴하면
	파괴되는 객체이다. 따라서 [&job](* { job(); } 안에서 job 을 접근할 때 이미 그 
	객체는 파괴되고 없어져 있을 것이다. 
	이 문제를 해결하는 방법으로는 크게 두 가지를 생각해볼 수 있다. 
	1) packaged_task 를 따로 컨테이너에 저장해서 보관한다.
	2) shared_ptr 에 packaged_task 를 보관한다. 
	1 번 방식의 경우 더 이상 packaged_task 를 사용하지 않을 때에도 컨테이너에 남아있다는
	문제가 있다. 하지만 2 번의 경우 packaged_task 를 사용하는 것이 없을 때 알아서 shared_ptr
	가 객체를 소멸시켜주므로 훨씬 관리하기 편하다. 따라서 후자인 2 번을 택하도록 할 것이다. 
	이를 구현하면 아래와 같다. 
	auto job = 
		std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));
	std::future<return_type> job_result_future = job->get_future();
	{
		std::lock_guard<std::mutex> lock(m_job_q_);
		jobs_.push([job]() { (*job)(); });
	}
	위와 같이 간단히 make_shared 를 통해서 shared_ptr 을 생성하였고, 대신에 람다 함수에
	shared_ptr 의 복사본을 전달해서 람다 함수 안에서도 packaged_ptr 하나를 붙들고 있게
	되었다. 
	따라서 job 을 실행하는 시점에서도 packaged_task 객체는 계속 살아있게 된다. */
}


/* 820 페이지 */
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace ThreadPool {
class ThreadPool {
	public:
	ThreadPool(size_t num_threads);
	~ThreadPool();

	// job 을 추가한다. 
	template <class F, class... Args>
	std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
		F f, Args... args);

	private:
	// 총 Worker 쓰레드의 개수
	size_t num_threads_;
	// Worker 쓰레드를 보관하는 벡터
	std::vector<std::thread> worker_threads_;
	// 할 일들을 보관하는 job 큐
	std::queue<std::function<void()>> jobs_;
	// 위의 job 큐를 위한 cv 와 m
	std::condition_variable cv_job_q_;
	std::mutex m_job_q_;

	// 모든 쓰레드 종료
	bool stop_all;

	// Worker 쓰레드
	void WorkerThread();
};

ThreadPool::ThreadPool(size_t num_threads)
	: num_threads_(num_threads), stop_all(false) {
	worker_threads_.reserve(num_threads_);
	for (size_t i = 0; i < num_threads_; ++i) {
		worker_threads_.emplace_back([this]() { this->WorkerThread(); });
	}
}

void ThreadPool::WorkerThread() {
	while (true) {
		std::unique_lock<std::mutex> lock(m_job_q_);
		cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
		if (stop_all && this->jobs_.empty()) {
			return;
		}

		// 맨 앞의 job 을 뺀다.
		std::function<void()> job = std::move(jobs_.front());
		jobs_.pop();
		lock.unlock();

		// 해당 job 을 수행한다. 
		job();
	}
}

ThreadPool::~ThreadPool() {
	stop_all = true;
	cv_job_q_.notify_all();

	for (auto& t : worker_threads_) {
		t.join();
	}
}

template <class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(
	F f, Args... args) {
	if (stop_all) {
		throw std::runtime_error("ThreadPool 사용 중지됨.");
	}

	using return_type = typename std::result_of<F(Args...)>::type;
	auto job =
		std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));
	std::future<return_type> job_result_future = job->get_future();
	{
		std::lock_guard<std::mutex> lock(m_job_q_);
		jobs_.push([job]() { (*job)(); });
	}
	cv_job_q_.notify_one();

	return job_result_future;
}

}	// namespace TheradPool

int work(int t, int id) {
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}

int main() {
	ThreadPool::ThreadPool pool(3);

	std::vector<std::future<int>> futures;
	for (int i = 0; i < 10; i++) {
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) {
		printf("result : %d \n", f.get());
	}
}






































































































































































































































































































































































































































