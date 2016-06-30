/* $CORTO_GENERATED
 *
 * compositeUnionApi.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_compositeUnionApi_onUpdate(
    test_compositeUnionApi this,
    corto_object observable)
{
/* $begin(test/compositeUnionApi/onUpdate) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_compare(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_compare) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_create(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_create) */

    test_compositeUnionType *o = test_compositeUnionTypeCreate_flt(1, 10.5);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createAuto(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createAuto) */

    test_compositeUnionTypeCreate_flt_auto(o, 1, 10.5);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createAutoDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createAutoDefault) */

    test_compositeUnionTypeCreate_other_auto(o, 4, 10);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createChild(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createChild) */

    test_compositeUnionType *o = test_compositeUnionTypeCreateChild_flt(
        root_o,
        "o",
        1,
        10.5);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createChildAuto(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createChildAuto) */

    test_compositeUnionTypeCreateChild_flt_auto(
        root_o,
        o,
        1,
        10.5);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createChildAutoDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createChildAutoDefault) */

    test_compositeUnionTypeCreateChild_other_auto(
        root_o,
        o,
        4,
        10);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createChildDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createChildDefault) */

    test_compositeUnionType *o = test_compositeUnionTypeCreateChild_other(
        root_o,
        "o",
        4,
        10);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_createDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_createDefault) */

    test_compositeUnionType *o = test_compositeUnionTypeCreate_other(
        4,
        10);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_declare(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_declare) */

    test_compositeUnionType *o = test_compositeUnionTypeDeclare();
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_declareAuto(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_declareAuto) */

    test_compositeUnionTypeDeclare_auto(o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_declareChild(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_declareChild) */

    test_compositeUnionType *o = test_compositeUnionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_declareChildAuto(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_declareChildAuto) */

    test_compositeUnionTypeDeclareChild_auto(root_o, o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_define(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_define) */
    corto_int16 result;

    test_compositeUnionType *o = test_compositeUnionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");

    result = test_compositeUnionTypeDefine_flt(o, 1, 10.5);
    test_assert(result == 0);
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 1);
    test_assert(o->is.flt == 10.5);

    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_defineDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_defineDefault) */
    corto_int16 result;

    test_compositeUnionType *o = test_compositeUnionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_compositeUnionType_o));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o->d == 2);
    test_assertstr(o->is.str, "foo");

    result = test_compositeUnionTypeDefine_other(o, 4, 10);
    test_assert(result == 0);
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(o->d == 4);
    test_assert(o->is.other == 10);

    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_compositeUnionApi_tc_fromStr(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_fromStr) */

/* $end */
}

corto_void _test_compositeUnionApi_tc_fromStrDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_fromStrDefault) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_set(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_set) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_setDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_setDefault) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_str(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_str) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_strDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_strDefault) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_update(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_update) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_compositeUnionApi_tc_updateDefault(
    test_compositeUnionApi this)
{
/* $begin(test/compositeUnionApi/tc_updateDefault) */

    /* << Insert implementation >> */

/* $end */
}
