#include <stdio.h>

/* Newtype macro in C
 */

#define newtype(tag, repr)               \
  typedef struct { repr val; } tag;      \
  static inline tag mk##tag(repr v) { \
    return (tag){.val = v};              \
  }                                      \
  static inline repr un##tag(tag v) {  \
    return v.val;                        \
  }                        

newtype(Bool, int)


int main() {
  Bool true = mkBool(1);
  Bool false = mkBool(0);
  printf("%d\n", unBool(true));
  return 0;
}
