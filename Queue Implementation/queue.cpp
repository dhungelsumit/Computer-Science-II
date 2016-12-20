include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <stdexcept>//set of standard exceptions that both the library and programs can use to report common errors.

template <typename T>//definition of template

struct Node {
    T info;
    Node<T>* next;
};

template <typename T>
class queueType
{
public:
    queueType(int );
    bool IsFull() const;
    bool IsEmpty() const;
    void Enqueue(T const&);
    int Size() const;
    void MakeEmpty();
    T Dequeue();
private:
    int size;
    int current;
    Node<T>* root;
    Node<T>* rear;
};


class queueTypeException: public std::logic_error {
public:
    queueTypeException(const std::string& message = "queueType Error")
        :logic_error(message.c_str())
        {}
};

template <typename T>
queueType<T>::queueType(int si){
    size = si;
    current = 0;
    Node<T>* root;
    root = NULL;
}

template <typename T>
bool queueType<T>::IsFull() const {
    return (size == current);
}

template <typename T>
bool queueType<T>::IsEmpty() const {
    return (current == 0);
}

template <typename T>
void queueType<T>::MakeEmpty(){
    current = 0;
}

template <typename T>
int queueType<T>::Size() const {
    return current;
}

template <typename T>
void queueType<T>::Enqueue(T const& newItem){
     if (IsFull())
        {
        throw queueTypeException("Limit Exceeded");
    }
    else{
        Node<T>* newNode = new Node<T>;
        newNode->info = newItem;
        newNode->next = NULL;
        if (root == NULL)
        {
            root=newNode;
        }
        else{
            rear->next = newNode;
        }
        rear=newNode;
        current++;

        }
};

template <typename T>
T queueType<T>::Dequeue()
{
    if (IsEmpty())
        {
        throw queueTypeException("The Queue is Empty");
    }
    else {
        Node<T>* nodeFront;
        nodeFront = root;
        T returnValue;
        returnValue = nodeFront->info;
        root = root->next;
        delete nodeFront;
        current-=1;
        return returnValue;
    }
}


using namespace std;

//implementation file

class DateType
{

public:
    void Initialize(int newMonth, int newDay, int newYear);
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

void DateType::Initialize(int newMonth, int newDay, int newYear) {
    year = newYear;
    month = newMonth;
    day = newDay;
}

void DateType::setYear(int Yr)
{
    year = Yr;
}
void DateType::setMonth(int Month)
{
    month = Month;
}
void DateType::setDay(int Day)
{
    day = Day;
}

int DateType::GetYear() const
{
    return year;
}
int DateType::GetMonth() const
{
    return month;
}
int DateType::GetDay() const
{
    return day;
}
class monthType
{
public:
    int month_num;
    int dates[6][7];
    monthType(); // constructor
    void printMonth();
    void setMonthName(string);
    string getMonthName();
private:
    string month_name;
};
monthType::monthType()
{
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
            dates[row][col] = 0;
    }
}
void monthType::setMonthName(string mon_name)
{
    month_name = mon_name;
}
string monthType::getMonthName()
{
    return month_name;
}

void monthType::printMonth()
{
    cout << endl << setw(12) << month_name << endl << endl;
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
        {
            if (dates[row][col]==0){
                cout << setw(6) << " ";
            }
            else{
                cout << setw(6) << dates[row][col];
            }

        }
        cout << endl; // skip a line between weeks
    }
}
class yearType
{
public:
    monthType months[12];
    yearType(); //constructor
    void printYear()
    {
        for (int month_index=0; month_index<12; month_index++)
        {
            months[month_index].printMonth();
        }
    }
};
yearType::yearType()
{
    for (int i=0; i<12; i++)
        months[i].month_num = i;
}
class calendar
{
    public:
    void printCalendar(yearType);
};
class USDollarCents
{
private:
    int dollars;
    int cents;

    // ****** USDollarCents Normalize ******
    void normalize();


public:
    USDollarCents (int dollars = 0, int cents = 0);
    USDollarCents Length(void) const; // USDollarCents length
    void CopyUSDollarCents(USDollarCents* t) const; // copy USDollarCents
    // Write USDollarCentss
    friend ostream& operator<< (ostream& ostr, const USDollarCents& s);
    // Read USDollarCentss
    friend istream& operator>> (istream& istr, USDollarCents& s);

