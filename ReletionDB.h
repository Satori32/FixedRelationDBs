#pragma once
#include <stdio.h>

#include "SurfaceT.h"
#include "FixedVector.h"
#include "Any.h"

template<size_t N>
struct RelationDB {
	FixedVector<SurfaceT<Any>,N> V;
};

template<size_t N> RelationDB<N> ConstructReletionDB<SurfaceT<Any>,N>();
template<size_t N>bool Free(RelationDB<N>& In);
template<size_t N> bool FreeII(RelationDB<N>& In);