#include <stdio.h>
#include <string.h>

int add_emotion(char (*date)[30], char (*emotion_state)[30], char (*notes)[100], int *num_total_entries);
int search_emotion(char (*date)[30], char (*emotion_state)[30], char (*notes)[100], int num_total_entries);
int compare(char *str1, char *str2);

int main() {
    int user_choice;  // 유저가 선택한 메뉴
    int num_total_entries = 0;  // 현재 감정 기록의 수

    // 각각 날짜, 감정 상태, 추가 설명을 저장할 배열 생성 (최대 100 개)
    char date[100][30], emotion_state[100][30], notes[100][100];

    while (1) {
        printf("감정 관리 프로그램\n");
        printf("메뉴를 선택하세요\n");
        printf("1. 감정 상태 추가하기\n");
        printf("2. 감정 상태 검색하기\n");
        printf("3. 프로그램 종료\n");

        printf("당신의 선택은: ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            // 감정 상태 추가 함수 호출
            add_emotion(date, emotion_state, notes, &num_total_entries);
        }
        else if (user_choice == 2) {
            // 감정 상태 검색 함수 호출
            search_emotion(date, emotion_state, notes, num_total_entries);
        }
        else if (user_choice == 3) {
            // 프로그램 종료
            break;
        }
    }

    return 0;
}

/* 감정 상태를 추가하는 함수 */
int add_emotion(char (*date)[30], char (*emotion_state)[30], char (*notes)[100], int *num_total_entries) {
    printf("오늘의 날짜(예: 2023-10-16): ");
    scanf("%29s", date[*num_total_entries]);

    printf("오늘의 감정 상태 (예: 행복, 슬픔, 불안): ");
    scanf("%29s", emotion_state[*num_total_entries]);

    printf("추가 설명을 입력하세요: ");
    scanf("%99s", notes[*num_total_entries]);

    printf("감정 기록이 추가되었습니다!\n");
    (*num_total_entries)++;

    return 0;
}

/* 감정 상태를 검색하는 함수 */
int search_emotion(char (*date)[30], char (*emotion_state)[30], char (*notes)[100], int num_total_entries) {
    int user_input;  // 사용자의 입력을 받는다
    int i;
    char search_term[30];

    printf("어떻게 검색하시겠습니까?\n");
    printf("1. 날짜로 검색\n");
    printf("2. 감정 상태로 검색\n");
    scanf("%d", &user_input);

    printf("검색할 단어를 입력하세요: ");
    scanf("%29s", search_term);

    printf("검색 결과\n");

    if (user_input == 1) {
        // 날짜로 검색
        for (i = 0; i < num_total_entries; i++) {
            if (compare(date[i], search_term)) {
                printf("날짜: %s // 감정 상태: %s // 추가 설명: %s\n", date[i], emotion_state[i], notes[i]);
            }
        }
    }
    else if (user_input == 2) {
        // 감정 상태로 검색
        for (i = 0; i < num_total_entries; i++) {
            if (compare(emotion_state[i], search_term)) {
                printf("날짜: %s // 감정 상태: %s // 추가 설명: %s\n", date[i], emotion_state[i], notes[i]);
            }
        }
    }

    return 0;
}

/* 문자열을 비교하는 함수 */
int compare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}
