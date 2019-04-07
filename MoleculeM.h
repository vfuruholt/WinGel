#pragma once

#include <vcclr.h>
#include "IDrawable.h"
#include "GelCore/Molecule.hh"

namespace WinGel
{
	public ref class MoleculeM : IDrawable
	{
	private:
		GelCore::Molecule* _molecule;
	public:
		MoleculeM(System::String^ filename) { 
			pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
			int len = (filename->Length+1) * 2;
			char* ch = new char[len];
			size_t* p = 0;
			if (wcstombs_s(p, ch, len, wch, len) != -1)
				_molecule = new GelCore::Molecule(std::string(ch));
		}
		~MoleculeM() { delete _molecule; }

		virtual System::Void Load() {}
		virtual System::Void DrawPoints() { _molecule->DrawPoints(); }
		virtual System::Void DrawLines() { _molecule->DrawLines(); }
		virtual System::Void DrawFilled() {}

		virtual GelCore::Drawable* GetUnmanaged() { return _molecule; }
	};
}
