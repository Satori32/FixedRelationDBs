#pragma once

#include <stdio.h>

#include "FixedRelationDB.h"
#include "FixedVector.h"

template<size_t A, size_t B>
struct FixedRelationDBs {
	FixedVector<FixedRelationDB<B>, A> F;
};

template<size_t A, size_t B> FixedRelationDBs<A, B> ConstructFixedRelationDBs<A, B>();
template<size_t A, size_t B> bool Free(FixedRelationDBs<A, B>& In);