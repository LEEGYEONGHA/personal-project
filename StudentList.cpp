#include <iostream>
#include <string>

class Student {
protected:
    std::string name;
    int study_hours;          // 하루 동안 공부한 시간

    std::string current_lesson;   // 현재 학습 중인 과목
    int progress_level;           // 학습 진도

public:
    Student(std::string name, int study_hours, std::string current_lesson, int progress_level)
        : name(name), study_hours(study_hours), current_lesson(current_lesson), progress_level(progress_level) {}

    // 복사 생성자
    Student(const Student& student) {
        name = student.name;
        study_hours = student.study_hours;
        current_lesson = student.current_lesson;
        progress_level = student.progress_level;
    }

    // 디폴트 생성자
    Student() {}

    virtual void print_info() {
        std::cout << name << " (" << current_lesson << " , " << study_hours << "시간 공부) ==> "
            << calculate_progress() << "%% 완료" << std::endl;
    }

    virtual int calculate_progress() { return 20 + progress_level * 10; }  // 학습 진도 계산
};

class AdvancedStudent : public Student {
    int total_study_hours;  // 총 누적 공부 시간

public:
    AdvancedStudent(std::string name, int study_hours, std::string current_lesson, int progress_level,
        int total_study_hours)
        : total_study_hours(total_study_hours), Student(name, study_hours, current_lesson, progress_level) {}

    int calculate_progress() override { return 20 + progress_level * 10 + 5 * total_study_hours / 10; }  // 총 학습 시간을 반영한 진도 계산
    void print_info() override {
        std::cout << name << " (" << current_lesson << " , " << study_hours << "시간 공부, "
            << total_study_hours << "시간 누적 학습) ==> " << calculate_progress() << "%% 완료"
            << std::endl;
    }
};

class StudentList {
    int alloc_students;       // 할당한 총 학생 수
    int current_students;     // 현재 학생 수
    Student** student_list;   // 학생 데이터

public:
    StudentList(int alloc_students) : alloc_students(alloc_students) {
        student_list = new Student * [alloc_students];
        current_students = 0;
    }

    void add_student(Student* student) {
        student_list[current_students] = student;
        current_students++;
    }

    int current_student_num() { return current_students; }

    void print_student_info() {
        int total_progress = 0;
        for (int i = 0; i < current_students; i++) {
            student_list[i]->print_info();
            total_progress += student_list[i]->calculate_progress();
        }

        std::cout << "총 평균 진도율: " << total_progress / current_students << "%%" << std::endl;
    }

    ~StudentList() {
        for (int i = 0; i < current_students; i++) {
            delete student_list[i];
        }
        delete[] student_list;
    }
};

int main() {
    StudentList student_list(10);
    student_list.add_student(new Student("학생1", 5, "수학", 1));  // 하루 5시간 공부
    student_list.add_student(new Student("학생2", 4, "영어", 2));   // 하루 4시간 공부

    student_list.add_student(new AdvancedStudent("학생3", 6, "과학", 3, 50));  // 하루 6시간, 누적 50시간 공부
    student_list.add_student(new AdvancedStudent("학생4", 7, "프로그래밍", 4, 70));  // 하루 7시간, 누적 70시간 공부
    student_list.add_student(new AdvancedStudent("학생5", 5, "물리", 2, 40));  // 하루 5시간, 누적 40시간 공부
    student_list.add_student(new Student("학생6", 3, "역사", 1));   // 하루 3시간 공부
    student_list.add_student(new Student("학생7", 2, "지리", 0));       // 하루 2시간 공부

    student_list.print_student_info();

    return 0;
}
