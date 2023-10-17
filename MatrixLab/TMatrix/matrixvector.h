// Copyright (c) Anikin Maksim Aleksandrovich

#ifndef INCLUDE_MATRIX_H_
#define INCLUDE_MATRIX_H_

#include <iostream>

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<typename T>
class TVector {
protected:
  size_t _size;
  T* pMem;
public:
  TVector(size_t sz = 1) : _size(sz) {
    if (sz == 0)
      throw std::length_error("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
      throw std::length_error("Vector size cannot be greater than MAX_VECTOR_SIZE = ", MAX_VECTOR_SIZE);
    pMem = new T[sz]();
  }

  TVector(T* data, size_t sz) : _size(sz) {
    // еще один способ ввода исключений
    assert(data != nullptr && "TVector constructor requires non-nullptr argument.");
    pMem = new T[sz];
    // дл€ массивов можно использовать std-функции с условием, что вы знаете как они там реализованы!
    std::copy(data, data + sz, pMem);
  }

  TVector(const TVector& v) {
      _size = v._size;
      pMem = v.pMem;
  }

  TVector(TVector&& v) : _size(0), pMem(nullptr) {
      std::swap(_size, v._size);
      std::swap(pMem, v.pMem);
  }

  ~TVector() {
      delete[] _size;
      pMem = nullptr;
  }

  TVector& operator=(const TVector& v) {
      this->_size = v._size;
      this->pMem = new T[_size];
      std::copy(v.pMem, v.pMem + _size, pMem);
      return *this;
  }

  TVector& operator=(TVector&& v) {
      _size = 0;
      pMem(nullptr);
      std::swap(_size, v._size);
      std::swap(pMem, v.pMem);
  }

  size_t size() const noexcept {
      return _size;
  }

  // индексаци€
  T& operator[](size_t ind) {
        return pMem[ind];
  }
  const T& operator[](size_t ind) const {
        return pMem[ind];
  }

  // индексаци€ с контролем - почитать в чЄм разница и объ€снить при сдаче работы
    T& at(size_t ind) {
        if (ind < 0 || ind >= _size) {
            throw std::length_error("Vector[index] out of range");
        }
        else {
            return pMem[ind];
        }
    }
    const T& at(size_t ind) const {
        if (ind < 0 || ind >= _size) {
            throw std::length_error("Vector[index] out of range");
        }
        else {
            return pMem[ind];
        }
    }

  // сравнение
    bool operator==(const TVector& v) const noexcept {
        if (_size != v._size)
            return 0;
        for (int i = 0; i < (_size > v.size) ? _size : v._size; i++) {
            if (pMem[i] != v.pMem[i]) {
                return 0;
            }
        }
        return 1;
    }
    bool operator!=(const TVector& v) const noexcept {
        return !(*this == v)
    }

    TVector operator+(T val) {
        TVector<T> Ret(*this)
        for (int i = 0; i < _size; i++) {
            Ret[i] += val;
        }
        return Ret;
    }
    TVector operator-(T val) {
        TVector<T> Ret(*this)
            for (int i = 0; i < _size; i++) {
                Ret[i] -= val;
            }
        return Ret;
    }
    TVector operator*(T val) {
        TVector<T> Ret(*this)
            for (int i = 0; i < _size; i++) {
                Ret[i] *= val;
            }
        return Ret;
    }

    TVector operator+(const TVector& v) {
        assert(_size == v._size && "Dimension error");
        TVector<T> Ret[*this];
        for (int i = 0; i < _size; i++) {
            Ret[i] += v[i];
        }
        return Ret;
    }
    TVector operator-(const TVector& v) {
        assert(_size == v._size && "Dimension error");
        TVector<T> Ret[*this];
        for (int i = 0; i < _size; i++) {
            Ret[i] -= v[i];
        }
        return Ret;
    }

    // почитать о noexcept(noexcept(T())) - объ€снить назначение при сдаче
    T operator*(const TVector& v) noexcept(noexcept(T())) {
        assert(_size == v._size && "Dimension error");
        T ScalarP = 0;
        for (int i = 0; i < _size; i++) {
            ScalarP += (*this)[i] * v[i];
        }
        return ScalarP;
    }

    friend void swap(TVector& lhs, TVector& rhs) noexcept;

    // ввод/вывод
    friend istream& operator>>(istream& istr, TVector& v);
    friend ostream& operator<<(ostream& ostr, const TVector& v);
};

template <class T>
void swap(TVector<T>& lhs, TVector<T>& rhs) noexcept {
  std::swap(lhs.sz, rhs.sz);
  std::swap(lhs.pMem, rhs.pMem);
}

// ввод/вывод
template <class T>
std::istream& operator>>(std::istream& istr, TVector<T>& v) {
  for (size_t i = 0; i < v.sz; i++)
    istr >> v.pMem[i];
  return istr;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v) {
  for (size_t i = 0; i < v.sz; i++)
    ostr << v.pMem[i] << ' ';
  return ostr;
}

template<typename T>
class TMatrix : private TVector<TVector<T>> {
  using TVector<TVector<T>>::pMem;
  using TVector<TVector<T>>::sz;
public:
  TMatrix(size_t s = 1) : TVector<TVector<T>>(s) {
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TVector<T>(sz);
  }
  // почему можно сделать так? ќбъ€снить.
  using TVector<TVector<T>>::operator[];

  // сравнение
  bool operator==(const TMatrix& m) const noexcept {
      if (sz != m.sz) { return 0; }
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              if (pMem[i][j] != m.pMem[i][j])
                  return 0;
          }
      }
      return 1;
  }
  bool operator!=(const TMatrix& m) const noexcept {
      return !(*this == m);
  }

  // матрично-скал€рные операции
  TMatrix operator*(const T& val) {
      TMatrix ScalarP(*this);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              pMem[i][j] *= val;               
          }
      }
      return ScalarP;
  }

  // матрично-векторные операции
  TVector<T> operator*(const TVector<T>& v) {
      TVector<T> Matrix_Vector(sz);
      for (int i = 0; i < sz; i++) {
          Matrix_Vector[i] = 0;
          for (int k = 0; k < sz; k++) {
              Matrix_Vector[i] += this->pMem[k][i] * v.pMem[k];
          }
      }
      return Matrix_Vector;
  }

  // матрично-матричные операции
  TMatrix operator+(const TMatrix& m) {
      TMatrix Res(*this);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              pMem[i][j] += m.pMem[i][j];
          }
      }
      return Res;
  }
  TMatrix operator-(const TMatrix& m) {
      TMatrix Res(*this);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              pMem[i][j] -= m.pMem[i][j];
          }
      }
      return Res;
  }
  TMatrix operator*(const TMatrix& m);

  // ввод/вывод
  friend istream& operator>>(istream& istr, TMatrix& m)
  friend ostream& operator<<(ostream& ostr, const TMatrix& m);
};

template <class T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& m) {
    for (int i = 0; i < m.sz; i++) {
        for (int k = 0; k < m.sz; k++) {
            istr >> m[i][k];
        }
    }
    return istr;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& m) {
    for (int i = 0; i < m.sz; i++) {
        for (int k = 0; k < m.sz; k++) {
            ostr << m[i][k];
        }
    }
    return ostr;
}

#endif  // INCLUDE_MATRIX_H_
