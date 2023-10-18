#pragma once
#include "../Set/set.h"
#include <array>

namespace ApplicationSet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: 
		TSet *A = nullptr, *B = nullptr;
	private: System::Windows::Forms::RichTextBox^ DemonstrateBox;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (A != nullptr) {
				delete A;
				A = nullptr;
			}
			if (B != nullptr) {
				delete B;
				B = nullptr;
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::Panel^ panel1;





	private: System::Windows::Forms::ListBox^ SetAList;




	private: System::Windows::Forms::RichTextBox^ SetAText;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ LoadfiormFileAButton;
	private: System::Windows::Forms::Button^ SaveToFileAButton;



	private: System::Windows::Forms::Button^ CleanAButton;
	private: System::Windows::Forms::Button^ AddSetAButton;
	private: System::Windows::Forms::Button^ DelElementsAButton;


	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ LoadfiormFileBButton;
	private: System::Windows::Forms::Button^ SaveToFileBButton;



	private: System::Windows::Forms::Button^ CleanBButton;
	private: System::Windows::Forms::Button^ AddSetBButton;
	private: System::Windows::Forms::Button^ DelElementsBButton;
	private: System::Windows::Forms::RichTextBox^ SetBText;





	private: System::Windows::Forms::ListBox^ SetBList;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ UnionSetButton;

	private: System::Windows::Forms::Button^ DiferenceSetButton;
	private: System::Windows::Forms::Button^ IntersectSetButton;



	private: System::Windows::Forms::Button^ NotSetAButton;
	private: System::Windows::Forms::Button^ NotSetBButton;
	private: System::Windows::Forms::ListBox^ ResList;




	private: System::Windows::Forms::Button^ DemonstrateButton;
















	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->LoadfiormFileAButton = (gcnew System::Windows::Forms::Button());
			this->SaveToFileAButton = (gcnew System::Windows::Forms::Button());
			this->CleanAButton = (gcnew System::Windows::Forms::Button());
			this->AddSetAButton = (gcnew System::Windows::Forms::Button());
			this->DelElementsAButton = (gcnew System::Windows::Forms::Button());
			this->SetAText = (gcnew System::Windows::Forms::RichTextBox());
			this->SetAList = (gcnew System::Windows::Forms::ListBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->DemonstrateButton = (gcnew System::Windows::Forms::Button());
			this->UnionSetButton = (gcnew System::Windows::Forms::Button());
			this->DiferenceSetButton = (gcnew System::Windows::Forms::Button());
			this->IntersectSetButton = (gcnew System::Windows::Forms::Button());
			this->NotSetAButton = (gcnew System::Windows::Forms::Button());
			this->NotSetBButton = (gcnew System::Windows::Forms::Button());
			this->ResList = (gcnew System::Windows::Forms::ListBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->LoadfiormFileBButton = (gcnew System::Windows::Forms::Button());
			this->SaveToFileBButton = (gcnew System::Windows::Forms::Button());
			this->CleanBButton = (gcnew System::Windows::Forms::Button());
			this->AddSetBButton = (gcnew System::Windows::Forms::Button());
			this->DelElementsBButton = (gcnew System::Windows::Forms::Button());
			this->SetBText = (gcnew System::Windows::Forms::RichTextBox());
			this->SetBList = (gcnew System::Windows::Forms::ListBox());
			this->DemonstrateBox = (gcnew System::Windows::Forms::RichTextBox());
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel2->AutoSize = true;
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->SetAText);
			this->panel2->Controls->Add(this->SetAList);
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->MaximumSize = System::Drawing::Size(1000, 1000);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(269, 527);
			this->panel2->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->Controls->Add(this->LoadfiormFileAButton);
			this->panel3->Controls->Add(this->SaveToFileAButton);
			this->panel3->Controls->Add(this->CleanAButton);
			this->panel3->Controls->Add(this->AddSetAButton);
			this->panel3->Controls->Add(this->DelElementsAButton);
			this->panel3->Location = System::Drawing::Point(4, 182);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(262, 93);
			this->panel3->TabIndex = 9;
			// 
			// LoadfiormFileAButton
			// 
			this->LoadfiormFileAButton->Location = System::Drawing::Point(0, 3);
			this->LoadfiormFileAButton->Name = L"LoadfiormFileAButton";
			this->LoadfiormFileAButton->Size = System::Drawing::Size(114, 23);
			this->LoadfiormFileAButton->TabIndex = 0;
			this->LoadfiormFileAButton->Text = L"LoadFile";
			this->LoadfiormFileAButton->UseVisualStyleBackColor = true;
			// 
			// SaveToFileAButton
			// 
			this->SaveToFileAButton->Location = System::Drawing::Point(120, 3);
			this->SaveToFileAButton->Name = L"SaveToFileAButton";
			this->SaveToFileAButton->Size = System::Drawing::Size(125, 23);
			this->SaveToFileAButton->TabIndex = 4;
			this->SaveToFileAButton->Text = L"SaveFile";
			this->SaveToFileAButton->UseVisualStyleBackColor = true;
			// 
			// CleanAButton
			// 
			this->CleanAButton->Location = System::Drawing::Point(56, 61);
			this->CleanAButton->Name = L"CleanAButton";
			this->CleanAButton->Size = System::Drawing::Size(121, 23);
			this->CleanAButton->TabIndex = 7;
			this->CleanAButton->Text = L"Clean A";
			this->CleanAButton->UseVisualStyleBackColor = true;
			this->CleanAButton->Click += gcnew System::EventHandler(this, &MyForm::CleanAButton_Click);
			// 
			// AddSetAButton
			// 
			this->AddSetAButton->Location = System::Drawing::Point(0, 32);
			this->AddSetAButton->Name = L"AddSetAButton";
			this->AddSetAButton->Size = System::Drawing::Size(114, 23);
			this->AddSetAButton->TabIndex = 5;
			this->AddSetAButton->Text = L"AddSet A";
			this->AddSetAButton->UseVisualStyleBackColor = true;
			this->AddSetAButton->Click += gcnew System::EventHandler(this, &MyForm::AddSetAButton_Click);
			// 
			// DelElementsAButton
			// 
			this->DelElementsAButton->Location = System::Drawing::Point(120, 32);
			this->DelElementsAButton->Name = L"DelElementsAButton";
			this->DelElementsAButton->Size = System::Drawing::Size(125, 23);
			this->DelElementsAButton->TabIndex = 6;
			this->DelElementsAButton->Text = L"DelButton A";
			this->DelElementsAButton->UseVisualStyleBackColor = true;
			this->DelElementsAButton->Click += gcnew System::EventHandler(this, &MyForm::DelElementsAButton_Click);
			// 
			// SetAText
			// 
			this->SetAText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SetAText->Location = System::Drawing::Point(4, 279);
			this->SetAText->Name = L"SetAText";
			this->SetAText->Size = System::Drawing::Size(259, 236);
			this->SetAText->TabIndex = 8;
			this->SetAText->Text = L"";
			// 
			// SetAList
			// 
			this->SetAList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SetAList->FormattingEnabled = true;
			this->SetAList->Location = System::Drawing::Point(4, 3);
			this->SetAList->Name = L"SetAList";
			this->SetAList->Size = System::Drawing::Size(259, 173);
			this->SetAList->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(12, 10);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(812, 524);
			this->panel1->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel6->AutoSize = true;
			this->panel6->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Controls->Add(this->ResList);
			this->panel6->Location = System::Drawing::Point(547, 2);
			this->panel6->MaximumSize = System::Drawing::Size(1000, 1000);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(255, 550);
			this->panel6->TabIndex = 10;
			// 
			// panel7
			// 
			this->panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel7->Controls->Add(this->DemonstrateBox);
			this->panel7->Controls->Add(this->DemonstrateButton);
			this->panel7->Controls->Add(this->UnionSetButton);
			this->panel7->Controls->Add(this->DiferenceSetButton);
			this->panel7->Controls->Add(this->IntersectSetButton);
			this->panel7->Controls->Add(this->NotSetAButton);
			this->panel7->Controls->Add(this->NotSetBButton);
			this->panel7->Location = System::Drawing::Point(4, 351);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(248, 116);
			this->panel7->TabIndex = 9;
			// 
			// DemonstrateButton
			// 
			this->DemonstrateButton->Location = System::Drawing::Point(121, 61);
			this->DemonstrateButton->Name = L"DemonstrateButton";
			this->DemonstrateButton->Size = System::Drawing::Size(124, 23);
			this->DemonstrateButton->TabIndex = 8;
			this->DemonstrateButton->Text = L"Demonstrate";
			this->DemonstrateButton->UseVisualStyleBackColor = true;
			this->DemonstrateButton->Click += gcnew System::EventHandler(this, &MyForm::DemonstrateButton_Click);
			// 
			// UnionSetButton
			// 
			this->UnionSetButton->Location = System::Drawing::Point(0, 3);
			this->UnionSetButton->Name = L"UnionSetButton";
			this->UnionSetButton->Size = System::Drawing::Size(114, 23);
			this->UnionSetButton->TabIndex = 0;
			this->UnionSetButton->Text = L"A+B";
			this->UnionSetButton->UseVisualStyleBackColor = true;
			this->UnionSetButton->Click += gcnew System::EventHandler(this, &MyForm::UnionSetButton_Click);
			// 
			// DiferenceSetButton
			// 
			this->DiferenceSetButton->Location = System::Drawing::Point(120, 4);
			this->DiferenceSetButton->Name = L"DiferenceSetButton";
			this->DiferenceSetButton->Size = System::Drawing::Size(125, 23);
			this->DiferenceSetButton->TabIndex = 4;
			this->DiferenceSetButton->Text = L"A-B";
			this->DiferenceSetButton->UseVisualStyleBackColor = true;
			this->DiferenceSetButton->Click += gcnew System::EventHandler(this, &MyForm::DiferenceSetButton_Click);
			// 
			// IntersectSetButton
			// 
			this->IntersectSetButton->Location = System::Drawing::Point(3, 61);
			this->IntersectSetButton->Name = L"IntersectSetButton";
			this->IntersectSetButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->IntersectSetButton->Size = System::Drawing::Size(111, 23);
			this->IntersectSetButton->TabIndex = 7;
			this->IntersectSetButton->Text = L"A*B";
			this->IntersectSetButton->UseVisualStyleBackColor = true;
			this->IntersectSetButton->Click += gcnew System::EventHandler(this, &MyForm::IntersectSetButton_Click);
			// 
			// NotSetAButton
			// 
			this->NotSetAButton->Location = System::Drawing::Point(0, 32);
			this->NotSetAButton->Name = L"NotSetAButton";
			this->NotSetAButton->Size = System::Drawing::Size(114, 23);
			this->NotSetAButton->TabIndex = 5;
			this->NotSetAButton->Text = L"~A";
			this->NotSetAButton->UseVisualStyleBackColor = true;
			this->NotSetAButton->Click += gcnew System::EventHandler(this, &MyForm::NotSetAButton_Click);
			// 
			// NotSetBButton
			// 
			this->NotSetBButton->Location = System::Drawing::Point(120, 32);
			this->NotSetBButton->Name = L"NotSetBButton";
			this->NotSetBButton->Size = System::Drawing::Size(125, 23);
			this->NotSetBButton->TabIndex = 6;
			this->NotSetBButton->Text = L"~B";
			this->NotSetBButton->UseVisualStyleBackColor = true;
			this->NotSetBButton->Click += gcnew System::EventHandler(this, &MyForm::NotSetBButton_Click);
			// 
			// ResList
			// 
			this->ResList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ResList->FormattingEnabled = true;
			this->ResList->Location = System::Drawing::Point(7, 6);
			this->ResList->Name = L"ResList";
			this->ResList->Size = System::Drawing::Size(245, 355);
			this->ResList->TabIndex = 3;
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel4->AutoSize = true;
			this->panel4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->SetBText);
			this->panel4->Controls->Add(this->SetBList);
			this->panel4->Location = System::Drawing::Point(278, 3);
			this->panel4->MaximumSize = System::Drawing::Size(1000, 1000);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(263, 527);
			this->panel4->TabIndex = 1;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->Controls->Add(this->LoadfiormFileBButton);
			this->panel5->Controls->Add(this->SaveToFileBButton);
			this->panel5->Controls->Add(this->CleanBButton);
			this->panel5->Controls->Add(this->AddSetBButton);
			this->panel5->Controls->Add(this->DelElementsBButton);
			this->panel5->Location = System::Drawing::Point(4, 182);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(256, 93);
			this->panel5->TabIndex = 9;
			// 
			// LoadfiormFileBButton
			// 
			this->LoadfiormFileBButton->Location = System::Drawing::Point(0, 3);
			this->LoadfiormFileBButton->Name = L"LoadfiormFileBButton";
			this->LoadfiormFileBButton->Size = System::Drawing::Size(114, 23);
			this->LoadfiormFileBButton->TabIndex = 0;
			this->LoadfiormFileBButton->Text = L"LoadFile";
			this->LoadfiormFileBButton->UseVisualStyleBackColor = true;
			// 
			// SaveToFileBButton
			// 
			this->SaveToFileBButton->Location = System::Drawing::Point(120, 3);
			this->SaveToFileBButton->Name = L"SaveToFileBButton";
			this->SaveToFileBButton->Size = System::Drawing::Size(125, 23);
			this->SaveToFileBButton->TabIndex = 4;
			this->SaveToFileBButton->Text = L"SaveFile";
			this->SaveToFileBButton->UseVisualStyleBackColor = true;
			// 
			// CleanBButton
			// 
			this->CleanBButton->Location = System::Drawing::Point(56, 61);
			this->CleanBButton->Name = L"CleanBButton";
			this->CleanBButton->Size = System::Drawing::Size(121, 23);
			this->CleanBButton->TabIndex = 7;
			this->CleanBButton->Text = L"Clean B";
			this->CleanBButton->UseVisualStyleBackColor = true;
			this->CleanBButton->Click += gcnew System::EventHandler(this, &MyForm::CleanBButton_Click);
			// 
			// AddSetBButton
			// 
			this->AddSetBButton->Location = System::Drawing::Point(0, 32);
			this->AddSetBButton->Name = L"AddSetBButton";
			this->AddSetBButton->Size = System::Drawing::Size(114, 23);
			this->AddSetBButton->TabIndex = 5;
			this->AddSetBButton->Text = L"AddSet B";
			this->AddSetBButton->UseVisualStyleBackColor = true;
			this->AddSetBButton->Click += gcnew System::EventHandler(this, &MyForm::AddSetBButton_Click);
			// 
			// DelElementsBButton
			// 
			this->DelElementsBButton->Location = System::Drawing::Point(120, 32);
			this->DelElementsBButton->Name = L"DelElementsBButton";
			this->DelElementsBButton->Size = System::Drawing::Size(125, 23);
			this->DelElementsBButton->TabIndex = 6;
			this->DelElementsBButton->Text = L"DelButton B";
			this->DelElementsBButton->UseVisualStyleBackColor = true;
			this->DelElementsBButton->Click += gcnew System::EventHandler(this, &MyForm::DelElementsBButton_Click);
			// 
			// SetBText
			// 
			this->SetBText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SetBText->Location = System::Drawing::Point(4, 279);
			this->SetBText->Name = L"SetBText";
			this->SetBText->Size = System::Drawing::Size(253, 236);
			this->SetBText->TabIndex = 8;
			this->SetBText->Text = L"";
			// 
			// SetBList
			// 
			this->SetBList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SetBList->FormattingEnabled = true;
			this->SetBList->Location = System::Drawing::Point(7, 6);
			this->SetBList->Name = L"SetBList";
			this->SetBList->Size = System::Drawing::Size(253, 173);
			this->SetBList->TabIndex = 3;
			// 
			// DemonstrateBox
			// 
			this->DemonstrateBox->Location = System::Drawing::Point(121, 92);
			this->DemonstrateBox->Name = L"DemonstrateBox";
			this->DemonstrateBox->Size = System::Drawing::Size(124, 24);
			this->DemonstrateBox->TabIndex = 10;
			this->DemonstrateBox->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 540);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Location = System::Drawing::Point(720, 579);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: void SynchSetAList() {
	SetAList->Items->Clear();
	if (A == nullptr) { return; }
	for (int i = 0; i < A->GetMaxPower(); i++) {
		if (A->IsMember(i) == 1) {
			SetAList->Items->Add(i.ToString() + " ");
		}
	}
}
private: void SynchSetBList() {
	SetBList->Items->Clear();
	if (B == nullptr) { return; }
	for (int i = 0; i < B->GetMaxPower(); i++) {
		if (B->IsMember(i) == 1) {
			SetBList->Items->Add(i.ToString() + " ");
		}
	}
}
private: System::Void AddSetAButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (A == nullptr) { A = new TSet(0); }
	array<String^> ^text = SetAText->Text->Split(' ');
	TSet set(0);
	for each (String ^ temp in text)
	{
		if (temp == "") { break; }
		int x = int::Parse(temp);
		if (x + 1 > set.GetMaxPower()) {
			TSet* tmp = new TSet(x + 1);
			set = set + *tmp;
		}
		set = set + x;
	}
	*A = *A + set;
	SynchSetAList();
	delete text;
}
private: System::Void AddSetBButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (B == nullptr) { B = new TSet(0); }
	array<String^>^ text = SetBText->Text->Split(' ');
	TSet set(0);
	for each (String ^ temp in text)
	{
		if (temp == "") { break; }
		int x = int::Parse(temp);
		if (x + 1 > set.GetMaxPower()) {
			TSet* tmp = new TSet(x + 1);
			set = set + *tmp;
		}
		set = set + x;
	}
	*B = *B + set;
	SynchSetBList();
	delete text;
}
private: System::Void DelElementsAButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (A == nullptr) { return; }
	array<String^>^ text = SetAText->Text->Split(' ');
	TSet set(A->GetMaxPower());
	for each (String ^ temp in text)
	{
		if (temp == "") { break; }
		int x = int::Parse(temp);
		if (x < set.GetMaxPower()) {
			set.InsElem(x);
		}
	}
	*A = *A * ~set;
	SynchSetAList();
	delete text;
}
private: System::Void DelElementsBButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (B == nullptr) { return; }
	array<String^>^ text = SetBText->Text->Split(' ');
	TSet set(B->GetMaxPower());
	for each (String ^ temp in text)
	{
		if (temp == "") { break; }
		int x = int::Parse(temp);
		if (x < set.GetMaxPower()) {
			set.InsElem(x);
		}
	}
	*B = *B * ~set;
	SynchSetBList();
	delete text;
}
private: System::Void CleanAButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (A != nullptr) {
		delete A;
		A = nullptr;
		SynchSetAList();
	}
}
private: System::Void CleanBButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (B != nullptr) {
		delete B;
		B = nullptr;
		SynchSetBList();
	}
}
private: System::Void UnionSetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResList->Items->Clear();
	if (A != nullptr && B != nullptr) {
		TSet res(0);
		res = *A + *B;
		for (int i = 0; i < res.GetMaxPower(); i++) {
			if (res.IsMember(i) == 1) {
				ResList->Items->Add(i.ToString() + " ");
			}
		}
	}
	else{ ResList->Items->Add("One of the sets is not specified"); }
	
}

