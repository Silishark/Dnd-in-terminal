#ifndef character_h
#define character_h
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <Qstring>
#include "action/action.h"

class character
{
public:
character(
    Qstring name,int health,int attack,int defense):
    cname(name),chealth(health),cattack(attack),cdefense(defense)
    {loadmemory();}
    virtual ~character()
    {savememory();}
    void addmemory(const Qstring& memory)
    {
        cmemory=memory;
    }
    void loadmemory()
      {
        QFile
        file(memoryFilename());
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            cmemory=in.readAll();
            file.close();
        }
        
      }
      void save memory()
      {
        QFile file(memoryFilename());
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out<<cmemory;
            file.close();
        }
      }
      void addAction(Action* action) {
        cactions.append(action);
    }

    QString performAction(int index) {
        if (index >= 0 && index < cactions.size()) {
            return cactions[index]->perform();
        }
        return "Invalid action";
    }
      QString getmemory() const {return cmemory;}
      protected:
      QString memoryFilename() const{return Qstring("%1memory.txt").arg(cname);}
      private:
      QString cname;
      int chealth;
      int cattack;
      int cdefense;
      QString cmemory;
      QVector<Action*> cactions;
}
#endif
