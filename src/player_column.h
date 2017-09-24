/*!
  \file player_column.h
  \brief file to define PlayerColumn(
*/

#ifndef PLAYER_COLUMN_H
#define PLAYER_COLUMN_H

class PlayerColumn {

public:
  PlayerColumn(const int NameColumn) :
  mRootColumn(NameColumn) {}

  int name() const {
    return mRootColumn;
  }

  int team() const {
    return mRootColumn + 2;
  }

  int rank() const {
    return mRootColumn + 4;
  }

  int played() const {
    return mRootColumn + 6;
  }

  int value() const {
    return mRootColumn + 8;
  }

  int scarcity() const {
    return mRootColumn + 11;
  }

  ~PlayerColumn() {}

protected:

private:
  int mRootColumn;
};

#endif //PLAYER_COLUMN_H
