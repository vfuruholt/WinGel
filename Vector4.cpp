#include "StdAfx.h"
#include <Math.h>
#include "Vector4.h"

using namespace Gel;

Vector4::Vector4(void)
{
	GLdouble zero = 0.0;
	// Default to null vector.
	for (int i=0; i<4; ++i) {
		entries.Add(zero);
	}
}

Vector4::Vector4(GLdouble* values)
{
	for (int i=0; i<4; ++i) {
		entries.Add(values[i]);
	}
}

System::Void Vector4::Normalize()
{
	GLdouble norm = sqrt(this->DotProduct(this));

	for (int i=0; i<4; ++i) {
		this->Set(i, this->Get(i)/norm);
	}
}

GLdouble Vector4::DotProduct(Gel::Vector4^ v)
{
	GLdouble val = 0.0;
	for (int i=0; i<4; ++i) {
		val += this->Get(i) * v->Get(i);
	}

	return val;
}

System::Void Vector4::Multiply(Gel::Matrix4^ m, Gel::Vector4^ result)
{
	result->Clear();

	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			result->Set(i,result->Get(i)+m->Get(i,j) * this->Get(j));
		}
	}
}
