/***************************************************************************
 *   Copyright (C) 2005-2007 by Tarek Saidi                                *
 *   tarek.saidi@arcor.de                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
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
 
#include <QString>
#include <QFile>
#include "main.h"
#include "lib/SecString.h"
#include "Export_Txt.h"


QString EntryTemplate=QString("\n\
  Title:    %1\n\
  Username: %2\n\
  Url:      %3\n\
  Password: %4\n\
  Comment:  %5\n\
");

QString GroupTemplate=QString("\n\
*** Group: %1 ***\n\
");

QString Export_Txt::exportDatabase(QWidget* GuiParent, IDatabase* db, QIODevice* file){
	QList<IGroupHandle*> groups=db->sortedGroups();
	for(int g=0;g<groups.size();g++){
		file->write(GroupTemplate.arg(groups[g]->title()).toUtf8());
		QList<IEntryHandle*> entries=db->entries(groups[g]);
		for(int e=0;e<entries.size();e++){
			SecString password=entries[e]->password();
			password.unlock();
			file->write(EntryTemplate.arg(entries[e]->title())
									.arg(entries[e]->username())
									.arg(entries[e]->url())
									.arg(password.string())
									.arg(entries[e]->comment().replace('\n',"\n            "))
									.toUtf8());
			password.lock();
		}
	}
	return QString();
}