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
    hashElement* element;
    Node* node = bucket->head;
    for(i = 0;i<bucket->length;i++){
        if(NULL == node) return -1;
        element = node->data;
        if(0 == compare(element->key,key)) return i;
        node = node->next;
    }        
    return -1;
};

void* search(List* bucket,void* key,Compare compare){
    int i;
    hashElement* element;
    Node* node = bucket->head;
    for(i = 0;i<bucket->length;i++){
        if(NULL == node) return NULL;
        element = node->data;
        if(0 == compare(element->key,key))
            return element->value;
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
    hashElement* element =calloc(1,sizeof(hashElement));
    element->key =key;
    element->value =value;
    return insert(Bucket,Bucket->length,element);
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