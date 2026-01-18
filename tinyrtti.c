//tinyrtti.c
#include "tinyrtti.h"
#define SN RTTI
#define PREPROCCESSED_CAT(a,b) a##_##b
#define PREPROCCESSED_CAT_NAME(a,b) PREPROCCESSED_CAT(a,b)
#define PREPROCCESSED_DEFINE_THING(name) PREPROCCESSED_CAT_NAME(SN,name)
//this ensures expansion before concatonation
//now if any confilcting symbols happens change SN
//note change in in both .h and .c
TypeID PREPROCCESSED_DEFINE_THING(NONE)=0;
TypeID PREPROCCESSED_DEFINE_THING(INT)=1;
TypeID PREPROCCESSED_DEFINE_THING(FLOAT)=2;
TypeID PREPROCCESSED_DEFINE_THING(DOUBLE)=3;
TypeID PREPROCCESSED_DEFINE_THING(CHAR)=4;
TypeID PREPROCCESSED_DEFINE_THING(STRING)=5;

static TypeID typecount=5;

TypeID PREPROCCESSED_DEFINE_THING(append_type)(){
    typecount++;
    return typecount;
}

