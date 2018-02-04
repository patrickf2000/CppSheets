#pragma once

#include <QTableWidget>
#include <QVector>
#include <QTableWidgetItem>

#include "parser.hh"

class TableWidget : public QTableWidget {
    Q_OBJECT
public:
    TableWidget();
    void setMathItems(QVector<MathItem> items);
    void addMathItem(MathItem item);
    void updateMath();
private:
    QVector<MathItem> mathItems;
private slots:
    void onCellChanged();
    void onItemChanged(QTableWidgetItem *item);
signals:
    void cellModified();
};
