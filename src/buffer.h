/*Copyright (C) 2013 David Leiter

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BUFFER_H
#define BUFFER_H

template <class T>
class Buffer
{
public:
	Buffer():_data(0),_length(0) {}

	Buffer(int length):_data(new T[length]),_length(length) {}

	Buffer( T *data, int length)
	{
		_data=0;
		set(data,length); 
	}
	
	Buffer(const Buffer<T>& buffer)
	{
		_data=0;
		set(buffer);
	}

	virtual ~Buffer()
	{
		delete[] _data;
	}	
	
	void set( T *data, int length)
	{
		if(_data!=0) {
			delete[] _data;
		}

		_length=length;
		_data= new T[_length];
		
		for(int i=0;i<_length;i++) {
			_data[i]=data[i];		
		}
	}

	void set(const Buffer<T>& buffer)
	{
		if(_data!=0) {
			delete[] _data;
		}
		_length=buffer._length;
		_data= new T[_length];

		for(int i=0;i<_length;i++) {
			_data[i]=buffer._data[i];
		}
	}

	T *getData() const {return _data; }
	
	int getSize() const { return _length*sizeof(T); }

	int getLength() const { return _length; }

	inline T operator [] (int pos) const { return _data[pos]; }
	
	inline T &operator[] (int pos) { return _data[pos]; }

	const Buffer<T>& operator=(const Buffer<T> &buffer)
	{
		set(buffer);
		return *this;
	}

protected:
	T *_data;
	int _length;
	
};
#endif
