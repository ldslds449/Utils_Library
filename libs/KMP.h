// --------------------------------------------------------------------
// Create a KMP Algorithm
// Author: malecat
// Date: 20200424
// Verification: PASSED
// reference: https://www.ptt.cc/bbs/b99902HW/M.1300796484.A.EE1.html
// --------------------------------------------------------------------

#ifndef LDS_KMP_H
#define LDS_KMP_H

#include <cstdint>

namespace lds
{

template <typename T>
class KMP
{
private:
  const T *data;
  int64_t data_size;
  int64_t *failure = nullptr;

  void genFailure(const T *target, const int64_t &target_size);

public:
  KMP(const T *_data, const int64_t &_data_size); // constructor
  ~KMP(); // destructor

  int64_t find(const T *target, const int64_t &target_size);
};

} // namespace lds

#endif