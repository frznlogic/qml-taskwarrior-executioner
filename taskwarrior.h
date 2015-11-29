/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2015 Oscar Andreasson
 */

#ifndef TASKWARRIOR_H
#define TASKWARRIOR_H

#include <QQuickItem>
#include <QProcess>
#include <QFile>


class TaskWarrior : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(TaskWarrior)
    Q_PROPERTY(QString jsonFile READ jsonFile WRITE setJsonFile NOTIFY jsonFileChanged)

public:
    TaskWarrior(QQuickItem *parent = 0);
    ~TaskWarrior();

    Q_INVOKABLE void sync();

    QString jsonFile();
    void setJsonFile(QString str);

signals:
    void jsonFileChanged();
public slots:
    void syncFinished(int exitCode, QProcess::ExitStatus es);

private:
    QString m_jsonFile;
    QProcess m_process;
    QFile m_file;

};

#endif // TASKWARRIOR_H

