#pragma once

#include <iostream>

template <class T> class TVector;
template <class T> std::ostream& operator<<(std::ostream& ostr, const TVector<T>& vec);


template<class T>
class InIterator : public std::iterator<std::input_iterator_tag, T> {
private:
	T* ptr;
	InIterator(T* p) : ptr(p) { }
public:
	InIterator(const InIterator& it) : ptr(it.ptr) { }

	bool operator ==(const InIterator& it) {
		return ptr == it.ptr;
	}
	bool operator!=(const InIterator& it) {
		return ptr != it.ptr;
	}
	T& operator*() { 
		return *ptr;
	}
	InIterator& operator ++() {
		++ptr;
		return *this;
	}
};

template<class T>
class OutIterator : public std::iterator<std::output_iterator_tag, T> {
private:
	T* ptr;
	OutIterator(T* p) : ptr(p) { };
public:
	OutIterator(const OutIterator& it) : ptr(it.ptr) { };
	bool operator ==(const OutIterator& it) const {
		return ptr == it.ptr;
	}
	bool operator!=(const OutIterator& it) const {
		return ptr != it.ptr;
	}
	const T& operator*() const {
		return *ptr;
	}
	OutIterator& operator ++() const {
		++ptr;
		return *this;
	}
	OutIterator operator++(T*) {
		OutIterator copy{ *this };
		++ptr;
		return copy;
	}
};

template<class T>
class ForIterator : public std::iterator<std::forward_iterator_tag, T> { };

template<class T>
class BdIterator : public std::iterator<std::bidirectional_iterator_tag, T> { };

template<class T>
class RaIterator : public std::iterator<std::random_access_iterator_tag, T> { };

template <class T>
class TVector {
private:
	T* pMem;
	size_t size;
	typedef InIterator<T> iterator;
	typedef InIterator<const T> const_iterator;
public:
	TVector(size_t _size) : size(_size) {
		pMem = new T[_size];
		for (int i = 0; i < size; i++) {
			pMem[i] = i + 1;
		}
	}
	TVector(const TVector& vec) : size(vec.size) {
		for (int i = 0; i < vec.size; i++) {
			pMem[i] = vec.pMem[i];
		}
	}
	~TVector() {
		delete[] pMem;
		pMem = nullptr;
	}


	T* begin() {
		return &pMem[0];
	}
	T* end() {
		return (&pMem[size - 1]) + 1;
	}

	friend std::ostream& operator<<<T>(std::ostream& ostr, const  TVector<T>& vec);
};
template <class T>
std::ostream& operator<<(std::ostream& ostr, const  TVector<T>& vec) {
	for (int i = 0; i < vec.size; i++) {
		ostr << vec[i] << " ";
	}
	return ostr;
}