    // ***** relational operator *****

    // USDollarCents == USDollarCents
    int operator== ( const USDollarCents& s) const;
    // USDollarCents < USDollarCents
    int operator< ( const USDollarCents& s) const;
    // USDollarCents > USDollarCents
    int operator> ( const USDollarCents& s) const;
    // USDollarCents <= USDollarCents
    int operator<= ( const USDollarCents& s) const;
    // USDollarCents >= USDollarCents
    int operator>= ( const USDollarCents& s) const;
    // USDollarCents != USDollarCents
    int operator!= ( const USDollarCents& s) const;

    // ***** USDollarCents Arithmetic operators ****

    // ***** USDollarCents addition *****
    USDollarCents operator+ ( const USDollarCents& s) const;

    // ***** USDollarCents addition equal *****
    void operator+= ( const USDollarCents& s);

    // ***** USDollarCents subtraction *****
    USDollarCents operator- ( const USDollarCents& s) const;

    // ***** USDollarCents subtraction equal *****
    void operator-= ( const USDollarCents& s);

    // ***** USDollarCents mutiplication *****
    USDollarCents operator* (const USDollarCents& s) const;

    // ***** USDollarCents mutiplication equal *****
    void operator*= (int);

    // ***** USDollarCents division *****
    USDollarCents operator/ (int) const;

    // *******  USDollarCents absolute value ***
    USDollarCents absolute() const;

    // ******* USDollarCents divided by 100 ***
    USDollarCents divideby100() const;


};

USDollarCents::USDollarCents(int dd, int cc ) : dollars(dd), cents(cc)
{
    while (cents >= 100)
    {
        cents = cents - 100;
        dollars++;
    }
}

ostream& operator<< (ostream& ostr, const USDollarCents& s)
{
    ostr << "$" << s.dollars << "." << s.cents;
    return ostr;
}

istream& operator>> (istream& istr, USDollarCents& s)
{
    char char1;
    istr >> s.dollars >> char1 >> s.cents;
    return istr;
}

int USDollarCents::operator< ( const USDollarCents& s) const
{
    if (dollars < s.dollars)
        return 1;
    else
        if (dollars == s.dollars)
            if (cents < s.cents)
                return 1;
            else
                return 0;
        else
            return 0;
}
int USDollarCents::operator> ( const USDollarCents& s) const
{
    if (dollars > s.dollars)
        return 1;
    else
        if (dollars == s.dollars)
            if (cents > s.cents)
                return 1;
            else
                return 0;
        else
            return 0;
}

int USDollarCents::operator== ( const USDollarCents& s) const
{
     if (dollars == s.dollars)
            if (cents == s.cents)
                return 1;
            else
                return 0;

}

USDollarCents USDollarCents::operator+ ( const USDollarCents& s) const
{
    int h = dollars + s.dollars;
    int m = cents + s.cents;
    USDollarCents D(h, m);
    D.normalize();
    return D;
}

void USDollarCents::operator+= ( const USDollarCents& s)
{
    dollars += s.dollars;
    cents += s.cents;
    if (cents >= 100)
    {
        cents = cents - 100;
        dollars++;
    }
    normalize();
}


USDollarCents USDollarCents::operator- ( const USDollarCents& s) const
{
    int h = dollars - s.dollars;
    int m = cents - s.cents;
    if (m < 0)
    {
        m = m + 100;
        h--;
    }
    USDollarCents D(h, m);
    D.normalize();
    return D;
}

void USDollarCents::operator-= ( const USDollarCents& s)
{
    dollars -= s.dollars;
    cents -= s.cents;
    if (cents < 0 )
    {
        cents = cents + 100;
        dollars--;
    }
    normalize();
}

USDollarCents USDollarCents::absolute() const
{
    int h = abs(dollars);
    int m = abs(cents);
    USDollarCents D(h, m);
    return D;
}

USDollarCents USDollarCents::divideby100() const
{
    int m = cents;
    int h = dollars;

    m = h * 100 + m ;
    h = m / 10000;
    m = (( m / 10000.0 )  - h + .005)  * 100;

    USDollarCents D(h, m);
    D.normalize();
    return D;
}

