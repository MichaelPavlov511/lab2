#ifndef TESTS_H
#define TESTS_H

#include <cassert>
#include "bodies.h"
#include "Set.h"
#include <map>

void HasElement(){
    int arr[5] = {12, 4, 7, 11, 5};
    Set<int> set1(arr,5);
    bool value = set1.HasElement(11);
    assert(value == 1);
}

void AddNew(){
    int arr1[5] = {12, 4, 7, 11, 5};
    int arr2[6] = {12, 4, 7, 11, 5, 6};
    Set<int> set(arr1,5);
    set.Add(6);
    Set<int> expected(arr2,6);
    assert(set == expected);
}

void Comparison(){
    int arr1[7] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[7] = {2, 7, 5, 4, 3, 6, 1};
    Set<int> set(arr1,7);
    Set<int> expected(arr2,7);
    assert(set == expected);
}

void AddNotNew(){
    int arr1[5] = {12, 4, 7, 11, 5};
    Set<int> set(arr1,5);
    set.Add(4);
    Set<int> expected = set;
    assert(set == expected);
}

void GetLength(){
    int arr1[5] = {12, 4, 7, 11, 5};
    Set<int> set(arr1,5);
    assert(set.Get_Length() == 5);
}

void Concat(){
    int arr1[5] = {12, 4, 7, 11, 5};
    int arr2[4] = {3, 11, 8, 0};
    int arrres[8] = {3, 4, 5, 8, 7, 12, 11, 0};
    Set<int> set1(arr1,5);
    Set<int> set2(arr2,4);
    Set<int> setr(arrres,8);
    assert (set1.concat(set2) == setr);
}

void Intersection(){
    int arr1[5] = {12, 4, 0, 11, 5};
    int arr2[4] = {3, 11, 8, 0};
    int arrres[2] = {11, 0};
    Set<int> set1(arr1,5);
    Set<int> set2(arr2,4);
    Set<int> setr(arrres,2);
    assert (set1.intersection(set2) == setr);
}

void Subtraction(){
    int arr1[5] = {12, 4, 0, 11, 5};
    int arr2[4] = {3, 11, 8, 0};
    int arrres[3] = {12, 4, 5};
    Set<int> set1(arr1,5);
    Set<int> set2(arr2,4);
    Set<int> setr(arrres,3);
    assert (set1 - set2 == setr);
}

void Subset(){
    int arr1[5] = {12, 4, 0, 11, 5};
    int arr2[4] = {12, 11, 5, 0};
    Set<int> set1(arr1,5);
    Set<int> set2(arr2,4);
    assert (set1.subset(set2));
}

void maptest(){
    int arr5[] = {1, 2, 3, 4, 5};
    Set<int> array(arr5, 5);
    map<int, Set<int>> t = {{1, array}};
    int z = 1;
    int first = t[z].HasElement(6);
    int second = t[z].HasElement(5);
    assert(first == 0 && second == 1);
}

int sum(const int& a, const int& b){
    return a+b;
}

int multiplication(const int& a, const int& b){
    return a*b;
}

int intdevide(const int& a, const int& b){
    return a/b;
}

int foo(const int& garbage){
    return 1;
}

void functions(){
    int a = 18, b = 4;
    int(f[3]) = {sum(a, b), multiplication(a, b), intdevide(a, b)};
    Set<int> set(f, 3);
    assert(set.get(0) == 22 && set.get(1) == 72 && set.get(2) == 4);
    assert(set.HasElement(multiplication(a, b)));
    assert(!set.HasElement(foo(a)));
    set.Add(foo(a));
    assert(set.Get_Length() == 3);
}

void students(){
    Person_ID mypassport = Person_ID(6357, 010400);
    Date mybirthday(1895, 12, 14);
    person me("Albert", "Frederick", "George", mybirthday, mypassport);

    Person_ID mybrospassport = Person_ID(6357, 339417);
    Date mybrosbirthday(1894, 06, 23);
    person bro("Edward", "Patrick", "David", mybrosbirthday, mybrospassport);

    Person_ID mysisterspassport = Person_ID(6123, 180898);
    Date mysistersbirthday(1897, 04, 25);
    person sister("Mary", "Victoria", "Alexandra", mysistersbirthday, mysisterspassport);

    student student1(me, "B13-144");
    student student2(bro, "B12-144");
    student student3(sister, "B15-144");
    student Class[2] = {student1, student2};
    Set set1(Class, 2);
    assert(set1.get(1).get_group() == "B12-144" && set1.HasElement(student1) && set1.Get_Length() == 2);
    set1.Add(student3);
    assert(set1.Get_Length() == 3);
}


void Tests(){
    HasElement();
    AddNew();
    Comparison();
    AddNotNew();
    GetLength();
    Concat();
    Intersection();
    Subtraction();
    Subset();
    maptest();
    functions();
    students();
}
#endif