private: System::Void NotSetAButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResList->Items->Clear();
	if (A != nullptr) {
		*A = ~*A;
		for (int i = 0; i < A->GetMaxPower(); i++) {
			if (A->IsMember(i) == 1) {
				ResList->Items->Add(i.ToString() + " ");
			}
		}
		SynchSetAList();
	}
	else { ResList->Items->Add("This set is not specified"); }
}
private: System::Void NotSetBButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResList->Items->Clear();
	if (B != nullptr) {
		*B = ~*B;
		for (int i = 0; i < B->GetMaxPower(); i++) {
			if (B->IsMember(i) == 1) {
				ResList->Items->Add(i.ToString() + " ");
			}
		}
		SynchSetBList();
	}
	else { ResList->Items->Add("This set is not specified"); }
}
private: System::Void DiferenceSetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResList->Items->Clear();
	if ((A != nullptr) && (B != nullptr)) {
		TSet res(0);
		if (A->GetMaxPower() > B->GetMaxPower()) {
			TSet tmp1(B->GetMaxPower());
			tmp1 = ~tmp1;
			TSet tmp2(A->GetMaxPower());
			tmp2 = ~(tmp2 + tmp1);
			res = (*A * ~*B) + (*A * tmp2);
		}
		else { res = *A * ~*B; }
		for (int i = 0; i < res.GetMaxPower(); i++) {
			if (res.IsMember(i) == 1) {
				ResList->Items->Add(i.ToString() + " ");
			}
		}
	}
	else { ResList->Items->Add("One of the sets is not specified"); }
}

private: System::Void IntersectSetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResList->Items->Clear();
	if ((A != nullptr) && (B != nullptr)) {
		TSet res = *A * *B;
		for (int i = 0; i < res.GetMaxPower(); i++) {
			if (res.IsMember(i) == 1) {
				ResList->Items->Add(i.ToString() + " ");
			}
		}
	}
	else { ResList->Items->Add("One of the sets is not specified"); }
}
private: System::Void DemonstrateButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResList->Items->Clear();
	if (DemonstrateBox->Text != "") {
		int n = int::Parse(DemonstrateBox->Text);
		if (n > 0) {
			TSet res(n + 1);
			res = ~res;
			for (int i = 2; i < sqrt(n) + 1; i++) {
				for (int j = i; j < n / i + 1; j++) {
					res.DelElem(i * j);
				}
			}
			for (int i = 0; i < res.GetMaxPower(); i++) {
				if (res.IsMember(i) == 1) {
					ResList->Items->Add(i.ToString() + " ");
				}
			}
		}
		else { ResList->Items->Add("Set natural N"); }
	}
	else { ResList->Items->Add("Set natural N"); }
}
};
}
