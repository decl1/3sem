#pragma once

#include <iostream>
#include "bitfield.h"

class TSet {
private:
  size_t maxPower;                       // максимальная мощность множества
  TBitField bitField;                    // битовое поле для хранения множества
public:
  TSet(int mp);
  TSet(const TSet &s);

  TSet(const TBitField& bf);
  operator TBitField();                  // преобразование типа к битовому полю

  size_t GetMaxPower() const noexcept;

  void InsElem(size_t Elem);            // включить элемент в множество
  void DelElem(size_t Elem);            // удалить элемент из множества
  bool IsMember(size_t Elem) const;     // проверить наличие элемента в множестве

  TSet operator+ (const int Elem);       // объединение с элементом
  TSet operator- (const int Elem);       // разность с элементом
  TSet operator+ (const TSet &s);        // объединение
  TSet operator* (const TSet &s);        // пересечение
  TSet operator~ ();                     // дополнение

  int operator== (const TSet &s) const;
  int operator!= (const TSet &s) const;
  TSet& operator=(const TSet &s);

  friend std::istream& operator>>(std::istream& in, TSet &bf);
  friend std::ostream& operator<<(std::ostream& out, const TSet &bf);
};


TSet::TSet(int mp) : bitField(mp), maxPower(mp) {}

TSet::TSet(const TSet& s) : bitField(s.bitField), maxPower(s.maxPower) { }

size_t TSet::GetMaxPower() const noexcept {
	return maxPower;
}

TSet::operator TBitField() {
	return bitField;
}

TSet::TSet(const TBitField& bf) : bitField(bf), maxPower(bf.size()) {}

bool TSet::IsMember(size_t Elem) const {
    if (Elem < 0 || Elem >= maxPower) {
        throw "out of range (in IsMember)";
    }
    return bitField.test(Elem);
}

void TSet::InsElem(size_t Elem) {
    if (Elem < 0 || Elem >= maxPower) {
        throw "out of range (in InsElem)";
    }
    return bitField.set(Elem);
}

void TSet::DelElem(size_t Elem) {
    if (Elem < 0 || Elem >= maxPower) {
        throw "out of range (in DelElem)";
    }
    return bitField.reset(Elem);
}

TSet TSet::operator+(const int Elem) {
    if (Elem < 0 || Elem >= maxPower)
    {
        throw "out of range (operator+elem)";
    }
    TSet tmp(bitField);
    tmp.InsElem(Elem);
    return tmp;
}

TSet TSet::operator-(const int Elem) {
    if (Elem < 0 || Elem >= maxPower) {
        throw "out of range (operator-elem)";
    }
    TSet tmp(bitField);
    tmp.DelElem(Elem);
    return tmp;
}

TSet TSet::operator+(const TSet& s) {
    int cor_len = maxPower;
    if (maxPower > s.maxPower) {
        cor_len = maxPower;
    }
    else
        cor_len = s.maxPower;
    TSet tmp(cor_len);
    tmp.bitField = bitField | s.bitField;
    return tmp;
}

TSet TSet::operator*(const TSet& s) {
    int cor_len = maxPower;
    if (maxPower > s.maxPower) {
        cor_len = maxPower;
    }
    else
        cor_len = s.maxPower;
    TSet tmp(cor_len);
    tmp.bitField = bitField & s.bitField;
    return tmp;
}

TSet TSet::operator~() {
    return TSet(~bitField);
}

std::istream& operator>>(std::istream& istr, TSet& s) {
    const int mp = s.maxPower;
    for (int i = 0; i < mp; ++i) {
        int val; 
        istr >> val;
        s.InsElem(val);
    }
    return istr;
}

std::ostream& operator<<(std::ostream& ostr, const TSet& s) {
    const int mp = s.maxPower;
    for (int i = 0; i < mp; ++i) {
        ostr << s.IsMember(i) << " ";
    }
    return ostr;
}

int TSet::operator==(const TSet& s) const {
    return (bitField == s.bitField);
}

int TSet::operator!=(const TSet& s) const {
    return !(*this == s);
}

TSet& TSet::operator=(const TSet& s) {
    maxPower = s.maxPower;
    bitField = s.bitField;
    return *this;
}
