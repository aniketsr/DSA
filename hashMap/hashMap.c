#include "customTypes.h"
#include <stdlib.h>

HashMap* createHashMap(HashCodeGenerator hash, Compare compare){
    int i;
    HashMap* map=calloc(1,sizeof(map));
    map->capacity =10;
    map->buckets =(List*)calloc(map->capacity,sizeof(void*));
    map->compare = compare;
    map->hash =hash;
    return map;
};

int getIndex(List* bucket,void* key,Compare compare){
    int i;
    Object* object;
    Node* node = bucket->head;
    for(i = 0;i<bucket->length;i++){
        if(NULL == node) return -1;
        object = node->data;
        if(0 == compare(object->key,key)) return i;
        node = node->next;
    }        
    return -1;
};

void* search(List* bucket,void* key,Compare compare){
    int i;
    Object* object;
    Node* node = bucket->head;
    for(i = 0;i<bucket->length;i++){
        if(NULL == node) return NULL;
        object = node->data;
        if(0 == compare(object->key,key))
            return object->value;
        node =node->next;
    }
    return NULL;
};

List* getBucket(HashMap* map,void* key){
    int bucketNo = map->hash(key)%map->capacity;
    return map->buckets+bucketNo*sizeof(void*);
};
int put(HashMap* map,void* key,void* value){
    List* Bucket = getBucket(map,key);
    Object* object =calloc(1,sizeof(Object));
    object->key =key;
    object->value =value;
    return insert(Bucket,Bucket->length,object);
};

void* get(HashMap* map,void* key){
    return search(getBucket(map,key),key,map->compare);
};

void removeKey(HashMap* map,void* key){
    List* Bucket = getBucket(map,key);
    remove(Bucket,getIndex(Bucket,key,map->compare));
};

void dispose(HashMap* map){
    List* Bucket;
    int loop;
    for(loop=map->capacity;loop>0;loop--){
        Bucket = (List*)getBucket(map,&loop);
        if (Bucket == NULL) continue;
        if(Bucket->head!= NULL) 
        Free(Bucket);
    }
}; 