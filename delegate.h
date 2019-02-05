#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QPainter>
#include <QDateTime>

class Delegate : public QItemDelegate
{
    Q_OBJECT

public:
    Delegate(QSqlTableModel* model, QObject* parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    QSqlTableModel& model;
};

#endif // DELEGATE_H
