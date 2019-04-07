#pragma once

#include <vcclr.h>
#include "IDrawable.h"
#include "GelCore/Horizon.hh"

namespace WinGel
{
	public ref class HorizonM : IDrawable
	{
	private:
		GelCore::Horizon* _horizon;
	public:
		HorizonM(System::String^ filename) { 
			pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
			int len = (filename->Length+1) * 2;
			char* ch = new char[len];
			size_t* p = 0;
			if (wcstombs_s(p, ch, len, wch, len) != -1)
				_horizon = new GelCore::Horizon(std::string(ch));
		}
		~HorizonM() { delete _horizon; }

		virtual System::Void Load() {}
		virtual System::Void DrawPoints() { _horizon->DrawPoints(); }
		virtual System::Void DrawLines() { _horizon->DrawLines(); }
		virtual System::Void DrawFilled() {}

		virtual GelCore::Drawable* GetUnmanaged() { return _horizon; }
	};
}
