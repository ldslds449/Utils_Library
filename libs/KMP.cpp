#include <cstdint>
#include "KMP.h"

namespace lds
{

template <typename T>
KMP<T>::KMP(const T *_data, const int64_t &_data_size)
{
  this->data = _data;
  this->data_size = _data_size;
}

template <typename T>
KMP<T>::~KMP()
{
  // free failure array
  if(this->failure != nullptr){
    delete [] this->failure;
  }
}

template <typename T>
int64_t KMP<T>::find(const T *target, const int64_t &target_size){
  // create failure function
  genFailure(target, target_size);

  // find
  int64_t i = 0, j = 0;
  for(; i < this->data_size; i++){
    while(this->data[i] != target[j] && j > 0){
      j = this->failure[j - 1];
    }
    if(this->data[i] == target[j]){
      j++;
    }
    if(j == target_size){
      return i - j + 1;
    }
  }
  return -1;
}

template <typename T>
void KMP<T>::genFailure(const T *target, const int64_t &target_size){
  // delete previous failure function index
  if(this->failure != nullptr){
    delete [] this->failure;
  }

  // initial
  this->failure = new int64_t[target_size];
  this->failure[0] = 0;

  // create failure function
  int64_t i = 1, j = 0;
  for(; i < target_size; i++){
    while(target[i] != target[j] && j > 0){
      j = this->failure[j];
    }
    if(target[i] == target[j]){ // same
      j++;
      this->failure[i] = j;
    }else{ // different
      this->failure[i] = 0;
    }
  }
}

} // namespace lds
