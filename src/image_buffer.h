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

#ifndef IMAGE_BUFFER_H
#define IMAGE_BUFFER_H

#include "buffer.h"
#include "color.h"

class ImageBuffer: public Buffer<Color>
{
public:

	ImageBuffer();
	
	ImageBuffer(int width, int height);

	ImageBuffer(Color *data, int width, int height);

	ImageBuffer(const ImageBuffer &buffer);

	const ImageBuffer& operator=(const ImageBuffer &buffer);
	
	virtual ~ImageBuffer() {}

	void set( Color *data, int width, int height);

	int getWidth() const;

	int getHeight() const;

	inline Color operator ()(int x, int y) const{ return _data[y*_width+x]; }
	
	inline Color& operator () (int x, int y){ return _data[y*_width+x]; }

	void toIntArray(unsigned int *data);


protected:
	int _width;
	int _height;
};

#endif
