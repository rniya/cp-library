## 概要
自動で $\bmod$ を取る構造体.
- 各種演算子( `operator++, operator--, operator-(), operator==` 等)に対応
- `std::cin, std::cout` への対応
- 負数に対応したコンストラクタ
- 内部を 32 bit 符号なし整数で保存
- 0 除算や `pow` において指数が負の際に例外の送出を行う

## 参照
- [modint 構造体を使ってみませんか？ (C++) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/03/31/174006)