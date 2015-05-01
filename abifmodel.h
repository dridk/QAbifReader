#ifndef ABIFMODEL_H
#define ABIFMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "abifreader.h"

class AbifModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    AbifModel(QObject * parent = 0);
    ~AbifModel();

    void setFilename(const QString& filename);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
     AbifReader * mReader;

};

#endif // ABIFMODEL_H
