#pragma once

#include "IDrawable.h"
#include "GelCore/GlScene.hh"

using namespace GelCore;

namespace WinGel
{
	// Wrapper class for the unmanaged GlScene class.
	ref class GlSceneM
	{
	private:
		GelCore::GlScene* _glScene;
	public:
		GlSceneM(int width, int height) { _glScene = new GlScene(width, height); }
		~GlSceneM(void) { delete _glScene; }

		System::Void Init() { _glScene->Init(); }
		System::Void Render() { _glScene->Render(); }
		System::Void Resize(int width, int height) { _glScene->Resize(width, height); }
		System::Void Rotate(int xPos, int yPos, int dx, int dy) { _glScene->Rotate(xPos, yPos, dx, dy); }
		System::Void Pan(int dx, int dy) { _glScene->Pan(dx, dy); }
		System::Void Zoom(int increment) { _glScene->Zoom(increment); }
		System::Void SetRotAxes() { _glScene->SetRotAxes(); }
		System::Void SetZScale(float zs) { _glScene->SetZScale(zs); }

		System::Boolean AddObject(WinGel::IDrawable^ sceneObj) { return _glScene->AddObject(sceneObj->GetUnmanaged()); }
		System::Boolean RemoveObject(WinGel::IDrawable^ sceneObj) { return _glScene->RemoveObject(sceneObj->GetUnmanaged()); }
	};
}
