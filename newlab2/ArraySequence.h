#pragma once

#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : public Sequence<T>
{
public:
	ArraySequence()
	{
		this->count = 0;
		this->items = new DynamicArray<T>(0);
	}

	explicit ArraySequence(int size)
	{
		this->count = size;
		this->items = new DynamicArray<T>(size);
	}

	ArraySequence(T* items, int new_count)
	{ 
		if (new_count < 0) {
			throw out_of_range("IndexOutOfRange");
		}
		this->items = new DynamicArray<T>(items, new_count);
		count = new_count;
	}

	ArraySequence(const ArraySequence<T>& other) 
	{
		this->items = other.items;
		this->count = other.count;
	}

public:
	[[nodiscard]] int getLength() const override
	{
		return this->items->getSize();
	}

	T getFirst() const override
	{
		if (count < 1)
			throw out_of_range("IndexOutOfRange");
		return this->items->get(0);
	}

	T getLast() const override 
	{ 
		if (count < 1)
			throw out_of_range("IndexOutOfRange");
		return this->items->get(count-1);
	}

	T get(const int i) const override
	{ 
		if ((i < 0) || (i > count))
			throw out_of_range("IndexOutOfRange");
		return this->items->get(i);
	}
	
public:
	void append(T value) override 
	{
		this->items->resize(this->count + 1);
		for (int i = this->count - 1; i >= 0; i--) {
			items[i + 1] = items[i];
		}
		items->set(0, value);
		this->count = this->count + 1;
	}
	
	void prepend(T value) override
	{
		this->items->resize(this->count + 1);
		this->items->set(this->count, value);
		this->count = this->count + 1;
	}
	
	void insertAt(const int index, T value) override 
	{ 
		this->items->set(index, value);
	}

    /*void erase(int index)
    {
	    int controller = 0;
	    T a = {};
        DynamicArray<T> array = DynamicArray(&a, count - 1);
        for(int i = 0; i < this->items->getSize(); i++){
            if(i != index){
                array.set(i - controller, this->items->get(index));
            }
            else controller = 1;
        }
        this->items = array;
        //this->count = this->count - 1;
        //this->items->resize(this->count - 1);
    }*/

private:
    DynamicArray<T>* items;
    int count = {};


};
#endif
