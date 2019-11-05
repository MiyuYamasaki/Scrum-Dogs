#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm>

using namespace std;

template <typename T>
class vector
{
	private:
		int size_v;
		T* elem;
		int space;
	
	public:
		vector() : size_v{0}, elem{nullptr}, space{0} {}

		explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s}
		{
			for (int i = 0; i < size_v; ++i)
				elem[i] = T();
		}

		vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space}
		{
			elem = new T[src.size_v];
			copy(src.elem, src.elem + src.size_v, p);
		}

		vector &operator=(const vector &src)
		{
			T* p = new T[src.size_v];
			copy(src.elem, src.elem + src.size_v, p);
			delete[] elem;
			elem = p;
			size_v = src.size_v;
			return *this;
		}

		~vector() {
			delete[] elem;
		}

		T &operator[](int n) {
			return elem[n];
		}

		const T &operator[](int n) const {
			return elem[n];
		}

		int size() const {
			return size_v;
		}

		int capacity() const {
			return space;
		}

		void resize(int newsize)
		{
			reserve(newsize);
			for (int i = size_v; i < newsize; ++i)
				elem[i] = T();
			size_v = newsize;
		}

		void push_back(T d)
		{
			if (space == 0)
				reserve(8);
			else if (size_v == space)
				reserve(2 * space);
			elem[size_v] = d;
			++size_v;
		}

		void reserve(int newalloc)
		{
			T* p = new T[newalloc];
			copy(elem, elem + size_v, p);
			delete [] elem;
			elem = p;
			size_v = newalloc;
		}

		using iterator = double *;
		using const_iterator = const double *;

		iterator begin()
		{
			if (size_v == 0)
				return nullptr;
			return &elem[0];
		}

		const_iterator begin() const
		{
			if (size_v == 0)
				return nullptr;
			return &elem[0];
		}

		iterator end()
		{
			if (size_v == 0)
				return nullptr;
			return &elem[size_v];
		}

		const_iterator end() const
		{
			if (size_v == 0)
				return nullptr;
			return &elem[size_v];
		}

		iterator insert(iterator p, const double &val) // insert a new element val before p
		{
			// make sure we have space

			// the place to put value

			// copy element one position to the right
			// insert value

			return nullptr; // temp remove & replace
		}

		iterator erase(iterator p) // remove element pointed to by p
		{
			if (p == end())
				return p;
			for (iterator pos = p + 1; pos != end(); ++pos)
				*(pos - 1) = *pos; // copy element one position to the left
			//delete (end() - 1);
			--size_v;
			return p;
		}
	};
};

#endif
