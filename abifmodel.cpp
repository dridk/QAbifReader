#include "abifmodel.h"

AbifModel::AbifModel(QObject * parent)
    :QAbstractTableModel(parent)
{
    mReader = NULL;
}

AbifModel::~AbifModel()
{

}

void AbifModel::setFilename(const QString &filename)
{
    beginResetModel();
    mReader = new AbifReader(filename);






    endResetModel();

}

int AbifModel::rowCount(const QModelIndex &parent) const
{
    if (mReader)
        return mReader->directoryKeys().count();
    else
        return 0;
}

int AbifModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant AbifModel::data(const QModelIndex &index, int role) const
{

    if (!mReader)
        return QVariant();

    if (!index.isValid())
        return QVariant();


    if ( (role == Qt::DisplayRole) || (role == Qt::EditRole))
    {
        QString key = mReader->directoryKeys().at(index.row());

        AbifDir dir = mReader->directory(key);
        if (index.column() == 0)
            return key;

        if (index.column() == 1)
            return dir.elementType;

        if (index.column() == 2){

            QVariant data = mReader->data(key);
            if (data.type() == QVariant::List)
            {
                QStringList list;
                int end = data.toList().length() < 20 ? data.toList().length() : 20;
                for (int i=0; i<end; ++i)
                    list.append(data.toList().at(i).toString());


                return list.join(",") + "...";
            }

            if (data.type() == QVariant::Time) {
                qDebug()<<data.toTime();
                return data.toTime().toString();

            }

            return data;
        }

        if (index.column() == 3)
            return dir.dataOffset;
    }












    return QVariant();
}



Qt::ItemFlags AbifModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;
}

