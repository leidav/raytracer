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

#include "image_buffer.h"
#include <cstdio>
ImageBuffer::ImageBuffer(): Buffer<Color>(),_width(0),_height(0)
{
}

ImageBuffer::ImageBuffer(int width, int height): Buffer<Color>(width*height),
						_width(width),_height(height)
{
}

ImageBuffer::ImageBuffer(Color *data, int width, int height):
				Buffer<Color>(data,width*height),
				_width(width),_height(height)
{
}

ImageBuffer::ImageBuffer(const ImageBuffer &buffer):Buffer<Color>(buffer),
		_width(buffer._width),_height(buffer._height)
{
}



const ImageBuffer& ImageBuffer::operator=(const ImageBuffer &buffer)
{
	Buffer<Color>::operator=(buffer);
	_width=buffer._width;
	_height=buffer._height;
	return *this;
}

void ImageBuffer::set( Color *data, int width, int height)
{
	_width=width;
	_height=height;
	Buffer<Color>::set(data,_width*_height);
	
}

void ImageBuffer::toIntArray(unsigned int *data)
{
	for(int i=0;i<_length;i++) {
		data[i]=_data[i].rgb();
	}
}

int ImageBuffer::getWidth() const 
{
	return _width;
};

int ImageBuffer::getHeight() const
{
	return _height;
};
