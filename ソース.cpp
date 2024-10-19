#include <stdio.h>

#include "FixedRelationDB.h"
#include "FixedVector.h"

template<size_t A,size_t B>
struct FixedRelationDBs {
	FixedVector<FixedRelationDB<B>, A> F;
};
template<size_t A,size_t B>
FixedRelationDBs<A, B> ConstructFixedRelationDBs<A, B>() {
	FixedRelationDBs<A, B> F;

	return F;
}
template<size_t A,size_t B>
bool Free(FixedRelationDBs<A, B>& In) {
	return Free(In);
}

int main() {
	FixedRelationDBs<16, 4> F;

	Free(F);

	return 0;
}