typedef int (*Compare)(void* first, void* second);
typedef int (*HashCodeGenerator)(void* key);

typedef struct {
	void* buckets;
	int capacity;
	HashCodeGenerator hash;
	Compare compare;
}HashMap;

HashMap* createHashMap(HashCodeGenerator hash, Compare compare);
void* get(HashMap* map,void* key);
int put(HashMap* map,void* key,void* value);
void removeKey(HashMap* map,void* key);
void dispose(HashMap* map);