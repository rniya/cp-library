---
title: スタック拡張マクロ
documentation_of: ./stack_extend.hpp
---

## 概要
ICPC 国内予選など手元実行が必要になる際に, 再帰に代表される重い処理はスタックオーバーフローを引き起こしやすい. それを回避するためにスタックを付け替えるマクロ. 具体的には以下のようにして用いる.

```c++
#include "stack_extend.hpp"

int main(){
    BEGIN_STACK_EXTEND(256 * 1024 *1024);   // 256 MB

    /**
     * メインの処理
     */

    END_STACK_EXTEND;
}
```

## Links
- [スタック拡張マクロ \| libalgo](https://tubo28.me/compprog/algorithm/extend-stack/)
