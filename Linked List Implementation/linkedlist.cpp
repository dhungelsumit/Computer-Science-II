#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "examType.h"

using namespace std;

void Input_Data(ifstream&, nodeType*); // funciton prototypes
void Calculate_Statistics(nodeType*);
void Print_Results( nodeType*);
void Calculate_Average(int,  nodeType*);
void Calculate_Above_Average(int,  nodeType*);
void Calculate_Below_Average(int,  nodeType*);

/*
 The input_data() function takes in two parameters, the infile and the statistics_array. This function reads (loops) through the five sets of semester final exam data and populates a portion of the statistics_array.
 */
void Input_Data(ifstream& myfile,  nodeType* firstptr) // function definition
{
    nodeType* current;
    myfile >> firstptr->info.semester_name >> firstptr->info.semester_year >> firstptr->info.num_of_grades;
        for (int grades_index = 0; grades_index < firstptr->info.num_of_grades; grades_index++)
        {
            myfile >> firstptr->info.grades_array[grades_index];
        }
    current=new nodeType;
    firstptr->next=new nodeType;
    current = firstptr->next;
    for (int index = 0; index < 4; index++)
    {
       myfile >> current->info.semester_name >> current->info.semester_year >> current->info.num_of_grades;
        for (int grades_index = 0; grades_index < current->info.num_of_grades; grades_index++)
        {
            myfile >> current->info.grades_array[grades_index];
        }
        current->next=new nodeType;
        current = current->next;
        }
        current->next=NULL;
}


/*
The calculate_statistics() function takes in the statistics_array and then loops five times calling the calculate_average(), calculate_above_average() and calculate_below_average() functions sending the semester_index (0 -4) and the statistics_array  to each function.  The result is that these computed statistics are stored in each of member structs in the statistics_array.
*/
void Calculate_Statistics(nodeType* firstptr) // function definition
{
    nodeType* current;
    int counter=0;
    for( current=firstptr; current->next !=NULL;current=current->next)
    {
       Calculate_Average(counter, firstptr);
       Calculate_Above_Average(counter, firstptr);
       Calculate_Below_Average(counter, firstptr);
       counter+=1;
    }
}
/*
The calculate_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indicated by the semester_index and sums all  the grades.  This sum is divided by the no_of _grades  in the member struct (indexed by semester_index) to compute the average grade for that semester's final exam.  Finally, this average is stored in the average_grade member of the struct indexed by the semester_index .
 */
void Calculate_Average(int semester_index, nodeType* firstptr) // function definition
{
    float grade_total = 0;
    float grade_average = 0;
    nodeType* current;
    current=firstptr;
    for (int i=0;i<semester_index;i++){
        current=current->next;
            }
    int number_of_grades=current->info.num_of_grades;
    for( int grade_index = 0; grade_index < number_of_grades; grade_index++)
    {
        grade_total += current->info.grades_array[grade_index];
    }
    grade_average = grade_total /number_of_grades;
    current->info.average_grade = grade_average;
}

/*The calculate_above_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indexed by the semester_index and counts all the grades that are above the average_grade member of the struct indexed by the semester_index.  Finally, this count is stored in the no_of_grades_above_average member of the  struct indexed by the semester_index.
 */
 void Calculate_Above_Average(int semester_index,nodeType* firstptr) // function definition
{
    int number_above_average = 0;
    nodeType* current;
    current = firstptr;
    for(int i=0;i<semester_index;i++){
        current=current->next;
    }
    float average_grade = current->info.average_grade;
    int number_of_grades = current->info.num_of_grades;
    for( int grade_index = 0; grade_index < number_of_grades; grade_index++)
    {
        if (current->info.grades_array[grade_index] > average_grade)
            number_above_average++;
    }
    current->info.number_of_grades_above_average = number_above_average;
}
/*
 The calculate_below_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indexed by the semester_index and counts all the grades that are below the average_grade member of the struct indicated by the semester_index.  Finally, this count is stored in the no_of_grades_below_average member of the struct indexed by the semester_index.
 */
void Calculate_Below_Average(int semester_index, nodeType* firstptr) // function definition
{
    int number_below_average = 0;
    nodeType* current;
    current=firstptr;
    for(int i=0;i<semester_index;i++){
        current=current->next;
    }

    float average_grade = current->info.average_grade;
    int number_of_grades = current->info.num_of_grades;
    for( int grade_index = 0; grade_index < number_of_grades; grade_index++)
    {
        if (current->info.grades_array[grade_index] < average_grade)
            number_below_average++;
    }
    current->info.number_of_grades_below_average = number_below_average;
}
/*The print_results() function takes in the statistics_array  and loops through it printing the exam information stored for each semester.  This function prints the report show below:*/
void Print_Results(nodeType* firstptr) // function definition
{
    nodeType* current;

    // loop that outputs each semester's data
    for (current=firstptr;current->next!=NULL;current=current->next)
    {
        cout << "Analysis of exams in " << current->info.semester_name << " " << current->info.semester_year << endl << endl;
        cout << "The number of grades is " << current->info.num_of_grades << endl;
        cout << "The average grade is " << fixed << showpoint << setprecision(2) << current->info.average_grade << endl;
        cout << "The number of grades above the average is " << current->info.number_of_grades_above_average << endl;
        cout << "The number of grades below the average is " << current->info.number_of_grades_below_average << endl;
        cout << endl << endl;
    }
}

int main()
{
    nodeType* firstptr;
    firstptr=new nodeType;
    ifstream myfile;
    myfile.open("infile.txt"); // opening file
    Input_Data(myfile, firstptr); // function calls
    Calculate_Statistics(firstptr);
    Print_Results(firstptr);
    myfile.close(); // closing file
    return 0;
}

/*
Analysis of exams in Fall 2013

The number of grades is 17
The average grade is 66.06
The number of grades above the average is 9
The number of grades below the average is 8


Analysis of exams in Spring 2014

The number of grades is 10
The average grade is 67.70
The number of grades above the average is 5
The number of grades below the average is 5


Analysis of exams in Fall 2014

The number of grades is 12
The average grade is 57.33
The number of grades above the average is 6
The number of grades below the average is 6


Analysis of exams in Spring 2015

The number of grades is 20
The average grade is 70.00
The number of grades above the average is 11
The number of grades below the average is 9


Analysis of exams in Fall 2015

The number of grades is 15
The average grade is 60.13
The number of grades above the average is 8
The number of grades below the average is 7



Process returned 0 (0x0)   execution time : 0.047 s
Press any key to continue.
*/
