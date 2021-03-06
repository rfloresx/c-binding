/* $CORTO_GENERATED
 *
 * voidReferenceApi.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_voidReferenceApi_onUpdate(
    test_voidReferenceApi _this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/voidReferenceApi/onUpdate) */
    _this->updated = TRUE;
/* $end */
}

corto_void _test_voidReferenceApi_tc_create(
    test_voidReferenceApi _this)
{
/* $begin(test/voidReferenceApi/tc_create) */

    test_voidReferenceType o = test_voidReferenceTypeCreate();
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == test_voidReferenceType_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_voidReferenceApi_tc_createAuto(
    test_voidReferenceApi _this)
{
/* $begin(test/voidReferenceApi/tc_createAuto) */

    test_voidReferenceTypeCreate_auto(o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == test_voidReferenceType_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_voidReferenceApi_tc_createChild(
    test_voidReferenceApi _this)
{
/* $begin(test/voidReferenceApi/tc_createChild) */

    test_voidReferenceType o = test_voidReferenceTypeCreateChild(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == test_voidReferenceType_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_voidReferenceApi_tc_createChildAuto(
    test_voidReferenceApi _this)
{
/* $begin(test/voidReferenceApi/tc_createChildAuto) */

    test_voidReferenceTypeCreateChild_auto(root_o, o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == test_voidReferenceType_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkAttr(o, CORTO_ATTR_NAMED));
    test_assert(corto_parentof(o) == root_o);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(!corto_delete(o));

/* $end */
}

corto_void _test_voidReferenceApi_tc_update(
    test_voidReferenceApi _this)
{
/* $begin(test/voidReferenceApi/tc_update) */
    corto_int16 result;

    test_voidReferenceType o = test_voidReferenceTypeCreate();
    test_assert(o != NULL);

    result = corto_observer_observe(test_voidReferenceApi_onUpdate_o, _this, o);
    test_assert(result == 0);

    result = test_voidReferenceTypeUpdate(o);
    test_assert(result == 0);
    test_assert(_this->updated == TRUE);

    result = corto_observer_unobserve(test_voidReferenceApi_onUpdate_o, _this, o);
    test_assert(result == 0);

    corto_delete(o);

/* $end */
}
