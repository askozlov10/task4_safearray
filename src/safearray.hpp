////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


// we have to indicate that methods of the class Safearray are also inside the namespace xi
#include "safearray.h"

namespace xi {


template <typename T>
SafeArray<T>::SafeArray(size_t cap)
{
    if(cap <= 0)
       std::__throw_logic_error("Capacity cannot be negative or equal zero");
    _capacity = cap;
    _storage = new T[_capacity];
    // TODO: здесь необходимо добавить реализацию метода
}

    template<typename T>
    SafeArray<T>::~SafeArray() {
        delete[] _storage;
        _storage = nullptr;
    }

    template<typename T>
    SafeArray<T>::SafeArray(const SafeArray& param) {
        if(param._storage == nullptr|| param.getCapacity() <= 0){
            delete [] _storage;
            _storage = nullptr;
        }
        else{
            _capacity = param.getCapacity();
            _storage = new T[_capacity];
            for(int iter = 0; iter < param.getCapacity(); iter++){
                _storage[iter] = param[iter];
            }
        }
    }

    template<typename T>
    T &SafeArray<T>::operator[](size_t k) {
        if(k >= _capacity || k< 0)
            std::__throw_out_of_range("INCORRECT INDEX");
        return _storage[k];
    }

    template<typename T>
    const T &SafeArray<T>::operator[](size_t k) const {
        if(k >= _capacity || k< 0)
            std::__throw_out_of_range("INCORRECT INDEX");
        return _storage[k];
    }

    template<typename T>
    size_t SafeArray<T>::getCapacity() const {
        return _capacity;
    }

    template<typename T>
    void SafeArray<T>::checkBounds(size_t index) const {
        if(index >= _capacity || index< 0)
            std::__throw_out_of_range("INCORRECT INDEX");

    }

    template<typename T>
    SafeArray<T>& SafeArray<T>::operator=(const SafeArray &right) {
        if(this == &right){
            return *this;
        }
        else{
            if(right._storage == nullptr|| right.getCapacity() <= 0){
                delete [] _storage;
                _storage = nullptr;
            }
            else{
                _capacity = right.getCapacity();
                _storage = new T[right.getCapacity()];
                for(int iter = 0; iter < right.getCapacity(); iter++){
                    _storage[iter] = right[iter];
                }
            }

        }
        return  *this;

    }

// TODO: реализуйте остальные методы по образцу выше

} // namespace xi
