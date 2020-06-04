#ifndef SET_H
#define SET_H

#include "ArraySequence.h"

template <typename T>
class Set{
public:
    Set<T>(){
        T* A = nullptr;
        this->list = new ArraySequence<T>(A, 0);
    };

    Set<T>(T* new_list, int new_size){
        this->list = new ArraySequence<T>(new_list, new_size);
    }

    T get(int index){
        return this->list->get(index);
    }

    T begin(){
        return this->list->getFirst();
    }

    T end(){
        return this->list->getLast();
    }

    Set<T> concat(const Set<T>& new_set){
        Set<T> result = *this;
        for (int i = 0; i < new_set.Get_Length(); ++i) result.Add(new_set.list->get(i));

        return result;
    }

    Set<T> intersection(const Set<T>& new_set){
        Set<T> result;
        T elem;

        if (this->Get_Length() < new_set.Get_Length()){
            for (int i = 0; i < this->Get_Length(); ++i){
                elem = this->list->get(i);
                if (new_set.HasElement(elem)) result.Add(elem);
            }
        }
        else{
            for (int i = 0; i < new_set.Get_Length(); ++i){
                elem = new_set.list->get(i);
                if (this->HasElement(elem)) result.Add(elem);
            }
        }

        return result;
    }

    bool HasElement(const T& elem){
        for (int i = 0; i < list->getLength(); i++){
            if (list->get(i) == elem) return true;
        }

        return false;
    }

    void Add(const T& item){
        if (this->HasElement(item)) return;
        list->prepend(item);
    }

    friend bool operator==(const Set<T>& set1, const Set<T>& set2){
        if (set1.list->getLength() != set2.list->getLength()) return false;
        for (int i = 0; i < set1.list->getLength(); i++){
            if (!set1.HasElement(set2.list->get(i))) return false;
        }

        return true;
    }

    friend Set<T> operator-(const Set<T>& set1, const Set<T>& set2){
        Set<T> result;
        T item;
        for (int i = 0; i < set1.Get_Length(); ++i){
            item = set1.list->get(i);
            if (!set2.HasElement(item)) result.Add(item);
        }

        return result;
    }

    int Get_Length(){
        return list->getLength();
    }

    bool subset(const Set<T>& set){
        if (set.Get_Length() > this->Get_Length()) throw logic_error("Subset can't be bigger then set");
        for (int i = 0; i < set.Get_Length(); ++i) if (!this->HasElement(set.list->get(i))) return false;
        return true;
    }


private:
    ArraySequence<T>* list;
    //int size = 0;
};

#endif
