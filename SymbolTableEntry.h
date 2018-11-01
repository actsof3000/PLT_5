#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define UNDEFINED  -1
#define INT         1
#define STR         2
#define INT_OR_STR  3
#define BOOL        4
#define INT_OR_BOOL 5
#define STR_OR_BOOL 6
#define INT_OR_STR_OR_BOOL 7

typedef struct{
  int type;
  int nval;
  int sval;
  int bval;
  int op;
  int logop;
  int unop;
} TYPE_INFO;

class SYMBOL_TABLE_ENTRY 
{
private:
  // Member variables
  string name;  
  TYPE_INFO entry;

public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) { name = ""; entry.type = UNDEFINED; }

  SYMBOL_TABLE_ENTRY(const string theName, const TYPE_INFO theType)
  {
    name = theName;
    entry.type = theType;
    entry.nval = theType.nval;
    entry.sval = theType.sval;
    entry.bval = theType.bval;
  }  

  // Accessors
  string getName() const { return name; }
  TYPE_INFO getTypeCode() const { return entry; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
