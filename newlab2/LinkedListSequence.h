#pragma once

#ifndef LINKEDLISTSEQUENCE_H
#define LINKEDLISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class LinkedListSequence : public Sequence<T>
{
public:
	LinkedListSequence()
	{
		this->count = 0;
		this->items = new LinkedList<T>;
	}

	LinkedListSequence(T* items, int count)
	{
		if (count < 0) {
			throw LinkedException("IndexOutOfRange");
		}
		this->items = new LinkedList<T>(items, count);
		this->count = count;
	}

	LinkedListSequence(const LinkedListSequence<T>& other)     //copy constructor
	{
		this->items = other.items;
		this->count = other.count;
	}
	
public:
	int getLength() const override
	{
		return this->items->getLength();
	}

	T getFirst() const override
	{
		if (count < 1)
			throw LinkedException("IndexOutOfRange");
		return this->items->getFirst();
	}

	T getLast() const override
	{
		if (count < 1)
			throw LinkedException("IndexOutOfRange");
		return this->items->getLast();
	}

	T get(const int i) const override
	{
		if ((i < 0) || (i > count))
			throw LinkedException("IndexOutOfRange");
		return this->items->get(i);
	}
	
public:
	void append(T value) override
	{
		this->items->append(value);
		this->count++;
	}

	void prepend(T value) override 
	{
		this->items->prepend(value);
		this->count++;
	}

	void insertAt(const int index, T value) override
	{ 
		this->items->insertAt(value, index);
		this->count++;
	}

private:
    LinkedList<T>* items;
    int count;

};

#endif