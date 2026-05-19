/*
Struct and Class: A struct has public members by default, while a class has private members by default. Otherwise, they are very similar in C++.
*/

struct StudentS
{
    int id;
    int getId() { return id; }
};

/*
struct Student and class Student cannot both exist in the same scope because both define a type named Student.
*/
class StudentC
{
    int id;

public:
    int getId() { return id; }
};
