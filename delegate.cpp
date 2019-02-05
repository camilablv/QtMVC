#include "delegate.h"


Delegate::Delegate(QSqlTableModel* m, QObject* parent) : QItemDelegate (parent), model(*m){}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString data;
    QSqlRecord record = model.record(index.data().toInt());
    QDateTime dateTime = record.value("arrival").toDateTime();
    data.append(dateTime.toString("dd.MM.yyyy/HH:mm"));
    data.append("\n");
    QString name = record.value("name").toString();
    data.append(name).append(" ");
    QString age = record.value("age").toString();
    data.append(age);
    painter->drawText(option.rect, data);
}


QSize Delegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize result = QItemDelegate::sizeHint(option, index);
    result.setHeight(result.height() * 2);
    return result;
}