void  USDollarCents::normalize()
{
    if (( dollars != 0 ) && ( cents != 0 ))
    {
        if  (( dollars < 0 ) && ( cents > 0 ))
        {
            if ( cents > 0 )
            {
                cents = cents - 100;
                dollars++;
            }
        }

        if (( dollars > 0 ) && ( cents < 0 ))
        {
            if ( cents < 0)
            {
                cents = cents + 100;
                dollars--;
            }
        }
    }
}

//Class declaration
class addressType
{
public:
    string number;
    string streetName;
    string streetAddress;
    string streetType;
    string city;
    string state;
    string zipcode;
};

class personType
{
public:
    personType(); //constructor
    string lastName;
    string firstName;
    int personNum;
    int personID;
    char gender;
    addressType address;
/********MEMBER FUNCTIONS********/
    string getInterest1();
    string getInterest2();
    void setInterest1(string);
    void setInterest2(string);
    void print();
private:
    string interest1;
    string interest2;
};

//define membershipType class
class membershipType:public personType
{
public:
    char membership_type;
    char membership_status;
    membershipType();  // 1st constructor
    membershipType(char,char);  // 2nd constructor
    void print_member_type();
    yearType memberCalendar;
    USDollarCents memberAccount;
    bool operator<(const membershipType &rhs) const
  {
      return personID < rhs.personID;
  }

};

//personType
personType::personType()
{
    firstName ="";
    lastName = "";
    personNum =0;
    personID = 0;
    gender = ' ';
    address.number= "";
    address.streetName="";
    address.streetAddress = "";
    address.streetType="";
    address.city="";
    address.state = "";
    address.zipcode="";

}

membershipType::membershipType()
{
 membership_type = 'a';
 membership_status = 'b';

}

membershipType::membershipType(char mem1,char mem2)
{
    membership_type=mem1;
    membership_status=mem2;
}

string personType::getInterest1()
{
    return interest1;
}

string personType::getInterest2()
{
    return interest2;
}

void personType::setInterest1(string int1)
{
    interest1=int1;
}

void personType::setInterest2(string int2)
{
    interest2=int2;
}

void membershipType::print_member_type(){
cout << lastName <<" " << firstName <<"\t" <<personNum << "   " <<personID << "   " << address.number <<"\t" << address.streetAddress << "\t" << address.streetType;
cout << "  " << address.city << "\t" << address.state << "\t" << address.zipcode << "\t" << gender << "  " << getInterest1() << "  " <<getInterest2() << "\t" << membership_type<<"  "<<membership_status;
cout <<" " << memberAccount <<endl;
}

int main()
{
    queueType<membershipType> memberlist(6);
    ifstream file;
    file.open("infile.txt");
    string int1, int2;
    int dollar;
    int cent;
    membershipType temp;
    for (int i = 0; i < 6; i++){
        file >> temp.lastName >> temp.firstName>>temp.personNum >> temp.personID;
        file >> temp.address.number >> temp.address.streetAddress >> temp.address.streetType;
        file >> temp.address.city >> temp.address.state >> temp.address.zipcode>>temp.gender;
        file >> int1 >> int2 >> temp.membership_type >> temp.membership_status;
        temp.setInterest1(int1);
        temp.setInterest2(int2);
        file>> dollar >> cent;
        temp.memberAccount= USDollarCents(dollar,cent);
        memberlist.Enqueue(temp);
                }
        int me_size=0;
        me_size=memberlist.Size();
        for(int i=0;i<me_size;i++){
        memberlist.Dequeue().print_member_type();

    }
    file.close();
    return 0;

}
/*
Herold, Jill    1   2234   123  Main    St.  Washington,        DC      20019   F  yoga  facebook       1  2 $231.12
Jackson, Stan   2   3748   12   Douglas Ave.  Baltimore,        MD      30229   M  sports  movies       2  4 $200.0
Jerry, Francis  3   6666   2345 6th     Street  Woodbridge,     VA      44040   M  movies  roadtrips    1  1 $611.33
Joan, Wilson    4   1234   12   Georgia Ave.  Washington,       DC      20019   F  romance  dining      2  3 $190.10
Smith, Stanley  5   3456   56   D       Street  Baltimore,      MD      30229   M  movies  dining       2  1 $876.25
Claire, Claude  6   2311   66   32nd    Street  Woodbridge,     VA      44040   F  cooking  facebook    1  1 $332.99

Process returned 0 (0x0)   execution time : 0.048 s
Press any key to continue.



*/
