## 概要
- 高速ゼータ変換(上位集合)：集合$S$を部分集合に含むような集合$T$についての$f(T)$の総和, すなわち,
$$g(S)=\sum_{T\supseteq S} f(T)$$
を計算する.
- 高速ゼータ変換(下位集合)：集合$S$の部分集合$T$についての$f(T)$の総和, すなわち,
$$g(S)=\sum_{T\subseteq S} f(T)$$
を計算する.
- 高速メビウス変換(上位集合)：高速ゼータ変換(上位集合)の逆変換, すなわち,
$$f(S)=\sum_{T\supseteq S} (-1)^{|T|-|S|}g(T)$$
を計算する.
- 高速メビウス変換(下位集合)：高速ゼータ変換(上位集合)の逆変換, すなわち,
$$f(S)=\sum_{T\subseteq S} (-1)^{|S|-|T|}g(T)$$
を計算する.

また高速ゼータ変換は演算を$+$に限定せずとも環上で動く([参考](http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9), 未整備)

## 計算量
どれも$O(n2^n)$

## 参照
- [高速ゼータ変換について - Qiita](https://qiita.com/Euglenese/items/260f9ddf513f772d7e42)
- [高速ゼータ・メビウス変換 - Mister雑記](https://misteer.hatenablog.com/entry/zeta-moebius)
