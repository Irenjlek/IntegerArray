#pragma once
class IntegerArray
{
private:
	int _length;
	int* _data;

public:
	IntegerArray() = default;
	IntegerArray(int length);
	IntegerArray(const IntegerArray& a);
	~IntegerArray();

	void erase();
	int& operator[](const int index);
	IntegerArray& operator=(const IntegerArray& a);
	int getLength() const;
	void reallocate(int newLength);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void remove(int index);
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	int FirstIndexOf(const int value);
};

