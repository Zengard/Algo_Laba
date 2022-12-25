#pragma once
#include <iostream>

constexpr static int defautArrayCapacity = 8;

template<typename T>

class Array final
{
private:
	T* pitems;
	int size_m;
	int capacity_m;

public:
	Array();
	Array(const Array& other);//copy
	Array(Array&& other);// move
	~Array();

	int insert(const T& value);
	int insert(int index, const T& value);
	void remove(int index);

	const T& operator[](int index) const;

	T& operator[](int index);

	//void swap(Array other); //copy-swap

	Array& operator = (const Array& other); // copy operator

	Array& operator = (Array&& other); // move operator

	int size() const;
	int capacity() const;

	class Iterator final {
	protected:

		T* cur;
		Array& arr;
		bool direction;

	public:
		Iterator(Array& const arr, bool direction) : arr(arr), direction(direction) {

			if (direction == true) {
				cur = arr.pitems;
			}
			else
			{
				cur = arr.pitems + arr.size_m - 1;
			}

		}


		const T& get() const {
			return *cur;
		}

		void set(const T& value) {

			*cur = value;
		}

		void next() {
			if (direction == true) {
				cur++;
			}
			else
			{
				cur--;
			}

		}

		bool hasnext() const {
			if (direction == true)
				return cur >= arr.pitems;
			else
				return cur < arr.pitems + arr.size_m;
		}

	};


	class ConstIterator final {
	protected:

		T* cur;
		Array& arr;
		bool direction;

	public:
		ConstIterator(Array& const arr, bool direction) : arr(arr), direction(direction) {

			if (direction == true) {
				cur = arr.pitems;
			}
			else
			{
				cur = arr.pitems + arr.size_m - 1;
			}
		}

		const T& get() const {
			return *cur;
		}

		void next() {
			if (direction == true) {
				cur++;
			}
			else
			{
				cur--;
			}

		}

		bool hasnext() const {
			if (direction == true)
				return cur >= arr.pitems;
			else
				return cur < arr.pitems + arr.size_m;
		}

	};

	Iterator iterator() {
		return Iterator(*this, true);
	}

	ConstIterator constIterator() const {
		return ConstIterator(*this, true);
	}

	Iterator reverseiterator() {
		return Iterator(*this, false);

	}

	ConstIterator reverseconstIterator() const {

		return ConstIterator(*this, false);
	}

};


template<typename T>
Array<T>::Array() : capacity_m(defautArrayCapacity), size_m(0)
{
	pitems = (T*)malloc(sizeof(T) * capacity_m);
}

//copy
template<typename T>
Array<T>::Array(const Array& other)
{
	capacity_m = other.capacity_m;
	size_m = other.size_m;
	pitems = (T*) malloc(sizeof(T) * capacity_m);

	for (int i = 0; i < size_m; i++) {
		new (pitems + i) T(other.pitems[i]);
	}
}


//move
template<typename T>
Array<T>::Array(Array&& other) 
{
	pitems = other.pitems;
	size_m = other.size_m;
	capacity_m = other.capacity_m;

	other.pitems = nullptr;
	other.size_m = 0;
	other.capacity_m = 0;
}

template <typename T>
int Array<T>::insert(const T& value) {
	if (size_m >= capacity_m) {
		capacity_m *= 2;
		T* p = (T*)malloc(capacity_m * sizeof(T));

		for (int i = 0; i < size_m; i++) {
			new (p + i) T(std::move(pitems[i]));
		}

		for (int i = 0; i < size_m; i++) {
			pitems[i].~T();
		}
		free(pitems);
		pitems = p;

	}
		new (pitems + size_m) T(value);
		size_m += 1;
		return size_m - 1;
	
}

template <typename T>
int Array<T>::insert(int index, const T& value) {
	if (index > size_m || index < 0) {
		return -1;
	}

	if (size_m >= capacity_m) {
		capacity_m *= 2;
		T* p = (T*)malloc(capacity_m * sizeof(T));
		
		for (int i = 0; i < size_m; i++) {
			new (p + i) T(std::move(pitems[i]));
		}

		for (int i = 0; i < size_m; i++) {
			pitems[i].~T();
		}
		free(pitems);
		pitems = p;
	}

			for (int i = size_m; i > index; i--) {
				new (pitems + i) T(std::move(pitems[i - 1]));
				pitems[i-1].~T();
		}

		new (pitems + index) T(value);

		size_m++;
		return index;
	
}

template<typename T>
void Array<T>::remove(int index) {

	if (index > size_m || index < 0) {
		return;
	}

	
	for (int i = index; i < size_m-1; i++) {
		pitems[index].~T();
		new (pitems + i) T(std::move(pitems[i + 1]));
	}
	size_m -= 1;


}

template<typename T>
const T& Array<T>::operator[](int index) const
{
	return pitems[index];
}

template<typename T>
T& Array<T>:: operator[](int index)
{
	return pitems[index];
}


/* copy-swap
 
template<typename T>
void Array<T>::swap(Array other) {
	std::swap(pitems, other.pitems);
	std::swap(size_m, other.size_m);
	std::swap(capacity_m, other.capacity_m);

}
template<typename T>
Array<T>& Array<T>:: operator = (Array other)
{
	if (this != other){ 
		Array<T> temp = other;
		swap(temp);
	}
	return *this;
}
*/


//copy operator
template<typename T>
Array<T>& Array<T>:: operator = (const Array& other)
{
	if (this != &other) {
		for (int i = 0; i < size_m; i++) {
			pitems[i].~Array();
		}
		
		free(pitems);
		capacity_m = other.capacity_m;
		size_m = other.size_m;
		pitems = (T*)malloc(sizeof(T) * capacity_m);
			for (int i = 0; i < capacity; i++) {
				new (pitems + i) T(other.pitems[i]);
			}
	
	return *this;
}


//move operator
template<typename T>
Array<T>& Array<T>:: operator = (Array&& other)
{
	if (this != &other) {
		for (int i = 0; i < size_m; i++) {
			pitems[i].~Array();
		}
		free(pitems);

		pitems = other.pitems;
		size_m = other.size_m;
		capacity_m = other.capacity_m;

		other.pitems = nullptr;
		other.size_m = 0;
		other.capacity_m = 0;
	}
	return *this;
}

template<typename T>
int Array<T>:: size() const {

	return size_m;
}

template<typename T>
int Array<T>:: capacity() const {

	return capacity_m;
}

template<typename T>
Array<T>::~Array()
{
	for (int i = 0; i < size_m; i++) {
		pitems[i].~T();
	}

	free(pitems);
}



