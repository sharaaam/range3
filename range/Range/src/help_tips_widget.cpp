/*********************************************************************
 *  AUTHOR: Tomas Soltys                                             *
 *  FILE:   help_tips_widget.cpp                                     *
 *  GROUP:  Range                                                    *
 *  TYPE:   source file (*.cpp)                                      *
 *  DATE:   26-th November 2017                                      *
 *                                                                   *
 *  DESCRIPTION: Help tips and tricks widget class definition        *
 *********************************************************************/

#include <rmlib.h>

#include "help_tips_widget.h"
#include "main_settings.h"

HelpTipsWidget::HelpTipsWidget(QWidget *parent)
    : DocumentWidget(parent)
{
    QStringList tips;


    foreach (const QString &tipName, tips)
    {
        this->addListItem(tipName,
                          RFileManager::buildPath(MainSettings::getInstance().findHelpDir(),"tip_" + tipName + ".html"));
    }
}
