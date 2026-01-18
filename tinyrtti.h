#ifndef MINI_RTTI
#define MINI_RTTI


#define SN RTTI
#define PREPROCCESSED_CAT(a,b) a##_##b
#define PREPROCCESSED_CAT_NAME(a,b) PREPROCCESSED_CAT(a,b)
#define PREPROCCESSED_DEFINE_THING(name) PREPROCCESSED_CAT_NAME(SN,name)
//this ensures expansion before concatonation
//now if any confilcting symbols happens change SN
//note change in in both .h and .c

typedef unsigned int TypeID;
typedef struct {
    TypeID type;
    void *data;
}PREPROCCESSED_DEFINE_THING(ANY);


extern TypeID PREPROCCESSED_DEFINE_THING(NONE);
extern TypeID PREPROCCESSED_DEFINE_THING(INT);
extern TypeID PREPROCCESSED_DEFINE_THING(FLOAT);
extern TypeID PREPROCCESSED_DEFINE_THING(DOUBLE);
extern TypeID PREPROCCESSED_DEFINE_THING(CHAR);
extern TypeID PREPROCCESSED_DEFINE_THING(STRING);
//some built in types
TypeID PREPROCCESSED_DEFINE_THING(append_type)(void); //function append_type(void) returns TypeID _uint_

#undef SN
#undef PREPROCCESSED_CAT
#undef PREPROCCESSED_CAT_NAME
#undef PREPROCCESSED_DEFINE_THING


#endif
