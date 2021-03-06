#ifndef __ENUMCLASSOPERATOR_HPP__
#define __ENUMCLASSOPERATOR_HPP__
template<class T> T Operator(const T A, const T B) {
	return static_cast<T>(static_cast<unsigned long>(A) | static_cast<unsigned long>(B));
}
#endif
