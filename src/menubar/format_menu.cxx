// Copyright 2018 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this
//	list of conditions and the following disclaimer in the documentation and/or
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may
//	be used to endorse or promote products derived from this software
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include <QPixmap>
#include <QKeySequence>
#include <QFontDialog>
#include <QTableWidgetItem>

#include "format_menu.hh"
#include "../actions/format_actions.hh"
#include "../tabwidget.hh"

FormatMenu::FormatMenu() {
    this->setTitle("Format");

    bold = new QAction("Bold",this);
    italic = new QAction("Italic",this);
    underline = new QAction("Underline",this);
    border = new QAction("Set Border",this);
    setFont = new QAction("Set Font",this);
    
    colorMenu = new QMenu;
    colorMenu->setTitle("Color");
    bg = new QAction("Background",colorMenu);
    fg = new QAction("Text",colorMenu);
    colorMenu->addAction(bg);
    colorMenu->addAction(fg);

    bold->setIcon(QPixmap(":/icons/format-text-bold.svg"));
    italic->setIcon(QPixmap(":/icons/format-text-italic.svg"));
    underline->setIcon(QPixmap(":/icons/format-text-underline.svg"));

    bold->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_B));
    italic->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_I));
    underline->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_U));

    connect(bold,&QAction::triggered,this,&FormatMenu::onBoldClicked);
    connect(italic,&QAction::triggered,this,&FormatMenu::onItalicClicked);
    connect(underline,&QAction::triggered,this,&FormatMenu::onUnderlineClicked);
    connect(bg,&QAction::triggered,this,&FormatMenu::onBgColorClicked);
    connect(fg,&QAction::triggered,this,&FormatMenu::onFgColorClicked);
    connect(border,&QAction::triggered,this,&FormatMenu::onBorderClicked);
    connect(setFont,&QAction::triggered,this,&FormatMenu::onSetFontClicked);

    this->addAction(bold);
    this->addAction(italic);
    this->addAction(underline);
    this->addMenu(colorMenu);
    this->addAction(border);
    this->addAction(setFont);
}

FormatMenu::~FormatMenu() {
    delete bold;
    delete italic;
    delete underline;
    delete colorMenu;
    delete border;
    delete setFont;
}

void FormatMenu::onBoldClicked() {
    FormatActions::bold();
}

void FormatMenu::onItalicClicked() {
    FormatActions::italic();
}

void FormatMenu::onUnderlineClicked() {
    FormatActions::underline();
}

void FormatMenu::onBgColorClicked() {
    FormatActions::bgColor();
}

void FormatMenu::onFgColorClicked() {
    FormatActions::fgColor();
}

void FormatMenu::onBorderClicked() {
    FormatActions::dspBorderDialog();
}

void FormatMenu::onSetFontClicked() {
    QFontDialog dialog;

    if (!dialog.exec()) {
        return;
    }

    QFont font = dialog.selectedFont();
    auto item = TabWidget::currentWidget()->currentCell();
    item->setFont(font);
}

