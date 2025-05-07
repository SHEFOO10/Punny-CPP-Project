#pragma once
#pragma once
#include "LibraryLogic.h"
#include <msclr/marshal_cppstd.h>

namespace LibraryGUI {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MainForm : public Form
    {
    public:
        MainForm() {
            InitializeComponent();
        }

    private:
        TextBox^ idBox;
        TextBox^ titleBox;
        TextBox^ authorBox;
        Button^ addButton;
        Button^ showButton;
        TextBox^ displayArea;

        void InitializeComponent(void) {
            this->Text = "Library Management System";
            this->Width = 500;
            this->Height = 400;

            Label^ idLabel = gcnew Label();
            idLabel->Text = "Book ID:";
            idLabel->Top = 20;
            idLabel->Left = 20;
            this->Controls->Add(idLabel);

            idBox = gcnew TextBox();
            idBox->Top = 20;
            idBox->Left = 100;
            this->Controls->Add(idBox);

            Label^ titleLabel = gcnew Label();
            titleLabel->Text = "Title:";
            titleLabel->Top = 60;
            titleLabel->Left = 20;
            this->Controls->Add(titleLabel);

            titleBox = gcnew TextBox();
            titleBox->Top = 60;
            titleBox->Left = 100;
            this->Controls->Add(titleBox);

            Label^ authorLabel = gcnew Label();
            authorLabel->Text = "Author:";
            authorLabel->Top = 100;
            authorLabel->Left = 20;
            this->Controls->Add(authorLabel);

            authorBox = gcnew TextBox();
            authorBox->Top = 100;
            authorBox->Left = 100;
            this->Controls->Add(authorBox);

            addButton = gcnew Button();
            addButton->Text = "Add Book";
            addButton->Top = 140;
            addButton->Left = 100;
            addButton->Click += gcnew EventHandler(this, &MainForm::addBookClicked);
            this->Controls->Add(addButton);

            showButton = gcnew Button();
            showButton->Text = "Display Books";
            showButton->Top = 180;
            showButton->Left = 100;
            showButton->Click += gcnew EventHandler(this, &MainForm::showBooksClicked);
            this->Controls->Add(showButton);

            displayArea = gcnew TextBox();
            displayArea->Top = 220;
            displayArea->Left = 20;
            displayArea->Width = 440;
            displayArea->Height = 120;
            displayArea->Multiline = true;
            displayArea->ScrollBars = ScrollBars::Vertical;
            this->Controls->Add(displayArea);
        }

        void addBookClicked(Object^ sender, EventArgs^ e) {
            int id = Int32::Parse(idBox->Text);
            string title = msclr::interop::marshal_as<string>(titleBox->Text);
            string author = msclr::interop::marshal_as<string>(authorBox->Text);

            addBook(id, title, author);
            MessageBox::Show("Book added!");
        }

        void showBooksClicked(Object^ sender, EventArgs^ e) {
            string books = getBooks();
            displayArea->Text = gcnew String(books.c_str());
        }
    };
}
