#pragma once

#include "GelCore/Drawable.hh"

namespace WinGel
{
	public interface class IDrawable
	{
		System::Void Load();
		System::Void DrawPoints();
		System::Void DrawLines();
		System::Void DrawFilled();

		GelCore::Drawable* GetUnmanaged();
	};
}
