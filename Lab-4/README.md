
# Lab4 - CI/CD with Github Actions

## Part 1 - Write a rock-paper-scissors game with JAVA
1. Main.java
    1. 主程式
    2. 呼叫 Game.java 相關邏輯進行勝負判斷
2. Game.java
    1. 遊戲相關邏輯處理
    2. 須含 ***兩個 function***
        1. 判斷勝負 ( Player 1 win, Player 2 win, Draw )
        2. 輸入 validation: Invalid input throw *IllegalArgumentException* ( player 輸入剪刀石頭布以外 )

## Part 2 - Write a rock-paper-scissors game unit test
- 針對 Game.java 進行單元測試即可 ( Main.java 不要求 )
- 測試須滿足以下條件
    1. all win cases
    2. all lose cases
    3. all draw cases
    4. valid/invalid input cases

## Part 3 - Use github action to build, test, assemble jar
- 將程式托管到 github 上並公開 ( 名稱請取 st_nycu_lab4_*[你的學號]* )
- 撰寫 github action
    1. 只要有新 commit 並 push, 就需執行 **Build, Test, Assemble**
    2. **Storing workflow "all test report directory", "assemble jar file" as workflow artifacts**
    3. Add github action badge to README

## Part 4 - Use github action to automate release jar file when push is a tag pushed events
1. 新增一個 job 為 Release
2. 該 Release 階段觸發條件為只有 Git tag push 的時候
3. 第三階段 Assemble jar file 後透過 ***action-gh-release*** 加入到 Github release 裡面

## Bonus - Use action/cache to cache your dependencies and speed up your build time.
1. 每個 Job 獨立環境
2. 專案龐大, Dependencies 肥大問題
3. 嘗試使用 ***action/cache*** 來 cache 你的 dependencies 供每次 workflow 利用

## 繳交方式
- 請上傳一份 **PDF** 說明文件至 E3, 內容需含以下幾點
    - 學號, 姓名, 系級
    - Your lab4 Github repo url
    - Part 1 ~ 4 (Bonus optional) 簡單截圖說明
        - 如何完成...
        - step3, step4 請額外附上對應的 github workflow 連結參考 (以此當基準點評分)
        - 如果有做 Bonus 也請說明分析減少了哪些部分,那些部分因此加速了
    - (Optional) 作業心得
