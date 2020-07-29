// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2020 The Chellit Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CHELLITCOIN_TOKENFILTERPROXY_H
#define CHELLITCOIN_TOKENFILTERPROXY_H

#include <QSortFilterProxyModel>

class TokenFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit TokenFilterProxy(QObject *parent = 0);

    void setTokenNamePrefix(const QString &tokenNamePrefix);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex & source_parent) const;

private:
    QString tokenNamePrefix;
};


#endif //CHELLITCOIN_TOKENFILTERPROXY_H
