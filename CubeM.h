#pragma once

#include "IDrawable.h"
#include "GelCore/Cube.hh"

namespace WinGel
{
	public ref class CubeM : IDrawable
	{
	private:
		GelCore::Cube* _cube;
	public:
		CubeM(int nx, int ny, int nz, double csx, double csy, double csz, double sx, double sy, double sz) { 
			_cube = new GelCore::Cube(nx, ny, nz, csx, csy, csz, sx, sy, sz);
		}
		~CubeM() { delete _cube; }

		virtual System::Void Load() {}
		virtual System::Void DrawPoints() {}
		virtual System::Void DrawLines() { _cube->DrawLines(); }
		virtual System::Void DrawFilled() {}

		virtual GelCore::Drawable* GetUnmanaged() { return _cube; }
	};
}
