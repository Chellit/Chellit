/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#ifndef CHELLITCOIN_DARKSTYLE_H
#define CHELLITCOIN_DARKSTYLE_H

#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFont>
#include <QFile>

class DarkStyle : public QProxyStyle
{
Q_OBJECT

public:
    DarkStyle();
    explicit DarkStyle(QStyle *style);

    QStyle *baseStyle() const;

    void polish(QPalette &palette) override;
    void polish(QApplication *app) override;

private:
    QStyle *styleBase(QStyle *style = Q_NULLPTR) const;
};

#endif //CHELLITCOIN_DARKSTYLE_H
