/* ************************************************************
 * Syntox
 * Copyright 2012-2013 Lionel Clément. All rights reserved.
 * Author: Lionel Clément
 * Labri
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 ************************************************************ */

#ifndef VALUE_H
#define VALUE_H

#include <set>
#include "flags.hh"
#include "errors.hh"
#include "enum.hh"
#include "bits.hh"

class Value : 
  public Flags {
  
public:
  typedef enum {	      
    BOOL, 
    CONSTANT, 
    VARIABLE,
    IDENTIFIER,
    FORM,
    FEATURES,
    LIST,
    NUMBER
  } valuetype;
  
  union VALUE {
    bitset<MAXBITS> *bits; // pour encoder les constantes et les variables
    unsigned int integer; // pour encoder les identifiers
    class Features *features; // pour encoder les SF
    class List *list;
    string *form;
    float number;
  };
  
  static class Value *_nil;
  static class Value *_true;

private:
  static unsigned int uniqId;
  unsigned int id;
  valuetype type;
  union VALUE slots;
  string sign;
  class Value *left;
  class Value *right;

  public:

  Value(const valuetype);
  Value(const valuetype, class Value *, class Value *);
  Value(unsigned int, const valuetype);
  Value(float, const valuetype);
  Value(string *, const valuetype);
  Value(bitset<MAXBITS> *, const valuetype);
  Value(class Features *);
  Value(class Set *);
  Value(class List *);
  Value(float);
  Value(void);
  ~Value(void);
  
  inline int getId(void){return this->id;}
  
  inline union VALUE getSlots(void){return slots;}
  
  inline valuetype getType(void){return type;}
  inline void putTypeValue(valuetype type){this->type=type;}
  
  inline bitset<MAXBITS> *getBits(void){return slots.bits;}
  inline void putBits(bitset<MAXBITS> *bits){this->slots.bits=bits;}

  inline unsigned int getInteger(void){return slots.integer;}
  inline void putInteger(unsigned int integer){this->slots.integer=integer;}
  
  inline class Features *getFeatures(void){return slots.features;}
  inline void putFeatures(class Features *features){this->slots.features=features;}

  inline float getNumber(void){return slots.number;}
  inline void putNumber(float number){this->slots.number=number;}
  
  inline string *getForm(void){return slots.form;}
  inline void putForm(string *form){this->slots.form=form;}
  
  inline class List *getList(void){return slots.list;}
  inline void putList(class List *list){this->slots.list=list;}

  inline class Value *getLeft(void){return left;}
  inline void putLeft(class Value *left){this->left=left;}

  inline class Value *getRight(void){return right;}
  inline void putRight(class Value *right){this->right=right;}

  void print(ostream&, bool_html=TRUE_HTML);
#ifdef OUTPUT_XML
  void toXML(xmlNodePtr NodeRoot);
#endif
  bool buildEnvironment(class Environment *, class Value *, bool);
  //bool filter(class Value*, class Environment *);
  bool subsumes(class Value*, class Environment *);
  bool equivalent(class Value*);
  bool less(class Value*);
  class Value *copy(void);
  //void deleteVariables(class Environment *);
  void deleteNIL(void);
  void customizeVariables(unsigned int=0);
  string getSign(void);
  void buildLexicalEnvironment(class Environment *);
  inline bool isNil(void){return this==_nil;}
  inline bool isTrue(void){return this==_true;}
  inline bool isNumber(void){return getType()==NUMBER;}
  inline bool isFeatures(void){return getType()==FEATURES;}
  inline bool isConstant(void){return getType()==CONSTANT;}
  inline bool isList(void){return getType()==LIST;}
  bool exists(class Environment *);
  void disable(class Statement *, class Gitem *);

};

#endif // VALUE_H
