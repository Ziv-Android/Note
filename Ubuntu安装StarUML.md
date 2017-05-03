# 统一建模工具UML(Unified Modeling Langage)
UML是一种通用的建模语言，适用与一般系统和并行、分布式系统。
## 1. 用例图
从用户的角度描述系统功能，并指各功能的操作者，描述用户需求
## 2. 静态图
### 2.1 类图
描述系统中类的静态结构
### 2.2 包图
包和类组成，描述包与包之间的关系，描述系统的分层结构
### 2.3 对象图
类图的实例
## 3. 行为图
描述系统动态模型和对象组成的交互关系
### 3.1 活动图
业务实现用例的工作流程
### 3.2 状态图
描述状态到状态控制流，常用与动态建模
## 4. 交互图
对象之间的交互关系
### 4.1 顺序图
对象之间的动态合作关系，强调对象发送消息的顺序，同时显示对象之间的交互
### 4.2 合作图
对象之间的协助关系
## 5. 实现图
### 5.1 配置图
定义系统中软硬件的物理体系结构

# StarUML的安装
进入[官网下载](http://staruml.io/download)页选择下载对应版本的StarUML，由于StarUML依赖于 libgcrypt11，所以安装过程中会提示缺少libgcrypt11，[下载](https://launchpad.net/ubuntu/trusty/amd64/libgcrypt11/1.5.3-2ubuntu4.4) [文件](http://launchpadlibrarian.net/279485070/libgcrypt11_1.5.3-2ubuntu4.4_amd64.deb)并执行
```bash
sudo dpkg -i libgcrypt11_1.5.3-2ubuntu4.4_amd64.deb
sudo apkg -i StarUML-v2.7.0-64-bit.deb 
```
完成安装

# 正版破解
Linux安装完成后，在`/opt/staruml/www/license/node`路径下有他一个`LicenseManagerDomain.js`文件，使用sodu权限打开
```bash
function validate(PK, name, product, licenseKey) {
        var pk, decrypted;
        // edit by yourName
        return {
            name: "yourName",
            product: "StarUML",
            licenseType: "vip",
            quantity: "ziv-android.github.io",
            licenseKey: ""
        };

        try {
            pk = new NodeRSA(PK);
            decrypted = pk.decrypt(licenseKey, 'utf8');
        } catch (err) {
            return false;
        }
        var terms = decrypted.trim().split("\n");
        if (terms[0] === name && terms[1] === product) {
            return { 
                name: name, 
                product: product, 
                licenseType: terms[2],
                quantity: terms[3],
                licenseKey: licenseKey
            };
        } else {
            return false;
        }
    }
```
保存退出，然后在starUML软件中Help-->Enter License输入yourName回车即可完成破解注册
