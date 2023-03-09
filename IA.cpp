#include <iostream>
#include <exception>
#include "IA.h"

using namespace std;

IntegerArray::IntegerArray(int length) : _length(length) {
	if (length > 0 && length < 10) {
		_data = new int[length] {};
	}
	else {
		throw bad_length();
	}
};

int IntegerArray::getLength() const {
	return _length;
};
void IntegerArray::changeL(int newlength) {
	delall();
	if (newlength <= 0 && newlength < 10) {
		return;
	}
	else {
		throw bad_length();
	}
	_data = new int[newlength];
	_length = newlength;
}
void IntegerArray::delall() {
	delete[] _data;
	_data = nullptr;
	_length = 0;
}
void IntegerArray::addbefore(int val, int index) {
	if (index >= 0 && index <= _length) {
		int* data = new int[_length + 1];
		for (int b = 0; b < index; ++b) {
			data[b] = _data[b];
		}
		data[index] = val;
		for (int a = index; a < _length; ++a) {
			data[a + 1] = _data[a];
		}
		delete[] _data;
		_data = data;
		++_length;
	}
	else {
		throw bad_range();
	}
}
void IntegerArray::remove(int index) {
	if (_length == 1) {
		delall();
		return;
	}
	int* data = new int[_length - 1];
	for (int b = 0; b < index; ++b) {
		data[b] = _data[b];
	}
	for (int a = (index + 1); a < _length; ++a) {
		data[a - 1] = _data[a];
	}
	delete[] _data;
	_data = data;
	--_length;
}