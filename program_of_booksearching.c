#include <stdio.h>
#include <string.h>

int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int num_total_book);
int borrow_book(int *borrowed, int num_total_book);
int return_book(int *borrowed, int num_total_book);
int compare(char *str1, char *str2);

int main() {
    int user_choice;  // 유저가 선택한 메뉴
    int num_total_book = 0;  // 현재 책의 수

    // 각각 책, 저자, 출판사를 저장할 배열 생성 (책의 최대 개수는 100 권)
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    // 빌렸는지 상태를 표시
    int borrowed[100] = {0};

    while (1) {
        printf("도서 관리 프로그램\n");
        printf("메뉴를 새로 선택하세요\n");
        printf("1. 책을 새로 추가하기\n");
        printf("2. 책을 검색하기\n");
        printf("3. 책을 빌리기\n");
        printf("4. 책을 반납하기\n");
        printf("5. 프로그램 종료\n");

        printf("당신의 선택은: ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            // 책을 새로 추가하는 함수 호출
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        }
        else if (user_choice == 2) {
            // 책을 검색하는 함수 호출
            search_book(book_name, auth_name, publ_name, num_total_book);
        }
        else if (user_choice == 3) {
            // 책을 빌리는 함수 호출
            borrow_book(borrowed, num_total_book);
        }
        else if (user_choice == 4) {
            // 책을 반납하는 함수 호출
            return_book(borrowed, num_total_book);
        }
        else if (user_choice == 5) {
            // 프로그램 종료
            break;
        }
    }
    
    return 0;
}

/* 책을 추가하는 함수 */
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book) {
    printf("추가할 책의 제목: ");
    scanf("%29s", book_name[*num_total_book]);

    printf("추가할 책의 저자: ");
    scanf("%29s", auth_name[*num_total_book]);

    printf("추가할 책의 출판사: ");
    scanf("%29s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0;  // 빌려지지 않음
    printf("추가 완료!!\n");
    (*num_total_book)++;

    return 0;
}

/* 책을 검색하는 함수 */
int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int num_total_book) {
    int user_input;  // 사용자의 입력을 받는다
    int i;
    char user_search[30];

    printf("어느 것으로 검색할 것인가요??\n");
    printf("1. 책 제목 검색\n");
    printf("2. 지은이 검색\n");
    printf("3. 출판사 검색\n");
    scanf("%d", &user_input);

    printf("검색할 단어를 입력해주세요: ");
    scanf("%29s", user_search);

    printf("검색 결과\n");

    if (user_input == 1) {
        // 책 제목으로 검색
        for (i = 0; i < num_total_book; i++) {
            if (compare(book_name[i], user_search)) {
                printf("번호: %d // 책 이름: %s // 지은이: %s // 출판사: %s \n", i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }
    else if (user_input == 2) {
        // 지은이로 검색
        for (i = 0; i < num_total_book; i++) {
            if (compare(auth_name[i], user_search)) {
                printf("번호: %d // 책 이름: %s // 지은이: %s // 출판사: %s \n", i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }
    else if (user_input == 3) {
        // 출판사로 검색
        for (i = 0; i < num_total_book; i++) {
            if (compare(publ_name[i], user_search)) {
                printf("번호: %d // 책 이름: %s // 지은이: %s // 출판사: %s \n", i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }

    return 0;
}

/* 문자열 비교 함수 */
int compare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');  // 둘 다 끝에 도달했을 때만 같다고 간주
}

/* 책을 빌리는 함수 */
int borrow_book(int *borrowed, int num_total_book) {
    int book_num;

    printf("빌릴 책의 번호를 말해주세요\n");
    printf("책 번호: ");
    scanf("%d", &book_num);

    if (book_num < 0 || book_num >= num_total_book) {
        printf("잘못된 책 번호입니다.\n");
        return 1;
    }

    if (borrowed[book_num] == 1) {
        printf("이미 대출된 책입니다!! \n");
    } else {
        printf("책이 성공적으로 대출되었습니다!!\n");
        borrowed[book_num] = 1;
    }

    return 0;
}

/* 책을 반납하는 함수 */
int return_book(int *borrowed, int num_total_book) {
    int num_book;

    printf("반납할 책의 번호를 써주세요\n");
    printf("책 번호: ");
    scanf("%d", &num_book);

    if (num_book < 0 || num_book >= num_total_book) {
        printf("잘못된 책 번호입니다.\n");
        return 1;
    }

    if (borrowed[num_book] == 0) {
        printf("이미 반납되어 있는 상태입니다.\n");
    } else {
        borrowed[num_book] = 0;
        printf("성공적으로 반납되었습니다!!\n");
    }

    return 0;
}
