#pragma once
#include <iostream>

using elem_type = unsigned int;

class TBitField {
private:
  size_t bitLen;                      // ����� �������� ���� (������������ ���������� �������� ��-�� ��-��, �������� ��������)
  size_t memLen;                      // ���-�� ���������, ����������� ��� �������� �������� ����
  elem_type* pMem;                    // ������ ��� ������������� �������� ����

  // ��������� ���� (�� �����������)
    // size_t bitsInElem;
    // size_t shiftSize;

  // ��������� ������

  // ������ � p��� ��� ���� pos
  size_t GetMemIndex(size_t pos) const //noexcept 
  {
	  if (pos < 0 || pos >= bitLen)
		  throw ("pos out of range");
	  else
		  return (pos / (sizeof(elem_type)) * 8);
  }

  // ������� ����� ��� ���� pos
  elem_type GetMemMask(size_t pos) const //noexcept 
  {
	  if (pos < 0 || pos >= bitLen)
		  throw("pos out of range");
	  int i;
	  i = pos % (8 * sizeof(elem_type));
	  return 1 << i;
  }

public:
  // ������������ ����������
  TBitField(size_t _BitLen);                             // ����������� ������������ ����
  TBitField(const TBitField& bf);                        // ����������� �����������
  //TBitField(TBitField&& bf) noexcept;                    // move-����������� (����������� ����������� bf � this)
  ~TBitField();                                          // ����������

  TBitField& operator=(const TBitField &bf);
  //TBitField& operator=(TBitField &&bf) noexcept;
  bool operator==(const TBitField &bf) const noexcept;
  bool operator!=(const TBitField &bf) const noexcept;

  bool test(size_t i) const;                             // �������� �������� ���� i
  void set(size_t i);                                    // ���������� ��� i
  void reset(size_t i);                                  // �������� ��� i

  TBitField  operator|(const TBitField &bf);             // ���
  TBitField  operator&(const TBitField &bf);             // �
  TBitField  operator~(void);                            // ���������

  // �������� ����� (�-�� �����)
  size_t size() const noexcept;

  //friend void swap(TBitField& lhs, TBitField& rhs) noexcept;

  // ����/�����
  friend std::istream& operator>>(std::istream& istr, TBitField& bf);
  friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf);
};

TBitField::TBitField(size_t _BitLen) {
	if (_BitLen <= 0)
		throw "len <= 0";
	else {
		bitLen = _BitLen;
		memLen = (_BitLen - 1) / (8 * sizeof(elem_type)) + 1;
		pMem = new elem_type[memLen];
		for (int i = 0; i < memLen; i++) {
			pMem[i] = 0;
		}
	}
}

TBitField::TBitField(const TBitField& bf) {
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	pMem = new elem_type[memLen];
	for (int i = 0; i < memLen; i++) {
		pMem[i] = bf.pMem[i];
	}
}

TBitField::~TBitField() {
	delete[] pMem;
}

TBitField& TBitField::operator=(const TBitField& bf) {
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	delete[] pMem;
	pMem = new elem_type[memLen];
	for (int i = 0; i < memLen; ++i)
	{
		pMem[i] = bf.pMem[i];
	}
	return *this;
}

bool TBitField::operator==(const TBitField& bf) const noexcept {
	if (bitLen != bf.size())
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < memLen; ++i)
		{
			if (pMem[i] != bf.pMem[i])
				return 0;
		}
	}
	return 1;
}

bool TBitField::operator!=(const TBitField& bf) const noexcept {
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) {
	int cor_len = bitLen;
	if (bf.bitLen > bitLen)
	{
		cor_len = bf.bitLen;
	}
	TBitField result(cor_len);
	for (int i = 0; i < memLen; i++)
	{
		result.pMem[i] = pMem[i] | bf.pMem[i];
	}
	return result;
}

TBitField TBitField::operator&(const TBitField& bf) {
	int cor_len = bitLen;
	if (bf.bitLen > bitLen)
	{
		cor_len = bf.bitLen;
	}
	TBitField result(cor_len);
	for (int i = 0; i < memLen; i++)
	{
		result.pMem[i] = pMem[i] & bf.pMem[i];
	}
	return result;
}

TBitField TBitField::operator~(void) {
	TBitField tmp(*this);
	for (int i = 0; i < bitLen; ++i)
	{

		if (test(i) == 0)
		{
			tmp.set(i);
		}
		else
		{
			tmp.reset(i);
		}
	}
	return tmp;
}

std::istream& operator>>(std::istream& istr, TBitField& bf) {
	for (int i = 0; i < bf.size(); ++i)
	{
		int input;
		istr >> input;
		if (input) bf.set(i);
	}
	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const TBitField& bf) {
	for (int i = 0; i < bf.size(); ++i)
	{
		ostr << bf.test(i) << " ";
	}
	ostr << "\n";
	return ostr;
}

size_t TBitField::size() const noexcept {
	return bitLen;
}

bool TBitField::test(size_t i) const {
	if (i < 0 || i >= bitLen)
		throw ("i out of range");
	else {
		return pMem[GetMemIndex(i)] & GetMemMask(i);
	}
}

void TBitField::set(size_t i) {
	if (i < 0 || i >= bitLen)
		throw ("i out of range");
	else {
		pMem[GetMemIndex(i)] |= GetMemMask(i);
	}
}
void TBitField::reset(size_t i) {
	if (i < 0 || i >= bitLen)
		throw ("i out of range");
	else {
		pMem[GetMemIndex(i)] &= (~(GetMemMask(i)));
	}
}
