#pragma once

#include <stdexcept>

using namespace std;

template <typename ELT>
class FixedVector {
private:
	int _length;
	ELT *_array;

public:
	// length copies of default_value
	FixedVector(int length) {
		if (length < 0) throw invalid_argument("length < 0");
		_length = length;
		_array = new ELT[length];
	}

	// default constructor: empty vector
	FixedVector() {
		_length = 0;
		_array = new ELT[0];
	}

	// copy constructor
	FixedVector(const FixedVector& a) {
		_length = a._length;
		_array = new ELT[length];
		for (int i = 0; i < length; i++)
			_array[i] = a._array[i];
	}

	~FixedVector() { delete[] _array; }

	int length() { return _length; }

	bool is_empty() { return (_length == 0); }

	ELT& get(int index) {
		if ((index < 0) || (index >= _length)) throw range_error("index out of bounds");
		return _array[index];
	}

	void set(int index, ELT value) {
		if (is_empty()) throw invalid_argument("array is empty");
		if ((index < 0) || (index >= _length)) throw range_error("index out of bounds");
		_array[index] = value;
	}

	ELT& operator[](int index) {
		if ((index < 0) || (index >= _length)) throw range_error("index out of bounds");
		return get(index);
	}
};

