#ifndef ABSTRACT_FILE_READER_H
#define ABSTRACT_FILE_READER_H

#include <QObject>

class AbstractFileReader : public QObject
{
  Q_OBJECT
public:
  explicit AbstractFileReader(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ABSTRACT_FILE_READER_H