#pragma once

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <utility>
#include <utility>

using namespace std;

class ArrayException
{
public:
	explicit ArrayException(std::string error)
		: m_error(std::move(std::move(error)))
	{
	}

	const char* getError() { return m_error.c_str(); }

private:
    std::string m_error;

};

template <class T>
class DynamicArray
{
public:
	DynamicArray(T* items, int count) 
	{
		this->items = new T[count];

		for (int i = 0; i < count; i++) {
			this->items[i] = items[i];
		}

		this->size = count;

		this->itemsCheck = new bool[count];
		for (int i = 0; i < size; i++)
			this->itemsCheck[i] = true;
	}

	explicit DynamicArray(int size)
	{
		if (size < 0) {
			throw out_of_range("IndexOutOfRange");
		}
		
		this->items = new T[size];
		this->itemsCheck = new bool[size];
		for (int i = 0; i < size; i++)
			this->itemsCheck[i] = false;
		this->size = size;
	}

	DynamicArray(const DynamicArray<T>& array)
	{
		this->items = array.items;
		this->size = array.size;
		this->itemsCheck = array.itemsCheck;
	}

public:
	int getSize()
	{
		return this->size;
	}

	T get(const int index) const
	{
		if (index < 0 || index >= this->size || !this->itemsCheck[index])
			throw out_of_range("IndexOutOfRange");
		return this->items[index];
	}

public:
	void set(const int index, const T value)
	{
		if (index < 0 || index >= this->size)
			throw out_of_range("IndexOutOfRange");
		this->items[index] = value;
		this->itemsCheck[index] = true;
	}

	void resize(int newSize)
	{
		if (newSize < 0) {
			throw out_of_range("IndexOutOfRange");
		}

		T* items2 = new T[newSize];
		bool* itemsCheck2 = new bool[newSize];

		int count = 0;

		if (newSize > this->size) {
			count = this->size;
		}
		else {
			count = newSize;
		}

		for (int i = 0; i < count; i++) {
			items2[i] = items[i];
			itemsCheck2[i] = this->itemsCheck[i];
		}

		this->items = items2;
		this->itemsCheck = itemsCheck2;
		this->size = newSize;
	}
  
	void concat(DynamicArray<T>* arr) {
		int count = this->size;
		this->resize(count + arr->size);
		for (int i = 0; i < arr->size; i++) {
			items[count + i] = arr[i];
			items[count + i] = arr->itemsCheck[i];
		}
	}

private:
    T* items;
    bool* itemsCheck{};
    int size{};


};

#endif 


