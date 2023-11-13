#include<iostream>
#include<vector>
#include <random>
using namespace std;

typedef uint64_t u64;

bool is_prime(u64 p)
{
    if (p % 2 == 0) return false;
    for (u64 d = 3; d*d <= p; ++d) {
        if (p % d == 0) return false;
    }
    return true;
}

u64 random_int(u64 start, u64 end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(start, end);
    return dist(gen);
}

u64 random_prime(u64 start, u64 end)
{
   u64 p;

   while (!is_prime(p = random_int(start, end))) {}
   return p;
}

template<typename K, typename V>
struct hashnode{
    K k;
    V v;
    hashnode<K,V>* next; 
};


template<typename K, typename V>
hashnode<K,V>* newNode(K k,V v){
    auto node= new hashnode<K,V>;
    node->k=k;
    node->v=v;
    node->next=NULL;
    return node;
}

template<typename K,typename V>
struct hashmap{
     uint64_t a,b,p,n;
     vector<hashnode<K,V>*> slots;
};

template<typename K, typename V>
hashmap<K,V> empty(){
    hashmap<K,V> h;
    h.n = 0;
    h.a = 3;
    h.b = 5;
    h.p = 19;
    for (int i = 0; i < h.p; ++i) {
        h.slots.push_back(NULL);
    }
    return h;
}

constexpr int fact(int i)
{
    int p = 1;
    for (int j = 2; j <= i; ++j) {
        p *= j;
    }
    return p;
}
template<typename K, typename V>
int ord(K key){
    auto position=key.first;
    auto orentationCubes= key.second;
    int pos;int orent;
    int seen[9] = { 0 };
    int a = 0;
    int k = 8;
    int j=1;
    int o;
    for(int i=1;i<=8;i++){
        int v=position[i];
        o=1;
        for(int j=1;j<v;j++){
            if(!seen[j]){o++;}
        }
        a+=o*fact(k)*orentationCubes[i]*j;
        j*=7;
        k--;
        seen[v]=1;
    }
    return o;
}

template <typename K, typename V>
void rehash(hashmap<K, V>& h)
{
    u64 p = random_prime(h.n, 2*h.n);
    u64 a = random_int(1, p-1);
    u64 b = random_int(0, p-1);
    std::vector<hashnode<K, V>*> old_slots = std::move(h.slots);
    h.slots.resize(p);

    for (u64 i = 0; i < h.p; ++i) {
        auto x = old_slots[i];
        while (x) {
            auto y = x->next;
            auto new_hash = (a*ord<K,V>(x->k) + b) % p;
            x->next = h.slots[new_hash];
            h.slots[new_hash] = x;
            x = y;
        }
    }
    h.p = p;
    h.a = a;
    h.b = b;
}

template<typename K, typename V>
void insert(hashmap<K, V>& h, K k, V v)         
{
    u64 hash = (h.a * ord<K,V>(k) + h.b) % h.p;      //ord funtion word(i.e. string) ko integer me convert kar raha hai jo decide karega ki kis index par Value store hogi
                                                //Key is unique but value is not therefore we use key to determine index in hashmap
    auto node = newNode<K,V>(k, v);

    node->next = h.slots[hash];
    h.slots[hash] = node;
    ++h.n;

    if (2*h.p < h.n) {
        rehash(h);
    }
}


template <typename K, typename V>
bool member(const hashmap<K, V>& h, K k)
{
    u64 hash = (h.a * ord<K,V>(k) + h.b) % h.p;
    auto p = h.slots[hash];

    while (p) {
        if (p->k == k) {
            return true;
        }
        p = p->next;
    }
    return false;
}

template <typename K, typename V>
V lookup(const hashmap<K, V>& h, K k)
{
    u64 hash = (h.a * ord<K,V>(k) + h.b) % h.p;
    auto p = h.slots[hash];

    while (p) {
        if (p->k == k) {
            return p->v;
        }
        p = p->next;
    }
    assert(0);
}