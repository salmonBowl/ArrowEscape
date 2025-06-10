#pragma once
#include <memory>
#include "SingletonBase.h"
#if false
template <class T>
std::shared_ptr<T> SingletonBase<T>::instance = nullptr;

template <class T>
std::shared_ptr<T> SingletonBase<T>::Instance()
{
	if (!instance)
	{
		instance = std::make_unique<T>();
	}
	return instance;
}
#endif