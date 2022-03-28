#include "data.h"
#include <QStringList>
#include <vector>
#include<QTime>
#include <QString>

bool Data::IsEmpty() {return (vectortitle.isEmpty() && vectorsource.isEmpty() && vectordate.empty());}

QString Data::rtitle(std::ptrdiff_t index) {return vectortitle[index];}

QString Data::rsource(std::ptrdiff_t index) {return vectorsource[index];}

QTime Data::rdate(std::ptrdiff_t index) {return vectordate[index];}

void Data::push(QString title, QString source, QTime date)
{
    vectortitle.push_back(title);
    vectorsource.push_back(source);
    vectordate.push_back(date);
}

void Data::pop(std::ptrdiff_t index)
{
    if (!IsEmpty())
    {
        for (std::ptrdiff_t i = index; i < vectortitle.count() - 1; i+=1)
        {
            vectortitle[i] = vectortitle[i+1];
            vectorsource[i] = vectorsource[i+1];
            vectordate[i] = vectordate[i+1];
        }
        vectortitle.pop_back();
        vectorsource.pop_back();
        vectordate.pop_back();
    }
}

std::vector<QTime> Data::getvectordate()
{
    return vectordate;
}
QStringList Data::getvectortitle()
{
    return vectortitle;
}
