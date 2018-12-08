#pragma once

#include <fstream>
#include <msclr/marshal.h>
#include "Spline.h"

namespace vmlab12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		int n;
		CubSpline *spline;
		double *X;
		double *Y;
		int lb;
		int rb;
		int ub;
		int db;
		Graphics ^gr;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;



	private: System::Windows::Forms::Button^  button1;


	public:


		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			lb = -10;
			rb = 10;
			ub = 10;
			db = -10;
			gr = pictureBox1->CreateGraphics();
			spline = NULL;
			X = NULL;
			Y = NULL;


		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(561, 517);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(752, 14);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(116, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(592, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Number of points:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(592, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Enter coordinates:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(596, 410);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(272, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Set coordinates and create";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(596, 123);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 90;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(272, 272);
			this->dataGridView1->TabIndex = 9;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"X";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Y";
			this->Column2->Name = L"Column2";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Location = System::Drawing::Point(596, 51);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(272, 35);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Set size";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 548);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(855, 128);
			this->textBox2->TabIndex = 11;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(596, 496);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(272, 35);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Delete all";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(592, 459);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Point coordinates:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(748, 459);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"( ; )";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(883, 688);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Spline";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		X = new double[n + 2];
		Y = new double[n + 2];

		if (dataGridView1->RowCount) {
			for (int i = 0; i < n; i++) {

				X[i + 1] = Convert::ToDouble(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				Y[i + 1] = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value->ToString());
			}
		}

		spline = new CubSpline(n);
		spline->CreateSpline(X, Y);
		ofstream fout("polynoms.txt");
		for (int i = 0; i < n - 1; i++) {
			String^ str = gcnew String(spline->spline[i].polynom.c_str());
			textBox2->Text += str;
			textBox2->Text += gcnew String("\r\n");
			textBox2->Refresh();
			fout << spline->spline[i].polynom << '\n';
			spline->spline[i].lb = X[i + 1];
			spline->spline[i].rb = X[i + 2];
		}
		fout.close();
	
		
		// отрисовка сплайна 

		int width = pictureBox1->Width;
		int height = pictureBox1->Height;

		double coeff_h = height / double(ub - db);
		double coeff_w = width / double(rb - lb);

		for (int i = 0; i < n - 1; i++)
		{
			Color col1(Color::FromArgb(239, 000, 151));
			Color col2(Color::FromArgb(75, 000, 130));
			Pen^ p = gcnew Pen(col1);

			int sc_x0, sc_x1;
			double w_x0, w_x1;

			w_x0 = spline->spline[i].lb;
			w_x1 = spline->spline[i].rb;

			sc_x0 = double(w_x0 - lb) * coeff_w;
			sc_x1 = double(w_x1 - lb) * coeff_w;

			int k = 50;


			//отрисовка кривой
			for (int j = sc_x0 * k; j < sc_x1 * k; j++) {
				double w_y = spline->spline[i].CreatePolynom((double(j) / double(k)) / coeff_w + lb);
				int sc_y = (ub - w_y) * coeff_h;
				gr->FillEllipse(gcnew SolidBrush(col1), int(double(j) / double(k)), sc_y, 2, 2);

			}

			//отрисовка точек

			double w_y_p = spline->spline[i].CreatePolynom((double(sc_x0) / double(1)) / coeff_w + lb);

			int sc_y_p = (ub - w_y_p) * coeff_h;
			gr->FillEllipse(gcnew SolidBrush(col2), sc_x0 - 3, sc_y_p - 3, 7, 7);

			w_y_p = spline->spline[i].CreatePolynom((double(sc_x1) / double(1)) / coeff_w + lb);
			sc_y_p = (ub - w_y_p) * coeff_h;
			gr->FillEllipse(gcnew SolidBrush(col2), sc_x1 - 3, sc_y_p - 3, 7, 7);


		}
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		n = Convert::ToInt32(textBox1->Text);
		this->dataGridView1->RowCount = n;

		// разметка окна
		gr->Clear(Color::White);

		int h = ub - db;
		int w = rb - lb;

		int width = pictureBox1->Width;
		int height = pictureBox1->Height;

		for (int i = 1; i <= h; i++)
			gr->DrawLine(Pens::Gray, 0, height / h * i, width, height / h * i);
		for (int i = 1; i <= w; i++)
			gr->DrawLine(Pens::Gray, height / w * i, 0, height / w * i, height);
		gr->DrawLine(Pens::Black, 0, height / 2, width, height / 2);
		gr->DrawLine(Pens::Black, height / 2, 0, height / 2, height);
	}
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	double wc, hc;

	wc = double(rb - lb) / pictureBox1->Width;
	hc = double(ub - db) / pictureBox1->Height;

	double x = lb + e->X * wc;
	double y = ub - e->Y * hc;

	String^ strx = String::Format("{0:0.00}",x);
	String^ stry = String::Format("{0:0.00}", y);


	label4->Text = "( " + strx + "; " + stry + ")";
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	delete spline;
	delete gr;

	

	lb = -10;
	rb = 10;
	ub = 10;
	db = -10;
	gr = pictureBox1->CreateGraphics();
	gr->Clear(Color::White);
	spline = NULL;
	X = NULL;
	Y = NULL;
	textBox2->Text = "";

}
};

	}
