/***************************************************************************
 *   Copyright (C) 2007 by Tarek Saidi                                     *
 *   tarek.saidi@arcor.de                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef MANAGEBOOKMARKSDLG_H
#define MANAGEBOOKMARKSDLG_H

#include <QDialog>
#include <QCloseEvent>
#include "ui_ManageBookmarksDlg.h"

class ManageBookmarksDlg : public QDialog, private Ui::ManageBookmarksDlg
{
  	Q_OBJECT
	public:
		ManageBookmarksDlg(QWidget* parent=0);
	private:
		virtual void closeEvent(QCloseEvent* event);
	private slots:
		void OnButtonUp();
		void OnButtonDown();
		void OnButtonDelete();
		void OnButtonAdd();
		void OnButtonEdit();
		void edit(QListWidgetItem*);
};

#endif

