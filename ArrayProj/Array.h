#pragma once
#include "BadLength.h"
#include "BadRange.h"
#include <iostream>

template <typename T> class Array
{
	int _length;
	T* _data;

public:
	Array() = default;
	Array(int length);

	
	Array(const Array& a);
	~Array();

	void erase();
	T& operator[](const int index);
	Array& operator=(const Array& a);
	int getLength() const;
	void reallocate(int newLength);
	void resize(int newLength);
	void insertBefore(T value, int index);
	void remove(int index);
	void insertAtBeginning(T value);
	void insertAtEnd(T value);
	int FirstIndexOf(T& value);
	
};

template<typename T>
inline Array<T>::Array(int length) : _length(length)
{
    if (length <= 0) {
        throw BadLength();
    }
    _data = new T[length];
}

template<typename T>
Array<T>::Array(const Array& a)
{
    reallocate(a.getLength());
    for (int index{ 0 }; index < _length; ++index)
        _data[index] = a._data[index];
}

template<typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template<typename T>
void Array<T>::erase()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

template<typename T>
T& Array<T>::operator[](const int index)
{
    if (index < 0 || index > _length) {
        throw BadRange();
    }
    return this->_data[index];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());
    for (int index = 0; index < _length; ++index)
        _data[index] = a._data[index];

    return *this;
}

template<typename T>
int Array<T>::getLength() const
{
    return _length;
}

template<typename T>
void Array<T>::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;

    _data = new T[newLength];
    _length = newLength;
}

template<typename T>
void Array<T>::resize(int newLength)
{
    if (newLength == _length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    T* data = new T[newLength];
    if (_length > 0)
    {
        int elementsToCopy = (newLength > _length) ? _length : newLength;
        for (int index = 0; index < elementsToCopy; ++index)
            data[index] = _data[index];
    }

    delete[] _data;
    _data = data;
    _length = newLength;
}

template<typename T>
void Array<T>::insertBefore(T value, int index)
{
    if (index < 0 || index > _length) {
        throw BadRange();
    }

    T* data = new T[_length + 1];
    for (int before = 0; before < index; ++before)
        data[before] = _data[before];

    data[index] = value;

    for (int after = index; after < _length; ++after)
        data[after + 1] = _data[after];

    delete[] _data;
    _data = data;
    ++_length;
}

template<typename T>
void Array<T>::remove(int index)
{
    if (index < 0 || index > _length) {
        throw BadRange();
    }

    if (_length == 1)
    {
        erase();
        return;
    }

    T* data = new T[_length - 1];

    for (int before = 0; before < index; ++before)
        data[before] = _data[before];

    for (int after = index + 1; after < _length; ++after)
        data[after - 1] = _data[after];

    delete[] _data;
    _data = data;
    --_length;
}

template<typename T>
void Array<T>::insertAtBeginning(T value)
{
    insertBefore(value, 0);
}

template<typename T>
void Array<T>::insertAtEnd(T value)
{
    insertBefore(value, _length);
}

template<typename T>
int Array<T>::FirstIndexOf(T& value)
{
    for (int j = 0; j < _length; j++) {
        if (_data[j] == value) {
            return j;
        }
    }
    std::cout << "Not found!" << std::endl;
    return -1;
}