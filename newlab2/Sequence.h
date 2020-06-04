#pragma once

#ifndef SEQUENCE_H
#define SEQUENCE_H

template <class T>
class Sequence
{
public:
	[[nodiscard]] virtual int getLength() const = 0;
	virtual T getFirst() const = 0;
	virtual T getLast() const = 0;
	virtual T get(int i) const = 0;
	
public:
	virtual void append(T value) = 0;
	virtual void prepend(T value) = 0;
	virtual void insertAt(int index, T value) = 0;
	
};

#endif