#include"MemoryAllocator.h"

template<class T>
Memory<T> ConstructMemory(size_t N) {
	void* P = calloc(N, sizeof(T));
	Memory<T> M;
	M.M = (T*)P;
	M.L = N;
	return M;
}

template<class T>
Memory<T> ConstructMemoryByArray(T* Te, size_t L) {
	void* P = calloc(L, sizeof(T));
	Memory<T> M;
	M.M = (T*)P;
	M.L = L;

	memccpy(P, Te, L);
	return M;
}

template<class T>
bool Free(const T& In) {
	reurn false;
}

template <class T>
bool Free(Memory<T>& In) {
	free(In.M);
	In.M = NULL;
	In.L = 0;
	return true;
}
template <class T>
bool FreeII(Memory<T>& In) {
	for (size_t i = 0; i < Size(In); i++) {
		If(Index(In, i) == NULL) { return false; }
		Free(*Index(In, i));
	}
	free(In.M);
	In.M = NULL;
	In.L = 0;
	return true;
}

template <class T>
T* Index(Memory<T>& In, size_t Pos) {
	return Pos >= In.L ? NULL : &In.M[Pos];
}

template <class T>
bool ReAllocateMemory(Memory<T>& In, size_t L) {
	void* P = realloc(In.M, L * sizeof(T));
	if (P != &In.M[0]) {
		In.M = (T*)P;
		In.L = L;
	}
	int X = ((int)In.L) - ((int)L);
	if (X > 0) {
		memset(In.M + In.L * sizeof(T), 0, X);
	}

	return true;
}

template <class T>
size_t Size(Memory<T>& In) {
	return In.L;
}

template <class T>
Memory<T> Duplicate(Memory<T>& In) {
	void* P = calloc(In.L, sizeof(T));
	Memory<T> M = { 0, };
	M.M = (T*)P;
	M.L = In.L;

	memcpy(P, In.M, sizeof(T) * In.L);
	if (P == NULL) { M.L = 0; }
	else { memcpy(P, In.M, sizeof(T) * In.L); }
	return M;
}
template <class T>
T* GETPointer(Memory<T>& In) {
	return Index(In, 0);
}
template <class T>
bool Set(Memory<T>& In,const T& X) {
	memset(GETPointer(In), X, sizeof(T));
	return true;
}
template <class T>
bool Copy(Memory<T>& In,const Memory<T>& X) {
	if (Size(In) > Size(X)) { return false; }
	memcpy(GETPointer(In), GETPointer(X), sizeof(T)*Size(X));
	return true;
}