获取ssh-keygen：`ssh-keygen -t rsa -C "邮箱地址"`

修改config信息
```
git config --global --add user.name new_name
git config --global --add user.email new_email@xxx.com
git config --global --unset user.name old_name
git config --global --unset user.email old_email@xxx.com 
```
提示有多值时
```
git config --global --replace-all user.name new_name
git config --global --replace-all user.email new_email@xxx.com
```

带账号clone项目：`git clone http://userName:password@link`

新建本地分支并切换：`git checkout -b local_name origin_name`

不使用`-b`参数直接切换已有分支：`git checkout local_name`

重命名分支：`git checkout -m <old_name> <new_name>`

使用`git fetch` + `git rebase` 代替 `git pull` 能减少部分代码冲突

取消git跟踪：`git cache --rm filePath`

代码暂存相关：`git stash`
```bash
git stash --list
git stash pop
git stash clear
```

提交代码在本地：`git commit -m "<type> <scope> <subject>"`  
type | 说明
--- | ---
add/feat | 新功能（feature）
fix | 修补bug
docs | 文档
style | 格式
refactor | 重构（功能不增不减）
test | 测试
chore | 构建过程或辅助工具变动

scope(可选)
影响范围：数据层、控制层、视图层等

subject：尽量控制在50个字以内

提交在上次commit中：`git commit --amend`
进入vim编辑环境后
按`i`键进入编辑状态，编辑完成按`esc`键退出编辑
按`:`键进入命令模式，保存修改输入`w`，退出输入`q`，可一起使用，如保存并退出输入`wq`回车即可

向服务器指定分支提交代码：`git push origin HEAD:tencent`

代码回退：`git reset --hard XXXXXX`
回退后的返回：`git reflog` + `git reset --hard xxxxxx`

Cherry-pick：`git cherry-pick --no-commit 路径/CommitId`

制作diff：`git diff > patch` 应用diff：`git apply patch` 注：对应目录下  
1. git diff --cached > patch //是将我们暂存区与版本库的差异做成补丁
2. git diff --HEAD > patch //是将工作区与版本库的差异做成补丁
3. git diff Testfile > patch //将单个文件做成一个单独的补丁

diff文件检查：`git apply --check patch` 手动处理冲突rej文件：`git apply --reject patch`

添加Tag：`git tag 1.1` 注：tag不可重命名，但可以删`-d` 提交历史中添加tag：`git tag 1.1 xxxxxx`  

查看两个tag之间的提交：`git log --pretty=oneline tagA...tagB`

删除git跟踪的文件：`git rm --cache file_path`

新建Github仓库
初始化本地：`git init`
添加文件：`git add .`
提交本地：`git commit -m "feat: create project"`
命名分支：`git branch -M main`
添加远程仓库：`git remote add origin https://github.com/xxx/xxxxxx.git`
推送至远程仓库：`git push -u origin main`

https://www.ruanyifeng.com/blog/2016/01/commit_message_change_log.html