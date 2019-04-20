#pragma once

#include "GLPanel.h"

namespace WinGel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	enum MouseState { DEFAULT, ROTATE, PAN, ZOOM };

	/// <summary>
	/// Summary for MainForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		GlPanel^ glPanel;
		
		MainForm(void)
		{
			InitializeComponent();
			
			// 
			// glPanel
			//
			glWidth = 780;
			glHeight = 700;
			this->glPanel = gcnew GlPanel(this, glWidth, glHeight);
			this->glPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->glPanel->Location = System::Drawing::Point(200, 30);
			this->glPanel->Name = "glPanel";
			this->glPanel->TabIndex = 2;
			this->glPanel->AllowDrop = true;
			this->glPanel->Resize += gcnew System::EventHandler(this, &MainForm::On_glPanel_Resize);
			this->glPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::On_glPanel_MouseClick);
			this->glPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::On_glPanel_MouseDown);
			this->glPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::On_glPanel_MouseUp);
			this->glPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::On_glPanel_MouseMove);
			this->glPanel->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::On_DragDrop);
			this->glPanel->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::On_DragEnter);
			
			mouseState = DEFAULT;

			this->comboBoxZScale->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		GLsizei glWidth;
		GLsizei glHeight;
		System::Drawing::Point prevPt;
		MouseState mouseState;
		
		System::Windows::Forms::TreeView^  objectTree;
		System::Windows::Forms::StatusStrip^  statusStrip1;
		System::Windows::Forms::ToolStripStatusLabel^  statusLabelMousePos;
		System::Windows::Forms::ToolStripStatusLabel^  statusLabelMousePosition;
		System::Windows::Forms::ComboBox^  comboBoxZScale;




		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->objectTree = (gcnew System::Windows::Forms::TreeView());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->statusLabelMousePos = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusLabelMousePosition = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->comboBoxZScale = (gcnew System::Windows::Forms::ComboBox());
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// objectTree
			// 
			this->objectTree->AllowDrop = true;
			this->objectTree->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->objectTree->Location = System::Drawing::Point(13, 30);
			this->objectTree->Name = L"objectTree";
			this->objectTree->Size = System::Drawing::Size(181, 700);
			this->objectTree->TabIndex = 1;
			this->objectTree->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::On_DragDrop);
			this->objectTree->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::On_DragEnter);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->statusLabelMousePos, 
				this->statusLabelMousePosition});
			this->statusStrip1->Location = System::Drawing::Point(0, 744);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(992, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"Status";
			// 
			// statusLabelMousePos
			// 
			this->statusLabelMousePos->Name = L"statusLabelMousePos";
			this->statusLabelMousePos->Size = System::Drawing::Size(82, 17);
			this->statusLabelMousePos->Text = L"Mouse position:";
			// 
			// statusLabelMousePosition
			// 
			this->statusLabelMousePosition->Name = L"statusLabelMousePosition";
			this->statusLabelMousePosition->Size = System::Drawing::Size(0, 17);
			// 
			// comboBoxZScale
			// 
			this->comboBoxZScale->FormattingEnabled = true;
			this->comboBoxZScale->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"1.0", L"2.0", L"3.0", L"5.0", L"10.0"});
			this->comboBoxZScale->Location = System::Drawing::Point(200, 3);
			this->comboBoxZScale->Name = L"comboBoxZScale";
			this->comboBoxZScale->Size = System::Drawing::Size(50, 21);
			this->comboBoxZScale->TabIndex = 3;
			this->comboBoxZScale->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainForm::On_ZScaleChanged);
			// 
			// MainForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->ClientSize = System::Drawing::Size(992, 766);
			this->Controls->Add(this->comboBoxZScale);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->objectTree);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"WinGel v0.1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::OnPaint);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::On_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::On_DragEnter);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void OnPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		{
			UNREFERENCED_PARAMETER(sender);
			UNREFERENCED_PARAMETER(e);

			
			glPanel->Paint();
		}

		System::Void On_glPanel_Resize(System::Object^  sender, System::EventArgs^  e) 
		{
			glPanel->ResizeScene();
		}

		System::Void On_glPanel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			this->statusLabelMousePosition->Text = e->Location.ToString();
		}

		System::Void On_glPanel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			System::Drawing::Point pt = e->Location;
			tagPOINT* tpt = new tagPOINT();
			tpt->x = pt.X;
			tpt->y = pt.Y;

			if (safe_cast<Panel^>(sender) != this->glPanel)
				return;

			if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				// Gives Rotation if current state is Default; Zoom if current state is Pan.
				mouseState = MouseState(mouseState + ROTATE);
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
				mouseState = MouseState(mouseState + PAN);
			}
			
			switch (mouseState) {
				case PAN:
					this->Cursor = System::Windows::Forms::Cursors::Hand;
					break;
				case ZOOM:
					this->Cursor = System::Windows::Forms::Cursors::SizeAll;
					break;
				default:
					this->Cursor = System::Windows::Forms::Cursors::Default;
					break;
			}

			prevPt = pt;
		}

		System::Void On_glPanel_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			this->Cursor = System::Windows::Forms::Cursors::Default;
			mouseState = DEFAULT;
		}
		
		System::Void On_glPanel_MouseMove(System::Object^sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			System::Drawing::Point pt = e->Location;
			
			switch (mouseState) {
				case ROTATE:
					glPanel->RotateScene(pt.X, pt.Y, pt.X-prevPt.X, pt.Y-prevPt.Y);
					break;
				case PAN:
					glPanel->PanScene(pt.X-prevPt.X, prevPt.Y-pt.Y);
					break;
				case ZOOM:
					glPanel->ZoomScene(prevPt.Y-pt.Y);
					break;
				default:
					break;
			}

			prevPt = pt;
		}
	
		System::Void On_ZScaleChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			String^ selection = this->comboBoxZScale->SelectedItem->ToString();
			float zs = System::Convert::ToSingle(selection);
			glPanel->SetZScale(zs);
		}

		System::Void On_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) 
		{
			e->Effect = DragDropEffects::Copy;
		}
		
		System::Void On_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) 
		{
			if (!e->Data->GetDataPresent( DataFormats::FileDrop )) {
				return;
			}

			array<String^>^ files = (array<String^>^)e->Data->GetData( DataFormats::FileDrop );

			for (int i = 0; i < files->Length; ++i) {
				if (files[i]->Contains("_EM.")) {
					// Recognize file as an EM data file if the filename less extension ends with _EM
					// Create EmData wrapper object and try to load data
				}
				else if (files[i]->Contains("_Horizon.")) {
					// Recognize file as a Horizon data file if the filename less extension ends with _Horizon
					// Create Horizon wrapper object and try to load data
					try {
						HorizonM^ horizon = gcnew HorizonM(files[i]);
						this->glPanel->AddObject(horizon);
						this->objectTree->Nodes->Add(files[i]->Substring(files[i]->LastIndexOf("\\")+1));
					}
					catch (Exception^ ex) {
						// Do nothing
					}
				}
				else if (files[i]->Contains("_Molecule.")) {
					// Recognize file as a Molecule data file if the filename less extension ends with _Molecule
					// Create Molecule wrapper object and try to load data
					try {
						MoleculeM^ molecule = gcnew MoleculeM(files[i]);
						this->glPanel->AddObject(molecule);
						this->objectTree->Nodes->Add(files[i]->Substring(files[i]->LastIndexOf("\\") + 1));
					}
					catch (Exception^ ex) {
						// Do nothing
					}
				}
				else {
					// Do nothing
					// Add a warning message
				}
			}
		}

};
}

