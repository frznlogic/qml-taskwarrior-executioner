#include "taskwarrior.h"

#include <QProcess>

TaskWarrior::TaskWarrior(QQuickItem *parent):
    QQuickItem(parent),
    m_jsonFile("")
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

TaskWarrior::~TaskWarrior()
{
}

void TaskWarrior::sync()
{
    QProcess process;
    process.start("task");

}

QString TaskWarrior::jsonFile()
{
    return m_jsonFile;

}

void TaskWarrior::setJsonFile(QString str)
{
    m_jsonFile = str;
}

