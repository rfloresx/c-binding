/* $CORTO_GENERATED
 *
 * collectionApi.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_collectionApi_onUpdate(
    test_collectionApi _this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/collectionApi/onUpdate) */
    _this->updated = TRUE;
/* $end */
}

corto_void _test_collectionApi_tc_compare(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_compare) */
    corto_equalityKind eq;
    test_collectionType a = {10, 20}, b = {20, 30};

    eq = test_collectionTypeCompare(a, b);
    test_assert(eq == CORTO_LT);

    eq = test_collectionTypeCompare(b, a);
    test_assert(eq == CORTO_GT);

    eq = test_collectionTypeCompare(a, a);
    test_assert(eq == CORTO_EQ);

/* $end */
}

corto_void _test_collectionApi_tc_create(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_create) */

    corto_int32* o =
        test_collectionTypeCreate(2, ((corto_int32[]){10, 20}));
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o[0] == 10);
    test_assert(o[1] == 20);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_createAuto(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_createAuto) */

    test_collectionTypeCreate_auto(o, 2, ((corto_int32[]){10, 20}));
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o[0] == 10);
    test_assert(o[1] == 20);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_createChild(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_createChild) */

    corto_int32 *o =
      test_collectionTypeCreateChild(root_o, "o", 2, ((corto_int32[]){10, 20}));
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o[0] == 10);
    test_assert(o[1] == 20);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_createChildAuto(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_createChildAuto) */

    test_collectionTypeCreateChild_auto(root_o, o, 2, ((corto_int32[]){10, 20}));
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o[0] == 10);
    test_assert(o[1] == 20);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_declare(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_declare) */

    corto_int32 *o = test_collectionTypeDeclare();
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(o[0] == 1);
    test_assert(o[1] == 2);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_declareAuto(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_declareAuto) */

    test_collectionTypeDeclare_auto(o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(o[0] == 1);
    test_assert(o[1] == 2);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_declareChild(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_declareChild) */

    corto_int32 *o = test_collectionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o[0] == 1);
    test_assert(o[1] == 2);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_declareChildAuto(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_declareChildAuto) */

    test_collectionTypeDeclareChild_auto(root_o, o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o[0] == 1);
    test_assert(o[1] == 2);
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_define(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_define) */
    corto_int16 result;

    corto_int32 *o = test_collectionTypeDeclareChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_collectionType_o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(o[0] == 1);
    test_assert(o[1] == 2);

    result = test_collectionTypeDefine(o, 2, ((corto_int32[]){10, 20}));
    test_assert(result == 0);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(o[0] == 10);
    test_assert(o[1] == 20);

    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_collectionApi_tc_fromStr(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_fromStr) */
    test_collectionType o = {10, 20};

    test_collectionTypeFromStr(o, "{20, 30}");
    test_assert(o[0] == 20);
    test_assert(o[1] == 30);

/* $end */
}

corto_void _test_collectionApi_tc_set(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_set) */
    test_collectionType o = {10, 20};

    test_collectionTypeAssign(o, 2, ((corto_int32[]){20, 30}));
    test_assert(o[0] == 20);
    test_assert(o[1] == 30);

/* $end */
}

corto_void _test_collectionApi_tc_str(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_str) */
    test_collectionType o = {10, 20};

    corto_string str = test_collectionTypeStr(o);
    test_assert(!strcmp(str, "{10,20}"));

/* $end */
}

corto_void _test_collectionApi_tc_update(
    test_collectionApi _this)
{
/* $begin(test/collectionApi/tc_update) */
    corto_int16 result;

    corto_int32 *o =
        test_collectionTypeCreate(2, ((corto_int32[]){10, 20}));
    test_assert(o != NULL);

    result = corto_observer_observe(test_collectionApi_onUpdate_o, _this, o);
    test_assert(result == 0);

    result = test_collectionTypeUpdate(o, 2, ((corto_int32[]){20, 30}));
    test_assert(result == 0);
    test_assert(_this->updated == TRUE);
    test_assert(o[0] == 20);
    test_assert(o[1] == 30);

    result = corto_observer_unobserve(test_collectionApi_onUpdate_o, _this, o);
    test_assert(result == 0);

    corto_delete(o);

/* $end */
}
