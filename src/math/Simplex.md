---
title: Simplex
documentation_of: ./Simplex.hpp
---

## 概要
$$
\begin{alignedat}{5}
    & \mathrm{Maximize}     & \quad & \boldsymbol{c}^\top \boldsymbol{x}    \\
    & \mathrm{subject\ to}  & \quad & A \boldsymbol{x} \leq \boldsymbol{b}  \\
    &                       & \quad & \boldsymbol{x} \geq \boldsymbol{0}    \\
\end{alignedat}
$$

を解く．2 段階単体法を利用しており，$\boldsymbol{b} \geq \boldsymbol{0}$ といった制約には縛られない．

ピボットの対象となる基底変数と非規定変数の選び方については以下が代表的である．

- 最小添字規則 (smallest subscript rule)
  - 最も収束の遅い規則であることがわかっているものの，アルゴリズムの有限回での停止が保証されている．
- 最大係数規則 (largest coefficient rule)
  - 平均的な振舞いにおいては最も無難な規則とされているが有限回で停止するとは限らない（ただ，有限回で停止しないようなケースはかなり恣意的なケースである）．

これはデフォルトでは最小添字規則で計算するようにされているが，引数 `mode` によって切り替えることが可能である．テストしてみても概ね最小添字規則で十分高速に動作するのでこのままで構わないはず．
