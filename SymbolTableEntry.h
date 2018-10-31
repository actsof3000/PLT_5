#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define UNDEFINED  -1

typedef struct{
  int type;
  int numParams;
  int returnType;
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

  SYMBOL_TABLE_ENTRY(const string theName, const int theType)
  {
    name = theName;
    entry.type = theType;
    entry.numParams = UNDEFINED;
    entry.returnType = UNDEFINED;
  }  
  
  SYMBOL_TABLE_ENTRY(const string theName, const int theType, const int numParam, const int returnType) 
  {
    name = theName;
    entry.type = theType;
    entry.numParams = numParam;
    entry.returnType = returnType;
  }

  // Accessors
  string getName() const { return name; }
  TYPE_INFO getTypeCode() const { return entry; }
  int getType() const { return entry.type; }
  int getNumParams() const { return entry.numParams; }
  int getReturnType() const { return entry.returnType; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
