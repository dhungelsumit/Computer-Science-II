#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class ExamType // declaration of a struct
{
public:
    string semester_name;
	int semester_year;
	int num_of_grades;
	int grades_array[35];
	float average_grade;
	int number_of_grades_above_average;
	int number_of_grades_below_average;
};

struct nodeType{
    ExamType info;
    nodeType* next;
    };
