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
#pragma once

#include <QTableWidget>
#include <QItemDelegate>
#include <QPainter>
#include <QVector>
#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QKeyEvent>

#include "parser/xml_parser.hh"

class TableWidgetDelegate : public QItemDelegate {
    Q_OBJECT
public:
    explicit TableWidgetDelegate(QObject *parent);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

class TableWidget : public QTableWidget {
    Q_OBJECT
public:
    TableWidget();
    void loadHeaders();
    void setMathItems(QVector<MathItem> items);
    void addMathItem(MathItem item);
    QVector<MathItem> allMathItems();
    void updateMath();
    bool isMath(int row, int col);
    QString formula(int row, int col);
    QModelIndexList currentSelectedItems();
private:
    void keyPressEvent(QKeyEvent *event);
private:
    QVector<MathItem> mathItems;
private slots:
    void onCellChanged();
    void onItemChanged(QTableWidgetItem *item);
    void onCellClicked(int row, int col);
signals:
    void cellModified();
};
