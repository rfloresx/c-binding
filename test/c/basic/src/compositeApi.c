/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_compositeApi_onUpdate(
    corto_observerEvent *e)
{
    this->updated = TRUE;
}

void test_compositeApi_tc_compare(
    test_compositeApi this)
{
    corto_equalityKind eq;
    test_compositeType a = {10, 20}, b = {20, 30};

    eq = test_compositeTypeCompare(&a, &b);
    test_assert(eq == CORTO_LT);

    eq = test_compositeTypeCompare(&b, &a);
    test_assert(eq == CORTO_GT);

    eq = test_compositeTypeCompare(&a, &a);
    test_assert(eq == CORTO_EQ);

}

void test_compositeApi_tc_create(
    test_compositeApi this)
{

    test_compositeType *o = test_compositeTypeCreate(10, 20);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->x == 10);
    test_assert(o->y == 20);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_createAuto(
    test_compositeApi this)
{

    test_compositeTypeCreate_auto(o, 10, 20);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->x == 10);
    test_assert(o->y == 20);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_createChild(
    test_compositeApi this)
{

    test_compositeType *o = test_compositeTypeCreateChild(root_o, "o", 10, 20);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->x == 10);
    test_assert(o->y == 20);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_createChildAuto(
    test_compositeApi this)
{

    test_compositeTypeCreateChild_auto(root_o, o, 10, 20);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->x == 10);
    test_assert(o->y == 20);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_declare(
    test_compositeApi this)
{

    test_compositeType *o = test_compositeTypeDeclare();
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_declareAuto(
    test_compositeApi this)
{

    test_compositeTypeDeclare_auto(o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_declareChild(
    test_compositeApi this)
{

    test_compositeType *o = test_compositeTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_declareChildAuto(
    test_compositeApi this)
{

    test_compositeTypeDeclareChild_auto(root_o, o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_define(
    test_compositeApi this)
{
    corto_int16 result;

    test_compositeType *o = test_compositeTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    result = test_compositeTypeDefine(o, 10, 20);
    test_assert(result == 0);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->x == 10);
    test_assert(o->y == 20);

    test_assert(!corto_delete(o));

}

void test_compositeApi_tc_fromStr(
    test_compositeApi this)
{
    test_compositeType o = {10, 20};

    test_compositeTypeFromStr(&o, "{20, 30}");
    test_assert(o.x == 20);
    test_assert(o.y == 30);

}

void test_compositeApi_tc_set(
    test_compositeApi this)
{
    test_compositeType o = {10, 20};

    test_compositeTypeAssign(&o, 20, 30);
    test_assert(o.x == 20);
    test_assert(o.y == 30);

}

void test_compositeApi_tc_str(
    test_compositeApi this)
{
    test_compositeType o = {10, 20};

    corto_string str = test_compositeTypeStr(&o);
    test_assert(!strcmp(str, "{10,20}"));
    corto_dealloc(str);

}

void test_compositeApi_tc_update(
    test_compositeApi this)
{
    corto_int16 result;

    test_compositeType *o = test_compositeTypeCreate(10, 20);
    test_assert(o != NULL);

    result = corto_observer_observe(test_compositeApi_onUpdate_o, this, o);
    test_assert(result == 0);

    result = test_compositeTypeUpdate(o, 20, 30);
    test_assert(result == 0);
    test_assert(this->updated == TRUE);
    test_assert(o->x == 20);
    test_assert(o->y == 30);

    result = corto_observer_unobserve(test_compositeApi_onUpdate_o, this, o);
    test_assert(result == 0);

    corto_delete(o);

}

