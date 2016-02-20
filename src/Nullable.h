/*
 * Nullable.h
 *
 *  Created on: Feb 20, 2016
 *      Author: troym
 */

#ifndef SRC_NULLABLE_H_
#define SRC_NULLABLE_H_

template<class T>
class Nullable {
public:
	Nullable();
	Nullable(T value);
	bool HasValue();
	T GetValue();

private:
	bool hasValue;
	T value;
};

template<class T>
Nullable<T>::Nullable() {
	hasValue = false;
}

template<class T>
Nullable<T>::Nullable(T value) {
	this->value = value;
	hasValue = true;
}

template<class T>
bool Nullable<T>::HasValue() {
	return hasValue;
}

template<class T>
T Nullable<T>::GetValue() {
	return value;
}

#endif /* SRC_NULLABLE_H_ */
