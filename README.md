# ori_keyboard
自作キーボードのファームウェアを自作するためのリポジトリ

## 必要な機能
- キーマトリックスの読み込み  
- OLEDまたはLCDに現在のレイヤー、numlockなどを表示
- LEDの制御（余力があれば）
- 一部マウス実装  
    - マウススクロール
    - 右クリック、左クリック  

マウスホイールに関してはトラックボールをUSB接続で追加
（USBハブをキーボードに乗せる）

## レイヤー機能について
現状はレイヤーの値を0xF0以上にすることで対応している
