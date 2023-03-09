#pragma once
#include <exception>

using namespace std;

class bad_range : public exception {
public:
	virtual const char* what() const noexcept override {
		return "Out of bounds!";
	}
};

class bad_length : public exception {
public:
	virtual const char* what() const noexcept override {
		return "Wrong array length!";
	}
};

class IntegerArray {
public:
	IntegerArray() = default;
	IntegerArray(int length) {}
	IntegerArray(const IntegerArray& a) {
		changeL(a.getLength());
		for (int index = 0; index < _length; ++index) {
			_data[index] = a._data[index];
		}
	}

	int& operator[](int index) {
		if (index >= 0 && index < _length) {
			return _data[index];
		}
		else {
			throw bad_range();
		}
	}

	IntegerArray& operator = (const IntegerArray& a) {
		if (&a == this) {
			return *this;
		}
		changeL(a.getLength());
		for (int index = 0; index < _length; ++index) {
			_data[index] = a._data[index];
		}
		return *this;
	}

	int getLength() const {}

	void changeL(int newlength) {}

	void delall() {}

	void addbefore(int val, int index) {}

	void remove(int index) {}

	~IntegerArray() {
		delete[] _data;
	}
private:
	int _length;
	int* _data;
};