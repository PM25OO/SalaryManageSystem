# 👨‍🏫教师工资管理系统 v2.1
 --程序设计基础大作业

## 运行说明

### 方法一：使用构建工具（GNU Make）
- 拉取仓库，执行命令并生成可执行文件
```shell
make
```
- 运行程序
```shell
./salary_manager.exe
```

### 方法二：手动编译（GCC）
- 执行以下命令，编译源代码，程序将保存为```salary_manager.exe```
```shell
gcc -o salary_manager main.c functions.c
```
- 运行程序
```shell
./salary_manager.exe
```

## 迭代日志
v1.0 实现基础功能

v1.1 优化交互体验，显示方式

v2.0 重大更新，新增单个员工统计功能，优化交互性

v2.1 修复了部分Windows和Linux兼容性问题，完善说明（新增原神彩蛋

## 其他问题
- 若命令行页面显示中文字符为乱码，请使用```chcp 65001```更改活动代码页为UTF-8