#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// a. Membaca data mahasiswa
void getData(studentType students[], int& numStudents) {
    numStudents = 6;
    students[0] = {"Soke", "Bahtera", 98, ' '};
    students[1] = {"Zaman", "Zulkarnaen", 76, ' '};
    students[2] = {"Tegar", "Karang", 82, ' '};
    students[3] = {"Putri", "Raib", 67, ' '};
    students[4] = {"Ananta", "Prahadi", 88, ' '};
    students[5] = {"Biru", "Laut", 74, ' '};
}

// b. Menentukan huruf grade
void assignGrade(studentType students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// c. Menentukan nilai tertinggi
int findHighest(studentType students[], int numStudents) {
    int highest = students[0].testScore;
    for (int i = 1; i < numStudents; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

// d. Menampilkan nama mahasiswa dengan nilai tertinggi
void printHighest(studentType students[], int numStudents, int highest) {
    cout << "Mahasiswa dengan nilai tertinggi (" << highest << "):" << endl;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].testScore == highest) {
            cout << students[i].studentLName << ", "
                 << students[i].studentFName
                 << "\nNilai: " << students[i].testScore
                 << "\nGrade: " << students[i].grade << endl;
        }
    }
}

// Fungsi utama
int main() {
    studentType students[MAX_STUDENTS];
    int numStudents, highest;

    getData(students, numStudents);       // a. Membaca data
    assignGrade(students, numStudents);   // b. Menentukan grade
    highest = findHighest(students, numStudents); // c. Mencari nilai tertinggi
    printHighest(students, numStudents, highest); // d. Menampilkan hasil

    return 0;
}
