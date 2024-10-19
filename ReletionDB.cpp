#include "ReletionDB.h"

template<size_t N>
RelationDB<N> ConstructReletionDB() {
	RelationDB<N> R;
	R.V = ConstructFixedVector<SurfaceT<Any>,N>(;

	return R;
}
template <size_t N>
bool Free(RelationDB<N>& In) {
	Free(In.V);

	return true;
}
template<size_t N>
bool FreeII(RelationDB<N>& In) {
	for (size_t i = 0; i < Size(In.V); i++) {
		if (Index(In.V, i) == NULL) { return false; }
		Free(*Index(In.V, i));
	}
	Free(In.V);

	return true;
}