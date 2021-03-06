/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_compositeUnionApi_onUpdate(
    corto_observerEvent *e)
{

    this->updated = TRUE;

}

void test_compositeUnionApi_tc_compare(
    test_compositeUnionApi this)
{
    corto_equalityKind eq;
    test_compositeUnionType a = {1, {.flt = 10.5}}, b = {1, {.flt = 10.7}};

    eq = test_compositeUnionTypeCompare(&a, &b);
    test_assert(eq == CORTO_LT);

    eq = test_compositeUnionTypeCompare(&b, &a);
    test_assert(eq == CORTO_GT);

    eq = test_compositeUnionTypeCompare(&a, &a);
    test_assert(eq == CORTO_EQ);

}

void test_compositeUnionApi_tc_compareDefault(
    test_compositeUnionApi this)
{
    corto_equalityKind eq;
    test_compositeUnionType a = {4, {.other = 10}}, b = {4, {.other = 20}};

    eq = test_compositeUnionTypeCompare(&a, &b);
    test_assert(eq == CORTO_LT);

    eq = test_compositeUnionTypeCompare(&b, &a);
    test_assert(eq == CORTO_GT);

    eq = test_compositeUnionTypeCompare(&a, &a);
    test_assert(eq == CORTO_EQ);

    a = (test_compositeUnionType){4, {.other = 10}};
    b = (test_compositeUnionType){5, {.other = 10}};

    eq = test_compositeUnionTypeCompare(&a, &b);
    test_assert(eq == CORTO_EQ);

}

void test_compositeUnionApi_tc_compareDiscriminator(
    test_compositeUnionApi this)
{
    corto_equalityKind eq;
    test_compositeUnionType a = {0, {.num = 10}}, b = {4, {.other = 10}};

    eq = test_compositeUnionTypeCompare(&a, &b);
    test_assert(eq == CORTO_NEQ);

}

void test_compositeUnionApi_tc_create(
    test_compositeUnionApi this)
{

    test_compositeUnionType *o = test_compositeUnionTypeCreate_flt(1, 10.5);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createAuto(
    test_compositeUnionApi this)
{

    test_compositeUnionTypeCreate_flt_auto(o, 1, 10.5);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createAutoDefault(
    test_compositeUnionApi this)
{

    test_compositeUnionTypeCreate_other_auto(o, 4, 10);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createChild(
    test_compositeUnionApi this)
{

    test_compositeUnionType *o = test_compositeUnionTypeCreateChild_flt(
        root_o,
        "o",
        1,
        10.5);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createChildAuto(
    test_compositeUnionApi this)
{

    test_compositeUnionTypeCreateChild_flt_auto(
        root_o,
        o,
        1,
        10.5);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createChildAutoDefault(
    test_compositeUnionApi this)
{

    test_compositeUnionTypeCreateChild_other_auto(
        root_o,
        o,
        4,
        10);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createChildDefault(
    test_compositeUnionApi this)
{

    test_compositeUnionType *o = test_compositeUnionTypeCreateChild_other(
        root_o,
        "o",
        4,
        10);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_createDefault(
    test_compositeUnionApi this)
{

    test_compositeUnionType *o = test_compositeUnionTypeCreate_other(
        4,
        10);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_declare(
    test_compositeUnionApi this)
{

    test_compositeUnionType *o = test_compositeUnionTypeDeclare();
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_declareAuto(
    test_compositeUnionApi this)
{

    test_compositeUnionTypeDeclare_auto(o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_declareChild(
    test_compositeUnionApi this)
{

    test_compositeUnionType *o = test_compositeUnionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_declareChildAuto(
    test_compositeUnionApi this)
{

    test_compositeUnionTypeDeclareChild_auto(root_o, o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_define(
    test_compositeUnionApi this)
{
    corto_int16 result;

    test_compositeUnionType *o = test_compositeUnionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");

    result = test_compositeUnionTypeDefine_flt(o, 1, 10.5);
    test_assert(result == 0);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);

    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_defineDefault(
    test_compositeUnionApi this)
{
    corto_int16 result;

    test_compositeUnionType *o = test_compositeUnionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");

    result = test_compositeUnionTypeDefine_other(o, 4, 10);
    test_assert(result == 0);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);

    test_assert(!corto_delete(o));

}

void test_compositeUnionApi_tc_fromStr(
    test_compositeUnionApi this)
{
    test_compositeUnionType o = {0, {.num = 10}};

    test_compositeUnionTypeFromStr(&o, "{1, 10.5}");
    test_assert(o.d == 1);
    test_assert(o.is.flt == 10.5);

}

void test_compositeUnionApi_tc_fromStrDefault(
    test_compositeUnionApi this)
{
    test_compositeUnionType o = {0, {.num = 10}};

    test_compositeUnionTypeFromStr(&o, "{4, 0x14}");
    test_assert(o.d == 4);
    test_assertint(o.is.other, 20);

}

void test_compositeUnionApi_tc_set(
    test_compositeUnionApi this)
{
    test_compositeUnionType o = {0, {.num = 10}};

    test_compositeUnionTypeAssign_flt(&o, 1, 10.5);
    test_assert(o.d == 1);
    test_assert(o.is.flt == 10.5);

}

void test_compositeUnionApi_tc_setDefault(
    test_compositeUnionApi this)
{
    test_compositeUnionType o = {0, {.num = 10}};

    test_compositeUnionTypeAssign_other(&o, 4, 20);
    test_assert(o.d == 4);
    test_assert(o.is.other == 20);

}

void test_compositeUnionApi_tc_str(
    test_compositeUnionApi this)
{
    test_compositeUnionType o = {0, {.num = 10}};

    corto_string str = test_compositeUnionTypeStr(&o);
    test_assertstr(str, "{0,10}");
    corto_dealloc(str);

}

void test_compositeUnionApi_tc_strDefault(
    test_compositeUnionApi this)
{
    test_compositeUnionType o = {4, {.other = 20}};

    corto_string str = test_compositeUnionTypeStr(&o);
    test_assertstr(str, "{4,0x14}");
    corto_dealloc(str);

}

void test_compositeUnionApi_tc_update(
    test_compositeUnionApi this)
{
    corto_int16 result;

    test_compositeUnionType *o = test_compositeUnionTypeCreate_num(0, 10);
    test_assert(o != NULL);

    result = corto_observer_observe(test_compositeUnionApi_onUpdate_o, this, o);
    test_assert(result == 0);

    result = test_compositeUnionTypeUpdate_flt(o, 1, 10.5);
    test_assert(result == 0);
    test_assert(this->updated == TRUE);
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);

    result = corto_observer_unobserve(test_compositeUnionApi_onUpdate_o, this, o);
    test_assert(result == 0);

    corto_delete(o);

}

void test_compositeUnionApi_tc_updateDefault(
    test_compositeUnionApi this)
{
    corto_int16 result;

    test_compositeUnionType *o = test_compositeUnionTypeCreate_num(0, 10);
    test_assert(o != NULL);

    result = corto_observer_observe(test_compositeUnionApi_onUpdate_o, this, o);
    test_assert(result == 0);

    result = test_compositeUnionTypeUpdate_other(o, 4, 20);
    test_assert(result == 0);
    test_assert(this->updated == TRUE);
    test_assert(o->d == 4);
    test_assert(o->is.other == 20);

    result = corto_observer_unobserve(test_compositeUnionApi_onUpdate_o, this, o);
    test_assert(result == 0);

    corto_delete(o);

}

