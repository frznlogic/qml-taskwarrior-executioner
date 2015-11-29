#include "taskwarrior.h"

#include <QDebug>

TaskWarrior::TaskWarrior(QQuickItem *parent):
    QQuickItem(parent),
    m_jsonFile(""),
    m_file(m_jsonFile)
{

    connect(&m_process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(syncFinished(int, QProcess::ExitStatus)));

}

TaskWarrior::~TaskWarrior()
{
}

void TaskWarrior::sync()
{
    QStringList args("export");
    m_process.start("task", args);
}

QString TaskWarrior::jsonFile()
{
    return m_jsonFile;

}

void TaskWarrior::setJsonFile(QString str)
{
    m_jsonFile = str;
    m_file.close();
    m_file.setFileName(m_jsonFile);
    m_file.open(QIODevice::WriteOnly);
}

void TaskWarrior::syncFinished(int exitCode, QProcess::ExitStatus es)
{
    m_file.close();
    m_file.remove();
    m_file.open(QIODevice::WriteOnly);


    m_file.write(QByteArray("["));

    bool firstLine = true;

    while (m_process.canReadLine() == true)
    {
        QByteArray ba = m_process.readLine();

        (firstLine == true) ? firstLine = false : m_file.write(",");

        m_file.write(ba);
    }

    m_file.write(QByteArray("]"));
}

