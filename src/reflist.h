/******************************************************************************
 *
 * 
 *
 *
 * Copyright (C) 1997-2000 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#ifndef _REFLIST_H
#define _REFLIST_H

#include "qtbc.h"
#include <qintdict.h>

/*! This struct represents an item in the list of references. */
struct RefItem
{
  RefItem() : written(FALSE) {}
  QCString text;           //!< text of the item.
  QCString listAnchor;     //!< anchor in the list
  bool written;
};

/*! Singleton for the one and only RefList */
class RefList
{
  public:
    int      addRefItem();
    RefItem *getRefItem(int todoItemId);
    RefItem *getFirstRefItem();
    RefItem *getNextRefItem();

    RefList();
   ~RefList();

  private:
    int m_id;
    QIntDict<RefItem> *m_dict;
    QIntDictIterator<RefItem> *m_dictIterator;
};

extern RefList todoList;
extern RefList testList;

#endif