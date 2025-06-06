#pragma once
#include <memory>

template<class T>
class SingletonBase
{
public:
	static std::shared_ptr<T> Instance();
	
protected:
	SingletonBase() = default;
	static std::shared_ptr<T> instance;
};

//#include "SingletonBase.inl"

template<class T>
std::shared_ptr<T> SingletonBase<T>::instance = nullptr;

template<class T>
std::shared_ptr<T> SingletonBase<T>::Instance()
{
	if (!instance)
		instance = std::shared_ptr<T>(new T());
	return instance;
}