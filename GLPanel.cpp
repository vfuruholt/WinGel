#include "stdafx.h"
#include <Math.h>
#include "GLPanel.h"

using namespace System::Collections;
using namespace WinGel;

System::Void GlPanel::InitGL()
{
	glScene->Init();
}

System::Void GlPanel::Paint()
{
	glScene->Render();
	SwapOpenGLBuffers();
}

System::Void GlPanel::ResizeScene()
{ 
	glScene->Resize(this->Width, this->Height);
}

System::Void GlPanel::RotateScene(int xPos, int yPos, int dx, int dy)
{
	glScene->Rotate(xPos, yPos, dx, dy);
	SwapOpenGLBuffers();
}

System::Void GlPanel::PanScene(int dx, int dy)
{
	glScene->Pan(dx, dy);
	SwapOpenGLBuffers();
}

System::Void GlPanel::ZoomScene(int increment)
{
	glScene->Zoom(increment);
	SwapOpenGLBuffers();
}

System::Void GlPanel::SetZScale(float zs)
{
	glScene->SetZScale(zs);
	SwapOpenGLBuffers();
}

System::Boolean GlPanel::AddObject(IDrawable^ sceneObj)
{
	System::Boolean added = false;
	
	sceneObjects.Add(sceneObj);
	added = glScene->AddObject(sceneObj);

	SwapOpenGLBuffers();
	return added;
}

System::Boolean GlPanel::RemoveObject(IDrawable^ sceneObj)
{
	System::Boolean removed = false;

	sceneObjects.Remove(sceneObj);
	removed = glScene->RemoveObject(sceneObj);

	SwapOpenGLBuffers();
	return removed;
}