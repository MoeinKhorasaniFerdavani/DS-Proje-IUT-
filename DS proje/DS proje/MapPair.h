#pragma once
#include <iostream>
using namespace std;
template <class K,class T>
class MapPair
{
	K key;
public:
	T value;

	MapPair(const K& key, const T& value)
	{
		this->key = key;
		this->value = value;
	}
	K getKey() { return this->key; }
	bool operator> (const MapPair<K, T>& other)
	{
		return (this->key > other.key);
	}
	bool operator< (const MapPair<K, T>& other)
	{
		return (this->key < other.key);
	}
	bool operator>= (const MapPair<K, T>& other)
	{
		return (this->key >= other.key);
	}
	bool operator<= (const MapPair<K, T>& other)
	{
		return (this->key <= other.key);
	}
	bool operator== (const MapPair<K, T>& other)
	{
		return (this->key == other.key);
	}
	bool operator!= (const MapPair<K, T>& other)
	{
		return (this->key != other.key);
	}
};
