#ifndef BODIES_H
#define BODIES_H

#include <iostream>
#include <iomanip>

class Person_ID{
public:
    Person_ID() {
        series = 0;
        number = 0;
    };

    Person_ID(int new_series, int new_number) {
        if (new_series > 9999 || new_number > 999999 || new_number < 0 || new_series < 0){
            std::cerr << "Incorrect ID";
        }
        series = new_series;
        number = new_number;
    };

    [[nodiscard]] int Get_Series() const{
        return series;
    };

    [[nodiscard]] int Get_Number() const{
        return number;
    };

private:
    int series;
    int number;
};

std::ostream& operator << (std::ostream& os, const Person_ID& per) {
    return os << std::setw(4) << per.Get_Series() << ' ' << std::setw(6) << per.Get_Number();
}

class Date {
public:
    Date(){
        day = 1;
        month = 1;
        year = 2001;

    }
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        if (new_month > 12 || new_month < 1) {
            throw std::logic_error("Month value is invalid");
        }
        month = new_month;
        if (new_day > 31 || new_day < 1) {
            throw std::logic_error("Day value is invalid");
        }
        day = new_day;
    }

    [[nodiscard]] int GetYear() const {
        return year;
    }
    [[nodiscard]] int GetMonth() const {
        return month;
    }
    [[nodiscard]] int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

class person{
public:
    person(){
        Date bd(2001, 1, 1);
        first_name = "Danila";
        last_name = "Eugenevich";
        middle_name = "Andreev";
        birthday = bd;
        passport = Person_ID(0, 0);
    }

    person(std::string new_1name, std::string new_2name, std::string new_3name, Date new_birthday, Person_ID new_ID){
        first_name = move(new_1name);
        middle_name = move(new_2name);
        last_name = move(new_3name);
        birthday = new_birthday;
        passport = new_ID;
    }

    std::string name(){
        return first_name;
    }

    std::string surname(){
        return middle_name;
    }

    std::string full_name(){
        return (middle_name + ' ' + first_name + ' ' + last_name);
    }

    Date Get_birtday(){
        return birthday;
    }

    Person_ID Get_passport(){
        return passport;
    }

    void change_passport(const Person_ID& new_pas){
        passport = new_pas;
    }

private:
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    Date birthday;
    Person_ID passport;
};

class student{
public:
    student() = default;
    student(const person& new_human, const std::string& new_group){
        human = new_human;
        group = new_group;
    }
    void change_group(const std::string& new_group){
        group = new_group;
    }

    [[nodiscard]] person get_student() const{
        return human;
    }

    [[nodiscard]] std::string get_group() const{
        return group;
    }

private:
    person human;
    std::string group;
};

bool operator==(const Date& date1, const Date& date2){
    return (date1.GetDay() == date2.GetDay() &&
            date1.GetMonth() == date2.GetMonth() &&
            date1.GetYear() == date2.GetYear());
}

bool operator==(const Person_ID& pid1, const Person_ID& pid2){
    return (pid1.Get_Series() == pid2.Get_Series()) &&
           (pid1.Get_Number() == pid2.Get_Number());
}

bool operator==(person person1, person person2){
    return ((person1.full_name() == person2.full_name()) &&
            (person1.Get_birtday() == person2.Get_birtday()) &&
            person1.Get_passport() == person2.Get_passport());
}

struct teacher{
    person human;
    int departament_number;
};

bool operator==(const teacher& t1, const teacher& t2){
    return (t1.human == t2.human) &&
           (t1.departament_number == t2.departament_number);
}

bool operator==(const student& student1, const student& student2){
    if(student1.get_group() == student2.get_group()) return student1.get_student() == student2.get_student();
    return false;
}
#endif
