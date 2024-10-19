#include "FixedRelationDBs.h"

template<size_t A, size_t B>
FixedRelationDBs<A, B> ConstructFixedRelationDBs<A, B>() {
	FixedRelationDBs<A, B> F;

	return F;
}
template<size_t A, size_t B>
bool Free(FixedRelationDBs<A, B>& In) {
	return Free(In);
}