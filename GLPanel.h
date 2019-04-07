#pragma once

#include <GL/gl.h>
#include "GlSceneM.h"
#include "CubeM.h"
#include "HorizonM.h"

using namespace System::Windows::Forms;

namespace WinGel
{
	public ref class GlPanel: public System::Windows::Forms::Panel
	{
	public:
		GlPanel(System::Windows::Forms::Form^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{			
			this->Width = iWidth;
			this->Height = iHeight;

			// Specify the form as the parent.
			this->Parent = parentForm;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			this->CreateParams->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				
				glScene = gcnew GlSceneM(this->Width, this->Height);
				InitGL();
			}
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC) ;
		}

		System::Void InitGL();
		System::Void Paint();
		System::Void ResizeScene();
		System::Void RotateScene(int xPos, int yPos, int dx, int dy);
		System::Void PanScene(int dx, int dy);
		System::Void ZoomScene(int increment);
		System::Void SetRotAxis() { glScene->SetRotAxes(); }
		System::Void SetZScale(float zSs);
		System::Boolean AddObject(WinGel::IDrawable^ sceneObj);
		System::Boolean RemoveObject(WinGel::IDrawable^ sceneObj);

	private:
		HDC m_hDC;
		HGLRC m_hglrc;

		GlSceneM^ glScene;
		System::Collections::ArrayList sceneObjects;
		
	protected:
		~GlPanel(System::Void)
		{
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 

				1,                                // version number 

				PFD_DRAW_TO_WINDOW |              // support window 

				PFD_SUPPORT_OPENGL |              // support OpenGL 

				PFD_DOUBLEBUFFER,                 // double buffered 

				PFD_TYPE_RGBA,                    // RGBA type 

				24,                               // 24-bit color depth 

				0, 0, 0, 0, 0, 0,                 // color bits ignored 

				0,                                // no alpha buffer 

				0,                                // shift bit ignored 

				0,                                // no accumulation buffer 

				0, 0, 0, 0,                       // accum bits ignored 

				32,                               // 32-bit z-buffer     

				0,                                // no stencil buffer 

				0,                                // no auxiliary buffer 

				PFD_MAIN_PLANE,                   // main layer 

				0,                                // reserved 

				0, 0, 0                           // layer masks ignored 

			}; 
	    
			GLint  iPixelFormat; 
	     
			// get the device context's best, available pixel format match 

			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
	         
			// make that match the device context's current pixel format 

			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}
	    
			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}
	        
			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}
	    
			return 1;
		}
	};
}