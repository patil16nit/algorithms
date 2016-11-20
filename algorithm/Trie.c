#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ALPHABETS (26)
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct TrieNode {
  struct TrieNode *child[ALPHABETS];
  bool isLeaf;
};

struct TrieNode *getNode() {
  struct TrieNode *node;
  node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  if (node) {
    int i;
    node->isLeaf = false;
    for(i=0; i<ALPHABETS; i++) {
      node->child[i] = NULL;
    }
  }
  return node;
}

void insert(struct TrieNode *root, const char *key) {
  int level = 0;
  int keyLen = strlen(key);
  struct TrieNode *node = root;
  for (; level< keyLen; level++) {
    int index = CHAR_TO_INDEX(key[level]);
    if(!node->child[index]) {
      node->child[index] = getNode();
    }
    node = node->child[index];
  }
  node->isLeaf = true;
}


bool search(struct TrieNode *root, const char *key) {
  int level = 0;
  int length = strlen(key);
  struct TrieNode *node = root;
  for (;level<length; level++) {
    int index = CHAR_TO_INDEX(key[level]);
    if (!node->child[index]) {
      return false;
    }
    node = node->child[index];
  }
  return (node !=NULL && node->isLeaf);
}


int main() {
  char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"}; 
  char output[][32] = {"Not present in trie", "Present in trie"};
  struct TrieNode *root = getNode();
  int i;
  for(i=0; i< ARRAY_SIZE(keys); i++) {
    insert(root, keys[i]);
  }

  printf("%s......%s\n", "the", output[search(root, "thee")]);
  return 0;
}

