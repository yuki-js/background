# 雙峰祭の背景アニメーション

![スクリーンショット](screenshot.png)

## なにこれ

はいどうも〜！バーチャル女の子、筑波のキズナアイこと、つくコレ ミスNo.2の青木ゆうきです！

雙峰祭2019前夜祭でスクリーンに投影したグラフィックのソースコードのOSS版です！

それでは早速〜ビルド行ってみよう！

なお、OSS化につき一部変更しています。

## ビルド

ビルド環境: macOS Mojave
他プラットフォームは
```
- #include <GLUT/glut.h>
+ #include <GL/glut.h>
```
するなど

```
$ ./ai
```

## 謝辞

本プログラムを作るにあたり、CG基礎で学んだことを生かしました。筑波大学 三谷先生、金森先生、遠藤先生に感謝いたします。また、本プログラムのグラフィックはキズナアイ様を参考にさせていただきました。感謝の意を表します。


