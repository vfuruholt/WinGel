#pragma once

#include "Matrix4.h"

namespace Gel
{
	public ref class Vector4
	{
	public:
		Vector4(void);
		Vector4(GLdouble* values);
		//Vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble p);
		
		GLdouble operator[] (int i) {
			return (safe_cast<GLdouble>(entries[i]));
		}
		inline System::Void Clear() {
			for (int i=0; i<4; ++i) {
				entries[i] = 0.0;
			}
		}
		System::Void Normalize();
		inline GLdouble Get(unsigned i) { return safe_cast<GLdouble>(entries[i]); }
		inline System::Void Set(unsigned i, GLdouble d) { entries[i] = d; }
		GLdouble DotProduct(Vector4^ v);
		System::Void Multiply(Matrix4^ m, Vector4^ result);
	private:
		System::Collections::ArrayList entries;
	};
}